// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHOverlayOperator.h
//
//===================================================================
// July 2014 Creation: ndo
//===================================================================
#ifndef CATPolyBVHOverlayOperator_H
#define CATPolyBVHOverlayOperator_H

#include "PolyBodyBoolean.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATPolyBodyOverlayOptions.h"

class CATBVHTree;
class CATPolyBody;
class CATPolyCell;
class CATIPolyCurve;
class CATMathTransformation;
class CATPolyBodyOverlayDebug;


/**
* Overlay operator for BVH Trees: CATBVHTree.
* This operators clashes CATPolyBody operands from the BVH trees and edits the operands to make 
* them conformal along their intersections.  Observer calls are made for capture of the conformal
* operands and their intersection curves.
*/
class ExportedByPolyBodyBoolean CATPolyBVHOverlayOperator
{

public:

  /**
   * Constructs an instance of CATPolyBVHOverlayOperator operator.
   * @param iOptions
   *   @see CATPolyBodyBooleanOptions
   *   @see CATPolyBodyOverlayOptions
   */
  inline CATPolyBVHOverlayOperator (const CATPolyBodyOverlayOptions* iOptions = 0);

  ~CATPolyBVHOverlayOperator () {}

  /**
   * Sets the operator options.
   */
  inline void SetOptions (const CATPolyBodyOverlayOptions& iOptions);

  /**
   * Returns the options.
   */
  inline const CATPolyBodyOverlayOptions& GetOptions () const;

public:

  /**
   * Observer interface.
   * This observer interface must be implemented to capture the CATPolyBody constructed from an overlay.
   * It can also be used to map the cells from the output CATPolyBody to the cells from the input operands.
   */
  class ExportedByPolyBodyBoolean Observer
  {

  public:

    virtual ~Observer () {}

  public:

    /**
      * Observer call made when a binary operation between two CATPolyBody operands begins.
      * @param iOperand0
      *   The first CATPolyBody operand.
      * @param iPosition0
      *   The optional position of the first operand.
      * @param iOperand1
      *   The second CATPolyBody operand.
      * @param iPosition1
      *   The optional position of the second operand.
      */
    virtual void Begins (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                         const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1) {}

    /**
      * Observer call made when a binary operation between two CATPolyBody operands ends.
      * The argument is the HRESULT returned by the Run () method.
      */
    virtual void Ends (HRESULT hrRun) {}

  public:

    /**
     * Call made before the construction of the intersection curves from the initial overlay.
     */
    virtual void BeginInitialIntersectionCurves () {}

    /**
     * Call made after the construction of the intersection curves from the initial overlay.
     */
    virtual void EndInitialIntersectionCurves () {}

    /**
     * Call made before the construction of the intersection curves from the processed overlay.
     */
    virtual void BeginProcessedIntersectionCurves () {}

    /**
     * Call made after the construction of the intersection curves from the processed overlay.
     */
    virtual void EndProcessedIntersectionCurves () {}

    /**
     * Observer call made after construction of an intersection curve from the overlay (initial or processed.)
     * This method is called as many times as the number of distinct intersection curves constructed from the overlay.
     * For curves from the initial overlay, the calls are preceded by a call to BeginInitialIntersectionCurves () and
     * succeeded by a call to EndInitialIntersectionCurves ().
     * For curves from the processed overlay, the calls are preceded by a call to BeginProcessedIntersectionCurves () and
     * succeeded by a call to EndProcessedIntersectionCurves ().
     * @param iPolyCurve
     *   The intersection curve.  The reference count must be incremented when keeping a reference to this CATIPolyCurve.
     * @param iCellOperand0
     *   The cell from Operand 0 associated to this curve.
     * @param iCellOperand1
     *   The cell from Operand 1 associated to this curve.
     */
    virtual void IntersectionCurve (CATIPolyCurve& iPolyCurve, CATPolyCell* iCellOperand0, CATPolyCell* iCellOperand1) {}

  public:

    /**
     * Observer call made to map cells from a CATPolyBody to cells from Operand 0 or Operand 1.
     * After mapping of all the cells, a call to ProcessedOperand0 (), ProcessedOperand1 () or Result () is made.
     */
    virtual void MapPolyCells (CATPolyCell* iResultCell, CATPolyCell* iCellOperand0, CATPolyCell* iCellOperand1) {}

    /**
     * Observer call made after processing of the overlay with a CATPolyBody representing Operand 0.
     * The reference count of the CATPolyBody passed as an argument must be incremented when 
     * keeping a reference to the result.
     */
    virtual void ProcessedOperand0 (CATPolyBody& iPolyBody) {}

    /**
     * Observer call made after processing of the overlay with a CATPolyBody representing Operand 1.
     * The reference count of the CATPolyBody passed as an argument must be incremented when 
     * keeping a reference to the result.
     */
    virtual void ProcessedOperand1 (CATPolyBody& iPolyBody) {}

  };

public:

  /**
   * Runs the overlay operator between the two BVH tree operands.  
   * Observer calls are made for each pair of CATPolyBody operands processed by the operator.
   */
  HRESULT Run (CATBVHTree& iBVHTreeOperand0, const CATMathTransformation* iTreePosition0, 
               CATBVHTree& iBVHTreeOperand1, const CATMathTransformation* iTreePosition1,
               Observer& iObserver,
               CATPolyBodyOverlayDebug* bdbg = 0);

private:

  CATPolyBodyOverlayOptions _Options;

};


inline CATPolyBVHOverlayOperator::CATPolyBVHOverlayOperator (const CATPolyBodyOverlayOptions* iOptions)
{
  if (iOptions)
    _Options = *iOptions;
}

inline void CATPolyBVHOverlayOperator::SetOptions (const CATPolyBodyOverlayOptions& iOptions)
{
  _Options = iOptions;
}

inline const CATPolyBodyOverlayOptions& CATPolyBVHOverlayOperator::GetOptions () const
{
  return _Options;
}

#endif
