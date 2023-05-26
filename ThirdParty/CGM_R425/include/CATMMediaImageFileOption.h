//----------------------------------------------------------------------------
//	CATMMediaImageFileOption.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageFileOption_H
#define CATMMediaImageFileOption_H

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaRasterFormats_SB_File.h"
#include "CATMMediaImageFileDef.h"
#include "CATBoolean.h"

/*
 * Preferences when writing a raster file
 */
typedef int CATMMediaImageWritePreference;

/*
 *	Main preference :
 *	MMIWP_KEEP_IMAGE_RESOLUTION : 
 *		means that image can't decrease in bits per pixel
 *		resolution when flush to disk.
 *		Image can however use lose compression.
 *	MMIWP_FORCE_FILE_FORMAT :		
 *		Image is adapted to math with file format/compression.
 *		Image can lose quality with a loseless compression,
 *		while image is first convert to file format bits per pixel.
 */
#define	MMIWP_KEEP_IMAGE_RESOLUTION	(0x0001)
#define	MMIWP_FORCE_FILE_FORMAT		(0x0002)
#define	MMIWP_ALLOW_MULTIPAGES		(0x0004)

/*
 *	Conversion preferences :
 *	You can specify the algorithm use when decrease color depth :
 *	4, 8 or 24 bits per pixel to 1 bit per pixel use MONO.
 *	With MMIWP_MONO_TRESH you can specify a quality as tresh in write options.
 */
#define	MMIWP_MONO_BAYER			(0x0010)
#define	MMIWP_MONO_DIFFUSION		(0x0020)
#define	MMIWP_MONO_HALFTONE			(0x0040)
#define	MMIWP_MONO_TRESH			(0x0080)

#define	MMIWP_COLOR_OCTREE			(0x0100)
#define	MMIWP_COLOR_MEDIANCUT		(0x0200)
#define	MMIWP_COLOR_BAYER			(0x0400)
#define	MMIWP_COLOR_DIFFUSION		(0x0800)
#define	MMIWP_COLOR_POPULARITY		(0x1000)

#define	MMIWP_DEFAULT				(MMIWP_FORCE_FILE_FORMAT | MMIWP_MONO_BAYER | MMIWP_COLOR_OCTREE)


/*
 * You should not derive this class !
 */
//class ExportedByCATMMediaRasterFormats CATMMediaImageFileOption
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFileOption
{
public:
	CATMMediaImageFileOption();

	/*
	 * Compression, MMIFC_NONE by default
	 * If you want compression but don't available compression types with the file format type
	 * use SetCompression() without parameter, we will deal with default.
	 */
	void SetCompression(const CATMMediaImageFileCompression iCompression = MMIFC_UNKNOW) { _Compression = iCompression; }
	CATMMediaImageFileCompression GetCompression() const;
	CATBoolean HasDefaultCompression() const				{ return (_Compression == MMIFC_DEFAULT); }
	CATBoolean HasCompression() const						{ return (!HasDefaultCompression() && (_Compression != MMIFC_NONE)); }

	/*
	 * Write Preference, MMIWP_DEFAULT by default
	 */
	void SetPreference(CATMMediaImageWritePreference iPreference)	{ _Preference = iPreference; }
	CATMMediaImageWritePreference GetPreference() const				{ return _Preference; }
	CATBoolean MustKeepImageResolution() const						{ return ((_Preference & MMIWP_KEEP_IMAGE_RESOLUTION) != 0); }
	CATBoolean AllowMultipages() const								{ return ((_Preference & MMIWP_ALLOW_MULTIPAGES) != 0); }

	/*
	 * Quality (for compression)
	 * Range is : Low [0.0, 1.0] Hight (default)
	 */
	void SetQuality(const float iQuality)	{ if (iQuality < 0.0) _Quality = 0.0f; else if (iQuality > 1.0) _Quality = 1.0f; else _Quality = iQuality; }
	float GetQuality() const;
	
	/*
	 * Dpi, Dots per inch (usage for printing)
	 * 0 means don't care about (default)
	 */
	void SetDpi(const int iDpi) { if (iDpi < 0) _Dpi = 0; else _Dpi = iDpi; }
	int GetDpi() const;
	CATBoolean HasDpi() const	{ return (_Dpi != 0); }
	/*
	 * Bpp, Bits per pixel 
	 * Valid range is [1, 32] 
	 * 0 means don't care about (default)
	 */
	void SetBpp(const CATMMediaImageFileBPP iBpp)	{ _Bpp = iBpp; }
	CATMMediaImageFileBPP GetBpp() const			{ return _Bpp; }
	CATBoolean HasBpp() const						{ return (_Bpp != BPP_NO); }

/*
	CATMMediaImageFileOption(const CATMMediaImageFileOption& iOther)
	{
		_Compression	=	iOther._Compression;
		_Bpp			=	iOther._Bpp;
		_Preference		=	iOther._Preference;
		_Quality		=	iOther._Quality;
		_Dpi			=	iOther._Dpi;
	}

	CATMMediaImageFileOption& operator=(const CATMMediaImageFileOption& iOther)
	{
		_Compression	=	iOther._Compression;
		_Bpp			=	iOther._Bpp;
		_Preference		=	iOther._Preference;
		_Quality		=	iOther._Quality;
		_Dpi			=	iOther._Dpi;
		return *this;
	}
*/
protected:
	friend class CATMMediaImageFileManager;

	// --- Internal use ---
/*
	CATBoolean UseMonoBayer() const			{ return ((_Preference & MMIWP_MONO_BAYER) != 0); }
	CATBoolean UseMonoDiffusion() const		{ return ((_Preference & MMIWP_MONO_DIFFUSION) != 0); }
	CATBoolean UseMonoHalfTone() const		{ return ((_Preference & MMIWP_MONO_HALFTONE) != 0); }
	CATBoolean UseMonoTresh() const			{ return ((_Preference & MMIWP_MONO_TRESH) != 0); }
	CATBoolean UseColorOctree() const		{ return ((_Preference & MMIWP_COLOR_OCTREE) != 0); }
	CATBoolean UseColorMedianCut() const	{ return ((_Preference & MMIWP_COLOR_MEDIANCUT) != 0); }
	CATBoolean UseColorBayer() const		{ return ((_Preference & MMIWP_COLOR_BAYER) != 0); }
	CATBoolean UseColorDiffusion() const	{ return ((_Preference & MMIWP_COLOR_DIFFUSION) != 0); }
*/

private:
	CATMMediaImageFileCompression	_Compression;
	CATMMediaImageFileBPP			_Bpp;
	CATMMediaImageWritePreference	_Preference;
	float							_Quality;
	int								_Dpi;
};

#endif // CATMMediaImageFileOption_H
