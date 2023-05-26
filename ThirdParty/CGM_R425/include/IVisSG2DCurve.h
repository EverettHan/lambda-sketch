#ifndef IVISSG2DCURVE_H
#define IVISSG2DCURVE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG2DPrimitive.h"
#include "VisSceneGraph.h"

#include "VisDataType.h"

extern ExportedByVisSceneGraph IID IID_IVisSG2DCurve;

/** 
 * Basic class of any Scene Graph 2D Curve.
 * <b>Role</b>: This is the basic class that any Scene Graph 2D Curve has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG2DCurve : public IVisSG2DPrimitive
{  
public:

  /**
   * Returns the number of vertices in the curve.
   */
  virtual HRESULT GetNumberOfVertices(VisSize& oNumberOfVertices) = 0;

  /**
   * Returns a vertex.
   */
  virtual HRESULT GetVertex(const VisSize iVertexIndex, float oVertex[2]) = 0;
};

#endif // IVISSG2DCURVE_H
