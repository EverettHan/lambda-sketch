#ifndef _catgmpolysaveasncgm_h
#define _catgmpolysaveasncgm_h

#include "GMPolyTopTools.h"   // ExportedBy
#include "CATBoolean.h"

class CATBody;
class CATGeometry;
class CATUnicodeString;
class CATTopology;

class CATPolyBody;
class CATListPtrCATICGMObject;

ExportedByGMPolyTopTools void CATGMPolySaveAsNCGM(CATBody & iBody, CATUnicodeString & iStr, int iCounter, CATTopology * iTopo = 0, CATBoolean iBypassVar = FALSE); // NULL ko on Linux
ExportedByGMPolyTopTools void CATGMPolySaveAsNCGM(CATListPtrCATICGMObject & iLCGMObjects, CATUnicodeString & iStr, int iCounter, CATTopology * iTopo = 0, CATBoolean iBypassVar = FALSE); // NULL ko on Linux
ExportedByGMPolyTopTools void CATGMPolySaveAsPOLY(CATPolyBody & iBody, CATUnicodeString & iKeyword, int iCounter, CATBoolean iBypassVar = FALSE);

#endif
