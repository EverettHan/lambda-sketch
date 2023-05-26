#ifndef CATGetStringNameFromIID_H
#define CATGetStringNameFromIID_H

// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// Function  :     CATGetStringFromIID 
// Author    :     B. Granier
// Date      :     October 97
//------------------------------------------------------------------------------
// Abstract  : Get a CATUnicodeString from an IID   
//                            
//------------------------------------------------------------------------------

#include "JS0DSPA.h"
#include "IUnknown.h"

class CATUnicodeString;

ExportedByJS0DSPA HRESULT __stdcall  CATGetStringFromIID ( const IID &riid, CATUnicodeString &oInterfaceName);

#endif // CATGetStringNameFromIID_H
