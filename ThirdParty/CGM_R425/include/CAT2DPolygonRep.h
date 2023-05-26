#ifndef CAT2DPolygonRep_H
#define CAT2DPolygonRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"
#include "CAT2DRep.h"
#include "CATVisMacroForInterfaces.h"

#ifndef NOFILL
#define NOFILL 0
#define FILL 1
#endif

class IVisSG2DPrimitiveIterator;
class CAT2DPolygonRepIVisSG2DPrimitiveIteratorBOAImpl;

class CAT2DPolygonGP;

/**
 * Class to create the representation of a 2D polygon.
 * <b>Role</b>: <pre>
 *           Example of a CAT2DPolygon with 4 points :
 *
 *             point 1 X--------------------X point 2
 *                     |                    |
 *                     |                    |
 *             point 4 X--------------------X point 3
 *              </pre>
 */
class ExportedBySGInfra CAT2DPolygonRep : public CAT2DRep
{
  friend class CATMarshallable2DPolygonRep;
  friend class CATDmuStream2DPolygonRep;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DPolygonRep, IVisSG2DPrimitiveIterator, CAT2DPolygonRepIVisSG2DPrimitiveIteratorBOAImpl);

public:

  /**
 *	Contructs an empty representation of a 2D polygon.
 */
  static CAT2DPolygonRep* CreateRep();

  /**
    * Constructs a 2D polygon representation from a list of points.
    * The last point is linked to the first point.
    * @param iPoints
    *   Array containing the x, y  coordinates for
    *   each point of the polygon. Its size is equal
    *   to two times the number of points. So, the coordinates
    *   x, y of the first point are respectively stored in iPoints[0], and  iPoints[1],
    *   the coordinates x, y of the second point, in iPoints[2], iPoints[3], and so on...
    * @param iNbPoints
    *   The number of points used to define the polygon.
    * @param iFill
    *	the integer which allows to construct a 2D polygon
    *	just with edges or filled with graphic attributes.
    *	<br><b>legal values</b>:
    *	<ul><li>NOFILL : just edges are drawn.</li>
    *	<li>FILL : the 2D circle arc or the 2D circle is filled
    *				with graphic attributes.</li></ul>
    *	The default value is FILL.
    */
  static CAT2DPolygonRep* CreateRep(const float* iPoints, const int iNbPoints, const int iFill);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @deprecated R422 CAT2DPolygonRep::CreateRep
  *	Default contructor.
  */
  CAT2DPolygonRep();

  /**
     * @deprecated R422 CAT2DPolygonRep::CreateRep
     * Constructs a 2D polygon representation from a list of points.
     * The last point is linked to the first point.
     * @param iPoints
     *   Array containing the x, y  coordinates for
     *   each point of the polygon. Its size is equal
     *   to two times the number of points. So, the coordinates
     *   x, y of the first point are respectively stored in iPoints[0], and  iPoints[1],
     *   the coordinates x, y of the second point, in iPoints[2], iPoints[3], and so on...
     * @param iNbPoints
     *   The number of points used to define the polygon.
     * @param iFill
     *	the integer which allows to construct a 2D polygon
     *	just with edges or filled with graphic attributes.
     *	<br><b>legal values</b>:
     *	<ul><li>NOFILL : just edges are drawn.</li>
     *	<li>FILL : the 2D circle arc or the 2D circle is filled
     *				with graphic attributes.</li></ul>
     *	The default value is FILL.
     */
  CAT2DPolygonRep(const float* iPoints, const int iNbPoints, const int iFill);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DPolygonRep();

  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive* gp);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /**
  *	@nodoc
  */
  virtual void DrawShading(CATRender& iRemder, int iInside) FUNC_OVERRIDE_FINAL;

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

protected:

  /**
  * @nodoc
  */
  CAT2DPolygonGP* _geometrie;
};

#endif 









