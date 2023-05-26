#ifndef CAT2DIMAGEPIXELREP_H
#define CAT2DIMAGEPIXELREP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "SGInfra.h"

#include "CAT2DRep.h"

class CATPixelImage;
class CAT2DImagePixelGP;


/**
* Class to create a representation of a 2D image.
* <b>Role</b>:
*	This representation allows to constructs an image with pixels
*	in 2D.
*/
class ExportedBySGInfra CAT2DImagePixelRep : public CAT2DRep
{
  friend class CATDmuStream2DImagePixelRep;
  CATDeclareClass;
public:

  /**
  * Constructs a 2D image representation.
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
  static CAT2DImagePixelRep* CreateRep(const float iPoint[2], const CATPixelImage* iPixelImage, int iZoomQuality = 0,
    int iXPixelOffset = 0, int iYPixelOffset = 0, int iScaleOffset = 0);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @deprecated R422 CAT2DImagePixelRep::CreateRep
  * Constructs a 2D image representation.
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
  CAT2DImagePixelRep(const float iPoint[2], const CATPixelImage* iPixelImage, int iZoomQuality = 0,
    int iXPixelOffset = 0, int iYPixelOffset = 0, int iScaleOffset = 0);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DImagePixelRep();

  /**
   * @nodoc
   */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive* gp);

  /**
  * Returns the 2D pixel image associated with the representation.
  */
  const CATPixelImage* GetPixelImage() const;

  /**
  * Sets the alpha mode.
  * Alpha mode allows to define a degree of transparency for each pixel of the
  * 2D image representation.
  * @param iOnOff
  *	the integer which defines the alpha mode.
  *	<br><b>legal values</b>:
  *	<ul><li>0 : alpha mode is not activated</li>
  *	<li>1 : alpha mode is activated and transparency is managed as a mask:</li></ul>
  *	if alpha is inferior to 128 the color is fylly transparent, if it is superior the color is fully opaque.
  *	<li>2 : alpha mode is activated and transparency is managed as true transparency</li></ul>
  */
  void SetAlphaMode(int iOnOff);

  /**
  * Modifies the position of the 2D image representation.
  * @param oPoint
  *	the position of the 2D image representation.
  */
  void Modify(const float oPoint[2]);

  #if defined(REMOVE_USELESS_INCLUDE)
    #pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
  #endif
  /**
  * @nodoc
  */
  virtual void DrawShading(CATRender& render, int iInside) FUNC_OVERRIDE_FINAL;


  /**
  * @nodoc
  */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iPath) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
  /**
  * @nodoc
  */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  /**
  * @nodoc
  */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

  //------------------------------------------------------------------------------
protected:

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

private:

  /**
 * @nodoc
 * Constructs an empty 2DImagePixelRep -UnStreaming-
 */
  CAT2DImagePixelRep();

  float _point[2], _width, _height;
  int _zoomQuality,
    _xOffset, _yOffset, _scaleOffset;
  CATPixelImage* _originalImage;
  CAT2DImagePixelGP* _imageGP;
};


#endif
