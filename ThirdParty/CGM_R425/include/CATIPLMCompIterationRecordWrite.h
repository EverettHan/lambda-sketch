// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMCompIterationRecordWrite.h
// Define the CATIPLMCompIterationRecordWrite interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
// July 2012  Creation: EPB
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompIterationRecordWrite_H
#define CATIPLMCompIterationRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompIterationRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompIterationRecordWrite ;
#endif

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to New Version current object.
* This operation can be done under the control of a transaction of the PDM(s). 
*/
class ExportedByCATPLMServicesItf CATIPLMCompIterationRecordWrite: public CATBaseUnknown
{
  CATDeclareInterface;

public:

    
  /**
  *
  * <br><b>Role</b>: 
  * @param 0;
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT RestoreObject() = 0;

  /**
  * Returns the CATPlmId of this Record (of the current object). 
  * @param  oId
  *    The PLMId of the object to modify
  * @return
  *   <dl>
  *     <dt>S_OK</dt><dd>Success.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation.</dd>
  *   </dl>
  */ 
  virtual HRESULT GetPLMId( CATPLMID & oId ) = 0;

};

#endif
