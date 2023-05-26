#ifndef CATCGMUVFaceMeshCrvIterBuffersItf_H
#define CATCGMUVFaceMeshCrvIterBuffersItf_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListOfULONG32.h"

class CATFace;
class CATEdge;
class CATVertex;

class CATCGMUVParamSubdivision1D;

class ExportedByTessellateCommon CATCGMUVFaceMeshCurveBuffersItf
{
public:
  virtual ~CATCGMUVFaceMeshCurveBuffersItf();

public:

  virtual CATULONG32 GetNbVerticesInEdge() const = 0;

  virtual CATULONG32 GetNbDeltaVerticesInEdge() const;

  // iEVIdx should be between 0 and (GetNbVerticesInEdge(iEdge) - 1)
  // The sequence should be aligned along the CATEdge direction
  // (supported only in classic V5 cache)
  virtual HRESULT GetCurveParamAtEdgeVertex(CATULONG32 iEVIdx, double& oW) const = 0;

  // Get edge curve params in the form of compressed subdivision 
  virtual HRESULT GetCrvParamSubdivisionForEdge(const unsigned char*& oSubdivBuffer, CATULONG32& oSubdivBufferSize) const = 0;

  virtual HRESULT Get(CATULONG32& oNbIndices, const CATULONG32*& oIndices, 
                      CATBoolean iGetTangents, CATULONG32& oNbTangents, const double*& oTangents, 
                      CATBoolean iGetWs, CATULONG32& oNbWs, const double*& oWs,
                      CATBoolean& oReleaseAlloc) const = 0;
};

#endif 
