#ifndef CATCmdSeparator_H
#define CATCmdSeparator_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"
#include "CATCmdAccess.h"

class CATCommand;

/**
 * Class to create a separator's access .
 * <b>Role</b>: Application Frame elementary component used to separate other
 * components visually (line in a submenu, blank in a toolbar). Use the @href NewAccess 
 * macro to create a <tt>CATCmdSeparator</tt>
 */
class ExportedByCATAfrFoundation CATCmdSeparator: public CATCmdAccess
{
  friend class CATMarshallableCmdSeparator;
  
  CATDeclareKindOf;
  
public:

	/*---------------------------------*/
    //     CONSTRUCTORS  
    /*---------------------------------*/
  /**
  * @nodoc
  */
  CATCmdSeparator (Persistence = Code);
  /**
  * @nodoc
  */
  CATCmdSeparator (const CATString &name, Persistence = Code);
  /**
  * @nodoc
  */
  CATCmdSeparator (CATCmdSeparator &);
  
  /**
  * @nodoc
  */
  virtual CATCmdAccess * Clone(int noNext = 0,CATCmdAccess * toBeCompleted = NULL);
			       
  
  virtual ~CATCmdSeparator();
 
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
    //  INTERNAL USAGE 
    /*---------------------------------*/

  /** @nodoc */
  virtual char *GenerateVariableName(const char *);

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

  /** 
  * @nodoc 
  */
  virtual void CreateToolbarVisRep (CATCommand*);
  /** 
  * @nodoc 
  */
  virtual void DestroyToolbarVisRep();

  /*-----------------------------------------------*/
  //  Extension AfrFoundation :Generic Representation
  /*-------------------------------------------------*/

	  /**
  * Creates a generic representation for a separator. 
  * @nodoc
  * @author ld3
  */
  CATCommand *  GenericRepCreation(CATCommand *);

  /**
  * Deletes generic representation of a separator. 
  * @nodoc
  * @author ld3
  */
  void  GenericRepDeletion();


protected:
  
  /**
  * @nodoc
  * Creates a representation for a separator in a toolbar.
  * Should be overloaded by every kind of access that wants to be representable in a toolbar.
  */
  virtual CATCmdRep * BarRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for a separator in a menu.
  * Should be overloaded by every kind of access that wants to be representable in a menu.
  */
  virtual CATCmdRep * MenuRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Creates a representation for a separator in a contextual menu.
  * Should be overloaded by every kind of access that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual CATCmdRep * ContextRepCreation (CATBaseUnknown *parent, CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a separator in a toolbar.
  * Should be overloaded by every kind of access that wants to be representable in a toolbar.
  */
  virtual void BarRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a separator in a menu.
  * Should be overloaded by every kind of access that wants to be representable in a menu.
  */
  virtual void MenuRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);
  
  /**
  * @nodoc
  * Deletes a representation for a separator in a contextual menu.
  * Should be overloaded by every kind of access that wants to be representable in a contextual menu.
  * parent is the dialog object 
  */
  virtual void ContextRepDeletion (CATCmdAccessRepVisu RepVisu = AfrDialogRep);


};

#endif
