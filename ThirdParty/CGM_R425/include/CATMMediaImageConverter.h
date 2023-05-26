//----------------------------------------------------------------------------
//	CATMMediaImageConverter.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageConverter_H
#define CATMMediaImageConverter_H

#include "CATMMediaRasterFormats_SB_File.h"
#include "CATMMediaImageFileDef.h" // Transfert de CATMMediaImageType de CATMMediaImageDef.h vers CATMMediaImageFileDef.h
#include "CATMMediaImageOption.h"
//#include "CATPixelImage.h"

class CATPixelImage;

#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef NULL
#define NULL 0
#endif

/** @nodoc */
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageConverter
{
public:
	/** @nodoc */
	static uchar * CreateBitmap(
			const CATPixelImage& iImage,
			int& oSize,
			const CATMMediaImageType iType = MMIT_RGB,
			const CATMMediaImageEncodingOption * const iprOption = NULL);

	/** @nodoc */
	static CATPixelImage * CreatePixelImage(
			const uchar * const iprBitmap,
			const int iSize,
			const int iSizeX, const int iSizeY,
			const CATMMediaImageType iType = MMIT_RGB,
			const CATMMediaImageDecodingOption * const iprOption = NULL);

	/** @nodoc */
#ifdef _WINDOWS_SOURCE		
	static char * CreateDIB(
			const CATPixelImage& iImage,
			int& oDibSize,HGLOBAL& ohDib);
#else
    static char *CreateDIB(const CATPixelImage& iImage,
			int& oDibSize);
#endif

private:
	// useless default methods intentionally not accessible (and not generated)
    CATMMediaImageConverter();
    CATMMediaImageConverter(const CATMMediaImageConverter&);
    ~CATMMediaImageConverter();
    CATMMediaImageConverter& operator=(const CATMMediaImageConverter&);
    CATMMediaImageConverter * operator&();
    const CATMMediaImageConverter * operator&() const;
};

#endif // CATMMediaImageConverter_H
