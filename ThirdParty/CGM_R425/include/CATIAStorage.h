/**
 * @level Protected
 * @usage U1
 */
/* CATIAStorage.h : COPYRIGHT DASSAULT SYSTEMES 1996 */
#ifndef  CATIAStorage_h
#define  CATIAStorage_h

#include<ExportedByCATIAEntity.h>

class CATIAModel;

extern "C"
{
#ifdef PLATEFORME_DS64
ExportedByCATIAEntity int gimread(const char* name, int &oMnum, int &ier);
ExportedByCATIAEntity int gimwrite(const char* name, int &iMnum, int &ier);
#else /* PLATEFORME_DS64 */
ExportedByCATIAEntity int gimread(const char* name, CATIAModel* &oModel, int &ier);
ExportedByCATIAEntity int gimwrite(const char* name, CATIAModel *const iModel, int &ier);
#endif /* PLATEFORME_DS64 */
}
#endif /* CATIAStorage_h */  

















