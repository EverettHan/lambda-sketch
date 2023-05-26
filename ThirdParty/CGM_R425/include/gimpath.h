/**
* @level Protected 
* @usage U1
*/
#ifndef gimpath_h
#define gimpath_h
#include "CATIADataInterfaces.h"

/** 
* Retrieves the path of a given model.
*
* @param mnum [inout]
*   The model number.
* @param pathname [inout]
*   The path of the model.
* @param ier [in]
*   The error code.
*
* @return
*   0 if everything ran OK. 
*
*/
#ifndef PLATEFORME_DS64
extern "C" ExportedByCATIAEntity
        int gimpath(int &mnum, const char* &pathname, int &ier);
#else
class CATIAModel;
extern "C" ExportedByCATIAEntity
        int gimpath(CATIAModel *const &mnum, const char* &pathname, int &ier);
#endif

#endif
/* 10.03.97 */
