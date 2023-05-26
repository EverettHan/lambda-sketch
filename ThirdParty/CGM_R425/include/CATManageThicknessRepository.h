// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageThicknessRepository_H
#define CATManageThicknessRepository_H

#include "SGInfra.h"      
class CATSettingRepository;
class CATVizViewer;

#define NB_VISU_THICK 63
    
extern float ExportedBySGInfra CATGetMMThickness(const int iIndex, const int mode=1);
extern void  ExportedBySGInfra CATSetMMThickness(const int iIndex,const float iMMValue);

extern int   ExportedBySGInfra CATGetPixelThickness(const int iIndex, const int mode=1);
extern void  ExportedBySGInfra CATSetPixelThickness(const int iIndex,const int iPixelValue);

extern char  ExportedBySGInfra CATGetLockThickness();
extern long  ExportedBySGInfra CATSetLockThickness(const int iLockMode);

extern void  ExportedBySGInfra CATInitializeThicknessRepository(const int force=0);
extern void  ExportedBySGInfra CATSaveThicknessRepository();
extern void  ExportedBySGInfra CATCommitThicknessRepository();
extern void  ExportedBySGInfra CATRollbackThicknessRepository();

extern ExportedBySGInfra CATSettingRepository * CATGetThicknessRepository();

#endif
