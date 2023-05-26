#ifndef CATReadWriteSceneGraph_H
#define CATReadWriteSceneGraph_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATReadWriteCgr.h"
#include "CATErrorDef.h"

/** @nodoc */
extern ExportedBySGInfra HRESULT  CATWriteSceneGraph(CATRep * iRep, char * & oBuffer, int & oLBuffer, CATSettingCgr iSettingCgr);

/** @nodoc */
extern ExportedBySGInfra HRESULT  CATWriteTargetReleaseSceneGraph(CATRep * iRep, char * & oBuffer, int & oLBuffer, CATSettingCgr iSettingCgr, CATVizTargetCGR target);

/** @nodoc */
extern ExportedBySGInfra CATRep * CATReadSceneGraph(char *iBuffer, int iLBuffer);

#endif
