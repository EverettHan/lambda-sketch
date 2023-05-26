#ifndef CATIAfrGeneralWksAddin_h
#define CATIAfrGeneralWksAddin_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATIWorkbenchAddin.h"

extern ExportedByCATAfrItf IID IID_CATIAfrGeneralWksAddin;

/**
* Interface to implement to create an addin on the general workshop.
* <b>Role</b>: The general workshop can be customized by the client 
* application programmer. This customization consists in putting commands into one or 
* several new toolbars, and add these toolbars to the general workshop. 
* <br>
*/
class ExportedByCATAfrItf CATIAfrGeneralWksAddin : public CATIWorkbenchAddin
{
  CATDeclareInterface;

  public:
};


#endif
