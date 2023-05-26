#ifndef CATICSOFilter_H
#define CATICSOFilter_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U5
*/


#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATCSO;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATICSOFilter ;
#else
extern "C" const IID IID_CATICSOFilter ;
#endif

/**
* Interface to disable the contextual menu commands for the selected objects. 
* <b>Role:</b> After a selection, the Select command analyzes if the current UI-Active
* object (see @href CATIUIActivate ) implements this interface. If it does, the implementation of this interface will 
* decide which commands are to be made available. If it does not, then all the commands of the 
* contextual menu are available. Before implementing this interface on your object, you must verify 
* the context you are working in:
* <ul>
* <li>if your object is in a CATProduct context, then the ASMProduct which is the UI-Active object 
* for a CATProduct document already implements this interface and disables all the commands 
* other than: Cut, Copy, Paste and Delete. For these four commands, the ASMProduct requests a 
* specific feature implementation and if none is found, the four commands are disabled.</li>
* <li>if your object is in a CATPart context, then the MechanicalPart which is the UI-Active object
* for a CATPart document, does not already implement this interface, so all the commands of the
* contextual menu are available.</li>
* </ul>
* In short, before implementing this interface, if your object is the UI-Active object,
* then you can implement this interface. Otherwise, verify the context to know if your 
* implementation will be called.
* <br><br>Note that it is always possible for a @href CATCommandHeader to decide to disable or not the
* command by overriding the @href CATCommandHeader#BecomeAvailable and 
* @href CATCommandHeader#BecomeUnavailable methods.
*/
class ExportedByCATAfrItf CATICSOFilter : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Query for command availability.
  * <br><b>Role:</b>This method is called each time the CSO change. So the 
  * command avaibility can change in according the selection.
  * @param iHeaderID 
  *  command identifier
  * @param iCSO
  *  CSO to filter
  * @return 
  *   S_OK if command available for provided objects otherwise S_FALSE.
  *   <br>E_FAIL if unexpected internal problem
  */
  virtual HRESULT CommandIsAvailable (const char * iHeaderID,
				      const CATCSO * iCSO ) = 0;

  /**
   * Query for available objects from CSO.
   * @param iHeaderID 
   *  command identifier
   * @param iCSO
   *  CSO to filter
   * @param ioAvailableElements
   *  available objets for command. In entry it contains the CSO's objects.
   * @return 
   *   S_OK 
   */
  virtual HRESULT AvailableElements (const char * iHeaderID,
				     const CATCSO * iCSO,
				     CATListValCATBaseUnknown_var ** ioAvailableElements ) = 0;
  
};

CATDeclareHandler( CATICSOFilter, CATBaseUnknown );

#endif



