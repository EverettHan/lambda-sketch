#ifndef CATReadWriteUVR_H
#define CATReadWriteUVR_H

#include "SGInfra.h"

// For HRESULT definition
#include "IUnknown.h"
#include <sys/types.h>
class CATVizUVRStreamOptions;
class CATRep;
class CATUnicodeString;
class CATILockBytes2;

// Write UVR functions

/** @nodoc */
ExportedBySGInfra HRESULT CATWriteUVR(CATRep & iRep, CATILockBytes2 * oILockBytes2, CATVizUVRStreamOptions & iStreamOptions);

/** @nodoc */
ExportedBySGInfra HRESULT CATWriteUVR(CATRep & iRep, char * & oBuffer, size_t & oBufferLength, CATVizUVRStreamOptions & iStreamOptions);

/** @nodoc */
ExportedBySGInfra HRESULT CATWriteUVR(CATRep & iRep, const CATUnicodeString & oFile, CATVizUVRStreamOptions & iStreamOptions);

// Read UVR functions

/** @nodoc */
ExportedBySGInfra HRESULT CATReadUVR(CATILockBytes2 * iILockBytes2, CATVizUVRStreamOptions & ioStreamOptions, CATRep * & oRep);

/** @nodoc */
ExportedBySGInfra HRESULT CATReadUVR(const char * iBuffer, size_t iBufferLength, CATVizUVRStreamOptions & ioStreamOptions, CATRep * & oRep);

/** @nodoc */
ExportedBySGInfra HRESULT CATReadUVR(const CATUnicodeString & iFile, CATVizUVRStreamOptions & ioStreamOptions, CATRep * & oRep);

/** @nodoc */
ExportedBySGInfra HRESULT CATReadUVR(unsigned int nbItems, CATILockBytes2 ** iILockBytes2, CATVizUVRStreamOptions & ioStreamOptions, CATRep ** oReps);


/** @nodoc
 *  @deprecated
 *  Wrapper compatibility function for PLM3DSearchServices. Will disappear as soon as the call is migrated
 */
ExportedBySGInfra HRESULT CATReadUVR(CATILockBytes2 * iILockBytes2, CATRep * & oRep);

/** @nodoc
 *  @deprecated
 *  Wrapper compatibility function for ENOVWebNavigator. Will disappear as soon as the call is migrated
 */
ExportedBySGInfra HRESULT CATReadUVR(const char * iBuffer, size_t iBufferLength, CATRep * & oRep);

/** @nodoc
 *  @deprecated
 *  Wrapper compatibility function for ENOVWebNavigator. Will disappear as soon as the call is migrated
 */
ExportedBySGInfra HRESULT CATReadUVR(const CATUnicodeString & iFile, CATRep * & oRep);

#endif
