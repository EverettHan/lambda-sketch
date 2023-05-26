//===================================================================
// CATIGeomCache.h
//===================================================================

#ifndef CATIGeomCache_H
#define CATIGeomCache_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"

class CATRep;
class CATCgrHeader;
class CATGeoFactory;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIGeomCache;
#else
extern "C" const IID IID_CATIGeomCache;
#endif

class ExportedByCATVisItf CATIGeomCache: public CATBaseUnknown
{
CATDeclareInterface;
public:
	virtual HRESULT LoadCacheFromCGR(CATRep* iCgrRep, CATGeoFactory* iFactory, CATCgrHeader* header) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIGeomCache, CATBaseUnknown );

#endif
