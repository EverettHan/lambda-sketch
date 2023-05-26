// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyNaryJoin.h
//
//===================================================================
// December 2016 Creation: ndo/xxc
//===================================================================
#ifndef CATPolyBodyNaryJoin_H
#define CATPolyBodyNaryJoin_H

#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

class CATPolyBody;
class CATMathTransformation;

class CATPolyBodyNaryObserver;
class CATPolyBodyNaryJoinImpl;
class CATPolyBodyOverlayOptions;

class CATPolyBodyNaryJoinObserver; // Capture
class CATPolyBodyJoinOptions;

/**
 * Join two CATPolyBody operands along their boundaries.  This
 * operator joins two CATPolyBody operands along their common boundary
 * curves up to a given tolerance.
 * The result is returned in a new CATPolyBody instance.
 *
 * @see CATPolyBodyNaryObserver
*/
class ExportedByPolyBodyBoolean CATPolyBodyNaryJoin
{
public:

public:

  /**
   * Constructor of the join operator.
   * @param iOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBodyNaryJoin();

  ~CATPolyBodyNaryJoin ();

  /**
   * Sets the operator options.
   */
  void SetOptions (const CATPolyBodyOverlayOptions& iOptions);
  void SetOptions(const CATPolyBodyJoinOptions& iOptions);
  void SetObserver (CATPolyBodyNaryObserver * iObserver);

  /**
   * Adds an operand to the operator.
   * Identifying tags must be different among all operands.
   */
  void AddOperand (const CATPolyBody& iOperand, const CATMathTransformation* iPosition, const int iTag);

  /**
   * Adds a CATPolyBody operand to the operator.
   * @see AddOperand
   */
  void AddPolyBody (const CATPolyBody& iOperand, const CATMathTransformation* iPosition);

public:

  /**
   * Runs the operator between all given CATPolyBody's through AddPolyBody method.
   * This method must be called prior to a call to the GetResult () method.
   */
  HRESULT Run ();

  /**
   * Gets the joined operands after a successfull call to Run ().
   * Upon successful completion of the call, it creates a new instance of a CATPolyBody representing the join result.
   *
   * @param oResult
   *   The resulting CATPolyBody.
   *   This instance must be released.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null for an empty body) has been constructed.
   *   <li> <tt>S_FALSE</tt> A result cannot be constructed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT GetResult (CATPolyBody*& oResult);

private:

  CATPolyBodyNaryJoinImpl* _Operator;
};

#endif
