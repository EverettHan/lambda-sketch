#ifndef IVISSG3DEDGE_H
#define IVISSG3DEDGE_H

#include "IVisSG3DCurve.h"
#include "VisSceneGraph.h"

#include "VisDataType.h"

class IVisSG3DFace;

extern ExportedByVisSceneGraph IID IID_IVisSG3DEdge;

class ExportedByVisSceneGraph IVisSG3DEdge : public IVisSG3DCurve
{
public:
  virtual HRESULT GetNumberOfBoundedFaces(VisSize& nbBoundedFaces) = 0;
  virtual HRESULT GetBoundedFace(VisSize index, IVisSG3DFace * & boundedFace) = 0;

  /*
  virtual HRESULT GetNumberOfBoundingVertices(unsigned int & nbBoundingVertices);
  virtual HRESULT GetBoundingVertex(IVisSG3DVertex * & vertex);
  */
};

#endif
