// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarsBarSupportLayerBarsObserver.h
// Header definition of CATPolyBarsBarSupportLayerBarsObserver
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2008 Creation: ndo
//===================================================================
#ifndef CATPolyBarsBarSupportLayerBarsObserver_H
#define CATPolyBarsBarSupportLayerBarsObserver_H

#include "PolyVizLayers.h"
#include "CATPolyBarsObserver.h"
#include "CATErrorDef.h"  // For the definition of HRESULT.
#include "CATBoolean.h"

class CATPolyBars;
class CATPolyBarsBarSupportLayer;


/*
Observer that updates the CATPolyBarsBarVizLayer during events that modify a CATPolyBars object.
*/
class ExportedByPolyVizLayers CATPolyBarsBarSupportLayerBarsObserver : public CATPolyBarsObserver
{

public:

  CATPolyBarsBarSupportLayerBarsObserver (const CATPolyBars& iObservedBars, CATPolyBarsBarSupportLayer& iBarSupportLayer);

  virtual ~CATPolyBarsBarSupportLayerBarsObserver () {}

public:

  // Bars events.
  HRESULT ReactToAddBar (const int vertex0, const int vertex1, const int bar);
  HRESULT PrepareToRemoveBar (const int bar);

public:

  // Call made before two vertices are merged.
  HRESULT PrepareToMergeVertices (const int v0, const int v1);

public:

  inline HRESULT Suspend ();

  inline HRESULT Resume ();

private:

  // Operand.

  const CATPolyBars& _ObservedBars;
  CATPolyBarsBarSupportLayer& _BarSupportLayer;

  CATBoolean _Suspended;

};

inline HRESULT CATPolyBarsBarSupportLayerBarsObserver::Suspend ()
{
  _Suspended = TRUE;
  return S_OK;
}

inline HRESULT CATPolyBarsBarSupportLayerBarsObserver::Resume ()
{
  _Suspended = FALSE;
  return S_OK;
}

#endif
