#ifndef CATGMPolyCheckUp_H
#define CATGMPolyCheckUp_H

// COPYRIGHT DASSAULT SYSTEMES  2017
//=============================================================================
//
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// February 2017   Dominique PREVOST (DPS)    Creation 
//=============================================================================

#include "CATIAV5Level.h"

#include "GMPolyTopTools.h"   // ExportedBy
#include "CATErrorDef.h"        
#include "CATBoolean.h"        
#include "CATSysBoolean.h"        
#include "CATCollec.h"

class CATTopology;
class CATSoftwareConfiguration;
class CATListPtrCATGMPolyAnomaly;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyTopTools CATGMPolyCheckUp
{

public:

  // Encapsulation of CATICGMObject::Completed() in order to manage errors.
  // Service checking a topology (most likely PH, see below) and returning S_FALSE in case of diagnosis (no throw by default).
  // * The iFreezeMode option allows the service to freeze the topology.
  // * The iThrowLevel option provides different levels of alert, from none to always.
  enum ThrowLevel
  {
    NoThrow  = 0,
    Official = 1, // Throw is conditioned by _DoThrow in the same way it is in CATGMPolyTopology::Completed
    Always   = 2
  };

  // Return values :
  // - E_FAIL  : severe error, nothing could be done
  // - S_FALSE : errors found
  // - S_OK    : no errors found
  
  // Light version, no poly anomalies lists
  static HRESULT CheckTopo(CATTopology * iTopoToCheck, CATBoolean iFreezeMode, CATSoftwareConfiguration * iConfig, CATGMPolyCheckUp::ThrowLevel iThrowLevel = CATGMPolyCheckUp::NoThrow);

  // Full version, anomalies lists will contain errors and warnings.
  // *** Caller must release the anomalies using CATGMPolyAnomaly::ReleaseList *** //
  static HRESULT CheckTopo(CATTopology * iTopoToCheck, CATBoolean iFreezeMode, CATSoftwareConfiguration * iConfig, CATLISTP(CATGMPolyAnomaly) & oErrors, CATLISTP(CATGMPolyAnomaly) & oWarnings, CATGMPolyCheckUp::ThrowLevel iThrowLevel = CATGMPolyCheckUp::NoThrow);

  // Completed is conditioned by CATGMPolyCheckReport::_DoThrow to throw exceptions.
  // Completed is not equivalent to CheckTopo + some unconditional throw.
  // 
  // Ideally, CheckTopo should have 3 throw levels : 0 none
  //                                                 1 conditioned by _DoThrow
  //                                                 2 always
  // with a default value at 0, since it was the initial purpose of CheckTopo.
  //
  // In addition to this, ChecKTopo may call Completed on input topo if not PH.
  // If the intent is to check a freshly produced topology, it was automatically done
  // with completed before, no matter the nature of the input.
  //
  // There are some instances where we produce CX topo (vertices, lines, planes).
  // If it is done by operators, Completed happens at GetResult.
  // If it is done elsewhere, Completed used to do it, CheckTopo should still do it.

private:

  static void ThrowInternalError();

};

#endif


