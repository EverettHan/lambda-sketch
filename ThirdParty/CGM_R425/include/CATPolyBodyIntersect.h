// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyIntersect.h
//
//===================================================================
// February 2016 Creation: ndo
//===================================================================
#ifndef CATPolyBodyIntersect_H
#define CATPolyBodyIntersect_H

#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

class CATPolyBody;
class CATPolyCell;
class CATPolyVertex;
class CATPolyEdge;
class CATPolyFace;
class CATMathTransformation;
class CATMapOfIntToInt;
class CATIPolyCurve;
class CATIPolyPoint;

class CATPolyBodyNaryObserver;
class CATPolyBodyIntersectImpl;
class CATPolyBodyIntersectObserver;
class CATPolyBodyOverlayOptions;


/**
 * Intersects two CATPolyBody operands.
 * This operators intersects two (skin) CATPolyBody operands and computes their intersection curves.
 * The result is returned in a new CATPolyBody instance.
 *
 * @see CATPolyBodyNaryObserver
*/
class ExportedByPolyBodyBoolean CATPolyBodyIntersect
{

public:

  /**
   * Constructor of the intersect operator.
   * @param iOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBodyIntersect (const CATPolyBodyOverlayOptions* iOptions = 0);

  ~CATPolyBodyIntersect ();

  /**
   * Updates the operator options.
   */
  void SetOptions (const CATPolyBodyOverlayOptions& iOptions);

  // DEPRECATED (To get rid of.)
  CATPolyBodyIntersect (const double iDTolerance);

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
                  int * oTag = nullptr);

  /**
   * This method must be called prior to calls to the GetResult () method.
   * @param iConformal
   *   An option turned on to compute conformal intersection curves.
   *   Conformal intersection curves are computed from a conformal overlay.
   */
  HRESULT Run(CATBoolean iConformal = FALSE);

  /**
   * Computes a CATPolyBody operands constructed from the intersection curves between the
   * two operands.  It must be called after an initial call to Run.
   * 
   * @param oResult
   *   The resulting CATPolyBody.
   *   This instance must be released.
   * @param iObserver
   *   An observer to obtain the mappings of the resulting cells to the input operand cells.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null for an empty body) has been constructed.
   *   <li> <tt>S_FALSE</tt> A result cannot be constructed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT GetResult (CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver = 0);

public:
  /**
   * deprecated
   */
  HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0, const int iTag0,
              const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1, const int iTag1,
              CATBoolean iConformal = FALSE);
  /**
   * deprecated
   */
  inline HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                     const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                     CATBoolean iConformal = FALSE);

private:

  CATPolyBodyIntersectImpl* _Operator;
  CATPolyBodyIntersectObserver* _Observer;

public:

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetCaptureObserver (CATPolyBodyIntersectObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyBodyIntersectObserver* GetCaptureObserver () const;

};

inline HRESULT CATPolyBodyIntersect::Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                                          const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                                          CATBoolean iConformal)
{
  return Run (iOperand0, iPosition0, 0, iOperand1, iPosition1, 1, iConformal);
}

inline void CATPolyBodyIntersect::SetCaptureObserver (CATPolyBodyIntersectObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyBodyIntersectObserver* CATPolyBodyIntersect::GetCaptureObserver () const
{
  return _Observer;
}

#endif
