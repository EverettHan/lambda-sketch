#ifndef CATDLGNOTIFICATION
#define CATDLGNOTIFICATION

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "DI0PANV2.h"
#include "CATDlgUtility.h"
#include "CATNotification.h"
class CATDialog;


/** 
 * Class to notify a dialog object visibility change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever the object visibility is modified.
 */
class ExportedByDI0PANV2 CATDlgVisibilityNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgVisibilityNotification object. 
 */   
    CATDlgVisibilityNotification();

    virtual ~CATDlgVisibilityNotification();

};

/** 
 * Class to notify a dialog object creation.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog when the object is created.
 */
class ExportedByDI0PANV2 CATDlgCreateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgCreateNotification object. 
 */   
    CATDlgCreateNotification();

    virtual ~CATDlgCreateNotification();

};

/** 
 * Class to notify a dialog object size change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever the object is resized.
 */
class ExportedByDI0PANV2 CATDlgResizeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgResizeNotification object. 
 */   
    CATDlgResizeNotification();

    virtual ~CATDlgResizeNotification();

};

/** 
 * Class to notify a dialog object selection by the What's This command.
 * <b>Role</b>:
 * This event notification is sent by :
 * <MENU>
 * <LI>@href CATDialog whenever the object is selected using the What's This command,
 * <LI>@href CATDlgDialog and @href CATDlgFile whenever the Help push button is pressed.
 * </MENU>
 */
class ExportedByDI0PANV2 CATDlgHelpNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgHelpNotification object. 
 */   
    CATDlgHelpNotification();

    virtual ~CATDlgHelpNotification();

};

/** 
 * Class to notify a dialog window object size change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgWindow when the window is resized.
 */
class ExportedByDI0PANV2 CATDlgWindSizeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgWindSizeNotification object. 
 */   
    CATDlgWindSizeNotification();

    virtual ~CATDlgWindSizeNotification();

};

/** 
 * Class to notify a dialog window object closing.
 * <b>Role</b>:
 * This event notification is sent by
 * <MENU> 
 * <LI>@href CATDlgWindow when the window is closed,
 * <LI>@href CATDlgToolBar whenever the end user closes the toolbar window when it is undocked.
 * </MENU>
 */
class ExportedByDI0PANV2 CATDlgWindCloseNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgWindCloseNotification object. 
 */   
    CATDlgWindCloseNotification();

    virtual ~CATDlgWindCloseNotification();

};

/** 
 * Class to notify a dialog window object moving.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgWindow when the window is moved.
 */
class ExportedByDI0PANV2 CATDlgWindMoveNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgWindMoveNotification object. 
 */   
    CATDlgWindMoveNotification();

    virtual ~CATDlgWindMoveNotification();

};

/** 
 * Class to notify a dialog window object being maximized.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgWindow when the window is maximized.
 */
class ExportedByDI0PANV2 CATDlgWindMaximizeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgWindMaximizeNotification object. 
 */   
    CATDlgWindMaximizeNotification();

    virtual ~CATDlgWindMaximizeNotification();

};

/** 
 * Class to notify a dialog window object being restored.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgWindow when the window is restored to its previous size after being minimized or maximized.
 */
class ExportedByDI0PANV2 CATDlgWindRestoreNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgWindRestoreNotification object. 
 */   
    CATDlgWindRestoreNotification();

    virtual ~CATDlgWindRestoreNotification();

};

/** 
 * Class to notify a dialog window object being minimized.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgWindow when the window is minimized.
 */
class ExportedByDI0PANV2 CATDlgWindMinimizeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgWindMinimizeNotification object. 
 */   
    CATDlgWindMinimizeNotification();

    virtual ~CATDlgWindMinimizeNotification();

};

/** 
 * Class to notify a dialog object attachment change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgToolBar whenever the end user modifies the toolbar attachment.
 */
class ExportedByDI0PANV2 CATDlgWindDockNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgWindDockNotification object. 
 */   
    CATDlgWindDockNotification();

    virtual ~CATDlgWindDockNotification();

};

/** 
 * Class representing an event notification sent when the OK push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog and @href CATDlgFile whenever the OK push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaOKNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaOKNotification object. 
 */   
    CATDlgDiaOKNotification();

    virtual ~CATDlgDiaOKNotification();

};

/** 
 * Class representing an event notification sent when the Cancel push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog and @href CATDlgFile whenever the Cancel push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaCANCELNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaCANCELNotification object. 
 */   
    CATDlgDiaCANCELNotification();

    virtual ~CATDlgDiaCANCELNotification();

};

/** 
 * Class representing an event notification sent when the Preview push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the Preview push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaPREVIEWNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaPREVIEWNotification object. 
 */   
    CATDlgDiaPREVIEWNotification();

    virtual ~CATDlgDiaPREVIEWNotification();

};

/** 
 * Class representing an event notification sent when the Apply push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog and @href CATDlgFile whenever the Apply push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaAPPLYNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaAPPLYNotification object. 
 */   
    CATDlgDiaAPPLYNotification();

    virtual ~CATDlgDiaAPPLYNotification();

};

/** 
 * Class representing an event notification sent when the Close push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the Close push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaCLOSENotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaCLOSENotification object. 
 */   
    CATDlgDiaCLOSENotification();

    virtual ~CATDlgDiaCLOSENotification();

};

/** 
 * Class representing an event notification sent when the Help push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog and @href CATDlgFile whenever the Help push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaHELPNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaHELPNotification object. 
 */   
    CATDlgDiaHELPNotification();

    virtual ~CATDlgDiaHELPNotification();

};

/** 
 * Class representing an event notification sent when the PREVIOUS push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the PREVIOUS push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaPREVIOUSNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaPREVIOUSNotification object. 
 */   
    CATDlgDiaPREVIOUSNotification();

    virtual ~CATDlgDiaPREVIOUSNotification();

};

/** 
 * Class representing an event notification sent when the NEXT push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the NEXT push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaNEXTNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaNEXTNotification object. 
 */   
    CATDlgDiaNEXTNotification();

    virtual ~CATDlgDiaNEXTNotification();

};

/** 
 * Class representing an event notification sent when the FINISH push button is pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the FINISH push button is pressed.
 */
class ExportedByDI0PANV2 CATDlgDiaFINISHNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDiaFINISHNotification object. 
 */   
    CATDlgDiaFINISHNotification();

    virtual ~CATDlgDiaFINISHNotification();

};

/** 
 * Class to notify a check button state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCheckButton whenever the check button is checked or unchecked.
 */
class ExportedByDI0PANV2 CATDlgChkBModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgChkBModifyNotification object. 
 */   
    CATDlgChkBModifyNotification();

    virtual ~CATDlgChkBModifyNotification();

};

/** 
 * Class to notify a check button being double clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCheckButton whenever the check button is double clicked. 
 * The expected behavior is to loop on the associated command.
 */
class ExportedByDI0PANV2 CATDlgChkBDoubleClickNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgChkBDoubleClickNotification object. 
 */   
    CATDlgChkBDoubleClickNotification();

    virtual ~CATDlgChkBDoubleClickNotification();

};

/** 
 * Class to notify a check item state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCheckItem whenever the check item is checked or unchecked.
 */
class ExportedByDI0PANV2 CATDlgChkIModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgChkIModifyNotification object. 
 */   
    CATDlgChkIModifyNotification();

    virtual ~CATDlgChkIModifyNotification();

};

/** 
 * Class to notify a combo list selection.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCombo whenever a value is selected in the list.
 */
class ExportedByDI0PANV2 CATDlgComboSelectNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgComboSelectNotification object. 
 */   
    CATDlgComboSelectNotification();

    virtual ~CATDlgComboSelectNotification();

};

/** 
 * Class to notify a combo entry change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCombo whenever the keyboard entry is modified by selection.
 */
class ExportedByDI0PANV2 CATDlgComboModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgComboModifyNotification object. 
 */   
    CATDlgComboModifyNotification();

    virtual ~CATDlgComboModifyNotification();

};

/** 
 * Class to notify a combo entry change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCombo whenever the keyboard entry is modified by pressing the "Enter" key.
 */
class ExportedByDI0PANV2 CATDlgComboModifyExtNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgComboModifyExtNotification object. 
 */   
    CATDlgComboModifyExtNotification();

    virtual ~CATDlgComboModifyExtNotification();

};

/** 
 * Class to notify a combo list display.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCombo whenever the list of values is displayed.
 * Available with CATDlgCmbEntry only.
 */
class ExportedByDI0PANV2 CATDlgComboDropNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgComboDropNotification object. 
 */   
    CATDlgComboDropNotification();

    virtual ~CATDlgComboDropNotification();
};

/** 
 * Class to notify a combo list concealing.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCombo whenever the list of values gets hidden.
 * Available with CATDlgCmbEntry only.
 */
class ExportedByDI0PANV2 CATDlgComboCloseUpNotification : public CATNotification
{

 CATDeclareClass;
 public:
/**
 * Constructs a CATDlgComboCloseUpNotification object. 
 */
    CATDlgComboCloseUpNotification();

    virtual ~CATDlgComboCloseUpNotification();

};

/** 
 * @nodoc
 * Class to notify a combo is clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgCombo whenever it is clicked.
 */
class ExportedByDI0PANV2 CATDlgComboSingleClickNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgComboSingleClickNotification object. 
 */   
    CATDlgComboSingleClickNotification();

    virtual ~CATDlgComboSingleClickNotification();

};

/** 
 * Class to notify a dialog object's entry field change.
 * <b>Role</b>:
 * This event notification is sent by :
 * <MENU>
 * <LI>@href CATDlgEditor whenever the entry field is modified,
 * <LI>@href CATDlgStatusBar whenever the end user edits the PowerInput entry field,
 * <LI>@href CATDlgCombo whenever the keyboard entry is modified by editing.
 * </MENU>
 */
class ExportedByDI0PANV2 CATDlgEditModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgEditModifyNotification object. 
 */   
    CATDlgEditModifyNotification();

    virtual ~CATDlgEditModifyNotification();

};

/** 
 * Class to notify a dialog object's entry field change.
 * <b>Role</b>:
 * This event notification is sent by :
 * <MENU>
 * <LI>@href CATDlgEditor whenever the entry field is modified. (key "Enter" is pressed).
 * </MENU>
 */
class ExportedByDI0PANV2 CATDlgEditModifyExtNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgEditModifyExtNotification object. 
 */   
    CATDlgEditModifyExtNotification();

    virtual ~CATDlgEditModifyExtNotification();

};

/** 
 * Class to notify a dialog object gaining the keyboard focus .
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgEditor whenever it gets the keyboard focus.
 */
class ExportedByDI0PANV2 CATDlgEditFocusInNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgEditFocusInNotification object. 
 */   
    CATDlgEditFocusInNotification();

    virtual ~CATDlgEditFocusInNotification();

};

/** 
 * Class to notify a dialog object losing the keyboard focus.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgEditor whenever it lost the keyboard focus.
 */
class ExportedByDI0PANV2 CATDlgEditFocusOutNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgEditFocusOutNotification object. 
 */   
    CATDlgEditFocusOutNotification();

    virtual ~CATDlgEditFocusOutNotification();

};

/** 
 * Class to notify a dialog object's entry field selection change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgEditor whenever the selection in entry field is changed.
 */
class ExportedByDI0PANV2 CATDlgSelectionChangeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgSelectionChangeNotification object. 
 */   
    CATDlgSelectionChangeNotification();

    virtual ~CATDlgSelectionChangeNotification();

};

/** 
 * Class to notify a dialog file object's file selection.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgFile whenever a file is selected.
 */
class ExportedByDI0PANV2 CATDlgFileSelectNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgFileSelectNotification object. 
 */   
    CATDlgFileSelectNotification();

    virtual ~CATDlgFileSelectNotification();

};

/** 
 * Class to notify a dialog list object's line selection.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgMultiList and @href CATDlgSelectorList whenever a line is selected.
 */
class ExportedByDI0PANV2 CATDlgListSelectNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgListSelectNotification object. 
 */   
    CATDlgListSelectNotification();

    virtual ~CATDlgListSelectNotification();

};

/** 
 * Class to notify a dialog list object's line being double clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgMultiList and @href CATDlgSelectorList whenever a line is double clicked.
 */
class ExportedByDI0PANV2 CATDlgListActivateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgListActivateNotification object. 
 */   
    CATDlgListActivateNotification();

    virtual ~CATDlgListActivateNotification();

};

/** 
 * @nodoc
 * Class to notify a dialog list object is clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgMultiList and @href CATDlgSelectorList whenever it is clicked.
 */
class ExportedByDI0PANV2 CATDlgListSingleClickNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgListSingleClickNotification object. 
 */   
    CATDlgListSingleClickNotification();

    virtual ~CATDlgListSingleClickNotification();

};

/** 
 * Class to notify a dialog list object's column header being activated.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgMultiList whenever a column header is activated.
 */
class ExportedByDI0PANV2 CATDlgListColumnActivateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgListColumnActivateNotification object. 
 */   
    CATDlgListColumnActivateNotification();

    virtual ~CATDlgListColumnActivateNotification();

};

/** 
 * Class to notify a dialog list object's cell content change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgMultiList whenever a cell content is modified.
 */
class ExportedByDI0PANV2 CATDlgListCellModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgListCellModifyNotification object. 
 */   
    CATDlgListCellModifyNotification();

    virtual ~CATDlgListCellModifyNotification();

};

/** 
 * @nodoc
 * Internal Use. Sent by CATDlgMultiList and CATDlgSelectorList 
 */
class ExportedByDI0PANV2 CATDlgListContextualLineNotification : public CATNotification
{

 CATDeclareClass;
 public:

    CATDlgListContextualLineNotification();

    virtual ~CATDlgListContextualLineNotification();

};

/** 
 * Class to notify a push button being clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgPushButton whenever the push button is clicked,
 */
class ExportedByDI0PANV2 CATDlgPushBActivateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgPushBActivateNotification object. 
 */   
    CATDlgPushBActivateNotification();

    virtual ~CATDlgPushBActivateNotification();

};

/** 
 * Class to notify a push button being maintained pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgPushButton as long as the push button is maintained pressed if its style is set to CATDlgPusRepetitive,
 */
class ExportedByDI0PANV2 CATDlgPushBRepetitiveNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgPushBRepetitiveNotification object. 
 */   
    CATDlgPushBRepetitiveNotification();

    virtual ~CATDlgPushBRepetitiveNotification();

};

/** 
 * Class to notify a push item being clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgPushItem whenever the push item is clicked.
 */
class ExportedByDI0PANV2 CATDlgMenuIActivateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMenuIActivateNotification object. 
 */   
    CATDlgMenuIActivateNotification();

    virtual ~CATDlgMenuIActivateNotification();

};

/** 
 * Class to notify a radio button state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgRadioButton whenever the radio button is checked or unchecked.
 */
class ExportedByDI0PANV2 CATDlgRadBModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgRadBModifyNotification object. 
 */   
    CATDlgRadBModifyNotification();

    virtual ~CATDlgRadBModifyNotification();

};

/** 
 * Class to notify a radio item state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgRadioItem whenever the radio item is checked or unchecked.
 */
class ExportedByDI0PANV2 CATDlgRadIModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgRadIModifyNotification object. 
 */   
    CATDlgRadIModifyNotification();

    virtual ~CATDlgRadIModifyNotification();

};

/** 
 * Class to notify a scrollbar state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgScrollBar whenever the scroll arrows or the shaft is clicked.
 */
class ExportedByDI0PANV2 CATDlgScrollBarModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgScrollBarModifyNotification object. 
 */   
    CATDlgScrollBarModifyNotification();

    virtual ~CATDlgScrollBarModifyNotification();

};

/** 
 * Class to notify a scrollbar being dragged.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgScrollBar whenever the scroll box is dragged.
 */
class ExportedByDI0PANV2 CATDlgScrollBarDragNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgScrollBarDragNotification object. 
 */   
    CATDlgScrollBarDragNotification();

    virtual ~CATDlgScrollBarDragNotification();

};

/** 
 * Class to notify a slider state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgSlider whenever the end user clicks 
 * in the scrollable field. If the click is right or above the slider, the value 
 * increments of one step, and decrements of one step otherwise. The end user can 
 * press the left mouse key continuously and then the current value increments or 
 * decrements accordingly as long as the left mouse key is pressed, or the start 
 * or end value is reached. 
 */
class ExportedByDI0PANV2 CATDlgSliderModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgSliderModifyNotification object. 
 */   
    CATDlgSliderModifyNotification();

    virtual ~CATDlgSliderModifyNotification();

};

/** 
 * Class to notify a slider being dragged.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgSlider as long as the slider is dragged.
 */
class ExportedByDI0PANV2 CATDlgSliderDragNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgSliderDragNotification object. 
 */   
    CATDlgSliderDragNotification();

    virtual ~CATDlgSliderDragNotification();

};

/** 
 * Class to notify a spinner state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgSpinner whenever the current value is modified, 
 * whatever the means used to modify it, such as arrows or field edition.
 * Available with CATDlgSpnUserIncrement only.
 */
class ExportedByDI0PANV2 CATDlgSpinnerModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgSpinnerModifyNotification object. 
 */   
    CATDlgSpinnerModifyNotification();

    virtual ~CATDlgSpinnerModifyNotification();

};

/** 
 * Class to notify a spinner's up arrow being clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgSpinner whenever the up (increment) arrow is clicked.
 */
class ExportedByDI0PANV2 CATDlgSpinnerBtnUpNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgSpinnerBtnUpNotification object. 
 */   
    CATDlgSpinnerBtnUpNotification();

    virtual ~CATDlgSpinnerBtnUpNotification();

};

/** 
 * Class to notify a spinner's down arrow being clicked.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgSpinner whenever the down (decrement) arrow is clicked.
 */
class ExportedByDI0PANV2 CATDlgSpinnerBtnDownNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgSpinnerBtnDownNotification object. 
 */   
    CATDlgSpinnerBtnDownNotification();

    virtual ~CATDlgSpinnerBtnDownNotification();

};

/** 
 * Class to notify the drop of an object in a document window.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDocument whenever the end user drops an object in a document window.
 */
class ExportedByDI0PANV2 CATDlgDroppedFileNotification : public CATNotification
{

 CATDeclareClass;
 friend class l_CATDlgDocument;
 public:

/**
 * Constructs a CATDlgDroppedFileNotification object. 
 */   
    CATDlgDroppedFileNotification();

    virtual ~CATDlgDroppedFileNotification();

/**
 * Gives access to the path of the file which has been dropped.
 */ 
    const CATUnicodeString& GetDroppedFile();

    /** 
    * @nodoc
    */
    CATString DroppedFile;

 private :
    CATUnicodeString _droppedFile;
};

/** 
 * Class representing an event notification sent by CATDlgDocument.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDocument whenever the end user clicks on the logo.
 */
class ExportedByDI0PANV2 CATDlgDSLogoNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDSLogoNotification object. 
 */   
    CATDlgDSLogoNotification();

    virtual ~CATDlgDSLogoNotification();

};

/** 
 * Class representing an event notification sent by CATDlgDocument.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDocument.
 */
class ExportedByDI0PANV2 CATDlgEscapeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgEscapeNotification object. 
 */   
    CATDlgEscapeNotification();

    virtual ~CATDlgEscapeNotification();

};

/** 
 * Class to notify an icon selection in an icon box.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgIconBox whenever an icon is selected in the icon box.
 */
class ExportedByDI0PANV2 CATDlgIconBoxSelectNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgIconBoxSelectNotification object. 
 */   
    CATDlgIconBoxSelectNotification();

    virtual ~CATDlgIconBoxSelectNotification();

};

/** 
 * Class to notify an icon box state change.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgIconBox whenever the icon displayed as the icon box is selected.
 */
class ExportedByDI0PANV2 CATDlgIconBoxModifyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgIconBoxModifyNotification object. 
 */   
    CATDlgIconBoxModifyNotification();

    virtual ~CATDlgIconBoxModifyNotification();

};

/** 
 * Class to notify a dialog tab object selection.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgTabContainer whenever a tab is selected.
 */
class ExportedByDI0PANV2 CATDlgTabSelectNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgTabSelectNotification object. 
 */   
    CATDlgTabSelectNotification();

    virtual ~CATDlgTabSelectNotification();

};

/** 
 * Class to notify a dialog window object being restored.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the dialog window is restored.
 */
class ExportedByDI0PANV2 CATDlgMDIRestoreNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMDIRestoreNotification object. 
 */   
    CATDlgMDIRestoreNotification();

    virtual ~CATDlgMDIRestoreNotification();

};

/** 
 * Class to notify a dialog window object being minimized.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the dialog window is minimized.
 */
class ExportedByDI0PANV2 CATDlgMDIMinimizeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMDIMinimizeNotification object. 
 */   
    CATDlgMDIMinimizeNotification();

    virtual ~CATDlgMDIMinimizeNotification();

};

/** 
 * Class to notify a dialog window object being maximized.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the dialog window is maximized.
 */
class ExportedByDI0PANV2 CATDlgMDIMaximizeNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMDIMaximizeNotification object. 
 */   
    CATDlgMDIMaximizeNotification();

    virtual ~CATDlgMDIMaximizeNotification();

};

/** 
 * Class to notify a dialog window object being closed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the dialog window is closed.
 */
class ExportedByDI0PANV2 CATDlgMDICloseNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMDICloseNotification object. 
 */   
    CATDlgMDICloseNotification();

    virtual ~CATDlgMDICloseNotification();

};

/** 
 * Class to notify a dialog window object being activated as the next of the current one.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the dialog window is activated as the next of the current one.
 */
class ExportedByDI0PANV2 CATDlgMDINextNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMDINextNotification object. 
 */   
    CATDlgMDINextNotification();

    virtual ~CATDlgMDINextNotification();

};

/** 
 * Class to notify a dialog window object being activated as the previous of the current one.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the dialog window is activated as the previous of the current one.
 */
class ExportedByDI0PANV2 CATDlgMDIPreviousNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMDIPreviousNotification object. 
 */   
    CATDlgMDIPreviousNotification();

    virtual ~CATDlgMDIPreviousNotification();

};

/** 
 * Class to notify a dialog window object being activated.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgDialog whenever the dialog window is activated.
 */
class ExportedByDI0PANV2 CATDlgMDIActivateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgMDIActivateNotification object. 
 */   
    CATDlgMDIActivateNotification();

    virtual ~CATDlgMDIActivateNotification();

};

/** 
 * @nodoc
 * Class to notify a mouse drag entering a dialog object.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drag enters the window.
 */
class ExportedByDI0PANV2 CATDlgDragEnterNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDragEnterNotification object. 
 */   
    CATDlgDragEnterNotification();

    virtual ~CATDlgDragEnterNotification();

    CATDialog *SourceDialog, *TargetDialog;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * @nodoc
 * Class to notify a mouse drag rolling over a dialog object.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drag rolls over the window.
 */
class ExportedByDI0PANV2 CATDlgDragOverNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDragOverNotification object. 
 */   
    CATDlgDragOverNotification();

    virtual ~CATDlgDragOverNotification();

    CATDialog *SourceDialog, *TargetDialog;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * @nodoc
 * Class to notify a mouse drag leaving a dialog object.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drag leaves the window.
 */
class ExportedByDI0PANV2 CATDlgDragLeaveNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDragLeaveNotification object. 
 */   
    CATDlgDragLeaveNotification();

    virtual ~CATDlgDragLeaveNotification();

    CATDialog *SourceDialog, *TargetDialog;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * @nodoc
 * Class to notify a mouse drop.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drop happens.
 * This notification is sent by the target of the drag&drop operation.
 */
class ExportedByDI0PANV2 CATDlgDropNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDropNotification object. 
 */   
    CATDlgDropNotification();

    virtual ~CATDlgDropNotification();

    CATDialog *SourceDialog ;
    CATDialog *TargetDialog;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * @nodoc
 * Class to notify a mouse drag beginning.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drag mechanism begins.
 */
class ExportedByDI0PANV2 CATDlgStartDragNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgStartDragNotification object. 
 */   
    CATDlgStartDragNotification();

    virtual ~CATDlgStartDragNotification();

    CATDialog *SourceDialog, *TargetDialog;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * @nodoc
 * Class to notify a mouse drag stopping.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drag mechanism stops.
 */
class ExportedByDI0PANV2 CATDlgCancelDragNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgCancelDragNotification object. 
 */   
    CATDlgCancelDragNotification();

    virtual ~CATDlgCancelDragNotification();

    CATDialog *SourceDialog ;
    CATDialog *TargetDialog ;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * @nodoc
 * Class to notify a mouse drag starting on a button.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drag mechanism starts on a button.
 */
class ExportedByDI0PANV2 CATDlgDragButtonNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDragButtonNotification object. 
 */   
    CATDlgDragButtonNotification();

    virtual ~CATDlgDragButtonNotification();

    CATDialog *SourceDialog, *TargetDialog;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * @nodoc
 * Class to notify a mouse drop.
 * <b>Role</b>:
 * This event notification is sent by @href CATDialog whenever a mouse drop happens.
 * This notification is sent by the source of the drag&drop operation.
 */
class ExportedByDI0PANV2 CATDlgEndDropNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgEndDropNotification object. 
 */   
    CATDlgEndDropNotification();

    virtual ~CATDlgEndDropNotification();

    CATDialog *SourceDialog, *TargetDialog;
    POINTL  CursorPosition;
    DWORD   PossibleEffects;
    DROPEFFECT CurrentEffect;
    DWORD   KeyModifier;
};

/** 
 * Class to notify a dialog object's Abort push button being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgNotify whenever the end user presses the Abort push button.
 */
class ExportedByDI0PANV2 CATDlgNfyAbortNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgNfyAbortNotification object. 
 */   
    CATDlgNfyAbortNotification();

    virtual ~CATDlgNfyAbortNotification();

};

/** 
 * Class to notify a dialog object's Ignore push button being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgNotify whenever the end user presses the Ignore push button.
 */
class ExportedByDI0PANV2 CATDlgNfyIgnoreNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgNfyIgnoreNotification object. 
 */   
    CATDlgNfyIgnoreNotification();

    virtual ~CATDlgNfyIgnoreNotification();

};

/** 
 * Class to notify a dialog object's Retry push button being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgNotify whenever the end user presses the Retry push button.
 */
class ExportedByDI0PANV2 CATDlgNfyRetryNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgNfyRetryNotification object. 
 */   
    CATDlgNfyRetryNotification();

    virtual ~CATDlgNfyRetryNotification();

};

/** 
 * Class to notify a dialog object's OK push button being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgNotify whenever the end user presses the OK push button.
 */
class ExportedByDI0PANV2 CATDlgNfyOKNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgNfyOKNotification object. 
 */   
    CATDlgNfyOKNotification();

    virtual ~CATDlgNfyOKNotification();

};

/** 
 * Class to notify a dialog object's Cancel push button being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgNotify whenever the end user presses the Cancel push button.
 */
class ExportedByDI0PANV2 CATDlgNfyCancelNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgNfyCancelNotification object. 
 */   
    CATDlgNfyCancelNotification();

    virtual ~CATDlgNfyCancelNotification();

};

/** 
 * Class to notify a dialog object's Yes push button being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgNotify whenever the end user presses the Yes push button.
 */
class ExportedByDI0PANV2 CATDlgNfyYesNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgNfyYesNotification object. 
 */   
    CATDlgNfyYesNotification();

    virtual ~CATDlgNfyYesNotification();

};

/** 
 * Class to notify a dialog object's No push button being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgNotify whenever the end user presses the No push button.
 */
class ExportedByDI0PANV2 CATDlgNfyNoNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgNfyNoNotification object. 
 */   
    CATDlgNfyNoNotification();

    virtual ~CATDlgNfyNoNotification();

};

/** 
 * Class to notify a toolbar's push, check, or radio item being pressed.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgToolBar whenever the end user presses a toolbar push, check, or radio item.
 */
class ExportedByDI0PANV2 CATDlgToolBarMButtonNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgToolBarMButtonNotification object. 
 */   
    CATDlgToolBarMButtonNotification();

    virtual ~CATDlgToolBarMButtonNotification();

};

/** 
 * @nodoc
 * Class to notify the application that a session event was received.
 * <b>Role</b>:
 * This event notification is sent by the @href CATDlgDocument whenever 
 * the system sends a power or session event to CATIA
 */
class ExportedByDI0PANV2 CATDlgSessionNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgSessionNotification object. 
 */   
    CATDlgSessionNotification();

    virtual ~CATDlgSessionNotification();

};

#endif
