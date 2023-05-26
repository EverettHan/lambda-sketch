/* -*-c++-*- */
#ifndef CATINavigateObject_h
#define CATINavigateObject_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Level L1
  * @CAA2Usage U5
  */

#include "CATBaseUnknown.h"
#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATINavigateObject;

class CATListValCATBaseUnknown_var;
class CATListValCATUnicodeString;

/**
* Interface to navigate in object tree.
* <b>Role:</b> This interface enables you to visualize a component in an object tree. This interface
* implementation is mandatory, even if the component is a leaf. In this case, the @href #GetChildren method
* returns an empty list.
* <p>Once you have implemented this interface, you may customize default behaviors
* for the node representing your component. Refer to the @href CATINavigElement  
* and the @href CATINavigModify interfaces. Note that contrary to <tt>CATINavigateObject</tt>, the 
* implementation of these two interfaces is not mandatory.</p>
* This interface is called in the following contexts:
* <ul>
*   <li>When the node is redrawn, thanks to the @href CATIRedrawEvent interface:
*     @href #GetIdentificators and @href #GetChildren methods are then called.</li>
*   <li>When the node is expanded: @href #GetChildren and
*    @href #GetIdentificators methods are then called.</li>
*   <li>When the node is collapsed: only @href #GetIdentificators method is called.</li>
* </ul>
* <p>This interface can be also used to "dump" the contents of an existing object tree.
*/
class ExportedByCATOmnMain CATINavigateObject: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	* Retrieves the node text.
    * <br><b>Role:</b>This method retrieves the 
    * text associated with the node. This text is used as reference for 
    * the graph name criterion of the Search mechanism. Refer to 
    * the <tt> CATIIniSearchGraphNameCriterion </tt> interface. 
    * @return
    *  The text of the node. There are as many strings as lines.  
	*/
	virtual CATListValCATUnicodeString* GetIdentificators()=0;
		
	/**
	* Retrieves list of direct childrens in the tree.
    * @return
    *  The children list.
    *  <br>The <tt>CATINavigateObject</tt> interface will be called for each one. This list
    *  is empty if the node is a leaf. 
	*/
	virtual CATListValCATBaseUnknown_var* GetChildren()=0;
};

CATDeclareHandler ( CATINavigateObject, CATBaseUnknown );


#endif

