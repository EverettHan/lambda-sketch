#ifndef CATDIALOG_H
#define CATDIALOG_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "DI0PANV2.h"

class CATString;
class CATUnicodeString;
class l_CATDialog;
class CATDlgWindow;
class CATNotification;
class CATMarshal;
class CATDlgGridConstraints;
class CATMsgCatalog;
class CATRscCatalog;
class CATDlgIndexedConstraints;
class CATDlgSYPRectDimensions;
class CATDlgSYPPoint;
class CATDlgSYPIconName;
class CATISYPCollection_var;

#include "CATCommand.h"

#include "CATBoolean.h"
#include "CATDlgUtility.h"
#include "CATDlgResource.h"

#include <assert.h>

/** @nodoc */
typedef unsigned int CATDlgCursorID;

#ifndef CATDialog_ADD
/** @nodoc */
#define CATDialog_ADD
#endif

#ifndef CATDialog_LateADD
/** @nodoc */
#define CATDialog_LateADD
#endif

/** 
 * Base class for all dialog objects.
 * <b>Role</b>:
 * This class implements common mechanisms for any dialog object.
 * <br>
 * This class can not be instantiated.
 */
class ExportedByDI0PANV2 CATDialog : public CATCommand
{

 public:

        virtual ~CATDialog();
        /**
         * Requests the dialog object delayed destruction.
         * <br><b>Role</b>: The dialog object will be destroyed as soon as it is possible.
         * This method, declared in parent class CATCommand, is overloaded here for internal reasons.
         * You are recommended against overloading it in a derived class.
         */
        virtual void RequestDelayedDestruction();

        /**
         * Sets the command identifier.
         * @param iIdentifier
         *   The identifier to set to the command
         */
        virtual void SetName(CATString & iIdentifier);

        /**
         * Returns the name of the dialog object.
         */
        virtual CATString& GetName();

        /**
         * Returns the parent window that contains the dialog object.
         */
        CATDlgWindow* GetFatherWindow();

        /**
         * Returns the number of children of the dialog object.
         */
        int           GetChildCount();
        /**
         * Returns the rank of a given child dialog object among all the children of the dialog object.
         * @param iChild
         * The pointer to the child.
         */
        int           GetChildNumberFromChild( CATDialog *iChild );

        /**
         * Returns a pointer to a child dialog object from its rank.
         * @param iChild
         * The number of the child.
         */
        CATDialog*    GetChildFromChildNumber( int iChild);

        /**
         * Modifies the parent relationship by setting a new parent for the dialog object.
         * @param iNewParent
         * The pointer to the new parent to set.
         * @return 
         * TRUE if the operation succeeded.
         */
        int           Reparent(CATDialog *iNewParent);

        /**
         * Returns the current display state of the dialog object.
         *   <br>
         * The visibility state can be :
         *   <dl>
         *   <dt><tt>CATDlgShow</tt><dd> if the dialog object is shown,
         *   <dt><tt>CATDlgHide</tt><dd> if the dialog object is hidden.
         *   </dl>
         */
        CATULong GetVisibility();


        /**
         * Sets the display state of the dialog object.
         * @param iState
         * The visibility state to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgShow</tt><dd> to show the dialog object,
         *   <dt><tt>CATDlgHide</tt><dd> to hide the dialog object.
         *                               This is not possible with the CATDlgTabPage dialog object .
         *   </dl>
         */
        void SetVisibility( CATULong iState);

        /**
         * Sets the dialog object state to the enabled, disabled or undefined state.
         * When a dialog object is disabled, it is grayed.
         * Undefined state is relevant only for the CATDlgCheckButton, CATDlgCombo, CATDlgEditor and CATDlgSpinner dialog objects
         * @param iState
         * The dialog object state to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the dialog object,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the dialog object (grayed),
         *   <dt><tt>CATDlgUndefined</tt><dd> for an undefined state.
         *   </dl>
         */
        void SetSensitivity( CATULong iState);

        /**
         * Returns TRUE if the dialog object is enabled.
         * @return
         * TRUE if the dialog object is enabled, FALSE otherwise.
         */
        CATBool IsSetSensitivity();

        /**
         * Returns the dialog object state.
         *   <br>
         * The dialog object state can be :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the dialog object is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the dialog object is disabled (grayed),
         *   <dt><tt>CATDlgUndefined</tt><dd> if the dialog object is in an undefined state.
         *   </dl>
         */
        CATULong GetSensitivity();

        /**
         * Sets the title of the dialog object to the specified character string. 
         * @param iTitle
         * The title to be displayed.
         */
        void       SetTitle( const CATUnicodeString& iTitle);

        /**
         * Returns the displayed title of the dialog object.
         */
        CATUnicodeString& GetTitle();

        /**
         * Sets the resource key of the dialog object.
         * @param iID
         * The resource key
         */
        void       SetResourceID( const CATString& iID);

        /**
         * Returns the resource key of the dialog object.
         */
        CATString& GetResourceID();

        /**
         * Retrieves a resource value from its key, and the possible associated parameters, if any.
         * @param iKey
         * The researched resource.
         * @param oValue
         * The returned resource value.
         * @param iParameters
         * The parameters array.
         * @return
         * TRUE if the operation succeeded.
         */
        int        GetResourceValueFromKey( const CATString& iKey, CATUnicodeString& oValue, CATUnicodeString* iParameters = NULL);

        /**
         * Retrieves a resource value from its key, and the possible associated parameters, if any.
         * @param iKey
         * The researched resource.
         * @param oValue
         * The returned resource value.
         * @param iParameters
         * The parameters array.
         * @param iNbParameters
         * The number of parameters.
         * @return
         * TRUE if the operation succeeded.
         */
        int        GetResourceFromKey( const CATString& iKey, CATString& oValue, CATString* iParameters = NULL, int iNbParameters = 0 );

        /**
         * Adds a message catalog and its path.
         * @param iCat
         * The message catalog.
         * @param iPath
         * The path of the message catalog.
         */
        void       AddResourcePath( const CATMsgCatalog& iCat, const CATString& iPath);

        /**
         * Adds a resource catalog and its path.
         * @param iCat
         * The resource catalog.
         * @param iPath
         * The path of the resource catalog.
         */
        void       AddResourcePath( const CATRscCatalog& iCat, const CATString& iPath);

        /**
         * Adds a catalog name and its path.
         * @param iCatname
         * The name of the catalog.
         * @param iPath
         * The path of the catalog.
         */
        void       AddResourcePath( const CATString & iCatname, const CATString& iPath);

        /**
         * Sets the mnemonic (underlined letter for a menu item) of the dialog object.
         * This method works only for @href CATDlgSubMenu, @href CATDlgPushItem, 
         * @href CATDlgRadioItem and @href CATDlgCheckItem.
         * @param iLetter
         * The character to set.
         */
        void   SetMnemonic( CATUnicodeChar iLetter);

        /**
         * Returns the mnemonic (underlined letter for a menu item) of the dialog object.
         * This method works only for @href CATDlgSubMenu, @href CATDlgPushItem, 
         * @href CATDlgRadioItem and @href CATDlgCheckItem.
         */
        CATUnicodeChar GetMnemonic();

        /**
         * Sets the accelerator of the dialog object as a keystroke combination.
         * <br><b>Role:</b> Allows a quick access to a command.
         * <br>
         * It is usually set using a resource file.
         * @param iKey
         * The accelerator key.
         * <br><b>Legal values:</b> usually a control key and an alphanumeric key,
         * such as "Ctrl+N" for the New Command.
         */
        void      SetAccelerator( CATDlgAccelerator iKey);

        /**
         * Returns the accelerator of the dialog object as a keystroke combination.
         * @see #SetAccelerator
         */
        CATDlgAccelerator GetAccelerator();

        /**
         * Sets the accelerator of the dialog object as a CATUnicodeString instance.
         * @param iKey
         * The accelerator key.
         */
        void      SetAcceleratorString( const CATUnicodeString& iKey );

        /**
         * Removes the accelerator of the dialog object.
         */
        void      RemoveAccelerator();

        /**
         * Returns the accelerator of the dialog object as a CATUnicodeString instance.
         */
        CATUnicodeString& GetAcceleratorString();

        /**
         * Sets the icon names associated to the state of the dialog object.
         *
         * @param iIconNameNormal
         * The name of the icon in its default state.
         *
         * @param iIconNameSelected
         * The name of the icon when the dialog object is selected.
         * 
         * For Toolbars buttons, if not explicitly 
         * specified through SetIconName, the "selected" 
         * icon (sometimes called "pressed") is dynamically generated and displayed.
         * 
         * @param iIconNameFocused
         * The name of the icon when the dialog object is on focus.
         *
         * For toolbars buttons, if not explicitly 
         * specified through SetIconName, the focussed icon is dynamically 
         * generated and displayed.  

         * @param iIconNameDisabled
         * The name of the icon when the dialog object is disabled.
         *
         * This parameter is obsolete and no longer taken into account
         * The disabled icon is automatically generated.
         *
         * @param iForceSmall
         * If an icon exists both in normal format and small format, this parameter forces selection of the small one. 
         * That does not apply to toolbar buttons, for which format is chosen through setting in Tools+Customize.
         * nor to icon box buttons, nor to menu items.
         */
        void      SetIconName(const CATString& iIconNameNormal,
                              const CATString& iIconNameSelected = "",
                              const CATString& iIconNameFocused = "",
                              const CATString& iIconNameDisabled = "",
                              const CATBool iForceSmall = FALSE);

        /**
         * Gets the icon names associated to the dialog object.
         *
         * @param oIconNameNormal
         * The name of the icon in its default state.
         *
         * @param oIconNameSelected
         * The name of the icon when the dialog object is selected
         * (relevant for toolbar buttons only).
         * 
         * @param oIconNameFocused
         * The name of the icon when the dialog object is on focus.
         * (relevant for toolbar buttons only).
         *
         */
        void      GetIconName(CATString& oIconNameNormal,
                              CATString& oIconNameSelected,
                              CATString& oIconNameFocused);

        /**
         * @nodoc 
         * This method is obsolete and no longer taken into account.
         */
        void      SetIconType(CATDlgIconType iType);

        /**
         * Sets the help message displayed in the message area of the status bar.
         * @param iMessage
         * The message to be displayed.
         */
        void       SetHelp( const CATUnicodeString& iMessage);

        /**
         * Returns the help message displayed in the message area of the status bar.
         */
        CATUnicodeString& GetHelp();

        /**
         * Sets the short help message (or tooltip) of the dialog object.
         * This message is displayed in a box beside the dialog object when the mouse moves above it. 
         * @param iMessage
         * The message to be displayed.
         */
        void       SetShortHelp( const CATUnicodeString& iMessage);

        /**
         * Returns the short help message (or tooltip) of the dialog object.
         * This message is displayed in a box beside the dialog object when the mouse moves above it. 
         */
        CATUnicodeString& GetShortHelp();

        /**
         * Sets the Power Input help message of the dialog object.
         * This message is displayed in front of the Power Input entry field.
         * @param iMessage
         * The message to be displayed.
         */
        void       SetPowerInputHelp( const CATUnicodeString& iMessage);

        /**
         * Returns the Power Input help message of the dialog object.
         * This message is displayed in front of the Power Input entry field.
         */
        CATUnicodeString& GetPowerInputHelp();

        /**
         * Sets the long help message of the dialog object.
         * This message is displayed in a box when the What's This command is used.
         * @param iMessage
         * The message to be displayed.
         */
        void       SetLongHelp( const CATUnicodeString& iMessage);

        /** 
         * Enables to get More Info from the LongHelp message of the dialog object.
         *  <br><b>Role</b>:
         *  <ul>
         *    <li>This method allows to display the More Info link at the end of a dialog object 
         *        LongHelp message. A dialog object with a LongHelpId displays a More Info link
         *        at the end of its LongHelp message.  
         *        Use the following link to get further information about LongHelpId 
         *        and documentation:
         *        <ul>
         *          <li> @href online/CAAAfrTechArticles/CAAAfrHelpOnLine.htm </li>
         *        </ul>
         *    </li>
         *  </ul>
         * @param longHelpId
         *    The dialog object LongHelpId.
         */
        void       SetLongHelpId(const CATUnicodeString& longHelpId);

        /**
         * Returns the long help message of the dialog object.
         * This message is displayed in a box when the What's This command is used.
         */
        CATUnicodeString& GetLongHelp();

        /**
         * Sets the icon name of the image displayed in the long help message of the dialog object.
         * @param iIconName
         * The name of the icon.
         */
        void SetLongHelpIconName( const CATString& iIconName );

        /**
         * Returns the icon name of the image displayed in the long help message of the dialog object.
         */
        CATString& GetLongHelpIconName();

        /**
         * Sets the status bar text of the current document.
         * @param iText
         * The text to be displayed.
         */
        void       SetStatusBarText( const CATUnicodeString& iText);

        /**
         * @nodoc 
         * nodoc in Jan 2001. Should be reserved for Dialog internal use.
         * Sets the status bar text of the current document with a transient text.
         * "Permanent" statusbar text is restored when this method is re-called 
         * with an empty string as argument.
         * @param iText
         * The text to be displayed.
         */
        void       SetStatusBarTemporaryText( const CATUnicodeString& iText);

        /**
         * Returns the style of the dialog object.
         */
        CATDlgStyle GetStyle();

        /**
         * @deprecated R422 Use SetRectDimensionsEx
         * Sets the size and position of the dialog object from a DRECT struct.
         * This method works only for @href CATDlgContainer and all @href CATDlgWindow.
         * @param iRectangle
         * The specified DRECT struct.
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite the origin of the rectangle.
         */
        void SetRectDimensions(DRECT& iRectangle, CATBool iPreferencePriority=FALSE);

        /**
         * Sets the size and position of the dialog object from a DRECT struct.
         * This method works only for @href CATDlgContainer and all @href CATDlgWindow.
         * @param iRectangle
         * The specified DRECT struct.
         * @param iAlreadyScaled
         * Specifies if iRectangle respects the current display scaling.
         * When FALSE, iRectangle must match a 100% display scaling, position and size will be automatically scaled according to current display scaling.
         * When TRUE, iRectangle must match the current display scaling, position and size won't be scaled.
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite the origin of the rectangle.
         */
        void SetRectDimensionsEx(const DRECT& iRectangle, CATBoolean iAlreadyScaled, CATBoolean iPreferencePriority=FALSE);

        /**
         * @deprecated R422 Use SetRectDimensionsEx
         * Sets the size and position of the dialog object from coordinates, width and height.
         * This method works only for @href CATDlgContainer and all @href CATDlgWindow.<br>
         * None of the four arguments can be null.
         * @param iX, iY
         * The coordinates of the upper left corner of the dialog object.
         * @param iHeight
         * The value to use to set the height of the dialog object.
         * @param iWidth
         * The value to use to set the width of the dialog object.
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite coordinates of the upper left corner.
         */
        void SetRectDimensions(int iX, int iY, int iHeight, int iWidth, CATBool iPreferencePriority=FALSE);

        /**
         * Sets the size and position of the dialog object from coordinates, width and height.
         * This method works only for @href CATDlgContainer and all @href CATDlgWindow.<br>
         * None of the four arguments can be null.
         * @param iX, iY
         * The coordinates of the upper left corner of the dialog object.
         * @param iHeight
         * The value to use to set the height of the dialog object.
         * @param iWidth
         * The value to use to set the width of the dialog object.
         * @param iAlreadyScaled
         * Specifies if iX, iY, iWidth, iHeight respect the current display scaling.
         * When FALSE, iX, iY, iWidth, iHeight must match a 100% display scaling, position and size will be automatically scaled according to current display scaling.
         * When TRUE, iX, iY, iWidth, iHeight must match the current display scaling, position and size won't be scaled.
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite coordinates of the upper left corner.
         */
        void SetRectDimensionsEx(int iX, int iY, int iHeight, int iWidth, CATBoolean iAlreadyScaled, CATBoolean iPreferencePriority=FALSE);

        /**
         * @deprecated R422 Use GetRectDimensionsEx
         * Retrieves the size and position of the dialog object as DRECT struct.
         * @param oRectangle
         * The DRECT struct filled with the size and position of the dialog object.
         */
        void GetRectDimensions(DRECT* oRectangle);

        /**
         * Retrieves the size and position of the dialog object as DRECT struct.
         * @param oRectangle
         * The DRECT struct filled with the size and position of the dialog object.
         * @param iAlreadyScaled
         * Specifies if oRectangle must respect the current display scaling.
         * When FALSE, oRectangle position and size will match a 100% display scaling.
         * When TRUE, oRectangle position and size will match the current display scaling.
         */
        void GetRectDimensionsEx(DRECT * oRectangle, CATBoolean iAlreadyScaled);

        /**
         * @deprecated R422 Use SetRectPositionEx
         * Sets the position of the upper left corner of the dialog object from a DPOS struct.
         * @param iUpperLeftCorner
         * The specified DPOS struct.
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite coordinates of the upper left corner.
         */
        void SetRectPosition(DPOS iUpperLeftCorner, CATBool iPreferencePriority=FALSE);

        /**
         * Sets the position of the upper left corner of the dialog object from a DPOS struct.
         * @param iUpperLeftCorner
         * The specified DPOS struct.
         * @param iAlreadyScaled
         * Specifies if iUpperLeftCorner respects the current display scaling.
         * When FALSE, iUpperLeftCorner must match a 100% display scaling, position will be automatically scaled according to current display scaling
         * When TRUE, iUpperLeftCorner must match the current display scaling, position won't be scaled.
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite coordinates of the upper left corner.
         */
        void SetRectPositionEx(const DPOS& iUpperLeftCorner, CATBoolean iAlreadyScaled, CATBoolean iPreferencePriority=FALSE);

        /**
         * @deprecated R422 Use SetRectPositionEx
         * Sets the position of the upper left corner of the dialog object from two coordinates.
         * @param iX, iY
         * The coordinates of the upper left corner of the dialog object. 
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite coordinates of the upper left corner.
         */
        void SetRectPosition(int iX, int iY, CATBool iPreferencePriority=FALSE);

        /**
         * Sets the position of the upper left corner of the dialog object from two coordinates.
         * @param iX, iY
         * The coordinates of the upper left corner of the dialog object. 
         * @param iAlreadyScaled
         * Specifies if iX, iY respect the current display scaling.
         * When FALSE, iX, iY must match a 100% display scaling, position will be automatically scaled according to current display scaling.
         * When TRUE, iX, iY must match the current display scaling, position won't be scaled.
         * @param iPreferencePriority
         * Specifies if, only for CATDlgDialog objects without CATDlgWndChildMDI style, the user preferences may overwrite coordinates of the upper left corner.
         */
        void SetRectPositionEx(int iX, int iY, CATBoolean iAlreadyScaled, CATBoolean iPreferencePriority=FALSE);

        /**
         * @deprecated R422 Use GetRectPositionEx
         * Retrieves the position of the upper left corner of the dialog object from two coordinates.
         * @param oUpperLeftCorner
         * The DPOS struct filled with the coordinates of the upper left corner of the dialog object. 
         */
        void GetRectPosition(DPOS * oUpperLeftCorner);

        /**
         * Retrieves the position of the upper left corner of the dialog object from two coordinates.
         * @param oUpperLeftCorner
         * The DPOS struct filled with the coordinates of the upper left corner of the dialog object. 
         * @param iAlreadyScaled
         * Specifies if oUpperLeftCorner must respect the current display scaling.
         * When FALSE, oUpperLeftCorner coordinates will match a 100% display scaling.
         * When TRUE, oUpperLeftCorner coordinates will match the current display scaling.
         */
        void GetRectPositionEx(DPOS * oUpperLeftCorner, CATBoolean iAlreadyScaled);

        /**
         * @deprecated R422 Use GetAbsolutePositionEx
         * Retrieves the position of the dialog object relative to the root.
         * @param oX, oY
         * The returned coordinates of the upper left corner of the dialog object.
         */
        void GetAbsolutePosition(int &oX, int &oY);

        /**
         * Retrieves the position of the dialog object relative to the root.
         * @param oX, oY
         * The returned coordinates of the upper left corner of the dialog object.
         * @param iAlreadyScaled
         * Specifies if oX, oY must respect the current display scaling.
         * When FALSE, oX, oY coordiantes will match a 100% display scaling.
         * When TRUE, oX, oY coordiantes will match the current display scaling.
         */
        void GetAbsolutePositionEx(int &oX, int &oY, CATBoolean iAlreadyScaled);

        /**
         * Adds or removes a link to PowerInput.
         * @param iOnOff
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>1</tt><dd> to add a link to PowerInput, or
         *   <dt><tt>0</tt><dd> to remove a link to PowerInput.
         *   </dl>
         */
        void SetPowerInputLink(int iOnOff);

        /**
         * Returns the event notification sent when the dialog object is created.
         */
        CATNotification *GetCreateNotification() const;
        /**
         * Returns the event notification sent whenever the object visibility is modified.
         */
        CATNotification *GetVisibilityNotification() const;
        /**
         * Returns the event notification sent whenever the object is resized.
         */
        CATNotification *GetResizeNotification() const;
        /**
         * Returns the event notification sent whenever the object is selected using the What's This command.
         */
        CATNotification *GetHelpNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drag enters the window.
         */
        CATNotification *GetDragEnterNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drag rolls over the window.
         */
        CATNotification *GetDragOverNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drag leaves the window.
         */
        CATNotification *GetDragLeaveNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drop happens.
         * This notification is sent by the target of the drag&drop operation.
         */
        CATNotification *GetDropNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drop happens.
         * This notification is sent by the source of the drag&drop operation.
         */
        CATNotification *GetEndDropNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drag mechanism begins.
         */
        CATNotification *GetStartDragNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drag mechanism stops.
         */
        CATNotification *GetCancelDragNotification() const;
        /**
         * Returns the event notification sent whenever a mouse drag mechanism starts on a button.
         */
        CATNotification *GetDragButtonNotification() const;

        /**
         * @nodoc 
         * Gets the internal object.
         */
        virtual l_CATDialog* GetLetterObject()=0;

        /**
         * @nodoc 
         * Resets the internal object.
         */
        virtual void ResetLetterObject()=0;

        /**
         * @nodoc
         * Default implementation of resource file lookup.
         */
        virtual char* GetResourceFilename(int) const;

        /**
         * @nodoc 
         * Static strings for builders.
         */
        static char* KeyName[];

        /**
         * @nodoc 
         */
        static char* MagnitudeName[];

        /**
         * @nodoc 
         */
        static char* UnitName[];

        /**
         * Sets the layout grid constraints of the dialog object from a grid constraints object.
         * @param iGc
         * The grid constraints to set.
         */
        void SetGridConstraints(const CATDlgGridConstraints& iGc);

        /**
         * Sets the layout grid constraints of the dialog object from its top left anchor cell,
         * row and column extents, and justification.
         * @param iTopRow
         *   The initial row index under the upper left corner of the object.
         * @param iLeftColumn
         *   The initial column index under the upper left corner of the object.
         * @param iRowSpan
         *   The initial horizontal span (in number of columns) of the object. 
         * @param iColumnSpan
         *   The initial vertical span (in number of rows) of the object. 
         * @param iJustification
         *   The initial position of the object in its cell.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATGRID_LEFT</tt><dd> to attach the object to the left side of its cell,
         *   <dt><tt>CATGRID_RIGHT</tt><dd> to attach the object to the right side of its cell,
         *   <dt><tt>CATGRID_TOP</tt><dd> to attach the object to the upper side of its cell,
         *   <dt><tt>CATGRID_BOTTOM</tt><dd> to attach the object to the lower side of its cell,
         *   <dt><tt>CATGRID_4SIDES</tt><dd> to set the object size equal to the size of its cell,
         *   <dt><tt>CATGRID_CST_WIDTH</tt><dd> to keep the object width constant, independently of its cell width,
         *   <dt><tt>CATGRID_CST_HEIGHT</tt><dd> to keep the object height constant, independently of its cell height,
         *   <dt><tt>CATGRID_CST_SIZE</tt><dd> to keep the object size constant, independently of its cell size,
         *   <dt><tt>CATGRID_CENTER</tt><dd> to center the object.
         *   </dl>
         */
        void SetGridConstraints(short int iTopRow, short int iLeftColumn,
                                short int iRowSpan, short int iColumnSpan,
                                unsigned int iJustification);

        /**
         * Returns the layout grid constraints of the dialog object.
         */
        const CATDlgGridConstraints& GetGridConstraints();

        /**
         * @nodoc 
         * Reception of Events from CATCommandSelector.
         */
        virtual CATStatusChangeRC Activate    ( CATCommand* FromClient, CATNotification* EvtDat );
        /**
         * @nodoc 
         */
        virtual CATStatusChangeRC Desactivate ( CATCommand* FromClient, CATNotification* EvtDat );
        /**
         * @nodoc 
         */
        virtual CATStatusChangeRC Cancel      ( CATCommand* FromClient, CATNotification* EvtDat );
        /**
         * @nodoc 
         * Migrate : method CATInteractiveApplication::UpdateDisplay().
         */
        void Refresh (int iflag=0);

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;

#ifdef DRIVER_WINDOWS
        /**
         * For Windows platform use only.
         * Returns the handle of the underlying Windows object, if it is created, and NULL otherwise.
         * The type of this object is HWND.
         */
        HANDLE GetWindowHandle();
#endif

 protected:

        /** 
         * Constructs a CATDialog object using its parent container, its name and its style.
         * @param iParent
         * The parent container of the dialog object.
         * @param iObjectName
         * The name of the dialog object.
         * @param iStyle
         *   The style of the dialog object.
         *   <br>
         *   <b>Legal values</b> :
         *   <dl>
         *   <dt><tt>NULL</tt><dd> the default style, if no value is passed in argument,
         *   <dt><tt>CATDlgPowerInputLink</tt><dd> the dialog object and its children are linked to the PowerInput.
         *   </dl>
         */
        CATDialog( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        /**
         * @nodoc 
         * Address of the internal object.
         */
        l_CATDialog* LetterObject;        

 public:

        /**
         * Cursor settings 
         */

        /**
         * @nodoc
         */
        static CATDlgCursorID GetCursor(const CATUnicodeString&);

        /**
         * @nodoc 
         */
        CATDlgCursorID SetCursor(CATDlgCursorID);

        /**
         * @nodoc 
         */
        CATDlgCursorID GetCursor();

        /**
         * @nodoc
         */
        void ResetCursor();

        /**
         * @deprecated R421 Use CATDlgCursorID instead
         */
        typedef CATDlgCursorID CATDlgCursor;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthWestArrow") instead
         */
        static const CATDlgCursorID NorthWestArrow = (CATDlgCursorID) 1;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorCross") instead
         */
        static const CATDlgCursorID Cross = (CATDlgCursorID) 2;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthHand") instead
         */
        static const CATDlgCursorID NorthHand = (CATDlgCursorID) 3;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthWestHand") instead
         */
        static const CATDlgCursorID NorthWestHand = (CATDlgCursorID) 4;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorFilterNorthWestHand") instead
         */
        static const CATDlgCursorID FilterNorthWestHand = (CATDlgCursorID) 5;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNoArrow") instead
         */
        static const CATDlgCursorID NoArrow = (CATDlgCursorID) 6;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMoveArrow") instead
         */
        static const CATDlgCursorID MoveArrow = (CATDlgCursorID) 7;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthSouthArrow") instead
         */
        static const CATDlgCursorID NorthSouthArrow = (CATDlgCursorID) 8;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorTarget") instead
         */
        static const CATDlgCursorID Target = (CATDlgCursorID) 9;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorForward") instead
         */
        static const CATDlgCursorID Forward = (CATDlgCursorID) 10;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorBackward") instead
         */
        static const CATDlgCursorID Backward = (CATDlgCursorID) 11;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorOpenedHand") instead
         */
        static const CATDlgCursorID OpenedHand = (CATDlgCursorID) 12;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMagnifier") instead
         */
        static const CATDlgCursorID Magnifier = (CATDlgCursorID) 13;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorClosedHand") instead
         */
        static const CATDlgCursorID ClosedHand = (CATDlgCursorID) 14;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNoEntry") instead
         */
        static const CATDlgCursorID NoEntry = (CATDlgCursorID) 15;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemSeek") instead
         */
        static const CATDlgCursorID MeasureItemSeek = (CATDlgCursorID) 16;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnTarget") instead
         */
        static const CATDlgCursorID MeasureItemOnTarget = (CATDlgCursorID) 17;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnTargetPlus") instead
         */
        static const CATDlgCursorID MeasureItemOnTargetPlus = (CATDlgCursorID) 18;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnTargetMinus") instead
         */
        static const CATDlgCursorID MeasureItemOnTargetMinus = (CATDlgCursorID) 19;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBetweenOnFirstTarget") instead
         */
        static const CATDlgCursorID MeasureBetweenOnFirstTarget = (CATDlgCursorID) 20;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBetweenOnSecondTarget") instead
         */
        static const CATDlgCursorID MeasureBetweenOnSecondTarget = (CATDlgCursorID) 21;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureThreePointsOnFirstPoint") instead
         */
        static const CATDlgCursorID MeasureThreePointsOnFirstPoint = (CATDlgCursorID) 22;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureThreePointsOnSecondPoint") instead
         */
        static const CATDlgCursorID MeasureThreePointsOnSecondPoint = (CATDlgCursorID) 23;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureThreePointsOnThirdPoint") instead
         */
        static const CATDlgCursorID MeasureThreePointsOnThirdPoint = (CATDlgCursorID) 24;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorEastWestArrow") instead
         */
        static const CATDlgCursorID EastWestArrow = (CATDlgCursorID) 25;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorEastArrow") instead
         */
        static const CATDlgCursorID EastArrow = (CATDlgCursorID) 26;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthWestSmallArrow") instead
         */
        static const CATDlgCursorID NorthWestSmallArrow = (CATDlgCursorID) 27;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthWestSmallArrowWithPoint") instead
         */
        static const CATDlgCursorID NorthWestSmallArrowWithPoint = (CATDlgCursorID) 28;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthWestSmallArrowWithEdge") instead
         */
        static const CATDlgCursorID NorthWestSmallArrowWithEdge = (CATDlgCursorID) 29;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthWestSmallArrowWithFace") instead
         */
        static const CATDlgCursorID NorthWestSmallArrowWithFace = (CATDlgCursorID) 30;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorNorthWestContextualArrow") instead
         */
        static const CATDlgCursorID NorthWestContextualArrow = (CATDlgCursorID) 31;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorCrossWhiteContour") instead
         */
        static const CATDlgCursorID CrossWhiteContour = (CATDlgCursorID) 32;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnPlane") instead
         */
        static const CATDlgCursorID MeasureItemOnPlane = (CATDlgCursorID) 33;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnCylinder") instead
         */
        static const CATDlgCursorID MeasureItemOnCylinder = (CATDlgCursorID) 34;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnCone") instead
         */
        static const CATDlgCursorID MeasureItemOnCone = (CATDlgCursorID) 35;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnSphere") instead
         */
        static const CATDlgCursorID MeasureItemOnSphere = (CATDlgCursorID) 36;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnSurface") instead
         */
        static const CATDlgCursorID MeasureItemOnSurface = (CATDlgCursorID) 37;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnLine") instead
         */
        static const CATDlgCursorID MeasureItemOnLine = (CATDlgCursorID) 38;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnCircle") instead
         */
        static const CATDlgCursorID MeasureItemOnCircle = (CATDlgCursorID) 39;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnCurve") instead
         */
        static const CATDlgCursorID MeasureItemOnCurve = (CATDlgCursorID) 40;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnPoint") instead
         */
        static const CATDlgCursorID MeasureItemOnPoint = (CATDlgCursorID) 41;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnAxisSystem") instead
         */
        static const CATDlgCursorID MeasureItemOnAxisSystem = (CATDlgCursorID) 42;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureItemOnVolume") instead
         */
        static const CATDlgCursorID MeasureItemOnVolume = (CATDlgCursorID) 43;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnPlane") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnPlane = (CATDlgCursorID) 44;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnCylinder") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnCylinder = (CATDlgCursorID) 45;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnCone") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnCone = (CATDlgCursorID) 46;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnSphere") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnSphere = (CATDlgCursorID) 47;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnSurface") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnSurface = (CATDlgCursorID) 48;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnLine") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnLine = (CATDlgCursorID) 49;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnCircle") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnCircle = (CATDlgCursorID) 50;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnCurve") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnCurve = (CATDlgCursorID) 51;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnPoint") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnPoint = (CATDlgCursorID) 52;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnAxisSystem") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnAxisSystem = (CATDlgCursorID) 53;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn1OnVolume") instead
         */
        static const CATDlgCursorID MeasureBtwn1OnVolume = (CATDlgCursorID) 54;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnPlane") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnPlane = (CATDlgCursorID) 55;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnCylinder") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnCylinder = (CATDlgCursorID) 56;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnCone") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnCone = (CATDlgCursorID) 57;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnSphere") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnSphere = (CATDlgCursorID) 58;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnSurface") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnSurface = (CATDlgCursorID) 59;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnLine") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnLine = (CATDlgCursorID) 60;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnCircle") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnCircle = (CATDlgCursorID) 61;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnCurve") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnCurve = (CATDlgCursorID) 62;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnPoint") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnPoint = (CATDlgCursorID) 63;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnAxisSystem") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnAxisSystem = (CATDlgCursorID) 64;
        /**
         * @deprecated R421 Use CATDialog::GetCursor("I_CursorMeasureBtwn2OnVolume") instead
         */
        static const CATDlgCursorID MeasureBtwn2OnVolume = (CATDlgCursorID) 65;

        /**
         * Applicative cursor.
         * @deprecated R421 Use CATDlgCursorID instead
         * @see #DefineCursor
         */
        typedef CATDlgCursorID CATDlgHCursor;

        /**
         * @deprecated R421 Use CATDialog::GetCursor(const CATUnicodeString&) to load cursor from PNG file
         *
         * Constructs an applicative cursor using its width, its height, its hot spot coordinates and its geometry.
         * <br>
         * The hot spot of a cursor is the point to which the framework Dialog refers in tracking the
         * cursor's position.
         * <br>
         * When the coordinates are (0, 0), the hot spot is set to the upper-left corner.
         * <br>
         * The geometry of a cursor is defined by an array of characters.
         * <br>
         * The dimension of this array is : iWidth * iHeight.
         * <br>
         * The space character, ' ', defines a transparent pixel.
         * <br>
         * The point character, '.', defines a white pixel.
         * <br>
         * The star  character, '*', defines a black pixel.
         * <br>
         * @param iWidth
         * The cursor's width.
         * @param iHeight
         * The cursor's height.
         * @param iXspot
         * The x coordinate of the hot spot.
         * @param iYspot
         * The y coordinate of the hot spot.
         * @param iCursorDef
         * The geometry of the cursor.
         *   <br>
         *   Example, a small arrow, Width = 9, Height = 13, Hot Spot = (0, 0) :
         *   <dl>
         *   <dt><tt>         </tt><dd>
         *   <dt><tt>*        </tt><dd>
         *   <dt><tt>**       </tt><dd>
         *   <dt><tt>*.*      </tt><dd>
         *   <dt><tt>*..*     </tt><dd>
         *   <dt><tt>*...*    </tt><dd>
         *   <dt><tt>*....*   </tt><dd>
         *   <dt><tt>*.....*  </tt><dd>
         *   <dt><tt>*......* </tt><dd>
         *   <dt><tt>*...*****</tt><dd>
         *   <dt><tt>*..*     </tt><dd>
         *   <dt><tt>*.*      </tt><dd>
         *   <dt><tt>**       </tt><dd>
         *   <dt><tt>*        </tt><dd>
         *   </dl>
         * @return 
         * A CATDialog::CATDlgHCursor used by the framework DialogEngine.
         * @href CATPathElementAgent#SetNoSelectionCursor, @href CATPathElementAgent#SetPreselectionCursor.
         */
        static CATDlgCursorID DefineCursor(int iWidth, int iHeight, int iXspot, int iYspot, const char *iCursorDef);

        /**
         * @deprecated R421 Useless
         *
         * Frees an applicative cursor.
         */
        static void FreeCursor(CATDlgCursorID iCursor);

        /**
         * @deprecated R421 Use SetCursor instead
         *
         * @nodoc 
         */
        void UseCursor(CATDlgCursorID);

        /**
         * @nodoc 
         */
        void SetUserData(void *);

        /**
         * @nodoc 
         */
        void * GetUserData();

        /**
         * @nodoc
         */
        void Dump(int iSpaces=0);

 private:

        /**
         * @nodoc 
         * inhibit default constructor
         */
//      CATDialog() {}

        /**
         * @nodoc 
         */
        friend class l_CATDialog;
  public:
        /**
         * @nodoc 
         */
        virtual int SaveState(CATNotification*, CATMarshal&);
        /**
         * @nodoc 
         */
        virtual int RestoreState(CATNotification*, CATMarshal&);

        /** @nodoc */
        CATDialog_ADD
};


/** @nodoc */
CATDialog_LateADD

#endif
