#ifndef __EM_TYPES_CAL_H__
#define __EM_TYPES_CAL_H__

#include "EM_Types.h"

typedef enum _EM_SensorCorrectionType{
	EM_SENSOR_CORRECTION_TYPE_NONE,
	EM_SENSOR_CORRECTION_TYPE_2DEGREE
}EM_SensorCorrectionType;

typedef enum _EM_Sensor{
	EM_SENSOR_UNDEFINED,
	EM_SENSOR_EYEONEMONITOR_PRO,
	EM_SENSOR_EYEONEDISPLAY,
	EM_SENSOR_SPYDER3_EX1,
	EM_SENSOR_DTP94,
	EM_SENSOR_COLORMUNKI,
	EM_SENSOR_EYEONEMONITOR_PRO_XRGA,
	EM_SENSOR_EYEONEDISPLAY3_PRO,
	EM_SENSOR_SPYDER4_EX2,
	EM_SENSOR_DISCUS
}EM_Sensor;

typedef enum _EM_CalibrationThresholdLevel{
	EM_THRESHOLD_LEVEL_HIGH,
	EM_THRESHOLD_LEVEL_STANDARD,
	EM_THRESHOLD_LEVEL_LOW
}EM_CalibrationThresholdLevel;

typedef enum _EM_CalibrationProgressPhase{
	EM_CAL_PROGRESS_NOTSTART,
	EM_CAL_PROGRESS_INITIALIZE_START,
	EM_CAL_PROGRESS_NATIVEGAMUT_MEASURE_START,
	EM_CAL_PROGRESS_BRIGHTNESS_ADJUST_START,
	EM_CAL_PROGRESS_GAIN_ADJUST_START,
	EM_CAL_PROGRESS_BLACKLEVEL_ADJUST_START,
	EM_CAL_PROGRESS_GAMUT_ADJUST_START,
	EM_CAL_PROGRESS_GRAYBALANCE_ADJUST_START,
	EM_CAL_PROGRESS_CALIBRATIONRESULT_MEASURE_START,
	EM_CAL_PROGRESS_END
}EM_CalibrationProgressPhase;

typedef enum _EM_CalibrationPolicy{
	EM_TARGET_POLICY_GRAYBALANCE,
	EM_TARGET_POLICY_STANDARD,
	EM_TARGET_POLICY_CONTRAST
}EM_CalibrationPolicy;

typedef enum _EM_TargetTRCType{
	EM_TARGET_TRC_GAMMA,
	EM_TARGET_TRC_LSTAR,
	EM_TARGET_TRC_LUT
}EM_TargetTRCType;

typedef struct _EM_TargetTRC{
	EM_TargetTRCType type;
	EM_Gamma redGammaValue;
	EM_Gamma greenGammaValue;
	EM_Gamma blueGammaValue;
	unsigned short redLutValue[256];
	unsigned short greenLutValue[256];
	unsigned short blueLutValue[256];
}EM_TargetTRC;

typedef enum _EM_TargetGamutType{
	EM_TARGET_GAMUT_NATIVECHROMATICITY,
	EM_TARGET_GAMUT_SPECIFIED
}EM_TargetGamutType;

typedef struct _EM_TargetGamut{
	EM_TargetGamutType type;
	EM_Chromaticity red;
	EM_Chromaticity green;
	EM_Chromaticity blue;
}EM_TargetGamut;

typedef struct _EM_CalibrationTarget{
	double luminance;
	EM_Chromaticity white;
	double blackLevel;
	EM_TargetTRC trc;
	EM_TargetGamut gamut;
}EM_CalibrationTarget;

typedef struct _EM_CalibratedMonitorParameter{
	long brightness;
	long contrast;
	unsigned short redLut[256];
	unsigned short greenLut[256];
	unsigned short blueLut[256];
	double matrix[3][3];
}EM_CalibratedMonitorParameter;

#endif /* __EM_TYPES_CAL_H__ */

