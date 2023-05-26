#ifndef CATTopRibTimerTree_H
#define CATTopRibTimerTree_H

// For dumping timer-tree info: 
// - use #define ActivateCATTopRibTimerTree 1
// - use #define ActivateCATechTimerTree 1 in CATTechTimerTree.h
// - change File Name (CATechTimerTreeLogFile) in CATTechTimerTree.cpp

#define ActivateCATTopRibTimerTree 0

#if defined  (ActivateCATTopRibTimerTree)  &&  (ActivateCATTopRibTimerTree  ==  1) 
  #include "CATechTimerTree.h"
  #define CATTopRibBlockMacro(BLOCK_NAME) CATechDeclareBlock(BLOCK_NAME)
  #define CATTopRibFuncMacro(FUNC_NAME) CATechDeclareFunction(FUNC_NAME)
#else //i.e. #ifndef ActivateCATTopRibTimerTree
  #define CATTopRibBlockMacro(BLOCK_NAME)
  #define CATTopRibFuncMacro(FUNC_NAME)
  #define CATechTimerTree_TryBlockStart
  #define CATechTimerTree_TryBlockEnd
#endif // ActivateCATTopRibTimerTree


#endif // CATTopRibTimerTree_H

