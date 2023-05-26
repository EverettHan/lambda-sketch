/**
* @level Protected 
* @usage U1
*/
#ifndef gimcur_h
#define gimcur_h
#include "CATIADataInterfaces.h"

/** 
* retrieves the current model.
*
* @param mnum [inout]
*   The current model.
* @param ier [in]
*   The error code.
*
* @return
*   0 if everything ran OK. 
*
*/
#ifdef PLATEFORME_DS64
extern "C" ExportedByCATIAEntity
        int gimcur(int &mnum, int &ier);
#else
class CATIAModel;
extern "C" ExportedByCATIAEntity
        int gimcur(CATIAModel* &mnum, int &ier);
#endif

#endif
/* 10.03.97 */
