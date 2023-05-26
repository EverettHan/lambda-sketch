/**
 * @level Protected
 * @usage U1
 */
/* CATIAStorage.h : COPYRIGHT DASSAULT SYSTEMES 1996 */
#ifndef  CATIAStorageExt_h
#define  CATIAStorageExt_h

#include<ExportedByCATIAEntity.h>

extern "C"
{
ExportedByCATIAEntity int gimread(const char* name, int &Mnum, int &ier);
ExportedByCATIAEntity int gimwrite(const char* name, int &Mnum, int &ier);
}
#endif /* CATIAStorage_h */


















