// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBarAttributeLayerObserver.h
//
//===================================================================
// November 2009 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonBarAttributeLayerObserver_H
#define CATPolyPolygonBarAttributeLayerObserver_H

#include "PolygonalLayers.h"
#include "CATPolyPolygonObserver2D.h"
#include "CATErrorDef.h"

class CATPolyPolygon2D;
class CATPolyPolygonBarAttributeLayer;
class CATPolyVertex2D;
class CATPolyBar2D;


class ExportedByPolygonalLayers CATPolyPolygonBarAttributeLayerObserver : public CATPolyPolygonObserver2D
{

public :

  CATPolyPolygonBarAttributeLayerObserver (CATPolyPolygonBarAttributeLayer& iBarAttributeLayer,
                                           const CATPolyPolygon2D& polygon);

  ~CATPolyPolygonBarAttributeLayerObserver () {}

public:

  // Call made after a bar is added.
  virtual HRESULT ReactToAddBar (const CATPolyBar2D* bar);

  // Call made before a bar is removed.
  virtual HRESULT PrepareToRemoveBar (const CATPolyBar2D* iBar);

public:

  // Call made after a bar is split.
  virtual HRESULT ReactToSplitBar (const CATPolyBar2D* iSplitBar, const CATPolyVertex2D* iVertex, 
                                   const CATPolyBar2D* iNewBar); 

  // Call made before two bars are merged.
  virtual HRESULT PrepareToMergeBars (const CATPolyBar2D* iMergeBar, const CATPolyBar2D* iDuplicateBar);

private:

  CATPolyPolygonBarAttributeLayer& _BarAttributeLayer;
  const CATPolyPolygon2D& _Polygon;

};

#endif
