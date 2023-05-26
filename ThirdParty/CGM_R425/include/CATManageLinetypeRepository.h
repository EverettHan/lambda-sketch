// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageLinetypeRepository_H
#define CATManageLinetypeRepository_H

#include "SGInfra.h"      
#include "CATVizDisplayContext.h"

class CATSettingRepository;
class CATVizViewer;


extern ExportedBySGInfra void CATGetLinetype(const int iIndex, unsigned short *pattern, unsigned short *ratio, unsigned short *type, CATVizDisplayContext *vdc=NULL);
extern ExportedBySGInfra void CATSetLinetype(const int iIndex, const unsigned short pattern, const unsigned short ratio, const unsigned short type);

extern ExportedBySGInfra void    CATSetLinetypeSegments(const int iIndex, const unsigned int nb, const float *tab);
extern ExportedBySGInfra float * CATGetLinetypeSegments(const int iIndex, unsigned int *nb);

extern ExportedBySGInfra void CATSetModifyLineFont();

extern ExportedBySGInfra char CATGetLockLinetype();
extern ExportedBySGInfra long CATSetLockLinetype(const int iLockMode);

extern ExportedBySGInfra void CATInitializeLinetypeRepository(const int force=0);
extern ExportedBySGInfra void CATSaveLinetypeRepository();
extern ExportedBySGInfra void CATCommitLinetypeRepository();
extern ExportedBySGInfra void CATRollbackLinetypeRepository();

extern ExportedBySGInfra CATSettingRepository * CATGetLinetypeRepository();
#endif
