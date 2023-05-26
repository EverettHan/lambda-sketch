/**
* @level Protected 
* @usage U1
*/
#ifndef gisfws_h
#define gisfws_h
#include "CATIADataInterfaces.h"


/** 
* Retrieves the first workspace of a model.
*
* <br><b>Role</b>: Explain what this method does.
*
* @param mnum_ [inout]
*   The model.
* @param numovl_ [inout]
*   The overlay number. (Not used).
* @param jwsp_ [inout]
*   The jele of the first workspace
* @param ier_ [in]
*   error code.
*
* @return
*   0 if everything ran OK.
*
*/
#ifdef PLATEFORME_DS64

extern "C" ExportedByCATGEOBasic
        int gisfws(const int *mnum_, const int* numovl_, int* jwsp_, int* ier_);
#else
class CATIAModel;
extern "C" ExportedByCATGEOBasic
        int gisfws(CATIAModel *const &mnum_, const int* numovl_, int* jwsp_, int* ier_);
#endif

#endif
/* 10.03.97 */
