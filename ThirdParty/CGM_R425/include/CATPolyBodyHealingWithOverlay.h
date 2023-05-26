//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyHealingWithOverlay.h
//
//===================================================================
// 18/05/18 Creation: F1Z
// DD/MM/YY
//===================================================================
#ifndef CATPolyBodyHealingWithOverlay_H
#define CATPolyBodyHealingWithOverlay_H

// PolyhedralMathematics
#include "Poly/Vector.h"

// PolyhedralObjects
#include "CATPolyBodyOperandIterator.h"

// Polyhedral Body Operators
#include "PolyBodyBoolean.h"
#include "CATPolyBodyHealingWithOverlayStatus.h"
#include "CATPolyBodyHealingWithOverlayOptions.h"
#include "CATPolyHoleFilling.h"

// Others
class CATMathTransformation;
class CATPolyBodyUnaryObserver;
class CATPolyBody;
class CATPolyBodyOverlayOptions;
class CATPolyBodyHealingWithOverlayImpl;
class CATProgressCallback;
class CATPolyBodyGeoCheckerObserver;
class CATPolyBodyOverlay;
class CATPolyBodyOperandIterator;
class CATPolyBodyNaryObserver;

namespace Poly
{
  namespace HWO
  {
    class Impl;
  };
};

/**
 * Try to heal a CATPolyBody with the overlay structure.
 * This operator first tries to heal meshes self intersection, joint them and then 
 * heal domains (self)intersection.
 * The result is returned in a new CATPolyBody instance.
 *
 * @see CATPolyBodyUnaryObserver
*/
class ExportedByPolyBodyBoolean CATPolyBodyHealingWithOverlay
{
public:
  // ---------------------------------------------------------------------------
  // Object Management
  // ---------------------------------------------------------------------------
  /**
   * Constructor of the splitter operator.
   * @param iOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyBodyHealingWithOverlay (const CATPolyBodyOverlayOptions * iOptions = 0);
  CATPolyBodyHealingWithOverlay (const CATPolyBodyHealingWithOverlayOptions * iOptions);
  ~CATPolyBodyHealingWithOverlay ();

  // ---------------------------------------------------------------------------
  // Set (before run)
  // ---------------------------------------------------------------------------

  // @deprecated
  // Set the options from the constructor
  void SetOptions (const CATPolyBodyOverlayOptions & iOptions);
  void SetOptions (const CATPolyBodyHealingWithOverlayOptions & iOptions);

  /**
   * Set/Unset a progress callback to have feedback on the 
   * operator progress
   */
  void SetProgressCallback(CATProgressCallback * iProgress);

  // ---------------------------------------------------------------------------
  // Set (during run, after call to StartRun and before the call to ContinueAndEndRun)
  // ---------------------------------------------------------------------------
  /**
   * Set the status directly from the operator (and not the options)
   */
  void SetPolyBodyStatus(int iPolyBodyStatus);

  // ---------------------------------------------------------------------------
  // Run
  // ---------------------------------------------------------------------------
  /**
   * Runs the operator.
   * This method must be called prior to calls to the GetResult () method.
   * Run is thread safe as long as iOperand isn't changed by another progress.
   */
  HRESULT Run (const CATPolyBody             & iOperand    ,
               const CATMathTransformation *   iPosition = 0,
               const int                       iTag      = 0);

  /**
   * Start the run (create the overlay)
   */
  HRESULT StartRun(const CATPolyBody             & iOperand     ,
                   const CATMathTransformation *   iPosition = 0,
                   const int                       iTag      = 0);

  enum ContactStatus
  {
    eMeshSelfIntersectionsSet = 0x001,
    eMeshesIntersectionsSet   = 0x002,
    eNonManifoldBarsSet       = 0x004
  };

  /**
   * ContinueAndEndRun (to call after StartRun)
   * Informe if some contacts were provided from outside
   */
  HRESULT ContinueAndEndRun(int iContactsStatus=0);

  // ---------------------------------------------------------------------------
  // Get
  // ---------------------------------------------------------------------------
  /**
   * Get the healed poly body (new poly body created).
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
  HRESULT GetResult(CATPolyBody             * & oResult       ,
                    CATPolyBodyNaryObserver *   ioObserver = 0);

  enum Status
  {
    eConformalIssue        = (int) Poly::HWO::Status::eConformalIssue     , // Issue during the overlay conformisation (leads to E_FAIL)
    eReorientationIssue    = (int) Poly::HWO::Status::eOrientationIssue   , // Issue during the orientation of the triangles (leads to E_FAIL)
    eFillHoleIncomplete    = (int) Poly::HWO::Status::eFillHoleIssue      , // Issue during the fill hole (doesn't lead to E_FAIL so far). Holes might remain in the result.
    eIsOpen                = (int) Poly::HWO::Status::eIsOpen             , // The return poly body is open
    eNonManifoldBars       = (int) Poly::HWO::Status::eNonManifoldBars    , // The result contains non manifold bars
    eMoreThanOneElements   = (int) Poly::HWO::Status::eMoreThanOneElements  // The results contains more than one connexe element
  };

  /**
   * Return the status on the last run.
   * @return
   *  The status of the last run
   */
  int GetStatus() const;

  /**
   * Call during a run only
   * Get the CATPolyBodyGeoCheckerObserver useful to add information to the overlay
   */
  CATPolyBodyGeoCheckerObserver * GetGeoObserver();

  /**
   * Call during a run only
   * Get the current overlay
   */
  CATPolyBodyOverlay * GetOverlay();

private:
  // ---------------------------------------------------------------------------
  // Attributs (private)
  // ---------------------------------------------------------------------------
  Poly::HWO::Impl * _Operator;

  void AllocatedOperator(const CATPolyBodyHealingWithOverlayOptions * iOptions=0);

public:
  // ------------- under dev. Do not use  -------------- //
  /**
  * Runs the operator.
  * This method must be called prior to calls to the GetResult () method.
  * Run is thread safe as long as the operators aren't changed by another progress.
  */
  HRESULT Run(const Poly::Vector<CATPolyBodyOperandInfo> & iOperands);
  /**
  * Start the run (create the overlay)
  */
  HRESULT StartRun(const Poly::Vector<CATPolyBodyOperandInfo> & iOperands);
};

#endif
