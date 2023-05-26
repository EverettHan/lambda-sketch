// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMProviderRestrictedAccessAdapter.h
// Define the CATPLMProviderRestrictedAccessAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMProviderRestrictedAccess
//
//===================================================================
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMProviderRestrictedAccessAdapter_H
#define CATPLMProviderRestrictedAccessAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

#include "CATIPLMCompProviderRestrictedAccess.h"// CATPLMServices ProtectedInterfaces
#include "CATIPLMProviderRestrictedAccess.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

#include "CATLISTV_CATPLMID.h"// CATPLMIdentificationAccess ProtectedInterfaces CATPLMIdentifier.m CATPLMIdentificationAccess.dll

#include "CATListOfCATBinary.h"// System ProtectedInterfaces
#include "CATPLMID.h"
#include "CATOmxOMap.h"
#include "CATDbdGlassBoxInfo.h"
#include "CATPLMOmxCollections.h"

class CATLISTV_CATPLMCEStamp;
/**
 * gives an adapter to the interface CATIPLMProviderRestrictedAccess
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMProviderRestrictedAccessAdapter : public CATIPLMProviderRestrictedAccess
{
public:
  CATPLMProviderRestrictedAccessAdapter();
  virtual ~CATPLMProviderRestrictedAccessAdapter();

  /**
  * @nodoc
  */
  virtual HRESULT GetPLMIDFromProviderIdentifiers(const CATListOfCATBinary &iBinInputs, CATPLMIDs &oPLMIdentifiers);

  /**
  * @nodoc
  */
  virtual HRESULT GetProviderIdentifiersFromPLMID(const CATPLMIDs &iPLMIdentifiers, CATListOfCATBinary &oBinInputs);

  /**
  * @nodoc
  */
  virtual HRESULT GetProviderVersionFamiliesFromPLMIDs(const CATPLMIDs & iPLMIdentifiers,
    CATListOfCATBinary &oBinInputs);

  /**
  * @nodoc
  */
  virtual HRESULT GetPLMIDsFromProviderVersionFamilies(const CATListOfCATBinary &iBinInputs,
    CATPLMIDs & oPLMIdentifiers);

  /**
  * @nodoc
  */
  virtual HRESULT GetProvidersIdentifiersFromFileIds(const CATListOfCATBinary &iBinPointing,
    const CATListOfCATBinary &iBinPointed,
    CATListOfCATBinary &oBinOutputs);

  /**
   * @nodoc
   */
  virtual HRESULT GetContextFromRepresentations(const CATPLMIDs & iRepresentations,
    CATPLMIDs & oContextObjects,
    CATPLMCEStamps &oContextObjectsCEStamp,
    CATListOfInt *&oTrees);

  /**
     * @nodoc
     */
  virtual HRESULT GetProviderVersionInfosFromPLMIDs(const CATPLMIDs & iPLMIdentifiers,
    CATListOfCATBinary &oBinOutputsMajorInfos,
    CATListOfCATBinary &oBinOutputsMinorInfos);
  /**
     * @nodoc
     */
  virtual HRESULT SetProviderVersionInfosToPLMIDs(const CATPLMIDs & iPLMIdentifiers,
    const CATListOfCATBinary &iBinInputsMajorInfos,
    const CATListOfCATBinary &iBinInputsMinorInfos);

  /**
   * @nodoc
   */
  virtual HRESULT GetExposedDataMigrator(CATPLMIDs &iRefAndRepPLMIDs,
    CATBaseUnknown* & oExposedDataMigrator);

  /**
    * @nodoc
    */
  virtual HRESULT CompleteScopeToTransferWithConfig(const CATPLMIDs& iListPLMIDs,
    CATPLMIDs& oListPLMIDsCompletedWithConfig,
    CATError*& oError);

  /**
    * @nodoc
    */
  virtual HRESULT GetListOfInternalNamesFromRepPLMIDs(CATOmxOMap<CATPLMID, CATDbdGlassBoxInfo> &ioMapInternalInfo);

  /**
  * Required after Batch server mode: Informs provider that next batch job is to be started..
  * Called to perform/check :
  *  - if various static cache of a Provider are cleaned
  *  - Required processing for setting of Environment Variables
  *
  * @param iBatchName [input]
  *   Name of the Batch (like CoexistenceV5V6).. Can be useful in some context
  * @return
  *   <code>S_OK</code>Success when session is ‘clean’ and fully ready for a new transaction, including the Successful processing for Env Vars
  *   <code>S_FALSE </code> if not implemented by the connector
  *   <code>E_FAIL</code>In case of trouble when preparing the session for a new transaction
  *
  */
  virtual HRESULT StartBatchSrvModeTransaction(CATString & iBatchName);


  /**
  * Required after Batch server mode: Informs provider that current batch job has ended..
  * Called to perform:
  *  - clean/re-initialize various static cache of a Provider
  *
  * @return
  *   <code>S_OK</code>Clean up data to close the transaction
  *   <code>S_FALSE </code> if not implemented by the connector
  *   <code>E_FAIL</code> In case of trouble when ending the transaction
  *
  */
  virtual HRESULT EndBatchSrvModeTransaction();

  virtual HRESULT GetListOfPLMIDFromFile(CATIPLMCompProviderRestrictedAccess::OrchestrationDefines  iFileType,
    const CATUnicodeString & iusiFilePath,
    CATListValCATPLMID     & oPLMIdentifiers,
    CATUnicodeString       & ousReportMessage);

  virtual HRESULT GetDrawingLinksInformation(CATPLMSequenceOfOctetToArrayOfBin& ioMapDrawingInfo);

private:
  CATPLMProviderRestrictedAccessAdapter(CATPLMProviderRestrictedAccessAdapter &);
  CATPLMProviderRestrictedAccessAdapter& operator=(CATPLMProviderRestrictedAccessAdapter&);
};

#endif
