// COPYRIGHT DASSAULT SYSTEMES 2011

#ifndef CATReadWriteXMLISO_H
#define CATReadWriteXMLISO_H

#include "CATVisInteropXMLMeshV6.h"
#include <sys/types.h>

// For HRESULT definition
#include "CATErrorDef.h"

#ifndef NULL
#define NULL 0
#endif

class CATRep;
class CATVizXMLISOStreamOptions;
class CATUnicodeString;
class CATILockBytes2;

/** @nodoc */
ExportedByCATVisInteropXMLMeshV6 HRESULT CATWriteXMLISO(CATRep & iRep, CATILockBytes2 * oLockBytes2, CATVizXMLISOStreamOptions * iStreamOptions);

/** @nodoc */
ExportedByCATVisInteropXMLMeshV6 HRESULT CATWriteXMLISO(CATRep & iRep, const CATUnicodeString & oFile, CATVizXMLISOStreamOptions * iStreamOptions);

/** @nodoc */
ExportedByCATVisInteropXMLMeshV6 HRESULT CATReadXMLISO(CATILockBytes2 * iLockBytes2, CATVizXMLISOStreamOptions * iStreamOptions, CATRep * & oRep);

/** @nodoc */
ExportedByCATVisInteropXMLMeshV6 HRESULT CATReadXMLISO(const void * iBuffer, size_t iBufferLength, CATVizXMLISOStreamOptions * iStreamOptions, CATRep * & oRep);

/** @nodoc */
ExportedByCATVisInteropXMLMeshV6 HRESULT CATReadXMLISO(const CATUnicodeString & iFile, CATVizXMLISOStreamOptions * iStreamOptions, CATRep * & oRep);


#endif
