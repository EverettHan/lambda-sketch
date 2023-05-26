// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshTriangleVizLayer.h
// Header definition of CATPolyMeshTriangleVizLayer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2007 Creation: ndo
//===================================================================
#ifndef CATPolyMeshTriangleSupportLayer_H
#define CATPolyMeshTriangleSupportLayer_H

#include "PolyVizLayers.h"
#include "CATPolySurfaceFacetSupportLayer.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATIPolyMesh;
class CATPolyVizContainer;


/*
Implementation class for triangle support attributes. 
This class defines a layer of surface support attributes that are associated to each triangle of a CATIPolyMesh object.
*/
class ExportedByPolyVizLayers CATPolyMeshTriangleVizLayer : public CATPolySurfaceFacetSupportLayer
{

public:

  CATPolyMeshTriangleVizLayer (const CATIPolyMesh& iMesh, CATPolyVizContainer& iSupports);

  virtual ~CATPolyMeshTriangleVizLayer ();

public:

  inline CATPolyVizContainer& GetSupportContainer () const;

private:

  CATPolyVizContainer& _SupportContainer;

};


inline CATPolyVizContainer& CATPolyMeshTriangleVizLayer::GetSupportContainer () const
{
  return _SupportContainer;
}


#endif
