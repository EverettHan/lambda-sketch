// COPYRIGHT DASSAULT SYSTEMES 2011

#ifndef CATReadWriteXMLISOFTAServices_H
#define CATReadWriteXMLISOFTAServices_H

#include "CATVisInteropXMLMeshV6.h"
#include <sys/types.h>

// For HRESULT definition
#include "CATErrorDef.h"

#ifndef NULL
#define NULL 0
#endif

class CATRep;
class CATUnicodeString;
class CATVizXMLISOStreamOptions;
class CATIXMLPPWriter;

/** @nodoc */
ExportedByCATVisInteropXMLMeshV6 HRESULT CATWriteXMLISOFTA(CATRep & iRep, CATIXMLPPWriter * iWriter, CATVizXMLISOStreamOptions * iStreamOptions);

/** @nodoc */
ExportedByCATVisInteropXMLMeshV6 HRESULT CATReadXMLISOFTA(const CATUnicodeString & iFile, CATVizXMLISOStreamOptions * iStreamOptions, CATRep * & oRep);

#endif
