#ifndef IVISSG3DFACE_H
#define IVISSG3DFACE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DMesh.h"
#include "VisSceneGraph.h"

//#include "VisDataType.h"

class CATMathPointf;
class CATMathVectorf;

extern ExportedByVisSceneGraph IID IID_IVisSG3DFace;

class IVisSG3DEdge;

class ExportedByVisSceneGraph IVisSG3DFace : public IVisSG3DMesh
{
public:

  //virtual HRESULT GetNumberOfBoundingEdges(VisSize& nbBoundingEdges) = 0;
  //virtual HRESULT GetBoundingEdge(VisSize index, IVisSG3DEdge * & boundingEdge) = 0;
};

#endif // IVISSG3DFACE_H
