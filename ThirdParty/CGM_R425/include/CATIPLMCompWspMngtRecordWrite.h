// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCompWspMngtRecordWrite.h
// Define the CATIPLMCompWspMngtRecordWrite interface
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMCompWspMngtRecordWrite_H
#define CATIPLMCompWspMngtRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompWspMngtRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompWspMngtRecordWrite ;
#endif

class CATPLMID;
class CATPLMTypeId;
class CATIPLMAttrWrite;
class CATListValCATString;
class CATPLMCopyProperties;
class CATUnicodeString;

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to New Version current object.
* This operation can be done under the control of a transaction of the PDM(s). 
*/
class ExportedByCATPLMServicesItf CATIPLMCompWspMngtRecordWrite: public CATBaseUnknown
{
  CATDeclareInterface;

public:

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
  virtual HRESULT GetPLMId( CATPLMID & oId ) = 0;

  /**
  * Specifies the mapping between a worspace object and its reference.
  * Note : The PLMID of the record is the wortkspace object
  */ 
  virtual HRESULT SynchronizeMap ( const CATPLMID &iRefObject) = 0;

  /**
  * Attachs a reference object in the workspace.
  * Note : The PLMID of the record is the reference object.
  */ 
  virtual HRESULT SynchronizeAttach() = 0;

  /**
  * Updates a workspace object from a reference object.
  * Note : The PLMID of the record is the wortkspace object
  */ 
  virtual HRESULT SynchronizeUpdate( const CATPLMID &iRefObject) = 0;

  /**
  * Detachs a workspace object from a reference object.
  * Note : The PLMID of the record is the wortkspace object
  */ 
  virtual HRESULT SynchronizeDetach ( const CATPLMID &iRefObject) = 0;


  /**
  * Delivers the creation a new reference object.
  * Note : The PLMID of the record is the wortkspace object
  */ 
  virtual HRESULT DeliverCreate() = 0;

  /**
  * Delivers the update of an object.
  * Note : The PLMID of the record is the reference object
  */ 
  virtual HRESULT DeliverUpdate(const CATPLMID &iWspObject) = 0;

  /**
  * Delivers the deletion of an object.
  * Note : The PLMID of the record is the reference object
  */ 
  virtual HRESULT DeliverDelete(const CATPLMID &iWspObject) = 0;

  /**
  * Specifies the mapping between a worspace object and its reference.
  * Note : The PLMID of the record is the reference object
  */ 
  virtual HRESULT DeliverMap ( const CATPLMID &iWspObject) = 0;

  /**
  * Log an attributes update. This method computes a CATIPLMAttrWrite interface for the dedicated object.
  * The return interface will be used by the system to update attributes. 
  *
  * It has no meaning with Detach / Delete / Map records.
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
  virtual HRESULT GetAttributeAccess ( CATIPLMAttrWrite** oAttrAccess, const CATPLMTypeId *iExtensionType = NULL) = 0;
};

#endif
