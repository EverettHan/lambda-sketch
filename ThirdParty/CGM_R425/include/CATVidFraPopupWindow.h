#ifndef CATVidFraPopupWindow_H
#define CATVidFraPopupWindow_H

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>
#include <CATVidInformation.h>

// System framework
#include <CATBaseUnknown_WR.h>
#include <CATUnicodeString.h>
#include <CATBoolean.h>

// UIVCoreTools
#include <CATSYPEvent.h>

class CATSYPEventArgs;

class CATVidCtlPopup;
class CATVidWidget;
class CATVidFraPopupWindowConstraints;

/** 
* @ingroup VIDFrame
* The window used to display the content of a @ref CATVidCtlPopup.
*
* The popup is accessible through the @ref #GetPopup function.
*/
class ExportedByVisuDialog CATVidFraPopupWindow : public CATVidFraWindow
{
    CATDeclareClass;

public:

    /** 
    * Initialize this class 
    *
    * @param i_pParent the CATCommand parent; can be @c NULL.
    *
    * @param i_pIdentifier the name of the CATCommand.
    *
    * @param i_pPopup the popup whose content is displayed with this
    * window; can't be @c NULL.
    */
    CATVidFraPopupWindow(
        CATCommand * i_pParent, 
        const CATString & i_pIdentifier, 
        CATVidCtlPopup * i_pPopup,
        const CATUnicodeString& i_look);

    /** 
    * Initialize this class 
    *
    * @param i_pWidget the widget whose content is displayed with this
    * window.
    */
    CATVidFraPopupWindow(CATVidWidget *i_pWidget,
                         const CATString & i_pIdentifier,
                         const CATUnicodeString& i_look);

    virtual void RequestDelayedDestruction();


    /**
    * Default constructor 
    */
    CATVidFraPopupWindow();

    /** 
    * Get the popup represented by this window.
    *
    * @return the popup. @c NULL if it has already been destroyed.
    */
    CATVidCtlPopup *GetPopup();

    /** 
    * Get the popup or widget that display this popup window.
    *
    * @return the widget. @c NULL if it has already been destroyed.
    */
    CATVidWidget* GetPopupOwner();

    /**
    *  Get only the widget that is associated to the popup window
    * @return the widget. @c NULL if the popup window is not assiated to a widget.
    */
    CATVidWidget* GetWidget();
    
    /** 
    * Set the widget that display this popup window.
    *
    * @param i_pOwner : popup window owner
    */
    void SetPopupOwner(CATVidWidget* i_pOwner, CATBoolean i_listenToOwnerPosition);

    /**
    * @returns window presenter content.
    */
    CATVidWidget* GetHandledWidget() const;
   
    /**
    * Gets popup window behavior constraints
    * @see CATVidFraPopupWindowConstraints
    */
    CATVidFraPopupWindowConstraints& GetConstraints();

    /**
    * Sets popup window behavior constraints
    * @see CATVidFraPopupWindowConstraints
    */
    void SetConstraints(CATVidFraPopupWindowConstraints& i_constraints);

    CATVid::Side GetSnapSide() const;

    /**
    * close popup window
    */
    void
    AutoClose();

    /**
    * Set fra poup window properties
    */
    void SetProperties(const CATUnicodeString& i_look);
    
    /**
    * build fra popup window
    */
    /*virtual void Build();*/

    /** @copydoc CATVidFraPopupWindowConstraints#GetOffsetPosition */
    //CATMathPoint2Df GetOffset() const;
    /** @copydoc CATVidFraPopupWindowConstraints#SetOffsetPosition */
   /* void SetOffset(CATMathPoint2Df i_offset);*/

  /** 
   * Get the @c AutoClosed event. 
   *
   * @par
   * This event is emitted on auto-close.
   * 
   * @par EventProperties
   *   @li Name: @c "AutoClosed"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   */
  static CATSYPEvent * AutoClosed();

  void ClosePopupCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

protected:
    virtual ~CATVidFraPopupWindow();

    // Write/Read the window Preferences
    virtual void WriteWindowPreferences();
    virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);

private:

    CATVidFraPopupWindow(const CATVidFraPopupWindow &);
    CATVidFraPopupWindow &operator=(const CATVidFraPopupWindow &);

    /**Ensure that window constraints are up to date while the class that contain constraints is modified*/
    void ConnectConstraints();

    /** a weak reference on the popup represented by this window */
    CATBaseUnknown_WR _wrPopup;
    
    /** a weak reference on the widget related to this popup window */
    CATBaseUnknown_WR _wrWidget;
    /**placement constraints of this popup window according to the related widget that display it*/
    CATVidFraPopupWindowConstraints* _pConstraints;
};

#endif // CATVidFraPopupWindow_H
 
 
 
