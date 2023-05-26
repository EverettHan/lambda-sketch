#ifndef CAT3DLineRep_H
#define CAT3DLineRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CAT3DRep.h"
#include "SGInfra.h"
#include "CATVisMacroForInterfaces.h"

class IVisSG3DPrimitiveIterator;
class CAT3DLineRepIVisSG3DPrimitiveIteratorBOAImpl;

class CAT3DLineGP;
class CATMathPointf;

/** Class to create the representation of a line segment. */
class ExportedBySGInfra CAT3DLineRep : public CAT3DRep
{
  friend class CATMarshallable3DLineRep;
  friend class CATDmuStream3DLineRep;
  friend class CATVrmlMaker3DLineRep;
  friend class CATVrml2Maker3DLineRep;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DLineRep, IVisSG3DPrimitiveIterator, CAT3DLineRepIVisSG3DPrimitiveIteratorBOAImpl);

public:

  virtual ~CAT3DLineRep();

  /** Constructs an empty representation of a line segment. */
  static CAT3DLineRep* CreateRep();

  /** Constructs the representation of a line segment from end-point coordinates.
   * @param iCoordinates
   * The coordinates of the extremities of the line segment.
   */
  static CAT3DLineRep* CreateRep(const float iCoordinates[6]);

  /** Constructs the representation of a line segment from end-points.
   * @param iFirstPoint
   * The first extremity of the line segment.
   * @param iSecondPoint
   * The second extremity of the line segment.
   */
  static CAT3DLineRep* CreateRep(const CATMathPointf &firstPoint, const CATMathPointf &secondPoint);

protected:

   /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DLineRep();

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DLineRep(const float iCoordinates[6]);

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DLineRep(const CATMathPointf &firstPoint, const CATMathPointf &secondPoint);

  /** @nodoc : nodoc : deprecated constructor. */
  CAT3DLineRep(CATModelIdentificator & iModelId,
               void     * iController = NULL);

  /** @nodoc : deprecated constructor. */
  CAT3DLineRep(const CATMathPointf   & iFirstPoint,
               const CATMathPointf   & iSecondPoint,
               CATModelIdentificator & iModelId,
               void     * iController = NULL);

public:

  /** Modifies the representation of a line segment with the new end-point coordinates.
   * @param iCoordinates
   * The coordinates of the extremities of the line segment.
   */
  void Modify(const float iCoordinates[6]);

  /** Modifies the representation of a line segment with the new end-points.
   * @param iFirstPoint
   * The first extremity of the line segment.
   * @param iSecondPoint
   * The second extremity of the line segment.
   */
  void Modify(const CATMathPointf & iFirstPoint,
              const CATMathPointf & iSecondPoint);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void DrawShading(CATRender &iRender, int iInside) FUNC_OVERRIDE_FINAL;

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

  /** Retrieves the representation of the line.
   * @param oCoordinates
   * The array of points that will be filled with the extremity points.
   */
  void Get(float oCoordinates[6]);

  /** Retrieves the representation of the line.
   * @param oFirstPoint
   * The first extremity of the line segment.
   * @param oSecondPoint
   * The second extremity of the line segment.
   */
  void Get(CATMathPointf & oFirstPoint,
           CATMathPointf & oSecondPoint);

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

protected:

  /* @nodoc */
  void BuildLine(const CATMathPointf & iFirstPoint, const CATMathPointf & iSecondPoint);

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  // data
  CAT3DLineGP * _geometrie;

};

#endif // CAT3DLineRep_H
