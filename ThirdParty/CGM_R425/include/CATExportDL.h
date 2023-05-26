//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2004                                          *
//*===========================================================================*
//*                                                                           *
//*  Advanced Function for DLNames                                            *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation mars 2004                                      adt              *
//*===========================================================================*
#ifndef CATSYSDLEXP_H
#define CATSYSDLEXP_H
#include "JS0LIB.h"
class CATUnicodeString;

#ifdef __cplusplus
extern "C" {
#endif

/** @nodoc*/

ExportedByJS0LIB HRESULT CATSysImportDLNames (char mode, int nocheck,  
					      unsigned int fd, unsigned int Fr,
					      CATUnicodeString **DLNTab=0,
					      HRESULT **Hres=0, 
					      unsigned int *oNb=0) ;

/** @nodoc*/
ExportedByJS0LIB HRESULT CATSysExportDLNames ( unsigned int iFd,
					       unsigned int *NbDLname);


/** @nodoc*/
ExportedByJS0STDLIB HRESULT CATGetDLNameNumber (unsigned int *oNB);


#ifdef __cplusplus
}
#endif
#endif
