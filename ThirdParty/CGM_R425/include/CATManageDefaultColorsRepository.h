// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageDefaultColorsRepository_H
#define CATManageDefaultColorsRepository_H

#include "CATVisItf.h"      
    
extern ExportedByCATVisItf void CATGetEdgeValues(unsigned int *);
extern ExportedByCATVisItf void CATSetEdgeValues(const unsigned int *);
    
extern ExportedByCATVisItf void CATGetLineicValues(unsigned int *);
extern ExportedByCATVisItf void CATSetLineicValues(const unsigned int *);
    
extern ExportedByCATVisItf void CATGetMeshValues(unsigned int *);
extern ExportedByCATVisItf void CATSetMeshValues(const unsigned int *);
    
extern ExportedByCATVisItf void CATGetPointValues(unsigned int *);
extern ExportedByCATVisItf void CATSetPointValues(const unsigned int *);
    

extern ExportedByCATVisItf void CATSaveDefaultColorsRepository();
extern ExportedByCATVisItf void CATCommitDefaultColorsRepository();
extern ExportedByCATVisItf void CATInitializeDefaultColorsRepository();
extern ExportedByCATVisItf void CATRollbackDefaultColorsRepository();

#endif
