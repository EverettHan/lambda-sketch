// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPolyMeshDistanceLayer.h
// Store one set of distance data for each vertex contained in a
// CATIPolyMesh.
// Corresponds to the data computed in the CATPolyMesh/CATPolyMesh
// distance operator CATPolyMeshDistance.
//
//===================================================================
//  2009/01/13   XXC: Creation
//===================================================================
#ifndef CATPolyMeshDistanceLayer_H
#define CATPolyMeshDistanceLayer_H

#include "CATErrorDef.h"
#include "CATPolyDistanceOperators.h"
#include "CATPolyRefCounted.h"
#include "CATMathPoint.h"
#include "CATIPolySurfaceVertexIterator.h"
#include "CATIPolyMesh.h"
#include "CATMapOfIntToInt.h"


class DistInfo;
//------------------------------------------------------------------

class ExportedByPolyhedralDistanceOperators CATPolyMeshDistanceLayerIterator
{
 public:
 CATPolyMeshDistanceLayerIterator(CATIPolyMesh * iPolyMesh)
   :
  _Ref(iPolyMesh),
    _VIterator(0)
      {
        iPolyMesh->AddRef();
      }
  
  ~CATPolyMeshDistanceLayerIterator()
    {
      if (_VIterator) _VIterator->Release();
      _VIterator = NULL;
      if (_Ref) _Ref->Release();
      _Ref = NULL;
    }

  inline void Begin() {
    if (!_VIterator)
        _Ref->GetVertexIterator(_VIterator);
    _VIterator->Begin();
  }

  inline CATBoolean End()
  {
    return (_VIterator)?_VIterator->End():TRUE;
  }

  inline void Next()
  {
    if (_VIterator)
      ++(*_VIterator);
  }

  inline void Get(int & oIdxVertex)
  {
    if (!_VIterator)
      Begin();

    oIdxVertex = (_VIterator ? _VIterator->Get() : -1);
  }

private:
  CATIPolyMesh * _Ref;
  CATIPolySurfaceVertexIterator * _VIterator;
};

class ExportedByPolyhedralDistanceOperators CATPolyMeshDistanceLayer : public CATPolyRefCounted
{
public:
  enum Location { Inside, OnBorder, Out };
  
public:
  CATPolyMeshDistanceLayer(CATIPolyMesh & iPolyMesh, double iRefinementLengthLimit = 0.0);
  virtual ~CATPolyMeshDistanceLayer();
  
public:
  
  /** Set all informations contained in a Surface vertex distance
   *  layer.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param iDist: the distance from the vertex and an element (a
   *polygon in another CATIPolySurface, etc.)
   *@param iProj: the projection of the vertex on the element. The
   *distance iDist is the one between the vertex and its projection
   *iProj.
   *@param iLoc: The location of the projection on the element:
   *inside, on the border, outside (no projection).
   *@param iIndex: index of the element in the CATIPolyMesh where
   *the vertex is projected.
   */
  virtual HRESULT SetData(const int iIdxVertex,
                          const double & iDist, const CATMathPoint & iProj,
                          const Location & iLoc, const int & iIndex);
  /** Set the distance from the concerned vertex and the distant
   *  element.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param iDist: the distance
   */
  virtual HRESULT SetDistance(const int iIdxVertex, const double & iDist);
  /** Set the projection point of the concerned vertex on the surface
   *  of reference.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param iProj: the projection point.
   */
  virtual HRESULT SetProjection(const int iIdxVertex, const CATMathPoint & iProj);
  /** Set the location of the projection point on the element in the
   *  surface of reference.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param iLoc: the projection location: inside, on the border, outside (no
   *projection).
   */
  virtual HRESULT SetLocation(const int iIdxVertex, const Location iLoc);
  /** Set the index of the element where is located the projection
   *  point in the surface of reference.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param iIndex: the index of the element in the opposite
   *CATIPolySurface.
   */
  virtual HRESULT SetIdxFacet(const int iIdxVertex, const int & iIndex);
  
  /** Get the distance from the concerned vertex and the distant
   *  element.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param oDist: the distance
   */
  virtual HRESULT GetDistance(const int iIdxVertex, double & oDist) const;
  /** Get the projection point of the concerned vertex on the surface
   *  of reference.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param oProj: the projection point.
   */
  virtual HRESULT GetProjection(const int iIdxVertex, CATMathPoint & oProj) const;
  /** Get the location of the projection point on the element in the
   *  surface of reference.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param oLoc: the location: inside, on the border, outside (no
   *projection).
   */
  virtual HRESULT GetLocation(const int iIdxVertex, Location & oLoc) const;
  /** Get the index of the element where is located the projection
   *  point in the surface of reference.
   *@param iIdxVertex: the index of the vertex in the CATIPolySurface
   *the layer refers to.
   *@param oIndex: the index of the element in the surface.
   */
  virtual HRESULT GetIdxFacet(const int iIdxVertex, int & oIndex) const;

  /** Get an iterator on every vertex index in the PolyMesh used to
   *  construct the distance layer. Allows a direct access to every
   *  distance data contained in the layer.
   */
  HRESULT GetIterator(CATPolyMeshDistanceLayerIterator *& oIterator) const;

  /** 
   * Get the CATPolyMesh to which the layer is associated.
   * @param oPolyMesh [out, IUnknown#Release] 
   */
  HRESULT GetPolyMesh(CATIPolyMesh *& oPolyMesh) const;

  /** Export the distance datum, for each vertex, to the normal
   *  coordinates in the CATIPolySurfaceVertexTextureCoordLayer. With
   *  the appropriate shader, allows to get a display of the result as
   *  a coloured surface, from blue (higher distances, little risk of
   *  clash) to red (smaller distances, high risk of clash).
   */
  HRESULT ExportToTextureCoordLayer() const;

private:

  CATIPolyMesh * _RefPolyMesh;
  DistInfo* _DistInfos;
  CATMapOfIntToInt _MapVertices;
};

//------------------------------------------------------------------

#endif
