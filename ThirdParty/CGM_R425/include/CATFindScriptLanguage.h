#ifndef CATFindScriptLanguage_H
#define CATFindScriptLanguage_H

// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// Function  :     CATFindScriptLanguage 
// Author    :     B. Granier
// Date      :     October 97
// Resp      :     E. Houdet
//------------------------------------------------------------------------------
// Abstract :  Find the script language
//                            
//------------------------------------------------------------------------------

#include "CATScriptEngine.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;

ExportedByCATScriptEngine HRESULT __stdcall CATFindScriptLanguage(CATUnicodeString  & iScriptBuffer,
							          CATUnicodeString  ** oScriptLang);

#endif // CATFindScriptLanguage_H
