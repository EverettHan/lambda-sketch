/* -*-c++-*- */
#ifndef CATINavigElement_H
#define CATINavigElement_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
  * @CAA2Level L1
  * @CAA2Usage U4 CATNodeExtension
  */
#include <CATBaseUnknown.h>

class CATINavigContainer;
class CATNavigInstance;
class CATNavigController;

#include "CATOmnMain.h"
extern ExportedByCATOmnMain IID IID_CATINavigElement;

/**
* Interface to manage tree node modifications.
* <br><b>Role:</b>This interface enables you to specify or apply behaviors for a node associated with
* your object. If to be visualized in object tree, an object must implement the @href CATINavigateObject 
* interface, this interface implementation is not mandatory. Nodes associated with an object have a
* default implementation of this interface, such as the @href CATINavigModify and @href CATIGraphNode interfaces.
* <p>You can re-implement the <tt>Processxxx</tt> methods, but in most cases their default behavior 
* is sufficient. However, the three others: @href #Update ,@href #GetController , 
* and @href #GetAssociatedInstance cannot be re-implemented, you can only use it. </p>
* <p>This implementation, full or partial, is not done on the object itself but on an object, named 
* <tt>MyObject<b>_node</b></tt>, where <tt>MyObject</tt> is the name of the object. </p>
*
* <p><b>BOA information</b>: this interface CANNOT be implemented
* using the BOA (Basic Object Adapter).
* To know more about the BOA, refer to the CAA Encyclopedia home page.
* Click Middleware at the bottom left, then click the Object Modeler tab page.
* Several articles deal with the BOA.</p>
*/

class ExportedByCATOmnMain CATINavigElement : public CATBaseUnknown
{
	CATDeclareInterface;
 public:	
	

    /**
	* Defines behavior after selection of the node.
    * <br><b>Role:</b>This method defines the behavior after selection of the node. Refer to
    * the @href CATNodeExtension#ProcessAfterSelect method for the default implementation.
	*/
	virtual void ProcessAfterSelect()=0;
	/**
	* Defines behavior after selection of several nodes.
    * <br><b>Role:</b>This method defines the behavior after selection of several nodes. Refer to
    * the @href CATNodeExtension#ProcessAfterExtSelect method for the default implementation.
	*/
	virtual void ProcessAfterExtSelect()=0;
	/**
	* Defines behavior after double-click of the node.
    * <br><b>Role:</b>This method defines the behavior after double-click of the node. Refer to
    * the @href CATNodeExtension#ProcessAfterAction method for the default implementation.
	*/
	virtual void ProcessAfterAction()=0;
	/**
	* Defines behavior after expand of the node.
    * <br><b>Role:</b>This method defines the behavior when the end user clicks on the 
    * +/- icons of the node. Refer to
    * the @href CATNodeExtension#ProcessAfterExpand method for the default implementation.
    * <br>This method can be also used to produce an expand/collapse of the node. 
	*/
	virtual void ProcessAfterExpand()=0;

	/**
	* Defines behavior when the contextual menu is asked on the node.
  * <br><b>Role:</b>This method defines the behavior when the contextual menu is asked on the node. Refer to
  * the @href CATNodeExtension#ProcessAfterMethod method for the default implementation.
  * <br>You may not have to re-implement this method, the contextual menu defined
  * through the <tt>CATIContextualMenu</tt> or
  * <tt>CATIContextualSubMenu</tt> interfaces is the contextual menu of an object, 
  * in 3D such as in the object tree.
	*/
	virtual void ProcessAfterMethod()=0;

	/**  
   *  Returns  the  father container.  
   *  Returned  pointer  must  be  released.  
   */
	virtual CATINavigContainer* GetFatherContainer()=0;

  /**
	 * Updates node. 
   * <br><b>Role:</b>This method is useful when an update of the node is necessary.
   * You have used methods of the @href CATIGraphNode 
   * interface to modify a visual aspect of the node, 
   * a call to this method is necessary to update the visualization of the node. 
	 */
	virtual void Update()=0;

	/**
	* Retrieves the tree controller.
    * @return 
    * The tree controller.
    * <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
    *  returned value.
	*/
	virtual const CATNavigController* GetController()=0;

	/**
	* Retrieves the instance associated with the node.
    * <br><b>Role</b>: This method retrieves the object associated with the
    *  node.  
	* @return 
    * The associated instance.
    * <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
    *  returned value.
	*/
	virtual CATNavigInstance* GetAssociatedInstance()=0;


	/**
     * @nodoc
	 * Removes a node.
	 * @param iIndex
	 *        useless 
	 */
	virtual void Remove(int iIndex)=0;

	/**
	* @nodoc 
	* internal
	*/
	virtual void SetMarked(int mark=1)=0;
	/**
	* @nodoc 
	* internal
	*/
	virtual int  GetMarked()=0;
};


CATDeclareHandler ( CATINavigElement , CATBaseUnknown);


#endif

