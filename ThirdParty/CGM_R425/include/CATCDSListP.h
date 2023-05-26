// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
//
// CATCDSListP:
//   Macro for declaring dynamic array of pointers class.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Dec 2004  Creation                                   S. Lipskiint
//=============================================================================

#ifndef CATCDSListP_h
#define CATCDSListP_h

#include "CATCDSArray.h"

#define NotExported

#define CATCDSLISTP_DECLARE_EXPORTED_NAMED(ClassName, T, Export) class ClassName : public CATCDSArray<T*> {public: ClassName(int iSize = 0) : CATCDSArray<T*>(0) {Reserve(iSize);} };
#define CATCDS_DECLARE_LIST_OF(T) CATCDSLISTP_DECLARE_EXPORTED_NAMED(T##List, T, NotExported)
#define CATCDSLISTP_DECLARE(T) CATCDSLISTP_DECLARE_EXPORTED_NAMED(CATCDSListP##T, T, NotExported)
#define CATCDSLISTP_DECLARE_EXPORTED(T, Export) CATCDSLISTP_DECLARE_EXPORTED_NAMED(CATCDSListP##T, T, Export)

#define CATCDSLISTP(T) CATCDSListP##T
#define CATCDSLISTP_NAMESPACE(N, T) N::CATCDSListP##T
#define CATCDSLISTP_FORWARD(T) class CATCDSListP##T;

typedef CATCDSArray<void*> CATCDSListPV;

#endif
