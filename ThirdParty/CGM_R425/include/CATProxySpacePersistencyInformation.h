#ifndef __CATProxySpacePersistencyInformation_H
#define __CATProxySpacePersistencyInformation_H

/**
 * @level Private
 * @usage U1       
 */

#include "ExportedByCATPLMTos.h"
#include "IUnknown.h"
#include <stdlib.h>
#include "CATLISTV_CATPLMID.h"
#include "CATIPLMSessionDataSource.h"
#include "CATOmxSR.h"

class CATOxSpaceStreamingInformation;
class CATOxMemTOS;
class CATIPLMRecordRead;
class CATProxySpacePersistency;

class ExportedByCATPLMTos CATProxySpacePersistencyInformation
{
public:

  /**
  * Empty constructor
  */
  CATProxySpacePersistencyInformation();

  /**
  * Destructor
  */
  ~CATProxySpacePersistencyInformation();

  /**
  * List activated components
  *
  * @param oLPLMID_Activated
  *        The identifiers of activated components.
  * @return
  *
  */
  HRESULT ListActivatedComponents (CATLISTV(CATPLMID) & oLPLMID_Activated) const;


    /**
  * List created components
  *
  * @param oLPLMID_Created
  *        The identifiers of createdd components.
  *
  * @return
  *      S_OK if request succeeded.
  *      E_FAIL if request failed.
  */
  HRESULT ListCreatedComponents (CATLISTV(CATPLMID) & oLPLMID_Created) const;

  /**
  * List destroyed components
  *
  * @param oLPLMID_Destroyed
  *        The identifiers of destroyed components.
  */
  HRESULT ListDestroyedComponents (CATLISTV(CATPLMID) & oLPLMID_Destroyed) const;

  /**
  * Bind data source for activated components.
  * The data source is filled with data and memory state.
  *
  * @param iRecord
  *        The record defining the data associated to the component to be restored.
  * @param oDataSource
  *        The data source of activated component.
  *
  * @return
  *      S_OK if request succeeded.
  *      E_ACCESSDENIED : memory state not found.
  *      E_FAIL if request failed.
  */
  HRESULT BindAndCompleteDataSourceForActivatedComponent (CATIPLMRecordRead * iRootRecord, CATIPLMSessionDataSource_var & oDataSource) const;

 /**
  * Bind data source for destroyed components.
  * The data source is filled with memory state.
  *
  * @param iPLMID
  *        The identifier of the destroyed compnoent to be restored.
  * @param oDataSource
  *        The data source of destroyed component.
  *
  * @return
  *      S_OK if request succeeded.
  *      E_ACCESSDENIED : memory state not found.
  *      E_FAIL if request failed.
  */
  HRESULT BindAndCompleteDataSourceForDestroyedComponent (const CATPLMID & iPLMID, CATIPLMSessionDataSource_var & oDataSource) const;

private:

  friend class CATProxySpaceImageAssistant;


  // The letter of the object
  CATOmxSR<CATOxMemTOS> _MemTOS;
};

#endif
