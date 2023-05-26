//----------------------------------------------------------------------------
//	CATMMediaImageOption.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageOption_H
#define CATMMediaImageOption_H

#include "CATMMediaRasterFormats_SB_File.h"
//#include "CATMMediaImageDef.h"
#include "CATMMediaImageFileDef.h"
#include "CATBoolean.h"

/** @nodoc */
//class ExportedByCATMMediaRasterFormats CATMMediaImageOption
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageOption
{
public:
	CATMMediaImageOption();
	virtual ~CATMMediaImageOption();

	void SetLineAlignment(const CATMMediaImageAlignment iAlignment)		{ _LineAlignment = iAlignment; }
	CATMMediaImageAlignment GetLineAlignment() const					{ return _LineAlignment; }
	CATBoolean IsLineAlignmentNone() const								{ return (_LineAlignment == MMIA_None); }
	int GetAlignedSize(const int iBitWidth) const;
	int GetAlignedSize(const int iBitWidth, const int iHeight) const;
	
	void SetPhotometric(const CATMMediaImagePhotometric iPhotometric)	{ _Photometric = iPhotometric; }
	CATMMediaImagePhotometric GetPhotometric() const					{ return _Photometric; }
	CATBoolean IsWhiteZero() const										{ return (_Photometric == MMIP_WhiteIsZero); }
	CATBoolean IsWhiteOne() const										{ return (_Photometric == MMIP_WhiteIsOne); }
	CATBoolean IsBlackZero() const										{ return (_Photometric == MMIP_BlackIsZero); }
	CATBoolean IsBlackOne() const										{ return (_Photometric == MMIP_BlackIsOne); }

private:
	CATMMediaImagePhotometric	_Photometric;
	CATMMediaImageAlignment		_LineAlignment;
};


/** @nodoc */
//class ExportedByCATMMediaRasterFormats CATMMediaImageEncodingOption : public CATMMediaImageOption
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageEncodingOption : public CATMMediaImageOption
{
public:
	CATMMediaImageEncodingOption() : CATMMediaImageOption() {}
	virtual ~CATMMediaImageEncodingOption() {}
};

/** @nodoc */
//class ExportedByCATMMediaRasterFormats CATMMediaImageDecodingOption : public CATMMediaImageOption
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageDecodingOption : public CATMMediaImageOption
{
public:
	CATMMediaImageDecodingOption() : CATMMediaImageOption() {}
	virtual ~CATMMediaImageDecodingOption() {}
};

#endif // CATMMediaImageOption_H
