// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMReplicationEnginePrivateOptions.h
// Define the CATIPLMReplicationEnginePrivateOptions interface
//
//===================================================================
//
//  Dec 2008  Creation: JDC/PA
//===================================================================
#ifndef CATIPLMReplicationEnginePrivateOptions_H
#define CATIPLMReplicationEnginePrivateOptions_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMReplicationEnginePrivateOptions;
#else
extern "C" const IID IID_CATIPLMReplicationEnginePrivateOptions ;
#endif

#include "CATCollec.h"

class CATLISTV(CATPLMID);
class CATPLMRepositoryName;

//------------------------------------------------------------------

/**
* Interface exposing services ONLY DEDICATED TO A PRIVATE USE BY THE REPLICATION ENGINE TEAM FOR DEVLOPMENT & DEBUG REASONS
* ( MUST NEVER BE IMPLEMENTED NEITHER BY APPLICATIONS, NOR BY FINAL USERS.
*/

class ExportedByCATPLMIntegrationInterfaces CATIPLMReplicationEnginePrivateOptions: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
  * Private options of the replication engine
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>DataImportReportingInfra_ShowReferenced</tt><dd>Data import reporting infrastructure : Show "Referenced" PLM entities
  * Show "Referenced" applies at export extend (when acquiring applicative entity ids) & at import (when generating the data import results)
  * </dl>
  */
  enum CATPLMREPrivateOptionName 
  {
    DataImportReportingInfra_ShowReferenced=0,           
  };

/**
  * Set a boolean private option of the replication engine
  * <br><b>Role:</b>Set a boolean private option of the replication engine.
  *
  * @param iOptionName
  *   Name of the private option
  * @param iOptionValue
  *   if iOptionValue = Yes, the option is activated, else it’s not activated
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>Set a boolean private option of the replication engine succeeded.</dd>
  *   <dt>E_FAIL</dt><dd>Set a boolean private option of the replication engine failed.</dd>
  * <br>
  */ 
   virtual HRESULT SetOption ( CATPLMREPrivateOptionName iOptionName, CATBoolean iOptionValue ) = 0; 

/**
  * Get a boolean private option of the replication engine
  * <br><b>Role:</b>Set a boolean private option of the replication engine.
  *
  * @param iOptionName
  *   Name of the private option
  * @param iOptionValue
  *   if iOptionValue = Yes, the option is activated, else it’s not activated
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>Set a boolean private option of the replication engine succeeded.</dd>
  *   <dt>E_FAIL</dt><dd>Set a boolean private option of the replication engine failed.</dd>
  * <br>
  */ 
   virtual HRESULT GetOption ( CATPLMREPrivateOptionName iOptionName, CATBoolean &oOptionValue ) = 0;
};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMReplicationEnginePrivateOptions, CATBaseUnknown );

#endif
