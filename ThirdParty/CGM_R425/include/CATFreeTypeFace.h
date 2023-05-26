//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2011/10/20
//===================================================================
// CATFreeTypeFace.cpp
// Header definition of class CATFreeTypeFace
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/10/20 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATFreeTypeFace_H
#define CATFreeTypeFace_H


#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATUnicodeChar.h"
#include "CATFreeType.h"
#include "vector.h"
#include <unordered_map>

//-----------------------------------------------------------------------

#ifdef VISU_ENABLE_FREETYPE
typedef struct FT_FaceRec_* FT_Face;  
#endif // VISU_ENABLE_FREETYPE

class CATFreeTypeFactory;
class CATFreeTypeFontFile;

//-----------------------------------------------------------------------

class ExportedBySGInfra CATFreeTypeFace : public CATBaseUnknown
{
	friend class CATFreeTypeFactory;
public:
	typedef CATUC2Bytes CharType;
public:
	//! Set the size of the EM square in device units (=char_height in Windows)
	HRESULT SetPixelSize(int size);

	//! Set the point size of the font (1 pt = 1/72 of an inch)
	HRESULT SetPointSize(int size, int Hres, int Vres);

	//! Retrieve global metrics for the face
	HRESULT GetGlobalMetrics(CATFreeType::GlobalMetrics* metrics) const;

	//! Retrieve image metrics for a character
	HRESULT GetGlyphAdvance(CharType charcode, CATFreeType::GlyphAdvance* advance) const;

	//! Retrieve image metrics for a character
	HRESULT GetGlyphMetrics(CharType charcode, CATFreeType::ImageMetrics* metrics) const;

	//! Get a bitmap representing a character. oDst must be at least of size iBufferSize and is allocated by the caller
	HRESULT GetBitmap(CharType charcode, unsigned char* oDst, size_t iBufferSize) const;

	//! Get the size of a string in pixels
	HRESULT GetStringSize(CATUnicodeString const& iString, int* oWidth, int* oHeight) const;

	//! Get the advance size of a string in 26.6 fixed point units (1/64th of a pixel)
	int GetStringAdvancePrecise(CATUnicodeString const& iString) const;
  //! Get the advance width and height of a string in 26.6 fixed point units (1/64th of a pixel)
  void GetStringAdvanceWidthHeight(CATUnicodeString const& iString,int &width,int &height,int iPath)  const;

	//! Set rendering options for the creation of images
	void SetRenderMode(CATFreeType::RenderMode mode);
	CATFreeType::RenderMode GetRenderMode() const;

	//! Get kerning value for a pair (in 1/64th of a pixel)
	int GetKerningDistance(CharType iLhs, CharType iRhs) const;

	//! Get auto kerning distance from a pair of deltas (in 1/64th of a pixel)
	int GetAutoKerningDistance(int iLhsRsb, int iRhsLsb) const;

	//! Measure compatible with GDI+Wgl
	CATBoolean GdiCompatible() const;

	//! Set face configuration options
	void SetFaceOptions(CATFreeType::FaceOptions _options);
	CATFreeType::FaceOptions GetFaceOptions() const;

	//! Enable/disable kerning pairs
	void SetKerning(CATBoolean _val);
	CATBoolean GetKerning() const;

	//! Enable/disable rendering mode from gasp table
	void SetGasp(CATBoolean _val);
	CATBoolean GetGasp() const;

	//! Enable/disable font linking
	void SetLinking(CATBoolean _val);
	CATBoolean GetLinking() const;

	//! Set/Get the radius of the outline strokes (in 1/4th of a pixel) up to 64 pixels
	void SetStrokeRadius(int _thickness);
	int GetStrokeRadius() const;

	//! Enable/disable auto-kerning via hint deltas. Only works with the FT autohinter.
	CATBoolean GetAutoKerning() const;
	void SetAutoKerning(bool _val);

	//! Query if subpixel rendering is enabled for this face
	CATBoolean GetSubpixel() const; 

	//! Query/set subpixel positioning
	CATBoolean GetSubpixelPositioning() const;
	void SetSubpixelPositioning(CATBoolean _val);

	//! Get the number of subpixel elements per pixel
	int GetHorizontalSubpixels() const;
	int GetVerticalSubpixels() const;

	//! Get the name of the font (usually the name of the font file)
	CATUnicodeString const& GetFontName() const;
	void SetFontFamily(CATUnicodeString const& iName);

	//! Query the face for a char code
	CATBoolean HasCharCode(CharType iCharCode) const;

	//! Get the font weight
	CATFreeType::FontWeight GetFontWeight() const;

	//! Get the font style
	CATFreeType::FontStyle GetFontStyle() const;

	//! Name of the font family (e.g. Arial, Segoe UI, etc)
	CATUnicodeString const& GetFontFamily() const;

	//! Obtain a copy of the current face sharing the underlying freetype object
	HRESULT Clone(CATFreeTypeFace** oCopy) const;

private:
	struct Glyph {
			CATUC2Bytes charcode;
			int index;
			CATFreeType::GlyphAdvance advance;

			inline Glyph() : charcode(0), index(0), advance() {}
	};
	struct GlyphCmp {
		inline CATBoolean operator() (Glyph const& lhs, CATUC2Bytes const& c)
		{
			return lhs.charcode < c;
		}
		inline CATBoolean operator()(CATUC2Bytes const& c, Glyph const& lhs)
		{
			return  c < lhs.charcode;
		}
		inline CATBoolean operator()(Glyph const& lhs, Glyph const& rhs)
		{
			return lhs.charcode < rhs.charcode;
		}
	};
	typedef vector<Glyph> GlyphCache;
	typedef GlyphCache::iterator GlyphIterator;
	typedef GlyphCache::const_iterator ConstGlyphIterator;
	typedef vector<CATFreeTypeFace*> FaceList;

private:
	CATFreeTypeFace(CATFreeTypeFactory* iFactory, CATFreeTypeFontFile* iFile
#ifdef VISU_ENABLE_FREETYPE
		, FT_Face iFace  
#endif // VISU_ENABLE_FREETYPE
		);
	~CATFreeTypeFace();
	GlyphIterator FindGlyph(CharType charcode) const;
	void ClearCache();
	HRESULT RenderGlyph() const;
	void ReadGasp();
	void SetMetrics(int ppem);

	CATFreeTypeFace* FindLinkedFace(CharType charcode) const;
	void AddLinkedFace(CATFreeTypeFace* iLinked) const;
	void ClearLinkedFaces();
	unsigned int GetCharIndex(CharType charcode) const;

private:
	//! CFTFactory associated with this face
	CATFreeTypeFactory* _factory;

	//! Physical font, might be shared with other CFTFaces
	CATFreeTypeFontFile*	_file;

#ifdef VISU_ENABLE_FREETYPE
	//! underlying freetype face, currently owned exclusively by the CFTFace,
	//! it could be shared to save memory at the expense of extra FT_Set_Size calls (which aren't too expensive)
	FT_Face _face;  
#endif // VISU_ENABLE_FREETYPE


	//! details identifying the font this face represents
	CATUnicodeString			_family;
	CATFreeType::FontWeight		_weight;
	CATFreeType::FontStyle		_style;

	//! list of faces searched for missing characters
	FaceList*	_linkedFaces;

	//! Glyph advance data is cached for fast retrieval of string measurements
	mutable GlyphCache	_glyphs;

	//! cf. freetype glyph loading flags
	int _loadFlags;

	//! cf. freetype glyph rendering flags
	int _renderFlags;

	//! charcode in the face slot, to avoid repeating queries. Probably redundant.
	CharType _currentChar;	

	//! Global font metrics scaled at the face size
	CATFreeType::GlobalMetrics _metrics;

	//! face configuration options
	CATFreeType::FaceOptions _options;

	//! rendering & hinting selection
	CATFreeType::RenderMode _renderMode;

	//! size of the glyph outlines when they're enabled
	unsigned int _strokeThickness;

	//! subpixel elements per pixel in the horizontal direction (=3 for RGB lcd panels)
	size_t _horizontalSubpixels;

	//! subpixel alements per pixel in the vertical direction (=1 for RGB lcd panels)
	size_t _verticalSubpixels;
private:	
	mutable std::unordered_map<int, int>  _kernPairsCache;
};



#endif // CATFreeTypeFace_H
