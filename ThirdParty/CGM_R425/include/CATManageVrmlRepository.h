// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageVrmlRepository_H
#define CATManageVrmlRepository_H

#include "SceneGraphManager.h"      
//#include "CATListOfCATString.h"
    
extern ExportedBySceneGraphManager int CATGetVrmlImportUnit();
extern ExportedBySceneGraphManager void CATSetVrmlImportUnit(const int);
    
extern ExportedBySceneGraphManager float CATGetVrmlImportCreaseAngle();
extern ExportedBySceneGraphManager void CATSetVrmlImportCreaseAngle(const float);

extern ExportedBySceneGraphManager int CATGetVrmlExportVersion();
extern ExportedBySceneGraphManager void CATSetVrmlExportVersion(const int);
    
extern ExportedBySceneGraphManager int CATGetVrmlSaveNormals();
extern ExportedBySceneGraphManager void CATSetVrmlSaveNormals(const int);

extern ExportedBySceneGraphManager int CATGetVrmlSaveEdges();
extern ExportedBySceneGraphManager void CATSetVrmlSaveEdges(const int);

extern ExportedBySceneGraphManager int CATGetVrmlSaveTexture();
extern ExportedBySceneGraphManager void CATSetVrmlSaveTexture(const int);

extern ExportedBySceneGraphManager int CATGetVrmlSaveTextureFile();
extern ExportedBySceneGraphManager void CATSetVrmlSaveTextureFile(const int);

extern ExportedBySceneGraphManager int CATGetVrmlSaveTextureFormat();
extern ExportedBySceneGraphManager void CATSetVrmlSaveTextureFormat(const int);

extern ExportedBySceneGraphManager void CATGetVrmlBackgroundColor(unsigned int *,
    							unsigned int *,
    							unsigned int *);
extern ExportedBySceneGraphManager void CATSetVrmlBackgroundColor(const unsigned int,
    		 				 const unsigned int,
    		 				 const unsigned int);

extern ExportedBySceneGraphManager void CATSaveVrmlRepository();
extern ExportedBySceneGraphManager void CATCommitVrmlRepository();
extern ExportedBySceneGraphManager void CATInitializeVrmlRepository(int force=0);
extern ExportedBySceneGraphManager void CATRollbackVrmlRepository();

#endif
