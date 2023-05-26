// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
//
// CATCDSStringUtilities:
//   Auxiliary functions for strings.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jul 2008  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSStringUtilities_h
#define CATCDSStringUtilities_h

#include "CATCDSBoolean.h"

#include "CATCDSUtilities.h"

#include "CATCDSString.h"

ExportedByCATCDSUtilities CATCDSString FillString(const CATCDSString& iString, int iSize, char iFill = '0');
ExportedByCATCDSUtilities CATCDSBoolean HasPrefix(const CATCDSString& iString, const CATCDSString& iPrefix);

#endif
