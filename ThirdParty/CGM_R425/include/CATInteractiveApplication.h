#ifndef CATINTERACTIVEAPPLICATION_H
#define CATINTERACTIVEAPPLICATION_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


//------------------------------------------------------------------------------
// Abstract: The base class for dialog applications.
//
//------------------------------------------------------------------------------
// Usage:    Derive to suit your need
//------------------------------------------------------------------------------
// Inheritance:   CATInteractiveApplication    (Dialog framework)
//                  CATApplication             (System framework)
//------------------------------------------------------------------------------
// Main methods:
//
//           Destroy                    to terminate the application
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "DI0PANV2.h"

#include "CATDlgControl.h"
#include "CATApplication.h"
#include "CATString.h"
#include "CATListOfCATUnicodeString.h"
//--------------------------------------------------------------------------
class l_CATInteractiveApplication;
struct IDataObject;
class CATDlgSession;

//--------------------------------------------------------------------------
/**
 * base class for all interactive applications.
 * <b>Role</b>: Base class for an interactive application,
 * whether it displays only a single dialog window, a classical Single 
 * Document Interface (SDI) application, or a Multiple Document 
 * Interface (MDI) application such as CATIA Version 5.
 * <p>
 * To create your interactive application, you should: 
 * <ul>
 * <li>Create a class for your application that derives from 
 * CATInteractiveApplication</li> 
 * <li>Override at least the methods BeginApplication and EndApplication</li>
 * </ul>
 * To not instanciate this class directly.
 */
class ExportedByDI0PANV2 CATInteractiveApplication : public CATApplication
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
/**
 * Constructs an interactive application.
 * <br><b>Role:</b>
 * Note that, deriving this class, your interactive application constructor 
 * should have a single argument: its name. When calling this base class
 * constructor from the derived class one, a NULL value should be passed
 * as iParent.
 * @param iParent
 *   The parent class in the @href CATCommand agregation 
 *   hierarchy. 
 * @param iApplicationName
 *   The application name. 
 */
        CATInteractiveApplication(CATCommand *iParent, const CATString& iApplicationName);
/**
 * @nodoc 
 */
        virtual ~CATInteractiveApplication();

        // Specific methods
/**
 * Initializes the application environment.
 * <p>
 * Called with UNIX only.
 * @param iArgc
 *   The number of arguments passed to the application. 
 * @param iArgv
 *   The argument list. 
 * @param iEnvVariableList
 *   The environment variable list. 
 */
        virtual void BuildApplicationEnvironment(int iArgc, 
                                                 char** iArgv, 
                                                 char** iEnvVariableList);
// Runs the application. 
// Architecture detail, called with UNIX only.
// Deserves interfacing with System framework JS0FM module
/**
 * @nodoc 
 */
        virtual void RunApplication();
/**
 * Application mean to transmit the return code to this software.
 * The application calls the Destroy method (when the user selects 
 * File/Exit, see @href #Destroy, which calls the EndApplication 
 * method. You overload the EndApplication method, transmitting this
 * way the recturn code to this software.
 */
        virtual int  EndApplication();
/**
 * Retrieve the arguments passed to the application.
 * @return
 *   The argument list.  
 */
        CATListOfCATUnicodeString& GetArgs();
/**
 * Retrieve the arguments passed to the application.
 * @param oArgCount
 *   The number of arguments passed to the application. 
 * @param oArgList
 *   The argument list. 
 *   The variable to pass here as a parameter has to be contructed the
 *   following way: you declare a char** in the calling service and 
 *   pass its address as oArgList to the GetArgs of your class
 *   deriving from CATInteractiveApplication.
 */
        void GetArgs( int* oArgCount, char*** oArgList);
/**
 * Terminate the application.
 * The application must call this service when it wants to
 * end the application. In practice, the application will call
 * this service when the user selects File/Exit , and only
 * at this moment.
 * <p>
 * This method calls the EndApplication method (that the application
 * must overload) which transmit to this software your return code.
 */
        void Destroy();

/**
 * Request that the display cursor be changed to a busy cursor.
 */
        void SetBusyCursor();

/**
 * @nodoc 
 * only for compatibility 
*/  
        void SetDialogBitmapName(int ifield, const CATString& bmpName);
/**
 * @nodoc 
*/  
        void SetApplicationLogo(const CATString& bmpName);
/**
 * @nodoc 
 */  
        void SetApplicationBackground(const CATString& bmpName);
/**
 * @nodoc
 * Not implemented. Reserved for future use.
 */
        void SetDialogBoxBottom(const CATString & bmpName);
/**
 * Retrieve the user interface class (P1, P2, P3).
 * @return
 *   The user interface style. 
 *   <br><b>Legal values</b>: <tt>1</tt> if the style is P1,
 *   or <tt>2</tt> if the style is P2, or <tt>3</tt> if the style is P3.
 */
        int GetUIClass();
/**
 * Request that the contextual help be automatically set to any control of 
 * any window. 
 * <p>
 * This service will be called only once during execution.
 * Then, when this service has been called, activating "What's This" command
 * becomes available to the end-user. To activate the "What's This" command, 
 * the end-user will have to select the possible dedicated icon or, on Windowsonly, 
 * the panel question mark selection, or, on WIndows and UNIX, the panel help 
 * button selection. 
 * <p>
 * We remind you what the "What's This" command is.  
 * It turns the cursor to a question mark, and then, 
 * when the end-user clicks a control, displays the control associated 
 * "Long Help" in a balloon. The clicks, after displaying the balloon,
 * ends the current "What's This" command.
 * Entering the "What's This" command will be done, at the Dialog framework
 * level, through calling the QueryHelpOnContext method on any @href CATDlgWindow .
 */
        void SetAutomaticContextualHelp();
/**
 * @nodoc 
 */
        void UnsetAutomaticContextualHelp();
/**
 * @nodoc 
 */
        void SetCurrentLongHelpId(const CATUnicodeString& iHelp);
/**
 * @nodoc 
 */
        CATUnicodeString GetCurrentLongHelpId();
/**
 * Assign a splash screen.
 * @param iFileName
 *   The splash file name. The extension must not be appended.
 *   The file will be a .png or a .bmp picture.
 *   It must be located in the splashscreens directory of the 
 *   graphic directory defined using the <tt>CATGraphicPath</tt> environment variable.
 */
        void SetSplashScreen(CATString& iFileName);
/**
 * Request that the display be updated.
 * At the end of a given interaction, the panels display is automatically
 * updated (the X server does it), thus no call to this service has 
 * to be made. A call to this service will be made only if, during a
 * long process, the application wants to update the display so that to
 * give a regular feedback to the user. 
 */
        void UpdateDisplay();

// Set the unit for a given applicative magnitude.
// We remind you that, for a given control (CATDlgSpinner, CATDlgEditor
// or CATDlgCombo), you can associate it, if you want, to an applicative
// magnitude (length, angle ...) using @href CATControl#SetMagnitude. 
// This enables an automatic unit management.
// At a given moment of the execution, all the controls which are
// asociated to the same applicative magnitude, share the same unit.
// The unit of all these controls can be processed globally through
// the current method. When calling this service, all the controls
// sharing the given applicative magnitude will be assigned the
// new unit, with all subsequent conversions managed. 
// @param iControlMagnitude
//    The control magnitude that the call to this method relates to.
// @param iControlMagnitudeUnit
//    The new unit for the given control magnitude.
//
// This service is not of very much use.
/**
 * @nodoc 
 */
        void SetMagnitudeCurrentUnit( 
                CATDlgControl::CATDlgMagnitude iControlMagnitude, 
                CATDlgControl::CATDlgUnit iControlMagnitudeUnit);
// This service is not of very much use.
/**
 * @nodoc 
 */
        CATDlgControl::CATDlgUnit GetMagnitudeCurrentUnit( 
                CATDlgControl::CATDlgMagnitude iControlMagnitude);
//
// Convert, for given magnitude, a given MKS value into the user unit 
// system.
//
// This service is not of very much use.
/**
 * @nodoc 
 */
        CATUnicodeString& GetDoubleValueString( 
                     double iMagnitudeMKSValue, 
                     CATDlgControl::CATDlgMagnitude iControlMagnitude);

//      Drag And Drop operations 

// The Drag and Drop methods are not to be used directly by CAA2 developpers.
// ApplicationFrame wrapped software should be used. In fact, CAA2 purpose
// is the development around CATIA itself.
//
// Set the drag and drop ability.
// In practice, the drag and drop ability may, as in CATIA V6, be given
// from a dedicated command. For example, in CATIA V6, the drag and drop
// is offered in particular during the following actions (set when entering 
// the command and supressing the availability when leaving the command):
// <ul>
// <li>Select command: when beeing inside this command, you have in particular
// the possibility to make drag and drop of features inside the application</li>
// <li>Tools/Customize: drag and drop from a toolbar to another</li>
// </ul>
// Thus, in practice, drag and drop availability is localized to a dedicated
// command.
// <p>
// After an application has called this service, the software sends the
// following events, that the application can trap:
// <ul>
// <li>when a mouse drag begins: CATDlgStartDragNotification</li>
// <li>when the cursor begins to cross a widget (the widget will be a Dialog
// framework object. For a viewer showing geometric data for example, 
// the viewer is considered globally as one widget): CATDlgDragEnterNotification</li>
// <li>when the cursor is beeing above a widget, crossing it:
// CATDlgDragOverNotification</li>
// <li>when the cursor ends crossing a widget: CATDlgDragLeaveNotification</li>
// <li>when the user does a drop above a valid father: CATDlgDropNotification</li>
// <li>when the user does a drop above nothing: CATDlgCancelDragNotification</li>
// </ul>   
// @param iAvailable
//   The drag and drop availability.
//   <br><b>Legal values</b>: <tt>1</tt> so that the drag and drop be available,
//   or <tt>0</tt> so that the drag an drop be no more available.
/**
 * @nodoc 
 */
        void SetDragAvailability(int iAvailable);
// Determine if drag and drop is currently available.
// This method gives the value currently set for drag and drop availability.
// See @href SetDragAvailability .
// @return
//   The drag and drop availability.
//   <br><b>Legal values</b>: <tt>1</tt> if the drag and drop is currently available,
//   or <tt>0</tt> if the drag an drop is not currently available.
/**
 * @nodoc 
 */
        int  GetDragAvailability();
/**
 * @nodoc 
 */
        int  GetDragState( CATDialog** source, 
                           CATDialog** target, 
                           POINTL& TargetPosition, 
                           DWORD& keyModifier);
// Start the drag and drop operation.
// The application should call this service when a CATDlgStartDragNotification 
// event is sent.
// See @href SetDragAvailability .
// @param iDataObject
//   OLE Object initialized by ApplicationFrame (Windows only). 
// @param iDragAndDropOptionsDeliveredToUser
//   The drag and drop options that will be delivered to the user.
//   During execution, the user will choose effectively between the
//   options using the CTRL key (to choose copy instead of move) and
//   the SHIFT key (CTRL and SHIFT simultaneously to choose link instead 
//   of the data itself). The cursor form will precise the current option.
//   Specifying here the options that will be delivered to the user,
//   you will cumulate them using a logical or.
//   <br><b>Legal values</b>: <tt>DROPEFFECT_COPY</tt> so that the 
//   copy be delivered, or <tt>DROPEFFECT_MOVE</tt> so that the move be delivered, 
//   or <tt>DROPEFFECT_LINK</tt> so that the link be delivered, or 
//   <tt>DROPEFFECT_SCROLL</tt> so that the scroll be delivered.
/**
 * @nodoc 
 */
        void StartDrag ( IDataObject* iDataObject, DWORD iDeliveredDragAndDropOptions );
/**
 * @nodoc 
 */
        IDataObject* GetDragDataObject();
// Cancels the drag and drop operation.
// Call this service when a a CATDlgCancelDragNotification occurs (when 
// the user does a drop above nothing). 
// See @href SetDragAvailability .
/**
 * @nodoc 
 */
        void CancelDrag();
// Set the drag and drop current option.
// The application should call this method when the current state of the keys 
// controlling the current drag and drop option (CTRL to choose copy instead 
// of move and SHIFT which, cumulated with CTRL, indicates link instead 
// of the data itself) changes.
// Changing the current option through a call to this service will
// change automatically the cursor form.
// See @href SetDragAvailability .
// @param iDragAndDropCurrentOption
//   The drag and drop current option.
//   <br><b>Legal values</b>: <tt>DROPEFFECT_COPY</tt> so that the 
//   current option be a copy, or <tt>DROPEFFECT_MOVE</tt> so that 
//   the current option be a move, or <tt>DROPEFFECT_LINK</tt> so that the 
//   current option be a link, or <tt>DROPEFFECT_SCROLL</tt> so that 
//   the current option be a scroll.
/**
 * @nodoc 
 */
        void SetDropEffect(DROPEFFECT m);
// Get the drag and drop current option.
// See @href SetDragAvailability .
// @param iDragAndDropCurrentOption
//   The drag and drop current option.
//   <br><b>Legal values</b>: <tt>DROPEFFECT_COPY</tt> if the 
//   current option is a copy, or <tt>DROPEFFECT_MOVE</tt> if 
//   the current option is a move, or <tt>DROPEFFECT_LINK</tt> if the 
//   current option is a link, or <tt>DROPEFFECT_SCROLL</tt> if 
//   the current option is a scroll.
/**
 * @nodoc 
 */
        DROPEFFECT GetDropEffect();

//      get application Name
/**
 * @nodoc 
 */
        virtual CATString GetApplicationName ();

//      get framework internal object
/**
 * @nodoc 
 */
        l_CATInteractiveApplication* GetLetterObject();

//      drag&drop from an external application
/**
 * @nodoc 
 */
        CATDeclareCBEvent(DRAGENTER);
/**
 * @nodoc 
 */
        CATDeclareCBEvent(DRAGLEAVE);
/**
 * @nodoc 
 */
        CATDeclareCBEvent(DRAGEND);
/**
 * @nodoc 
 */
        CATDeclareCBEvent(ACTIVATION);
/**
 * @nodoc 
 */
        CATDeclareCBEvent(DEACTIVATION);

/**
 * @nodoc 
 */
        CATDeclareCBEvent(DLGNOTIFYENTER);

/**
 * @nodoc 
 */
        CATCallbackManager* GetCallbackManager();

/**
 * @nodoc
 */
        CATDlgSession * GetSession ();

/**
 * @nodoc
 * Requests the ClassName, IsA, and IsAKindOf methods to be created.
 */
        CATDeclareClass ;

#ifdef DRIVER_WINDOWS
/**
 * @nodoc
 * Returns the VBA application object, along with the name
 * of the type library where this object is described.
 * The object must support all of VBA constraints (have a
 * coclass, be dual, have the appobject IDL tag, support
 * IProvideClassInfo2...). 
 */
        virtual HRESULT GetVBAApplicationObject(
                IDispatch*& oAppObject,
                CATUnicodeString& oAppName,
                CATUnicodeString& oTypelibName);
#endif // _WINDOWS_SOURCE

#if defined (DRIVER_COCOA) || defined (DRIVER_ANDROID)
#endif
	//--------------------------------------------------------------------------
 private:

//      address of internal object.
/**
 * @nodoc 
 */
        l_CATInteractiveApplication *_applicationObject;        
};

/**
 * @nodoc 
 */
#if defined (_IOS_SOURCE) || defined (_ANDROID_SOURCE)
#define DECLARE_APPLICATION(T) \
extern "C" CATInteractiveApplication * CreateApplication() \
{ \
	return new T(); \
}
#else
#define DECLARE_APPLICATION(T) \
T theApp;
#endif

#endif
