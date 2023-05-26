// COPYRIGHT DASSAULT SYSTEMES 2011/09/19
#ifndef CATICAfrComponent_H
#define CATICAfrComponent_H

/**
 * @level Protected
 * @CAA2Usage U3
 */

#include "CATAfrItf.h"
#include "CATICAfrComponentElement.h"
#include "CATString.h"
#include "CATListOfCATICAfrComponentElement.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATAfrPropertyBundle;
class CATICAfrComponentElement;
class CATICAfrComponentController;

extern ExportedByCATAfrItf  IID IID_CATICAfrComponent ;
//-----------------------------------------------------------------------------
/**
* Interface to manage the Afr Component.
*/
class ExportedByCATAfrItf CATICAfrComponent: public CATICAfrComponentElement
{
  CATDeclareInterface;

  public:

    /**
    * Sets the title of the form.
	*   @param iTitle
    *     The title
    */
    virtual void SetTitle( const CATUnicodeString& iTitle ) = 0;

    /**
    *  Returns the title of the form.
	*    @Return
	*      The title of the form
    */
    virtual const CATUnicodeString& GetTitle( ) const = 0;

    /**
    * Sets the view parent.
	* <b>Role</b>: Can be NULL. In this case, 
    * the view will create a panel box that contains the component. 
    * <br>Use the method @href CATCAfrComponentServices#AddComponentViewDeletedCB with the name of 
	* your component, to be called when the view is deleted in order to manage your life cycle.
    */
    virtual void SetViewParent( const CATBaseUnknown_var& i_spViewParent ) = 0;

    /**
    * Gets the view parent.
	*  @Return
	*    The view parent.
    */
    virtual CATBaseUnknown_var GetViewParent() = 0;

    /**
    * Refreshes the view. 
	* <b>Role</b>: the view is regenerated.
    */
    virtual void RefreshView( ) = 0;

    /**
    * Invalidates the view.
    * <b>Role</b>: If RootFlag, delete the model view
    */
    virtual void Invalidate( ) = 0;

    /**
    * Adds a new element.
	*
    * <br><b>Role</b>: This method enables to add a new element.
    * <br>You can initialize properties of the new element thanks to the Property Bundle. 
    * Here is an example of how you can use it:
    * <code>
    *   CATAfrPropertyBundle bundle;
    *   bundle.PutObject("IconPixelImage",new CATPixelImage(...));
    *   bundle.PutCATString("Name","MyName");
    *   bundle.PutCATUnicodeString("Display","MyTitle");   
    *   bundle.PutInt("Visibility",0);   
    *   piComponent->AddElement(&piComponentElement,"CATAfrListItem","MyId","",FALSE,&bundle);
    *</code>
    * <strong>IMPORTANT: </strong> These properties must exist for this element.
	*
    *  @param opiComponentElement
    *    The created element [out, CATICAfrComponentElement#Release]
	*
    *  @param iElementType
    *    The type of the element
	*
    *  @param iElementId
    *    The id of the element
	*
    *  @param iPrecElementId
    *    The precedent id of the element to add
	*
    *  @param iNotifFire
    *    A Notification fire
	*
    *  @param iPropertyBundle
    *    The bundle that maps properties of element that will be created in order to initialize properties
	*
    *  @return 
    *    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *      <li><b>S_OK</b>The function was executed successfully.</li>
    *      <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    *
    */
    virtual HRESULT AddElement( CATICAfrComponentElement** opiComponentElement, 
                                const CATString& iElementType, 
                                const CATString& iElementId, 
                                const CATString& iPrecElementId = "", 
                                const CATBoolean& iNotifFire = TRUE,
                                CATAfrPropertyBundle * iPropertyBundle = NULL ) = 0;

    /**
    * Adds a C-Afr Component.
	*
    * <br><b>Role</b>: This method enables to add a C-Afr Component.
	*
    *  @param ipiCAfrComponent
    *    The component to add
	*
    *  @return 
    *    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *     <ul>
    *     <li><b>S_OK</b>The function was executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT AddCAfrComponent( CATICAfrComponent* ipiCAfrComponent ) = 0;

    /**
    * Moves an element.
    *
    *  @param ipiElementTomove
    *    The element to move
    *
    *  @param iNewIndex
    *    The new index to move
    *
    *  @param iUpdateView
    *    Update view needed
    *
    *  @return 
    *    An HRESULT value. 
	*     <br><b>Legal values</b>:
    *     <ul>
    *       <li><b>S_OK</b>The function was executed successfully.</li>
    *       <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT Move( CATBaseUnknown* ipiElementTomove, 
                          const int& iNewIndex, const CATBoolean& iUpdateView = TRUE ) = 0;

    /**
    * Removes an element.
    *
    *  @param iElementId
    *    The id of the element to remove
    *
    *  @return
	*    An HRESULT value. 
	*     <br><b>Legal values</b>:
    *     <ul>
    *       <li><b>S_OK</b>The function was executed successfully.</li>
    *       <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT RemoveElement( const CATString& iElementId ) = 0;

    /**
    * Removes all elements
	*
    *  @return
	*    An HRESULT value. 
	*     <br><b>Legal values</b>:
    *     <ul>
    *     <li><b>S_OK</b>The function was executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT RemoveAll( ) = 0;

    /**
    * Retrieves an element by its Id.
    *
    *  @param opiComponentElement
    *    The retrived element [out, CATICAfrComponentElement#Release]
    *
    *  @param iElementId
    *    The id of the element
    *
    *  @return 
	*    An HRESULT value. 
	*     <br><b>Legal values</b>:
    *     <ul>
    *       <li><b>S_OK</b>The function was executed successfully.</li>
    *       <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT GetElement( CATICAfrComponentElement** opiComponentElement, 
                                const CATString& iElementId ) = 0;

    /**
    * Retrieves all elements of the component.
    *
    *  @param oListComponentElements
    *    The list of elements [out, CATICAfrComponentElement#Release]
    *
    *  @return
	*    An HRESULT value. 
	*     <br><b>Legal values</b>:
    *     <ul>
    *       <li><b>S_OK</b>The function was executed successfully.</li>
    *       <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT GetElements( CATListOfCATICAfrComponentElement& oListComponentElements ) = 0;

    /**
    * Registers an applicative controller.
    *
    * <br><b>Role</b>: This method adds a controller of the component.
    *
    *  @param ipiController
    *    The controller to add
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function was executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT RegisterController( CATICAfrComponentController* ipiController ) = 0;

    /**
    * Gets the register controller.
	*  @Return
	*    The register controller.
    */
    virtual CATICAfrComponentController*& GetRegisterController( ) = 0;


};
CATDeclareHandler( CATICAfrComponent, CATICAfrComponentElement );
#endif
