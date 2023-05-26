#ifndef CATVariant_Unbox_H
#define CATVariant_Unbox_H

#include "JS0LIB.h"
#include "CATVariant.h"
#include "CATSafeArray.h"
#include "CAT_VARIANT_BOOL.h"

#ifndef DEFINE_CATVARIANTBOOL_AS_CLASS
HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, CAT_VARIANT_BOOL *& oUnboxed);
#else

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, CAT_VARIANT_BOOL *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, short *& oUnboxed);

#endif
HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, CATLONG *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, float *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, double *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, char *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, short *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, unsigned short *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, ULONG *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, CATVariant **& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, CATVariant *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, BSTR *& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, BSTR **& oUnboxed);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, IUnknown **& oPointer, const char * iInterfaceTypeName);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, IUnknown **& oPointer);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, CATSafeArrayVariant *& oPointer);

HRESULT ExportedByJS0LIB Unbox(CATVariant * iVariant, CATSafeArrayVariant **& oPointer);

#endif
