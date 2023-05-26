/* -*-C++-*-*/
#ifndef CATHLRComputeKey_H
#define CATHLRComputeKey_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRComputeKeyCGM 
//
// DESCRIPTION :
/**
 * Compute a key for CGM objects that is unique.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
// Jan. 2004 TPD passage en 64 bits
//
//=============================================================================

#include "CATHLRModeldentificator.h"

class CATGeometry;

// Computes a key from an object
inline unsigned int CATHLRComputeKey(const CATHLRModeldentificator & iIdentificator);
inline CATUINTPTR CATHLRComputeKey(void * iGeometry);

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline unsigned int CATHLRComputeKey(const CATHLRModeldentificator & Identificator)
{
  unsigned int Result = Identificator.GetKey();
  return Result;
}

inline CATUINTPTR CATHLRComputeKey(void * PointerGeometry)
{
  union { void * Object; CATUINTPTR Value;} Converter;
  Converter.Object = PointerGeometry;

#if defined (_WINDOWS_SOURCE) || defined (PLATEFORME_DS64)
  CATUINTPTR Result = Converter.Value / 8;
#else
  CATUINTPTR Result = Converter.Value / 4;
#endif
  return Result;
}
	  
#endif
