// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMReplicationTransaction.h
// Define the CATIPLMReplicationTransaction interface
//
//===================================================================

/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMReplicationTransaction_H
#define CATIPLMReplicationTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMReplicationTransaction;
#else
extern "C" const IID IID_CATIPLMReplicationTransaction ;
#endif

class CATPLMID;
class CATPLMTextInputStream;
class CATLISTV(CATPLMID);
class CATLISTV(CATPLMReplicationStreamInfo);

//------------------------------------------------------------------

/**
* Interface allowing replication import under the control of a transaction.
* <b>Role:</b>This interface should be used only by the replication engine.
* It should be implemented by any PLM provider that needs to support replication capabilities.
*
* Note: the transaction should be commited only after the PLM data AND the streams have been successuly imported.
*/
class ExportedByCATPLMServicesItf CATIPLMReplicationTransaction: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Sends PLM data to the server and returns the localization of streams to be imported.
  * @param ipPLMDataInputStream
  *   CATILockBytes2 input stream where the PLM data to be imported will be read. The input PLM Data should compliant with the replication proprietary format.
  * @param iListOptions
  *   list of additional (provider specific) options, with the (option1, value1, option2, value2...) format.
  * @param oStreamsToBeImported
  *   return list containing the streams to be imported and their target localization.
  * @param ioImportedEntityIDs
  *   optional list where the PLMIDs of the imported objects are appended.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>import is successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation.</dd>
  *   </dl>
  */
  virtual HRESULT ImportPLMData( CATPLMTextInputStream &iPLMDataInputStream, 
                                 const CATListOfCATUnicodeString& iListOptions,
                                 CATLISTV(CATPLMReplicationStreamInfo) &oStreamsToBeImported,
                                 CATLISTV(CATPLMID) *ioImportedEntityIDs = NULL) = 0;

  /**
  * Commit in the PDM all the import operations. If the operation fails a PDM rollback can be launched.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>commit is successfully.</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>nothing to commit.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. </dd>
  *   </dl>
  */
  virtual HRESULT Commit() = 0;
  
  /**
  * As soon as the import step has failed, you can rollback the PDM using this service..
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>rollback is successfully.</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>nothing to rollback.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation.</dd>
  *   </dl>
  */
  virtual HRESULT Rollback() = 0;
  
};

//------------------------------------------------------------------

#endif
