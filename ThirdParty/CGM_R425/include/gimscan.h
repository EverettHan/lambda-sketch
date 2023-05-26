/**
* @level Protected 
* @usage U1
*/
#ifndef gimscan_h
#define gimscan_h
#include "CATIADataInterfaces.h"

/** 
* Scan the loaded model.
*
* @param previous [inout]
*   The previous model. NULL to initialize the scan.
* @param next [inout]
*   The following model.
* @param ier [in]
*   The error code.
*
* @return
*   0 if everything ran OK. 
*
*/
#ifdef PLATEFORME_DS64
extern "C" ExportedByCATIAEntity
    int gimscan(int &previous, int &next, int &ier);
#else
class CATIAModel;
extern "C" ExportedByCATIAEntity
    int gimscan(CATIAModel *const &previous, CATIAModel* &next, int &ier);
#endif

#endif
/* 10.03.97 */
