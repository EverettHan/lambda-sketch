/**
* @level Protected 
* @usage U1
*/
#ifndef gimswap_h
#define gimswap_h
#include "CATIADataInterfaces.h"

/** 
* Swap and retrieves the previous current model.
*
* @param mnum [inout]
*   The current model
* @param previous [inout]
*   The previous current model
* @param ier [in]
*   The error code.
*
* @return
*   0 if everything ran OK. 
*
*/
#ifdef PLATEFORME_DS64


extern "C" ExportedByCATIAEntity
        int gimswap(int &mnum, int &previous, int &ier);
#else
class CATIAModel;
extern "C" ExportedByCATIAEntity
        int gimswap(CATIAModel *const &mnum, CATIAModel* &previous, int &ier);
#endif

#endif
/* 10.03.97 */
