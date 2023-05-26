#ifndef CATGETBufferFromTXTFile_H
#define CATGETBufferFromTXTFile_H

// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// Function  :     CATGETBufferFromTXTFile 
// Author    :     B. Granier
// Date      :     October 97
// Resp      :     E. Houdet
//------------------------------------------------------------------------------
// Abstract  : Get a buffer from a text file   
//                            
//------------------------------------------------------------------------------

#include "CATScriptEngine.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;

ExportedByCATScriptEngine HRESULT __stdcall CATGetBufferFromTXTFile(const CATUnicodeString & ifileName,
                                                                    CATUnicodeString       & oScriptBuffer);

#endif // CATGETBufferFromTXTFile_H
