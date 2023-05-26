/* -*-c++-*- */
#ifndef CATINavigModify_h
#define CATINavigModify_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Level L1
  * @CAA2Usage U4 CATNodeExtension 
  */


#include <CATBaseUnknown.h>

#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATINavigModify;

class CATNavigInstance;
class CATUnicodeString ;

/**
* Interface to customize tree node visualization.
* <br><b>Role:</b>This interface enables you to customize the visual aspect of nodes associated with
* your object. If to be visualized in object tree, an object must implement the @href CATINavigateObject 
* interface, this interface implementation is not mandatory. Nodes associated with an object have a
* default implementation of this interface, such as the @href CATINavigElement and @href CATIGraphNode interfaces.
* <br><br>This implementation, full or partial, is not done on the object itself but on an object, named 
* <tt>MyObject<b>_node</b></tt>, where <tt>MyObject</tt> is the name of the object. 
* <br><br>To implement @href #UpdateElem or @href #ModifyShortHelp , 
* it can be useful to retrieve a pointer to the object implementing @href CATINavigateObject. 
* From a node, there are two steps:
* <ol>
*    <li> Call @href CATINavigElement#GetAssociatedInstance , to retrieve a @href CATNavigInstance 
*      pointer (It is already the @href #UpdateElem input) </li>
*    <li> Then, call @href CATNavigInstance#GetReference  to retrieve a pointer on the 
*        object associated with the node.</li>
* </ol>
* <p><b>BOA information</b>: this interface CANNOT be implemented
* using the BOA (Basic Object Adapter).
* To know more about the BOA, refer to the CAA Encyclopedia home page.
* Click Middleware at the bottom left, then click the Object Modeler tab page.
* Several articles deal with the BOA.</p>
*/

class ExportedByCATOmnMain CATINavigModify: public CATBaseUnknown
{
	CATDeclareInterface;
public:

	/**
	* Defines node graphic representation.
    * <br><b>Role</b>:This method enables you to modify the default visual aspect of a node. By using
    * the @href CATIGraphNode interface you can:
    * <ul>
    *   <li>Modify the text ( @href CATIGraphNode#SetText ): the default one is those returned 
    *       by @href CATINavigateObject#GetIdentificators ,</li>
    *   <li>Modify the box color ( @href CATIGraphNode#SetColor ): the default color is blue , </li>
    *   <li>Add an icon ( @href CATIGraphNode#SetPixelImage ) , </li>
    *   <li>...</li>  
    * </ul>
    * The @href CATIGraphNode interface is natively implemented on your node. You use it in the
    * <tt>UpdateElem</tt> implementation such as:
    * <pre>
    *      CATIGraphNode *pIGraphNode = NULL ;
    *      HRESULT rc = QueryInterface(IID_CATIGraphNode,
	*                        (void**)&pIGraphNode);
    *      if ( SUCCEEDED(rc) )
    *      {
    *          pIGraphNode->SetXXX(..);
    *      }
    * </pre>
    * @param iInst
    *   The navig instance associated with the node.
    *   <br>This parameter enables you to retrieve the component associated with the node and then 
    *   to get specific information from the component.
	*/
	virtual void UpdateElem (CATNavigInstance* iInst)=0;

    /**
    * Defines the node short help.
    * <br><b>Role</b>: When you pass over a node a short help is
    * displayed. The short help text is the text associated with the node. This text
    * is either the name returned by the @href CATINavigateObject#GetIdentificators
    * method, or if defined, the text set thanks to the @href CATIGraphNode#SetText method.
    * <br>This method enables you to modify this default behavior defined by
    * @href CATNodeExtension#ModifyShortHelp. You have three
    *  possibilities:
    *   <ul>
    *    <li>do not overwrite this method: you have the
    *        default behavior: short help + text associated with the node, </li>.
    *    <li>Overwrite it and return <tt>E_FAIL</tt>: no short help will be displayed,</li>
    *    <li>Overwrite it and return <tt>S_OK</tt>: <tt>ioText</tt> will be the displayed text.</li>
    *   </ul>
    * @param ioText
    *   The short help of the node. 
    *   <br>In input <tt>ioText</tt> is the text associated with the node.
    * @return
    *    The displaying state.
    *    <br><b>Legal values</b>: 
    *     <ul>
    *      <li>E_FAIL: no short help will be displayed</li>
    *      <li>S_OK : <tt>ioText</tt> will be displayed</li>
    *     </ul>
    */
    virtual HRESULT ModifyShortHelp(CATUnicodeString& ioText) = 0;

	/**
	* Defines whether the node is selectable or not.
	* <br><b>Note:</b> This method enables you to control 
  *  the node selection. The default behavior brings the node selectionnable.
  * @param iMode
  *   The selectable mode.
  *  
	*/
	virtual void Select(int iMode)=0;

	/**
	* Defines whether the node has ever been selected. 
  * @return
  *    The selecting state.
  *    <br><b>Legal values</b>: 
  *     <ul>
  *      <li>0: The node is not selected</li>
  *      <li>Otherwise : selected</li>
  *     </ul>
	*/
	virtual int IsSelected()=0;

};

CATDeclareHandler( CATINavigModify, CATBaseUnknown);


#endif

