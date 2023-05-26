// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMV5Settings.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMV5Settings_H
#define CATCGMV5Settings_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATCGMUVCommonSettings.h"
#include "CATTessSettings.h"
#include "CATTessellateParamCache.h"


class CATSoftwareConfiguration;
class CATGeoFactory;

class ExportedByTessellateCommon CATCGMV5Settings:public  CATCGMUVCommonSettings
{
public:
  CATCGMV5Settings(const CATTessellateParam& iTessParam,
                   CATGeoFactory* iGeoFactory);

  virtual ~CATCGMV5Settings();

public:
  CATGeoFactory* GetGeoFactory(){return _GeoFactory ;}
  CATTessSettings& GetTessSettings(){return _TessSettings;}
	HRESULT GetTessellateParamCache(CATTessellateParamCache& oParam);

private:
  CATTessSettings _TessSettings;
  CATGeoFactory* _GeoFactory;
	CATTessellateParamCache _TessellateParamCache;
};

#endif
