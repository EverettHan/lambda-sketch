#ifndef CATIRepeatableCommand_h
#define CATIRepeatableCommand_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIRepeatableCommand;
#else
extern "C" const IID IID_CATIRepeatableCommand;
#endif

/**
 * Interface to override the default behavior for command repeating.
 * <b>Role</b>:
 * This interface class provides a method to override the default behavior for command repeating,
 * when the user double-clicks on the command :
 * For Undefined and Shared commands, each clic launches the command (so a double-clic launches 
 * the command twice);
 * For exclusive commands, the double-clic sets the repeat mode, and the command will loop.
 * For exemple, the following instruction in the RepeatCommand method for a shared command 
 * will make it loop as if it was an exclusive command : 
 * SetBehavior (CATDlgEngRepeat);
 */
class ExportedByCATAfrItf CATIRepeatableCommand : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
/**
 * Overrides the default behavior for command repeating.
 */
  virtual void RepeatCommand() = 0;
};
CATDeclareHandler(CATIRepeatableCommand, CATBaseUnknown);

#endif
