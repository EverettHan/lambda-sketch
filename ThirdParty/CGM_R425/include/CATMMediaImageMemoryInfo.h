//----------------------------------------------------------------------------
//	CATMMediaImageMemoryInfo.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageMemoryInfo_H
#define CATMMediaImageMemoryInfo_H

#include "CATMMediaRasterFormats_SB_File.h"
#include "CATMMediaImageDimension.h"
#include "CATMMediaImageDef.h"
//#include "CATPixelImage.h"

class CATPixelImage;

class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageMemoryInfo : public CATMMediaImageDimension
{
public:
    CATMMediaImageMemoryInfo();
	CATMMediaImageMemoryInfo(const CATPixelImage * const ipImage);
	virtual ~CATMMediaImageMemoryInfo();

	CATMMediaImagePixelFormat GetPixelFormat() const	{ return _PixelFormat; }
	long GetSize() const								{ return _Size; }
	int GetPages() const								{ return _Pages; }

private:
	// useless default methods intentionally not accessible (and not generated):
    CATMMediaImageMemoryInfo(const CATMMediaImageMemoryInfo&);
    CATMMediaImageMemoryInfo * operator&();
    const CATMMediaImageMemoryInfo * operator&() const;

	void SetPixelFormat(const CATMMediaImagePixelFormat iFormat) { _PixelFormat = iFormat; }
	void SetSize(const long iSize)						{ _Size = iSize; }
	void SetPages(const int iPages)						{ _Pages = iPages; }

	long	_Size;
	int		_Pages;
	CATMMediaImagePixelFormat	_PixelFormat;
};

#endif // CATMMediaImageMemoryInfo_H
