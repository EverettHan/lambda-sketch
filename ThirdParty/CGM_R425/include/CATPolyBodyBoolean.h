// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBoolean.h
//
//===================================================================
// 07/13 - NDO : Creation
// 04/19 - F1Z : Migration on Nary observer
// MM/YY
//===================================================================
#ifndef CATPolyBodyBoolean_H
#define CATPolyBodyBoolean_H

// PolyhedralMathematics
#include "Poly/TemplateUtils.h"


#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATPolyBoolean.h"
#include "CATPolyBodyOperandContainer.h"
#include "CATPolyBodyNaryObserver.h"

class CATPolyBody;
class CATPolyCell;
class CATPolyVertex;
class CATPolyEdge;
class CATPolyFace;
class CATMathTransformation;
class CATMapOfIntToInt;

class CATPolyBodyBooleanImpl;
class CATPolyBodyBooleanObserver;
class CATPolyBodyBooleanOptions;

class CATProgressCallback;


/**
 * Boolean operator for solid operands of CATPolyBody type.
 * It performs the union, intersection or subtraction between two solid operands.
 * The result is returned in a new CATPolyBody instance.
 *
 * It can also clip a skin by a solid operand.  
 * To do clipping, just pass as arguments the skin and solid CATPolyBody operands to the operator (in any order) 
 * and perform an intersection between the operands.
 *
 * The union or subtraction operations will fail unless the operands are both solid.
 *
 * @see CATPolyBodyNaryObserver
 *
*/
class ExportedByPolyBodyBoolean CATPolyBodyBoolean
{

public:

  typedef CATPolyBodyNaryObserver Observer;

public:

  /**
   * Constructor of the boolean operator.
   * @param iOptions
   *   @see CATPolyBodyBooleanOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBodyBoolean (const CATPolyBodyBooleanOptions* iOptions = 0);

  ~CATPolyBodyBoolean ();

  /**
   * Updates the operator options.
   */
  void SetOptions (const CATPolyBodyBooleanOptions& iOptions);

  // DEPRECATED (To get rid of.)
  CATPolyBodyBoolean (const double iDTolerance);

public:

  /**
   * Enumerator that specifies the boolean operation.
   */
  enum BooleanOperation
  {
    /** Extract the part of Operand 1 in Operand 0
        (preserves all operands loops) */                       //eBooleanOperand1InOperand0 = CATPolyBoolean::eBooleanOperand1InOperand0,
    /** Extract the part of Operand 0 in Operand 1
        (preserves all operands loops) */                       //eBooleanOperand0InOperand1 = CATPolyBoolean::eBooleanOperand0InOperand1,
    /** Do the union of the two operands. */                    eBooleanUnion = CATPolyBoolean::eBooleanUnion,
    /** Do the intersection of the two operands. */             eBooleanIntersection = CATPolyBoolean::eBooleanIntersection,
    /** Do the subtraction of Operand 1 from Operand 0. */      eBooleanSubtraction = CATPolyBoolean::eBooleanSubtraction,
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
                  int * oTag = NULL);
  /**
   * Set the progress callback for progress feedback during the execution
   */
  void SetProgressCallback(CATProgressCallback * ioProgress);


public:

  /**
   * Runs the operator given the provided operands.
   * This method must be called prior to calls to the GetResult () method, and after AddOperand methods.
   */
  HRESULT Run();

  /**
   * Returns the result of the boolean operation after a successfull call to Run ().
   * This method can be called several times to perform distinct boolean operations between the operands.
   * Upon successful completion of the call, it creates a new instance of a CATPolyBody representing the boolean result.
   * 
   * @param oResult
   *   The resulting CATPolyBody.
   *   This instance must be released.
   *   The result is in the first operand referential (iPosition0)
   * @param iObserver
   *   An observer to obtain the mappings of the resulting cells to the input operand cells.
   * @param iOperation
   *   Specifies the boolean operation.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null for an empty body) has been constructed.
   *   <li> <tt>S_FALSE</tt> A result cannot be constructed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT GetResult (CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver,
                     const CATPolyBoolean::BooleanOperation iOperation);

public:
  /**
   * For old option (runmesh, old mesh boolean), use this run.
   */
  HRESULT Run(const CATPolyBoolean::BooleanOperation iOperation,
              CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver = 0);

public:
  /**
  * @deprecated
  */
  HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
              const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
              const CATPolyBoolean::BooleanOperation iOperation,
              CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver = 0);

  /**
  * @deprecated
 */
  HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0, const int iTag0,
              const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1, const int iTag1);

  /**
  * @deprecated
   */
  inline HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                     const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1);

private:

  CATPolyBodyBooleanImpl* _Operator;
  CATPolyBodyBooleanObserver* _Observer;
  double _DummyTolerance;

public:

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetCaptureObserver (CATPolyBodyBooleanObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyBodyBooleanObserver* GetCaptureObserver () const;

};

inline HRESULT CATPolyBodyBoolean::Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                                        const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1)
{
  return Run (iOperand0, iPosition0, 0, iOperand1, iPosition1, 1);
}

inline void CATPolyBodyBoolean::SetCaptureObserver (CATPolyBodyBooleanObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyBodyBooleanObserver* CATPolyBodyBoolean::GetCaptureObserver () const
{
  return _Observer;
}

#endif
