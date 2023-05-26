#ifndef CATCGMUVFaceMeshCurveBuffersItf2_H
#define CATCGMUVFaceMeshCurveBuffersItf2_H

#include "ExportedByTessellateCommon.h"
#include "CATCGMUVFaceMeshCurveBuffersItf.h"

class ExportedByTessellateCommon CATCGMUVFaceMeshCurveBuffersItf2
  : public CATCGMUVFaceMeshCurveBuffersItf
{
public:
  virtual ~CATCGMUVFaceMeshCurveBuffersItf2();
};

//class ExportedByTessellateCommon CATCGMUVFaceMeshCurveBuffersItf2
//{
//public:
//  virtual ~CATCGMUVFaceMeshCurveBuffersItf2();
//
//public:
//
//  virtual CATULONG32 GetNbVerticesInEdge() const = 0;
//
//  // iEVIdx should be between 0 and (GetNbVerticesInEdge(iEdge) - 1)
//  // The sequence should be aligned along the CATEdge direction
//  // (supported only in classic V5 cache)
//  virtual HRESULT GetCurveParamAtEdgeVertex(CATULONG32 iEVIdx, double& oW) const = 0;
//
//  // Get edge curve params in the form of compressed subdivision 
//  virtual HRESULT GetCrvParamSubdivisionForEdge(const unsigned char*& oSubdivBuffer, CATULONG32& oSubdivBufferSize) const = 0;
//
//  virtual HRESULT Get(CATULONG32& oNbIndices, const CATULONG32*& oIndices, 
//                      CATBoolean iGetTangents, CATULONG32& oNbTangents, const double*& oTangents, 
//                      CATBoolean iGetWs, CATULONG32& oNbWs, const double*& oWs,
//                      CATBoolean& oReleaseAlloc) const = 0;
//};

#endif 
