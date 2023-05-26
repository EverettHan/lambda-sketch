// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMCompTransferOwnershipRecordWrite.h
// Define the CATIPLMCompTransferOwnershipRecordWrite interface
//
//===================================================================
//
// Usage notes:
// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATIPLMCompTransferOwnershipTransaction.h
//
//===================================================================
//
// Usage notes:
//
//  June 2011  Creation: FBN
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompTransferOwnershipRecordWrite_H
#define CATIPLMCompTransferOwnershipRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompTransferOwnershipRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompTransferOwnershipRecordWrite;
#endif
//------------------------------------------------------------------

class CATPLMID;
class CATUnicodeString;

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to change ownership of an object.
* This operation can be done under the control of a transaction of the PDM(s).
*/
class ExportedByCATPLMServicesItf CATIPLMCompTransferOwnershipRecordWrite : public CATBaseUnknown
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
   *     <dt>S_OK</dt>
   *     <dd>successfully.</dd>
   *     <dt>E_FAIL </dt>
   *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
   *   </dl>
   */
  virtual HRESULT GetPLMId(CATPLMID &oId) = 0;

  /**
   * Change the ownership of the object already identified.
   * @param  iUserName
   *    New user to transfert the ownership to.
   * @param  iOrganisation
   *    New organisation to transfert the ownership to.
   * @param  iProject
   *    New project to transfert the ownership to.
   * @return
   *    Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dt>S_FALSE</dt>
   *     <dd>The input Identifier does not represent an object belonging to the PDM associated to the transaction.</dd>
   *     <dt>E_FAIL </dt>
   *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
   *   </dl>
   */
  virtual HRESULT ChangeOwnership(const CATUnicodeString &iUserName, const CATUnicodeString &iOrganisation, const CATUnicodeString &iProject) = 0;
};
//------------------------------------------------------------------
#endif
