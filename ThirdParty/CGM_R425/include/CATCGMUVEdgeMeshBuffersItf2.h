#ifndef CATCGMUVEdgeMeshBuffersItf2_H
#define CATCGMUVEdgeMeshBuffersItf2_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATEdge;
class CATCGMUVParamSubdivision1D;
class CATMathBox;

class ExportedByTessellateCommon CATCGMUVEdgeMeshBuffersItf2
{
public:
  virtual ~CATCGMUVEdgeMeshBuffersItf2();

public:
  virtual HRESULT BeginTransaction() const = 0;
  virtual HRESULT EndTransaction() const = 0;

public:

  virtual CATULONG32 GetNbVertices() const = 0; 

  virtual CATBoolean AreCoordsAvailable() const = 0;

  virtual CATBoolean AreTangentsAvailable() const = 0;

  virtual HRESULT GetCrvParamSubdivision(const unsigned char*& oSubdivBuffer, CATULONG32& oSubdivBufferSize) const = 0;

  virtual HRESULT GetGeometry(CATBoolean iGetPositions, CATULONG32& oNbPositions, const double*& oPositions,
                              CATBoolean iGetTangents, CATULONG32& oNbTangents, const double*& oTangents,
                              CATBoolean iGetWs, CATULONG32& oNbWs, const double*& oWs,
                              CATBoolean& oReleaseAlloc)const = 0;

};

#endif 

