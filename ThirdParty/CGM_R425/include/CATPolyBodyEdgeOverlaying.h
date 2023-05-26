// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyEdgeOverlaying.h
//
//===================================================================
// June 2015 Creation: mee1
// November 2016: Revisited: ndo
//===================================================================
#ifndef CATPolyBodyEdgeOverlaying_H
#define CATPolyBodyEdgeOverlaying_H

#include "CATMathTransformation.h"
#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATPolyBoolean.h"
#include "CATPolyBodyOverlayOptions.h"
#include "CATPolyDeprecated.h"

#include <memory>

class CATPolyBody;
class CATPolyCell;
class CATPolyVertex;
class CATPolyEdge;
class CATPolyFace;
class CATMathTransformation;
class CATIPolyCurve;
class CATIPolyPoint;

class CATPolyBodyNaryObserver;
class CATPolyBodyOverlay;


/**
 Operator overlaying polyhedral edges onto a CATPolyBody. 
 Edges within the input tolerance are overlaid onto the CATPolyBody.
*/
class ExportedByPolyBodyBoolean CATPolyBodyEdgeOverlaying
{

public:

  /**
   * Constructor.
   * @param iOptions
   *   This operator will overlay the edges from an operand onto another operand
   *   that are closer than the distance tolerance.
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBodyEdgeOverlaying (const CATPolyBodyOverlayOptions* iOptions = 0);

  ~CATPolyBodyEdgeOverlaying ();

public:
  /**
   * @nodoc
   * operator to update the result by sliding the curve instead of launching a full recomputation
   * So far under dev.
   */
  class ExportedByPolyBodyBoolean Updater
  {
  public:
    ~Updater(){};

    HRESULT Run(const CATMathTransformation* ipPosition0,
                const CATMathTransformation* ipPosition1,
                CATPolyBodyNaryObserver * ipObserver,
                CATPolyBody *& oResult);

  private:
    Updater(std::shared_ptr<CATPolyBodyOverlay> ipOverlay);
    friend class CATPolyBodyEdgeOverlaying; 

    std::shared_ptr<CATPolyBodyOverlay> _pOverlay;
    CATMathTransformation _pos01;
    HRESULT _HR;
  };

public:

  /**
   * Computes the overlaying of the edges from Operand 1 onto Operand 0. 
   * Identifying tags must be different.
   * Can retrieve an updator for later update
   */
  HRESULT Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0, const int iTag0,
               const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1, const int iTag1,
               CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver = 0, std::unique_ptr<Updater> * oUpdater = 0);

  /**
   * Computes the overlaying of the edges from Operand 1 onto Operand 0.
   */
  inline HRESULT Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                      const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                      CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver = 0);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:

  /**
   * Obsolete.  
   * DO NOT USE.
   * @see CATPolyBodyNaryObserver
   */
  class ExportedByPolyBodyBoolean Observer
  {

  public:

    virtual ~Observer () {}

  public:

    // Obsolete calls.

    /**
     * DO NOT USE.
     * Use instead CATPolyBodyNaryObserver.
     */
    virtual void OverlayingCurve (CATIPolyCurve& iPolyCurve, CATPolyCell* iCellOperand0, CATPolyEdge* iEdgeOperand1) {}

    /**
     * DO NOT USE.
     * Use instead CATPolyBodyNaryObserver.
     */
    virtual void OverlayingPoint (CATIPolyPoint& iPolyPoint, CATPolyCell* iCellOperand0, CATPolyCell* iCellOperand1) {}

  };

  /**
   * Obsolete.  See other Run method.
   * Computes the overlaying of the edges from Operand 1 onto Operand 0. 
   */
  POLY_DEPRECATED ("Deprecated call: call Run () with a CATPolyBodyNaryObserver.",
                   HRESULT Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                                const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                                Observer* iObserver = 0););

#endif

private:

  std::shared_ptr<CATPolyBodyOverlayOptions> _Options;

};

inline HRESULT CATPolyBodyEdgeOverlaying::Run (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0,
                                               const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                                               CATPolyBody*& oResult, CATPolyBodyNaryObserver* iObserver)
{
  return Run (iOperand0, iPosition0, 0, iOperand1, iPosition1, 1, oResult, iObserver);
}

#endif
