//----------------------------------------------------------------------------
//	CATMMIHelperRGBA.h
//----------------------------------------------------------------------------
//	RGBA Image drawing primitives
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2002
//----------------------------------------------------------------------------
#ifndef CATMMIHelperRGBA_H
#define CATMMIHelperRGBA_H

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaRasterProcessor_Base.h"
#include "CATMMediaImageDef.h"
#include "CATMMIDrawPrimitive.h"
#include "IUnknown.h"
#include "CATBoolean.h"

class CATPixelImage;

//ExportedByCATMMediaRasterFormats CATPixelImage * CATMMICreateImage(
ExportedByCATMMediaRasterProcessor_Base CATPixelImage * CATMMICreateImage(
		const CATMMITriangle2DP * iprTriangleList, 
		int iCount,
		float iDpu, 
		const CATPixelImage * iprRGBATexture=0);

//class ExportedByCATMMediaRasterFormats CATMMIHelperRGBA
class ExportedByCATMMediaRasterProcessor_Base CATMMIHelperRGBA
{
public:
	CATMMIHelperRGBA(CATPixelImage& iPixelImage);
	virtual ~CATMMIHelperRGBA();

	HRESULT Attach(CATPixelImage& iPixelImage);
	HRESULT Blend(CATPixelImage& iAlphaMask, int iX=0, int iY=0);
	CATMMIColor Pick(int iX, int iY);

	// --- 2D Drawing methods ---
	void Clear(CATMMIColor iColor);
	void Fill(int iX, int iY, CATMMIColor iColor);
	void FillArea(const int iLineCount, 
			const int * const iprCornerCount, 
			const int * const iprCoord2d,
			CATMMIColor iColor);
	
	// --- 2D Drawing methods ---
	void Plot(int iX, int iY, CATMMIColor iColor);
	void Brush(int iX, int iY, CATMMIColor iColor, CATMMIBrush iBrush=MMI_BSH_Point1);
	void HLine(int iY, int iX1, int iX2, CATMMIColor iColor);
	void Line(int iX1, int iY1, int iX2, int iY2, CATMMIColor iColor, CATMMIBrush iBrush=MMI_BSH_Point1);
	void Rectangle(int iX1, int iY1, int iX2, int iY2, CATMMIColor iColor, CATBoolean ibSolid = FALSE);
	void Circle(int iX, int iY, int iRadius, CATMMIColor iColor, CATBoolean ibSolid = FALSE);
	void Ellipse(int iX, int iY, int iRadiusX, int iRadiusY, CATMMIColor iColor, CATBoolean ibSolid = FALSE);


	// --- draw primitives ---
	//void Draw(const CATMMILine2DP& iPrimitive);
	//void Draw(const CATMMIEllipse2DP& iPrimitive);
	void Draw(const CATMMIRectangle2DP& iPrimitive);
	void Draw(const CATMMITriangle2DP& iPrimitive, const CATPixelImage * iprRGBATexture=0);

protected:
	CATPixelImage& _Image;

	CATMMIColor	*_prBitmap;
	CATBoolean	_bValid;
	int			_Width;
	int			_Height;
private:
	// useless default methods intentionally not accessible (and not generated)
	CATMMIHelperRGBA();
	CATMMIHelperRGBA(const CATMMIHelperRGBA&);
    CATMMIHelperRGBA& operator=(const CATMMIHelperRGBA&);
    CATMMIHelperRGBA * operator&();
    const CATMMIHelperRGBA * operator&() const;
	void LineBrush(int iX1, int iY1, int iX2, int iY2, CATMMIColor iColor, CATMMIBrush iBrush);
};

#endif // CATMMIHelperRGBA_H
