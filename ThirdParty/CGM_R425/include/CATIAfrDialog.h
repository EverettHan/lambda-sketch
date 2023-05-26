/* -*-c++-*- */
#ifndef _CATIAfrDialog_H
#define _CATIAfrDialog_H

// COPYRIGHT DASSAULT SYSTEMES  1997

/**
 * @CAA2Level L1
 * @CAA2Usage U6
 */

#include "IUnknown.h"
#include "CATAfrItf.h"

class CATAfrDialogRep;
class CATDialog;
class CATNotification;

/**
 * Class to derive to provide an interface to visualize object in a toolbar.
 * <b>Role</b>: This interface is used by a @href CATCommandHeaderWithSDO 
 * command header class.
 * <br>
 * To be seen in the toolbar, the object must be set in the Set of Dialog Object (SDO) and must 
 * implement an interface which derives from the current one. 
 * <ul>
 * <li>The class header file :</li>
 * <pre>
 *   #include "CATIAfrDialog.h" 
 *   [#include "ModuleName.h" ]
 *   [extern ExportedByModuleName] IID IID_CATIDerivedInterface;
 *
 *   class  [ExportedByModuleName] CATIDerivedInterface : public CATIAfrDialog
 *   {
 *       public:
 *   }
 * </pre>
 * <li>The implement class:</li>
 * <br>
 * <pre>
 *   #include "CATIDerivedInterface.h"
 *   // Use uuid_gen -C on UNIX or uuidgen -s on NT  to generate the IID 
 *   extern "C" const IID IID_CATIDerivedInterface = { uuid } ;
 * </pre>
 * </ul>
 * @see CATCommandHeaderWithSDOForAgent
 */
class ExportedByCATAfrItf CATIAfrDialog : public IUnknown
{
public: 
  
/**
 * @nodoc
 * Constructs a representation of an object set in the CATSDO.
 * <br><b>Role</b>:This method is called by the @href CATCommandHeaderWithSDO process
 * to get the representation of the object by this interface.
 * <br><b>Lifecycle of oRep </b>
 * <br>
 * This method can be called more than once, but at each time there is a creation of an
 * representation. The implementation keeps the new pointer in the list and the caller
 * too.(the caller is an internal object)  
 * <br>When the caller want delete a given representation:
 * <ul>
 * <li>it calls the @href #InvalidateRep method to 
 * take the representation out of the list, </li>
 * <li>it takes the representation out of
 * its own liste, </li>
 * <li>and at least deletes the representation.</li>
 * </ul>
 * @param iParent
 *   The Parent, see @href CATDialog, of the created representation.  
 * @param oRep
 *    The representation of the object 
 *    <br><b>Cyclic Reference</b>: the pointer of the representation 
 *     is kept in the implementation. 
 * @return 
 * <dl>
 * <dt> <tt>S_OK</tt>    <dd> The representation has been built.
 * <dt> <tt>S_FALSE</tt> <dd> The representation hasn't been built.
 * </dl>
 */
  virtual HRESULT GetRep( CATDialog * iParent, CATAfrDialogRep ** oRep ) = 0;


/**
 * @nodoc
 * Updates the representation of an object set in the CATSDO.
 * <br><b>Role</b>:This method is called by the @href CATCommandHeaderWithSDO process
 * to update the representation of the object. Update operation doesn't delete iRep, you can
 * only change the "contents" of the representation. [ for add/remove/modify a widget ] 
 * @param iRep
 *   the representation to update. An object can have several representation. 
 * @param iNotification
 *   Information about the update operation. This data can be NULL 
 * @return 
 * <dl>
 * <dt> <tt>S_OK</tt>    <dd> The update is OK 
 * <dt> <tt>S_FALSE</tt> <dd> The update is KO, so in this case the @href CATCommandHeaderWithSDO
 * deletes the rep and asks a new creation.
 * </dl>
 */

  virtual HRESULT UpdateRep( const CATAfrDialogRep * iRep, const CATNotification * iNotification) = 0;

/**
 * @nodoc
 * Invalids a representation of an object set in the CATSDO.
 * <br><b>Role</b>: Object is aware that iRep will be deleted. So object must 
 * take off all references that it has on it. 
 * See the @href #GetRep method to understand the lifecycle of an object'representation
 * @param iRep
 *   The representation to invalid
 *
 */
  virtual HRESULT InvalidateRep( const CATAfrDialogRep * iRep ) = 0;
  
};

#endif
