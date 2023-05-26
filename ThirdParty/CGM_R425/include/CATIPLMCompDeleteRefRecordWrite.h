// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCompDeleteRefRecordWrite.h
// Define the CATIPLMCompDeleteRefRecordWrite interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Oct 2006  Creation: Code generated by the CAA wizard  JVM
//===================================================================

/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompDeleteRefRecordWrite_H
#define CATIPLMCompDeleteRefRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompDeleteRefRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompDeleteRefRecordWrite ;
#endif

//------------------------------------------------------------------
class CATPLMID;

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to Delete current Reference object.
* This operation can be done under the control of a transaction of the PDM(s). 
*/
class ExportedByCATPLMServicesItf CATIPLMCompDeleteRefRecordWrite: public CATBaseUnknown
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
	virtual HRESULT GetPLMId( CATPLMID & oId ) = 0;

	/**
	* Delete the Reference object already identified.
	*
	* @return
	*    Error code of function :
	*   <dl>
	*     <dt>S_OK</dt>
	*     <dd>New version is successfully.</dd>
	*     <dt>S_FALSE</dt>
	*     <dd>The input Identifier does not represent an object belonging to the PDM associated to the transaction.</dd>
	*     <dt>E_FAIL </dt>
	*     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	*   </dl>
	*/ 
	virtual HRESULT DeleteRefObject() = 0;

};

//------------------------------------------------------------------

#endif
