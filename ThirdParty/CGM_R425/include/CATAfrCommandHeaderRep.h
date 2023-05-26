// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef CATAfrCommandHeaderRep_h
#define CATAfrCommandHeaderRep_h

/**
* @CAA2Level L1
* @CAA2Usage U2
*/

// System Framework
#include "CATCommand.h" // to derive from

#include "CATAfrFoundation.h"

class CATString ;
class CATDialog ;
class CATSysWeakRef;

/**
* Base class to create a customized representation for a command header.
* <b>Role:</b>This class is the base class to create a customized representation
* for a @href CATCommandHeader class. This customized command header must 
* derive from the @href CATAfrDialogCommandHeader class, and must implement
* the @href CATIAfrCommandHeaderRep interface. This interface contains three
* methods to overload the default representation of the command header into a toolbar, 
* the menubar or a contextual menu. In most cases, only one method creates an instance
* of a class deriving from <tt>CATAfrCommandHeaderRep</tt>, and the two others 
* create nothing. 
* <p>The @href #Build method is automatically called just after the instantiation
* of the class deriving from <tt>CATAfrCommandHeaderRep</tt>. This method generally 
* creates dialog object, whose the dialog parent is the first argument of the constructor, 
* and that you retrieve with the @href #GetDialogParent method.</p>
* <p>It is strongly recommended to read User Interfaces articles about 
* command header into the CAA Encyclopedia before to creating such classes. You will learn
* how to manage the multi-representation, and more generally how to "refresh" all the 
* instances of the representations.</p>
*/ 
class ExportedByCATAfrFoundation CATAfrCommandHeaderRep : public CATCommand
{

public:
  
  /**
  * Constructs a customized representation for a command header.
  * @param iParent
  * The Dialog parent of dialog objects created by the @href #Build method. 
  * @param iCommandName
  * The name of the command. It is the argument of the @href CATCommand class
  * constructor. This name can be the same for all instances of the current class.
  */
  CATAfrCommandHeaderRep(const CATDialog * iParent, CATString & iCommandName);

  virtual ~CATAfrCommandHeaderRep() ;

  /**
  * Creates the customized representation.
  * <br><b>Role:</b>This method instantiates Dialog objects whose the dialog parent is
  * the value returned by the @href #GetDialogParent method.
  */
  virtual HRESULT Build() = 0;

  /**
  * Retrieves the dialog parent.
  * @param ioParent
  * The first argument of the @href #CATAfrCommandHeaderRep constructor.
  */
  HRESULT GetDialogParent(const CATDialog ** ioParent);
 
private:

  // Copy constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATAfrCommandHeaderRep(const CATAfrCommandHeaderRep &iObjectToCopy);

  // Assignment operator, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATAfrCommandHeaderRep & operator = (const CATAfrCommandHeaderRep &iObjectToCopy);

private:

  const CATDialog    * _pParent ;
  CATSysWeakRef      * _parentWeakRef;

};

#endif
