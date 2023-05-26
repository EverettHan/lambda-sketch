#ifndef CATIMultiSelectShow_H
#define CATIMultiSelectShow_H

// COPYRIGHT DASSAULT SYSTEMES 1999
/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtISelectShow
 */

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATShowAttribut.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListOfInt.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIMultiSelectShow;
#else
extern "C" const IID IID_CATIMultiSelectShow;
#endif

class CATPathElement;

/** 
 * Interface for managing the hide/show command.
 * <b>Role</b> : This interface has two goals.
 * <ol>
 * <li> The hide/show command works on @href CATPathElement, and 
 * puts in show or noshow the last object of the pathelement
 * which implements CATIMultiSelectShow. So, if you want the hide/show command
 * to work on your object, it is necessary to implement <tt>CATIMultiSelectShow</tt>.</li>
 * <li> You can implement your own function @href #GetElementsForHideShow . This way,
 * the hide/show command will put in show or noshow the objects
 * returned by this function. .</li>
 *</ol>
 */
class ExportedByCATVisItf CATIMultiSelectShow : public CATBaseUnknown
{
	/** @nodoc */
    CATDeclareInterface;
public:

 /**
  * Selects the object to really put in show/noshow from the user selection. 
  * <br><b>Role</b>: 
  * This method is used by the hide/show command to select the object, that will be showed or hidden, 
  * among the elements in the selected pathelement.
  * @param iPathElt
  * The pathelement which encloses the user selection.
  * @param oSelectedObject
  * The objects you wish to put in Show or NoShow.
  * <br>It is list of a CATPathElement, objects which will be put in show or noshow.
   * @return
  * <ul>
  * <li>S_OK if the operation has succeeded.</li>
  * <li>E_FAIL if the operation has failed. </li>
  * <li>E_NOTIMPL if the method is not implemented.</li>
  * </ul>
  */


   virtual HRESULT GetElementsForHideShow(CATPathElement *iPathElt, CATListValCATBaseUnknown_var  & oSelectedObjects) = 0;

};

/** @nodoc */
CATDeclareHandler(CATIMultiSelectShow, CATBaseUnknown);

#endif
