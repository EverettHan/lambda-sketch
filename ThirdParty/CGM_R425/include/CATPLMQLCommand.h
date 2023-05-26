//-*- C+ -*-
#ifndef CATPLMQLCommand_H
#define CATPLMQLCommand_H

/**
* @level Protected
* @usage U1
*/

/**
* List of PLMQL commands that can be launched by PLMAdapterQL infrastructure.
*/
enum CATPLMQLCommand 
{
  PLMQL_None            = 0
  /** Command used for SELECT (as Basic Query) */
 ,PLMQL_Query           = 1
  /** Command used for SELECT COUNT */
 ,PLMQL_QueryCount      = 2
  /** Command used for EXPAND */
 ,PLMQL_Expand          = 3
  /** Command used for SELECT (as Open) */
 ,PLMQL_Open            = 4   
  /** Deprecated will disappear soon, replaced by CheckTransaction and SaveAndCommit */
 ,PLMQL_Save            = 5   // Deprecated... Will disapear with JPO
  /** Command used for Lock/Unlock */
 ,PLMQL_LockUnlock      = 6
  /** Command used for Change maturity */
 ,PLMQL_Maturity        = 7
  /** Command used for Delete reference */
 ,PLMQL_DeleteReference = 8
  /** Command used for NAVIGATE orders */
 ,PLMQL_Navigate        = 9
  /** Command used for Versioning */
 ,PLMQL_NewVersion      = 10
  /** Command used for Cloning */
 ,PLMQL_Clone           = 11
  /** Command used for CheckEdit */
 ,PLMQL_CheckEdit       = 12
  /** Command used for Check and Prepare save */
 ,PLMQL_CheckTransaction= 13
  /** Command used for effective Save */
 ,PLMQL_SaveAndCommit   = 14
  /** Command used for Import (replication) */
 ,PLMQL_Import          = 15
  /** Command used for URL Request (Replication) */
 ,PLMQL_Request         = 16
  /** Command used for Querying maturity */
 ,PLMQL_QueryMaturity   = 17
  /** Command used for generating names */
 ,PLMQL_AutoNaming      = 18
  /** Command used for Procedure Call */
 ,PLMQL_ProcedureCall   = 19
  /** Command used for Change control (Set an element to be controled by an Action in modification API) */
 ,PLMQL_ChangeControl   = 20
  /** Command used for Copy */
 ,PLMQL_Copy            = 21
  /** Command used for 3DIndex */
 ,PLMQL_3DIndex         = 22
  /** Command used for workspace management Synchro / Deliver */
 ,PLMQL_SynchroDelivery = 23
  /** Command used to check path upon a config filter */
 ,PLMQL_QueryValidity   = 24
  /** Command to refresh an object from another */
 ,PLMQL_Refresh         = 25
  /** Command to launch a Full Text Search Query (FTS) using an index */
 ,PLMQL_SearchQuery     = 26
  /** Command to launch all IPML Search messages */
 ,IPML_Read             = 27
  /** Command to launch a short transaction IPML script */
 ,IPML_WriteLight       = 28
  /** Command to launch a long transaction IPML */
 ,IPML_WriteRich        = 29
  /** Command used for Transfer Ownership */
 ,PLMQL_TransferOwnership = 30
 /** Command used to restore a specific Iterationation */
 ,PLMQL_RestoreIteration = 31
  /** Command used for 3DIndex, new version */
 ,PLMQL_3DIndexV2        = 32
  /** Command used for DWS reservation */
 ,PLMQL_WspReservation   = 33
  /***/
  ,PLMQL_Fork = 34
};

//------------------------------------------------------------------

#endif
