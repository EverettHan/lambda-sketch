// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySmallCellRemoval.h
//
//===================================================================
// February 2019 Creation: NDO
//===================================================================
#ifndef CATPolyBodySmallCellRemoval_H
#define CATPolyBodySmallCellRemoval_H

#include "PolyBodyRegularize.h"
#include "CATErrorDef.h"

class CATPolyBody;
class CATTolerance;
class CATSoftwareConfiguration;
class CATPolyBodyUnaryObserver;


/**
 * Operator to remove the cells that are too small from a CATPolyBody operand.
 * This operator edits the CATPolyBody topology.
 * This is an in-place operator that edits a native CATPolyBody.
 */
class ExportedByPolyBodyRegularize CATPolyBodySmallCellRemoval
{

public:

  /**
   * Constructor of the operator to remove small cells from a CATPolyBody.
   */
  inline CATPolyBodySmallCellRemoval (const CATTolerance& iTolerance, const CATSoftwareConfiguration* iSoftConfig = 0);

  inline ~CATPolyBodySmallCellRemoval ();

public:

/** @name Main Methods
    @{ */

  /**
   * Runs the operator.
   * @param iPolyBody
   *   The input CATPolyBody to process.  
   *   It must be a native and fully editable CATPolyBody.
   *   The operator modifies in-place this CATPolyBody.
   * @param iTag
   *   The optional tag identifying the CATPolyBody operand which will be provided to the observer calls.
   * @param obs
   *   An optional observer to capture the events modifying the CATPolyBody.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the CATPolyBody is successfully processed and was modified.
   *   <li> <tt>S_FALSE</tt>  if the CATPolyBody is successfully processed and was not edited.
   * </ul>
   */
  HRESULT Run (CATPolyBody& iPolyBody, const int iTag = 0, CATPolyBodyUnaryObserver* obs = 0);

/** @} */

private:

  const CATTolerance& _Tolerance;
  const CATSoftwareConfiguration* _SoftConfig;

};

inline CATPolyBodySmallCellRemoval::CATPolyBodySmallCellRemoval (const CATTolerance& iTolerance, const CATSoftwareConfiguration* iSoftConfig) :
  _Tolerance (iTolerance),
  _SoftConfig (iSoftConfig)
{
}

inline CATPolyBodySmallCellRemoval::~CATPolyBodySmallCellRemoval ()
{
  _SoftConfig = 0;
}

#endif
