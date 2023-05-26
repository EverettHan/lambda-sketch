#ifndef CAT2DArcCircleRep_H
#define CAT2DArcCircleRep_H

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

class CAT2DArcCircleGP;

class IVisSG2DPrimitiveIterator;
class CAT2DArcCircleRepIVisSG2DPrimitiveIteratorBOAImpl;


/**
* Class to create a representation of a 2D circle arc or a 2D circle.
*/
class ExportedBySGInfra CAT2DArcCircleRep : public CAT2DRep
{
  friend class CATDmuStream2DArcCircleRep;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DArcCircleRep, IVisSG2DPrimitiveIterator, CAT2DArcCircleRepIVisSG2DPrimitiveIteratorBOAImpl);

public:

  /**
  * Constructs a 2D circle arc representation.
  * @param iCenter
  *	the center of the 2D circle or 2D circle arc, it is a 2D point.
  * @param iRadius
  *	the radius of the 2D circle or 2D circle arc.
  * @param iStart_angle
  *	the start angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 0.
  *	By this way, it creates a 2D circle.
  * @param iEnd_angle
  *	the end angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 2*pi.
  *	By this way, it creates a 2D circle.
  * @param iFill
  *	the integer which allows to construct a 2D circle arc or a 2D circle
  *	just with edges or filled with graphic attributes.
  *	<br><b>legal values</b>:
  *		<br>NOFILL : just edges are drawn.
  *		<br>FILL : the dynamic graphic primitive is filled with
  *				graphic attributes.
  * @param iStaticSagUsed
  *	used to specify wheter using a dynamic or a static sag
  *	for the circle arc visualization
  *	<br><b>legal values</b>:
  *		<br>0 :  the sag value is static and taken from settings,
  *		and is constant whatever the distance between the viewpoint
  *		and the circle arc be
  *		<br>1 : the sage value is dynamic and calculated
  *		depending on the distance between the viewpoint and
  *		the circle arc.
  */
  static CAT2DArcCircleRep* CreateRep(const float iCenter[2], const float iRadius,
    const float iStart_angle = 0.f, const float iEnd_angle = 6.2831853f,
    const int iFill = NOFILL, const int iStaticSagUsed = 0);

  /**
  * Constructs a 2D circle arc representation.
  * @param iCenter
  *	the center of the 2D circle or 2D circle arc, it is a 2D point.
  * @param iRadius
  *	the radius of the 2D circle or 2D circle arc.
  * @param iStart_angle
  *	the start angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 0.
  *	By this way, it creates a 2D circle.
  * @param iEnd_angle
  *	the end angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 2*pi.
  *	By this way, it creates a 2D circle.
  * @param iFill
  *	the integer which allows to construct a 2D circle arc or a 2D circle
  *	just with edges or filled with graphic attributes.
  *	<br><b>legal values</b>:
  *		<br>NOFILL : just edges are drawn.
  *		<br>FILL : the dynamic graphic primitive is filled with
  *				graphic attributes.
  * @param iStaticSagUsed
  *	used to specify wheter using a dynamic or a static sag
  *	for the circle arc visualization
  *	<br><b>legal values</b>:
  *		<br>0 :  the sag value is static and taken from settings,
  *		and is constant whatever the distance between the viewpoint
  *		and the circle arc be
  *		<br>1 : the sage value is dynamic and calculated
  *		depending on the distance between the viewpoint and
  *		the circle arc.
  */
  static CAT2DArcCircleRep* CreateRep(const double iCenter[2], const double iRadius,
    const double iStart_angle = 0., const double iEnd_angle = 6.2831853,
    const int iFill = NOFILL, const int iStaticSagUsed = 0);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @deprecated R422 CAT2DArcCircleRep::CreateRep
  * Constructs a 2D circle arc representation.
  * @param iCenter
  *	the center of the 2D circle or 2D circle arc, it is a 2D point.
  * @param iRadius
  *	the radius of the 2D circle or 2D circle arc.
  * @param iStart_angle
  *	the start angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 0.
  *	By this way, it creates a 2D circle.
  * @param iEnd_angle
  *	the end angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 2*pi.
  *	By this way, it creates a 2D circle.
  * @param iFill
  *	the integer which allows to construct a 2D circle arc or a 2D circle
  *	just with edges or filled with graphic attributes.
  *	<br><b>legal values</b>:
  *		<br>NOFILL : just edges are drawn.
  *		<br>FILL : the dynamic graphic primitive is filled with
  *				graphic attributes.
  * @param iStaticSagUsed
  *	used to specify wheter using a dynamic or a static sag
  *	for the circle arc visualization
  *	<br><b>legal values</b>:
  *		<br>0 :  the sag value is static and taken from settings,
  *		and is constant whatever the distance between the viewpoint
  *		and the circle arc be
  *		<br>1 : the sage value is dynamic and calculated
  *		depending on the distance between the viewpoint and
  *		the circle arc.
  */
  CAT2DArcCircleRep(const float iCenter[2], const float iRadius,
    const float iStart_angle = 0.f, const float iEnd_angle = 6.2831853f,
    const int iFill = NOFILL, const int iStaticSagUsed = 0);

  /**
  * @deprecated R422 CAT2DArcCircleRep::CreateRep
  * Constructs a 2D circle arc representation.
  * @param iCenter
  *	the center of the 2D circle or 2D circle arc, it is a 2D point.
  * @param iRadius
  *	the radius of the 2D circle or 2D circle arc.
  * @param iStart_angle
  *	the start angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 0.
  *	By this way, it creates a 2D circle.
  * @param iEnd_angle
  *	the end angle to construct a 2D circle arc.
  *	<br><b>legal values</b>: the default value is 2*pi.
  *	By this way, it creates a 2D circle.
  * @param iFill
  *	the integer which allows to construct a 2D circle arc or a 2D circle
  *	just with edges or filled with graphic attributes.
  *	<br><b>legal values</b>:
  *		<br>NOFILL : just edges are drawn.
  *		<br>FILL : the dynamic graphic primitive is filled with
  *				graphic attributes.
  * @param iStaticSagUsed
  *	used to specify wheter using a dynamic or a static sag
  *	for the circle arc visualization
  *	<br><b>legal values</b>:
  *		<br>0 :  the sag value is static and taken from settings,
  *		and is constant whatever the distance between the viewpoint
  *		and the circle arc be
  *		<br>1 : the sage value is dynamic and calculated
  *		depending on the distance between the viewpoint and
  *		the circle arc.
  */
  CAT2DArcCircleRep(const double iCenter[2], const double iRadius,
    const double iStart_angle = 0., const double iEnd_angle = 6.2831853,
    const int iFill = NOFILL, const int iStaticSagUsed = 0);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DArcCircleRep();

  /**
  * Modifies the center or the radius of the 2D circle arc or the 2D circle.
  * @param iCenter
  *	the new center of the 2D circle arc or the 2D circle
  * @param iRadius
  *	the new radius of the 2D circle arc or the 2D circle
  */
  void Modify(const float iCenter[2], const float iRadius);


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

  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  //------------------------------------------------------------------------------
protected:

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

private:

  /**
   * @nodoc
   * Constructs an empty 2DArcCircleRep -UnStreaming-
   */
  CAT2DArcCircleRep();

  CAT2DArcCircleGP* _geometrie;
};

#endif 









