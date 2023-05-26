//----------------------------------------------------------------------------
//	CATMMediaImageFilePageInfo.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageFilePageInfo_H
#define CATMMediaImageFilePageInfo_H

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaRasterFormats_SB_File.h"
#include "CATMMediaImageDimension.h"
#include "CATBoolean.h"

//class ExportedByCATMMediaRasterFormats CATMMediaImageTileInfo
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageTileInfo
{
};

//class ExportedByCATMMediaRasterFormats CATMMediaImageFilePageInfo : public CATMMediaImageDimension
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFilePageInfo : public CATMMediaImageDimension
{
public:
	CATMMediaImageFilePageInfo() : CATMMediaImageDimension(), _BitPerPixel(0), _bTiled(FALSE) {}
	~CATMMediaImageFilePageInfo() {}

	int GetPageSize() const							{ return (GetWidth()*GetHeight()*_BitPerPixel/8); }
	int GetBitPerPixel() const						{ return _BitPerPixel; }
	CATBoolean IsTiled() const						{ return _bTiled; }

	void SetBitPerPixel(const int iBitPerPixel)		{ _BitPerPixel = iBitPerPixel; }
	void SetTiled(const CATBoolean ibTiled)			{ _bTiled = ibTiled; }

private:
	int						_BitPerPixel;
	CATBoolean				_bTiled;
	CATMMediaImageTileInfo	_Tile;
};

#endif // CATMMediaImageFilePageInfo_H
