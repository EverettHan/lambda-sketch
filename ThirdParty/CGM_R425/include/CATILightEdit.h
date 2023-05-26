/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2001
#ifndef _CATILightEdit_h
#define _CATILightEdit_h

#include "CATBaseUnknown.h"

class CATCommand;

/**
 * CATILightEdit : Light edition for parallel mode command
 * <b>Role</b>: 
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATILightEdit;
#else
extern "C" const IID IID_CATILightEdit;
#endif

class ExportedByCATInteractiveInterfaces CATILightEdit : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
   * Light Edit by launching edit CATStateCommand.
   *   @return CATStateCommand
   *       Command which has been launched in parallel mode
   * @see CATStateCommand
   */
  virtual CATCommand* LightEdit() = 0;
};
CATDeclareHandler(CATILightEdit, CATBaseUnknown);

#endif
