#ifndef __CATOmyAsyncProcessConstants_H
#define __CATOmyAsyncProcessConstants_H
#include "CATOMYCuteIO.h"
/**
* @level Protected
* @usage U1
*/


/** Class meant to store enum relatives to processes. 
*/
class ExportedByCATOMYCuteIO CATOmyAsyncProcessConstants
{
public:
  enum Appli
  {
    Appli_Unknown,
    Appli_CATIA,
    Appli_ProcVVSAsync,
    Appli_ProcPLMQLAsync,    
    Appli_ProcGenericAsync
  };

  //Task State
  /** States of process tasks, those prefixed by '_' must not be set directly,
  they need a previous state initialization */

  enum State
  {
    // Common states
    State_New = 0,
    State_PrefetchConnection,
    State_Init,
    State_BeginTransaction,
    State_EndTransaction,
    State_Kill,
    State_KillNoRespawn,
    State_Error,
    // ####################################################################################################
    // States exclusively used process SIDE
    // ####################################################################################################
    _State_Idle,                // Internal idle state
    State_WaitForOrderBegin,
    _State_WaitForOrder,        // Don't do a direct transition to this state,
    // go instead through State_WaitForOrderBegin
    State_StartTransaction,
    State_PLMQLTransaction,    
    State_GenericTransaction,
    State_VVSTransaction,    
    // ####################################################################################################
    // States exclusively used by CATIA
    // ####################################################################################################
    State_WaitForAck,
    State_WaitForConnect,
    State_HasBeenCanceled,
    State_Treating
  };

  //Error type
  enum Error
  {
    Error_None,
    Error_TransactionId,
    Error_Treatment,
    Error_TransactionState,
    Error_ReadXML,
    Error_CopyUrl,
    Error_Kill
  };

  //Expand result Msg
  enum ExpandResultState
  {
    Expand_StartResult,
    Expand_EndResult,
    Expand_StartBlock,
    Expand_EndBlock,
    Expand_StartPath,
    Expand_EndPath,
    Expand_Record,
    Expand_GlobalReport
  };
};
#endif
