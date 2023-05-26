//----------------------------------------------------------------------------
//	CATMMediaImageFileDef.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageFileDefinitions_H
#define CATMMediaImageFileDefinitions_H

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaRasterFormats_SB_File.h"

#ifndef _RASTER_PROP_TYPES_DEFINED
#define _RASTER_PROP_TYPES_DEFINED

enum ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFileCompression
{
	MMIFC_DEFAULT	= 0,
	MMIFC_UNKNOW,
	MMIFC_NONE,
	MMIFC_RLE,
	MMIFC_HUFFMAN,
	MMIFC_PACKBITS,
	MMIFC_JPEG,
	MMIFC_G3,
	MMIFC_G4,
	MMIFC_CCITT,			// generic for g3,g4 ...
	// Licence limited
	MMIFC_GIF,
	MMIFC_LZW,
	MMIFC_JPEG2000,
	MMIFC_JBIG,
	MMIFC_MAX				// this is not a compression type !
};

enum ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFileType
{
	MMIFT_UNKNOW	= 0,
	MMIFT_TIFF,
	MMIFT_BMP,
	MMIFT_PCX,
	MMIFT_TARGA,
	MMIFT_GIF,
	MMIFT_WPG,
	MMIFT_WMF,
	MMIFT_DCX,
	MMIFT_JPEG,
	MMIFT_EPS,
	MMIFT_PICT,
	MMIFT_CALS,
	MMIFT_LASER_DATA,
	MMIFT_XBM,
	MMIFT_MACPAINT,
	MMIFT_GX2,
	MMIFT_KOFAX,
	MMIFT_IOCA,
	MMIFT_ICONTYPE,
	MMIFT_IFF_ILBM,
	MMIFT_CLIP,
	MMIFT_IMG,
	MMIFT_BROOK_TROUT,
	MMIFT_MSP,
	MMIFT_CUT,
	MMIFT_CCITT,
	MMIFT_XPM,
	MMIFT_XWD,
	MMIFT_RAST,
	MMIFT_ASCII,
	MMIFT_PHOTOCD,
	MMIFT_PHOTOSHOP,
	MMIFT_IMNET,
	MMIFT_PNG,
	MMIFT_DIB,
	MMIFT_FLASH_PIX,
	MMIFT_DICOM,
	MMIFT_JEDMICS,
	MMIFT_PCL_1,
	MMIFT_WINFAX,
	MMIFT_PDF,
	MMIFT_SCITEX,
	MMIFT_MAG,
	MMIFT_DCS,
	MMIFT_NCR,
	MMIFT_WBMP,
	MMIFT_JPEG2000,
	MMIFT_COD,
	MMIFT_CIMS,
	MMIFT_MAX				// this is not a format !
};
#endif

/*
 * file Bits per pixel
 */
enum ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFileBPP
{
	BPP_NO	=	0,
	BPP_ALL	=	~0,
	BPP_1	=	1<<0,
	BPP_2	=	1<<1,
	BPP_3	=	1<<2,
	BPP_4	=	1<<3,
	BPP_5	=	1<<4,
	BPP_6	=	1<<5,
	BPP_7	=	1<<6,
	BPP_8	=	1<<7,
	BPP_15	=	1<<14,
	BPP_16	=	1<<15,
	BPP_24	=	1<<23,
	BPP_32	=	1<<31,
	
	BPP_1_8_24 = BPP_1 | BPP_8 | BPP_24,
	BPP_1_4_8_24 = BPP_1_8_24 | BPP_4,
	BPP_1_4_8_16_24 = BPP_1_4_8_24 | BPP_16,
	BPP_1_2_4_8_16_24_32 = BPP_1_4_8_16_24 | BPP_2 | BPP_32,
	BPP_4_8_24 = BPP_4 | BPP_8 | BPP_24,
	BPP_8_24 = BPP_8 | BPP_24,
	BPP_8_16_24 = BPP_8 | BPP_16 | BPP_24,
	BPP_8_16_24_32 = BPP_8_16_24 | BPP_24,
	BPP_8_24_32 = BPP_8 | BPP_24 | BPP_24,
	BPP_4_8 = BPP_4 | BPP_8,
	BPP_1_4 = BPP_1 | BPP_4,
	BPP_1_4_8 = BPP_1_4 | BPP_8,
	BPP_1_4_8_24_32 = BPP_1_4_8 | BPP_24 | BPP_32,
	BPP_1_4_8_15_24_32 = BPP_1_4_8_24_32 | BPP_15,
	BPP_1_4_8_16_24_32 = BPP_1_4_8_24_32 | BPP_16,
	BPP_1_8_24_32 = BPP_1 | BPP_8 | BPP_24 | BPP_32,
	BPP_1_24 = BPP_1 | BPP_24,
	BPP_24_32 = BPP_24 | BPP_32,
	BPP_2_3_4_5_6_7_8 = BPP_2 | BPP_3 | BPP_4 | BPP_5 | BPP_6 | BPP_7 | BPP_8
};

// Transfert de CATMMediaImageType de CATMMediaImageDef.h vers CATMMediaImageFileDef.h
enum ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageType
{
        MMIT_INVALID = -1,
        MMIT_RGB = 0,           // Red 8 bit, Green 8 bits, Blue 8 bits
        MMIT_RGBA,                      // Red 8 bit, Green 8 bits, Blue 8 bits, Alpha 8 bits
        MMIT_L,                         // Luminance = Gray 8 bits
        MMIT_LA,                        // Luminance + Alpha = Gray 8 bits + Alpha 8 bits
        MMIT_BILEVEL,
        MMIT_RLE,
        MMIT_PACKBIT,
        MMIT_G3_1D,                     // CCITT group 3 T4 1d, modified Huffman, Run lenght
        MMIT_G3,                        // CCITT group 3 T4 2d
        MMIT_G4,                        // CCITT group 4 T6 2d
        MMIT_LZW,
        MMIT_JPEG
};

// Transfert de CATMMediaImageType de CATMMediaImageDef.h vers CATMMediaImageFileDef.h
enum ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageAlignment 
{ 
	MMIA_None,			// no alignement (possible bit to bit if bilevel format)
	MMIA_1byte,			// align to char (bilevel only)
	MMIA_2bytes,		// align to WORD
	MMIA_4bytes			// align to DWORD
};

// Transfert de CATMMediaImageType de CATMMediaImageDef.h vers CATMMediaImageFileDef.h
enum ExportedByCATMMediaRasterFormats_SB_File CATMMediaImagePhotometric 
{ 
	MMIP_WhiteIsZero,
	MMIP_BlackIsOne	 = MMIP_WhiteIsZero,
	MMIP_WhiteIsOne,
	MMIP_BlackIsZero = MMIP_WhiteIsOne
};

#endif // CATMMediaImageFileDef_H
