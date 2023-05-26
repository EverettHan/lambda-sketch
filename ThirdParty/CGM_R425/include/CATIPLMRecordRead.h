// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATIPLMRecordRead.h
// Define the CATIPLMRecordRead interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  Nov 2003  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMRecordRead_H
#define CATIPLMRecordRead_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMStrongRelationshipId.h"
#include "CATPLMOmxCollections.h"

#include "CATPLMIdentificationAccessMacros.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMRecordRead;
#else
extern "C" const IID IID_CATIPLMRecordRead;
#endif

class CATPLMID;
//class CATIPLMObjectDesc;
class CATVVSUrl;
class CATString;
//class CATIPLMObjectAttr;
class CATPLMTypeId;
class CATIPLMAttrRead;
class _SEQUENCE_octet;
class CATUnicodeString;
class CATPLMSemanticRelationData;
class CATListValCATString;
class CATIPLMError;
class CATPLMStreamDescriptor;
class CATListPtrCATPLMStreamDescriptor;
class CATIPLMRecordReadExtraInfo;
class CATPLMPathDataH;

//
#include "CATCollec.h"
class CATPLMSemanticRelation;
class CATLISTP(CATPLMSemanticRelation);
class CATPLMType;
class CATLISTP(CATPLMType);
class CATLISTV(CATPLMTypeId);
class CATPLMCEStamp;
class CATOmxKeyValueBlock;
template<class T> class CATOmxList;
//

/**
 * data in those records through a set of Get methods
 * CATIPLMRecord allow access to the various information of a record of the CATIPLMRecordReadSet.
 * It provides access to data through a set of Get methods
 */
class ExportedByCATPLMServicesItf CATIPLMRecordRead : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Return the name of the section containing the record.
  * (The RecordSet may be divided into section, a section containing several Records.)
  *
  * @param  oSectionName
  *         Name of the associated section
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT GetSectionName(CATUnicodeString ** oSectionName) = 0;

  /**
   * Return component Id for the current object
   *
   * @param  oId
   *         Component identifier
   * @return
   *         Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>operation is successfully.</dd>
   *     <dt>E_FAIL </dt>
   *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
   *   </dl>
   */
  virtual HRESULT GetPLMID(CATPLMID & oId) = 0;

  /**
  * @deprecated V6R2014x
  * Use GetAttrAccess with CATPLMType
  */
  virtual HRESULT GetAttributeAccess(const CATString * iPLMExtension,
    CATIPLMAttrRead ** oAttrAccess) = 0;

  /**
  * @deprecated V6R2014x
  * Use GetAttrAccess with CATPLMType
  */
  virtual HRESULT GetAttributeAccess(CATIPLMAttrRead ** oAttrAccess,
    const CATPLMTypeId * iPLMExtension = NULL) = 0;

  /**
  * Get Attribute Access. This method computes a CATIPLMObjectAttr interface for the current object.
  * The return interface will be used by the system to read attributes.
  *
  * @param  oAttrAccess [out, CATBaseUnknown#Release]
  *         interface managing attributes
  * @param  iPLMExtension
  *         Name of the PLM Extension of the object (optional)
  *         if NULL (Default) -> Attributes belong to the Base Type
  *         if Valuated -> Attributes belong to the corresponding iPLMExtension
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT GetAttrAccess1(CATIPLMAttrRead ** oAttrAccess,
    const CATPLMTypeId& iPLMExtension = CATPLMTypeId_Null) = 0;

  /**
  * Get Attribute Access. This method computes a CATIPLMObjectAttr interface for the current object.
  * The return interface will be used by the system to read attributes.
  *
  * @param  oAttrAccess [out, CATBaseUnknown#Release]
  *         interface managing attributes
  * @param  iPLMExtension
  *         Name of the PLM Extension of the object (optional)
  *         if NULL (Default) -> Attributes belong to the Base Type
  *         if Valued -> Attributes belong to the corresponding iPLMExtension
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *     <dt>E_INVALIDARG </dt><dd>if ipPLMExtension!=NULL, ipPLMExtension is not an extension</dd>
  *   </dl>
  */
  virtual HRESULT GetAttrAccess2(CATIPLMAttrRead ** oAttrAccess,
    CATPLMType* ipPLMExtension = NULL) = 0;

  /**
  * Get Stream Access. This method computes a CATVVSUrl access for the current object.
  * CATVVSUrl will be used to read the stream.
  * Several streams can be associated to a single object. The iFormat and iRole parameters identify the stream.
  * (sample: a Representation can have an Authoring associated Stream and a NavRep one)
  *
  * @param  iStreamDesc
  *         The CATPLMStreamDescriptor of the Stream.(Format, Role, TypeLate, MarkStamp...)
  * @param  oVVSUrl
  *         the Virtual Vault URL (the  stream.)
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT GetStreamAccess(CATPLMStreamDescriptor * iStreamDesc, CATVVSUrl **oVVSUrl) = 0;

  /**
  * Returns the list of available Stream Identifiers .
  * @param  oStreamDescList
  *     The list of available CATPLMStreamDescriptor.(Format, Role, TypeLate, MarkStamp...) written or rewritten during the save (progagate)<BR>
  *     Elements inside the list must be Released after use.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>no stream has been written or rewritten during the save operation</dd>
  *   </dl>
  */
  virtual HRESULT ListStreamDescriptors(CATListPtrCATPLMStreamDescriptor * oStreamDescList) = 0;

  /**
  * @deprecated
  * Please use HRESULT GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId,CATPLMID & oAssObjId)
  */
  virtual HRESULT GetAssociatedObject(const CATString * iRelType, CATPLMID & oAssObjId) = 0;

  /**
  * Get Associated object of the current object
  *
  * @param  iRelType
  *         Relation type
  * @param  oAssObjId
  *         Associated object ID
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMID & oAssObjId) = 0;

  /**
  * Returns the number of SemanticRelation in the record.
  * @param oCount
  *    number of SemanticRelation.
  */
  virtual HRESULT SemanticRelationCount(int * oCount) = 0;

  virtual HRESULT PathDataHCount(int& oCount) = 0;

  /**
  * Returns the semantic Relation at the given index
  *
  * @param  iIndex
  *    The index (It starts at 1)
  * @param  iTargetId
  *    Id of the targeted object
  * @param  oSemanticData [out]
  *    the CATPLMSemanticRelationData object (No delete must be made on it)
  * @return
  *    Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT GetSemanticRelation(int iIndex, CATPLMID & oTargetId, CATPLMSemanticRelationData ** oSemanticData) = 0;

  virtual HRESULT GetPathDataH(int iIndex, CATPLMPathDataH& oPathData) = 0;

  /**
   * Returns the all the Semantic Relations in a list
   *
   * @param  oSRList
   *    the list of CATPLMSemanticRelation objects
   *    Please, do CATLISTP_APPLY_DELETE(oSRList). Indeed, internal srList is copied and returned.
   * @return
   *    Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>operation is successfully.</dd>
   *     <dt>E_FAIL </dt>
   *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
   *   </dl>
   */
  virtual HRESULT GetSRList(CATLISTP(CATPLMSemanticRelation)& oSRList) = 0;

  /**
  * @deprecated V6R2014x
  * Use GetAttributeAccess with CATPLMType
  *     format <name of modeler>::<typename> OLD TYPING, format <typename> NEW TYPING
  */
  virtual HRESULT ListExtensionTypes(CATListValCATString ** oExtensionList) = 0;

  /**
  * Returns the list of available Extensions .
  * @param  oExtensionList [out]
  *     The ExtensionType list
  *
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *     <dt>E_INVALIDARG </dt><dd>oExtensionList is not an empty list</dd>
  *   </dl>
  */
  virtual HRESULT ListExtensionTypes(CATLISTV(CATPLMTypeId)& oExtensionList) = 0;

  /**
  * Returns the list of available Extensions .
  * @param  oExtensionList [out, CATBaseUnknown#Release] (CATLISTP_APPLY_RELEASE on oExtensionList)
  *     The ExtensionType list
  *
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *     <dt>E_INVALIDARG </dt><dd>oExtensionList is not an empty list</dd>
  *   </dl>
  */
  virtual HRESULT ListExtensionTypes(CATPLMTypeList & oExtensionList) = 0;

  /**
  * @nodoc
  * @deprecated use @href CATIPLMRecordRead::ListExtensionTypes with a CATOmxList
  */
  virtual HRESULT ListExtensionTypes(CATLISTP(CATPLMType)& oExtensionList) = 0;

  /**
  * @deprecated
  * Please use CATIPLMError GetReport()
  * @param  oError [out, CATBaseUnknown#Release]
  */
  virtual HRESULT GetReport(CATIPLMError ** oError) = 0;

  /**
  *	Enum of the lock status.
  */
  enum PLMLockStatus
  {
    /** The element is locked */
    PLMLocked = 1
    /** The element is unlocked */
    , PLMUnlocked = 2
  };

  /**
  *	Checks the lock attribute on the record.
  *	@param  oLockStatus [out]
  *			The lock status of the object in the record.
  * @return
  *     Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The lock attribute was found on the record and the value is valid.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>Either the lock attribute is not found, or the value of the attribute is incorrect.</dd>
  *   </dl>
  *
  */
  virtual HRESULT GetLockStatus(PLMLockStatus &oLockStatus) = 0;

  /**
  * Retrieve computed attribute(s).
  *
  * <br><b>Role</b>: Retrieve computed attribute(s).
  *                  Attribute doesn't belong to the dictionary.
  *                  CATPLMType::ListAttributes doesn't return this attribute.
  * @param &opAttrAccess
  *  Interface implemented to retrieve computed attribute(s).
  * @param &iPLMExtension
  *  Computed attribute retrieved on extension or base type.
  * @return
  *
  *   <dl>
  *     <dt>S_OK</dt><dd>Computed attribute was found</dd>
  *     <dt>E_FAIL</dt><dd>Computed attribute was not found</dd>
  *   </dl>
  */
  virtual HRESULT GetExtraInfo1(CATIPLMRecordReadExtraInfo ** opAttrAccess, const CATPLMTypeId& iPLMExtension = CATPLMTypeId_Null) = 0;

  virtual HRESULT GetExtraInfo2(CATIPLMRecordReadExtraInfo ** opAttrAccess, CATPLMType* ipPLMExtension = NULL) = 0;

  /**
   * Moved from CATIPLMSystemAttrRead
   */

   /**
    * Returns the CATPLMCEStamp on the Object.
    */
  virtual HRESULT GetCEStamp(CATPLMCEStamp & oStamp) const = 0;

  /**
   * Moved from CATIPLMAttributeBlockAccess
   */

   /**
    * Returns the block of attribute.
    * @param oAttrBlock [out]
    *   The block of attributes.
    * @param iPLMExtension [in]
    *   The extension on which the block should be accessed. If NULL, the block is the main attribute block.
    *   The list of extension can be found in CATIPLMRecordRead.ListExtensionTypes
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
    */
  virtual HRESULT GetAttributeBlock(CATOmxKeyValueBlock &oAttrBlock, const CATString * iPLMExtension = NULL) = 0;

  /**
   * Returns the block of attribute.
   * @param oAttrBlock [out]
   *   The block of attributes.
   * @param iPLMExtension [in]
   *   The extension on which the block should be accessed. If CATPLMTypeId_Null, the block is the main attribute block.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
   */
  virtual HRESULT GetAttributeBlock(CATOmxKeyValueBlock &oAttrBlock, const CATPLMTypeId &iPLMExtension) = 0;

  /**
   * Returns the block of attribute.
   * @param oAttrBlock [out]
   *   The block of attributes.
   * @param iPLMExtension [in]
   *   The extension on which the block should be accessed. If CATPLMTypeId_Null, the block is the main attribute block.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
   */
  virtual HRESULT GetAttrBlock(CATOmxKeyValueBlock &oAttrBlock, CATPLMType* ipPLMExtension = NULL) = 0;

  /**
   * Moved from CATIPLMSystemAttrAccess
   */

   /**
    * Returns the RepoPrivilege value of the Object.
    * @param oRepoPrivilege
    *    the RepoPrivilege
    * @return
    *    E_FAIL may be returned if the record does not contain information on the RepoPrivilege of the object
    */
  virtual HRESULT GetRepoPrivilege(int & oRepoPrivilege) const = 0;

  /*
   * Returns the list of available Stream Identifiers .
   */
  virtual HRESULT ListStreamDescriptors(CATOmxList<CATPLMStreamDescriptor>& oStreamDescList) = 0;

  /**
  * Returns number of SemanticRelation found on current record.
  * @return number of SemanticRelation.
  */
  virtual int SemanticRelationDataInfosCount() const = 0;

  /**
  * Returns information compute by server and mandatory to complete SR (IDRel, pathid)
  * Those informations can be accessed after creation of new SR while save/importing data
  * @param oInfos
  *    oInfos contains IDRel and pathid
  *    Complete CATPLMSemanticRelationData using those informations
  * @return
  *    S_OK
  *    E_FAIL
  */
  virtual HRESULT GetSemanticRelationDataInfos(int iIndex, CATOmxKeyValueBlock& oInfos) const = 0;

  enum eStatus
  {
    eUndefined = 1,
    eNewObject = 2,
    eCompletionObject = 3,
    eUpdateObject = 4
  };

  virtual eStatus GetStatus() const = 0;

  virtual CATUnicodeString GetStatusAsStr() const = 0;

  /**
  * Returns the report of the incident that occurs on the record. NULL if the record is successfully
  *
  * @return IUnknown#Release
  */
  virtual CATIPLMError* GetReport() = 0;
};

#endif