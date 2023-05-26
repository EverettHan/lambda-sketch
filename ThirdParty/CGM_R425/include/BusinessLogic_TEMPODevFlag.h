/* COPYRIGHT Dassault Systemes 2010
===================================================================

BusinessLogic_TEMPODevFlag : Development Flags Declaration

===================================================================
Feb 2010  Creation                                            ADZ
===================================================================*/

#ifndef __BusinessLogic_TEMPODevFlag_h__
#define __BusinessLogic_TEMPODevFlag_h__

/**
* @level Protected
* @usage U1
*/

// Export
#include "PLMBLTempoDevFlags.h"

#include "CATBoolean.h"
#include "IUnknown.h"

class ExportedByPLMBLTempoDevFlags BusinessLogic_TEMPODevFlag
{
public:

  enum ActivatedProject{
    DisableCheck = 1,     /* PLMBL_DISABLE_CHECK */
    AddParseError = 2,    /* PLMBL_ADD_PARSE_ERROR */
    ODTResetStatic = 3,   /* PLMBL_CTD_RESET_STORED_TARGET_PROVIDER */
    IdentifyCntn = 4,     /* PLMBL_ALLOW_CONNECTION_FOR_IMPLICIT_OPERATION */
    ReplaceReference = 5, /* PLMBL_ACTIVATE_REPLACE_REFERENCE */              /* [V6R2010x] */
    CustoDiscipline = 6   /* PLMBL_ACTIVATE_CUSTODISCIPLINE */                /* [V6R2011x] */
  };

  static CATBoolean IsProjectActive(ActivatedProject iProject);

private:

  static void DumpDevFlags();
};
#endif
