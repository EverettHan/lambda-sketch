#ifndef CATCGMUVFaceMeshCurveBuffersIter_H
#define CATCGMUVFaceMeshCurveBuffersIter_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATEdge;

class ExportedByTessellateCommon CATCGMUVFaceMeshCurveBuffersIter
{
public:
  virtual void Release() = 0;

public:
  // sets iterator to beginning (first face mesh curve data)
  virtual void Begin() = 0;

  // sets iterator to the next face mesh curve data
  virtual CATCGMUVFaceMeshCurveBuffersIter& operator ++ () = 0;

  // returns TRUE if iterator has reached its end
  virtual CATBoolean IsEnd() = 0;

public:
  virtual CATEdge* GetEdge() const = 0;

  virtual HRESULT GetNbVertices(CATULONG32& oNbVerticesInEdge, CATULONG32& oNbDeltaVerticesInEdge) const = 0;

  virtual HRESULT Get(
              CATBoolean iGetIndices, CATULONG32& oNbIndices, const CATULONG32*& oIndices, 
              CATBoolean iGetSubdivBuffer, CATULONG32& oSubdivBufferSize, const unsigned char*& oSubdivBuffer,
              CATBoolean iGetDeltaPositions, CATULONG32& oNbDeltaPositions, const double*& oDeltaPositions,
              CATBoolean iGetDeltaTangents, CATULONG32& oNbDeltaTangents, const double*& oDeltaTangents,
              CATBoolean& oReleaseAlloc) const = 0;

  // for classic tessellation, when subdiv buffer is not available
  virtual HRESULT GetWs(
              CATULONG32& oNbWs, const double*& oWs,
              CATBoolean& oReleaseAlloc) const = 0;

protected:
  virtual ~CATCGMUVFaceMeshCurveBuffersIter();
};

#endif 

