// COPYRIGHT Dassault Systemes 2006
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIOmbDelegateObject_H
#define CATIOmbDelegateObject_H

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATILinkableObject.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIOmbDelegateObject;
#else
extern "C" const IID IID_CATIOmbDelegateObject ;
#endif


/**
* CATIOmbDelegateObject interface.<br>
* <br>
* <b>Role</b>:<br>
* <ul>
*   Object pointed by ProductStructure Linkable Object (PLO).<br>
*   These objects are used by PLO to reference 
*   either geometrical features, or selection objects.<br>
* </ul>
*/
class ExportedByAC0XXLNK CATIOmbDelegateObject: public CATBaseUnknown
{
  CATDeclareInterface;
  
public:  
  /** 
  * Gets the Status of the DelegateObject.<br>
  * <br>
  * <b>Role</b>:<br>
  *   <ul>
  *   Gets the Status(OK or KO) of the DelegateObject.<br>
  *   </ul>
  * <br>
  * @param oStatus [out]
  *   The Status (OK or KO) of the DelegateObject.<br>
  * <br>
  * @return
  *   <code>S_OK</code>.<br>
  */
  virtual HRESULT GetStatus(int& oStatus) const=0; 

  /** 
  * Gets the LinkableObject pointed by the DelegateObject.<br>
  * <br>
  * <b>Role</b>:
  *   <ul>
  *   Gets the LinkableObject pointed by the DelegateObject.<br>
  *   </ul>
  * <br>
  * @param oLinkableObject [out]
  *   The LinkableObject pointed by the DelegateObject.<br>
  * <br>
  * @return
  *   <code>S_OK</code> if the LinkableObject pointed by the DelegateObject is valid and can be provided.<br>
  *   <code>E_FAIL</code> otherwise.<br>
  *
  */
  virtual HRESULT GetReferenceObject(CATILinkableObject_var& oLinkableObject)=0; 

};

CATDeclareHandler(CATIOmbDelegateObject,CATBaseUnknown);

#endif
