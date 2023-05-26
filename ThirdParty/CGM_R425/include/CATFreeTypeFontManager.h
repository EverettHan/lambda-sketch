//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2011/10/24
//===================================================================
// CATFreeTypeFontManager.cpp
// A convenience class to expose to applications. Ties together
// the various font classes to provide a simple interface
// 
//===================================================================
//
// Usage notes:
// Main function is GetTextFormat which returns an object callers
// can use to build TextGPs
//
//===================================================================
//===================================================================

#ifndef CATFreeTypeFontManager_H
#define CATFreeTypeFontManager_H


#include "CATFreeType.h"
#include "CATFreeTypeFace.h"
#include "vector.h"

class CATFreeTypeFactory;
class CATFreeTypeFontCollection;
class CATFreeTypeTextFormat;
class CATFreeTypeTextureFontManager;
class CATListValCATUnicodeString;


class ExportedBySGInfra CATFreeTypeFontManager {
public:
	CATFreeTypeFontManager();
	~CATFreeTypeFontManager();

	//! Get a pointer to the singleton manager
	static CATFreeTypeFontManager* Get();
	//static CATFreeTypeFontManager* Give();

	//! Obtain a text format for the specified font, size and format options
	HRESULT GetTextFormat(CATUnicodeString const& iFontFamily,
						  int	iPixelSize,	/* when this is negative, we match the cell height like in Windows */
						  CATFreeType::FontWeight iWeight, 
						  CATFreeType::FontStyle iStyle, 
						  CATFreeType::FormatHint iOptions, 
						  CATFreeTypeTextFormat** oFormat);

	//! The manager will try to keep the open faces below this number 
	void SetMaxOpenFaces(size_t iNum);

	//! Get the linked face to locate missing charcodes
	HRESULT GetLinkedFace(CATFreeTypeFace const* iFace, CATFreeTypeFace::CharType iCharCode, CATFreeTypeFace** oFace);

	//! Set the global face and render mode options for a particular format
	HRESULT SetGlobalFontOptions(CATFreeType::FormatHint iFormat, CATFreeType::FaceOptions iFaceOptions, CATFreeType::RenderMode iRenderMode);
	HRESULT GetGlobalFontOptions(	CATFreeType::FormatHint iFormat, CATFreeType::FaceOptions& oFaceOptions, CATFreeType::RenderMode& oRenderMode)const;

	//! Get/Set global font gamma
	void SetFontGamma(float iGamma);
	float GetFontGamma() const;

	//! Get/Set global lcd filter weights (9 floats)
	void SetLCDFilter(float* iWeights);
	void GetLCDFilter(float* oWeights) const;

	//! Get the list of fonts known to the manager
	void GetFontList(CATListValCATUnicodeString& oFamilies) const;

	//! Query if a particular font via family, weight & style 
	HRESULT Contains(CATUnicodeString const& iFamilyName, CATFreeType::FontWeight iWeight = CATFreeType::CFT_FONT_WEIGHT_NORMAL, CATFreeType::FontStyle iStyle = CATFreeType::CFT_FONT_STYLE_NORMAL) const;

	//! Check if subpixel rendering is active
	bool GetSubpixelRendering(CATFreeType::FormatHint iFormat);

	//! Get the texture font manager
	CATFreeTypeTextureFontManager* GetTextureFontManager();

	//! Release materials, textures..
	void ReleaseRenderingResources();

private:
	void SetDefaultOptions(CATFreeType::FormatHint iSel);
	void ApplyGlobalOptions(CATFreeType::FormatHint iSel);
	int GetTTCFaceIndexFromName(CATUnicodeString const& _faceNameAndIndex);

	void GetSystemFonts();
	void SetDefaultFont();
	void SetDefaultLCDFilter();
	void GC();

	CATFreeTypeFace* FindFace(
		CATUnicodeString const&		iFontFamily,
		CATFreeType::FontWeight		iWeight,
		CATFreeType::FontStyle		iStyle,
		CATFreeType::FormatHint		iOptions, 
		int							iPixelSize
		);


	struct FaceRec {
		CATUnicodeString			family;
		CATFreeType::FontWeight		weight;
		CATFreeType::FontStyle		style;
		CATFreeType::FormatHint		options; 
		size_t						ppem;		 // ppem size in pixels
		size_t						cell_height; // (ascender + descender)
		CATFreeTypeFace*	face;

		bool operator==(const FaceRec& other) const;
		bool operator!=(const FaceRec& other) const;
		CATBoolean operator<(const FaceRec& other) const;
	};
	typedef vector<FaceRec> FaceList;

	void InsertFace(FaceRec const& iRec);

	struct FontOptions {
		CATFreeType::FaceOptions _face_options;
		CATFreeType::RenderMode _render_mode;
	};
private:
	CATFreeTypeFactory*	_factory;
	CATFreeTypeFontCollection* _fonts;
	FontOptions _globalOpt[CATFreeType::CFT_FORMAT_HINT_MAX+1];
	FontOptions _defaultOpt[CATFreeType::CFT_FORMAT_HINT_MAX+1];
	FaceList	_faces;
	CATUnicodeString	_defaultFont;
	int					_defaultFontPixelSize;
	size_t		_numOpenFaces;
	size_t		_gcThreshold;
	float		_gamma;
	float		_lcdWeights[9];
	CATFreeTypeTextureFontManager* _textureFontManager;
  //static CATFreeTypeFontManager* _s_pInstance;
};


#endif // CATFreeTypeFontManager_H 
