
#ifndef CATIAfrVIAImmersiveView_H
#define CATIAfrVIAImmersiveView_H

// COPYRIGHT DASSAULT SYSTEMES 2011/12/01

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATICAfrComponent;

extern ExportedByCATAfrItf  IID IID_CATIAfrVIAImmersiveView ;

typedef CATULONG64 CAfrVIAImmersiveViewStyle;

#define SingleSelection    (1 << 1)  // For putting mono selection
#define WithCtxMenu        (1 << 2)  // With contextual Menu
#define TooltipView        (1 << 3)  // With tooltip view
#define AutoSizeWithHeader (1 << 4)  // Use to include column title in column auto-sizing 
#define Sortable           (1 << 5)  // Use to allow sort model by PLM_ExternalId
#define WithoutNumber      (1 << 6)  // Use to not display the number of lines
#define NoEditor           (1 << 7) // Use without editor
#define Filter             (1 << 8) // Use filter in detail view
#define Floating           (1 << 9) // Floating
#define WithBubble         (1 << 10) // With Bubble view
#define WithoutDetails     (1 << 11) // Without Details view.
#define WithoutThumb       (1 << 12) // Without thumbnails view
#define WithoutTiles       (1 << 13) // Without tiles view
#define WithoutF2Tree      (1 << 14) // Without tree view modification
#define WithoutTree        (1 << 15) // Without Tree view
#define WithoutF2Thumb     (1 << 16) // Without thumbnails view modification
#define VID                (1 << 17) // Use to display view in Immsersive dialog
#define VIDBottom          (1 << 18) // Use to display view in Immsersive dialog in bottom
#define VIDLeft            (1 << 19) // Use to display view in Immsersive dialog in left
#define VIDDialog          (1 << 20) // Use to display view in Immsersive dialog
#define BottomDockable     (1 << 21) // Bottom dockable
#define VIDDlg             (1 << 22)  // Use to display view in Immsersive dialog with dialog
#define VIDDlgExtract      (1 << 23)  // Use to display view in Immsersive dialog with dialog directly extract
#define VIDTop             (1 << 24) // Use to display view in Immsersive dialog in top

#ifdef _WINDOWS_SOURCE
#define NoThumbInTooltip            (((CAfrVIAImmersiveViewStyle)1) << 32) // Don't display the thumbnail in tooltip view
#define WithoutAutoRefresh          (((CAfrVIAImmersiveViewStyle)1) << 33) // Without refresh of result view when tree node is selected
#define VIDHTMLView                 (((CAfrVIAImmersiveViewStyle)1) << 34) // Create a VID with the htmlview
#define NoToolbar                   (((CAfrVIAImmersiveViewStyle)1) << 35) // No Toolbar
#define NoColumnsCustomization      (((CAfrVIAImmersiveViewStyle)1) << 36) // Use to not add the columns customization
#define VidFraPanelLeftDockArea     (((CAfrVIAImmersiveViewStyle)1) << 37) // Use to allow to dock on left
#define VidFraPanelRightDockArea    (((CAfrVIAImmersiveViewStyle)1) << 38) // Use to allow to dock on Right
#define VidFraPanelTopDockArea      (((CAfrVIAImmersiveViewStyle)1) << 39) // Use to allow to dock on Top
#define VidFraPanelBottomDockArea   (((CAfrVIAImmersiveViewStyle)1) << 40) // Use to allow to dock on Bottom
#define VidFraPanelAllDockArea      (((CAfrVIAImmersiveViewStyle)1) << 41) // Use to allow to dock on all area
#define ExpanderExclusiveFlag       (((CAfrVIAImmersiveViewStyle)1) << 42) // Use Expander Exclusive in Multi Zone
#define ThumbnailChannel            (((CAfrVIAImmersiveViewStyle)1) << 43) // Use Expander Exclusive in Multi Zone
#define CAfrComponent               (((CAfrVIAImmersiveViewStyle)1) << 44) // Use to have C-Afr component management display
#define NoListHeaderFullWidth       (((CAfrVIAImmersiveViewStyle)1) << 45) // Use to have ListView look ListHeaderFullWidth
#define PanelNoCloseButton          (((CAfrVIAImmersiveViewStyle)1) << 46) // Use to have No close button on panel
#define IFWESearchSignature         (((CAfrVIAImmersiveViewStyle)1) << 47) // Use specialy for Search Signature
#define IFWESearchSignatureWithoutTab (((CAfrVIAImmersiveViewStyle)1) << 48) // Use specialy for Search Signature witout tabpage
#define DragAuthorized              (((CAfrVIAImmersiveViewStyle)1) << 49) // Use specialy to allow to Drag
#define DropAuthorized              (((CAfrVIAImmersiveViewStyle)1) << 50) // Use specialy to allow to Drop
#define AutoAddIndex                (((CAfrVIAImmersiveViewStyle)1) << 51) // Use specialy to automatic add index
#define NoAutoActivation            (((CAfrVIAImmersiveViewStyle)1) << 52) // Use specialy for no automatic activation
#define DetailsViewInCID            (((CAfrVIAImmersiveViewStyle)1) << 53) // Use specialy for to have detail view in CID
#define WebRepresesentation         (((CAfrVIAImmersiveViewStyle)1) << 54) // Use specialy for to have web representation
#define CtxMenuInCID                (((CAfrVIAImmersiveViewStyle)1) << 55) // Use specialy to have ctx menu in cid
#else
#define NoThumbInTooltip            (1LL << 32)
#define WithoutAutoRefresh          (1LL << 33)
#define VIDHTMLView                 (1LL << 34)
#define NoToolbar                   (1LL << 35)
#define NoColumnsCustomization      (1LL << 36)
#define VidFraPanelLeftDockArea     (1LL << 37)
#define VidFraPanelRightDockArea    (1LL << 38)
#define VidFraPanelTopDockArea      (1LL << 39)
#define VidFraPanelBottomDockArea   (1LL << 40)
#define VidFraPanelAllDockArea      (1LL << 41)
#define ExpanderExclusiveFlag       (1LL << 42)
#define ThumbnailChannel            (1LL << 43)
#define CAfrComponent               (1LL << 44)
#define NoListHeaderFullWidth       (1LL << 45)
#define PanelNoCloseButton          (1LL << 46)
#define IFWESearchSignature         (1LL << 47)
#define IFWESearchSignatureWithoutTab (1LL << 48)
#define DragAuthorized              (1LL << 49)
#define DropAuthorized              (1LL << 50)
#define AutoAddIndex                (1LL << 51)
#define NoAutoActivation            (1LL << 52)
#define DetailsViewInCID            (1LL << 53)
#define WebRepresesentation         (1LL << 54)
#define CtxMenuInCID                (1LL << 55)

#endif

//-----------------------------------------------------------------------------
/**
* Interface representing a VIAImmersiveView.
*/
class ExportedByCATAfrItf CATIAfrVIAImmersiveView: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * @return the Title
    */
    virtual const CATUnicodeString& GetTitle() const = 0;

    /**
    * @return the Icon name
    */
    virtual const CATUnicodeString& GetIcon( ) const = 0;

    /**
    * @return the component see the interface VIAImmersiveViewInterfaces\ProtectedInterfaces\CATIVIATreeViewFrame.h
    *  The created element [out, CATBaseUnknown#Addref not be done]
    */
    virtual CATBaseUnknown* GetComponent( ) const = 0;

    /**
    * @return the component Left user toolbar component
    *  The created element [out, CATICAfrComponent#Addref be done]
    */
    virtual HRESULT GetLeftUserCAfrToolbarComponent( CATICAfrComponent** opiCAfrComponent ) = 0;

    /**
    * @return the styles
    *   <br>
    * The style of the component
    */
    virtual HRESULT GetStyle( CAfrVIAImmersiveViewStyle& oViewStyle ) = 0;

};
#endif
