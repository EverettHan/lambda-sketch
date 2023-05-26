//======================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//======================================================================
//
// CATPolyFixThinTrianglesOperator.h
//
//======================================================================
//
// Usage notes: !!! NE PAS UTILISER !!!
//              Création à partir de CATPolyFixSmallAngleTrianglesOper,
//              à supprimer pour éviter la duplication.
//
//======================================================================
// October,   2009 : RAQ : Creation
//======================================================================
#ifndef CATPolyFixThinTrianglesOperator_H
#define CATPolyFixThinTrianglesOperator_H

#include "CATPolyTrimOperators.h"
#include "CATPolyModOper.h"
#include "CATPolyBitSet.h"

#include "CATListOfInt.h"
#include "CATBooleanDef.h"

class CATIPolyMesh;
class CATPolyBarCollapseOper;
class CATMathPoint;

class ExportedByCATPolyTrimOperators CATPolyFixThinTrianglesOperator: public CATPolyModOper
{
public:

  CATPolyFixThinTrianglesOperator();
  ~CATPolyFixThinTrianglesOperator(void);

  void SetTolerance(const double tolerance);

  HRESULT Run(void);

  HRESULT RunOnSelectedTriangles(const CATListOfInt& triangles);

  HRESULT RunOnSelectedTriangles(const CATListOfInt& triangles, CATListOfInt& decimatedTriangles);

  void GetSmallAngleTriangles(CATListOfInt& triangles);

private:

  void ConstructCollapser();

  HRESULT InternalRun(const CATListOfInt& triangles, CATListOfInt& decimatedTriangles);

  void ClassifyTriangles(const CATListOfInt& triangles, CATListOfInt& trianglesToFlip, CATListOfInt& trianglesToBarCollapse) const;

  CATBoolean HasSmallAngle(const int triangle) const;

  void GetSmallAngleTriangles(const CATListOfInt& triangles, CATListOfInt& smallAngleTriangles);

  void CollapseBars(const CATListOfInt& trianglesToCollapse, CATListOfInt& decimatedTriangles);

  CATBoolean CollapseBar(CATListOfInt& ioTrianglesToCollapse, const int triangle, CATListOfInt& decimatedTriangles);
  CATBoolean CollapseBar(const int iVertexToKeep, const int iVertexToRemove, const CATMathPoint& iVertexToKeepCoords);

  void FlipBars(const CATListOfInt& trianglesToFlip);

  CATBoolean OkToFlip(const CATListOfInt& smallAngleTriangles, const int triangle, int& vertexIndex,
                      double& maxAngle, int* ioNeighbourTriangle = 0) const;

  CATBoolean FlipBar(const int triangle, const int vertexIndex);
  CATBoolean FlipBar(const int iVertex1, const int iVertex2, int& oNewTriangle1, int& oNewTriangle2);

  
  //--------- Data:
  double _angleTolerance;
  int _numTriangles;
  
  CATPolyBarCollapseOper* _BarCollapser;
  CATPolyBitSet _TriangleProcessedFlags;
};

#endif

