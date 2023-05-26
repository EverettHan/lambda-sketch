/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMSetSaveInfo_H
#define CATPLMSetSaveInfo_H

#include "CATPLMIntegrationInterfaces.h"
#include "IUnknown.h"
#include "CATOmxOSet.h"

class CATOmxAny;
class CATOmxKeyString;
class CATUuid;
class CATPLMID;

class CATPLMSessionSaveInfos
{
public:
  /* Set an additional information on a PLM component.
   * this additional information will be used to enrich the number of credits used for a component.
   * this additional information is automatically removed when the modification of the PLM component is successfully propagated to the database
   * it is restored through LocalSave or offline local persistency mechanisms
   * it is undo - able
   *
   * @param iPlmid
   *   a CATPLMID identifier
   *   it must be dirty(either created, deleted or modified state)
   * @param iUUID
   * the UUID identifier of the protocol
   * @param iProtocol
   *   the name of the protocol, there must exist an object which type is the concatenation of "CATIPLMSaveInfos_" and iProtocol that implements CATIPLMSaveInfos
   * @param iInfo
   *   the information to add(use empty to remove it)
   *   it must be serializable(allowed types are bool / int / string or list / maps of those types)
   * @return :
   *   S_OK in case of success
   *   E_FAIL if an error is raised.
   */
  virtual HRESULT SetSessionSaveInfos(const CATPLMID & iPLMId, const IID & iUUID, const CATOmxKeyString& iProtocol, const CATOmxAny& iInfo) = 0;

  /**
  * Retrieve an information set with SetSessionSaveInfos
  */
  virtual CATOmxAny GetSessionSaveInfo(const CATPLMID& iPlmid, const CATOmxKeyString& iProtocol) = 0;

  /**
  * Retrieve an information set with SetSessionSaveInfos
  */
  virtual CATOmxOSet<CATOmxKeyString> GetSessionSaveInfo(const CATPLMID iPlmid, const IID & iIID) = 0;
};

class ExportedByCATPLMIntegrationInterfaces CATPLMSessionSaveInfosBridegAccess
{
public:
  static CATPLMSessionSaveInfos * GetPLMSessionSaveInfos();
};

#endif
