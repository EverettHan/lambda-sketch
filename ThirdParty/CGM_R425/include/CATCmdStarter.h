#ifndef CATCmdStarter_H
#define CATCmdStarter_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"
#include "CATCmdAccess.h"
#include "CATCommand.h"
#include "CATBoolean.h"
#include "CATAfrPathComponent.h"

class CATCommandHeader;
class CATCmdWorkshop;
class CATSysWeakRef;

/**
 * Class to create a starter's access.
 * <b>Role</b>: A starter is a leaf of the workshop's accesses tree. At each starter 
 * you attach a @href CATCommandHeader to launch the associated command.<br>
 * Use the @href NewAccess macro with <tt>CATCmdStarter</tt> as 
 * <tt>classname</tt> parameter to create an instance. 
 * @see CATCommandHeader, CATIWorkshop, CATIWorkbench, CATIWorkbenchAddin 
 */
class ExportedByCATAfrFoundation CATCmdStarter: public CATCmdAccess
{
  friend class CATMarshallableCmdStarter;
  
  CATDeclareKindOf;
  
public:
	/*---------------------------------*/
    //     CONSTRUCTORS
    /*---------------------------------*/

    /** @nodoc */
  CATCmdStarter (Persistence = Code); // public pour Declarative Application Frame

  /** 
  * @nodoc 
  */
  CATCmdStarter (const CATString & name, Persistence = Code);
  /** 
  * @nodoc 
  */
  CATCmdStarter (CATCmdStarter &);
  
  virtual ~CATCmdStarter();

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

    /*---------------------------------*/
    //     NLS' QUERIES  
    /*---------------------------------*/

  /** 
  * @nodoc 
  */
  CATString              * GetIconName();

  /** 
  * @nodoc 
  */
  const CATUnicodeString & GetTitle();

    /*---------------------------------*/
    //     COMMAND HEADER MANAGMENT  
    /*---------------------------------*/

  /** 
  * @nodoc 
  */
  int                HasCommand() const;

  /** 
  * @nodoc 
  */
  const CATString  & GetCommand() const;

  /** 
  * @nodoc 
  */
  CATCommandHeader * GetHeader (CATBoolean forceWorkbenchesLoad = TRUE)  const;

  /** 
  * @nodoc 
  */
  void SetCommand(const CATString &name, int unset = 0);

  /** 
  * @nodoc 
  */
  virtual void CreateHeaders();
  
  /** 
  * @nodoc 
  * forget command header, no future use.
  */
  void ForgetHeader();

  /** 
  * @nodoc 
  */
  const CATString & GetHeaderOrigin() const;
  /** 
  * @nodoc 
  */
  void SetHeaderOrigin(const CATString &);

   /*-----------------------------------------------*/
   //  Extension AfrFoundation :Generic Representation
   /*-------------------------------------------------*/

	  /**
  * Creates a generic representation for a starter. 
  * @nodoc
  * @author ld3
  */
  CATCommand *  GenericRepCreation(CATCommand *);

  /**
  * Deletes generic representation of a starter. 
  * @nodoc
  * @author ld3
  */
  void  GenericRepDeletion();

  
    
    /*---------------------------------*/
    //  SAVE
    /*---------------------------------*/

#ifdef AfrCAA2
  /** 
  * @nodoc 
  */
  virtual void SaveAsXml (CATAfrGen * Gen, int depth);
#endif
  
   /*---------------------------------*/
   //  FOR INTERNAL USAGE 
   /*---------------------------------*/

  /** @nodoc */
  virtual char *GenerateVariableName(const char *);

  /** @nodoc */
	void OnHeaderBisDeleted  (
 	  CATCallbackEvent   iPublishedEvent,
    void             * iPublishingObject,
    CATNotification  * iNotification,
    CATSubscriberData  iClientData,
    CATCallback        iCallback
    );
  
  /** @nodoc */
  void SetHeaderBis        (CATCommandHeader *);

    /*---------------------------------*/
    //  EVENT
    /*---------------------------------*/
  
  /** 
  * @nodoc 
  */
  CATDeclareCBEvent(SetCommandEvent);
  /** 
  * @nodoc 
  */
  CATDeclareCBEvent(SetSelectEvent);

  /* Get the event PreselectedItemEvent*/
  static CATSYPEvent * PreselectedItemEvent();


  /** @nodoc */
  virtual void ParentChanged ();

  /** @nodoc */
  virtual void EditingContextChanged ();

  void SetCAfrPathComponent(const CATAfrPathComponent i_CAfr );
  CATAfrPathComponent GetCAfrPathComponent() const;

  /** Get / Set the property PreselectedItemState.*/
  const CATBoolean & GetPreselectedItemState() const;
  void SetPreselectedItemState(const CATBoolean & i_PreselectedItemState);

  /**
   * Indicates whether the starter is displayed or not
   * with the customization.
   *
   * @return 1 if the starter is displayed, 0 otherwise.
   */
  int IsDisplayedWithCustomization();
  /**
   * Set the displayWithCustomization flag.
   *
   * Use only by customization API in some complicated cases of
   * customization.
   *
   * @param i_customizeDisplay new value to set for the flag.
   */
  void SetDisplayWithCustomizationFlag(int i_customizeDisplay);

protected:
  
  /**
  * @nodoc
  * Creates a representation for a stater in a toolbar.
  * Should be overloaded by every kind of access that wants to be representable in a toolbar.
  */
  virtual CATCmdRep * BarRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for a stater in a menu.
  * Should be overloaded by every kind of access that wants to be representable in a menu.
  */
  virtual CATCmdRep * MenuRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for a stater in a contextual menu.
  * Should be overloaded by every kind of access that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual CATCmdRep * ContextRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a stater in a toolbar.
  * Should be overloaded by every kind of access that wants to be representable in a toolbar.
  */
  virtual void BarRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a stater in a menu.
  * Should be overloaded by every kind of access that wants to be representable in a menu.
  */
  virtual void MenuRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a stater in a contextual menu.
  * Should be overloaded by every kind of access that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual void ContextRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);


private:
	
  void OnDialogDestroyed (CATCallback, void *v,
                          CATNotification *, CATCallbackEvent,
                          CATSubscriberData);
  void OnRepDestroyed (CATCallback, void *v,
                       CATNotification *, CATCallbackEvent,
                       CATSubscriberData);
	
  /** @nodoc */
  CATCmdWorkshop * GetWorkshop ();

  /** @nodoc */  
  CATCommandHeader * GetHeaderBis();
   
  /** @nodoc */
  CATString        * _commandName;

  /** @nodoc */
  CATString  _headerOrigin;
  
 
  /** @nodoc */
  CATSysWeakRef * _headerBisWeakRef;

  /** @nodoc */
  CATCmdWorkshop   * _workshop;

  CATAfrPathComponent    _CAfrPathComponent;

  /**
   * Flag set by customization to prevent to display a starter when
   * customization is made on global workshop and workbench.
   */
  int _displayWithCustomizationFlag;
  CATBoolean _preselectedItemState;
};

#endif
