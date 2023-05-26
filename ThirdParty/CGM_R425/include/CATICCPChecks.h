#ifndef CATICCPChecks_H
#define CATICCPChecks_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
  * @level Protected 
  * @usage U4 CATECCPChecksAdapter
  */

#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATLISTPIUnknown.h"

class CATFormat;

#include "CP0CLIP.h"

extern ExportedByCP0CLIP IID IID_CATICCPChecks ;

/**
* Interface to manage Checks related to Cut Copy Paste and Delete operations.
* <b> Role:</b> this interface is used by interactive commands such as Drag&Drop
* or Cut Copy Paste and Delete.
* 
* <br> CATICCPChecks exposes the methods required to: 
* <br>
* <br>    Retrieve the list of impacted objects, on which performing Editability checks, for paste operation. 
* <br>
*/

class ExportedByCP0CLIP CATICCPChecks: public CATBaseUnknown
{
  CATDeclareInterface;
 public:

	/**
 	* Returns the list of impacted target objects in the paste operation.
	* <br><b> Role: </b> used on paste or drop to get the list of objects on which the editability check will be performed.
  * If this interface is not implemented by the federator object implementing CATICutAndPastable interface, no editability check will be performed
  * by the paste of drop default commands.
	* @param iObjectToCopy
	*        list of objects to copy. This list may be retreived from the Clipboard.
	* @param iSelectedToObjects   
	*        target objects for paste corresponding to selected objects.
	* @param iAnImposedFormat
	*        the format selected implicitely or explicitely (case of the Paste Special command).
  *
	* @param oImpactedObjects
	*        the list of impacted objects. This list is computed by the implementation, it contains the list of objects to be modified by the Paste operation.
  *        The calling Copy command will perform an Editability check on this list of objects before performing the Paste operation.
  *        <br>LifeCycle notice : a Release() is to be performed by the caller on the returned objects.
  * @return
  *   <code>S_OK</code>, if everything ran well, otherwise <code>E_FAIL</code>.
  */
  virtual HRESULT ImpactsOnPaste(const CATLISTV(CATBaseUnknown_var)& iObjectToCopy,
				                         const CATLISTV(CATBaseUnknown_var)& iSelectedToObjects,
				                         const CATFormat* iAnImposedFormat,
                                 CATListOfIUnknown& oImpactedObjects)=0;


};

#endif 

