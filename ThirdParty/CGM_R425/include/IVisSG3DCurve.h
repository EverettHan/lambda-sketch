#ifndef IVISSG3DCURVE_H
#define IVISSG3DCURVE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DPrimitive.h"
#include "VisSceneGraph.h"

#include "VisDataType.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DCurve;

/** 
 * Basic class of any Scene Graph 3D Curve.
 * <b>Role</b>: This is the basic class that any Scene Graph 3D Curve has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG3DCurve : public IVisSG3DPrimitive
{  
public:

  /**
   * Returns the number of vertices in the curve.
   */
  //virtual HRESULT GetNumberOfVertices(VisSize& oNumberOfVertices) = 0;

  /**
   * Returns a vertex.
   */
  //virtual HRESULT GetVertex(const VisSize iVertexIndex, float oVertex[3]) = 0;
};

#endif // IVISSG3DCURVE_H
