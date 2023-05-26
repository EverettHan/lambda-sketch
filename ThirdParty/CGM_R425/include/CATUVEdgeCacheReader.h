#ifndef CATUVEdgeCacheReader_H
#define CATUVEdgeCacheReader_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVAbstractTopo.h"

class CATCGMUVParam;
class CATSoftwareConfiguration;

class ExportedByTessellateCommon CATUVEdgeCacheReader
{
public:
  virtual ~CATUVEdgeCacheReader();
  virtual HRESULT SetEdgeHandle(
                        CATUVEdgeHandle iEdgeHandle, 
                        const CATCGMUVParam& iParam, 
                        CATSoftwareConfiguration& iConfig) = 0;
  virtual HRESULT SetEdgeHandle(
                        CATUVEdgeHandle iEdgeHandle, 
                        const CATTessellateParamCache& iParam, 
                        CATSoftwareConfiguration& iConfig) = 0;

public:

  virtual CATULONG32 GetNbVertices() const = 0; 

  virtual CATBoolean AreCoordsAvailable() const = 0;

  virtual CATBoolean AreTangentsAvailable() const = 0;

  virtual HRESULT GetCrvParamSubdivision(const unsigned char*& oSubdivBuffer, CATULONG32& oSubdivBufferSize) const = 0;

  virtual HRESULT GetGeometry(CATBoolean iGetPositions, CATULONG32& oNbPositions, const double*& oPositions,
                              CATBoolean iGetTangents, CATULONG32& oNbTangents, const double*& oTangents,
                              CATBoolean iGetWs, CATULONG32& oNbWs, const double*& oWs,
                              CATBoolean& oReleaseAlloc)const = 0;

  static CATUVEdgeCacheReader* Create(CATCGMUVAbstractTopo& iAbstractTopo);
};

#endif 

