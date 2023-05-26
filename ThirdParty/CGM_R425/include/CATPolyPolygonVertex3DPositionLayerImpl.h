// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonVertex3DPositionLayerImpl.h
//
//===================================================================
// June 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonVertex3DPositionLayerImpl_H
#define CATPolyPolygonVertex3DPositionLayerImpl_H

#include "PolygonalLayers.h"
#include "CATPolyPolygonVertex3DPositionLayer.h"
#include "CATPolyBuckets_T.h"
#include "CATErrorDef.h"
#include "CATMapOfPtrToInt.h"

class CATPolyPolygon2D;
class CATPolyVertex2D;


class ExportedByPolygonalLayers CATPolyPolygonVertex3DPositionLayerImpl : 
  public CATPolyPolygonVertex3DPositionLayer
{

public :

  CATPolyPolygonVertex3DPositionLayerImpl ();
  CATPolyPolygonVertex3DPositionLayerImpl (const CATPolyPolygon2D& polygon);
  ~CATPolyPolygonVertex3DPositionLayerImpl () {}

public:

  HRESULT Set (const CATPolyVertex2D* vertex, const double x, const double y, const double z);
  HRESULT Get (const CATPolyVertex2D* vertex, double& x, double& y, double& z) const;

private:

  // Buckets of doubles.
  class Specialize_CATPolyBuckets_T (DoubleBuckets, double);

private:
  DoubleBuckets _Data;
  CATMapOfPtrToInt m_map;
  int m_cur;
};

#endif
