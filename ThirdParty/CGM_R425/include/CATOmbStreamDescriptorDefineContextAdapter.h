#ifndef CATOmbStreamDescriptorDefineContextAdapter_H
#define CATOmbStreamDescriptorDefineContextAdapter_H

/**
* COPYRIGHT DASSAULT SYSTEMES 2009
* @level Protected
* @usage U2
*/

#include "CATIOmbStreamDescriptorDefineContext.h"
#include "CATListPtrCATOmbStreamDescriptorDefinitionKey.h"
#include "CATOmbStreamDescriptorDefinitionKey.h"
#include "CATOmbSDOvertypeQualifiers.h"

/**
* Base class for adaptable implementation of CATIOmbStreamDescriptorDefineContext interface.
* @see CATIOmbStreamDescriptorDefineContext
*/

class ExportedByCATOmbSelectiveLoading CATOmbStreamDescriptorDefineContextAdapter: public CATIOmbStreamDescriptorDefineContext
{
  CATDeclareKindOf;

public:

  /**
  * CTOR/DTOR
  */
  CATOmbStreamDescriptorDefineContextAdapter();
  virtual ~CATOmbStreamDescriptorDefineContextAdapter();

  /**
  * Defines a set of StreamDescriptors as synchronous with an Authoring one, depending on an applicative context.
  */
  virtual HRESULT DefineAsSynchronous(CATListPtrCATOmbStreamDescriptorDefinitionKey & oListOfStreamDescDefKeys, CATOmbStreamDescriptorDefinitionKey* & opSyncWithStreamDescDefKey);

  /**
  * Settings can determine which sds will be loaded to achieve a given SelectiveLoading_Mode.
  */
  virtual HRESULT SetSDsToBeLoadedForGivenMode(CATListPtrCATOmbStreamDescriptorDefinitionKey& iListOfStreamDescDefKeys, CATUnicodeString& iSelectiveLoading_Mode);

  virtual HRESULT ProvideSynchronousSDs(const CATOmbStreamDescriptorDefinitionKey& iAuthoringSDefKey, CATOmbImportExportParameters& iParameters, CATOmxArray<CATOmbStreamDescriptorDefinitionKey>& oSyncSDefKeys);

  virtual HRESULT IsExternalSynchroDeclared(const CATOmbStreamDescriptorDefinitionKey& iAuthoringSDefKey, CATOmbImportExportParameters*& ioParameters, CATBoolean& oSynchro);

  virtual HRESULT IsAlternativeSynchroDeclared(const CATOmbStreamDescriptorDefinitionKey& iAuthoringSDefKey, CATOmbImportExportParameters*& ioParameters, CATBoolean& oSynchro);

  virtual HRESULT ProvideAlternativeSynchronousSDs(const CATOmbStreamDescriptorDefinitionKey& iAuthoringSDefKey, CATOmbImportExportParameters*& ioParameters, CATOmxArray<CATOmbSDOvertypeQualifiers>& oOvertypeKeys);

private:

  CATOmbStreamDescriptorDefineContextAdapter(const CATOmbStreamDescriptorDefineContextAdapter& iData); 
  CATOmbStreamDescriptorDefineContextAdapter& operator = (const CATOmbStreamDescriptorDefineContextAdapter& iData);   

};
#endif
