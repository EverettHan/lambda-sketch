#ifndef CATAfrDialogCommandHeader_H
#define CATAfrDialogCommandHeader_H

// COPYRIGHT Dassault Systemes 2003

#include "CATCommandHeader.h"
#include "CATAfrFoundation.h"

class CATAfrDialogHeaderRep;

/**
* Base class to create a command header with a customized representation.
* <b>Role:</b> This class enables you to create a command header with a  
* customized representation. It means a representation which will be not the 
* default one: a push button in a toolbar, and a push item in the
* menu bar or a contextual menu. 
* <p> To do that, you should implement the @href CATIAfrCommandHeaderRep interface
* on the class deriving of <tt>CATAfrDialogCommandHeader</tt>. This interface 
* enables you to provide your specific representation in the toolbar, or/and the menubar, or/and 
* the contextual menu. This representation is an instance of a class deriving of
* the @href CATAfrCommandHeaderRep class.</p>
* <br>The @href CATCommand class describes how to create a customized command header. 
*/
class ExportedByCATAfrFoundation CATAfrDialogCommandHeader : public CATCommandHeader
{
  CATDeclareClass;
  
public:
  
  /**
  * Constructs a command header instance.
  * @param iHeaderIdentificator
  * The identificator of the command header class instance. It is the <tt>command</tt> 
  * argument of the <tt>SetAccessCommand</tt> macro. It is used for NLS resources.   
  * @param iState
  *    The command header state.
  *    <br><b>Legal values</b>: 
  *       <li> <tt>CATFrmAvailable</tt> (The default value) </li>
  *       <li> <tt>CATFrmUnavailable</tt> </li>
  */
  CATAfrDialogCommandHeader(const CATString & iHeaderIdentificator, 
                            int iState = CATFrmAvailable);

	virtual ~CATAfrDialogCommandHeader();
  
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
  CATCommandHeader * Clone();
  
  //-----------------------------------------------------------------------
  //   Create the representation of a command in a toolbar, a menu or a contextual menu
  //-----------------------------------------------------------------------
  /** @nodoc */
  CATCmdRep * CreateToolbarRep (CATCmdStarter *item, CATDialog *parent);
  /** @nodoc */
  CATCmdRep * CreateMenuRep    (CATCmdStarter *item, CATDialog *parent);
  /** @nodoc */
  CATCmdRep * CreateCtxMenuRep (CATCmdStarter *item, CATDialog *parent);
  
  //-----------------------------------------------------------------------
  // Destroy the representation of a command in a toolbar, a menu or a contextual menu
  //-----------------------------------------------------------------------
  /** @nodoc */
  void        DestroyToolbarRep(CATCmdStarter *item);
  /** @nodoc */
  void        DestroyMenuRep   (CATCmdStarter *item);
  /** @nodoc */
  void        DestroyCtxMenuRep(CATCmdStarter *item);
  
  const CATString & GetTypeLate();
  void SetTypeLate(const CATString & iTypeLate);


protected:

  /**
  * Constructs a command header instance.
  * <br<b>Role:</b>This method calls the @href CATCommandHeader copy constructor. 
  * In your derived class overwrite this method such that:
  * 
  * <pre>
  * MyHeader::MyHeader(CATCommandHeader * iHeaderToCopy):
  *                           CATAfrDialogCommandHeader(iHeaderToCopy)
  * {
  * }   
  * </pre>
  * This method is called by the @href #Clone method.
  * @param iHeaderToCopy
  * The header to copy. 
  */
  CATAfrDialogCommandHeader(CATCommandHeader * iHeaderToCopy);

  /**
  * @nodoc
  */
  CATAfrDialogCommandHeader(const CATString & HeaderID,
                    const CATString & LoadName,
                    int state = CATFrmAvailable);
  /**
  * @nodoc
  */
  CATAfrDialogCommandHeader(const CATString & HeaderID,
                    const CATString & LoadName,
                    const CATString & argument,
                    int state = CATFrmAvailable);

  /**
  * @nodoc
  */
  CATAfrDialogCommandHeader(const CATString & iHeaderIdentificator,
                    const CATString & LoadName,
                    const CATString & ClassName,
                    void * Argument, 
                    int state = CATFrmAvailable);

  
private:
  
  // constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATAfrDialogCommandHeader();

  // Assignment operator, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATAfrDialogCommandHeader& operator=(const CATAfrDialogCommandHeader&);

  // copy constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATAfrDialogCommandHeader(const CATAfrDialogCommandHeader &iObjectToCopy);

  //-----------------------------------------------------------------------
  //   Internals
  //-----------------------------------------------------------------------
  CATAfrDialogHeaderRep * CreateRep  (CATCmdStarter *item, CATDialog *parent);
  void                    DestroyRep (CATCmdStarter *item);

  CATString _typeLate;
};

#endif
