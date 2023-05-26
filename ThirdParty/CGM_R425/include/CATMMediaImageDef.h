//----------------------------------------------------------------------------
//	CATMMediaImageDef.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageDef_H
#define CATMMediaImageDef_H

//#include "CATMMediaRasterFormats.h"
#include "BigLittle.h"
#include "CATMMediaRasterProcessor_Base.h"

#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef uint
typedef unsigned int uint;
#endif

// Transfert de CATMMediaImageType de CATMMediaImageDef.h vers CATMMediaImageFileDef.h
/** @nodoc */
/*
enum ExportedByCATMMediaRasterFormats CATMMediaImageAlignment 
{ 
	MMIA_None,			// no alignement (possible bit to bit if bilevel format)
	MMIA_1byte,			// align to char (bilevel only)
	MMIA_2bytes,		// align to WORD
	MMIA_4bytes			// align to DWORD
};
*/

// Transfert de CATMMediaImageType de CATMMediaImageDef.h vers CATMMediaImageFileDef.h
/** @nodoc */
/*
enum ExportedByCATMMediaRasterFormats CATMMediaImagePhotometric 
{ 
	MMIP_WhiteIsZero,
	MMIP_BlackIsOne	 = MMIP_WhiteIsZero,
	MMIP_WhiteIsOne,
	MMIP_BlackIsZero = MMIP_WhiteIsOne
};
*/

/** @nodoc */
//enum ExportedByCATMMediaRasterFormats CATMMediaImagePixelFormat
enum ExportedByCATMMediaRasterProcessor_Base CATMMediaImagePixelFormat
{
	MMIPF_INVALID		= -1,
	MMIPF_BILEVEL		= 0,
	MMIPF_L,
	MMIPF_L_8			= MMIPF_L,
	MMIPF_LA,
	MMIPF_LA_88			= MMIPF_LA,
	MMIPF_RGB,
	MMIPF_RGB_888		= MMIPF_RGB,
	MMIPF_RGBA,
	MMIPF_RGBA_8888		= MMIPF_RGBA,	
	
	MMIPF_AL_88,		// alternative 16 bits
	MMIPF_RGB_555,
	MMIPF_RGB_565,
	MMIPF_RGBA_5551,
	MMIPF_RGBA_4444,
	MMIPF_ARGB_1555,
	MMIPF_ARGB_4444,
	MMIPF_BGR_555,
	MMIPF_BGR_565,
	MMIPF_BGRA_5551,
	MMIPF_BGRA_4444,
	MMIPF_ABGR_1555,
	MMIPF_ABGR_4444,
	
	MMIPF_BGR_888,		// alternative 24 bits

	MMIPF_ARGB_8888,	// alternative 32 bits
	MMIPF_BGRA_8888,
	MMIPF_ABGR_8888
};

// Transfert de CATMMediaImageType de CATMMediaImageDef.h vers CATMMediaImageFileDef.h
/** @nodoc */
/*
enum ExportedByCATMMediaRasterFormats CATMMediaImageType 
{
	MMIT_INVALID = -1,
	MMIT_RGB = 0,		// Red 8 bit, Green 8 bits, Blue 8 bits
	MMIT_RGBA,			// Red 8 bit, Green 8 bits, Blue 8 bits, Alpha 8 bits
	MMIT_L,				// Luminance = Gray 8 bits
	MMIT_LA,			// Luminance + Alpha = Gray 8 bits + Alpha 8 bits
	MMIT_BILEVEL,
	MMIT_RLE,
	MMIT_PACKBIT,
	MMIT_G3_1D,			// CCITT group 3 T4 1d, modified Huffman, Run lenght
	MMIT_G3,			// CCITT group 3 T4 2d
	MMIT_G4,			// CCITT group 4 T6 2d
	MMIT_LZW,
	MMIT_JPEG
};
*/

/** @nodoc */
typedef void (*CATMMIProgressCB)(float);

/** @nodoc */
/**
 * @ingroup groupPixelImageBufferAccess
 * @brief Restricted to RGB and RGBA.
 */
typedef unsigned int CATMMIColor;

#ifdef _ENDIAN_LITTLE

	inline uint GetR(CATMMIColor iColor) { return (iColor & 0xFF); }
	inline uint GetG(CATMMIColor iColor) { return ((iColor>>8) & 0xFF); }
	inline uint GetB(CATMMIColor iColor) { return ((iColor>>16) & 0xFF); }
	inline uint GetA(CATMMIColor iColor) { return ((iColor>>24) & 0xFF); }

	// --- MakeRGB ---
	inline CATMMIColor MakeRGB(uchar iR, uchar iG, uchar iB)
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16)); }

	inline CATMMIColor MakeRGB(uint iR, uint iG, uint iB)
		{ return (iR | (iG<<8) | (iB<<16)); }

	inline CATMMIColor MakeRGB(int iR, int iG, int iB)
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16)); }

	inline CATMMIColor MakeRGB(float iR, float iG, float iB)
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16)); }

	inline CATMMIColor MakeRGB(double iR, double iG, double iB)
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16)); }

	// --- MakeRGBA ---
	inline CATMMIColor MakeRGBA(uchar iR, uchar iG, uchar iB, uchar iA)
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16) | ((uint)(iA)<<24)); }

	inline CATMMIColor MakeRGBA(uint iR, uint iG, uint iB, uint iA)
		{ return (iR | (iG<<8) | (iB<<16) | (iA<<24)); }

	inline CATMMIColor MakeRGBA(int iR, int iG, int iB, int iA) 
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16) | ((uint)(iA)<<24)); }

	inline CATMMIColor MakeRGBA(float iR, float iG, float iB, float iA) 
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16) | ((uint)(iA)<<24)); }

	inline CATMMIColor MakeRGBA(double iR, double iG, double iB, double iA) 
		{ return ((uint)(iR) | ((uint)(iG)<<8) | ((uint)(iB)<<16) | ((uint)(iA)<<24)); }

#else // UNIX

	inline uint GetR(CATMMIColor iColor) { return ((iColor>>24) & 0xFF); }
	inline uint GetG(CATMMIColor iColor) { return ((iColor>>16) & 0xFF); }
	inline uint GetB(CATMMIColor iColor) { return ((iColor>>8) & 0xFF); }
	inline uint GetA(CATMMIColor iColor) { return (iColor & 0xFF); }
	
	// --- MakeRGB ---
	inline CATMMIColor MakeRGB(uchar iR, uchar iG, uchar iB)
		{ return (((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }

	inline CATMMIColor MakeRGB(uint iR, uint iG, uint iB)
		{ return ((iB<<8) | (iG<<16) | (iR<<24)); }

	inline CATMMIColor MakeRGB(int iR, int iG, int iB) 
		{ return (((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }

	inline CATMMIColor MakeRGB(float iR, float iG, float iB) 
		{ return (((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }

	inline CATMMIColor MakeRGB(double iR, double iG, double iB) 
		{ return (((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }
	
	// --- MakeRGBA ---
	inline CATMMIColor MakeRGBA(uchar iR, uchar iG, uchar iB, uchar iA)
		{ return ((uint)(iA) | ((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }

	inline CATMMIColor MakeRGBA(uint iR, uint iG, uint iB, uint iA)
		{ return (iA | (iB<<8) | (iG<<16) | (iR<<24)); }

	inline CATMMIColor MakeRGBA(int iR, int iG, int iB, int iA) 
		{ return ((uint)(iA) | ((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }

	inline CATMMIColor MakeRGBA(float iR, float iG, float iB, float iA) 
		{ return ((uint)(iA) | ((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }

	inline CATMMIColor MakeRGBA(double iR, double iG, double iB, double iA) 
		{ return ((uint)(iA) | ((uint)(iB)<<8) | ((uint)(iG)<<16) | ((uint)(iR)<<24)); }

#endif

/** @nodoc */
// --- defines image color planes ---
typedef int CATMMIPlane;
enum 
{
	MMI_PLN_None	= 0,
	MMI_PLN_L		= 1<<0,
	MMI_PLN_R		= 1<<1,
	MMI_PLN_G		= 1<<2,
	MMI_PLN_B		= 1<<3,
	MMI_PLN_A		= 1<<4,
	MMI_PLN_LA		= MMI_PLN_L | MMI_PLN_A,
	MMI_PLN_RGB		= MMI_PLN_R | MMI_PLN_G | MMI_PLN_B,
	MMI_PLN_RGBA	= MMI_PLN_RGB | MMI_PLN_A,
	MMI_PLN_All		= MMI_PLN_L | MMI_PLN_R | MMI_PLN_G | MMI_PLN_B | MMI_PLN_A
};

/** @nodoc */
// --- Brushes ---
//enum ExportedByCATMMediaRasterFormats CATMMIBrush
enum ExportedByCATMMediaRasterProcessor_Base CATMMIBrush
{
	MMI_BSH_Point1 = 0,
	MMI_BSH_Point2,
	MMI_BSH_Point3,
	MMI_BSH_Square1,
	MMI_BSH_Square2,
	MMI_BSH_Square3,
	MMI_BSH_Line1,
	MMI_BSH_Line2,
	MMI_BSH_Line3,
	MMI_BSH_Line4,
	MMI_BSH_Line5,
	MMI_BSH_Line6,
	MMI_BSH_Aero,
	MMI_BSH_Max
};

#endif // CATMMediaImageDef_H
