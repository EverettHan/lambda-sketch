// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageLightSourceRepository_H
#define CATManageLightSourceRepository_H

#include "SceneGraphManager.h"      

#define NB_LIGHT_SOURCE 2    
 
extern ExportedBySceneGraphManager int  CATGetLightNumber();
extern ExportedBySceneGraphManager void CATSetLightNumber(const int iNumber);

extern ExportedBySceneGraphManager float* CATGetGlobalAmbientCoefficient();
extern ExportedBySceneGraphManager void   CATSetGlobalAmbientCoefficient(
                                                        const float *ambient);

extern ExportedBySceneGraphManager float* CATGetDiffuseCoefficient(
                                                         const int iIndice);
extern ExportedBySceneGraphManager void   CATSetDiffuseCoefficient(
                                                        const int iIndice,
                                                        const float *diffuse);

extern ExportedBySceneGraphManager float* CATGetAmbientCoefficient(
                                                        const int iIndice);
extern ExportedBySceneGraphManager void   CATSetAmbientCoefficient(
                                                        const int iIndice,
                                                        const float *ambient);

extern ExportedBySceneGraphManager float* CATGetSpecularCoefficient(
                                                        const int iIndice);
extern ExportedBySceneGraphManager void   CATSetSpecularCoefficient(
                                                        const int iIndice,
                                                        const float *specular);

extern ExportedBySceneGraphManager float* CATGetDirection(const int iIndice);
extern ExportedBySceneGraphManager void   CATSetDirection(
                                                        const int iIndice,
                                                        const float *direction);

extern ExportedBySceneGraphManager void CATInitializeLightSourceRepository(const int force=0);
extern ExportedBySceneGraphManager void CATSaveLightSourceRepository();
extern ExportedBySceneGraphManager void CATCommitLightSourceRepository();
extern ExportedBySceneGraphManager void CATRollbackLightSourceRepository();

#endif
