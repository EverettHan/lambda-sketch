// COPYRIGHT Dassault Systemes 2008-2012
//==================================================================
//
// CATPLMREPlugTransferOptions.h
// Optional parameters of the plug transfer edition token APIs
//
//===================================================================
//
// History:
// --------
//  July  2008  Author: JDC  Objective: Creation: 
//  March 2012  Author: JLM  Objective: Quick code review
//===================================================================

#ifndef _CATPLMREPlugTransferOptions_H
#define _CATPLMREPlugTransferOptions_H

/**
  * @level Protected
  * @usage U1
  */

#include "CATPLMIntegrationInterfaces.h"
#include "CATSysErrorDef.h"
#include "CATSysBoolean.h"

class CATPLMREBriefcaseReport ;

/**
  * Object holding optional parameters of the plug transfer edition token APIs.
  * <br><b>Role</b>: This object allows to define optional parameters for @href CATIPLMReplicationEnginePlugServices#RequestEditionTokenTransfer.
  *
  * @see CATIPLMReplicationEnginePlugServices
  */
class ExportedByCATPLMIntegrationInterfaces CATPLMREPlugTransferOptions
{
   public:
      CATPLMREPlugTransferOptions()  ;
      ~CATPLMREPlugTransferOptions() ;

    /**
      * Specify if edition token transfer on weakened entities is allowed.
      * <br><b>Role:</b>.if set to TRUE, allows token transfer on weakened entities. default is FALSE.
      */ 
      HRESULT AllowWeakenedEntities( CATBoolean iAllow ) ;

    /**
      * Set the briefcase report to store operation result and errors.
      * <br><b>Role:</b> used by the engine to contain the report.
      */
      HRESULT SetBriefcaseReport( CATPLMREBriefcaseReport * ipBriefcaseReport ) ;

      /**
      * Get the briefcase report to store operation result and errors.
      * <br><b>Role:</b> Get the report container.
      */
      HRESULT GetBriefcaseReport( CATPLMREBriefcaseReport *& opBriefcaseReport ) const ;

   private:

      friend class CATPLMRERequestTransferTask ;

      CATPLMREPlugTransferOptions& operator=(const CATPLMREPlugTransferOptions &); // not implemented
      CATPLMREPlugTransferOptions(const CATPLMREPlugTransferOptions &) ;           // not implemented

      CATBoolean                _bAllowWeakeanedEntities ;
      CATPLMREBriefcaseReport * _pBriefcaseReport        ;
} ;
#endif
