/**
* @level Protected 
* @usage U1
*/
#ifndef g7usearch_h
#define g7usearch_h
#include "CATIADataInterfaces.h"

#ifndef CATIAuuid_typedef_h
#define CATIAuuid_typedef_h
typedef unsigned char CATIAuuid[16];
#endif

/** 
* Retrieves the jele and the model of a CATIA element from its UUID.
*
* @param key [inout]
*   The uuid of the element.
* @param model [inout]
*   The model of the element.
* @param jele [inout]
*   The jele of the element having the UUID.
* @param ier [in]
*   The error code.
*
* @return
*   0 if everything ran OK. 
*
*/
#ifdef PLATEFORME_DS64
extern "C" ExportedByCATIAEntity
        int g7usearch(const CATIAuuid key, int &model,
                      int &jele, int &ier);
#else
class CATIAModel;
extern "C" ExportedByCATIAEntity
        int g7usearch(const CATIAuuid key, CATIAModel* &model,
                      int &jele, int &ier);
#endif

#endif
/* 10.03.97 */
