#ifndef CATITosPLMServices_H
#define CATITosPLMServices_H

/**
* @level Private
* @usage U3
*/

// System
#include "CATBaseUnknown.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxList.h"
// CATPLMIdentificationAccess
#include "CATLISTV_CATPLMID.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATPLMIDCollections.h"
#include "CATPLMIdentificationAccess.h"

extern ExportedByCATPLMIdentificationAccess const IID IID_CATITosPLMServices;

class CATIAdpType;
class CATPLMRepositoryName;
class CATListValCATPLMCEStamp;
class CATIPLMRecordRead;
class CATIPLMIntegRecordRead;
class CATString;
class CATOmxKeyValueBlock;
class CATPLMCEStamp;
class CATPLMTypeId;
class CATPLMSemanticRelation;
class CATPLMStreamDefinition;
class CATListValCATPLMStreamDefinition;
class CATPLMPath;


/**
* Bridge from CATPLMIdentifiation to CATPLMServices
* <br><b>Role</b>Provides access to services implemented in PLMServices framework
* This API has only to be used by CATPLMIdentification framework.
*/
class ExportedByCATPLMIdentificationAccess CATITosPLMServices : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
  * Query on CEStamp
  *
  * @param iListPLMID
  * @param oListPLMID
  * @param oListCEStamp
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT QueryCEStamp(const  CATListValCATPLMID & iListPLMID, CATListValCATPLMID& oListPLMID, CATListValCATPLMCEStamp   & oListCEStamp) = 0;


  /**
  * Query on CEStamp and on Lock status and Lock user infos
  *
  * @param iListPLMID
  * @param oListRemoteStatus
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT QueryCEStampAndLockInfos(const  CATListValCATPLMID & iListPLMID, CATPLMIDToRemoteRefreshStatusMap & oListRemoteStatus) = 0;

  virtual HRESULT GetPLMID(CATIPLMRecordRead& iRecordRead, CATPLMID & oPLMID) = 0;

  virtual HRESULT GetAssociatedObject(CATIPLMRecordRead& iRecordRead, const CATString& iRelType, CATPLMID & oAssObjId) = 0;

  virtual HRESULT GetSRList(CATIPLMRecordRead& iRecordRead, CATOmxArray<CATPLMSemanticRelation>& oSRList) = 0;

  virtual HRESULT GetSDList(CATIPLMRecordRead& iRecordRead, CATListValCATPLMStreamDefinition& oSDList) = 0;

  virtual HRESULT GetPathList(CATIPLMRecordRead& iRecordRead, CATOmxList<CATPLMPath> & oPathList) = 0;

  virtual HRESULT ListExtensionTypes(CATIPLMRecordRead& iRecordRead, CATListValCATPLMTypeId& oLExtensionType) = 0;

  virtual HRESULT GetAttributeBlock(CATIPLMRecordRead& iRecordRead, const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock) = 0;

  virtual HRESULT GetCEStamp(CATIPLMRecordRead& iRecordRead, CATPLMCEStamp & oCEStamp) = 0;

  virtual HRESULT GetRepoPrivilege(CATIPLMRecordRead& iRecordRead, int & oRepo) = 0;

  virtual CATPLMTypeH GetSuperType(const CATPLMTypeH& iType) = 0;

  static CATITosPLMServices& Get();
};


#endif
