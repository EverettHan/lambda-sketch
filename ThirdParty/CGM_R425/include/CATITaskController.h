#ifndef __CATITaskController_h
#define __CATITaskController_h

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATCmdContainer;

extern ExportedByCATAfrItf IID IID_CATITaskController;

/**
 * @nodoc
 */
class ExportedByCATAfrItf CATITaskController : public CATBaseUnknown
{
	
  CATDeclareInterface;
  
public:

	/**
	 * @nodoc
	 * Interrupts the current progress task if it exists
	 */
  virtual void Interrupt () = 0;

};

#endif
