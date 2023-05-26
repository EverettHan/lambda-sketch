#ifndef CATCmdContainer_H
#define CATCmdContainer_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"
#include "CATCmdAccess.h"
#include "CATBoolean.h"
#include "CATAfrPathComponent.h"
#include "CATCAfrEnum.h"


class CATCommandHeader;
class CATPalette;
class CATDialog;
class CATCommand;
class CATSysWeakRef;

#ifdef AfrCAA2
class CATAfrGen;
#endif


/**
 * Class to create the container's access.
 * <b>Role</b>: A container can be :
 * <ul>
 * <li>a menubar, a menu, a submenu, a toolbar or an icon box. Use the @href NewAccess macro
 *  with <tt>CATCmdContainer</tt> as 
 * <tt>classname</tt> parameter to create an instance. </li>
 * <li>a workbench. Use the @href NewAccess macro
 *  with <tt>CATCmdWorkbench</tt> as 
 * <tt>classname</tt> parameter to create an instance.</li> 
 * </ul>
 * @see CATCmdWorkbench , CATIWorkbench, CATIWorkbenchAddin
 */
class ExportedByCATAfrFoundation CATCmdContainer: public CATCmdAccess
{
  /** @nodoc */
  friend class CATMarshallableCmdContainer;
  
  /** @nodoc */
  CATDeclareKindOf;
  
public:
  /** @nodoc */
  CATDeclareCBEvent(SetChildEvent);
    /** @nodoc */
  CATDeclareCBEvent(HideEvent);
    /** @nodoc */
  CATDeclareCBEvent(ShowEvent);
    /** @nodoc */
  CATDeclareCBEvent(StartTransaction);
    /** @nodoc */
  CATDeclareCBEvent(StopTransaction);
    /** @nodoc */
  CATDeclareCBEvent(SetActiveEvent);

  /** 
  * @nodoc 
  */  
  CATCmdContainer (const CATString & name, Persistence = Code);
  /** 
  * @nodoc 
  */
  CATCmdContainer (CATCmdContainer &);
  /** 
  * @nodoc 
  */  
  virtual ~CATCmdContainer();
  /** 
  * @nodoc 
  */  
  virtual CATCmdAccess * Clone(int noNext = 0,CATCmdAccess * toBeCompleted = NULL);

  
			       
    /*---------------------------------*/
    //     REPRESENTATION  
    /*---------------------------------*/

  //================== OBSOLETE =================================
  /** 
  * @nodoc 
  * Obsolete - To be moved to Protected
  */
  virtual CATCmdRep * CreateMenuRep (CATDialog *);
  /** 
  * @nodoc 
  * Obsolete - To be moved to Protected
  */
  virtual void        DestroyMenuRep();
  /** 
  * @nodoc 
  * Obsolete - To be moved to Protected
  */
  virtual CATCmdRep * CreateToolbarRep (CATDialog *);
  /** 
  * @nodoc 
  * Obsolete - To be moved to Protected
  */
  virtual void        DestroyToolbarRep();
  /** 
  * @nodoc 
  * Obsolete - To be moved to Protected
  */
  virtual CATCmdRep * CreateCtxMenuRep (CATDialog *);
  /** 
  * @nodoc 
  * Obsolete - To be moved to Protected
  */
  virtual void        DestroyCtxMenuRep();
  //===================== END OBSOLETE ==============================

    /*-----------------------------------------*/
    //     CONTENT'S MANAGMENT OF THE CONTAINER
    /*-----------------------------------------*/

  /** 
  * @nodoc 
  */  
  CATCmdAccess * GetChild() const;
  /** 
  * @nodoc 
  */
  CATCmdAccess * GetChild(const CATString & childName) const;
  /** 
  * @nodoc 
  */
  CATCmdAccess * GetChild(const CATUnicodeString & childTitle) const;
  
  /** 
  * @nodoc 
  */
  int GetNumberOfChildren() const;
  /** 
  * @nodoc 
  */
  CATCmdContainer * GetBranch(CATCmdAccess * item, CATCmdContainer ** parent);
  
  /** 
  * @nodoc 
  */
  void SetChild (CATCmdAccess *);
  
  /** 
  * @nodoc 
  *
  * A given CATCmdContainer object can't have two child elements with the same
  * name. It is mandatory before calling this member function to ensure that
  * the name of newItem doesn't matched the name of an already inserted child
  * item to avoid potential memory leaks.
  */
  void AddChild (CATCmdAccess * newItem, const CATString * beforeItem = NULL);

  /** 
  * @nodoc 
  */
  void RemoveChild (const CATString & itemName,
		    const CATString * fromContainer = NULL);

  /** 
  * @nodoc 
  */
  void RemoveChild (CATCmdAccess * item,
		    const CATString * fromContainer = NULL);
  

  /** 
  * @nodoc 
  */
  void SetSelect(int position, int notify = 1);

  /** 
  * @nodoc 
  */
  const int GetSelect() const;

  /**
  * @nodoc
  */
  virtual CATString * GetIconName();
  

    /*---------------------------------*/
    //  FOR INTERNAL USE
    /*---------------------------------*/

  /** 
  * @nodoc 
  */
  virtual CATCmdContainer * GetMenu() const;
  /** 
  * @nodoc 
  */
  virtual void SetMenu (CATCmdContainer *);

  /** 
  * @nodoc 
  */
  virtual void FilterPersistence(Persistence, int keep, int inDepth = 1);

  /** 
  * @nodoc 
  */
  void Merge (CATCmdContainer * toMerge, int replace = 0);

  /** 
  * @nodoc 
  */
  virtual char *GenerateVariableName(const char *);

  /**
  * @nodoc
  * Sets the access's type.
  * <b>Role</b>: The type is necessary for the <tt>CATCmdContainer</tt> access. 
  * <b>Legal values</b>: Menubar,Toolbar,Workshop,Workbench,Starter,
  * Separator,IconBox, Submenu and Menu.
  */
  virtual void SetType (const CATString & type); 
  
  /** 
  * @nodoc 
  */
  CATPalette * GetPalette();
  
  /** 
  * @nodoc 
  */
  void  BeginTransaction();

  /** 
  * @nodoc 
  */
  void  EndTransaction();

  /** 
  * @nodoc 
  */
  void SetScale(float scale);

  /** 
  * @nodoc 
  */
  float GetScale() { return _scale; }
  
    /*---------------------------------*/
    //  DISPLAY MANAGEMENT
    /*---------------------------------*/
  
  /** 
  * Position of the toolbar in the application window.
  * @param UnDock 
  *   The toolbar is undocked. 
  * @param Bottom  
  *   The toolbar is docked at the bottom of the application window 
  * @param Top 
  *   The toolbar is docked at the top of the application window
  * @param Left 
  *   The toolbar is docked at the left of the application window
  * @param Right 
  *   The toolbar is docked at the right of the application window
  * @param CompassWest 
  *   The toolbar is docked on the west side of the compass
  * @see AddToolbarView
  */
  enum ComponentPosition { Top, Bottom, Left, Right, UnDock, CompassWest };

  /** 
  * @nodoc 
  */
  virtual void AddView   (CATPalette * iPalette);
  /** 
  * @nodoc 
  */
  virtual void AddView(int iVisibility, ComponentPosition iPosition);


  //virtual void CreateVisReps(int isAnIconBox=0);
  //virtual void DestroyVisReps(int deleteRep=0,int isAnIconBox=0);

  /** 
  * @nodoc 
  */
  virtual int  FillViews (CATDialog * parent);
  /** 
  * @nodoc 
  */
  virtual void ClearViews(int deleteTlb = 0);

  /** 
  * @nodoc 
  */
  virtual int  Show(CATDialog * parent);
  /** 
  * @nodoc 
  */
  virtual void Hide(int vis=1);
  /** 
  * @nodoc 
  */
  virtual int  IsDisplayed();
  /**
   * @nodoc
   * Returns the value of _prevHidden
   */
  int  IsPrevDisplayed(); 
  /** 
  * @nodoc 
  * Sets a toolbar as not customizable
  */
  void NoCusto();
  /** 
  * @nodoc 
  */
  int IsNoCusto();
  
    /*---------------------------------*/
    //  SAVE
    /*---------------------------------*/
  
#ifdef AfrCAA2

  /** 
  * @nodoc 
  */
  virtual void SaveAsXml (CATAfrGen * Gen, int depth);
#endif


	/** @nodoc */
	virtual void ParentChanged ();
  
	/** @nodoc */
	virtual void EditingContextChanged ();



    /*---------------------------------*/
    //  Declarative Application Frame
    /*---------------------------------*/

  /**
  * Set the visibility of the toolbar for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  */
  void SetVisibility(int);

  /**
  * Get the visibility of the toolbar for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  **/
  int GetVisibility() const;

  /**
   * @nodoc
   *
   * Deprecated. Prefer using SetState with the CATAfrContainerActive bitfield value.
   */
  void SetActive (CATBoolean iActivity);
  /**
   * @nodoc
   *
   * Deprecated. Prefer using GetState function and test the bitfield returned
   * with the value CATAfrContainerActive.
   */
  CATBoolean GetActive() const;

  /**
   * Get the state of the container.
   *
   * @return the state of the container. It's a bitfield.
   *
   * The container could be in Normal state (you can test it with
   * CATAfrContainerNormal == pCtn->GetState()) or in Active or Pinned
   * state (you can test using CATAfrContainerActive == (CATAfrContainerActive & pCtn->GetState())
   * or CATAfrContainerPinned == (CATAfrContainerPinned & pCtn->GetState())
   */
  const CATCAfrEnum::ContainerState & GetState() const;
  /**
   * Set the state of the container.
   *
   * @param i_state the new state of the container.
   *
   * The state of the container is a bitfield which can be a combination of the
   * following value: CATAfrContainerActive, CATAfrContainerPinned.
   *
   * When the Container is in normal state its value is CATAfrContainerNormal.
   */
  void SetState(const CATCAfrEnum::ContainerState & i_state);

  /**
  * Set the position of the toolbar for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  */
  void SetPosition(ComponentPosition);

  /**
  * Get the position of the toolbar for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  **/
  ComponentPosition GetPosition() const;

  /**
  * To comply with the collection interface
  * Use by the introspection module
  * @nodoc
  **/
  CATBaseUnknown_var GetItems();

    /**
  * Set the icon name of the toolbar for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  */
  void SetIcon(const CATString & i_iconName);

  /**
  * Get the icon name of the toolbar for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  **/
  CATString GetIcon() const;

  /**
  * Set the command name of the container for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  */
  void SetContainerCommand(const CATString & i_ContainerCommand);

  /**
  * Get the command name of the container for the introspection module
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  **/
  const CATString GetContainerCommand() const;

  /**
  * Get the header with the name given in @SetContainerCommand.
  * @return NULL if the ContainerCommand name is not a valid header name, otherwise a pointer to the header.
  */
  CATCommandHeader* GetHeader();

  /**
  * @return TRUE if the header set by @SetContainerCommand is valid, otherwise FALSE.
  */
  CATBoolean GetValidCommandHeaderFlag();

  /**
  * Get the flag that determines if the container is registered as a component.
  **/
    const CATBoolean & GetRegisteredFlag() const;
   /**
  * Set the flag that determines if the container can be register into a component.
  */
    void SetRegisteredFlag(const CATBoolean &i_registeredFlag);

    /*
    * @internal use
    */
    void SetSignatureBarMenu(CATCmdContainer * ipMenu);
    CATCmdContainer * GetSignatureBarMenu() const;

  /**@Deprecated**/
  void SetCommandContainer(const CATString & i_ContainerCommand){SetContainerCommand(i_ContainerCommand);};
  const CATString GetCommandContainer() const { return GetContainerCommand();};

  const CATAfrPathComponent& GetPathComponent() const;
  void SetPathComponent(const CATAfrPathComponent & i_pathComponent);

protected:
  
  /**
  * @nodoc
  * Creates a representation for an container in a toolbar.
  * Should be overloaded by every kind of container that wants to be representable in a toolbar.
  */
  virtual CATCmdRep * BarRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for an container in a menu.
  * Should be overloaded by every kind of container that wants to be representable in a menu.
  */
  virtual CATCmdRep * MenuRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for an container in a contextual menu.
  * Should be overloaded by every kind of container that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual CATCmdRep * ContextRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for an container in a toolbar.
  * Should be overloaded by every kind of container that wants to be representable in a toolbar.
  */
  virtual void BarRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for an container in a menu.
  * Should be overloaded by every kind of container that wants to be representable in a menu.
  */
  virtual void MenuRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a container in a contextual menu.
  * Should be overloaded by every kind of container that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual void ContextRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);


   /*-----------------------------------------------*/
   //  Extension AfrFoundation :Generic Representation
   /*-------------------------------------------------*/

	  /**
  * Creates a generic representation for a container. 
  * @nodoc
  * @author ld3
  */
  CATCommand *  GenericRepCreation(CATCommand *);

  /**
  * Deletes generic representation of a container. 
  * @nodoc
  * @author ld3
  */
  void  GenericRepDeletion();

  void SetIconCB(CATCallbackEvent iEvt, void  * ipFrom,  CATNotification * ipNotif, CATSubscriberData iData, CATCallback iCbk) ;

public:
  /** 
  * @nodoc 
  */
  CATCmdContainer (Persistence = Code);

protected:
  CATCmdAccess * _child;
  /* Do not use this member use GetMenu/SetMenu methods*/
  CATCmdContainer * _menu;

  CATPalette * _view;
    
private:

  void OnDialogDestroyed (CATCallbackEvent iPublishedEvent, void* iPublishingObject, CATNotification* iNotification, CATSubscriberData iClientData, CATCallback iCallback);
 
  int _currentChildNumber;
  int _currentNumberOfViewsForMarshalling;
  int _numberOfDisplayedViews;
  char * _descriptor;

  float _scale;
  int   _noCusto;
  CATBoolean _iconResources;
  CATSysWeakRef * _menuWeakRef;
  CATSysWeakRef * _signatureBarmenuWeakRef;
  CATString _commandName;
  CATSysWeakRef * _headerWeakRef;
  CATBoolean      _registeredFlag;
  CATAfrPathComponent _PathComponent;
  CATCAfrEnum::ContainerState _state;

};

#endif
