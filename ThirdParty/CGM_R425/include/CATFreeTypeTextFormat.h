//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2011/10/24
//===================================================================
// CATFreeTypeTextFormat.cpp
// 
//===================================================================
//
// Usage notes:
//
//===================================================================
//===================================================================

#ifndef CATFreeTypeTextFormat_H
#define CATFreeTypeTextFormat_H

#include "CATFreeType.h"
#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATFreeTypeFactory;
class CATFreeTypeFace;


class ExportedBySGInfra CATFreeTypeTextFormat : public CATBaseUnknown
{
		friend class CATFreeTypeFactory;
		//friend class CATOGLTextureFont;
public:

  //! Get the size of a string in pixels depending upon the orientation of the string which is iPath
  HRESULT GetStringSize(CATUnicodeString const& iString, float* oWidth, float* oHeight,int iPath=0) const;

	//! Retrieve global metrics for the face
	HRESULT GetGlobalMetrics(CATFreeType::GlobalMetrics* metrics) const;

	//! Return the length in chars and size of the substring that fits in MaxWidth
	HRESULT CropString(CATUnicodeString const& iString, float iMaxWidth, size_t* oSubstringLen, float* oSubstringWidth, float* oSubstringHeight) const;

	void SetFormatHint(CATFreeType::FormatHint iFormatHint);
	CATFreeType::FormatHint GetFormatHint() const;

	//! Accessors
	CATFreeType::RenderMode GetRenderMode() const;
	CATUnicodeString const& GetFontName() const;
	CATFreeType::FontWeight GetFontWeight() const;
	CATFreeType::FontStyle GetFontStyle() const;
	CATUnicodeString const& GetFontFamily() const;

	CATFreeTypeFace const* GetFace() const;

private:
	CATFreeTypeTextFormat(CATFreeTypeFace* iFace);
	~CATFreeTypeTextFormat();

private:
	CATFreeTypeFace*	_face;
	CATFreeType::FormatHint _formatHint;
};


#endif // CATFreeTypeTextFormat_H 
