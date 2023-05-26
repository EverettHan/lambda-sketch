// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageColorsRepositories_H
#define CATManageColorsRepositories_H

#include "CATVisFoundation.h"      
    
#define NB_CUSTOM_COLORS 100

extern void  ExportedByCATVisFoundation CATGetBasicColors(int *);
extern void  ExportedByCATVisFoundation CATSetBasicColors(int *);
extern void  ExportedByCATVisFoundation CATGetCustomColors(int *);
extern void  ExportedByCATVisFoundation CATSetCustomColors(int *);
extern void  ExportedByCATVisFoundation CATSaveBasicColorsRepository();
extern void  ExportedByCATVisFoundation CATSaveCustomColorsRepository();
extern void  ExportedByCATVisFoundation CATCommitBasicColorsRepository();
extern void  ExportedByCATVisFoundation CATCommitCustomColorsRepository();
extern void  ExportedByCATVisFoundation CATRollbackBasicColorsRepository();
extern void  ExportedByCATVisFoundation CATRollbackCustomColorsRepository();
extern void  ExportedByCATVisFoundation CATInitializeBasicColorsRepository();
extern void  ExportedByCATVisFoundation CATInitializeCustomColorsRepository();

#endif
