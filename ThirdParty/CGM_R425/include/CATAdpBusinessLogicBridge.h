/**
* @level Protected
* @usage U1
*/
#ifndef CATAdpBusinessLogicBridge_h
#define CATAdpBusinessLogicBridge_h

#include "CATPLMIntegrationInterfaces.h"
#include "IUnknown.h"
#include "CATBaseUnknown.h"

class CATICkeParm;
class CATListValCATICkeParm_var;
class CATIInstance_var;
class CATIInstance;
class CATUnicodeString;
class CATListValCATIInstance_var;
class CATIType_var;
class CATUnicodeString;
class CATOmxKeyValueBlock;

class CATAdpBusinessLogicBridge
{
public:
  virtual HRESULT InitialiazeProxyForCloning(
    const CATIInstance_var & iComponentToClone,
    CATIInstance_var & oProxyOnClonedComponent,
    const CATUnicodeString & iIdCloningString) = 0;

  virtual HRESULT ApplyFinalizeOfflineNewBLs(
    CATIInstance_var & iComponentToFinalize,
    const CATIInstance_var & iComponentOwner,
    const CATIInstance_var & iComponentInstOf) = 0;

  virtual HRESULT AddUFOInitializationParameters(
    const CATUnicodeString & iOperationName,
    CATIInstance_var & iAggregatingReferenceBefore,
    CATIInstance_var & iInstantiatedReferenceBefore,
    CATListValCATIInstance_var & iOccurrenceBeforeList,
    CATIInstance_var & iInstanceBefore,
    CATListValCATICkeParm_var & oAttributesForContext) = 0;

  virtual HRESULT FinalizeAndRunUFOBL(CATIInstance_var & iCreatedComponent,
    CATIInstance_var & iAggregatingReferenceAfter,
    CATIInstance_var & iInstantiatedReferenceAfter,
    CATListValCATIInstance_var & iOccurrenceAfterList,
    CATListValCATICkeParm_var & iAttributesForContext) = 0;

  virtual HRESULT CreateVolatileInstanceFromType(const CATIType_var & ispType, CATIInstance_var & ospInstance) = 0;

  virtual HRESULT ApplyClientSaveActionBL(CATUnicodeString OperationType, CATIInstance_var & iComponentToSaveProxy,
    CATIInstance_var & iReferenceProxy,
    CATIInstance_var & iAggregatingReferenceProxy) = 0;

  virtual CATIInstance_var CallPLMIdentificationInitializationForReplace(CATBaseUnknown&, CATBaseUnknown&, CATBaseUnknown&, const CATOmxKeyValueBlock&) = 0;

  virtual HRESULT TransferModifiedAttributesFromProxyToObject(CATIInstance& source, CATBaseUnknown& destinationComponent) = 0;
};

class ExportedByCATPLMIntegrationInterfaces CATAdpBusinessLogicBridgeAccess
{
public:
  static CATAdpBusinessLogicBridge * GetAdpBusinessLogicBridge();
};
#endif
