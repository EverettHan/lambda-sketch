// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCompRefreshRecordWrite.h
// Define the CATIPLMCompRefreshRecordWrite interface
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

#ifndef CATIPLMCompRefreshRecordWrite_H
#define CATIPLMCompRefreshRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompRefreshRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompRefreshRecordWrite ;
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
class ExportedByCATPLMServicesItf CATIPLMCompRefreshRecordWrite: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Sets the PLMID of source object. 
  * @param  iBaseId
  *    The PLMId of the source object from which the target will be modified.
  * @return
  *    Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation.</dd>
  *   </dl>
  */ 
  virtual HRESULT SetBaseObject ( const CATPLMID & iBaseId ) = 0;

  /**
  * Gets the PLMID of objects involved in the refresh. 
  * @param  oTargetId
  *    The PLMId of the source object from which the target will be modified.
  * @return
  *    Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation.</dd>
  *   </dl>
  */ 
  virtual HRESULT GetObjects ( CATPLMID & oTargetId, CATPLMID & oBaseId ) = 0;

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
