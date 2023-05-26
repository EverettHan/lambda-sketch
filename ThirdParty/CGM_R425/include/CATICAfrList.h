
#ifndef CATICAfrList_H
#define CATICAfrList_H

// COPYRIGHT DASSAULT SYSTEMES 2012/02/08

#include "CATAfrItf.h"
#include "CATICAfrComponent.h"
#include "CATListOfInt.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATCAfrEnum.h"
#include "CATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"

class CATAfrPropertyBundle;
class CATListValCATUnicodeString;
class CATListValCATString;
class CATRawCollint;

extern ExportedByCATAfrItf  IID IID_CATICAfrList ;

//-----------------------------------------------------------------------------
/**
* Interface representing The thumbnail Component.
*/
class ExportedByCATAfrItf CATICAfrList: public CATICAfrComponent
{
  CATDeclareInterface;

  public:

    /**
    * Get the current mode used for the selection behavior.
    *
    * @return the current selection mode.
    */
    virtual CATCAfrEnum::SelectionMode GetSelectionMode() const = 0;

    /**
    * Set the current mode used for the selection behavior.
    *
    * @param i_mode the new selection mode to use.
    */
    virtual void SetSelectionMode( CATCAfrEnum::SelectionMode i_mode) = 0;

    /**
    * Get the current mode used for the Thumbnails behavior.
    *
    * @return the current selection mode.
    */
    virtual CATCAfrEnum::ThumbnailsMode GetThumbnailsMode() const = 0;

    /**
    * Set the current mode used for the Thumbnails behavior.
    *
    * @param i_mode the new selection mode to use.
    */
    virtual void SetThumbnailsMode( CATCAfrEnum::ThumbnailsMode i_mode) = 0;

    /**
    * enum for view modes
    **/
    enum ViewMode
    {
      Thumbnails = 1,
      Tiles      = 2,
      Details    = 3,
      Basic      = 4 
    };
    /**
    * Set the current mode used for the Thumbnails behavior.
    *
    * @param i_mode the new selection mode to use.
    */
    virtual void SetViewMode( const CATICAfrList::ViewMode& i_mode) = 0;

    /**
    * Sets the list of selected items.
    *
    * @param ispList the list of selected items.
    * @param iNotif notification fire
    */
    virtual HRESULT SetSelected( const CATLISTV(CATBaseUnknown_var)& iListItems, 
                                 const int& iNotif = 1 ) = 0;

    /**
    * Gets the list of selected items.
    */
    virtual CATLISTV(CATBaseUnknown_var)& GetSelectedItems( ) = 0;

    /**
    * Sets the type late of the tooltip.
    *
    * @param i_tooltipLate the type late of the tooltip.
    */
    virtual void SetTooltipProviderTypeLate( const CATUnicodeString & i_tooltipLate ) = 0;

    /**
    * Default value points to the default short tooltip data template.
    * 
    * @param i_sTemplateName the name of the template for the short tooltip form.
    *
    * @see #SetTooltipTemplateName
    */
    virtual void SetShortTooltipTemplateName(const CATUnicodeString& i_sTemplateName) = 0;

    /**
    * @return the name of the template for the short tooltip form.
    *
    * @see #GetTooltipTemplateName
    */
    virtual CATUnicodeString GetShortTooltipTemplateName() const = 0;

    /**
    * @return the name of the style sheet where the data template for the short
    * tooltip for is defined.
    *
    * @see #SetShortTooltipStyleSheet
    */
    virtual CATUnicodeString GetShortTooltipStyleSheet() const = 0;

    /**
    * Sets the name of the style sheet where the data template for the short 
    * tooltip is defined. Default value is the style sheet of default data 
    * template (see @ref #SetShortTooltipTemplateName).
    * 
    * @param i_sStyleSheet the name of the style sheet.
    *
    * @see #GetShortTooltipStyleSheet
    */
    virtual void SetShortTooltipStyleSheet(const CATUnicodeString& i_sStyleSheet) = 0;

    /**
    * Remove view element
    *
    * <br><b>Role</b>: This method removes the view of element
    *
    *  @param iElementId
    *  The id of the element
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT RemoveView( const CATString& iElementId ) = 0;

    /**
    * Connects two objects
    *
    * <br><b>Role</b>: This method connects two elements
    *
    *  @param ipObject
    *  The first element
    *
    *  @param ipNext
    *  The second element
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT ReconnectLink( CATBaseUnknown* ipObject, CATBaseUnknown* ipNext ) = 0;

    /**
    * Add existing elements
    *
    * <br><b>Role</b>: This method existing elements
    *
    *  @param ispList
    *  The existing elements
    *
    *  @param ispPrecElement
    *  The precedent the element.
    *
    *  @param iIndex
    *  The index to add.
    *
    *  @param ospListCreated
    *  The created elements
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    */
    virtual HRESULT AddFromExistingElements( const CATLISTV(CATBaseUnknown_var)& ispList, 
                                             CATBaseUnknown_var ispPrecElement, 
                                             const int& iIndex, 
                                             CATLISTV(CATBaseUnknown_var)& ospListCreated ) = 0;

    /**
    * Add a C-Afr Component
    *
    * <br><b>Role</b>: This method creates and adds a new CAfr component
    *
    *  @param iXMLFile
    *  The XML file to declare the Template
    *
    *  @param iTemplateName
    *  The Template name
    *
    *  @param iComponentInstanceName
    *  The Instance id, it will change to iComponentInstanceName.index
    *
    *  @param iNumberOfElements
    *  Number of objects to create
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    virtual HRESULT CreateCAfrComponent( const CATUnicodeString& iXMLFile, 
                                         const CATUnicodeString& iTemplateName, 
                                         const CATString& iComponentInstanceName, 
                                         const int& iNumberOfElements = 1 ) = 0;

    /**
    *
    * <br><b>Role</b>: Sets a flag to indicate that the list will add a lot of items.
    * 
    * @return
    * <dl>
    * <dt><code>S_OK</code> <dd>
    * <dt><code>E_FAIL</code> <dd>
    * </dl>
    */
    virtual HRESULT BeginAdding() = 0;

    /**
    *
    * <br><b>Role</b>: Add A list item.
    * This is a simplified service of CATICAfrComponent::AddElement
    * Here is an example how you can use it
    * <code>
    *   CATAfrPropertyBundle bundle;
    *   bundle.PutObject("IconPixelImage",new CATPixelImage(...));
    *   bundle.PutCATString("Name","MyName");
    *   bundle.PutCATUnicodeString("Display","MyTitle");   
    *   bundle.PutInt("Visibility",0);   
    *   piList->AddListItem("MyId",&bundle);
    *</code>
    * @param iName the identifier the item of list.
    * 
    * @param ipBundle the bundle that allows to fill properties of the list Item. <br/>
    * You can choice between thes folowing properties:
    *<code>
    * bundle.PutCATUnicodeString("Display","MyDisplay");
    * bundle.PutCATUnicodeString("Icon","MyIcon");
    * bundle.PutCATUnicodeString("Thumbnail","MyThumbnail");
    * bundle.PutCATUnicodeString("TileIcon","MyTileIcon");
    * bundle.PutCATUnicodeString("Description","MyDescription");
    * bundle.PutCATUnicodeString("TileInfo","MyTileInfo");
    * bundle.PutCATUnicodeString("Url","MyUrl");
    * bundle.PutInt("SelectedFlag",MySelectedFlag);
    * bundle.PutObject("ShadingColor",CATBoxingOfCATAfrColor::Box(MyShadingColor));
    * bundle.PutObject("IconPixelImage",MyIconPixelImage);
    * bundle.PutObject("ThumbPixelImage",MyThumbPixelImage);
    * bundle.PutObject("TilePixelImage",MyTilePixelImage);
    * bundle.PutObject("Rep3D",MyRep3D);
    * bundle.PutObject("DataModel",MyDataModel);
    *</code>
    * 
    * @return
    * <dl>
    * <dt><code>S_OK</code> <dd>
    * <dt><code>E_FAIL</code> <dd>
    * </dl>
    */
    virtual HRESULT AddListItem( const CATString & iName, CATAfrPropertyBundle * ipBundle) = 0;


    /**
    *
    * <br><b>Role</b>: Sets a flag to indicate that the list has finish 
    *  to add elements after the previous call of BegingAdding().
    * This call will be refresh the list view.
    * 
    * @return
    * <dl>
    * <dt><code>S_OK</code> <dd>
    * <dt><code>E_FAIL</code> <dd>
    * </dl>
    */
    virtual HRESULT EndAdding( const CATBoolean& iRefreshView = TRUE ) = 0;

    /**
    * Sets the list of selected items.
    *
    * @param ispList the list of selected items.
    * @param iNotif notification fire
    */
    virtual HRESULT SetSelected( const CATListOfInt& iListIndex, 
                                 const int& iNotif = 1 ) = 0;

    /**
    * Gets the list of selected items.
    *
    * @param ospList the list of selected items.
    * @param oNotif notification fire
    */
    virtual HRESULT GetSelected( CATListOfInt& oListIndex, int& oNotif ) = 0;

    /**
     * Sets the ids and the alias of the attributes for CATVIAFrameViewDetails mode.
     *   @param iAttrListIds attributes Id
     *   @param iAttrListTitles attributes Alias
     *   @param iAttrListRepType attributes representation type(Default, MultiList_Icon_Name, AfrColor,...)
     *   @param iAttrListType attributes type(int, CATUnicodeString,...), 
     *   @param iAttrListTypeReadWrite attributes type read or write
     */
    virtual HRESULT SetHeadersTitles( const CATListValCATString& iAttrListIds, 
                                      const CATListValCATUnicodeString & iAttrListTitles, 
                                      const CATListValCATString& iAttrListRepType, 
                                      const CATListValCATUnicodeString & iAttrListType = CATListValCATUnicodeString(), 
                                      const CATRawCollint & iAttrListTypeReadWrite = CATRawCollint(), 
                                      const CATListValCATString& iHiddenAttrListIds = CATListValCATString() ) = 0;

    /**
     * Gets the ids and the alias of the attributes for multi list view mode.
     *   @param oAttrListIds attributes Id
     *   @param oAttrListTitles attributes Alias
     *   @param oHiddenAttrListIds hidden attributes
     */
    virtual HRESULT GetHeadersTitles( CATListValCATString& oAttrListIds, 
                                      CATListValCATUnicodeString & oAttrListTitles, 
                                      CATListValCATString& oHiddenAttrListIds ) = 0;

    /**
    * Sets the flag to activate or not the multi list view mode model
    * 
    * @param i_Flag flag to activate or not.
    *
    */
    virtual void SetMultiListFlag( const CATBoolean& i_Flag ) = 0;

};
CATDeclareHandler( CATICAfrList, CATICAfrComponent );
#endif
