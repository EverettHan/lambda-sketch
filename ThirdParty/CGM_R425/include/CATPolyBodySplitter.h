// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySplitter.h
//
//===================================================================
// October 2015 Creation: ndo & jxo
//===================================================================
#ifndef CATPolyBodySplitter_H
#define CATPolyBodySplitter_H

#include "Poly/TemplateUtils.h"

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

class CATPolyBodyNaryObserver;
class CATPolyBodySplitterImpl;
class CATPolyBodySplitterObserver;
class CATPolyBodyOverlayOptions;


/**
 * Splitter of CATPolyBody objects.
 * This operators splits a CATPolyBody operand along the intersection curves with
 * a second CATPolyBody operand.  It reconstructs a CATPolyBody result by extraction of the
 * left-hand side, right-hand side or both sides of the intersection curves.  The sides are specified
 * with respect to the orientation of the intersection curves.
 *
 * @see CATPolyBodyNaryObserver
 */
class ExportedByPolyBodyBoolean CATPolyBodySplitter
{

public:

  /**
   * Constructor of the splitter operator.
   * @param iOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBodySplitter (const CATPolyBodyOverlayOptions* iOptions = 0);

  ~CATPolyBodySplitter ();

  /**
   * Updates the operator options.
   */
  void SetOptions (const CATPolyBodyOverlayOptions& iOptions);

public:

  /**
   * Enumerator that specifies the side for the split.
   */
  enum Side
  {
    /** Unset. */                                                eUnset =  0,
    /** Left-hand side of the splitter operand ("inside"). */    eLHS   = +1,
    /** Right-hand side of the splitter operand ("outside"). */  eRHS   = -1,
    /** On the splitter operand (same orientation). */           eOnPos = +2,
    /** On the splitter operand (opposite orientation). */       eOnNeg = -2,
    /** Both sides of the splitter operand
        LHS and RHS delimited by edges in one body. */           eBothSides = 3
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
                  int * oTag = nullptr);

  /**
   * Split all the provided operands with the operand of tag iSplitterTag.
   * By default, the splitter is the last operand added.
   * This method must be called prior to calls to the GetResult () and GetIntersectionCurves () methods.
   */
  HRESULT Run();
  HRESULT Run(const int iSplitterTag);

  /**
   * Extracts the result from the operator after a successfull call to Run ().
   * This method can be called as many times as required to extract different sides of the operands.
   * Upon successful completion of the call, it creates a new instance of a CATPolyBody representing the split result.
   * 
   * @param oResult
   *   The resulting CATPolyBody.
   *   This instance must be released.
   * @param iObserver
   *   An observer to obtain the mappings of the resulting cells to the input operand cells.
   * @param side
   *   Specifies the extracted side of the split surfaces.
   *   <ul>
   *     <li> eLHS:    Extracts the surfaces on the left-hand side of the other operand ("inside").
   *     <li> eRHS:    Extracts the surfaces on the right-hand side of the other operand ("outside").
   *     <li> eOnPos:  Extracts the surfaces in contact (overlapping) with the other operand and having the same orientation.
   *     <li> eOnNeg:  Extracts the surfaces in contact (overlapping) with the other operand and having opposite orientation.
   *   </ul>
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null for an empty body) has been constructed.
   *   <li> <tt>S_FALSE</tt> A result was not constructed because the side cannot be defined.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT GetResult (CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver = 0,
                     int side = eRHS, unsigned int doNotUse = 0);

private:

  CATPolyBodySplitterImpl* _Operator;
  CATPolyBodySplitterObserver* _Observer;

public:

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetCaptureObserver (CATPolyBodySplitterObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyBodySplitterObserver* GetCaptureObserver () const;

  public:
    /**
    * @deprecated
    * use AddOperand & Run methods
     */
    HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0, const int iTag0,
                const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1, const int iTag1,
                unsigned int indexOperand = 0);

    /**
    * @deprecated
    * use AddOperand & Run methods
     */
    inline HRESULT Run(const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                       const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                       unsigned int indexOperand = 0);
};

inline HRESULT CATPolyBodySplitter::Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                                         const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                                         unsigned int indexOperand)
{
  return Run (iOperand0, iPosition0, 0, iOperand1, iPosition1, 1, indexOperand);
}

inline void CATPolyBodySplitter::SetCaptureObserver (CATPolyBodySplitterObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyBodySplitterObserver* CATPolyBodySplitter::GetCaptureObserver () const
{
  return _Observer;
}

#endif
