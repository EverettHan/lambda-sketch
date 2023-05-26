/**
 * @level Private
 * @usage U1
 */
#ifndef CATOmbPLMActiveContextType_h
#define CATOmbPLMActiveContextType_h

/**
* Defines the PLM persistency action currently in progress.
* <b> Role:</b>
* It Indicates whether a PLM Open/Save/Fill/Expand/Refresh process is currently running
* in the current session.
*@param 
* 	CATPLMNoPersistAction  : No PLM persistency process currently running
*@param 
* 	CATPLMOpenEngineActive : PLM Open engine is currently running
*@param 
* 	CATPLMSaveEngineActive : PLM Save engine is currently running
*@param 
* 	CATPLMFillEngineActive : PLM Fill engine is currently running
*@param 
* 	CATPLMExpandEngineActive : PLM Expand engine is currently running
*@param 
* 	CATPLMRefreshEngineActive : PLM Refresh engine is currently running
*/
enum CATPLMActiveContext
{
  CATPLMNoPersistAction  = 0,
  CATPLMOpenEngineActive = 1,
  CATPLMSaveEngineActive = 2,
  CATPLMFillEngineActive = 3,
  CATPLMExpandEngineActive = 4,
  CATPLMRefreshEngineActive = 5
};

#endif
