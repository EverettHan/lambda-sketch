// COPYRIGHT Dassault Systemes 2012
//==================================================================
#ifndef CATPLMRepositoryPrivilege_H
#define CATPLMRepositoryPrivilege_H

/**
* @level Private
* @usage U1
*/

#include "CATPLMIdentificationAccess.h"
#include "IUnknown.h"
#include "CATOmxAny.h"

class CATOmxKeyValueBlock;
class CATComponentId;

typedef enum
{
  Repository_undefined,
  Repository_full,
  Repository_noedit,
  Repository_partial
} Repository_Privilege;

class ExportedByCATPLMIdentificationAccess CATPLMRepositoryPrivilege
{
public:
  CATPLMRepositoryPrivilege();
  ~CATPLMRepositoryPrivilege();

  Repository_Privilege GetValue() const;

  int GetValueAsInt() const;
  
  CATBoolean IsValid() const;

  HRESULT AddRepositoryPrivilegeToBlock(CATOmxKeyValueBlock & ioAttrBlock);

private:
  friend class CATOxEntity;
  friend class CATOxiRepoPrivilege;
  friend class CATOxSessionDataSource;
  friend class CATPLMItgPrivateToolbox;

  signed char _Value;
  CATPLMRepositoryPrivilege(CATOmxAny & iValue);

  HRESULT GetRepositoryPrivilegeFromBlock(CATOmxKeyValueBlock & iAttrBlock);
  HRESULT SetValue(CATOmxAny & iValue);

};

#endif
