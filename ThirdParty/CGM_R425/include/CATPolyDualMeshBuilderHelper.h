#ifndef CATPolyDualMeshBuilderHelper_H
#define CATPolyDualMeshBuilderHelper_H

#include <string>

class CATTessPoint;

class CATPolyDualMeshBuilderHelper
{
public:
  virtual ~CATPolyDualMeshBuilderHelper() {};

public:
  virtual void create(bool edgeMode, bool triMode, int nbPoints = 0, int nbTriangles = 0) = 0;
  virtual const int addPoint(int & ioIndex, const CATTessPoint * iPt, const double iVx, const double iVy, const double iVz) = 0;
  virtual const int addTriangle(const int iP0, const int iP1, const int iP2) = 0;
  virtual const int addEdgeValue(const double iValue, const int iP0, const int iP1) = 0;
  virtual const int addTriangleValue(const double iValue, const int iT) = 0;
  virtual int buildDualMesh(const CATBoolean iIsUniform) = 0;
};

#endif
