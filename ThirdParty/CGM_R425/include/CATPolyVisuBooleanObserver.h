// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuBooleanObserver.h
// Header definition of CATPolyVisuBooleanObserver
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2007 Creation: ndo
//===================================================================
#ifndef CATPolyVisuBooleanEventsObserver_H
#define CATPolyVisuBooleanEventsObserver_H

#include "PolyVisuBoolOper.h"
#include "CATPolyBooleanObserver.h"
#include "CATErrorDef.h"  // For the definition of HRESULT.
#include "CATBoolean.h"

class CATIPolyMesh;
class CATPolyMeshVertexNNormalsLayer;
class CATPolySurfaceFacetSupportLayer;
class CATPolyVisuRefinementMeshObserver;
class CATPolyBars;
class CATPolyBarsBarSupportLayer;
class CATPolyBarsBarSupportLayerBarsObserver;
class CATPolyVisuRefinementBarsObserver;

class CATPolyVizJournalLayer;


/*
Class watching the boolean events which edit the operands.
See CATPolyBooleanObserver.
*/
class ExportedByPolyVisuBoolOper CATPolyVisuBooleanObserver : public CATPolyBooleanObserver
{

public:

  CATPolyVisuBooleanObserver (CATIPolyMesh& iOperand0, 
                              CATPolyMeshVertexNNormalsLayer* iNormalLayer0,
                              CATPolySurfaceFacetSupportLayer* iTriangleVizLayer0,
                              CATPolyBars* iBars0,
                              CATPolyBarsBarSupportLayer* iBarVizLayer0, 
                              CATIPolyMesh& iOperand1, 
                              CATPolyMeshVertexNNormalsLayer* iNormalLayer1,
                              CATPolySurfaceFacetSupportLayer* iTriangleVizLayer1,
                              CATPolyBars* iBars1,
                              CATPolyBarsBarSupportLayer* iBarVizLayer1,
                              CATPolyBarsBarSupportLayer* iBarClippingLayer0 = 0); 

  CATPolyVisuBooleanObserver (CATIPolyMesh& iOperand0, 
                              CATPolyMeshVertexNNormalsLayer* iNormalLayer0,
                              CATPolySurfaceFacetSupportLayer* iTriangleVizLayer0,
                              CATPolyBars* iBars0,
                              CATPolyBarsBarSupportLayer* iBarVizLayer0, 
                              CATPolyVizJournalLayer* iVizJournalLayer0, 
                              CATIPolyMesh& iOperand1, 
                              CATPolyMeshVertexNNormalsLayer* iNormalLayer1,
                              CATPolySurfaceFacetSupportLayer* iTriangleVizLayer1,
                              CATPolyBars* iBars1,
                              CATPolyBarsBarSupportLayer* iBarVizLayer1,
                              CATPolyBarsBarSupportLayer* iBarClippingLayer0 = 0); 

  virtual ~CATPolyVisuBooleanObserver ();

public:

  // Refinement of the mesh.

  HRESULT PrepareToRefineOperand (const CATIPolyMesh& iOperand);

  HRESULT ReactToRefineOperand (const CATIPolyMesh& iOperand);

public:

  // Refinement of free bars.

  HRESULT PrepareToRefineOperand (const CATPolyBars& iOperand);

  HRESULT ReactToRefineOperand (const CATPolyBars& iOperand);

public:

  HRESULT ReactToCopyTriangle (const int iTriangleFrom, const CATIPolyMesh& iOperandFrom,
                               const int iTriangleTo, const CATIPolyMesh& iOperandTo);

  HRESULT ReactToCopyVertex (const int iVertexFrom, const CATIPolyMesh& iOperandFrom,
                             const int iVertexTo, const CATIPolyMesh& iOperandTo);

public:

  // Definition of an intersection bar event.
  HRESULT ReactToDefineIntersectionBar (CATPolyBars& iBars, const int iBar,
                                        const int triangleOtherMesh = 0);

public:

  // Map a triangle index from the origin operand to the its index in the destination operand.
  inline int MapTriangle (const int iTriangleFrom) const;

private:

  // Operand 0 and its layers.

  CATIPolyMesh& _Mesh0;
  CATPolyMeshVertexNNormalsLayer* _VertexNormalLayer0;
  CATPolySurfaceFacetSupportLayer* _TriangleVizLayer0;
  CATPolyBars* _Bars0;
  CATPolyBarsBarSupportLayer* _BarVizLayer0;

  CATPolyBarsBarSupportLayer* _BarClippingLayer0;
  CATPolyVizJournalLayer* _VizJournalLayer0;

  // Operand 1 and its layers.

  CATIPolyMesh& _Mesh1;
  CATPolyMeshVertexNNormalsLayer* _VertexNormalLayer1;
  CATPolySurfaceFacetSupportLayer* _TriangleVizLayer1;
  CATPolyBars* _Bars1;
  CATPolyBarsBarSupportLayer* _BarVizLayer1;

private:

  // Observers for Operand 0.

  CATPolyVisuRefinementMeshObserver* _RefinementMeshObserver0;   // Mesh observer for refinement events.

  CATPolyVisuRefinementBarsObserver* _RefinementBarsObserver0;   // Bars observer for refinement events.
  CATPolyBarsBarSupportLayerBarsObserver* _BarVizLayerBarsObserver0; // Bars observer for all other events.

  // Observer for Operand 1.

  CATPolyVisuRefinementMeshObserver* _RefinementMeshObserver1;   // Mesh observer for refinement events.

  CATPolyVisuRefinementBarsObserver* _RefinementBarsObserver1;   // Bars observer for refinement events.
  CATPolyBarsBarSupportLayerBarsObserver* _BarVizLayerBarsObserver1; // Bars observer for all other events.

private:

  // Maps from origin to destination operands.

  const CATIPolyMesh* _CopyFromMesh;  // The origin operand.

  int* _MapTriangle;       // Map a triangle from the origin operand to a triangle from the destination operand.
  int _MaxTriangleIndex;   // Maximum index of a triangle from the origin operand.

private:

  HRESULT SetMapSurface (const CATIPolyMesh& iCopyFromMesh);
  HRESULT SetMapCurve (const CATIPolyMesh& iCopyFromMesh);
  HRESULT SetMapTriangle (const CATIPolyMesh& iCopyFromMesh);
  HRESULT SetMap (const CATIPolyMesh& iCopyFromMesh);

private: 

  void Initialize ();

  void GetParameters (const CATIPolyMesh& iOperand,
                      CATPolyVisuRefinementMeshObserver*& refinementMeshObserver,
                      CATPolyBars*& bars,
                      CATPolyBarsBarSupportLayer*& barVizLayer,
                      CATPolyVisuRefinementBarsObserver*& refinementBarsObserver,
                      CATPolyBarsBarSupportLayerBarsObserver*& barVizLayerBarsObserver) const;

};

inline int CATPolyVisuBooleanObserver::MapTriangle (const int t) const
{
  return _MapTriangle && 0 < t && t <= _MaxTriangleIndex ? _MapTriangle[t] : 0;
}

#endif
