/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================

#ifndef CATOmyCioUtils_H
#define CATOmyCioUtils_H

#include "CATVVSUrl.h"
#include "CATSysTSURI.h"
#include "CATOMYCuteIO.h"
#include "CATUuid.h"
#include "CATOmyResourceReference.h"

/**
* Class of service to translate URL to URI.
*/

class ExportedByCATOMYCuteIO CATOmyCioUtils
{
public:	

	// give a pointer as oStreamId, we do the allocation, please, don't forget to free memory after use!
	static HRESULT CreateURLPatternAndStreamId(const CATOmyResourceReference & iSrc, CATVVSUrl& oUrlPattern, CATOmyStreamId* oStreamId);

  static HRESULT CreateStreamId(const CATVVSUrl& iURLSrc, const CATUnicodeString& iLateType, unsigned int iWS, CATOmyStreamId* oStreamId);

  static void Uint2Uuid(const CATUINT32& iId, CATUuid& oUuid);
  static HRESULT Uuid2Uint(const CATUuid& iUuid, CATUINT32& oId);

private :
  static HRESULT _TreatViscaUrl(CATUnicodeString& ioIdentifier);
	static CATUnicodeString _ScrambleUrl (const CATUnicodeString& iString);
	static CATUnicodeString _UnScrambleUrl (const CATUnicodeString& iString);
};

#endif
