#ifndef _CATPLMComponentCheckerAccess_H
#define _CATPLMComponentCheckerAccess_H
/**
 * @level Private
 * @usage U1
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATIPLMComponentChecker;

#if ! defined ( CheckerContext_definition )
#define CheckerContext_definition
typedef unsigned int CheckerContext;
#endif

#define CheckerContext_None                           0x00000000
#define CheckerContext_All                            0xFFFFFFFF
#define CheckerContext_Save                           0x00000001
#define CheckerContext_Open                           0x00000002
#define CheckerContext_Versioning                     0x00000004
#define CheckerContext_Cloning                        0x00000008
#define CheckerContext_Import                         0x00000010
#define CheckerContext_Refresh                        0x00000020

class ExportedByCATPLMTos CATPLMComponentCheckerAccess
{
public:
  /**
  * Looks if a checking mode is activated and returns checker if available
  */
  static CATIPLMComponentChecker * GetChecker (CheckerContext iCheckerContext);

private:

  friend class CATOxcComponentChecker;

  static CATBoolean IsNeverActivated() {return !_ActivationDrived;}

  static CheckerContext GetActivation();

  static void ChangeActivation(CheckerContext iCheckerContext);

  static CATBoolean     _ActivationDrived;
  static CheckerContext _BitField;
};

#endif
