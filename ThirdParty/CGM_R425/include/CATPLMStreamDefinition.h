#ifndef CATPLMStreamDefinition_H 
#define CATPLMStreamDefinition_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATVVSUrl.h"
#include "CATVVSURLConnection.h"
#include "CATUnicodeString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxKeyString.h"
#include "CATOmxAny.h"
#include "CATPLMSDProperties.h"
#include "CATOmxAutoPtr.h"

class CATUnicodeString;
class CATVVSUrl;
class CATOmbStreamDescriptorsMediator;
class CATVVSURLConnection;

class CATPLMStreamDefinition;

// ACTIVATION DU MONOCODAGE SPEC DANS : CATPLMExternalsStreamDescriptor::StreamInCache 
#define IS_NEW_STREAMINCACHE_IMPLEMENTATION_ACTIVATED_BY_OMB
// ACTIVATION DU MONOCODAGE SPEC DANS : CATPLMExternalsStreamDescriptor::StreamInCache 

template<> ExportedByCATPLMTos CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMStreamDefinition>::manager();
/**
* Stream definition.
*/
class ExportedByCATPLMTos CATPLMStreamDefinition : public CATPLMSDProperties
{
public:
  CATPLMStreamDefinition();
  CATPLMStreamDefinition(const CATOmxKeyValueBlock& iBlock);
  CATPLMStreamDefinition(int iFormat, const CATUnicodeString & iRole, const CATUnicodeString & iTypeLate, const CATUnicodeString & iPersistencyType, const CATUnicodeString & iPersistencyName, int iSynchroStamp);

  virtual ~CATPLMStreamDefinition();

  HRESULT GetPrimaryDefinition(int & oFormat, CATUnicodeString & oRole, CATUnicodeString & oPersistencyName) const;
  HRESULT GetPrimaryDefinition(CATOmxKeyString& oFormat, CATUnicodeString & oRole, CATUnicodeString & oPersistencyName) const;
  HRESULT GetSecondaryDefinition(CATUnicodeString & oPersistencyType, CATUnicodeString & oLateType, int & oSynchroStamp) const;

  HRESULT SetStreamAccess(const CATVVSUrl & iUrl, int iWatermarkStamp);
  HRESULT SetStreamAccess(const CATVVSUrl & iUrl);
  HRESULT GetStreamAccess(CATVVSUrl & oUrl, int & oWatermarkStamp) const;

  HRESULT SetStreamPhysicalAccess(CATVVSURLConnection * iUrlConnexion); // Keep stream lifecyle.

  CATBoolean IsEmpty() const; //Shortcut for GetBlock().IsEmpty() ie. we consider this empty if and only if the block is empty !

  CATPLMStreamDefinition(const CATPLMStreamDefinition &iCopy);
  CATPLMStreamDefinition& operator=(const CATPLMStreamDefinition &iCopy);
  HRESULT GetAuthoringMarkStampAsMD5(CATUnicodeString & oAuhoringWatermarkStamp);
  CATLONG64 GetSize(); //-1 if unknown

private:
  CATBoolean operator!() const;
  int operator==(const CATPLMStreamDefinition & iOther) const;
  int operator!=(const CATPLMStreamDefinition & iOther) const;

  friend class CATOmbStreamDescriptorsMediator;

  // temporaire migration VCS
  HRESULT HasAuthoringMarkStamp(int & oAuhoringWatermarkStamp);

  CATOmxAutoPtr<CATVVSURLConnection> _URLConnexion; // Uniquement pour la gestion du cycle de vie du stream. On le lie à celui du sdef.
};

#endif
