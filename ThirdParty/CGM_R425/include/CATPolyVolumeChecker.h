//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATPolyVolumeChecker
//
// Check topological consistency of a CATPolyVolume in a CATPolyBody
//
//=============================================================================
// 2022-10-22 JXO: New.
//=============================================================================
#pragma once

#include "PolyBodyTools.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATPolyBody;
class CATPolyVolume;
class CATPolyEdge;
class CATPolyVertex;
class CATPolyVolumeCheckerObserver;


/**
This class performs several consistency checks of a CATPolyVolume of a CATPolyBody.
*/
class ExportedByPolyBodyTools CATPolyVolumeChecker
{

public:

  inline CATPolyVolumeChecker ();
  ~CATPolyVolumeChecker ();

public:

/** @name Main Method
    @{ */

  /**
   * Performs all the various checks on a CATPolyVolume.
   * @return
   *   <ul>
   *     <li> <tt>S_OK</tt> The CATPolyVolume passes this test.
   *          The CATPolyVolume is valid.
   *     <li> <tt>S_FALSE</tt> The CATPolyVolume fails this test. 
   *          Errors are logged onto the diagnosis.  (Invalid CATPolyBody.)
   *     <li> <tt>E_FAIL</tt> A serious error occured during the check of the CATPolyVolume 
   *          or the check could not be completed.
   *   </ul>
   */
  static HRESULT Check (CATPolyVolume & iVolume, CATPolyBody& iBody);

/** @} */

};

