/* -*-c++-*- */
#ifndef CATINavigateObject2_h
#define CATINavigateObject2_h

// COPYRIGHT DASSAULT SYSTEMES 2019


#include "CATBaseUnknown.h"
#include "CATOmnMain.h"
#include "IUnknown.h"

extern ExportedByCATOmnMain IID IID_CATINavigateObject2;


/**
* Enrichment of interface CATINavigateObject
* /!\ THIS INTERFACE HAS TO BE IMPLEMENTED INHERITHING FROM ADAPTER CATENAVIGATEOBJECT2
*
* New feature : 
*   HasChildren : return if current node has children or not. This is a PCS complement to GetChildren, as this method can be very costly if the node has a lot of children (flat design for instance)
*
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
class ExportedByCATOmnMain CATINavigateObject2: public CATBaseUnknown
{
	CATDeclareInterface;
public:
/**
* Returns if current node has children or not. This method is supposed to be very fast and avoid unnecessary costs when properly get children is not necessary
*   @param oHasChildren [output]
      TRUE : node has at least one child
      FALSE : node has no children
    @return :
      S_OK : everything ran well and oHasChildren is usable
      E_XXX : something went wrong and output is not usable
*/
  virtual HRESULT HasChildren(CATBoolean& oHasChildren) = 0;
};

CATDeclareHandler ( CATINavigateObject2, CATBaseUnknown );


#endif

