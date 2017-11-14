#ifndef	__LIBEIZMONCTRL_H__
#define	__LIBEIZMONCTRL_H__

#ifdef __cplusplus
extern	"C" {
#endif	/* __cplusplus */


#ifdef	_WIN32
	/* for Win */
	#include <windows.h>
	#ifdef	LIBEIZMONCTRL_EXPORTS
		#define	LIBEIZMONCTRL_API	__declspec(dllexport)
	#else
		#define	LIBEIZMONCTRL_API	__declspec(dllimport)
	#endif
#else
	/* for Mac/Lin */
	#define	CALLBACK
	#define	WINAPI
	#define	LIBEIZMONCTRL_API

#endif	/* _WIN32 */

/**
 * include
 */
#include "EM_ErrorType.h"
#include "EM_Types.h"


/**** Device Handle API ****/
/**
 * Construct list for EIZO LCD monitors and EIZO Sensor as HID recognized by thte system
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_CreateEizoDevice(void);

/**
 * Get n-th monitor in the list created by EM_CreateEizoDevice() API.
 * To enumerate all devices, call EM_EnumMonitors() API repeatedly with increasing
 * the nIndex.
 */
LIBEIZMONCTRL_API EM_HANDLE WINAPI EM_EnumMonitors( int index );

/**
 * Determines whether a monitor has a SwingSensor and gets a handle to it.
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_HasSwingSensor( EM_HANDLE hMonitor, EM_HANDLE *hSensor );

/**
 * Determines whether a monitor has a IntegratedFrontSensor and gets a handle to it.
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_HasIntegratedFrontSensor( EM_HANDLE hMonitor, EM_HANDLE *hSensor );

/**
 * Determines whether a monitor has a AmbientLightSensor and gets a handle to it.
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_HasAmbientLightSensor( EM_HANDLE hMonitor, EM_HANDLE *hSensor );

/**
 * Release device interfaces and destroy the list
 */
LIBEIZMONCTRL_API void WINAPI EM_ReleaseEizoDevice(void);


/**** Generic Information API ****/
/**
 * SerialNubmer
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsSerial( EM_HANDLE h );
LIBEIZMONCTRL_API unsigned long WINAPI EM_GetSerialSize( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSerial( EM_HANDLE h, char* serial, const unsigned long size );

/**
 * ProductName
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsProduct( EM_HANDLE h );
LIBEIZMONCTRL_API unsigned long WINAPI EM_GetProductSize( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetProduct( EM_HANDLE h, char* product, const unsigned long size );

/**
 * UsageTime
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsUsageTime( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetUsageTime( EM_HANDLE h, EM_UsageTime* usageTime );

/**
 * MonitorType
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsMonitorType( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetMonitorType( EM_HANDLE h, EM_MonitorType* monitorType );


/**** Generic Display Control API ****/
/**
 * Monitor Power Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsPower( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetPower( EM_HANDLE h, EM_Power* power );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetPower( EM_HANDLE h, const EM_Power power );

/**
 * Brightness Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsBrightness( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetBrightnessRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetBrightness( EM_HANDLE h, long* brightness );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetBrightness( EM_HANDLE h, const long brightness );

/**
 * Color Mode Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_EnumAvailableColorMode( EM_HANDLE h, const unsigned long index, EM_ColorMode* colorMode );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetColorMode( EM_HANDLE h, EM_ColorMode* colorMode );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetColorMode( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetCalibrationMode( EM_HANDLE h, EM_ColorMode* colorMode );

/**
 * Input Source Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsInputSource( EM_HANDLE h );
LIBEIZMONCTRL_API EM_bool WINAPI EM_IsDualScreen( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SelectScreen( EM_HANDLE h, const unsigned long index );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetInputSource( EM_HANDLE h, EM_InputSource* inputSource );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetInputSource( EM_HANDLE h, const EM_InputSource inputSource );

/**
 * Auto Adjust Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsAutoAdjust( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetAutoAdjust( EM_HANDLE h, const EM_AutoAdjust adjustKind );

/**
 * Screen Size Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsScreenSize( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetScreenSize( EM_HANDLE h, EM_ScreenSize* screenSizeKind );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetScreenSize( EM_HANDLE h, const EM_ScreenSize screenSizeKind );

/**
 * Safe Area Marker
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsSafeAreaMarker( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSafeAreaMarker( EM_HANDLE h, const EM_bool display, const EM_SafeAreaMarkerParam params );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSafeAreaMarker( EM_HANDLE h, EM_bool* display, EM_SafeAreaMarkerParam* params );

/**
 * Signal Format
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsSignalFormat( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSignalFormat( EM_HANDLE h, const EM_SignalFormat signalFormat );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSignalFormat( EM_HANDLE h, EM_SignalFormat* signalFormat );

/**
 * Save
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_Save( EM_HANDLE h, const EM_SaveItem item );

/**
 * Reset
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_Reset( EM_HANDLE h );


/**** Generic Color Control API ****/
/**
 * Gamma Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsGamma( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsGammaForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_EnumAvailableGamma( EM_HANDLE h, const unsigned long index, EM_Gamma* gamma );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetGamma( EM_HANDLE h, EM_Gamma* gamma );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetGamma( EM_HANDLE h, const EM_Gamma gamma );

/**
 * Contrast Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsContrast( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsContrastForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetContrastRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetContrast( EM_HANDLE h, long* contrast );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetContrast( EM_HANDLE h, const long contrast );

/**
 * Gain Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsGain( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsGainForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetGainRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetGain( EM_HANDLE h, const EM_ColorParam colorParam, long* gain );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetGain( EM_HANDLE h, const EM_ColorParam colorParam, const long gain );

/**
 * Hue Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsHue( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsHueForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetHueRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetHue( EM_HANDLE h, long* hue );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetHue( EM_HANDLE h, const long hue );

/**
 * 6 Colors Hue Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports6ColorsHue( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports6ColorsHueForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get6ColorsHueRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get6ColorsHue( EM_HANDLE h, const EM_ColorParam colorParam, long* hue );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Set6ColorsHue( EM_HANDLE h, const EM_ColorParam colorParam, const long hue );

/**
 * Saturation Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsSaturation( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsSaturationForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSaturationRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSaturation( EM_HANDLE h, long* saturation );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSaturation( EM_HANDLE h, const long saturation );

/**
 * 6 Colors Saturation Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports6ColorsSaturation( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports6ColorsSaturationForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get6ColorsSaturationRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get6ColorsSaturation( EM_HANDLE h, const EM_ColorParam colorParam, long* saturation );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Set6ColorsSaturation( EM_HANDLE h, const EM_ColorParam colorParam, const long saturation );

/**
 * 6 Colors Lightness Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports6ColorsLightness( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports6ColorsLightnessForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get6ColorsLightnessRange( EM_HANDLE h, long* min, long* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get6ColorsLightness( EM_HANDLE h, const EM_ColorParam colorParam, long* lightness );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Set6ColorsLightness( EM_HANDLE h, const EM_ColorParam colorParam, const long lightness );

/**
 * Gamut Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsColorGamut( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsColorGamutForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_EnumAvailableColorGamut( EM_HANDLE h, const unsigned long index, EM_ColorGamut* gamut );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetColorGamut( EM_HANDLE h, EM_ColorGamut* gamut );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetColorGamut( EM_HANDLE h, const EM_ColorGamut gamut );


/**** Advanced Display Control API ****/
/**
 * Test Pattern Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsTestPattern( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_TestPatternOn( EM_HANDLE h, const EM_TriValue rgb );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_TestPatternOff( EM_HANDLE h );

/**
 * IIS
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsIIS( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetIIS( EM_HANDLE h, const EM_IISCommand iisCmd, const EM_IISRect iisRect );

/**
 * HybridGamma Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsHybridGamma( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetHybridGammaAssignment( EM_HANDLE h, const EM_HybridGammaAssignment hybridGammaAssignment );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetHybridGammaScanArea( EM_HANDLE h, long x, long y, long width, long height );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetHybridGammaArea( EM_HANDLE h, const EM_HybridGammaArea hybridArea, const EM_HybridGammaColorMode colorMode );
LIBEIZMONCTRL_API unsigned long WINAPI EM_GetHybridGammaRectCount( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetHybridGamma( EM_HANDLE h, const EM_HybridGammaCommand cmd, const EM_HybridGammaRect rect );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetHybridGammaEx( EM_HANDLE h, const EM_HybridGammaCommand cmd, const EM_HybridGammaRect* rect, const unsigned long rectCount );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetHighlight( EM_HANDLE h, const EM_Highlight highlight );

/**
 * SwingSensor
 */
typedef void (CALLBACK *PatternOn)( EM_MeasuredValue* mValue, void* userData );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_CorrelateSwingSensor( EM_HANDLE hSensor, PatternOn patOn, void* userData );
LIBEIZMONCTRL_API void WINAPI EM_CancelCorrelation( EM_HANDLE hSensor );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_RestoreFactoryCorrelationData( EM_HANDLE hSensor );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSwingSensorStatus( EM_HANDLE hSensor, const EM_SwingSensorStatus status );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSwingSensorStatus( EM_HANDLE hSensor, EM_SwingSensorStatus* status );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_InitializeSwingSensor( EM_HANDLE hSensor );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_InitializeSwingSensorForCalibration( EM_HANDLE hSensor, const double targetLuminance, const EM_Chromaticity targetChroma );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_MeasureXYZ( EM_HANDLE hSensor, EM_MeasuredValue* xyz );

/**
 * SelfCalibration
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsSelfCalibration( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_EnableSelfCalibrationForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_DisableSelfCalibrationForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSelfCalibrationTarget( EM_HANDLE h, const EM_SelfCalTarget target, const unsigned long flags );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSelfCalibrationTarget( EM_HANDLE h, EM_SelfCalTarget* target, unsigned long* flags );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_ExecuteSelfCalibration( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSelfCalibrationResult( EM_HANDLE h, EM_SelfCalTarget* target, unsigned long* flags );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSelfCalibrationSchedule( EM_HANDLE h, const EM_SelfCalScheduleStatus status, const EM_SelfCalScheduleType type, const EM_SelfCalSchedule schedule );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSelfCalibrationSchedule( EM_HANDLE h, EM_SelfCalScheduleStatus* status, EM_SelfCalScheduleType* type, EM_SelfCalSchedule* schedule );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetCurrentTime( EM_HANDLE h, const EM_Time time );

/**
 * SelfCorrection
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsSelfCorrection( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_EnableSelfCorrectionForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_DisableSelfCorrectionForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSelfCorrectionTargetByMeasuring( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_ExecuteSelfCorrection( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetSelfCorrectionSchedule( EM_HANDLE h, const EM_SelfCalScheduleStatus status, const EM_SelfCalScheduleType type, const EM_SelfCalSchedule schedule );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetSelfCorrectionSchedule( EM_HANDLE h, EM_SelfCalScheduleStatus* status, EM_SelfCalScheduleType* type, EM_SelfCalSchedule* schedule );

/**
 * Integrated Front Sensor
 */
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetIntegratedFrontSensorStatus( EM_HANDLE hSensor, const EM_IntegratedFrontSensorStatus status );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetIntegratedFrontSensorStatus( EM_HANDLE hSensor, EM_IntegratedFrontSensorStatus* status );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_IntegratedFrontSensorMeasure( EM_HANDLE hSensor, const EM_TriValue rgb, EM_MeasuredValue* xyz );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_CalcIntegratedFrontSensorTemperatureParameter( EM_HANDLE hSensor );

/**
 * Ambient Light Sensor
 */
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_AmbientLightSensorMeasure( EM_HANDLE hSensor, double* illuminance );

/**
 * Monitor Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsMonitorMutex( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsMonitorMutexForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetMonitorMutex( EM_HANDLE h, const EM_Mutex mutex );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsBacklight( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsBacklightForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetBacklight( EM_HANDLE h, const EM_Backlight backlight );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetBacklight( EM_HANDLE h, EM_Backlight* backlight );

/**
 * Display Resolution Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsDisplayResolution( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetDisplayResolution( EM_HANDLE h, const EM_DisplayResolutionCommand cmd, const EM_DisplayResolutionRect rect );

/**
 * Color Mode Setting Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsColorModeSetting( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_EnumAvailableColorModeSetting( EM_HANDLE h, const unsigned long index, EM_ColorModeSetting* colorModeSetting );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetColorModeSetting( EM_HANDLE h, EM_ColorModeSetting* colorModeSetting );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetColorModeSetting( EM_HANDLE h, const EM_ColorModeSetting colorModeSetting );


/**** Advanced Color Control API ****/
/**
 * ColorMatrix Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsColorMatrix( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsColorMatrixForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetColorMatrixRange( EM_HANDLE h, double* min, double* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetColorMatrix( EM_HANDLE h, double (*matrix)[3][3] );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetColorMatrix( EM_HANDLE h, double (*matrix)[3][3] );

/**
 * LUT Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsLUT( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsLUTForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetLUTDataRange( EM_HANDLE h, unsigned short* min, unsigned short* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetLUT( EM_HANDLE h, unsigned short (*lut)[256] );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetLUT( EM_HANDLE h, unsigned short (*lut)[256] );

/**
 * RGB LUT Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsRGBLUT( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_SupportsRGBLUTForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetRGBLUTDataRange( EM_HANDLE h, unsigned short* min, unsigned short* max );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetRGBLUT( EM_HANDLE h, const EM_ColorParam colorParam, unsigned short (*lut)[256] );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetRGBLUT( EM_HANDLE h, const EM_ColorParam colorParam, unsigned short (*lut)[256] );

/**
 * 3D-LUT Control
 */
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports3DLUT( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_API EM_bool WINAPI EM_Supports3DLUTForCurrentColorMode( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get3DLUTGridPoints( EM_HANDLE h, unsigned char (*gridPoints)[17] );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get3DLUT( EM_HANDLE h, EM_TriValue (*lut)[17][17][17] );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Set3DLUT( EM_HANDLE h, EM_TriValue (*lut)[17][17][17] );

/**
 * 3D-LUT Ex Control
 */
LIBEIZMONCTRL_API unsigned long WINAPI EM_Get3DLUTGridSizeEx( EM_HANDLE h );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get3DLUTGridPointsEx( EM_HANDLE h, unsigned char *gridPoints, const unsigned long gridSize );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Get3DLUTEx( EM_HANDLE h, EM_TriValue *lut, const unsigned long lutSize );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_Set3DLUTEx( EM_HANDLE h, EM_TriValue *lut, const unsigned long lutSize );


/**** System API ****/
/**
 * SDK Version
 */
LIBEIZMONCTRL_API unsigned long WINAPI EM_GetSDKVersion(void);

/**
 * Checks EIZO SDK license key.
 */
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_SetLicenseKey(const char* licenseKey);

/**
 * Display ID
 */
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetDisplayIDForWin( EM_HANDLE h, char (*displayID)[32] );
LIBEIZMONCTRL_API EM_ErrorType WINAPI EM_GetDisplayIDForMac( EM_HANDLE h, long* displayID );


#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif /* __LIBEIZMONCTRL_H__ */

