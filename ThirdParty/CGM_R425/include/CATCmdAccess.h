#ifndef CATCmdAccess_H
#define CATCmdAccess_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"

/** @nodoc */
#define NOMNEMONIC '\0'

#include "CATAfrModelBase.h"
#include "CATCallbackManager.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfInt.h"
#include <CATSYPDeclareEnumFactory.h>

class CATDialog;
class CATCmdRep;
class CATCommand;
#ifdef AfrCAA2
class CATAfrGen;
#endif

//class CATListOfInt;

/**
 * Base class to create an access.
 * <b>Role</b>: When you want to arrange commands to propose them appropriately to the end 
 * user, you need to create a workbench or create an add-in to 
 * an existing workshop or workbench. When you create such objects, you create in fact 
 * a containment tree structure to access to the commands. A <b>node</b> of the tree is 
 * a @href CATCmdContainer, a @href CATCmdWorkbench for
 * the workbench  
 * and a <b>leaf</b> can be a @href CATCmdStarter or 
 * a @href CATCmdSeparator. All these objects are therefore 
 * called accesses and their base class is <tt>CATCmdAccess</tt>. <br>
 *
 * To create any access use the @href NewAccess macro. 
 * @see CATIWorkbench, CATIWorkbenchAddin, CATCommandHeader
 */
class ExportedByCATAfrFoundation CATCmdAccess: public CATAfrModelBase
{
  friend class CATMarshallableCmdAccess;
  friend class CATCmdAccessEditor;
  
  CATDeclareClass;
  
public:

  /**
  * @nodoc
  */
  // This enum is exposed through introspection.
  // Do not forget to update the struct defined in the cpp
  // if you add or reorder values.
  enum Persistence { User, Default, Code };
  /**
  * @nodoc
  */
  enum LocalMode   { Workshop, Workbench };
  /**
  * @nodoc
  */
  CATCmdAccess (const CATString & name, Persistence = Code, int local = 0);
  /**
  * @nodoc
  */
  CATCmdAccess (CATCmdAccess &);
  /**
  * @nodoc
  */
  virtual ~CATCmdAccess();

  HRESULT LogicalDeath();

  /**
  * @nodoc
  */  
  virtual CATCmdAccess * Clone(int noNext = 0,CATCmdAccess * toBeCompleted = NULL);
			       
  /**
  * @nodoc
  */
  virtual void SaveClone();
  
    /*---------------------------------*/
    //     REPRESENTATION  
    /*---------------------------------*/
  
  /**
  * @nodoc
  * Types of representations
  */
  enum CATAfrAccessRepTypeDef { AfrBarRep, AfrMenuRep, AfrContextRep };
  
  /**
  * @nodoc
  * Modes of visualization
  */
  enum CATCmdAccessRepVisu { AfrDialogRep, AfrWindowsRep, AfrImmersiveRep };

  /**
  * @nodoc
  * Creates a representation for an access.
  * Calls protected methods BarRepCreation, MenuRepCreation, ContextRepCreation.
  */
  CATCmdRep * RepCreation (CATBaseUnknown *parent, CATAfrAccessRepTypeDef RepType, CATCmdAccessRepVisu RepVisu = AfrDialogRep);

  /**
  * @nodoc
  * Deletes representation of an access.
  * Calls protected methods BarRepDeletion, MenuRepDeletion, ContextRepDeletion.
  */
  void RepDeletion (CATAfrAccessRepTypeDef RepType, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  /**
  * @nodoc
  */
  virtual void SetRep(CATCmdRep *);
  /**
  * @nodoc
  */
  virtual CATCmdRep * GetRep();
  
    /*---------------------------------*/
    //     QUERIES  
    /*---------------------------------*/
  
  /**
  * @nodoc
  * Returns the next access.
  * <b>Role</b>: Accesses are chained. 
  */
  CATCmdAccess         * GetNext()        const;
  
  /**
  * @nodoc
  * Returns the next visible access.
  * <b>Role</b>: Accesses are chained. The next access of a give one could be invisible. 
  * Ivisible accesses are original accesses. 
  */
  CATCmdAccess         * GetNextVisible() const;
  
  /**
  * @nodoc
  * Returns the parent's access.
  * <b>Legal values</b>: a <tt>CATCmdContainer<</tt>. 
  */
  CATCmdAccess         * GetParent();
  
  /**
  * @nodoc
  */
  virtual CATCmdAccess * GetChild()       const;
  
  /**
  * @nodoc
  * default customer name is the label ??? .                                              
  */
  const CATString      & GetCustomerName();   
  
  /**
  * @nodoc
  * Returns the access's type. 
  */
  const CATString      & GetType()        const;

  /* ------> To ensure compatibility with base class CATAfrModelBase <------ */
  void Remove ();
  void SetNextElement (CATAfrModelBase * ipNext);
  CATAfrModelBase * GetNextElement() const;
  void SetPreviousElement (CATAfrModelBase * ipPrevious);
  CATAfrModelBase * GetPreviousElement() const;
  void SetParentElement (CATAfrModelBase * ipParent);
  CATAfrModelBase * GetParentElement() const;
  void SetFirstChildElement (CATAfrModelBase * ipChild);
  CATAfrModelBase * GetFirstChildElement() const;
  CATAfrModelBase * GetChildElement (const CATString & iName) const;
  void AddChildElement (CATAfrModelBase * ipChild);


    /*---------------------------------*/
    //     NLS QUERIES 
    /*---------------------------------*/

  /**
  * @nodoc
  */
  virtual CATString * GetIconName();

  /**
  * @nodoc
  * Returns the access's title.
  * <b>Role</b>: It's the name which appears on the screen. It's the NLS title. If
  * the NLS values doesn't exist, the title is the name of the access.
  */
  virtual const CATUnicodeString & GetTitle();   

  /**
  * @nodoc
  */
  CATUnicodeChar         GetMnemonic();
  

    /*---------------------------------*/
    //     EDITION 
    /*---------------------------------*/
  
  /**
  * @nodoc
  */
  void         SetName         (const CATString &, int userRequest = 0);

  /**
  * @nodoc
  */
  void         SetNext         (CATCmdAccess * const);

  /**
  * @nodoc
  */
  void         SetCustomerName (const CATString &);
  
  /**
  * @nodoc
  */
  virtual void SetIconName     (const CATString &, int userRequest=0);

  /**
  * @nodoc
  */
  virtual void SetTitle        (const CATUnicodeString &, int userRequest = 0);

  /**
  * @nodoc
  */
  void         SetMnemonic     (CATUnicodeChar, int userRequest = 0);

  /**
  * @nodoc
  */
  void UnsetCustomerName(int notify = 1);
  /**
  * @nodoc
  */
  void UnsetIconName    (int notify = 1, int userRequest = 0);
  /**
  * @nodoc
  */
  void UnsetTitle       (int notify = 1, int userRequest = 0);
  /**
  * @nodoc
  */
  void UnsetMnemonic    (int notify = 1, int userRequest = 0);
  /**
  * @nodoc
  */
  void SetParent        (CATCmdAccess *);

	
    /*---------------------------------*/
    //  FOR INTERNAL USE
    /*---------------------------------*/
  
  /**
  * @nodoc
  */
  int  HasTitle()   const;
  /**
  * @nodoc
  */
  int  HasCommand() const;
  /**
  * @nodoc
  */
  int  IsLocal()    const;

  /**
  * @nodoc
  */
  void MakeLocal();
  /**
  * @nodoc
  */
  int  IsLocal(LocalMode)    const;
  /**
  * @nodoc
  */
  void MakeLocal(LocalMode, int propagate = 1);

  /**
  * @nodoc
  */
  Persistence  GetPersistence() const;

  /**
  * @nodoc
  * Retrieves the internal name of the access just before this.
  * If you want retrieve the argument name of the @href #SetAnchorName method, use
  * the @href #GetOriginalAnchorName method.
  */
  CATString  * GetAnchorName () const;

  /**
  * @nodoc
  */
  void SetPersistence(Persistence);

  /**
  * @nodoc
  * @param iAnchorName
  * Name of the access which is just after this. iAnchorName can be an alias name. 
  * To retrieve the argument, iAnchorName, use the @href #GetOriginalAnchorName method.
  */
  void SetAnchorName (const CATString & iAnchorName);

  /**
  * @nodoc
  */
  enum DumpMode { Simple, WithPersistence, Address, StdOut };
  /**
  * @nodoc
  */
  virtual void FlatDump(DumpMode = Simple, int noNext = 0) const;

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
  virtual void ClearViews();

  /**
  * @nodoc
  * Add command headers.
  */
  virtual void CreateHeaders();

  /**
  * @nodoc
  */
  virtual void SetAddin (const CATString & Addin, int FirstAddin);
  /**
  * @nodoc
  */
  virtual int GetAddin (CATString & Addin);  
  /**
  * @nodoc
  */
  virtual int IsAddin ();

  /** @nodoc */
  void SetWeight (float iWeight);
  /** @nodoc */
  float GetWeight ();
  
    /*---------------------------------*/
    //  SAVE
    /*---------------------------------*/

  /**
  * @nodoc
  */
  virtual void FilterPersistence( Persistence, int keep,  int inDepth=1);

#ifdef AfrCAA2

  /**
  * @nodoc
  */
  virtual void SaveAsXml (CATAfrGen * Gen, int depth);
#endif


    /*---------------------------------*/
    //  EVENT 
    /*---------------------------------*/

  /**
  * @nodoc
  */
  void DispatchCallbacks(CATCallbackEvent  iPublishedEvent,
                         CATNotification  *iPublishedNotification=NULL,
                         void             *iEventPublisher=NULL);

  /**
  * @nodoc
  */
  CATDeclareCBEvent(DeleteEvent);
  /**
  * @nodoc
  */
  CATDeclareCBEvent(EditEvent);
  /**
  * @nodoc
  */
  CATDeclareCBEvent(SetIconEvent);
  /**
  * @nodoc
  */
  CATDeclareCBEvent(SetNextEvent);
  /**
  * @nodoc
  */
  CATDeclareCBEvent(SetMnemonicEvent);
  /**
  * @nodoc
  */
  CATDeclareCBEvent(SetTitleEvent);
  /**
  * @nodoc
  */
  CATDeclareCBEvent(UnsetChildEvent);
  /** 
  * @nodoc 
  */
  CATDeclareCBEvent(UnsetNextEvent);

   /*---------------------------------*/
   //  ALIAS 
   /*---------------------------------*/

  /**
  * Returns the alias's name of the access. 
  * @nodoc
  */
  const CATString     GetAliasName()           const;
  /**
  * @nodoc
  * Returns the original's name of the access. 
  * <br><b>Role</b>: The original name is the <tt>name</tt> parameter 
  * of the constructor.  
  */
  const CATString   & GetOriginalName()        const;
  /**
  * @nodoc
  * Returns the original anchor's name.
  * <br><b>Role</b>: The original name is the <tt>anchorName</tt> parameter 
  * of the @href SetAnchorName method.   
  */
  CATString         * GetOriginalAnchorName()  const;

	/**
	 * @nodoc
	 * Tells the access that a parent has changed
	 * in its parent hierarchy
	 */
	virtual void ParentChanged ();

	/**
	 * @nodoc
	 * Tells the access that a parent has changed
	 * in its parent hierarchy
	 */
	virtual void EditingContextChanged ();

   /*---------------------------------*/
   //  Extension AfrFoundation 
   /*---------------------------------*/

	  /**
  * Creates a generic representation for an access. 
  * @nodoc
  * @author ld3
  */
  virtual CATCommand *  GenericRepCreation(CATCommand *);

  /**
  * Deletes generic representation of an access.. 
  * @nodoc
  * @author ld3
  */
  virtual void  GenericRepDeletion();


  /**
  * Returns the representation type of the access. 
  * @nodoc
  * @author ld3
  */
  const CATString  &  GetRepresentationType();

    /**
    * Set the representation type of the model object. 
    */
  void SetRepresentationType(CATString &);
   /*---------------------------------*/
   //  Declarative Application Frame 
   /*---------------------------------*/

  /**
  * Set the anchor name
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  */
  void SetAnchor(const CATString &);

  /**
  * Get the anchor name
  * Use by the introspection module to match
  * the prototype of the method
  * @nodoc
  */
  const CATString & GetAnchor() const;


  //===================================================


  //================== OBSOLETE =================================
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
  virtual CATCmdRep * CreateMenuRep    (CATDialog *);
  /**
  * @nodoc
  * Obsolete - To be moved to Protected
  */
  virtual void        DestroyMenuRep   ();
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


protected:
  
  /**
  * @nodoc
  * Creates a representation for an access in a toolbar.
  * Should be overloaded by every kind of access that wants to be representable in a toolbar.
  */
  virtual CATCmdRep * BarRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for an access in a menu.
  * Should be overloaded by every kind of access that wants to be representable in a menu.
  */
  virtual CATCmdRep * MenuRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for an access in a contextual menu.
  * Should be overloaded by every kind of access that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual CATCmdRep * ContextRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for an access in a toolbar.
  * Should be overloaded by every kind of access that wants to be representable in a toolbar.
  */
  virtual void BarRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for an access in a menu.
  * Should be overloaded by every kind of access that wants to be representable in a menu.
  */
  virtual void MenuRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for an access in a contextual menu.
  * Should be overloaded by every kind of access that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual void ContextRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);

public:
  /**
  * @nodoc
  */ 
  CATCmdAccess (Persistence = Code);

protected:
  /**
  * @nodoc
  */ 
  void DumpName(DumpMode) const;
  
  CATCmdAccess * _next;
  CATCmdAccess * _father;
  CATCmdRep    * _rep;         
  CATCommand   * _visRep;
  CATString      _Type;
  CATString    * _icon;
  CATString    * _Addin;
  Persistence    _persistence;   /** @win64 fbq : 64-bit structure packing **/
  
  
private:
  
  int                _hasTitle;
  int                _local;  
  int                _local2Workshop;
  int                _local2Config;
  int                _FirstAddin;
  CATString        * _anchor;
  CATString        * _customerName;
  int                _titleResources;
  int                _mnemonicResources;
  CATUnicodeString   _title;
  CATUnicodeString   _unicodeName;
  char             * _titleForMarshalling;
  CATUnicodeChar     _mnemonic;
  char             * _mnemonicForMarshalling;

  // Alias managment 
  CATString           _OriginalName   ;
  CATString         * _OriginalAnchor ;

  void FindAlias(int iUpdateTable, const CATString & iName, CATString & oOriginName );
  CATBoolean WorkshopCommandAccessCreationRequired ();

  float _Weight;
};

#endif

// VTV #include <CATCmdContainer.h>
// VTV #include <CATCmdSeparator.h>
// VTV #include <CATCmdStarter.h>

// VTV #include <CATCmdWorkbench.h>


/**
 * @nodoc
 * obsolete, does nothing.
 * To remove a workbench from the Start menu, set its Transient resource to TRUE.
*/
#define SetWorkbenchTransient(variableName, transient) \
  variableName -> SetTransient (transient)
  
/**
 * @nodoc
 * obsolete, does nothing.
*/
#define SetWorkbenchPriority(variableName, priority) \
  variableName -> SetPriority(priority)
  
/**
 * @nodoc
 * Do not use, use a CATRsc resource file instead
*/
#define SetAccessIconName(variableName, icon) \
  variableName -> SetIconName(icon)
  
/**
 * @nodoc
 * Do not use, use a CATNls resource file instead
*/
#define SetAccessTitle(variableName, title) \
  variableName -> SetTitle(title)
 
/**
 * @nodoc
 * Do not use, use a CATNls resource file instead
*/
#define SetAccessCustomerName(variableName, customerName) \
  variableName -> SetCustomerName(customerName)

/**
 * @nodoc
 * Do not use, use a CATNls resource file instead
*/
#define SetAccessMnemonic(variableName, mnemonic) \
  variableName -> SetMnemonic(mnemonic)

CATSYP_DECLARE_ENUMFACTORY(ExportedByCATAfrFoundation, CATCmdAccess__Persistence);
