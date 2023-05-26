
#ifndef CATISwapShowSpaceCmdState_H
#define CATISwapShowSpaceCmdState_H

// COPYRIGHT Dassault Systemes 2014/09/12

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATISwapShowSpaceCmdState;
#else
extern "C" const IID IID_CATISwapShowSpaceCmdState ;
#endif

/**
 * Interface used to manage the command CATCmdSwapShowSpace
 */
class ExportedByCATAfrItf CATISwapShowSpaceCmdState: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** 
  * Makes the command Available.
  * <br><b>Role</b>: The command of the header becomes available. The icon switches from
  * the grayed to the normal state.
  */
  virtual void BecomeAvailable() = 0;
  
  /** 
  * Makes the command Unavailable.
  * <br><b>Role</b>: The command of the header becomes unavailable. The icon switches from
  * the normal to the grayed state.  
  */
  virtual void BecomeUnavailable () = 0;

};
CATDeclareHandler( CATISwapShowSpaceCmdState, CATBaseUnknown );
#endif
