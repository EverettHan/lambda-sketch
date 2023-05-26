//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2012/02/07
//===================================================================
// CATFreeTypeTextGP.cpp
// Header definition of class CATFreeTypeTextGP
//===================================================================
//
// Usage notes:
//
// Graphics primitive to render text via the CATFreeType pipeline
// The GP encapsulates a particular combination of text and font
// and internally caches some of the geometry for efficiency
// It also offers an API to render the text with outlining 
// or drop shadow effects
//===================================================================
//===================================================================
#ifndef CATFreeTypeTextGP_H
#define CATFreeTypeTextGP_H

#include "SGInfra.h"
#include "CATDynamicGP.h"
#include "CATUnicodeString.h"
#include "CATMathPointf.h"

#include "DSYSysTrace.h"

class CATFreeTypeTextFormat;
class CATFreeTypeTextureFont;
namespace CATFreeType { struct PenPoint; } // NHD : Fix for TSK2859740 (0), VS2015 migration.

class ExportedBySGInfra CATFreeTypeTextGP : public CATDynamicGP
{
	CATDeclareClass;

public:
	CATFreeTypeTextGP(CATMathPointf const& iPosition, CATUnicodeString const& iString, CATFreeTypeTextFormat* iFormat);

protected:
	virtual ~CATFreeTypeTextGP();

public:
	enum TessellationFormat {
		Undefined = 0,
		Quads = 1,
		Triangles = 2,
		Strip = 3,
		Quads3 = 4,
		Triangles3 = 5,
		Strip3 = 6
	};
public:
	virtual void ImmediateDraw (
		CATRender & iRender, 
		CATViewpoint const* iViewpoint, 
		CATViewport const* iViewport
		) override final;   
      
	virtual void Draw(CATRender& iRender) override final;

	//! Get the text format for this GP - this is constant throughout the lifetime of the GP
	CATFreeTypeTextFormat const* GetTextFormat() const;

	//! Get the string 
	CATUnicodeString const& GetString() const;

	//! Get the GP position - this is the baseline position in model space
	CATMathPointf const& GetPosition() const;

	//! Get the GP bounding box in model space
	void GetBoundingBox(CATMathPointf& oMin, CATMathPointf& oMax) const;

	//! The the points of the 'pen' position on the baseline for each of the characters
	CATFreeType::PenPoint const* GetBasePoints() const;

	//! Enable a text outlining effect
	void SetOutline(CATBoolean iVal);

	//! Set/Get the colour of the text outline
	void SetOutlineColor(float iR, float iG, float iB, float iA);
	void GetOutlineColor(float* oRgba) const;

	//! Set/Get the radius of the text outline in 1/4th of a pixel (up to a max of 64 pixels)
	void SetOutlineRadius(int iRadius);
	void GetOutlineRadius(int* oRadius) const;

	//! Query if text outlining is enabled
	CATBoolean GetOutline() const;


	//! Enable/Query a drop shadow effect
	void SetShadow(CATBoolean iVal);
	CATBoolean GetShadow() const;

	//! Set the drop shadow color
	void SetShadowColor(float iR, float iG, float iB, float iA);
	void GetShadowColor(float* oColor) const;

	//! Set the drop shadow offset in pixels
	void SetShadowOffset(float iX, float iY, float iZ);
	void GetShadowOffset(float* oOffset) const;

	//! Get the geometry of the GP
	HRESULT Get(
		int&	oAllocate,
		float**	oVertices,
		int&	oNumVertices,
		int&	oVerticesArraySize,
		float**	oTextureCoordinates,
		int&	oTextureArraySize,
		enum TessellationFormat& ioFormat,
		bool	iInvertY = true
	);

	//! Get the texture font used to render the text
	CATFreeTypeTextureFont* GetTextureFont();

	//! To provide your own texture font (not checked for compatibility)
	void SetTextureFont(CATFreeTypeTextureFont* iFont);

  //!Set the text invert flag
  void SetInvertFlag(int iVal);
	int GetInvertFlag() const;

  //!Set if we use the text invert flag when displays
  void SetUseInvertFlag(int iVal);
  int GetUseInvertFlag() const;
  void SetOrientation(const int iPath);
  int GetOrientation() const;
  

private:
	typedef struct { float r,g,b,a; } Rgbaf;

	CATFreeTypeTextureFont* TextureFont();
	void ReleaseGeometry();
	void ConvertGeometry(TessellationFormat oFormat);

private:
	CATUnicodeString		_string;
	CATFreeTypeTextFormat*	_format;
	CATFreeTypeTextureFont* _font;
	CATMathPointf			_position;
	CATFreeType::PenPoint*	_baselinePoints;

	//! data for various text drawing effects
	CATBoolean	_outline;
	Rgbaf		_outlineCol;
	int			_outlineRadius;

	CATBoolean	_shadow;
	Rgbaf		_shadowCol;
	float		_shadowOffset[3];

	// geometry
	float*		_vertices;
	float*	    _texcoords;
	unsigned int _numVertices;
	unsigned int _textureToken;
	TessellationFormat _tessellationFormat;
	bool		_cachedGeometry;
  int _path;

  //determin if invert the text GP display
  int _invertFlag;
  int _useInvertFlag;

  //Trace Log Mechanism
  void* _logger;
};

#endif // CATFreeTypeTextGP_H
