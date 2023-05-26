#ifndef __CATIAfrCommandHeaderRep_h
#define __CATIAfrCommandHeaderRep_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"

class CATAfrCommandHeaderRep;
class CATDialog;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrCommandHeaderRep;
#else
extern "C" const IID IID_CATIAfrCommandHeaderRep;
#endif

/**
  * Interface to customize the representations of a command header.
  * <b>Role</b>This interface, implemented on a class deriving from
  *  @href CATAfrDialogCommandHeader , enables you to provide for your command header 
  *  a customized representation into the toolbar, and/or the menubar, and/or the
  *  contextual menu .
  *   <br>This interface is called by the "frame" when a representation of the command header
  * is necessary during a workshop change ( and only during workshop change ) : in other words, 
  * each time the command header instance is associated with a starter during workshop change. 
  *  <ul>
  *    <li>You can in a workshop, associated with more one starter a command header instance, </li>
  *    <li>The end user can Drag/Drop a command header instance into a toolbar thanks the
  *        Tools/Customize command.
  *    <li>If two documents are opened, there are two representations of the same command header instance</li>
  *  </ul>
  *  Depending on the type of container of the starter, one of the three methods of this
  * interface is called. Each method creates an instance of a class deriving from
  * @href CATAfrCommandHeaderRep, or either returns E_FAIL if no representation. 
  */
class ExportedByCATAfrItf CATIAfrCommandHeaderRep: public CATBaseUnknown
{
  CATDeclareInterface;

public:

	/**
    * Creates a representation to be displayed in a toolbar.
    * <br><b>Role:</b>This method creates and returns an instance of a
    * class deriving from @href CATAfrCommandHeaderRep 
    * which will be the representation of the command header in a toolbar.
    * This representation manages one or several <tt>Dialog</tt> derived objects.
    * The representation will be automatically released .
    * @param iParent
    *    The parent for the CATDialog derived objects to create
    * @param oHdrRep
    *    The representation to be displayed in a toolbar.
    * @return 
    *  S_OK : oHdrRep is created otherwise E_FAIL
    */
  virtual HRESULT CreateToolbarRep (const CATDialog * iParent, CATAfrCommandHeaderRep ** oHdrRep) = 0;

	/**
    * Creates a representation to be displayed in the menu bar.
    * <br><b>Role:</b>This method creates and returns an instance of a
    * class deriving from @href CATAfrCommandHeaderRep 
    * which will be the representation of the command header in a toolbar.
    * This representation manages one or several <tt>Dialog</tt> derived objects.
    * The representation will be automatically released .
    * @param iParent
    *    The parent for the CATDialog derived objects to create
    * @param oHdrRep
    *    The representation to be displayed in the menu bar.
    * @return 
    *  S_OK : oHdrRep is created otherwise E_FAIL
    */
  virtual HRESULT CreateMenuRep (const CATDialog * iParent, CATAfrCommandHeaderRep ** oHdrRep) = 0;

	/**
    * Creates a representation to be displayed in a contextual menu.
    * <br><b>Role:</b>This method creates and returns an instance of a
    * class deriving from @href CATAfrCommandHeaderRep 
    * which will be the representation of the command header in a toolbar.
    * This representation manages one or several <tt>Dialog</tt> derived objects.
    * The representation will be automatically released .
    * @param iParent
    *    The parent for the CATDialog derived objects to create
    * @param oHdrRep
    *    The representation to be displayed in a contextual menu.
    * @return 
    *  S_OK : oHdrRep is created otherwise E_FAIL
    */
  virtual HRESULT CreateCtxMenuRep (const CATDialog * iParent, CATAfrCommandHeaderRep ** oHdrRep) = 0;

};

CATDeclareHandler (CATIAfrCommandHeaderRep, CATBaseUnknown);

#endif//__CATIAfrCommandHeaderRep_h
