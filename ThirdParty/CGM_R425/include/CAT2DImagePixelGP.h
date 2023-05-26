#ifndef CAT2DImagePixelGP_H
#define CAT2DImagePixelGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CATDynamicGP.h"


class CATPixelImage;
class CAT2DViewpoint;


/**
* Class to create a dynamic graphic primitive of a 2D image.
* <b>Role</b>: 
*	This graphic primitive allows to constructs an image with pixels
*	in 2D.
*/ 
class ExportedBySGInfra CAT2DImagePixelGP : public CATDynamicGP
{
	friend class CAT2DImagePixelGPPrivGetter;
	friend class CATDmuStream2DImagePixelRep;
	CATDeclareClass;

public:

/**
* Constructs a 2D image Graphic primitive.
* @param iPoint
*	the position of the graphic primitive in a 2D space (in model coordinates).
* @param iPixelImage
*	the 2D image used to create the 2D graphic primitive.
* @param iZoomQuality
*	the zoom quality.
*	<br><b>legal values</b>:
*	<ul><li>0 : no zoom available.</li>
*	<li>1 : low quality zoom.</li>
*	<li>2 : high quality zoom (smooth).</li></ul>
*	The default value is 0 (no zoom).
* @param iXPixelOffset
*	The offset along X axis. It allows to translate the graphic primitive from
*	the <tt>iPoint</tt>. <tt>iXPixelOffset</tt> is expressed in pixels.
*	<br><b>legal values</b>:
*	the default value is 0 (no translation along X axis)
* @param iYPixelOffset
*	The offset along Y axis. It allows to translate the graphic primitive from
*	the <tt>iPoint</tt>. <tt>iYPixelOffset</tt> is expressed in pixels.
*	<br><b>legal values</b>:
*	the default value is 0 (no translation along Y axis)
* @param iScaleOffset
*	Do not use.
*/
    CAT2DImagePixelGP(const float iPoint[2], const CATPixelImage* iPixelImage, int iZoomQuality = 0,
                      int iXPixelOffset = 0, int iYPixelOffset = 0, int iScaleOffset = 0);

/**
* Retrieves data about the 2D image Graphic primitive.
* @param oPoint
*	the position of the graphic primitive in a 2D space
* @param oPixelImage
*	the image which composes the graphic primitive.
* @param oAlpha
*	the alpha mode (the transparent mode).
*	<br><b>legal values</b>:
*	<ul><li>0 : alpha mode is activated</li>
*	<li>1 : alpha mode is not activated</li></ul>
* @param oXPixelOffset
*	The offset along X axis. It allows to translate the graphic primitive from
*	the <tt>iPoint</tt>. <tt>oXPixelOffset</tt> is expressed in pixels.
* @param oYPixelOffset
*	The offset along Y axis. It allows to translate the graphic primitive from
*	the <tt>iPoint</tt>. <tt>oYPixelOffset</tt> is expressed in pixels.
*/
    inline void Get(float** oPoint, CATPixelImage** oPixelImage, int* oAlpha, int* oXPixelOffset, int* oYPixelOffset);

#ifdef CATIAR426
    /** @nodoc */
    virtual void Draw(CATRender& iRender) override final;
#endif 

/** 
* Draws a 2D image.
* @param iRender
*	the render used to draw the 2D image.
* @param iViewpoint
*	the viewpoint used to draw the 2D image.
* @param iViewport
*	the viewPort used to draw the 2D image.
*/
    virtual void ImmediateDraw(CATRender& iRender, const CATViewpoint* iViewpoint, const CATViewport* iViewport) GP_FUNC_OVERRIDE_FINAL;


/**
* Sets the alpha mode.
* Alpha mode allows to define a degree of transparency for each pixel of the
* 2D image representation.
* @param iOnOff
*	the integer which defines the alpha mode.
*	<br><b>legal values</b>:
*	<ul><li>0 : alpha mode is not activated</li>
*	<li>1 : alpha mode is activated</li></ul>
*/
    void SetAlphaMode(int iOnOff) { _alpha = iOnOff; }

/**
 * @nodoc
 */
    virtual int DetailCulling(CATRender *iRender);

/**
 * @nodoc
 * Streaming
 */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
/**
 * @nodoc
 * Unstreaming
 */  
   virtual void UnStream(CATStreamer& iStr);

protected:

    virtual ~CAT2DImagePixelGP();

private:

    void BILEVELImmediateDraw(CATRender&, const CATViewpoint*, const CATViewport*);
    void BILEVELImmediateDrawNoZoom(CATRender&, int, int, int, int, float, float);
    void BILEVELImmediateDrawAnimatedZoomOut(CATRender&, int, int, int, int, float, float);
    void BILEVELImmediateDrawStaticZoomOut(CATRender&, int, int, int, int, float, float);
    void BILEVELImmediateDrawZoomIn(CATRender&, int, int, int, int, float, float);

    float _point[2];
    CATPixelImage* _image;
    int _alpha;
    int _xOffset, _yOffset, _scaleOffset;
    const int _zoomQuality;

    int _pixImgWidth, _pixImgHeight; // size of _image in pixels
    float _mmPixWidth, _mmPixHeight; // size of a pixel of _image in mm

    float _lastScale;
    float _lastxMinClippedImage, _lastxMaxClippedImage, _lastyMinClippedImage, _lastyMaxClippedImage;
    int _sharpened;
    float _newpoint[2];
    CATPixelImage* _zoomedImage;


    CATBoolean ImmediateDrawPrint(CATRender& iRender, const CATViewpoint* iViewpoint, const CATViewport* iViewport);
};


inline void CAT2DImagePixelGP::Get(float** point, CATPixelImage** image, int* alpha,
                                   int* xPixelOffset, int* yPixelOffset)
{
    *point = _point;
    *image = _image;
    *alpha = _alpha;
    *xPixelOffset = _xOffset;
    *yPixelOffset = _yOffset;
}


#endif
