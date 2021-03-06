#ifndef	__EM_ERRORTYPE_H__
#define	__EM_ERRORTYPE_H__

/**
 * definition of libEizMonCtrl error type
 */
typedef enum _EM_ErrorType{
	EMERR_SUCCEEDED					= 0x00000000,
	EMERR_DEFAULT_VALUE_USED		= 0x00000001,
	EMERR_IMPERFECT_CONDITION		= 0x00000002,

	EMERR_FAILED					= 0x80000000,

	EMERR_INVALID_HANDLE			= 0x80000001,
	EMERR_INVALID_BUFFER			= 0x80000002,
	EMERR_INVALID_BUFFER_SIZE		= 0x80000003,
	EMERR_INVALID_PARAMETER			= 0x80000004,
	EMERR_UNSUPPORT					= 0x80000005,
	EMERR_UNSUPPORT_COLORMODE		= 0x80000006,
	EMERR_INVALID_ARGUMENT			= 0x80000007,
	EMERR_NO_MORE_DATA				= 0x80000008,
	EMERR_INVALID_SIGNAL			= 0x80000009,

	EMERR_INVALID_SENSOR_STATUS		= 0x8000000a,
	EMERR_INVALID_ZEROCALIBRATION	= 0x8000000b,
	EMERR_FAILED_MEASURE			= 0x8000000c,
	EMERR_FAILED_CALCULATE			= 0x8000000d,
	EMERR_CANCEL					= 0x8000000e,
	EMERR_RUNNING_SELFCALIBRATION	= 0x8000000f,
	EMERR_FAILED_SELFCALIBRATION	= 0x80000010,

	EMERR_UNIMPLEMENTED
}EM_ErrorType;

#endif /*__EM_ERRORTYPE_H__*/

