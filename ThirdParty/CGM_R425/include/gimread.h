/**
* @level Protected 
* @usage U1
*/
#ifndef gimread_h
#define gimread_h
#include "CATIADataInterfaces.h"

/** 
* Loads a CATIA model.
*
* @param name [inout]
*   The path of the model to read.
* @param mnum [inout]
*   The number of the model.
* @param ier [in]
*   The error code.
*
* @return
*   0 if everything ran OK. 
*
*/
#ifdef PLATEFORME_DS64

extern "C" ExportedByCATIAStorage
        int gimread(const char* name, int &mnum, int &ier);
#else
class CATIAModel;
extern "C" ExportedByCATIAStorage
        int gimread(const char* name, CATIAModel* &mnum, int &ier);
#endif

#endif
/* 10.03.97 */
