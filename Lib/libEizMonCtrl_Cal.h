#ifndef __LIBEIZMONCTRL_CAL_H__
#define __LIBEIZMONCTRL_CAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef	_WIN32
	/* for Win */
	#include <windows.h>
	#ifdef	LIBEIZMONCTRL_CAL_EXPORTS
		#define LIBEIZMONCTRL_CAL_API	__declspec(dllexport)
	#else
		#define	LIBEIZMONCTRL_CAL_API	__declspec(dllimport)
	#endif
#else
	/* for Mac/Lin */
	#define	CALLBACK
	#define	WINAPI
	#define	LIBEIZMONCTRL_CAL_API
#endif	/* _WIN32 */

/**
 * include
 */
#include "EM_ErrorType.h"
#include "EM_Types.h"
#include "EM_Types_Cal.h"

/**
 * Calibration SDK Version
 */
LIBEIZMONCTRL_CAL_API unsigned long WINAPI EM_GetCalSDKVersion(void);

/**
 * Check Calibration supports
 */
LIBEIZMONCTRL_CAL_API EM_bool WINAPI EM_SupportsCalibration( EM_HANDLE h, const EM_ColorMode colorMode );
LIBEIZMONCTRL_CAL_API EM_bool WINAPI EM_SupportsCalibrationForCurrentColorMode( EM_HANDLE h );

/**
 * Calibration SDK Init / Release
 */
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_InitCalibration( EM_HANDLE h );
LIBEIZMONCTRL_CAL_API void WINAPI EM_ReleaseCalibration( EM_HANDLE h );

/**
 * Calibration setting
 */
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_SetSensorCorrectionType( EM_HANDLE h, const EM_SensorCorrectionType type, const EM_Sensor sensor );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_SetCalibrationThreshold( EM_HANDLE h, const EM_CalibrationThresholdLevel thresholdLevel );

/**
 * Calibration
 */
typedef void (CALLBACK *CalibrationProgress)( EM_CalibrationProgressPhase* phase, void* userData );
typedef void (CALLBACK *Measure)( EM_MeasuredValue* mValue, void* userData );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_ExecuteCalibrationWithSwingSensor( EM_HANDLE h, const EM_CalibrationTarget target, const EM_CalibrationPolicy policy, CalibrationProgress progress, void* userData );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_ExecuteICCProfileCalibrationWithSwingSensor( EM_HANDLE h, const char* iccProfilePath, CalibrationProgress progress, void* userData );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_ExecuteCalibration( EM_HANDLE h, const EM_CalibrationTarget target, const EM_CalibrationPolicy policy, CalibrationProgress progress, Measure measure, void* userData );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_ExecuteICCProfileCalibration( EM_HANDLE h, const char* iccProfilePath, CalibrationProgress progress, Measure measure, void* userData );
LIBEIZMONCTRL_CAL_API void WINAPI EM_CancelCalibration( EM_HANDLE h );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_GetCalibrationResult( EM_HANDLE h, EM_CalibrationTarget* result );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_CreateICCProfileWithResult( const EM_CalibrationTarget result, const char* iccProfilePath, const char* iccProfileDescription );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_ConvertSelfCalibrationTargetFromCalibrationTarget( const EM_CalibrationTarget calTarget, EM_SelfCalTarget* selfCalTarget, unsigned long* flags );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_GetCalibratedMonitorState( EM_HANDLE h, EM_CalibratedMonitorParameter* monitorParam );
LIBEIZMONCTRL_CAL_API EM_ErrorType WINAPI EM_RestoreCalibratedMonitorState( EM_HANDLE h, const EM_CalibratedMonitorParameter monitorParam );


#ifdef __cplusplus
}
#endif

#endif /* __LIBEIZMONCTRL_CAL_H__ */
