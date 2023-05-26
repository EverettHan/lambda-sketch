/*
*  CATMMCMSType.h
*
*  Created by o1x on 05/09/2013.
*  Copyright 2013 Dassault Systemes. All rights reserved.
*
*/
#ifndef CATMMCMSType_H
// COPYRIGHT DASSAULT SYSTEMES 2013

#define CATMMCMSType_H

/* ICC Intents*/
#define MM_CMS_INTENT_PERCEPTUAL                              0
#define MM_CMS_CAT_INTENT_RELATIVE_COLORIMETRIC               1
#define MM_CMS_INTENT_SATURATION                              2
#define MM_CMS_INTENT_ABSOLUTE_COLORIMETRIC                   3


typedef enum {
             CATcmsInfoDescription  = 0,
             CATcmsInfoManufacturer = 1,
             CATcmsInfoModel        = 2,
             CATcmsInfoCopyright    = 3
} CATcmsInfoType;

typedef enum {
			CATcmsSigXYZData                           = 0x58595A20,  /* 'XYZ '*/
			CATcmsSigLabData                           = 0x4C616220,  /* 'Lab '*/
			CATcmsSigLuvData                           = 0x4C757620,  /* 'Luv '*/
			CATcmsSigYCbCrData                         = 0x59436272,  /* 'YCbr'*/
			CATcmsSigYxyData                           = 0x59787920,  /* 'Yxy '*/
			CATcmsSigRgbData                           = 0x52474220,  /* 'RGB '*/
			CATcmsSigGrayData                          = 0x47524159,  /* 'GRAY'*/
			CATcmsSigHsvData                           = 0x48535620,  /* 'HSV '*/
			CATcmsSigHlsData                           = 0x484C5320,  /* 'HLS '*/
			CATcmsSigCmykData                          = 0x434D594B,  /* 'CMYK'*/
			CATcmsSigCmyData                           = 0x434D5920,  /* 'CMY '*/
			CATcmsSigOtherData
} CATcmsColorSpaceSignature;

typedef void* CATcmsHPROFILE;             /* Opaque typedefs to hide internals*/
typedef void* CATcmsHTRANSFORM;


typedef enum  {
		eDELTA_E_76 = 0,
		eDELTA_E_CMC_84,
		eDELTA_E_BFD_84,
		eDELTA_E_94,
		eDELTA_E_2000,
} DELTA_E_METHOD;



/* Format of pixel is defined by one int, using bit fields as follows*/
/**/
/*                               2                1          0*/
/*                          3 2 10987 6 5 4 3 2 1 098 7654 321*/
/*                          A O TTTTT U Y F P X S EEE CCCC BBB*/
/**/
/*            A: Floating point -- With this flag we can differentiate 16 bits as float and as int*/
/*            O: Optimized -- previous optimization already returns the final 8-bit value*/
/*            T: Pixeltype*/
/*            F: Flavor  0=MinIsBlack(Chocolate) 1=MinIsWhite(Vanilla)*/
/*            P: Planar? 0=Chunky, 1=Planar*/
/*            X: swap 16 bps endianess?*/
/*            S: Do swap? ie, BGR, KYMC*/
/*            E: Extra samples*/
/*            C: Channels (Samples per pixel)*/
/*            B: bytes per sample*/
/*            Y: Swap first - changes ABGR to BGRA and KCMY to CMYK*/

#define MM_CMS_FLOAT_SH(a)            ((a) << 22)
#define MM_CMS_OPTIMIZED_SH(s)        ((s) << 21)
#define MM_CMS_COLORSPACE_SH(s)       ((s) << 16)
#define MM_CMS_SWAPFIRST_SH(s)        ((s) << 14)
#define MM_CMS_FLAVOR_SH(s)           ((s) << 13)
#define MM_CMS_PLANAR_SH(p)           ((p) << 12)
#define MM_CMS_ENDIAN16_SH(e)         ((e) << 11)
#define MM_CMS_DOSWAP_SH(e)           ((e) << 10)
#define MM_CMS_EXTRA_SH(e)            ((e) << 7)
#define MM_CMS_CHANNELS_SH(c)         ((c) << 3)
#define MM_CMS_BYTES_SH(b)            (b)

/* These macros unpack format specifiers into integers*/
#define MM_CMS_T_FLOAT(a)            (((a)>>22)&1)
#define MM_CMS_T_OPTIMIZED(o)        (((o)>>21)&1)
#define MM_CMS_T_COLORSPACE(s)       (((s)>>16)&31)
#define MM_CMS_T_SWAPFIRST(s)        (((s)>>14)&1)
#define MM_CMS_T_FLAVOR(s)           (((s)>>13)&1)
#define MM_CMS_T_PLANAR(p)           (((p)>>12)&1)
#define MM_CMS_T_ENDIAN16(e)         (((e)>>11)&1)
#define MM_CMS_T_DOSWAP(e)           (((e)>>10)&1)
#define MM_CMS_T_EXTRA(e)            (((e)>>7)&7)
#define MM_CMS_T_CHANNELS(c)         (((c)>>3)&15)
#define MM_CMS_T_BYTES(b)            ((b)&7)


/* Pixel types*/
#define MM_CMS_PT_ANY       0    /* Don't check colorspace*/
                          /* 1 & 2 are reserved*/
#define MM_CMS_PT_GRAY      3
#define MM_CMS_PT_RGB       4



#define PT_LabV2     30     /* Identical to PT_Lab, but using the V2 old encoding*/

#define MM_CMS_TYPE_RGB_8             (MM_CMS_COLORSPACE_SH(MM_CMS_PT_RGB)|MM_CMS_CHANNELS_SH(3)|MM_CMS_BYTES_SH(1))

/* Some (not all!) representations*/

#endif  // CATMMCMSType_H


