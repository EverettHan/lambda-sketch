#ifndef CATSysGetLocalDecimalChar_H
#define CATSysGetLocalDecimalChar_H

#include "NS0S3STR.h"
#include "CATUnicodeString.h"

// COPYRIGHT DASSAULT SYSTEMES 2005

//-------------------------------------------------------------------
/** 
 * This method gives the character used in the current  local process
 * as decimal point character in the default string representation of
 * floating points value.
 * For example, in default english environment it will be a '.'. 
 * when in a localized french environment this character would  be a ','
 *
 * Upon  successful call, oLocalDC is set to the wanted value when returning
 * from this call
 *
 */
ExportedByNS0S3STR HRESULT CATSysGetLocalDecimalChar(CATUnicodeString &oLocalDC);

#endif

