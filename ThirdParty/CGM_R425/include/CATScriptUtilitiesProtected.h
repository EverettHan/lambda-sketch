#ifndef CATScriptUtilitiesProtected_h
#define CATScriptUtilitiesProtected_h

// COPYRIGHT DASSAULT SYSTEMES 2014
#include "AutomationItf.h"

class CATUnicodeString;

#define CAT_DISPLAY_NAME_DELIMITER1 "   (=> "

#ifdef __cplusplus
extern "C" {
#endif
    /**
     * Returns the expanded real path of the given path.
     * This function uses both CATExpandString and CATGetRealPath to
     * retrieve the full real path.
     */
    ExportedByCATAutoItf HRESULT DSYSysGetExpandedRealPath(const CATUnicodeString& iPath, CATUnicodeString& oRealPath);
#ifdef __cplusplus
}
#endif

#endif // CATScriptUtilitiesProtected_h

