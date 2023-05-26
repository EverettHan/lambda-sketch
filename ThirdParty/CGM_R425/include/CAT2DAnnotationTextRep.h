#ifndef CAT2DAnnotationTextRep_H
#define CAT2DAnnotationTextRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"
#include "CAT2DRep.h"
#include "CAT2DAnnotationTextGP.h"
#include "CATVisMacroForInterfaces.h"

class CATUnicodeString;
class CATMathPoint2Df;

class IVisSG2DPrimitiveIterator;
class CAT2DAnnotationTextRepIVisSG2DPrimitiveIteratorBOAImpl;


/**
* Class to create a representation of a 2D annotation text.
* <b>Role</b>:
* These representations have not a continuous zoom. There are various possible
* zoom values and current zoom is the zoom which is the nearest of possible zoom values.
*/
class ExportedBySGInfra CAT2DAnnotationTextRep : public CAT2DRep
{
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DAnnotationTextRep, IVisSG2DPrimitiveIterator, CAT2DAnnotationTextRepIVisSG2DPrimitiveIteratorBOAImpl);

public:

  /**
  * Constructs a 2D annotation text Graphic primitive.
  * @param iPoint
  *	the position of the representation in a 2D space
  * @param iString
  *	the string of characters which composes the text of
  *	the 2DAnnotationTextRep
  * @param iPosition
  *	the position of <tt>iPoint</tt> with respect to string of the 2DAnnotationTextRep
  *	<br><b>legal values</b>:<pre>
  *   TOP_LEFT          TOP_CENTER       TOP_RIGHT
  *            +------------+-----------+
  *            !                        !
  *            !        BASE_CENTER     !
  *  BASE_LEFT +            +           + BASE_RIGHT
  *            !                        !
  *            +------------+-----------+
  * BOTTOM_LEFT       BOTTOM_CENTER      BOTTOM_RIGHT</pre>
  * @param iHeight
  *	the height of the representation
    <br><b>legal values</b>: the default value is NULL.
  * @param iContour
  *	the integer which allows or does not allow to construct a contour around
  *	the representation.
  *	<br><b>legal values</b>:<br>
  *	0 : no contour is constructed around the graphic primitive.<br>
  *	1 : a contour is constructed around the graphic primitive.
  * @param iContour1
  *	the graphic attribute which
  *	defines graphic properties of top and left segments of the contour around
  *	the representation.
  *	<br><b>legal values</b>: the default value is NULL.
  * @param iContour2
  *	the graphic attribute which
  *	defines graphic properties of bottom and right segments of the contour around
  *	the representation.
  *	<br><b>legal values</b>: the default value is NULL.
  */
  static CAT2DAnnotationTextRep* CreateRep(const float iPoint[2], const CATUnicodeString& iString, CATAnchorPoint iPosition = BASE_LEFT, const float iHeight = 0.f,
    const int iContour = 0, const CATGraphicAttributeSet* iContour1 = NULL, const CATGraphicAttributeSet* iContour2 = NULL);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @deprecated R422 CAT2DAnnotationTextRep::CreateRep
  * Constructs a 2D annotation text Graphic primitive.
  * @param iPoint
  *	the position of the representation in a 2D space
  * @param iString
  *	the string of characters which composes the text of
  *	the 2DAnnotationTextRep
  * @param iPosition
  *	the position of <tt>iPoint</tt> with respect to string of the 2DAnnotationTextRep
  *	<br><b>legal values</b>:<pre>
  *   TOP_LEFT          TOP_CENTER       TOP_RIGHT
  *            +------------+-----------+
  *            !                        !
  *            !        BASE_CENTER     !
  *  BASE_LEFT +            +           + BASE_RIGHT
  *            !                        !
  *            +------------+-----------+
  * BOTTOM_LEFT       BOTTOM_CENTER      BOTTOM_RIGHT</pre>
  * @param iHeight
  *	the height of the representation
    <br><b>legal values</b>: the default value is NULL.
  * @param iContour
  *	the integer which allows or does not allow to construct a contour around
  *	the representation.
  *	<br><b>legal values</b>:<br>
  *	0 : no contour is constructed around the graphic primitive.<br>
  *	1 : a contour is constructed around the graphic primitive.
  * @param iContour1
  *	the graphic attribute which
  *	defines graphic properties of top and left segments of the contour around
  *	the representation.
  *	<br><b>legal values</b>: the default value is NULL.
  * @param iContour2
  *	the graphic attribute which
  *	defines graphic properties of bottom and right segments of the contour around
  *	the representation.
  *	<br><b>legal values</b>: the default value is NULL.
  */
  CAT2DAnnotationTextRep(const float iPoint[2], const CATUnicodeString& iString, CATAnchorPoint iPosition = BASE_LEFT, const float iHeight = 0.f,
    const int iContour = 0, const CATGraphicAttributeSet* iContour1 = NULL, const CATGraphicAttributeSet* iContour2 = NULL);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DAnnotationTextRep();

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /**
  * @nodoc
  */
  virtual void DrawShading(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
  /**
  * @nodoc
  */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
  /**
  * @nodoc
  */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  /**
  * @nodoc
  */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif
  /**
   * @nodoc
   */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive* gp);

  //------------------------------------------------------------------------------

protected:

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  /**
  * Dynamic Graphic Primitive associated to Representation.
  */
  CAT2DAnnotationTextGP* _geometrie;
};

#endif 









