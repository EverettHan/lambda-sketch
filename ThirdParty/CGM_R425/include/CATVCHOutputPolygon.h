//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// CATVCHOutputPolygon
//
//=============================================================================
// 2006-01-07   ALA: New
//=============================================================================
#ifndef CATVCHOutputPolygon_H
#define CATVCHOutputPolygon_H

#include "CATPolyConvexHullExport.h"


class ExportedByCATPolyConvexHull CATVCHOutputPolygon
{
public:

  virtual ~CATVCHOutputPolygon();

public:
  // add a point and return an index used by "AddTriangle".
  virtual int AddPoint( const float (&iCoord)[ 3 ], int iCC = -1 ) = 0;

  virtual void AddTriangle( const int (&iPoint)[3], int iCC = -1 ) = 0;
};

#endif // !CATVCHOutputPolygon_H
