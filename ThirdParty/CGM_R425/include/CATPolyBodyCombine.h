// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyCombine.h
//
//===================================================================
// December 2015 Creation: ndo
//===================================================================
#ifndef CATPolyBodyCombine_H
#define CATPolyBodyCombine_H

#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

class CATPolyBody;
class CATMathTransformation;

class CATPolyBodyBinaryObserver;
class CATPolyBodyCombineImpl;
class CATPolyBodyCombineObserver;
class CATPolyBodyOverlayOptions;


/**
 * Combine two CATPolyBody operands.
 * This operators splits two CATPolyBody operands along their intersection curves
 * and combines the split samples from the operands.
 * The result is returned in a new CATPolyBody instance.
 *
 * @see CATPolyBodyBinaryObserver
*/
class ExportedByPolyBodyBoolean CATPolyBodyCombine
{

public:

  /**
   * Constructor of the splitter operator.
   * @param iOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBodyCombine (const CATPolyBodyOverlayOptions* iOptions = 0);

  ~CATPolyBodyCombine ();

  /**
   * Updates the operator options.
   */
  void SetOptions (const CATPolyBodyOverlayOptions& iOptions);

  // DEPRECATED (To get rid of.)
  //CATPolyBodyCombine (const double iDTolerance);

public:

  /**
   * Enumerator that specifies the sides of the operands to combine.
   */
  enum Sides
  {
    /** Unset. */                                           eUnset   = 0,
    /** RHS of Operand 1; RHS of Operand 0. */              eRHSRHS  = 1,
    /** RHS of Operand 1; LHS of Operand 0. */              eRHSLHS  = 2,
    /** LHS of Operand 1; RHS of Operand 0. */              eLHSRHS  = 3,
    /** LHS of Operand 1; LHS of Operand 0. */              eLHSLHS  = 4,
    /** Both side of Operand 1; Both side of Operand 0. */  eBothBoth = 5
  };

public:
  /**
  * Adds an operand to the operator.
  * Identifying tags must be different among all operands.
  */
  void AddOperand(const CATPolyBody& iOperand,
                  const CATMathTransformation* iPosition,
                  const int iTag);

  /**
   * Adds a CATPolyBody operand to the operator.
   * @see AddOperand
   */
  void AddOperand(const CATPolyBody& iOperand,
                  const CATMathTransformation* iPosition,
                  int * oTag=nullptr);

  /**
    * Runs the operator given the two operands.
    * This method must be called prior to calls to the GetResult() method.
    */
  HRESULT Run();

  /**
   * Combines the sides of the operands after a successfull call to Run ().
   * This method can be called as many times as required to combine differently the operands.
   * Upon successful completion of the call, it creates a new instance of a CATPolyBody representing the combine result.
   * 
   * @param oResult
   *   The resulting CATPolyBody.
   *   This instance must be released.
   * @param iObserver
   *   An observer to obtain the mappings of the resulting cells to the input operand cells.
   * @param sides
   *   Specifies the combined sides of the operands.
   *   <ul>
   *     <li> eRHSRHS: Combines the RHS of Operand 1 with the RHS of Operand 0.
   *     <li> eRHSLHS: Combines the RHS of Operand 1 with the LHS of Operand 0.
   *     <li> eLHSRHS: Combines the LHS of Operand 1 with the RHS of Operand 0.
   *     <li> eLHSLHS: Combines the LHS of Operand 1 with the LHS of Operand 0.
   *   </ul>
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null for an empty body) has been constructed.
   *   <li> <tt>S_FALSE</tt> A result cannot be constructed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT GetResult (CATPolyBody*& oResult, CATPolyBodyBinaryObserver* iObserver = 0,
                     int sides = eRHSRHS);

private:

  CATPolyBodyCombineImpl* _Operator;
  CATPolyBodyCombineObserver* _Observer;

public:

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetCaptureObserver (CATPolyBodyCombineObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyBodyCombineObserver* GetCaptureObserver () const;


public:
  /**
  * @deprecated
  * use AddOperand & Run methods
 */
  HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0, int iTag0,
              const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1, int iTag1);

  /**
  * @deprecated
  * use AddOperand & Run methods
   */
  inline HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                     const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1);

};

inline HRESULT CATPolyBodyCombine::Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                                        const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1)
{
  return Run (iOperand0, iPosition0, 0, iOperand1, iPosition1, 1);
}

inline void CATPolyBodyCombine::SetCaptureObserver (CATPolyBodyCombineObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyBodyCombineObserver* CATPolyBodyCombine::GetCaptureObserver () const
{
  return _Observer;
}

#endif
