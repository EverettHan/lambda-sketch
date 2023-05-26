//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2000                                          *
//*===========================================================================*
//*                                                                           *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation juin 2000                                                       *
//*===========================================================================*
#ifndef CATENVVAR_H
#define CATENVVAR_H
#include "IUnknown.h"
#include "JS0LIB.h"

class CATUnicodeString;
class CATString;

#ifdef __cplusplus
extern "C" {
#endif

/** @nodoc */
ExportedByJS0LIB HRESULT  CATExpandString ( CATUnicodeString *ioString);
ExportedByJS0LIB HRESULT  CATExpandStr ( CATString *ioString);
#ifdef __cplusplus
}
#endif


#endif
