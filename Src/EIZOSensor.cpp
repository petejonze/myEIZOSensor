//http://uk.mathworks.com/matlabcentral/newsreader/view_thread/81585

/*
	Example matlab code:

	clear all

	cd ../../ EIZOSensor
	mex -v EIZOSensor.cpp -I../Lib ../Lib/x86/libEizMonCtrl_Cal.lib ../Lib/x86/libEizMonCtrl.lib -outdir ../Release/x86
	cd ../Release/x86;

	EIZOSensor('init');
	EIZOSensor('skipcalib');
	x = EIZOSensor('measure')
	EIZOSensor('raise')
	x = EIZOSensor('m')
	EIZOSensor('lower')

	clear all
*/

// PRECOMPILED HEADER:
#include "stdafx.h"
// MATLAB:
#include <math.h>
#include <matrix.h> //NB: https://devtalk.nvidia.com/default/topic/753650/visual-studio-include-quot-mex-h-quot-header-not-working-with-vs-cuda-project/
#include <mex.h>
// OTHER:
#include "EIZOSensor.h"
#include <sstream>
#include <string>
// EIZO:
#include "libEizMonCtrl_Cal.h"
#include "libEizMonCtrl.h"
//#include "afxwin.h"
//#include "afxcmn.h"



/*
* INTERNAL DATA STORAGE -------------------------------------------------------------------------------
*/

bool isConnectedToMonitor = false;
bool isSensorCalibrated = false;

EM_CalibrationTarget m_result;

EM_CalibratedMonitorParameter m_monitorParam;

EM_CalibrationThresholdLevel m_thresholdLevel;

EM_HANDLE m_hMonitor;

EM_HANDLE m_hSensor;

EM_CalibrationTarget m_target;

EM_CalibrationPolicy m_calPolicy;



/*
* INTERNAL COMMANDS -------------------------------------------------------------------------------
*/



void ConnectToMonitor()
{

	// ???
	EM_ReleaseEizoDevice();

	EM_bool bRet = 0;
	EM_HANDLE hMonitor = NULL, hSensor = NULL;

	/* Create the device list */
	bRet = EM_CreateEizoDevice();

	if (!bRet)
	{
		/* Failure */
		mexPrintf("No devices found (1)");
		return;
	}

	/* Gets the handle of monitor */
	m_hMonitor = EM_EnumMonitors(0); // pick first one

	if (!m_hMonitor)
	{
		/* No monitor is connected */
		mexPrintf("No devices found (2)");
		return;
	}

	///* Report Product Name and Serial Number of a monitor */
	///*		Gets the product name of a monitor */
	//unsigned long uSize = EM_GetProductSize(hMonitor); // get the buffer size of a product name
	//char* cProductName = new char[uSize];
	//EM_GetProduct(hMonitor, cProductName, uSize);
	///*		Gets the Serial number of a monitor */
	//uSize = EM_GetSerialSize(hMonitor);
	//char* cSerial = new char[uSize];
	//EM_GetSerial(hMonitor, cSerial, uSize);
	///*		Print*/
	//std::string sSerial(cSerial);
	//std::string sProductName(cProductName);
	//mexPrintf("Connecting to S/N:%s %s\n", sSerial, sProductName); // CString(cSerial) + _T(" ") + CString(cProductName));
	//mexPrintf("Connecting to S/N:%s\n", cSerial);
	//mexPrintf("Connecting to S/N:%s\n", sProductName);
	///*		Clean up*/
	//delete[] cProductName;
	//delete[] cSerial;

	/* Check that monitor has SwingSensor */
	EM_bool rst = EM_HasSwingSensor(m_hMonitor, &m_hSensor);
	if (!rst)
	{
		mexErrMsgIdAndTxt("myex:nrhs:unknownError", "monitor has no swing sensor!");
		return;
	}

	/* Set factory calibration */
	EM_ErrorType err = EMERR_FAILED;
	err = EM_RestoreFactoryCorrelationData(m_hSensor);
	if (EMERR_SUCCEEDED != err)
	{
		mexErrMsgIdAndTxt("myex:nrhs:unknownError", "failed to EM_RestoreFactoryCorrelationData");
		return;
	}

	/*err = EM_InitCalibration(m_hMonitor);
	if (EMERR_SUCCEEDED != err)
	{
		mexErrMsgIdAndTxt("myex:nrhs:unknownError", "failed to initialize monitor calibration");
		return;
	}*/

	// All done. Set connection flag to true
	isConnectedToMonitor = true;
}


void CalibrateSensor(void)
{

	/* Initialize the Swing Sensor */
	EM_ErrorType err = EMERR_FAILED;
	//mexPrintf("initialising sensor (this can take up to 10 seconds)\n");
	err = EM_InitializeSwingSensor(m_hSensor);
	if (EMERR_SUCCEEDED != err)
	{
		mexErrMsgIdAndTxt("myex:nrhs:unknownError", "failed to initialise");
		return;
	}

	// All done. Set initialisation flag to true
	isSensorCalibrated = true;
}

void RaiseSensor()
{
	EM_SetSwingSensorStatus(m_hSensor, EM_SSSTATUS_OPEN);
}

EM_MeasuredValue MakeMeasurement()
{

	EM_ErrorType err = EMERR_FAILED;
	EM_MeasuredValue xyz = { 0 };

	// for debugging
	//mexPrintf("making measurement");

	/* Measure the color patch */
	err = EM_MeasureXYZ(m_hSensor, &xyz);

	// check for success
	if (EMERR_SUCCEEDED != err)
	{
		mexErrMsgIdAndTxt("myex:nrhs:unknownError", "failed to make measurement");
	}

	// for debugging
	/*
		double d = xyz.Z; // 453.23;
		std::ostringstream os;
		os << d;
		std::string str = os.str();
		mexPrintf(str.c_str());
	*/

	return xyz;
}

void LowerSensor()
{
	EM_SetSwingSensorStatus(m_hSensor, EM_SSSTATUS_CLOSE);
}

void AssertConnected()
{
	if (!isConnectedToMonitor)
	{
		mexErrMsgIdAndTxt("myex:nrhs:notConnected", "Must first connect to monitor, using EIZOSensor('connect')");
		return;
	}
}

void AssertCalibrated()
{
	AssertConnected();
	if (!isSensorCalibrated)
	{
		mexErrMsgIdAndTxt("myex:nrhs:notInitialised", "Must first calibrate sensor, using EIZOSensor('calibrate').\n[Alternatively, use EIZOSensor('skipcalibration') to bypass calibration]");
		return;
	}
}

void EnumerateDevices()
{
	mexErrMsgIdAndTxt("myex:nrhs:functionalityNotYetWritten", "Enumeration and choosing of monitors not yet available");
}



/*
* Application entry point.
*/
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	char *string_command;
	double *outArray;
	EM_MeasuredValue xyz;
	//mwSize M; //mwSize is a platform independent alternative to int

	if (nrhs != 1) {
		mexErrMsgIdAndTxt("myex:nrhs:invalidN", "Invalid input: One command string required.\n\nValid commands are:\n   EIZOSensor('enumerate')\n   EIZOSensor('initialise')\n   EIZOSensor('calibrate')\n   EIZOSensor('raisesensor')\n   x = EIZOSensor('measure')\n   EIZOSensor('lowersensor')\n   EIZOSensor('skipcalibration')");
	}

	string_command = mxArrayToString(prhs[0]);
	//mexPrintf("Executing >> %s\n", string_command);
	switch (string_command[0]) {
	case 'i':
		ConnectToMonitor();
		break;
	case 'c':
		AssertConnected();
		CalibrateSensor();
		break;
	case 'r':
		AssertCalibrated();
		RaiseSensor();
		break;
	case 'm':
		AssertCalibrated();
		//get data
		xyz = MakeMeasurement();
		// assign to output vector
		plhs[0] = mxCreateDoubleMatrix(3, 1, mxREAL);
		outArray = mxGetPr(plhs[0]);
		outArray[0] = xyz.X;
		outArray[1] = xyz.Y;
		outArray[2] = xyz.Z;
		break;
	case 'l':
		AssertCalibrated();
		LowerSensor();
		break;
	case 's':
		AssertConnected();
		isSensorCalibrated = true;
		break;
	case 'e':
		EnumerateDevices();
		break;
	default:
		mexErrMsgIdAndTxt("myex:nrhs:unrecognised", "Invalid input: Unrecognised command.\n\nValid commands are:\n   EIZOSensor('enumerate')\n   EIZOSensor('initialise')\n   EIZOSensor('calibrate')\n   EIZOSensor('raisesensor')\n   x = EIZOSensor('measure')\n   EIZOSensor('lowersensor')\n   EIZOSensor('skipcalibration')");
		break;
	}
	mxFree(string_command);

	return;
}