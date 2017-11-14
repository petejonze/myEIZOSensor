#ifndef	__EM_TYPES_H__
#define	__EM_TYPES_H__

/**
 * definition of boolean
 */
typedef unsigned char EM_bool;

/**
 * definition of Monitor handle
 */
typedef void* EM_HANDLE;


/** structure to specify a usage time */
typedef struct _EM_UsageTime{
	unsigned long hour;				/* hour */
	unsigned long minute;			/* minute */
}EM_UsageTime;

/** enumeration to specify a monitor type */
typedef enum _EM_MonitorType{
	EM_MONITORTYPE_MONO			= 0,	/* monochrome */
	EM_MONITORTYPE_COLOR		= 1		/* color */
}EM_MonitorType;

/** enumeration to specify the power status */
typedef enum _EM_Power{
	EM_PWR_OFF,						/* Power Off */
	EM_PWR_ON						/* Power On */
}EM_Power;

/** enumeration to specify a color mode */
typedef enum _EM_ColorMode{
	EM_CM_TEXT					= 0,	/* Text */
	EM_CM_PICTURE,						/* Picture */
	EM_CM_MOVIE,						/* Movie */
	EM_CM_CUSTOM,						/* Custom */
	EM_CM_SRGB,							/* sRGB */
	EM_CM_EXT,							/* External */
	EM_CM_VIEWER,						/* Viewer */
	EM_CM_CAL,							/* Cal */
	EM_CM_DICOMCB,						/* Dicom CB */
	EM_CM_DICOMBB,						/* Dicom BB */
	EM_CM_EMU,							/* Emulation */
	EM_CM_CAL1,							/* Cal1 */
	EM_CM_CAL2,							/* Cal2 */
	EM_CM_CAL3,							/* Cal3 */
	EM_CM_CAD,							/* Text */
	EM_CM_CIE,							/* CIE */
	EM_CM_FL,							/* FL */
	EM_CM_GAME,							/* Game */
	EM_CM_REC709,						/* Rec709 */
	EM_CM_EBU,							/* EBU */
	EM_CM_SMPTEC,						/* SMPTEC */
	EM_CM_DCI,							/* DCI */
	EM_CM_USER1,						/* USER1 */
	EM_CM_USER2,						/* USER2 */
	EM_CM_USER3,						/* USER3 */
	EM_CM_CAL4,							/* Cal4 */
	EM_CM_CAL5,							/* Cal5 */
	EM_CM_CGCAL1				= 28,	/* CGCal1 */
	EM_CM_CGCAL2,						/* CGCal2 */
	EM_CM_CGCAL3,						/* CGCal3 */
	EM_CM_EYECARE,						/* EyeCare */
	EM_CM_ADOBERGB,						/* Adobe RGB */
	EM_CM_CINEMA,						/* Cinema */
	EM_CM_PAPER,						/* Paper */
	EM_CM_HYBRIDGAMMA,					/* Hybrid-É¡ */
	EM_CM_ECO,							/* Eco */
	EM_CM_ALT,							/* ALT */
	EM_CM_DAY,							/* Day */
	EM_CM_NIGHT,						/* Night */
	EM_CM_FPS1,							/* FPS1 */
	EM_CM_FPS2,							/* FPS2 */
	EM_CM_RTS,							/* RTS */
	EM_CM_WEB,							/* Web */
	EM_CM_MODE1					= 1001,	/* Mode1 */
	EM_CM_MODE2,						/* Mode2 */
	EM_CM_MODE3,						/* Mode3 */
	EM_CM_MODE4,						/* Mode4 */
	EM_CM_MODE5,						/* Mode5 */
	EM_CM_MODE6,						/* Mode6 */
	EM_CM_MODE7,						/* Mode7 */
	EM_CM_MODE8,						/* Mode8 */
	EM_CM_MODE9,						/* Mode9 */
	EM_CM_MODE10						/* Mode10 */
}EM_ColorMode;

/** enumeration to specify an input source */
typedef enum _EM_InputSource{
	EM_INPUTSOURCE_PC1			= 0,	/* PC1 */
	EM_INPUTSOURCE_PC2			= 1,	/* PC2 */
	EM_INPUTSOURCE_DSUB			= 10,	/* D-Sub */
	EM_INPUTSOURCE_DSUB2,				/* D-Sub2 */
	EM_INPUTSOURCE_DVI			= 20,	/* DVI */
	EM_INPUTSOURCE_DVI2,				/* DVI2 */
	EM_INPUTSOURCE_DP			= 30,	/* Display Port */
	EM_INPUTSOURCE_DP2,					/* Display Port2 */
	EM_INPUTSOURCE_HDMI			= 40,	/* HDMI */
	EM_INPUTSOURCE_HDMI2,				/* HDMI2 */
	EM_INPUTSOURCE_SDI			= 50,	/* SDI */
	EM_INPUTSOURCE_SDI2,				/* SDI2 */
	EM_INPUTSOURCE_SDI_DUAL_AB,			/* SDIx2 AB Link */
	EM_INPUTSOURCE_SDI_DUAL_BA			/* SDIx2 BA Link */
}EM_InputSource;

/** enumeration to specify a type of the Auto Adjust */
typedef enum _EM_AutoAdjust{
	EM_AUTOADJ_SIZE				= 0,	/* Size */
	EM_AUTOADJ_RANGE			= 4		/* Range */
}EM_AutoAdjust;

/** enumeration to specify a screen size */
typedef enum _EM_ScreenSize{
	EM_SCRENSIZE_NORMAL			= 0,	/* Normal */
	EM_SCRENSIZE_ENLARGED		= 1,	/* Enlarged */
	EM_SCRENSIZE_FULLSCREEN		= 2,	/* FullScreen */

	EM_SCRENSIZE_DOTBYDOT		= 8,	/* Dot by Dot */
	EM_SCRENSIZE_4BY3			= 9,	/* 4:3 */
	EM_SCRENSIZE_16BY9			= 10,	/* 16:9 */
	EM_SCRENSIZE_LETTERBOX		= 11,	/* LetterBox */
	EM_SCRENSIZE_ENLARGED2		= 12,	/* Enlarged(SDI[720p]) */
	EM_SCRENSIZE_AUTO			= 13	/* Auto */
}EM_ScreenSize;

/** enumeration to specify color */
/** using by RGB LUT Gain Hue Saturation and Safe Area Marker */
typedef enum _EM_ColorParam{
	EM_CLR_R,							/* Red */
	EM_CLR_G,							/* Green */
	EM_CLR_B,							/* Blue */
	EM_CLR_C,							/* Cyan */
	EM_CLR_M,							/* Magenta */
	EM_CLR_Y,							/* Yellow */
	EM_CLR_W							/* White */
}EM_ColorParam;

/** enumeration to specify gamut */
typedef enum _EM_ColorGamut{
	EM_GAMUT_NATIVE,					/* Native */
	EM_GAMUT_ADOBERGB,					/* AdobeRGB */
	EM_GAMUT_SRGB,						/* sRGB */
	EM_GAMUT_EBU,						/* EBU */
	EM_GAMUT_REC709,					/* REC709 */
	EM_GAMUT_REC1886,					/* REC1886 */
	EM_GAMUT_SMPTEC,					/* SMPTE-C */
	EM_GAMUT_DCI						/* DCI */
}EM_ColorGamut;

/** structure to specify the Safe Area Marker parameter */
typedef struct _EM_SafeAreaMarkerParam{
	unsigned short		size;			/* Size (80-90 percent) */
	EM_ColorParam		color;			/* Marker Color */
}EM_SafeAreaMarkerParam;

/** enumeration to specify the Signal Format parameter */
typedef enum _EM_SignalFormat{
	EM_SIGFORMAT_YUV422			= 0,	/* YUV 4:2:2 */
	EM_SIGFORMAT_YUV444			= 1,	/* YUV 4:4:4 */
	EM_SIGFORMAT_RGB444			= 2,	/* RGB 4:4:4 */
	EM_SIGFORMAT_AUTO			= 3		/* Auto */
}EM_SignalFormat;

/** enumeration of save item */
typedef enum _EM_SaveItem{
	EM_SAVEITEM_BASIC			= 0,
	EM_SAVEITEM_3DLUT			= 1,
	EM_SAVEITEM_HYBRIDGAMMA		= 2
}EM_SaveItem;

/** enumeration to specify a gamma */
typedef enum _EM_Gamma{
	EM_GAM_14,							/* gamma = 1.4 */
	EM_GAM_15,							/* gamma = 1.5 */
	EM_GAM_16,							/* gamma = 1.6 */
	EM_GAM_17,							/* gamma = 1.7 */
	EM_GAM_18,							/* gamma = 1.8 */
	EM_GAM_19,							/* gamma = 1.9 */
	EM_GAM_20,							/* gamma = 2.0 */
	EM_GAM_21,							/* gamma = 2.1 */
	EM_GAM_22,							/* gamma = 2.2 */
	EM_GAM_23,							/* gamma = 2.3 */
	EM_GAM_24,							/* gamma = 2.4 */
	EM_GAM_25,							/* gamma = 2.5 */
	EM_GAM_26,							/* gamma = 2.6 */
	EM_GAM_27,							/* gamma = 2.7 */
	EM_GAM_28,							/* gamma = 2.8 */
	EM_GAM_29,							/* gamma = 2.9 */
	EM_GAM_30,							/* gamma = 3.0 */
	EM_GAM_GAME,						/* Game */
	EM_GAM_STANDARD,					/* Standard */
	EM_GAM_ADOBERGB,					/* AdobeRGB */
	EM_GAM_SRGB,						/* sRGB */
	EM_GAM_EBU,							/* EBU */
	EM_GAM_REC709,						/* REC709 */
	EM_GAM_REC1886,						/* REC1886 */
	EM_GAM_SMPTEC,						/* SMPTE-C */
	EM_GAM_DCI,							/* DCI */
	EM_GAM_PAPER						/* Paper */
}EM_Gamma;

/** structure to specify element of the Test Pattern and 3D-LUT */
typedef struct _EM_TriValue{
	unsigned short r;					/** TriValue R */
	unsigned short g;					/** TriValue G */
	unsigned short b;					/** TriValue B */
}EM_TriValue;

/** enumeration to specify the IIS action */
typedef enum _EM_IISCommand{
	EM_IISCMD_OFF				= 0,	/* IIS OFF */
	EM_IISCMD_ON				= 1,	/* IIS ON */
	EM_IISCMD_ALLERASE			= 2,	/* IIS ALLERASE */
	EM_IISCMD_IDERASE			= 3		/* IIS rectID ERASE */
}EM_IISCommand;

/** structure to specify an IIS rectangle */
typedef struct _EM_IISRect{
	unsigned char	rectID;				/* rect ID */
	EM_ColorMode	rectColorMode;		/* rect FC */
	long			rectX;				/* rect pos X */
	long			rectY;				/* rect pos Y */
	unsigned long	rectWidth;			/* rect width */
	unsigned long	rectHeight;			/* rect height */
}EM_IISRect;

/** enumeration to specify the Hybrid gamma assignment */
typedef enum _EM_HybridGammaAssignment{
	EM_HYBRIDGAMMAASSIGNMENT_FULLSCAN,
	EM_HYBRIDGAMMAASSIGNMENT_PARTIALSCAN,
	EM_HYBRIDGAMMAASSIGNMENT_CUSTOM
}EM_HybridGammaAssignment;

/** enumeration to specify the Hybrid gamma area */
typedef enum _EM_HybridGammaArea{
	EM_HYBRIDGAMMAAREA_MONOCHROME,
	EM_HYBRIDGAMMAAREA_COLOR,
	EM_HYBRIDGAMMAAREA_BASE,
	EM_HYBRIDGAMMAAREA_MONOCHROME2
}EM_HybridGammaArea;

/** enumeration to specify the Hybrid gamma color mode */
typedef enum _EM_HybridGammaColorMode{
	EM_HYBRIDGAMMACM_CAL1,				/* DICOM */
	EM_HYBRIDGAMMACM_CAL2,				/* Custom */
	EM_HYBRIDGAMMACM_CAL3,				/* CAL/CAL1 */
	EM_HYBRIDGAMMACM_CAL4,				/* CAL2 */
	EM_HYBRIDGAMMACM_CAL5,				/* CAL3 */
	EM_HYBRIDGAMMACM_BASEL,				/* BASE-L */
	EM_HYBRIDGAMMACM_BASEH				/* BASE-H */
}EM_HybridGammaColorMode;

/** enumeration to specify the Hybrid gamma command */
typedef enum _EM_HybridGammaCommand{
	EM_HYBRIDGAMMACMD_ON,
	EM_HYBRIDGAMMACMD_ALLERASE,
	EM_HYBRIDGAMMACMD_IDERASE
}EM_HybridGammaCommand;


/** structure to specify the hybrid gamma rect  */
typedef struct _EM_HybridGammaRect{
	unsigned char		rectID;
	EM_HybridGammaArea	hybridGammaArea;
	long				rectX;
	long				rectY;
	long				rectWidth;
	long				rectHeight;
}EM_HybridGammaRect;

/** enumeration to specify the highlight */
typedef enum _EM_Highlight{
	EM_HIGHLIGHT_OFF,
	EM_HIGHLIGHT_ON
}EM_Highlight;

/** enumeration to specify the Swing Sensor status */
typedef enum _EM_SwingSensorStatus{
	EM_SSSTATUS_OPEN,
	EM_SSSTATUS_CLOSE,
}EM_SwingSensorStatus;

/** structure to specify XYZ color */
typedef struct _EM_MeasuredValue{
	double X;
	double Y;
	double Z;
}EM_MeasuredValue;

/** structure to specify a xy coordinates */
typedef struct _EM_Chromaticity{
	double x;
	double y;
}EM_Chromaticity;

/** structure to specify a SelfCalibration target */
typedef struct _EM_SelfCalTarget{
	unsigned short luminance;
	EM_Chromaticity	white;
	EM_Chromaticity	red;
	EM_Chromaticity	green;
	EM_Chromaticity	blue;
	EM_Gamma		gamma;
}EM_SelfCalTarget;

/** enumeration of SelfCalibration target option */
enum {
	EM_SC_NATIVECHROMATICITY		= 0x00000001,	/* sets monitor native as the target gamut */
	EM_SC_NOTCALGAMMA				= 0x00000002,	/* gamma won't change */
	EM_SC_CLIPPING_ON				= 0x00000004	/* clipping on */
};

/** enumeration to specify a SelfCalibration timing */
typedef enum _EM_SelfCalScheduleStatus{
	EM_SC_SCHEDULE_OFF,					/* disable schedule */
	EM_SC_SCHEDULE_ON_POWERSAVE,		/* start when monitor changes into power save */
	EM_SC_SCHEDULE_ON_IMMEDIATELY		/* start immediately */
}EM_SelfCalScheduleStatus;

/** enumeration to specify a type of SelfCalibration schedule */
typedef enum _EM_SelfCalScheduleType{
	EM_SC_SCHEDULE_TYPE1,
	EM_SC_SCHEDULE_TYPE2,
	EM_SC_SCHEDULE_TYPE3
}EM_SelfCalScheduleType;

/** enumeration to specify the day of the week */
typedef enum _EM_DayOfWeek{
	EM_SUNDAY,
	EM_MONDAY,
	EM_TUESDAY,
	EM_WEDNESDAY,
	EM_THURSDAY,
	EM_FRIDAY,
	EM_SATURDAY
}EM_DayOfWeek;

/** enumeration to specify a SelfCalibration schedule */
typedef struct _EM_SelfCalSchedule{
	unsigned char	month;
	unsigned char	week;
	EM_DayOfWeek	dayOfWeek;
	unsigned short	hour;
	unsigned char	minute;
}EM_SelfCalSchedule;

/** structure to specify the current time */
typedef struct _EM_Time{
	unsigned char	minute;
	unsigned char	hour;
	unsigned char	day;
	unsigned char	month;
	unsigned short	year;
}EM_Time;

/** enumeration to specify the Integrated Front Sensor status */
typedef enum _EM_IntegratedFrontSensorStatus{
	EM_IFSSTATUS_OPEN,
	EM_IFSSTATUS_CLOSE,
}EM_IntegratedFrontSensorStatus;

/** enumeration to specify the monitor mutex status */
typedef enum _EM_Mutex{
	EM_MUTEX_LOCK,						/* Mutex Lock */
	EM_MUTEX_UNLOCK						/* Mutex Unlock */
}EM_Mutex;

/** enumeration to specify the backlight status */
typedef enum _EM_Backlight{
	EM_BACKLIGHT_OFF,					/* Backlight Off */
	EM_BACKLIGHT_ON						/* Backlight On */
}EM_Backlight;

/** enumeration to specify the Display Resolution command */
typedef enum _EM_DisplayResolutionCommand{
	EM_DRCMD_ON,
	EM_DRCMD_OFF,
	EM_DRCMD_ON_DOUBLED_SIZE,
	EM_DRCMD_ON_QUAD_SIZE
}EM_DisplayResolutionCommand;

/** structure to specify the Display Resolution rect  */
typedef struct _EM_DisplayResolutionRect{
	unsigned long		rectX;				/* rect pos X */
	unsigned long		rectY;				/* rect pos Y */
	unsigned long		rectWidth;			/* rect width */
	unsigned long		rectHeight;			/* rect height */
}EM_DisplayResolutionRect;

typedef enum _EM_ColorModeSetting
{
	EM_CMSETTING_NATIVE,
	EM_CMSETTING_ADOBERGB,
	EM_CMSETTING_SRGB,
	EM_CMSETTING_EBU,
	EM_CMSETTING_REC709,
	EM_CMSETTING_REC1886,
	EM_CMSETTING_SMPTEC,
	EM_CMSETTING_DCI,
	EM_CMSETTING_CAL			= 1000
}EM_ColorModeSetting;

#endif	/* __EM_TYPES_H__ */
