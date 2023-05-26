//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Angle Measure Operator between two Visualization representations
// (CATRep). Gives an interface between Visualization data and the
// angle measure operator on two CATBVHTree @CATPolyBVHAngle.
//
//=============================================================================
// 2009-10-16   XXC: New.
// 2013-08-22   JXO: CATTolerance for XScale compliance
// 2015-05-06   JXO: CATPolyBody operands, see IR 357262
//=============================================================================

#ifndef CATPolyVisuBVHAngle_h
#define CATPolyVisuBVHAngle_h

#include "PolyVisuMeasureBetween.h"
#include "CATPolyVisuBVHMeasureBetween.h"
#include "CATPolyBVHAngle.h"

// Math
#include "CATMathConstant.h"
#include "CATTolerance.h"
// System
#include "CATBoolean.h"

class CATRep;
class CAT3DBagRep;
class CAT4x4Matrix;
class CATMathPoint;

/**
 * Computes the angle between two segments, lines, planes or planar
 * faces given as visualisation representations (CATRep).
 * Note about memory consumption: Temporary computation data, refering
 * to the operands and their positions, are stored inside this
 * Operator and it does not return to the user of the operator to
 * manage them. These data are released each time an operand changes or
 * when the operator is rebooted or deleted.
 */

class ExportedByPolyhedralMeasureBetween CATPolyVisuBVHAngle : public CATPolyVisuBVHMeasureBetween
{
 public:
  CATPolyVisuBVHAngle(const CATTolerance & iTol = CATGetDefaultTolerance());

  ~CATPolyVisuBVHAngle();

  /** Defines the two objects to use for the distance computation.
   *@param iRepPath1: Path to a visualization representation of the first 3D object.
   *@param iSelPoint1: Selection point used to select the first
   *object. Allows to discard ambiguities.
   *@param iRepPath2: Path to a visualization representation of the first 3D object.
   *@param iSelPoint2: Selection point used to select the second
   *object. Allows to discard ambiguities.
   *@param iSubType1: type of sub-element to consider in the first
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@param iSubType2: type of sub-element to consider in the second
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetOperands(CATRepPath * iRepPath1, const CATMathPoint & iSelPoint1,
                      CATRepPath * iRepPath2, const CATMathPoint & iSelPoint2,
                      SubElementType iSubType1 = HighestLevelType,
                      SubElementType iSubType2 = HighestLevelType);

  /** Defines the two objects to use for the distance computation.
   *@param iRep1: visualization representation of the first 3D object.
   *@param iPosition1: position to use for the first 3D object.
   *@param iSelPoint1: Selection point used to select the first
   *object. Allows to discard ambiguities.
   *@param iRep2: visualization representation of the first 3D object.
   *@param iPosition2: position to use for the second 3D object.
   *@param iSelPoint2: Selection point used to select the second
   *object. Allows to discard ambiguities.
   *@param iSubType1: type of sub-element to consider in the first
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@param iSubType2: type of sub-element to consider in the second
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetOperands(CATRep * iRep1, CAT4x4Matrix * iPosition1, const CATMathPoint & iSelPoint1,
                      CATRep * iRep2, CAT4x4Matrix * iPosition2, const CATMathPoint & iSelPoint2,
                      SubElementType iSubType1 = HighestLevelType,
                      SubElementType iSubType2 = HighestLevelType);

  HRESULT SetFirstOperand(CATRepPath * iRepPath, const CATMathPoint & iSelPoint,
                          SubElementType iSubType = HighestLevelType);
  
  HRESULT SetFirstOperand(CATRep * iRep, CAT4x4Matrix * iPosition, const CATMathPoint & iSelPoint,
                          SubElementType iSubType = HighestLevelType);
  
  HRESULT SetFirstOperand(CATModelForSubElement * iSubElement, CAT4x4Matrix * iPosition, const CATMathPoint & iSelPoint,
                          SubElementType iSubType = HighestLevelType);
  
  HRESULT SetSecondOperand(CATRepPath * iRepPath, const CATMathPoint & iSelPoint,
                           SubElementType iSubType = HighestLevelType);
  
  HRESULT SetSecondOperand(CATRep * iRep, CAT4x4Matrix * iPosition, const CATMathPoint & iSelPoint,
                           SubElementType iSubType = HighestLevelType);
  
  HRESULT SetSecondOperand(CATModelForSubElement * iSubElement, CAT4x4Matrix * iPosition, const CATMathPoint & iSelPoint,
                           SubElementType iSubType = HighestLevelType);
  
  /**
   * Set the first operand as a CATPolyBody
   * @param iPoly can be released after this call
   */
  virtual HRESULT SetFirstOperand(CATPolyBody * iPoly, const CATMathTransformation * iPos, const CATMathPoint & iSelPoint,
                                  SubElementType iSubType = HighestLevelType);
  /**
   * Set the second operand as a CATPolyBody
   * @param iPoly can be released after this call
   */
  virtual HRESULT SetSecondOperand(CATPolyBody * iPoly, const CATMathTransformation * iPos, const CATMathPoint & iSelPoint,
                                   SubElementType iSubType = HighestLevelType);

  /** Gets the angle measured between the two objects. The result is
   *  significant only if two operands has been set and the operator
   *  successfully run.
   *@param iFormat: ask the method to return the measure in degree or
   *radian. Legal values are 0 for degree (default value) or any other
   *value for radian.
   *@return -1 if the class instance has not been correctly
   *initialized or successfully run, the computed angle between the
   *two instanciated objects otherwise.
   */
  CATAngle GetAngle(int iFormat = 0) const;

 private:

  HRESULT SetOperands(CATRepPath * iRepPath1, CATRepPath * iRepPath2,
                      SubElementType iSubType1, SubElementType iSubType2);

  HRESULT SetOperands(CATRep * iRep1, CAT4x4Matrix * iPosition1,
                      CATRep * iRep2, CAT4x4Matrix * iPosition2,
                      SubElementType iSubType1, SubElementType iSubType2);

  HRESULT SetFirstOperand(CATRepPath * iRepPath,
                          SubElementType iSubType);
  
  HRESULT SetFirstOperand(CATRep * iRep, CAT4x4Matrix * iPosition,
                          SubElementType iSubType);
  
  HRESULT SetFirstOperand(CATModelForSubElement * iSubElement, CAT4x4Matrix * iPosition,
                          SubElementType iSubType);
  
  HRESULT SetSecondOperand(CATRepPath * iRepPath,
                           SubElementType iSubType);
  
  HRESULT SetSecondOperand(CATRep * iRep, CAT4x4Matrix * iPosition,
                           SubElementType iSubType);
  
  HRESULT SetSecondOperand(CATModelForSubElement * iSubElement, CAT4x4Matrix * iPosition,
                           SubElementType iSubType);

  static HRESULT RepHasOnlyOneSubElement(CATRep * iRep);
};

#endif //CATPolyVisuBVHAngle_h
