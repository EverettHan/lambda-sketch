// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySurfaceFacetSupportLayerMeshObserver.h
// Header definition of CATPolySurfaceFacetSupportLayerMeshObserver
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2008 Creation: ndo
//===================================================================
#ifndef CATPolySurfaceFacetSupportLayerMeshObserver_H
#define CATPolySurfaceFacetSupportLayerMeshObserver_H

#include "PolyVizLayers.h"
#include "CATIPolyMeshObserver.h"
#include "CATErrorDef.h"  // For the definition of HRESULT.
#include "CATBoolean.h"

class CATIPolyMesh;
class CATPolySurfaceFacetSupportLayer;


/*
Observer that updates the CATPolyBarsBarVizLayer during events that modify a CATPolyBars object.
*/
class ExportedByPolyVizLayers CATPolySurfaceFacetSupportLayerMeshObserver : public CATIPolyMeshObserver
{

public:

  CATPolySurfaceFacetSupportLayerMeshObserver (const CATIPolyMesh& iObservedMesh, CATPolySurfaceFacetSupportLayer& iFacetSupportLayer);

  virtual ~CATPolySurfaceFacetSupportLayerMeshObserver () {}

public:

  // Triangle events.
  HRESULT ReactToAddTriangle (int v0, int v1, int v2, int t);
  HRESULT PrepareToRemoveTriangle (int t);

public:

  HRESULT ReactToSplitTriangle (int t, int t0, int t1);

public:

  // Call made before two vertices are merged.
  HRESULT PrepareToMergeVertices (int v0, int v1);

public:

  inline HRESULT Suspend ();

  inline HRESULT Resume ();

private:

  // Operand.

  const CATIPolyMesh& _ObservedMesh;
  CATPolySurfaceFacetSupportLayer& _FacetSupportLayer;

  CATBoolean _Suspended;

};

inline HRESULT CATPolySurfaceFacetSupportLayerMeshObserver::Suspend ()
{
  _Suspended = TRUE;
  return S_OK;
}

inline HRESULT CATPolySurfaceFacetSupportLayerMeshObserver::Resume ()
{
  _Suspended = FALSE;
  return S_OK;
}

#endif
