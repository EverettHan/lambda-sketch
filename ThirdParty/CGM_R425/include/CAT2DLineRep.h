#ifndef CAT2DLineRep_H
#define CAT2DLineRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"

#include "CAT2DRep.h"

 // definition of ALLOCATE/DONT_ALLOCATE, LINE/CURVE...
#include "CAT2DLineGP.h"
#include "CATVisMacroForInterfaces.h"
#include "CATGraphicPrimitive.h" // NHD :  Fix for CAA API closure errors 

class IVisSG2DPrimitiveIterator;
class CAT2DLineRepIVisSG2DPrimitiveIterator;

class CATMathPoint2Df;

/**
* Class to create the representation of a 2D segment.
* <b>Role</b> :
*	this representation is composed only of one 2D segment.
*/
class ExportedBySGInfra CAT2DLineRep : public CAT2DRep
{
  friend class CATDmuStream2DLineRep;
  friend class CAT2DFinalLineRep;
  friend class CAT2DLineGeometryRep;

  CATDeclareClass;
  
  CATVisDeclarePublicInterfaceAdhesion(CAT2DLineRep, IVisSG2DPrimitiveIterator, CAT2DLineRepIVisSG2DPrimitiveIterator);

public:

  /**
  * Constructs an empty representation of a 2D segment
  */
  static CAT2DLineRep* CreateRep();

  /** Constructs the representation of a 2D segment.
  * @param iPoints
  * The coordinates of the extremities of the 2D segment (XYXY).
  */
  static CAT2DLineRep* CreateRep(const float iPoints[4]);

  /**
  * Constructs the representation of a 2D segment.
  * @param iFirstPoint
  * The first extremity of the line segment.
  * @param iSecondPoint
  * The second extremity of the line segment.
  */
  static CAT2DLineRep* CreateRep(const CATMathPoint2Df& iFirstPoint, const CATMathPoint2Df& iSecondPoint);

  /**
  * Constructs a 2D line representation from point coordinates.
  * @param iPoints
  *    Array of point coordinates: XYXYXY...
  *    Its size is equal to two times the number of points.
  * @param iNbPoints
  *    The number of points.
  * @param iAlloc
  *    Flag used to specify whether points must be duplicated or not.
  *    <br><b>Legal values</b>:
  *    <ul>
  *      <li>ALLOCATE :
  *        All data are duplicate into the graphic primitive</li>
  *      <li>DONT_ALLOCATE
  *        The graphic primitive has a pointer to the data given as parameter</li>
  *    </ul>
  *    The default value is ALLOCATE.
  * @param iLineType
  *    Flag to specify the line type to use.
  *    <br><b>Legal values</b>:
  *    <ul>
  *      <li>LINES :
  *        The number of points must be even. A line will be drawn
  *            between points 1 and 2, another line will be drawn between
  *            points 3 and 4, ...
  *			<pre>
  *                       point 1 X--------------------X point 2
  *                                                   point 3 X-----------------------X point 4
  *			</pre>
  *		</li>
  *      <li>LINE_STRIP :
  *        The number of points can be either even or odd. A line will
  *            be drawn between points 1 and 2, then, another line will be drawn
  *            between points 2 and 3, ...
  *			<pre>
  *                       point 1 X--------------------X point 2
  *                                                   /
  *                                                 /
  *                                               /
  *                                      point 3 X----------------------X point 4
  *			</pre>
  *		</li>
  *      <li>LINE_LOOP :
  *        Same as LINE_LOOP, excepted that one more line will be
  *            drawn between the last and the first points.
  *			<pre>
  *                                    point 1 X--------X point 2
  *                                             \      /
  *                                              \    /
  *                                               \  /
  *                                                \/
  *                                                /\
  *                                               /  \
  *                                      point 3 X----X point 4
  *			</pre>
  *		</li>
  *    </ul>
  *    The default value is LINES.
  */
  static CAT2DLineRep* CreateRep(const float iPoints[], const int iNbPoints,
    const int iAlloc = ALLOCATE, const int iLinetype = LINES, const TessFlag iTessFlag = LINE);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class OR CAT2DFinalLineRep to derive" )
#endif
  BEGIN_MIGRATE_REP_CTOR_PRIVATE
  /**
  * @deprecated R422 CAT2DLineRep::CreateRep
  * Default constructor.
  */
  CAT2DLineRep();

  /**
  * @deprecated R422 CAT2DLineRep::CreateRep
  * Constructs the representation of a 2D segment.
  * @param iPoints
  * The coordinates of the extremities of the 2D segment (XYXY).
  */
  CAT2DLineRep(const float iPoints[4]);

  /**
  * @deprecated R422 CAT2DLineRep::CreateRep
  * Constructs the representation of a 2D segment.
  * @param iFirstPoint
  * The first extremity of the line segment.
  * @param iSecondPoint
  * The second extremity of the line segment.
  */
  CAT2DLineRep(const CATMathPoint2Df& iFirstPoint, const CATMathPoint2Df& iSecondPoint);

  /**
  * @deprecated R422 CAT2DLineRep::CreateRep
  * Constructs a 2D line representation from point coordinates.
  * @param iPoints
  *    Array of point coordinates: XYXYXY...
  *    Its size is equal to two times the number of points.
  * @param iNbPoints
  *    The number of points.
  * @param iAlloc
  *    Flag used to specify whether points must be duplicated or not.
  *    <br><b>Legal values</b>:
  *    <ul>
  *      <li>ALLOCATE :
  *        All data are duplicate into the graphic primitive</li>
  *      <li>DONT_ALLOCATE
  *        The graphic primitive has a pointer to the data given as parameter</li>
  *    </ul>
  *    The default value is ALLOCATE.
  * @param iLineType
  *    Flag to specify the line type to use.
  *    <br><b>Legal values</b>:
  *    <ul>
  *      <li>LINES :
  *        The number of points must be even. A line will be drawn
  *            between points 1 and 2, another line will be drawn between
  *            points 3 and 4, ...
  *			<pre>
  *                       point 1 X--------------------X point 2
  *                                                   point 3 X-----------------------X point 4
  *			</pre>
  *		</li>
  *      <li>LINE_STRIP :
  *        The number of points can be either even or odd. A line will
  *            be drawn between points 1 and 2, then, another line will be drawn
  *            between points 2 and 3, ...
  *			<pre>
  *                       point 1 X--------------------X point 2
  *                                                   /
  *                                                 /
  *                                               /
  *                                      point 3 X----------------------X point 4
  *			</pre>
  *		</li>
  *      <li>LINE_LOOP :
  *        Same as LINE_LOOP, excepted that one more line will be
  *            drawn between the last and the first points.
  *			<pre>
  *                                    point 1 X--------X point 2
  *                                             \      /
  *                                              \    /
  *                                               \  /
  *                                                \/
  *                                                /\
  *                                               /  \
  *                                      point 3 X----X point 4
  *			</pre>
  *		</li>
  *    </ul>
  *    The default value is LINES.
  */
  CAT2DLineRep(const float iPoints[], const int iNbPoints,
    const int iAlloc = ALLOCATE, const int iLinetype = LINES, const TessFlag iTessFlag = LINE);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DLineRep();

  /**
  * Modifies the representation of a 2D segment.
  * @param iPoints
  * The coordinates of the extremities of the 2D segment.
  */
  void Modify(const float iPoints[4]);

  /**
  * Modifies the representation of a 2D segment.
  * @param iFirstPoint
  * The first extremity of the line segment.
  * @param iSecondPoint
  * The second extremity of the line segment.
  */
  void Modify(const CATMathPoint2Df& iFirstPoint, const CATMathPoint2Df& iSecondPoint);

  /**
  * @nodoc
  */
  virtual void DrawShading(CATRender& iRender, int iInside);

  /**
   * @nodoc
   */
  virtual void ReverseLineRoute();

  /**
   * @nodoc
   */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive* gp);

protected:

  /** @nodoc */
  void BuildLine(const CATMathPoint2Df&, const CATMathPoint2Df&);

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  /** @nodoc */
  CAT2DLineGP* _geometrie;

};

#endif 









