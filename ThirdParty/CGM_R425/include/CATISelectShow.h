#ifndef CATISelectShow_H
#define CATISelectShow_H

// COPYRIGHT DASSAULT SYSTEMES 1999
/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtISelectShow
 */

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATShowAttribut.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATISelectShow;
#else
extern "C" const IID IID_CATISelectShow;
#endif

class CATPathElement;

/** 
 * Interface for managing the hide/show command.
 * <b>Role</b> : This interface has two goals.
 * <ol>
 * <li> The hide/show command works on @href CATPathElement, and 
 * puts in show or noshow the last object of the pathelement
 * which implements CATISelectShow. So, if you want the hide/show command
 * to work on your object, it is necessary to implement <tt>CATISelectShow</tt>.</li>
 * <li> You can implement your own function @href #GetElementForHideShow . This way,
 * the hide/show command will put in show or noshow the object
 * returned by this function. This second goal is optional.</li>
 *</ol>
 * NB : When the hide/show command puts in show or noshow an object,
 * it uses the interface @href CATIVisProperties on this object.
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 */
class ExportedByCATVisItf CATISelectShow : public CATBaseUnknown
{
	/** @nodoc */
    CATDeclareInterface;
public:
   /** @nodoc */
   virtual const IID & GetSelectShowInterface() = 0;

  /**
  * @nodoc : deprecated V5R13 GetElementForHideShow.
  * Returns the object to really put in show/noshow from the user selection. 
  * @param iPathElt
  * The pathelement which encloses the user selection.
  * @return
  * The object we really want to put in show/noshow 
  * <br>It is not a CATPathElement, it is the object which will be put in show or noshow.
  */
   virtual CATBaseUnknown * GetElement(CATPathElement *iPathElt) = 0;
 
 /**
  * Selects the object to really put in show/noshow from the user selection. 
  * <br><b>Role</b>: 
  * This method is used by the hide/show command to select the object, that will be showed or hidden, 
  * among the elements in the selected pathelement.
  * @param iPathElt
  * The pathelement which encloses the user selection.
  * @param oSelectedObject
  * The object you wish to put in Show or NoShow.
  * <br>It is not a CATPathElement, it is the object which will be put in show or noshow.
  * @param oPostProcess
  * The flag that allows the call to method @href #SelectShowPostProcess, once the object 
  * has been processed by the Hide/Show command.
  * The default implementation values this flag to 0.
  * <br><b>Legal values : </b>
  * <ul>
  * <li><tt>0</tt> : the method @href #SelectShowPostProcess will not be called</li>
  * <li><tt>1</tt> : the method @href #SelectShowPostProcess will be called</li>
  * </ul>
   * @return
  * <ul>
  * <li>S_OK if the operation has succeeded.</li>
  * <li>E_FAIL if the operation has failed. </li>
  * <li>E_NOTIMPL if the method is not implemented.</li>
  * </ul>
  */


   virtual HRESULT GetElementForHideShow(CATPathElement *iPathElt,CATBaseUnknown *& oSelectedObject, int& oPostProcess) = 0;

 /**
  * Post-processes a pathelement after an element has been put in Show or No Show.
  * <br><b>Role</b> :
  * This method is called if the method @href #GetElementForHideShow has valued the flag <tt>oPostProcess</tt> to 1.
  * <br>It allows the user to make some post-processing on the pathelement.
  * @param iPathElt
  * The pathelement which encloses the user selection. It is also the argument of <tt>GetElementForHideShow</tt>.
  * @param iShowAttr
  * The state in which the processed element has been put.
  * @return
  * <ul>
  *<li>S_OK if the operation has succeeded.</li>
  *<li>E_FAIL if the operation has failed</li>
  * </ul>
  */
   virtual HRESULT SelectShowPostProcess(CATPathElement *iPathElt,CATShowAttribut iShowAttr) = 0;
    
};

/** @nodoc */
CATDeclareHandler(CATISelectShow, CATBaseUnknown);

#endif
