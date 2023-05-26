//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// One-shot tessellation visitor dedicated to CATPolyBody filling
//
//=============================================================================
// 2006-11-02  BPG: New.
//=============================================================================
#ifndef CATTessStorePolyBody_H
#define CATTessStorePolyBody_H

#include "TessPolygon.h"

#include "CATTessStore.h"
#include "CATTessDiagnostic.h"
#include "CATTessPolyBodyTessellatorSettings.h"
#include "CATTessObjectLinker.h"
#include "CATMapOfPtrToPtr.h"
//
#include "CATPolyBody.h"
#include "CATPolyFace.h"
#include "CATPolyEdge.h"
#include "CATPolyVertex.h"
#include "CATSetOfPtr.h"

//
// Strongly typed map
template <typename A, typename B>
class Map
{
public:
  inline void Associate(A *a, B *b) {  _LowLevelMap.Associate(a, b); }
  inline B* RetrieveObject(A *a) { return (B *) _LowLevelMap.RetrieveObject(a); }

protected:
  CATTessObjectLinker _LowLevelMap;
};

//
class ExportedByTessPolygon CATTessStorePolyBody:
  public CATTessStore
{
public:
  CATTessStorePolyBody (const CATTessPolyBodyTessellatorSettings &iSettings, 
                        CATPolyBody &ioPolyBody, CATMapOfPtrToPtr* ioMapCATPolyCellToCATCell = 0);
  virtual ~CATTessStorePolyBody();

public:
  virtual void
  StoreFace(CATFace* iFace, 
            CATBoolean iNew,
            CATBoolean iVolume,
            CATSide iSide,
            CATBoolean iPlane,
            CATLONG32 iNbPoints, CATTessPointIter *iPoints,
            CATLONG32 iNbStrips, CATTessStripeIter *iStrips,
            CATLONG32 iNbFans, CATTessFanIter *iFans,
            CATLONG32 iNbPolygons, CATTessPolyIter *iPolygons,
            CATLONG32 iNbTriangles, CATTessTrianIter *iTriangles);

  virtual void
  StoreEdge(CATEdge *iEdge,
            CATBoolean iNew,
            CATTessEdgeIter *iEdgeIter);

  // This is called for wire-edges
  virtual void
  StoreEdge(CATEdge *iEdge,
            CATBoolean iNew,
            CATLONG32 iNumberOfPoints,
            double *iPointData);

  virtual void
  StoreVertex(CATVertex *iVertex,
              CATBoolean iNew,
              CATTessVertexIter *iVertexIter);

  // This is called for free vertices
  virtual void
  StoreVertex(CATVertex *iVertex,
              CATMathPoint *iMathPoint,
              CATBoolean iNew,
              CATFace *iBoundedFace,
              CATLONG32 iPointNumberInFace);

public:
  inline HRESULT GetStatus() const { return _Status; }
  inline const CATSetOfPtr& GetFlaggedPolyFaces() const { return _FlaggedPolyFaces; }

protected:
  const CATTessPolyBodyTessellatorSettings _Settings;

  HRESULT _Status;

  CATPolyBody &_PolyBody;
  CATMapOfPtrToPtr* _MapCATPolyCellToCATCell;

  Map<CATFace, CATPolyFace> _FaceToPolyFace;
  Map<CATEdge, CATPolyEdge> _EdgeToPolyEdge;
  Map<CATVertex, CATPolyVertex> _VertexToPolyVertex;

  CATSetOfPtr _FlaggedPolyFaces;
};

#endif // !CATTessStorePolyBody_H
