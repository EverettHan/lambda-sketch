#ifndef CATCommandHeader_H 
#define CATCommandHeader_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h" 
#include "CATAfrCommandHeader.h"
#include "CATAfrCommandHeaderArgs.h"

#include "CATEventSubscriber.h"
#include "CATBoolean.h"
#include "CATCollec.h"
#include "CATCommand.h"
#include "CATListOfCATString.h"
#include "CATListOfInt.h"
#include "CATMsg.h"
#include "CATMsgCatalog.h"
#include "CATUnicodeString.h"
#include "CATMetaObject.h"
#include "CATString.h"
#include "CATIAV5Level.h"
#include "CATCreateExternalObject.h" // To support derived command header from declarative files (D-Afr)

class CATCmdStarter;
class CATCommandHeaderList;
class CATDialog;
class CATNotification;
class l_CATCmdHeader;
class l_CATCommandHeader;
class CATCmdRep;
class CATFrmEditor;
class CATAfrAvailabilityMode;
#ifdef AfrCAA2
class CATAfrGen;
#endif

class AfrICommandHeaderVisitor;

class CATLISTP(CATCommand);

/**
* @nodoc 
* Command Header Activity.
* <b>Role</b>: Internal usage. Used  in the Callback methods set on the CATCommand event.
* @param CATFrmCmdNo
*    The command is Canceled
* @param CATFrmCmdAct
*    The command is Activated
* @param CATFrmCmdDeact
*    The command is Deactivated
* @param CATAfrChecked
*    The command is checked in check mode
* @param CATAfrUnchecked
*    The command is unchecked in check mode
* @param CATFrmCmdStarted
*    The command is started but hasn't being activated yet
*/

#define CATFrmCmdNo CATAfrUnchecked
enum CATFrmCmdState { CATAfrUnchecked,
                  CATFrmCmdAct,
                  CATFrmCmdDeact,
                  CATAfrChecked,
                  CATFrmCmdStarted};

/**
* @nodoc 
* Command Header Availability status.
* <b>Role</b>: Command Header applicative availability status.
* @param CATAfrApplicativeAvailable
*    The command header availability is available
* @param CATAfrApplicativeUnavailable
*    The command header availability is unavailable
*/
enum CATAfrApplicativeAvailabilityStatus  {CATAfrApplicativeAvailable, CATAfrApplicativeUnavailable};


/** @nodoc */
typedef int (* CATCmdRepEnabler) (void);

/**
* Command header class.
* <b>Role</b>: A command header is the link between the UI (User Interface) and the functions of an app (what we call 'Commands').
* <br>Each command you want to make available in the UI of your app 
* must have a command header. It holds the necessary information to load the command, 
* such as the name of the shared library in which the 
* command's executable code is located, the name of the command class, and the data to pass 
* to the command's code when this command will be started. 
* <p>The command header holds the necessary resources to be able to display the command representation, such as the command name shown to the end user, 
* its tooltip, its help message, and its icon. This enables the 
* workshop or workbench to be  displayed, that is loaded in memory without any of its 
* commands being itself loaded, except the default one. This mechanism spares memory space and improves 
* performance. The end user can see the commands represented in the Action Bar, in the Contextual Bar, in the contextual menu, in the menu bar, in App Options and Object Properties panels...,
* can ask for help on a given command, without the commands being loaded. The command code is actually loaded only when 
* the user clicks on a representation of this command for the first time.</p>
* 
* <p>WARNING: never directly instantiate <tt>CATCommandHeader</tt> class! This would lead to malfunction in licensed configurations.
* Use CATCreateCommandHeader function instead (see AfrFoundation\PublicInterfaces\CATAfrCommandHeader.h).
* In some cases you may want to create a <b>customized 
* command header</b> sub-class, mostly to manage the command availability (command representation selectable or not) with respect to what 
* the end user does, or what exists in the model.
* <br>The new class must at least derive from <tt>CATCommandHeader</tt>
* </ul>
* Creating a customized command header sub-class implies to have (or overwrite) at least
* the following methods:
* <ul>
*   <li>In public</li>
*   <ul>
*     <li>Constructor calling the base class constructor</li>
*     <li>Destructor</li>
*     <li>@href #Clone which calls the constructor class</li>
*   </ul>
*   <li>In private - to implement</li>
*   <ul>
*     <li>Constructor, with a <tt>CATCommandHeader</tt> pointer as argument, and 
*      calling the constructor with a <tt>CATCommandHeader</tt> of
*      the base class</li>
*   </ul>
*   <li>In private - not implemented</li>
*   <ul>
*   <li>Defauft constructor</li>
*     <li>Copy constructor</li>
*     <li>Assignment operator </li>
*   </ul>
* </ul>
* The customized command header class (named <tt>MyHeader</tt>) must be an <b>Object Modeler Component</b> able to implement 
* any kind of interfaces, so it must contain the following macros:
* <ul>
*   <li>in header file: @href CATDeclareClass </li>
*   <li>in source file: @href CATImplementClass with the following arguments: 
*      <pre>(MyHeader, Implementation, BaseClass, CATNull)</pre</li>                
* </ul>
* To assign <b>resources</b> to the command header,
* it must contain the following macros:
* <ul>
*   <li>in header file: @href CATDeclareHeaderResources ;</li>
*   <li>in source file: @href CATImplementHeaderResources with the following arguments:
*                  <pre>(MyHeader, BaseClass,MyHeaderResourceFile)</pre> </li>               
* </ul> 
* <b>Where</b> to create command header instances ? 
* Generaly, you create instances in the following methods: 
* <ul>
*   <li>@href CATIWorkbench#CreateCommands </li>
*   <li>@href CATIWorkbenchAddin#CreateCommands </li>
* </ul>
* Try to avoid it but if you absolutely want to create command headers more dynamically, for instance to populate contextual menus or bars.
* Then you should first check that the command header does not already exist, using CATGetCommandHeader function (see AfrFoundation\PublicInterfaces\CATAfrCommandHeader.h).
* In such case please call SetVisibility(0) on these command headers to avoid customization issues.
*</p>
*
* <p>How to <b>generate representations</b> of command headers in the UI?
* A command header instance, identified by the first argument of CATCreateCommandHeader
* function, may be <b>associated to a CATCmdStarter instance</b> thanks to the 
* @href SetAccessCommand macro. A command header may be associated to several CATCmdStarter instances in order to be multi-represented in the UI.</p>
*
* <p>Who <b>deletes</b> command header instances ? 
* <br>Each command header instance is kept in a list by the current @href CATFrmEditor instance. The editor manages the command header deletion. You should never 
* delete a command header instance.  </p>
*
* <p><b>Check Header (for on/off switch behaviors)</b>
* <br> In 3DEXPERIENCE, CATCheckHeader class is deprecated due to the following reasons:
* <ul>
*   <li>it can only be represented by a Dialog Framework view preventing to use it in immersive views or in the ActionBar.</li>
*   <li>it needs to be specialized to be used leading to some unnecessary applicative code to be written.</li>
* </ul>
* <br>The old CATCheckHeader is now replaced by a new behavior that can be activated on the CATCommandHeader
* class to simulate a check header. This new behavior on CATCommandHeader class changes the CATCommandHeader
* to act as a ON / OFF switch as soon as it is activated. Each time its state changes, an action is
* performed by launching the associated CATCommand (this check header behavior only supports to launch
* Undefined CATCommand).
* <br>The view of this new kind of Check Header is managed using X-Afr and representation types. That means you can
* represent it in every kind of representation supported by AfrFoundation (including Dialog and CID).
* <br>To create a new Check header, you need to instanciate a CATCommandHeader object and set its Behavior property
* to CATAfrHeaderCheck (using SetBehavior member function). Then this CATCommandHeader instance will act as
* a Check Header.
* You can then query the state of the check header by calling GetCmdState member function. A Check header in a
* OFF mode will return CATAfrUnchecked and a check header in a ON mode will return CATAfrChecked.
* Each time the Check header is started, its state is toggled. When the new state is ON, the associated command
* is started with the CATAfrCheckState argument set to 1. When the new state is OFF, the associated command
* is started with the CATAfrCheckState argument set to 0. Then the started CATCommand can get this CATAfrCheckState argument
* using CATAfrCommandHeaderArgs CATAfrGetArguments() function.
* </p>
*/

extern "C" DSYExport void * fctCreateCATCommandHeader(void *); //Necessary for friend to be understood
static CATBaseUnknown* CATSYPInstanciateCATCommandHeader(); //Necessary for friend to be understood (Unix compilers)

class ExportedByCATAfrFoundation CATCommandHeader: public CATEventSubscriber
{
  friend class CATECmdSelect;
  
  // Friends allowed to call CATCommandHeader constructors
  friend ExportedByCATAfrFoundation CATBaseUnknown * CreateCmdHdrArgs(CATString iHeaderID, CATString iLoadName, CATString iClassName,
								  void* iArgument, CATString iResourceFileName, CATString iFw, CATFrmState iState); // See CATAfrCommandHeader.h
  friend CATBaseUnknown* CATSYPInstanciateCATCommandHeader(); //For CATStyleProcessor
  friend void * fctCreateCATCommandHeader(void *); //Symbol generated by CATCreateClass System macro for dynamic instanciation from class name using CATCreateExternalObject function.
  
public:

  
  /** @nodoc */
  CATDeclareCBEvent(CommandStarted);
      /** @nodoc */
  CATDeclareCBEvent(BecomeAvailableEvent);
    /** @nodoc */
  CATDeclareCBEvent(BecomeUnavailableEvent);
    /** @nodoc */
  CATDeclareCBEvent(Cancel);
    /** @nodoc */
  CATDeclareCBEvent(Delete);
    /** @nodoc */
  CATDeclareCBEvent(Activate);
    /** @nodoc */
  CATDeclareCBEvent(Deactivate);
    /** @nodoc */
  CATDeclareCBEvent(CommandFailed);
    /** @nodoc */
  CATDeclareCBEvent(SetIconEvent);
    /** @nodoc */
  CATDeclareCBEvent(SetTitleEvent);
    /** @nodoc */
  CATDeclareCBEvent(SetAcceleratorEvent);
    /** @nodoc */
  CATDeclareCBEvent(SetUserAliasEvent);
    /** @nodoc */
  CATDeclareCBEvent(HeaderDeleted);
    /** @nodoc */
  CATDeclareCBEvent(Generic);
  /** @nodoc */
  CATDeclareCBEvent(CheckedEvt);
  /** @nodoc */
  CATDeclareCBEvent(BehaviorChanged);
  /**
   * @nodoc
   *
   * Callback CATFRM_COMMAND_ACTIVATED is dispatched by the global callback
   * manager when a shared or exclusive command is activated (for UA panel).
   */
  CATDeclareCBEvent(CATFRM_COMMAND_ACTIVATED);


  /** @nodoc */
  CATDeclareKindOf;

  /** @nodoc */
  void Initialize(const CATString & HeaderID,
      const CATString & loadName,
      const CATString & className);
  /** @nodoc */
  void Initialize(const CATString & HeaderID,
      const CATString & ClsidName);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message ("BADREM : ERS 20210301 " __FILE__ ": replace new CATCommandHeader by  a call to CATAfrCommandHeader::CATCreateCommandHeader (see AfrFoundation\\PublicInterfaces\\CATAfrCommandHeader.h)")
#else
    /*---------------------------------*/
    //     CONSTRUCTORS  
    /*---------------------------------*/
    
  /** @nodoc */
  CATCommandHeader ();

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        int state = CATFrmAvailable);

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        const CATString & loadName,
        int state = CATFrmAvailable);

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        const CATString & loadName,
        const CATString & argument,
        int state = CATFrmAvailable);

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        const CATString & loadName,
        const CATString & className,
        const CATString & argument,
        int state = CATFrmAvailable);
  

  /**
  * Constructs a command header. 
  * <br>DO NOT CALL this constructor or any other except to construct derived classes; see class comments above.
  * @param iHeaderID
  *     The identifier of the header. It iss the <tt>command</tt> argument of the <tt>
  *     SetAccessCommand </tt> macro.It iss used for NLS resources.
  * @param iLoadName
  *    The name of the shared library where <tt>iClassName</tt> is.
  * @param iClassName
  *    The name of the <tt> CATCommand </tt> class.
  * @param iArgument
  *    The argument of the <tt> CATCommand </tt> class.
  * @param iState
  *    The CATCommandHeader state.
  *    <br><b>Legal values</b>: 
  *       <li> CATFrmAvailable (The default value) </li>
  *       <li> CATFrmUnavailable </li>
  * 
  * @see CATCommand, SetAccessCommand, CATFrmState
  */
  CATCommandHeader (const CATString & iHeaderID,
                const CATString & iLoadName,
                const CATString & iClassName,
                           void * iArgument,
                              int iState = CATFrmAvailable);
#endif
  
  virtual ~CATCommandHeader ();
  
  /**   
  * Clones the command header.
  * <br<b>Role:</b>This method calls the constructor with a <tt>CATCommandHeader</tt> 
  *  pointer as argument. In your derived class overwrite this method such that:
  *  
  * <pre>
  * CATCommandHeader * MyHeader::Clone ()                                  
  * { 
  *   return new MyHeader(this); 
  * }   
  * </pre>
  * You must never call a <tt>Clone</tt> method. This method is called by the "frame".
  * Today, it is called for your CAA instances in only one case: when the command header 
  * instance is created in an Add-in of the General workshop, refer to the 
  * @href CATIAfrGeneralWksAddin interface for more details about these Add-ins. 
  * @return 
  *  The new command header instance.
  */
  virtual CATCommandHeader * Clone();
  
    /*---------------------------------*/
    //     STATISTICS
    /*---------------------------------*/
  /**
  * @nodoc
  * Returns the last statistics identifier .
  * <b>Role</b>: This id can be used by a undefined command to supend/resume
  * the command header statistics time.
  */
  int GetLastStatisticIdentifier();
  
    /*---------------------------------*/
    //     COMMAND HEADER MANAGMENT  
    /*---------------------------------*/
  
  /**
  * @nodoc
  * Returns the header identifier.
  * <b>Role</b>: 
  */
  const char * GetID ();

   /**
  * @nodoc
  * Returns the header Alias.
  * <b>Role</b>: The alias id of a header can be defined in a CATRsc file. The name
  * of this file depends on the workshop or workbench or addin origin of the header.
  */
  const char * GetAlias ();

  /** @nodoc
  * Returns a boolean indicating if the CATCommandHeader should be available in
  * the customize panel.
  * <br><b>Role</b>: Initially, GetVisibility was used to do that but other behaviors have been
  * linked to this property (SetAccelerator, filtering commands in the result of
  * the PowerInput Bar). It is impossible to force the visibility of CATCommandHeader
  * to false for header created during the application lifecycle (see CATCommandHeaderVisibilityGuard
  * for more information) without impacting legitimate behaviors in an application.
  * The decision was made to create a new dedicated flag to implement this behavior.
  * @return
  *  The header isCutomizable flag value.
  * <br><b>Legal values</b>: <tt>true</tt> customizable, <tt>false</tt>: not customizable.
  */
  bool IsCustomizable();

  /**
  * Returns the header visibility in the Customize command list.
  * <br><b>Role</b>: This method returns if the command header is visible or not
  * in the Customize command list.
  * <br>Furthermore, in the case where the header is not visible,
  * accelerator will not be applied calling CATCommandHeader::SetAccelerator.
  * <br>The PowerInput also relies on the visibility using only visible 
  * CATCommandHeader in its search.
  * @return
  *  The header visibility in the Tools/Customize command.
  * <br><b>Legal values</b>: <tt>1</tt> Visible, <tt>0</tt> : invisible
  */
  virtual int GetVisibility      ();

  /**
  * Sets the header visibility in the Customize command list.
  * <br><b>Role</b>: This method enables you to hide or show the 
  * command header instance in the Customize command list. It can be interesting
  * to hide some command header instances, when you do not want that the end user 
  * uses your command in a UI customization.
  * <br>Note also that CATCommandHeader::SetAccelerator will have no effect on
  * headers having a visibility set to 0 and that it will not be take into account
  * in the PowerInput search.
  * @param iIsVisible
  * The header visibility in the Customize command list.
  * <br><b>Legal values</b>: <tt>1</tt> Visible (default value), <tt>0</tt> : invisible
  */
  void        SetVisibility(int iIsVisible);

	 /**
  * Returns the header visibility in the customize context component panel.
  * <br><b>Role</b>: This method returns if the command header is visible or not
  * in the customize context component panel.
  * @return
  *  The header visibility in the customize context component panel.
  * <br><b>Legal values</b>: <tt>1</tt> Visible, <tt>0</tt> : invisible
  */
  virtual int GetCtxComponentVisibility ();

  /**
  * Sets the header visibility in the customize context component panel.
  * <br><b>Role</b>: This method enables you to hide or show the 
  * command header instance in the customize context component panel. 
  * @param iIsVisible
  * The header visibility in the customize context component panel.
  * <br><b>Legal values</b>: <tt>1</tt> Visible, <tt>0</tt> : invisible
  */
  void        SetCtxComponentVisibility(int iIsVisible);
  
    /*---------------------------------*/
    //     NLS-RSC
    /*---------------------------------*/

  /**
  * @nodoc
  * Types of representations
  */
  enum CATAfrAccessRepType { AfrBarRep, AfrMenuRep, AfrContextRep };
  
  /**
  * @nodoc
  * Modes of visualization
  */
  enum CATCmdAccessRepVisu { AfrDialogRep, AfrWindowsRep, AfrImmersiveRep };

	
  /** @nodoc */
  enum CATIconState { NormalIcon = 0, GreyedIcon = 1,
                      PressedIcon = 2, GreyedPressedIcon = 3,
                      FocusedIcon = 4 };
  /**
  * @nodoc
  * @param iState
  *    use a combination of NormalIcon, GreyedIcon
  *    and PressedIcon with | for state
  */
  void         SetIconName (const CATString & iconName, int iState = 0);
                              
  /** @nodoc */
  void         SetAccelerator(const CATUnicodeString &accelerator);
  /** @nodoc */
  void         SetCategory2(const CATUnicodeString &category);

  /** @nodoc */
  virtual void SetUserAlias(const CATUnicodeString & userAlias);

  /** @nodoc */
  virtual void SetTitle    (const CATUnicodeString & nlsCommandName);
  /** @nodoc */
  void         SetHelpRsc  (const CATString & helpRsc);
  /** @nodoc */
  void         SetHelp     (const CATUnicodeString & help);
  /** @nodoc */
  void         SetShortHelp(const CATUnicodeString & help);
  /** @nodoc */
  void         SetShortHelpIconName(const CATString & icon);
  /** @nodoc */
  void         SetShortHelpIconDimension(const unsigned int iWidth, const unsigned int iHeight);
  /** @nodoc */
  void         SetDialogLongHelp(const CATUnicodeString & help);
  /** @nodoc */
  void         SetLongHelpIconName(const CATString & icon);
  /** @nodoc */
  void         SetLongHelpIconDimension(const unsigned int iWidth, const unsigned int iHeight);

 /** @nodoc */
  CATUnicodeString         & GetAccelerator     ();

  /** @nodoc */
  CATUnicodeString         & GetDefaultAccelerator();

  /** @nodoc */
  CATUnicodeString         & GetUserAlias       ();

  /** @nodoc */
  CATUnicodeString         & GetDefaultUserAlias       ();

  /** @nodoc */
  CATUnicodeString         & GetCategory2       ();
  /** @nodoc */
  virtual CATString        & GetHelpRsc         ();
  /** @nodoc */
  virtual CATUnicodeString & GetHelp            ();
  /**
  * @nodoc
  * Returns an icon's name .
  * @param iIconType
  * Type of the icon. Use a value defined in @href CATIconState
  */
  virtual CATString          GetIconName        (int iIconType = 0);

  /** @nodoc */
  CATString                  GetDefaultIconName (int iIconType = 0);

  /** @nodoc */
  virtual CATUnicodeString & GetShortHelp       ();
  /** @nodoc */
  virtual CATUnicodeString & GetTitle           ();

  /** @nodoc */
  CATUnicodeString & GetDefaultTitle            ();

  /** @nodoc */
  virtual void               ShowLongHelp       ();
  /** @nodoc */
  virtual CATUnicodeString & GetContextualHelp  ();
  /** @nodoc */
  virtual void               SetContextualHelp  (CATUnicodeString);
  /** @nodoc */
  virtual CATString          GetContextualDocModule();
  /** @nodoc */
  virtual void               SetContextualDocModule  (CATString);
  /** @nodoc */
  virtual CATUnicodeString & GetDialogLongHelp  ();

 /** @nodoc */
  virtual CATString & GetShortHelpIconName  ();
 /** @nodoc */
  unsigned int GetShortHelpIconWidth  ();
 /** @nodoc */
  unsigned int GetShortHelpIconHeight  ();
 /** @nodoc */
  virtual CATString & GetLongHelpIconName  ();
 /** @nodoc */
  unsigned int GetLongHelpIconWidth  ();
 /** @nodoc */
  unsigned int GetLongHelpIconHeight  ();

 /** @nodoc */
  virtual CATString GetResourceFile(int depth);
 /** @nodoc */
  virtual int       GetResourceValue (const CATString  & key,
                              CATUnicodeString & resource);
  /** @nodoc */
  virtual int       GetResourceValue (const CATString & key,
                              CATString & resource);
  
    /*---------------------------------*/
    //     Representations
    /*---------------------------------*/

  /**
  * @nodoc
  * Creates a representation for a header.
  * Calls protected methods BarRepCreation, MenuRepCreation, ContextRepCreation.
  */
  CATCmdRep * RepCreation (CATCmdStarter *pItem, CATBaseUnknown *parent, CATAfrAccessRepType RepType, CATCmdAccessRepVisu RepVisu = AfrDialogRep);

  /**
  * @nodoc
  * Deletes a representation of a header.
  * Calls protected methods BarRepDeletion, MenuRepDeletion, ContextRepDeletion.
  */
  void RepDeletion (CATCmdStarter *pItem, CATAfrAccessRepType RepType, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /** @nodoc */
  void AddRep();
  /** @nodoc */
  void ReleaseRep();

  /** @nodoc */
  int NbRep() const;

  /** @nodoc */
  int                 CanCreateRep      () const;
  
  /** @nodoc */
  void                SetRepEnabler     (CATCmdRepEnabler);

  /** @nodoc */
  static int          OleRepDisable     ();


    /*---------------------------------*/
    //     CATCOMMAND's PART 
    /*---------------------------------*/

  /** @nodoc */
  virtual void SetName     (const CATString & loadName);

  /** @nodoc */
  virtual CATString        & GetClass           ();
  /** @nodoc */
  virtual CATString        & GetClsidName       ();
  /** @nodoc */
  virtual CATString        & GetName            ();
  /** @nodoc */
  virtual CATString        & GetOptionPage      ();

  /**
   * @nodoc
   *
   * GetArgs returns a reference on the CATAfrCommandHeaderArgs object associated
   * to the CATCommandHeader instance.
   * The CATAfrCommandHeaderArgs corresponds to the list of arguments given to the
   * launched CATCommand associated to this CATCommandHeader.
   * WARNING: When you have finished to use the reference, you need to call Release on it
   * (unusual way to use a reference but legacy).
   *
   * Sample:
   * // Get a command header by its name
   * CATCommandHeader * pHeader = (CATCommandHeader *)CATAfrCommandHeader::CATGetCommandHeader("MyHeaderID");
   * if (nullptr == pHeader)
   *   return;
   *
   * // Get its arguments list to populate it. Note the return by reference.
   * CATAfrCommandHeaderArgs & argList = pHeader->GetArgs();
   *
   * // Here you can add your arguments to the list using the CATAfrCommandHeaderArgs::Set function
   * argList.Set("MyArgument", CATBoxingOfint::Box(1));
   *
   * // When you finished to set your arguments, don't forget to release the arguments list
   * argsList.Release();
   *
   * @return [CATBaseUnknown#Release]
   */
  CATAfrCommandHeaderArgs & GetArgs();

  /** @nodoc */
  CATString GetArgument();

  /** @nodoc */
  void * GetPtrArgument();

  /** @nodoc */
  void         SetArgument (const CATString & argument);

  /** @nodoc */
  void         SetArgument (void * argument);
  /** @nodoc */
  void         SetCharArgument (const CATString & argument);
  /** @nodoc */
  CATString &  GetCharArgument ();

    /*---------------------------------*/
    //     COMMAND HEADER  ACTIVITY
    /*---------------------------------*/
  /** @nodoc */
  virtual int            GetCmdState      ();
  /**
   * Set the state of the header without starting the associated command.
   *
   * Note: This function can and must only be used with a CATCommandHeader
   * with Check behavior.
   *
   * i_state: either CATAfrUnchecked or CATAfrChecked
   */
  void SetCmdState(int i_state);

  /**
   * @nodoc
   * Command Header Behavior.
   * <b>Role</b>: Used to set the behavior of the command header (how it reacts
   * to press and release events).
   * @param Standard
   *    The command header starts the associated command when pressed
   * @param Check
   *    The command header starts the associated command with "ON" argument at
   *    first click, and starts the associated command with "OFF" argument at
   *    second click. Between first and second click, the representation is
   *    active.
   */
  enum CATAfrHeaderBehavior
  {
    CATAfrHeaderStandard = 0,
    CATAfrHeaderCheck
  };

  /**
   * @nodoc
   * Set the behavior of the command header.
   *
   * @param i_behavior the new behavior to set.
   *
   * see CATAfrHeaderBehavior documentation.
   */
  void SetBehavior(CATAfrHeaderBehavior i_behavior);

  /**
   * Get the behavior of the command header.
   *
   * @return the behavior of the command header.
   *
   * see CATAfrHeaderBehavior documentation.
   */
  CATAfrHeaderBehavior GetBehavior();

  /** @nodoc */
  int HasCommand();

  /**
  * @nodoc
  * Starts the command.
  * <br><b>Role</b>: The CATCommand associated to the header is created and launched.
  * <br> DO NOT OVERWRITE this method, if needed overwrite ExecuteCommand one that is empty in the base class and that is called by StartCommand when the header is OK to be started.
  * If you really want to overwrite this method, think to:
  * <ul>
  * <li></li> Test if the command is available: @href IsAvailable, and return NULL if it's not
  * the case.
  * <li></li> Set the cursor Busy 
  * <li></li> Set callbacks on the activate, delete, cancel and desactivate event of 
  * the CATCommand.
  * </ul>
  */
  virtual CATCommand * StartCommand       ();
  /** @nodoc 
  * Called by StartCommand in legal cases and empty in base class.
  */
  virtual CATCommand * ExecuteCommand     ();
  /** @nodoc */
  static  CATCommand * StartCommand       (const CATString & commandName);
  /**
   * @nodoc
   *
   * To override the behavior when a command is stopped, you can implement in
   * derived classes the StopCommandImpl member function.
   */
  void         StopCommand        ();
  /** @nodoc */
  static void          StopCommand        (const CATString & commandName);

  /**
  * Retrieves the argument of the header.
  */
  static CATString   & GetCurrentArgument ();
  
    /*---------------------------------*/
    //     COMMAND HEADER AVAILABILITY 
    /*---------------------------------*/
  /** @nodoc */
  int                IsAvailable ();
  
  /** 
  * Makes the command Available.
  * <br><b>Role</b>: The command of the header becomes available. The icon or other representation switches from
  * the grayed to the normal state.
  */
  virtual void               BecomeAvailable   ();
  
  /** 
  * Makes the command Unavailable.
  * <br><b>Role</b>: The command of the header becomes unavailable. The iconor other representation switches from
  * the normal to the grayed state.  
  */
  virtual void               BecomeUnavailable ();

  /** 
  * Makes the command Available in all availability modes.
  * <br><b>Role</b>: The command of the header becomes available. The icon or other representationswitches from
  * the grayed to the normal state.
  */
  virtual void               BecomeAlwaysAvailable ();
  
    /*---------------------------------*/
    //     COMMAND HEADER REPEATABILITY
    /*---------------------------------*/

  /** @nodoc 
  value
  -1 - DEFAULT (you didn't call CATCommandHeader::SetRepeatability): 

     a) The command implement the interface CATIRepeatableCommand => The command itself manages the behavior on double click. 
     b) The command is ONE SHOT                                   => The command is LAUNCHED A 2ND TIME on the 2nd click (double-click == 2 clicks). NO REPEAT MODE! 
     c) The command is NOT ONE SHOT and EXCLUSIVE                 => The command is set in REPEAT MODE (i.e. the command will be relaunched each time it ends). REPEAT MODE! 
     d) The command is NOT ONE SHOT and SHARED or UNDEFINED       => The command is STOPPED ON 2ND CLICK (double-click == 2 clicks, treated here like 2 simple clicks).d NO REPEAT MODE! 

  0 - Explicitly DEACTIVATED (you called CATCommandHeader::SetRepeatability(0)):

     a) The command is ONE SHOT                                   => The command is LAUNCHED A 2ND TIME on the 2nd click (double-click == 2 clicks). NO REPEAT MODE! 
     b) The command is NOT ONE SHOT (same for all command mode)   => The command is STOPPED ON 2ND CLICK (double-click == 2 clicks, treated here like 2 simple clicks). NO REPEAT MODE! 

  1 - Explicitly ACTIVATED (you called CATCommandHeader::SetRepeatability(1)): 

     b) Same for all type of command                              => The command is set in REPEAT MODE (i.e. the command will be relaunched each time it ends). REPEAT MODE! 
  */
  void SetRepeatability(int CanBeRepeated); // 1 for true, 0 for false
  /** 
  * @nodoc 
  * @return 
  * -1 default value (see above), 1 for true (repeat mode), 0 for false (not repeat mode)
  */
  int  GetRepeatability();  
  /** @nodoc */
  virtual void Repeat();
  
    /*---------------------------------*/
    //     RESEARCH COMMAND HEADER BY ID
    /*---------------------------------*/

  /** @nodoc */
  static int                GetHeaderCount   (const CATBoolean forceWorkbenchesLoad = TRUE);

  /** @nodoc */
  static CATCommandHeader * GetHeaderFromList(const
                CATString & commandHeaderID, const CATBoolean forceWorkbenchesLoad = TRUE);

  /** @nodoc */
  static CATCommandHeader * GetHeaderFromList(int position);

  /**
  * @nodoc
  * Researchs an instance by its ID .
  * <b>Role<b>: Necessary only in very special cases when the current editor is not the editor of the
  * command to activate.
  */
  static CATCommandHeader * GetHeaderFromNoCurrentList(
    const CATString & iCommandHeaderID, CATFrmEditor    * iEditor, const CATBoolean forceWorkbenchesLoad = TRUE);
  
 
    /*---------------------------------*/
    //     Callbacks
    /*---------------------------------*/

  /** @nodoc */
  virtual void DeleteCB     (CATCallbackEvent, void *, CATNotification *,
           CATSubscriberData, CATCallback);
  /** @nodoc */
  virtual void CancelCB     (CATCallbackEvent, void *, CATNotification *,
           CATSubscriberData, CATCallback);
  /** @nodoc */
  virtual void ActivateCB   (CATCallbackEvent, void *, CATNotification *,
           CATSubscriberData, CATCallback);
  /** @nodoc */
  virtual void DeactivateCB (CATCallbackEvent, void *, CATNotification *,
           CATSubscriberData, CATCallback);

  /** @nodoc */
  void         lSetIconCB       (CATCallbackEvent, void *, CATNotification *,
         CATSubscriberData, CATCallback);
  /** @nodoc */
  void         lSetAcceleratorCB(CATCallbackEvent, void *, CATNotification *,
         CATSubscriberData, CATCallback);
  /** @nodoc */
  void         lSetUserAliasCB(CATCallbackEvent, void *, CATNotification *,
         CATSubscriberData, CATCallback);
  /** @nodoc */
  void         lSetTitleCB      (CATCallbackEvent, void *, CATNotification *,
         CATSubscriberData, CATCallback);
  
    /*---------------------------------*/
    //     LICENSING
    /*---------------------------------*/
  
  /** @nodoc */
  virtual const char * GetFW();
  
  /** @nodoc */
  void SetAuthorizationLevel(int level);
  /** @nodoc */
  int  GetAuthorizationLevel();
  

    /*---------------------------------*/
    //     FOR INTERNAL USAGE 
    /*---------------------------------*/
  /** @nodoc */
  l_CATCmdHeader     * GetCmdLetterObject();
  /** @nodoc */
  l_CATCommandHeader * GetLetterObject ();
  /** @nodoc */
  const CATString & GetOrigin() const;
  /** @nodoc */
  const CATString & GetOriginWorkbench() const;
  /** @nodoc */
  static CATString LastCommandName;
  /** @nodoc */
  static CATString LastCommandArgument;
  /** @nodoc */
 
    /*---------------------------------*/
    //     CREATION BY CLSID 
    /*---------------------------------*/
#ifdef AfrCAA2
  /** @nodoc */
  virtual void SaveAsXml (CATAfrGen * Gen, int depth);
  /** @nodoc */
  void SetWorkElement (const CATString & type);
  /** @nodoc */
  int  GetWorkElement (CATString & WorkElement);
  /** @nodoc */
  void SetHdrLib (const CATString & iLib);
  /** @nodoc */
  void SetHdrClass (const CATString & iClass);
  /** @nodoc */
  void SetHdrClsidName (const CATString & iClsid);
  /** @nodoc */
  void SetHdrCharArgument(const CATString& iArg);
  /** @nodoc */
  CATString & GetHdrCharArgument();
#endif

  /**
  * @nodoc
  * method  to override for first treatments (@see CATBaseUnknown)
  */
  virtual HRESULT LogicalBirth();  
  /**
  * @nodoc
  * method  to override symetric as @href #LogicalBirth
  */
  virtual HRESULT LogicalDeath();     

  /** @nodoc */
  void SetAvailability (CATAfrAvailabilityType, CATFrmState);

  /** @nodoc */
  CATFrmState GetAvailability (CATAfrAvailabilityType);

  // 2 obsoletes:
  /** @nodoc */
  void SetApplicativeAvailability (CATAfrApplicativeAvailabilityStatus);
  /** @nodoc */
  CATAfrApplicativeAvailabilityStatus GetApplicativeAvailability ();

  /**
    * @nodoc
    * This is an internal method. Do not use it. Only one special mechanism uses it.
    */
  void SetLockUnavailable (CATClassId classId, CATBoolean locked);

  /** @nodoc */
  void SetLockUnavailable (CATBoolean locked);

  /** @nodoc */
  void SetOption (const char * opt);
  /** @nodoc */
  const char * GetOption () const;

  /** @nodoc */
  void IncrementUseCount ();
  /** @nodoc */
  void DecrementUseCount ();
  /** @nodoc */
  int GetUseCount ();
  /** @nodoc */
  void ExcludeOfMostUsed ();
  /** @nodoc */
  void SetHdrWeight (float iWeight);
  /** @nodoc */
  float GetHdrWeight ();
 
  /** @nodoc */
  void SetResourceFile(const CATString &);
  void SetFW(const CATString &);


    /*---------------------------------*/
    //  Declarative Application Frame 
    /*---------------------------------*/
  void SetID(const CATString &);
  void SetSharedLibraryName(const CATString &);
  const CATString & GetSharedLibraryName();
  void SetClassName(const CATString &);
  const CATString & GetClassName();
  void SetAvailable(int);
  int GetAvailable() const;
  CATString GetResourceFile();
  CATBaseUnknown_var GetItem();
  void SetAvailabilityMode(CATAfrAvailabilityMode & i_availabilityMode);
  CATAfrAvailabilityMode GetAvailabilityMode() const;

  void SetRGID(CATString iRGID);
  CATString GetRGID();

  virtual void AcceptVisitor(AfrICommandHeaderVisitor* i_pVisitor);


protected:

#if defined(REMOVE_USELESS_INCLUDE)
    /*---------------------------------*/
    //     CONSTRUCTORS  
    /*---------------------------------*/
    
  /** @nodoc */
  CATCommandHeader ();

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        int state = CATFrmAvailable);

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        const CATString & loadName,
        int state = CATFrmAvailable);

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        const CATString & loadName,
        const CATString & argument,
        int state = CATFrmAvailable);

  /** @nodoc */
  CATCommandHeader (const CATString & HeaderID,
        const CATString & loadName,
        const CATString & className,
        const CATString & argument,
        int state = CATFrmAvailable);
  

  /**
  * Constructs a command header. 
  * @param iHeaderID
  *     The identifier of the header. It iss the <tt>command</tt> argument of the <tt>
  *     SetAccessCommand </tt> macro.It iss used for NLS resources.
  * @param iLoadName
  *    The name of the shared library where <tt>iClassName</tt> is.
  * @param iClassName
  *    The name of the <tt> CATCommand </tt> class.
  * @param iArgument
  *    The argument of the <tt> CATCommand </tt> class.
  * @param iState
  *    The CATCommandHeader state.
  *    <br><b>Legal values</b>: 
  *       <li> CATFrmAvailable (The default value) </li>
  *       <li> CATFrmUnavailable </li>
  * 
  * @see CATCommand, SetAccessCommand, CATFrmState
  */
  CATCommandHeader (const CATString & iHeaderID,
                const CATString & iLoadName,
                const CATString & iClassName,
                           void * iArgument,
                              int iState = CATFrmAvailable);
#endif
  /**
  * Constructs a command header instance.
  * <br<b>Role:</b>This method calls the copy constructor. 
  * In your derived class overwrite this method such that:
  * 
  * <pre>
  * MyHeader::MyHeader(CATCommandHeader * iHeaderToCopy):
  *                           CATCommandHeader(iHeaderToCopy)
  * {
  * }   
  * </pre>
  * This method is called by the @href #Clone method.
  * @param iHeaderToCopy
  * The header to copy. 
  */
  CATCommandHeader (CATCommandHeader * header);
  
  /**
  * @nodoc
  * Creates a representation for a header in a toolbar.
  * Should be overloaded by every kind of header that wants to be representable in a toolbar.
  */
  virtual CATCmdRep * BarRepCreation (CATCmdStarter *pItem, CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for a header in a menu.
  * Should be overloaded by every kind of header that wants to be representable in a menu.
  */
  virtual CATCmdRep * MenuRepCreation (CATCmdStarter *pItem, CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for a header in a contextual menu.
  * Should be overloaded by every kind of header that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual CATCmdRep * ContextRepCreation (CATCmdStarter *pItem, CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a header in a toolbar.
  * Should be overloaded by every kind of header that wants to be representable in a toolbar.
  */
  virtual void BarRepDeletion (CATCmdStarter *pItem, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a header in a menu.
  * Should be overloaded by every kind of header that wants to be representable in a menu.
  */
  virtual void MenuRepDeletion (CATCmdStarter *pItem, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a header in a contextual menu.
  * Should be overloaded by every kind of header that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual void ContextRepDeletion (CATCmdStarter *pItem, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  //------------------ Obsolete methods -------------------
  /** @nodoc */
  virtual CATCmdRep * CreateMenuRep     (CATCmdStarter *, CATDialog *);
  /** @nodoc */
  virtual void        DestroyMenuRep    (CATCmdStarter *);
  /** @nodoc */
  virtual CATCmdRep * CreateToolbarRep  (CATCmdStarter *, CATDialog *);
  /** @nodoc */
  virtual void        DestroyToolbarRep (CATCmdStarter *);
  /** @nodoc */
  virtual void        SetDragDropModeForCommand(CATDialog *parent, CATCmdRep *rep);
  /** @nodoc */
  virtual void        UnsetDragDropModeForCommand(CATCmdRep *rep);
  /** @nodoc */
  virtual CATCmdRep * CreateCtxMenuRep  (CATCmdStarter *, CATDialog *);
  /** @nodoc */
  virtual void        DestroyCtxMenuRep (CATCmdStarter *);
  //------------------ End obsolete methods -------------------


  /** @nodoc */
  virtual void DoShow();
  /** @nodoc */
  virtual void DoHide();
  
  /** 
  * @nodoc 
  * Use ONLY inside ExecuteCommand !
  * See SetArgument otherwise
  */
  void SetCurrentArgument ();   
    
  /** @nodoc */
  CATString _Argument;
  /** @nodoc */
  CATCommandMode           _Mode;
  /** @nodoc */
  CATLISTP(CATCommand)   * _CommandList;
  /** @nodoc */
  CATFrmEditor           * _Editor     ;   // Creation's editor 
  /** @nodoc */
  CATCmdRepEnabler         _cmdRepEnabler;
  /** @nodoc */
  int                      _UseCount;
  /** @nodoc */
  float                    _HdrWeight;
  /** @nodoc */
  CATString _contextualDocModule;
  
  /** @nodoc */
  virtual void Init      (const CATString & HeaderID,
      const CATString & LoadName,
      const CATString & ClassName);

  /**
   * Concrete implementation of StopCommand member function.
   * The NVI pattern is used here because it was not possible to make virtual
   * StopCommand member function (as it is hidden by some derived classes that
   * have declared StopCommand member function).
   *
   * So, to override the behavior when a command is stopped, StopCommandImpl
   * needs to be implemented in derived classes.
   */
  virtual void StopCommandImpl();

  /**
   * Activate manually the representation by dispatching the CommandStarted
   * notification.
   */
  void ActivateRep();

  /**
   * Deactivate manually the representation by dispatching the Deactivate
   * notification.
   */
  void DeactivateRep();

  /**
   * Indicates when the header is double clicked.
   *
   * @return -1 when the header has not the behavior CATAfrHeaderCheck. 1 when
   * the header has been started with a double click, 0 otherwise.
   *
   * @note
   * This member function can only be used when the header has the behavior
   * CATAfrHeaderCheck. Otherwise, it will always return -1.
   *
   * It only aims to support compatibility with old CATCheckHeader. So this
   * member function will be called from a CATCommandHeader::StartCommand
   * member function overloading in an inherited class of CATCommandHeader.
   */
  int IsDoubleClicked();

private:

  // Copy constructor (not implemented)
  CATCommandHeader(const CATCommandHeader&);
  
  // Assignment operator (not implemented)
  CATCommandHeader& operator=(const CATCommandHeader&);

  
  void lGenericCB(CATCallbackEvent, void *, CATNotification *,
              CATSubscriberData, CATCallback);
  

  CATString _resourceFileName;  
  CATString _fwName;

  int          _State;
  unsigned int _Availability;
  CATListOfCATString _LockIds;
  CATListOfInt       _LockStates;

  int         _CommandState;
  void      * _pArgument;
  CATString * _charArg;
  CATAfrCommandHeaderArgs _argList;

  //HEB RADIO GROUP CLONAGE ISSUE
  CATString _sRGID;

#ifdef AfrCAA2
  CATString _HdrCharArg;
#endif
  

  
  l_CATCmdHeader       * _CmdLetter;
  l_CATCommandHeader   * _Letter;
  CATCommandHeaderList * _List;
  
  int _level;
  int _nbRep;
  
  static CATString     _CurrentArgument;
  static CATCommand  * _NotifSender;

  CATString _originAccess;
  CATString _originWorkbench;

#ifdef AfrCAA2
  CATString  _HdrLib;
  CATString  _HdrClass;
  CATString  _HdrClsid;
  //  CATString * _WorkElement;
#endif
  int _cmd;
  
  CATString  * _Option;

    // To manage statistic
  int                     _LastEventID ;
  static CATUnicodeString _CATCommandHeaderEmptyCUS;
  static CATString        _CATCommandHeaderEmptyCS;

  CATAfrHeaderBehavior _hdrBehavior;

  protected :
  /** @nodoc */
  CATBoolean  _repeatCmdAllowed;

};

//-----------------------------------------------------------------------------
/**
* Defines a method to get the header's resource file.
* <b>Role</b>: Insert this macro in the header file (.h) of your header class 
* and Use it in conjunction with @href CATImplementHeaderResources in the .cpp file.
*/

#define CATDeclareHeaderResources         \
public:                 \
                    \
  virtual const char * GetFW();           \
  virtual CATString GetResourceFile(int depth)

/** @nodoc */
#define MkHeaderStr(x)  #x
/** @nodoc */
#define XMkHeaderStr(x) MkHeaderStr(x)

/**
*  Implements the methods to get the header's resource file.
*  @param DerivedHeader
*      Command header class name 
*  @param BaseHeader
*      Base class of your header class. 
*  @param Rsrc
*      Resource file name
*      There is a Nls resources file , where each part must be translated
*      and there is a Rsc file. <tt>HeaderID</tt> is the identifier of the
*      header, in other words the first argument of the command header constructor class.
*     <dl>
*     <dt>In the <tt>Rsrc.CATNls</tt> file you find:
*     <br>
*     <ul>
*     <li><tt>Rsrc.HeaderID.<b>Title</b></tt></li>
*     <dt>Text displayed in the menu bar for the command
*     <li><tt>Rsrc.HeaderID.<b>Help</b></tt></li>
*     <dt>Text displayed in the status bar as the command help 
*     message when the mouse moves over   the command 
*     <li><tt>Rsrc.HeaderID.<b>ShortHelp</b></tt></li> 
*     <dt>Text displayed in a balloon as the command short help message 
*      when the mouse moves over the command. 
*     <li><tt>Rsrc.HeaderID.<b>LongHelp</b></tt></li>
*     <dt>Text displayed in a balloon when the end user clicks on the help command, 
*     which turns the mouse cursor as a question mark, 
*     and then clicks on the icon representing the command.
*     <li><tt>Rsrc.HeaderID.<b>Category</b></tt></li>
*     <dt>In Tools/Customize/Command, its a means to sort commands. 
*     </ul>
*     <br>
*     <dt>In this <tt>Rsrc.CATRsc</tt> file you find:
*     <ul>
*     <li><tt>Rsrc.HeaderID.<b>Icon.Normal</b></tt></li>
*     <li><tt>Rsrc.HeaderID.<b>LongHelpId</b></tt></li> 
*     <dt>Identifier to associate a URL with the command. The URL is stored in a .map file 
*     <li><tt>Rsrc.HeaderID.<b>Accelerator</b></tt></li>
*     <dt>A combination of keys, such as "Ctrl+character", used to activate the command 
*     directly (known as shortcut in Microsoft publications.) 
*     </ul>
*     </dl>
*  @see CATDeclareHeaderResources
*/
#define CATImplementHeaderResources(DerivedHeader, BaseHeader, Rsrc)  \
                  \
const char * DerivedHeader::GetFW()         \
{                 \
  return XMkHeaderStr(_MK_FWNAME_);         \
}                 \
                  \
CATString DerivedHeader::GetResourceFile(int depth)                     \
{                 \
  static CATString rsrc(#Rsrc);           \
  return (depth <= 0) ? rsrc : BaseHeader::GetResourceFile(depth - 1);  \
}
// Attention! La mise de la variable static implique que tous les headers 
// doivent être dérivés.


/**
 * Defines a method to get the header's resource file, in a special way.
 * <b>Role</b>: When the role of the header is defined in its constructor, 
 * insert this macro in its header file (.h)
 * and use it in conjunction with @href CATImplementHeaderSpecialResources 
 * in the .cpp file.
 * <br><br>
 * The difference with CATDeclareHeaderResources is that the resources files 
 * for different instances of this header, have a different name.
 * <br>Thus, if the role of the header is defined in its constructor, one needs 
 * to define specialized resources attached to every instance of this header. 
 * This is all the more true, when the different instanciations are made from 
 * different frameworks.
 * <br><br>
 * <b>Important points</b>:
 * <ul>
 * <li>Once <tt>CATDeclareHeaderSpecialResources</tt> has been used in a class D1, 
 * all derived classes from D1 must exclusively use this macro, and not 
 * <strike>CATDeclareHeaderResources</strike>.</li>
 * <li>When using this macro, a <tt><b>_ResourceFileNamePrefix</b></tt> CATString data 
 * member is thus defined. It <b>must</b> be valuated through in the class 
 * constructor.</li>
 * </ul>
 * <br><br>
 * Refer to @href CATImplementHeaderSpecialResources for more details, 
 * and an implementation example.
 */

#define CATDeclareHeaderSpecialResources          \
public:                                           \
  virtual const char * GetFW();                   \
  virtual CATString GetResourceFile(int depth);   \
  virtual CATString GetSpecialResourcesFile(const CATString& iSuffix);\
protected:                                        \
  CATString _ResourcesFileNamePrefix


/**
 * Implements the methods to get the header's resource file. 
 * <br><br>
 * The difference with CATImplementHeaderResources is that the resources 
 * files have a different name, which is useful if your header or any directly 
 * derived class can be instanciated from different frameworks.
 * <br><br>
 * Indeed, there can be only one resources file of the same name, whereever in 
 * the code. A more detailed explanation follows in the parameters' descriptions.
 * <br><br>
 * <b>Let us imagine the following scenario:</b>
 * <ul>
 * <li> a BaseHeader using CATDeclareHeaderResources and 
 * CATImplementHeaderResources(BaseHeader, BaseBaseHeader, BaseRsc). <br><br></li>
 * <li> a DerivedHeader1 deriving from BaseHeader, and
 * <ol><li>which role is specific for every instanciation, and therefore is 
 * using CATDeclareHeaderSpecialResources and 
 * CATImplementHeaderSpecialResources(<b>DerivedHeader1</b>, BaseHeader, <b>DerivedRsc1</b>) 
 * macros. </li>
 * <li> which constructors is of the following kind:<br>
 * <tt>DerivedHeader1(const CATString& iHeaderId,</tt><i>arguments for role definition</i>, 
 * <tt><b>const CATString& iResourcesFileNamePrefix1</b>);</tt></li>
 * <li> where <tt><b>iResourcesFileNamePrefix1</b></tt> is stored in the 
 * <tt><b>_ResourcesFileNamePrefix</b></tt> 
 * data declared by the <tt>CATDeclareHeaderSpecialResources</tt> macro.
 * </li></ol><br><br></li>
 * <li> a DerivedHeader2 deriving from DerivedHeader1, and 
 * <ol><li>which role is specific for every instanciation, and therefore is 
 * using CATDeclareHeaderSpecialResources and 
 * CATImplementHeaderSpecialResources(<b>DerivedHeader2</b>, BaseHeader, <b>DerivedRsc2</b>) 
 * macros. </li>
 * <li> which constructors is of the following kind:<br>
 * <tt>DerivedHeader2(const CATString& iHeaderId2,</tt><i>arguments for role definition</i>, 
 * <tt><b>const CATString& iResourcesFileNamePrefix2</b>);</tt></li>
 * <li> where <tt><b>iResourcesFileNamePrefix2</b></tt> is stored in the 
 * <tt><b>_ResourcesFileNamePrefix</b></tt>
 * data declared by the <tt>CATDeclareHeaderSpecialResources</tt> macro.</li></ol></li>
 * </ul>
 * <br><br>
 * When an application is instanciating DerivedHeader2 classes, through:<br>
 * <tt>new DerivedHeader2("MyDerivedHeader2", ..., "MyFilePrefix_");</tt>
 * <br>the resources for this header will be looked for:
 * <ul><li>first in "MyFilePrefix_DerivedRsc2" .CATNls and .CATRsc files</li>
 * <li>then in "MyFilePrefix_DerivedRsc1" .CATNls and .CATRsc files.</li>
 * <li>and at last in "BaseHeader" .CATNls and .CATRsc files.</li>
 * </ul>
 * <br><br>
 *  @param DerivedHeader
 *      Command header class name. 
 *  @param BaseHeader
 *      Base class of your header class.
 *  @param Rsrc
 *      Resources file name
 * <br><br>
 * The keys to be filled are the same as for the @href CATImplementHeaderResources macro.
 * <br>
 * They are all starting this way: <tt>FilePrefix_BaseRsc.HeaderId</tt>
 * <br><br>
 * @see CATDeclareHeaderSpecialResources, CATImplementHeaderResources.
*/
#define CATImplementHeaderSpecialResources(DerivedHeader, BaseHeader, Rsrc) \
                                                                            \
const char * DerivedHeader::GetFW()                                         \
{                                                                           \
  return XMkHeaderStr(_MK_FWNAME_);                                         \
}                                                                           \
                                                                            \
CATString DerivedHeader::GetResourceFile(int depth)                         \
{                                                                           \
  CATString rsrc(DerivedHeader::GetSpecialResourcesFile(#Rsrc));      \
  return (depth <= 0) ? rsrc : BaseHeader::GetResourceFile(depth - 1);      \
}                                                                           \
                                                                            \
CATString DerivedHeader::GetSpecialResourcesFile(const CATString& iSuffix)   \
{                                                                           \
  return (_ResourcesFileNamePrefix+iSuffix);                                 \
}

//Ici pas de static, car les headers ne sont pas dérivés (but de la macro 
//HeaderSpecialResources).



/*
//-----------------------------------------------------------------------------
#define CATHeaderDeclareResources(DerivedHeader, BaseHeader, Rsrc)          \
int DerivedHeader::GetResourceValue (const CATString & key,                 \
                     CATUnicodeString & resource)           \
{                                                                           \
  return 1;                                                                 \
}                                                                           \
                                                                            \
int DerivedHeader::GetResourceForClass (const CATString & key,              \
                        CATUnicodeString & resource)        \
{                                                                           \
  return 1;                                                                 \
}                                                                           \
                                                                            \
CATMsgCatalog * DerivedHeader::_Resources = NULL;                           \
                                                                            \
int DerivedHeader::_hasResources = 1;

*/

//---------------------------------------------------------------------------

#ifndef HeaderExportedBy
/** @nodoc */
#define HeaderExportedBy
#endif

//---------------------------------------------------------------------------
/**
*  @nodoc 
*  Declares a header class.
*  @param DerivedHeader
*     Command header class name 
*     
*/
#define MacDefineHeader(DerivedHeader)                                      \
class HeaderExportedBy DerivedHeader : public CATCommandHeader              \
{                                                                           \
 public:                                                                    \
  DerivedHeader();                                                          \
  DerivedHeader(const CATString & HeaderID,                                 \
                const CATString & LoadName,                                 \
    int state = CATFrmAvailable);                               \
  DerivedHeader(const CATString & HeaderID,                                 \
                const CATString & LoadName,                                 \
                const CATString & argument,                                 \
    int state = CATFrmAvailable);                               \
  DerivedHeader(const CATString & HeaderID,                                 \
                const CATString & LoadName,                                 \
                const CATString & ClassName,                                \
                void * Argument,                                            \
    int state = CATFrmAvailable);                               \
  virtual ~DerivedHeader();                                                 \
                                                                            \
  virtual CATCommandHeader * Clone();                                       \
                                                                            \
 protected:                                                                 \
                                                                            \
  DerivedHeader(CATCommandHeader * header);                                 \
                                                                            \
  CATDeclareKindOf;                                                         \
                                                                            \
  CATDeclareHeaderResources;                                                \
};

//---------------------------------------------------------------------------
/**
*  @nodoc 
*  Implement a header class.
*  @param DerivedHeader
*     Command header class name 
*     
*/
#define MacImplementHeader(DerivedHeader)                                   \
CATImplementKindOf(DerivedHeader, Implementation, CATCommandHeader,CATNull);\
                                                                            \
CATCreateClass(DerivedHeader);                                              \
                                                                            \
DerivedHeader::DerivedHeader ():                                            \
  CATCommandHeader ()                                                       \
{}                                                                          \
                                                                            \
DerivedHeader::DerivedHeader (const CATString & HeaderID,                   \
            const CATString & LoadName,                   \
            int state):                                   \
  CATCommandHeader(HeaderID, LoadName, state)                               \
{}                                                                          \
                                                                            \
DerivedHeader::DerivedHeader (const CATString & HeaderID,                   \
            const CATString & LoadName,                   \
            const CATString & argument,                   \
            int state):                                   \
  CATCommandHeader(HeaderID, LoadName, argument, state)                     \
{}                                                                          \
                                                                            \
DerivedHeader::DerivedHeader (const CATString & HeaderID,                   \
            const CATString & LoadName,                   \
            const CATString & ClassName,                  \
            void * Argument,                              \
            int state):                                   \
  CATCommandHeader(HeaderID, LoadName, ClassName, Argument, state)          \
{}                                                                          \
                                                                            \
DerivedHeader::DerivedHeader (CATCommandHeader * header):                   \
  CATCommandHeader(header)                                                  \
{}                                                                          \
                                                                            \
DerivedHeader::~DerivedHeader ()                                            \
{}                                                                          \
                                                                            \
CATCommandHeader * DerivedHeader::Clone ()                                  \
{ return new DerivedHeader(this); }                                         \
                                                                            \
CATImplementHeaderResources(DerivedHeader, CATCommandHeader, DerivedHeader)

//---------------------------------------------------------------------------
/**
*  Declares and defines a header class.
*  @param DerivedHeader
*     Command header class name 
*     
*/
#define MacDeclareHeader(DerivedHeader)                                     \
MacDefineHeader(DerivedHeader);                                             \
MacImplementHeader(DerivedHeader);

//---------------------------------------------------------------------------
/** @nodoc */
#define MacDefineDerivedHeader(DerivedHeader, BaseHeader)                   \
class HeaderExportedBy DerivedHeader : public BaseHeader                    \
{                                                                           \
 public:                                                                    \
  DerivedHeader(const CATString & HeaderID,                                 \
                const CATString & LoadName,                                 \
    int state = CATFrmAvailable);                               \
  DerivedHeader(const CATString & HeaderID,                                 \
                const CATString & LoadName,                                 \
                const CATString & argument,                                 \
    int state = CATFrmAvailable);                               \
  DerivedHeader(const CATString & HeaderID,                                 \
                const CATString & LoadName,                                 \
                const CATString & ClassName,                                \
                void * Argument,                                            \
    int state = CATFrmAvailable);                               \
  virtual ~DerivedHeader();                                                 \
                                                                            \
  virtual CATCommandHeader * Clone();                                       \
                                                                            \
 protected:                                                                 \
                                                                            \
  DerivedHeader(CATCommandHeader * header);                                 \
                                                                            \
  CATDeclareKindOf;                                                         \
                                                                            \
  CATDeclareHeaderResources;                                                \
};

//---------------------------------------------------------------------------
/** @nodoc */
#define MacImplementDerivedHeader(DerivedHeader, BaseHeader)                \
CATImplementKindOf(DerivedHeader, Implementation, BaseHeader, CATNull);     \
                                                                            \
DerivedHeader::DerivedHeader (const CATString & HeaderID,                   \
            const CATString & LoadName,                   \
            int state):                                   \
  BaseHeader(HeaderID, LoadName, state)                                     \
{}                                                                          \
                                                                            \
DerivedHeader::DerivedHeader (const CATString & HeaderID,                   \
            const CATString & LoadName,                   \
            const CATString & argument,                   \
            int state):                                   \
  BaseHeader(HeaderID, LoadName, argument, state)                           \
{}                                                                          \
                                                                            \
DerivedHeader::DerivedHeader (const CATString & HeaderID,                   \
            const CATString & LoadName,                   \
            const CATString & ClassName,                  \
            void * Argument,                              \
            int state):                                   \
  BaseHeader(HeaderID, LoadName, ClassName, Argument, state)                \
{}                                                                          \
                                                                            \
                                                                            \
DerivedHeader::DerivedHeader (CATCommandHeader * header):                   \
  BaseHeader(header)                                                        \
{}                                                                          \
                                                                            \
DerivedHeader::~DerivedHeader ()                                            \
{}                                                                          \
                                                                            \
CATCommandHeader * DerivedHeader::Clone ()                                  \
{ return new DerivedHeader(this); }                                         \
                                                                            \
CATImplementHeaderResources(DerivedHeader, BaseHeader, DerivedHeader)

//---------------------------------------------------------------------------
/**
*  Declares and defines a header class.
*  @param DerivedHeader
*     Command header class name 
*  @param BaseHeader
*     Command header base class name 
*     
*/
#define MacDeclareDerivedHeader(DerivedHeader, BaseHeader)                  \
MacDefineDerivedHeader(DerivedHeader, BaseHeader);                          \
MacImplementDerivedHeader(DerivedHeader, BaseHeader);

/**
 * @nodoc
 */
#define MacSetHeaderOption(hdr, opt)\
  if (hdr)\
    hdr->SetOption (#opt)


#endif
