/* -*-c++-*- */
#ifndef CATIPLMSessionDataSource_H
#define CATIPLMSessionDataSource_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010

/**
 * @level Protected
 * @usage U4
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATPLMSessionDataSourceStatus.h"
#include "CATOmxSR.h"
#include "CATOmxList.h"
#include "CATOmxArray.h"

class CATString;
class CATPLMID;
class CATPLMSemanticRelation;
class CATPLMStreamDefinition;
class CATLISTV(CATPLMStreamDefinition);
class CATPLMTypeId;
class CATLISTV(CATPLMTypeId);
class CATOmxKeyValueBlock;
class CATPLMCEStamp;
class CATBinary;
class CATPLMCompletionLevel;
class CATIPLMRecordRead;
class CATPLMPath;
class CATOxSessionCoarseMemoryState;


/**
* Protocol for importing a component in session
*/
class ExportedByCATPLMTos CATIPLMSessionDataSource : public CATBaseUnknown
{
public:
  /**
  * Returns the status of the data source (The default mode is ACTIVATED).
  *
  * The protocol allows to transfer a component from a session to an other session
  * even if the component is no more reachable after undo or delete operation.
  * A specific transfer is possible for this DESTROYED or GARBAGED components
  * but it is necessary to explicitely declared this working mode with the data source status DESTROYED.
  *
  * @param oDataSourceStatus
  *        CATPLMSessionDataSourceStatus_Activated : Not a session data source or cell is ACTIVATED.
  *        CATPLMSessionDataSourceStatus_Destroyed : Is a session data source and celle is GARBAGED or DESTROYED.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetStatus(CATPLMSessionDataSourceStatus & oDataSourceStatus) = 0;

  /**
  * Returns the component Identifier.
  *
  * @param oPLMID
  *        the component PLM identifier.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetPLMID(CATPLMID & oPLMID) = 0;

  /**
  * Returns the component completion level.
  *
  * @param oCompletionLevel
  *        the component completion LEVEL.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetCompletionLevel(CATPLMCompletionLevel & oCompletionLevel) = 0;

  /**
  * Returns strong relations.
  *
  * @param iRelType
  *        the relation type.
  * @param oAssObjId
  *        the associated object identifier.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetAssociatedObject(const CATString & iRelType, CATPLMID & oAssObjId) = 0;

  /**
  * Returns semantic relations data.
  *
  * @param oSRList
  *        the list of semantical relations.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetSRList(CATOmxArray<CATPLMSemanticRelation>& oSRList) = 0;
  virtual HRESULT GetPathList(CATOmxList<CATPLMPath>& oPathList) = 0;

  /**
  * Returns streams data.
  *
  * @param oSDList
  *        the list of stream definitions.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetSDList(CATLISTV(CATPLMStreamDefinition) & oSDList) = 0;

  /**
  * Returns extension types.
  *
  * @param oLExtensionType
  *        the list of extensions.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT ListExtensionTypes(CATLISTV(CATPLMTypeId) & oLExtensionType) = 0;

  /**
  * Returns attributes' block.
  *
  * @param iExtensionType
  *        the extension type.
  * @param oAttrBlock
  *        the block.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetAttributeBlock(const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock) = 0;

  /**
  * Returns concurrent engineering stamp.
  *
  * @param oCEStamp
  *        the CEStamp.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetCEStamp(CATPLMCEStamp & oCEStamp) = 0;

  /**
  * Returns system attributes, like the repo privilege
  *
  * @param oAttrBlock
  *        the block of system attributes
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetSystemAttributesBlock(CATOmxKeyValueBlock & oAttrBlock) = 0;


  /**
  * Returns the memory state of the component if component is imported from an other session.
  *
  * @param oSessionMemoryState
  *        the binary containing the memory state of the component with log, history, caches.
  *
  * @return
  *    S_OK   : if request succeeded.
  *    E_FAIL : if request failed.
  */
  virtual HRESULT GetMemoryState(CATBinary & oSessionMemoryState) = 0;

  /**
  * Allows to define a coarse memory state for duplicate operations
  *
  * @return
  *     Has to be released after usage.
  */
  virtual CATOxSessionCoarseMemoryState* GetCoarseMemoryState() = 0;

  /**
  * Return the record if the data source was created from a record.
  *
  * @param oRecord: the record if any. Has to be release after usage.
  *
  * @return
  *     TRUE if it was based on a record
  *     FALSE otherwise
  */
  virtual CATBoolean IsBasedOnRecordRead(CATIPLMRecordRead *& oRecord) = 0;

  static const CLSID& __stdcall ClassId() = delete; //this is not an OM interface
  static CATMetaClass* __stdcall MetaObject() = delete;
};

typedef CATOmxSR<CATIPLMSessionDataSource> CATIPLMSessionDataSource_var;

#endif
