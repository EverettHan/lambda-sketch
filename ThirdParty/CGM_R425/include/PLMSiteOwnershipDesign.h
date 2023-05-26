// *****************************************************************
// COPYRIGHT DASSAULT SYSTEMES 2015
// *****************************************************************
//
//   Identification :
//   ----------------
//
//      RESPONSIBLE : Sandeep SWAMI
//      FUNCTION    : Site Information Experience customization
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description : 
//   -------------
//      This class will be to hold the different status, operation Ids used in Site information command.
//
// *****************************************************************
//
//   Remark :
//   --------
//
/**
  * @level Private
  * @usage U1
  */
//
// *****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  January  2015  (ZUK) Initial Revision for V6R2016
//
// ****************************************************************
#ifndef PLMSiteOwnershipDesign_H
#define PLMSiteOwnershipDesign_H

// System
#include "CATUnicodeString.h"                      //CATSysTS.m

//*************** GROUPS & OPTIONS ***********************//
const CATUnicodeString cSiteOwnershipMngtOptionGroup                       = "CATPLMSiteOwnershipManagementCommand.SiteMngtGroupOption";
const CATUnicodeString cSiteOwnershipMngtSelectOption                      = "CATPLMSiteOwnershipManagementCommand.SiteMngtSelectOption";
const CATUnicodeString cSiteOwnershipMngtSelectOperationGroup              = "CATPLMSiteOwnershipManagementCommand.SiteMngtOperationGroup";

//*************** STATUS ************************//
const CATUnicodeString cSiteOwnershipMngtDefinitionTitle                   = "CATPLMSiteOwnershipManagementCommand.Definition";
const CATUnicodeString cSiteOwnershipMngtStatusLocal                       = "CATPLMSiteOwnershipManagementCommand.Local";
const CATUnicodeString cSiteOwnershipMngtStatusExchanged                   = "CATPLMSiteOwnershipManagementCommand.Exchanged";
const CATUnicodeString cSiteOwnershipMngtStatusDelegator                   = "CATPLMSiteOwnershipManagementCommand.Delegator";
const CATUnicodeString cSiteOwnershipMngtStatusForward                     = "CATPLMSiteOwnershipManagementCommand.Forward";
const CATUnicodeString cSiteOwnershipMngtStatusDistant                     = "CATPLMSiteOwnershipManagementCommand.Distant";
const CATUnicodeString cSiteOwnershipMngtStatusDelegated                   = "CATPLMSiteOwnershipManagementCommand.Delegated"      ;
const CATUnicodeString cSiteOwnershipMngtStatusDetached                    = "CATPLMSiteOwnershipManagementCommand.Detached";
const CATUnicodeString cSiteOwnershipMngtStatusWaived                      = "CATPLMSiteOwnershipManagementCommand.Waived"  ;
const CATUnicodeString cSiteOwnershipMngtStatusRevoked                     = "CATPLMSiteOwnershipManagementCommand.Revoked";
const CATUnicodeString cSiteOwnershipMngtStatusForcedToDistant             = "CATPLMSiteOwnershipManagementCommand.ForcedToDistant";
const CATUnicodeString cSiteOwnershipMngtStatusForcedToLocal               = "CATPLMSiteOwnershipManagementCommand.ForcedToLocal"  ;
const CATUnicodeString cSiteOwnershipMngtStatusNone                        = "None";

//*************** OPERATION ************************************************//
const CATUnicodeString cPLMExportSiteInfoExperienceOperationDetach         = "CATPLMSiteOwnershipManagementCommand.Operation.Detach"        ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationRevoke         = "CATPLMSiteOwnershipManagementCommand.Operation.Revoke"        ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationWaive          = "CATPLMSiteOwnershipManagementCommand.Operation.Waive"  ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationLocal          = "CATPLMSiteOwnershipManagementCommand.Operation.Local"            ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationDistant        = "CATPLMSiteOwnershipManagementCommand.Operation.Distant"          ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationCancelDetach   = "CATPLMSiteOwnershipManagementCommand.Operation.CancelDetach"  ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationCancelRevoke   = "CATPLMSiteOwnershipManagementCommand.Operation.CancelRevoke"  ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationCancelWaive    = "CATPLMSiteOwnershipManagementCommand.Operation.CancelWaive"  ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationCancelDistant  = "CATPLMSiteOwnershipManagementCommand.Operation.CancelDistant"    ;
const CATUnicodeString cPLMExportSiteInfoExperienceOperationCancelLocal    = "CATPLMSiteOwnershipManagementCommand.Operation.CancelLocal"      ;


//*************** EXECUTION ***********************************************//
const CATUnicodeString cPLMDefaultExperienceOK                          = "CATPLMSiteOwnershipManagementCommand.Execute.OK";
const CATUnicodeString cPLMExchangeExperienceReset                      = "CATPLMSiteOwnershipManagementCommand.Execute.Reset";
const CATUnicodeString cPLMDefaultExperienceCancel                     = "CATPLMSiteOwnershipManagementCommand.Execute.Cancel";

#endif
