#ifndef CATICmdAction_H
#define CATICmdAction_H

/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#include <IUnknown.h>

/**
 * Action behavior.
 * An action must implement this interface and is associated with a
 * transition or a state.
 */
class  CATICmdAction : public IUnknown
{
  
public:
  
  /**
  * Executes the action.
  */
  virtual HRESULT Do () = 0;
  

};

/* 87c6bc99-42c4-0000-0280-030b27000000 */
extern "C" const IID IID_CATICmdAction;

#endif
