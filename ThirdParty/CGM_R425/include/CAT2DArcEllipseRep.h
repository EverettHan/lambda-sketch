#ifndef CAT2DArcEllipseRep_H
#define CAT2DArcEllipseRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CATVisMacroForInterfaces.h"

#include "CAT2DRep.h"
#ifndef NOFILL
#define NOFILL 0
#define FILL 1
#endif

class CAT2DArcEllipseGP;

class IVisSG2DPrimitiveIterator;
class CAT2DArcEllipseRepIVisSG2DPrimitiveIteratorBOAImpl;


/**
* Class to create a representation of a 2D ellipse arc or a 2D ellipse.
*/
class ExportedBySGInfra CAT2DArcEllipseRep : public CAT2DRep
{
  friend class CATDmuStream2DArcEllipseRep;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DArcEllipseRep, IVisSG2DPrimitiveIterator, CAT2DArcEllipseRepIVisSG2DPrimitiveIteratorBOAImpl);

public:

  /**
* Constructs a 2D ellipse arc representation.
* @param iCenter
*	the center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
* @param iXRadius
*	the radius among X axis of the 2D ellipse or 2D ellipse arc.
* @param iYRadius
*	the radius among Y axis of the 2D ellipse or 2D ellipse arc.
* @param iStart_angle
*	the start angle to construct a 2D ellipse arc.
*	<br><b>legal values</b>: the default value is 0.
*	By this way, it creates a 2D ellipse.
* @param iEnd_angle
*	the end angle to construct a 2D ellipse arc.
*	<br><b>legal values</b>: the default value is 2*pi.
*	By this way, it creates a 2D ellipse.
* @param iOffset
*	the angle between X axis and main axis of the 2D ellipse.
*	By this way, it is possible to rotate the 2D ellipse arc
*	or the 2D ellipse in the 2D plan.
* @param iFill
*	the integer which allows to construct a 2D ellipse arc or a 2D ellipse
*	just with edges or filled with some graphic attributes.
*	<br><b>legal values</b>:
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D ellipse arc or the 2D ellipse is filled
*				with graphic attributes.
* @param iStaticSagUsed
*	used to specify wheter using a dynamic or a static sag
*	for the ellipse arc visualization
*	<br><b>legal values</b>:
*		<br>0 :  the sag value is static and taken from settings,
*		and is constant whatever the distance between the viewpoint
*		and the ellipse arc be
*		<br>1 : the sage value is dynamic and calculated
*		depending on the distance between the viewpoint and
*		the ellipse arc.
*/
  static CAT2DArcEllipseRep* CreateRep(const float            iCenter[2],
    const float            iXRadius,
    const float            iYRadius,
    const float            iStart_angle = 0.f,
    const float            iEnd_angle = 6.2831853f,
    const float            iOffset = 0.f,
    const int              iFill = NOFILL,
    const int              iStaticSagUsed = 0);

  /**
  * Constructs a 2D ellipse arc representation.
  * @param iCenter
  *	the center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
  * @param iXRadius
  *	the radius among X axis of the 2D ellipse or 2D ellipse arc.
  * @param iYRadius
  *	the radius among Y axis of the 2D ellipse or 2D ellipse arc.
  * @param iStart_angle
  *	the start angle to construct a 2D ellipse arc.
  *	<br><b>legal values</b>: the default value is 0.
  *	By this way, it creates a 2D ellipse.
  * @param iEnd_angle
  *	the end angle to construct a 2D ellipse arc.
  *	<br><b>legal values</b>: the default value is 2*pi.
  *	By this way, it creates a 2D ellipse.
  * @param iOffset
  *	the angle between X axis and main axis of the 2D ellipse.
  *	By this way, it is possible to rotate the 2D ellipse arc
  *	or the 2D ellipse in the 2D plan.
  * @param iFill
  *	the integer which allows to construct a 2D ellipse arc or a 2D ellipse
  *	just with edges or filled with some graphic attributes.
  *	<br><b>legal values</b>:
  *		<br>NOFILL : just edges are drawn.
  *		<br>FILL : the 2D ellipse arc or the 2D ellipse is filled
  *				with graphic attributes.
  * @param iStaticSagUsed
  *	used to specify wheter using a dynamic or a static sag
  *	for the ellipse arc visualization
  *	<br><b>legal values</b>:
  *		<br>0 :  the sag value is static and taken from settings,
  *		and is constant whatever the distance between the viewpoint
  *		and the ellipse arc be
  *		<br>1 : the sage value is dynamic and calculated
  *		depending on the distance between the viewpoint and
  *		the ellipse arc.
  */
  static CAT2DArcEllipseRep* CreateRep(const double           iCenter[2],
    const double           iXRadius,
    const double           iYRadius,
    const double           iStart_angle = 0.,
    const double           iEnd_angle = 6.2831853,
    const double           iOffset = 0.,
    const int              iFill = NOFILL,
    const int              iStaticSagUsed = 0);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @deprecated R422 CAT2DArcEllipseRep::CreateRep
  * Constructs a 2D ellipse arc representation.
  * @param iCenter
  *	the center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
  * @param iXRadius
  *	the radius among X axis of the 2D ellipse or 2D ellipse arc.
  * @param iYRadius
  *	the radius among Y axis of the 2D ellipse or 2D ellipse arc.
  * @param iStart_angle
  *	the start angle to construct a 2D ellipse arc.
  *	<br><b>legal values</b>: the default value is 0.
  *	By this way, it creates a 2D ellipse.
  * @param iEnd_angle
  *	the end angle to construct a 2D ellipse arc.
  *	<br><b>legal values</b>: the default value is 2*pi.
  *	By this way, it creates a 2D ellipse.
  * @param iOffset
  *	the angle between X axis and main axis of the 2D ellipse.
  *	By this way, it is possible to rotate the 2D ellipse arc
  *	or the 2D ellipse in the 2D plan.
  * @param iFill
  *	the integer which allows to construct a 2D ellipse arc or a 2D ellipse
  *	just with edges or filled with some graphic attributes.
  *	<br><b>legal values</b>:
  *		<br>NOFILL : just edges are drawn.
  *		<br>FILL : the 2D ellipse arc or the 2D ellipse is filled
  *				with graphic attributes.
  * @param iStaticSagUsed
  *	used to specify wheter using a dynamic or a static sag
  *	for the ellipse arc visualization
  *	<br><b>legal values</b>:
  *		<br>0 :  the sag value is static and taken from settings,
  *		and is constant whatever the distance between the viewpoint
  *		and the ellipse arc be
  *		<br>1 : the sage value is dynamic and calculated
  *		depending on the distance between the viewpoint and
  *		the ellipse arc.
  */
  CAT2DArcEllipseRep(const float            iCenter[2],
    const float            iXRadius,
    const float            iYRadius,
    const float            iStart_angle = 0.f,
    const float            iEnd_angle = 6.2831853f,
    const float            iOffset = 0.f,
    const int              iFill = NOFILL,
    const int              iStaticSagUsed = 0);

  /**
  * @deprecated R422 CAT2DArcEllipseRep::CreateRep
  * Constructs a 2D ellipse arc representation.
  * @param iCenter
  *	the center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
  * @param iXRadius
  *	the radius among X axis of the 2D ellipse or 2D ellipse arc.
  * @param iYRadius
  *	the radius among Y axis of the 2D ellipse or 2D ellipse arc.
  * @param iStart_angle
  *	the start angle to construct a 2D ellipse arc.
  *	<br><b>legal values</b>: the default value is 0.
  *	By this way, it creates a 2D ellipse.
  * @param iEnd_angle
  *	the end angle to construct a 2D ellipse arc.
  *	<br><b>legal values</b>: the default value is 2*pi.
  *	By this way, it creates a 2D ellipse.
  * @param iOffset
  *	the angle between X axis and main axis of the 2D ellipse.
  *	By this way, it is possible to rotate the 2D ellipse arc
  *	or the 2D ellipse in the 2D plan.
  * @param iFill
  *	the integer which allows to construct a 2D ellipse arc or a 2D ellipse
  *	just with edges or filled with some graphic attributes.
  *	<br><b>legal values</b>:
  *		<br>NOFILL : just edges are drawn.
  *		<br>FILL : the 2D ellipse arc or the 2D ellipse is filled
  *				with graphic attributes.
  * @param iStaticSagUsed
  *	used to specify wheter using a dynamic or a static sag
  *	for the ellipse arc visualization
  *	<br><b>legal values</b>:
  *		<br>0 :  the sag value is static and taken from settings,
  *		and is constant whatever the distance between the viewpoint
  *		and the ellipse arc be
  *		<br>1 : the sage value is dynamic and calculated
  *		depending on the distance between the viewpoint and
  *		the ellipse arc.
  */
  CAT2DArcEllipseRep(const double           iCenter[2],
    const double           iXRadius,
    const double           iYRadius,
    const double           iStart_angle = 0.,
    const double           iEnd_angle = 6.2831853,
    const double           iOffset = 0.,
    const int              iFill = NOFILL,
    const int              iStaticSagUsed = 0);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DArcEllipseRep();

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

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive* gp);

  //------------------------------------------------------------------------------
protected:
  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

private:

  /**
   * @nodoc
   * Constructs an empty 2DArcEllipseRep -UnStreaming-
   */
  CAT2DArcEllipseRep();

  CAT2DArcEllipseGP* _geometrie;
};

#endif 









