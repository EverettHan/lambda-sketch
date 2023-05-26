// COPYRIGHT DASSAULT SYSTEMES 2004

#ifndef		CATOmbDocFileServices_h
#define		CATOmbDocFileServices_h

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"

#include "IUnknown.h"

class CATUnicodeString;
class CATUuid;


// Restricted usage : to be used only by ObjectModelerBase, FileMenu and Smarteam environment.
/** @nodoc */
ExportedByAC0XXLNK
HRESULT CATGetIdentifierFromPath( const CATUnicodeString& iPath, CATUuid& identifier);



#endif	
