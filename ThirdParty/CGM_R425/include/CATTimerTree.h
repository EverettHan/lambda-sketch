#ifndef CATTimerTree_H
#define CATTimerTree_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U1
 */
//-------------------------------------------------------------------------------------------------
//     To avoid Tessellation or HLR prerequisite , have a look on internal migration CGM
//       Mathematics\ProtectedInterfaces\CATechTimerTree.h
//-------------------------------------------------------------------------------------------------
#include "HLRTools.h"
#include "CATechTimerTree.h"
 
#if defined  (ActivateCATechTimerTree)  &&  (ActivateCATechTimerTree ==  1)  

class ExportedByHLRTools CATTimerTreeGenerator 
  : public CATechTimerTreeGenerator
{
  void DummyFunction();
};

class ExportedByHLRTools CATBlockTimer 
  : public CATechBlockTimer
{
public:
  CATBlockTimer(const char* sBlockName);
};

class ExportedByHLRTools CATFunctionTimer 
  : public CATechFunctionTimer
{
public:
  CATFunctionTimer(const char* sFuncName);
};

#define CATDeclareBlock(BLOCK_NAME) CATBlockTimer __ThisBlock_DontUseMyNameElsewhere(#BLOCK_NAME)
#define CATDeclareFunction(FUNC_NAME) CATFunctionTimer __ThisFunction_DontUseMyNameElsewhere(#FUNC_NAME)

#endif //ActivateCATechTimerTree

#endif
