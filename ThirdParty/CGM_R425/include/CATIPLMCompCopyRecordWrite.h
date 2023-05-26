// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCompCopyRecordWrite.h
// Define the CATIPLMCompCopyRecordWrite interface
//
//===================================================================
//
// Usage notes:
//    New interface:
//    During a PLMCOPY, instances and references are explicitely given
//    Completion is called on the server side to get port and connection
//    For each object given (instance or reference), we specify options:
//    KeepOwnership,KeepLock,KeepMaturity,KeepVersioning.
//
//    During a PLMCLONE, completion is called on the server side to retrive
//    all objects.
//
//===================================================================
//
// June 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMCompCopyRecordWrite_H
#define CATIPLMCompCopyRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATIPLMAttrWrite.h"
#include "CATPLMOmxCollections.h"
#include "CATPLMStrongRelationshipId.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompCopyRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompCopyRecordWrite;
#endif

class CATPLMID;
class CATPLMTypeId;
class CATIPLMAttrWrite;
class CATListValCATString;
class CATPLMNLVPropertiesWrite;
class CATUnicodeString;

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to New Version current object.
* This operation can be done under the control of a transaction of the PDM(s).
*/
class ExportedByCATPLMServicesItf CATIPLMCompCopyRecordWrite : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Short role of the method.
  *
  * <br><b>Role</b>: Explain what this method does.
  *
  * @param iProperties [in]
  *    Specify options that can be set during the copy:
  *    For references, options are:
  *    KeepOwnership,KeepLock,KeepMaturity,KeepVersioning
  *    For instances,options are:
  *    KeepOwnership,KeepLock
  *    Note:
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *   <dt>E_FAIL </dt><dd>      A problem occurs during the operation.</dd>
  *   <dt>E_INVALIDARG</dt><dd> If you pass for an instance or a rep instance a CATCopyProperties object
  *                               which KeepMaturity or KeepVersioning is set, we raise an error
  *
  */
  virtual HRESULT SetProperties(const CATPLMNLVPropertiesWrite & iProperties) = 0;

  virtual HRESULT GetProperties(CATPLMNLVPropertiesWrite & oProperties) = 0;

  /**
  * Returns the CATPlmId of this Record (of the current object).
  * @param  oId
  *    The PLMId of the object to modify
  * @return
  *    Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation.</dd>
  *   </dl>
  */
  virtual HRESULT GetPLMId(CATPLMID & oId) = 0;

  /**
  * Copy the object already identified.
  *
  * Warning: this method must be called after SetProperties.
  *
  * @return
  *    Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>         operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>      A problem occurs during the operation.</dd>
  *   </dl>
  */
  virtual HRESULT CopyObject() = 0;

  virtual HRESULT GetAttributeAccess(CATPLMType* ipExtensionType, CATIPLMAttrWrite *& oAttrAccess) = 0;

  /**
  * Log an attributes update. This method computes a CATIPLMAttrWrite interface for the dedicated object.
  * The return interface will be used by the system to update attributes.
  *
  * @param  oAttrAccess [out, CATBaseUnknown#Release]
  *    interface managing attributes setting
  * @param  iExtensionType
  *    Applicative extension type
  *    if NULL (Default) -> Attributes belong to the Master Bloc (MBSI)
  *    if Valued -> Attributes belong to the Slave Bloc (SBSI) corresponding to iExtensionType
  * @return
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL</dt><dd>A problem occurs during the operation.</dd>
  *   </dl>
  */
  virtual HRESULT GetAttributeAccess(CATIPLMAttrWrite** oAttrAccess, const CATPLMTypeId *iExtensionType = NULL) = 0;

  virtual CATPLMOrderedOSetOfTypeH GetListExtension() const = 0;

  /**
  * Logs the request to keep the family ID.
  *
  * @return
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation.</dd>
  *   </dl>
  */
  virtual HRESULT KeepFamily() = 0;

  virtual HRESULT SetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, const CATPLMID& iValue) = 0;

  virtual HRESULT GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMID &  oTargetId) = 0;

  virtual HRESULT GetCEStamp(CATPLMCEStamp& oCEStamp) const = 0;

  virtual CATPLMCEStamp GetCEStamp() const = 0;

};

#endif
