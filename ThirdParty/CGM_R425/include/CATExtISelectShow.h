#ifndef CATExtISelectShow_H
#define CATExtISelectShow_H


// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATVisItf.h"

#include "CATBaseUnknown.h"
//#include "CATISelectShow.h"
#include "CATShowAttribut.h"
class CATPathElement;

/**
 * Adaptor class for the CATISelectShow interface.
 * <b>Role</b>: This class provides a default implementation for any extension of the 
 * @href CATISelectShow interface.<br>
 * Here is some advice on how to migrate your implementations after R15 : <br>
 * Until R13, R14, you can :
 * <ol>
 *   <li>return E_NOTIMPL in @href #GetElementForHideShow method.</li>
 *   <li>or you can copy and adapt the code that you do in @href #GetElement in the new method @href #GetElementForHideShow 
 *      <br>and call within <tt> GetElement </tt> the method <tt> GetElementForHideShow </tt> .</li>
 * </ol>
 * In R15 or before :
 * <ol>
 *   <li>return E_NOTIMPL in @href #GetElement .</li>
 *   <li>report the code of @href #GetElement in @href #GetElementForHideShow .</li>
 * </ol>
 */
class ExportedByCATVisItf CATExtISelectShow : public CATBaseUnknown
{
  /** @nodoc */
  CATDeclareClass;

  public:
  /** @nodoc */
  virtual const IID & GetSelectShowInterface();

  /**
  * @nodoc : deprecated V5R13 GetElementForHideShow.
  * Returns the object to really put in show/noshow from the user selection. 
  * <br><b>Role</b>: 
  * This method is used by the hide/show command to select, in the selected pathelement, the object
  * to show or hide.
  * <br>By default, this function returns the last object in the pathelement.
  * @param iPathElt
  * The pathelement which encloses the user selection.
  * @return
  * The object we really want to put in show/noshow.
  * <br> It is not a CATPathElement, it is the object which will be put in show or noshow.
  */
   virtual CATBaseUnknown * GetElement(CATPathElement *iPathElt);

 /**
  * Selects the object to really put in show/noshow from the user selection. 
  * <br><b>Role</b>: 
  * This method is used by the hide/show command to select the object, that will be showed or hidden, 
  * among the elements in the selected pathelement.<br>
  * In the default implementation, the selected element is the last object in the pathelement.
  * @param iPathElt
  * The pathelement which encloses the user selection.
  * @param oSelectedObject
  * The object you wish to put in Show or NoShow.<br>
  * It is not a CATPathElement, it is the object which will be put in show or noshow.
  * @param oPostProcess
  * The flag that allows the call to @href #SelectShowPostProcess method, once the object 
  * has been processed by the Hide/Show command.
  * <br>The default implementation values this flag to 0.
  * <br><b>Legal values : </b>
  * <ul>
  * <li><tt>0</tt> : the method @href #SelectShowPostProcess will not be called.</li>
  * <li><tt>1</tt> : the method @href #SelectShowPostProcess will be called.</li>
  * </ul>
  * @return
  * <ul>
  * <li>S_OK if the operation has succeeded.</li>
  * <li>E_FAIL if the operation has failed. </li>
  * <li>E_NOTIMPL if the method is not implemented. By default this is the returned result. </li>
  * </ul>
  */

   virtual HRESULT GetElementForHideShow(CATPathElement *iPathElt, CATBaseUnknown *& oSelectedObject,int& oPostProcess);

 /**
  * Post-processes a pathelement after an element has been put in Show or No Show.
  * <br><b>Role</b> :
  * This method will allow you to do particular processing after
  * the element, chosen in @href #GetElementForHideShow method, has been put in Show/NoShow.
  * @param iPathElt
  * The pathelement which encloses the user selection. It is also the argument of <tt>GetElementForHideShow</tt>.
  * @param iShowAttr
  * The state in which the processed element has been put.
  * @return
  * <ul>
  *<li>S_OK if the operation has succeeded.</li>
  *<li>E_FAIL if the operation has failed.</li>
  * </ul>
  */
   virtual HRESULT SelectShowPostProcess(CATPathElement *iPathElt,CATShowAttribut iShowAttr); 
};

#endif
