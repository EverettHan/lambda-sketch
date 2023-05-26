// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATReadWriteXML_H
#define CATReadWriteXML_H

#include "CATVisInteropXMLMesh.h"
#include <sys/types.h>

// For HRESULT definition
#include "CATErrorDef.h"

#ifndef NULL
#define NULL 0
#endif

class CATRep;
class CATVizXMLStreamOptions;
class CATUnicodeString;
class CATILockBytes2;

/** @nodoc */
ExportedByCATVisInteropXMLMesh HRESULT CATWriteXML(CATRep & iRep, CATILockBytes2 * oLockBytes2, CATVizXMLStreamOptions & iStreamOptions);

/** @nodoc */
ExportedByCATVisInteropXMLMesh HRESULT CATWriteXML(CATRep & iRep, const CATUnicodeString & oFile, CATVizXMLStreamOptions & iStreamOptions);

/** @nodoc */
ExportedByCATVisInteropXMLMesh HRESULT CATReadXML(CATILockBytes2 * iLockBytes2, CATVizXMLStreamOptions & iStreamOptions, CATRep * & oRep);

/** @nodoc */
ExportedByCATVisInteropXMLMesh HRESULT CATReadXML(const void * iBuffer, size_t iBufferLength, CATVizXMLStreamOptions & iStreamOptions, CATRep * & oRep);

/** @nodoc */
ExportedByCATVisInteropXMLMesh HRESULT CATReadXML(const CATUnicodeString & iFile, CATVizXMLStreamOptions & iStreamOptions, CATRep * & oRep);


#endif
