// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCompCheckEditRecordWrite.h
// Define the CATIPLMCompCheckEditRecordWrite interface
//
//  Oct 2006  Creation:  BHG
//===================================================================

/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompCheckEditRecordWrite_H
#define CATIPLMCompCheckEditRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompCheckEditRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompCheckEditRecordWrite;
#endif




//------------------------------------------------------------------
class CATPLMID;

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to Check Editability of an object.
* This operation can be done under the control of a transaction of the PDM(s). 
*/
class ExportedByCATPLMServicesItf CATIPLMCompCheckEditRecordWrite: public CATBaseUnknown
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
	virtual HRESULT GetPLMId(CATPLMID& oId) = 0;

	/**
	* Check the editability of an Object.
	* @return
	*    Error code of function :
	*   <dl>
	*     <dt>S_OK</dt>
	*     <dd>successfully.</dd>
	*     <dt>S_FALSE</dt>
	*     <dd>The input Identifier does not represent an object belonging to the PDM associated to the transaction.</dd>
	*     <dt>E_FAIL </dt>
	*     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	*   </dl>
	*/ 
	virtual HRESULT CheckEditability() = 0;

};

//------------------------------------------------------------------

#endif
