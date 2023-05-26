// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyTetrisContour.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Nov 2008  Creation: ZFI
//===================================================================


#ifndef CATPolyTetrisContour_H
#define CATPolyTetrisContour_H

#include "CATPolyVisuTetrisAtlas.h"
#include "CATErrorDef.h"


class CATPolyTetrisContour
{
public:
  CATPolyTetrisContour(double* iEdgesVertices, int iNbEdges);
  ~CATPolyTetrisContour();

public:
  //get/set
   HRESULT GetBottomLeftCorner(double& oMinX, double& oMinY);
   HRESULT GetDimensions(double& oWidth, double& oHeight);
   HRESULT GetNbEdges(int& oNbEdges);
   HRESULT GetEdge(const int iEdge, double& oX1, double& oY1, double& oX2, double& oY2 );

   //translate the contour
   HRESULT Translate(const double iX, const double iY);

   //rotate the contour
   HRESULT Rotate(const double iAngle);

private:
  double _MinX, _MinY, _MaxX, _MaxY;
  double _Width, _Height;
  double* _Vertices;
  int _NbVertices;
};

#endif
