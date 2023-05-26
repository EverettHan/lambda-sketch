/**
* @level Protected 
* @usage U1
*/
#ifndef gimsearch_h
#define gimsearch_h
#include "CATIADataInterfaces.h"

/** 
* Retrieves the model which has the given Path.
*
* @param name [inout]
*   The path of the model.
* @param mnum [inout]
*   The model.
*
* @return
*   0 if everything ran OK. 
*
*/
#ifdef PLATEFORME_DS64
extern "C" ExportedByCATIAEntity
        int gimsearch(const char* name, int &mnum);
#else
class CATIAModel;
extern "C" ExportedByCATIAEntity
        int gimsearch(const char* name, CATIAModel* &mnum);
#endif

#endif
/* 10.03.97 */
