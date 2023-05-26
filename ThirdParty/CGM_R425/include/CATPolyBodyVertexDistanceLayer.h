// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPolyVertexDistanceLayer.h
// Store one set of distance data for each vertex contained in each
// face of a CATPolyBody.
// Corresponds to the data computed in the CATPolyBody/CATPolyBody
// distance operator CATPolyDistanceBodyBodyDistance.
//
//===================================================================
//  2009/01/13   XXC: Creation
//===================================================================
#ifndef CATPolyVertexDistanceLayer_H
#define CATPolyVertexDistanceLayer_H

#include "CATErrorDef.h"
#include "PolyBodyDistance.h"
#include "CATPolyRefCounted.h"
#include "CATMathPoint.h"
#include "CATIPolySurfaceVertexIterator.h"

class CATPolyBody;
class DistInfo;
class CATMapOfIntToInt;
//------------------------------------------------------------------

class ExportedByPolyBodyDistance CATPolyBodyVertexDistanceLayerIterator
{
public:
  CATPolyBodyVertexDistanceLayerIterator(const CATPolyBody * iPolyBody)
    :
    _RefPB(iPolyBody),
    _VIterator(0),
    _IdxF(-1)
  {}
  ~CATPolyBodyVertexDistanceLayerIterator()
    {
      if (_VIterator) _VIterator->Release();
    }

  void Begin();

  inline CATBoolean End()
  {
    return (_VIterator)?FALSE:TRUE;
  }

  void Next();

  inline void Get(int & oIdxFace, int & oIdxVertex)
  {
    oIdxFace = _IdxF;
    if (_VIterator)
      oIdxVertex = _VIterator->Get();
  }

private:
  const CATPolyBody * _RefPB;
  CATIPolySurfaceVertexIterator * _VIterator;
  int _IdxF;
};

class ExportedByPolyBodyDistance CATPolyBodyVertexDistanceLayer : public CATPolyRefCounted
{
public:
  enum Location { Inside, OnBorder, Out };
  
public:
  CATPolyBodyVertexDistanceLayer(CATPolyBody & iPolyBody, double iRefinementLengthLimit = 0.0);
  virtual ~CATPolyBodyVertexDistanceLayer();
  
public:
  
  /** Set all informations contained in a Surface vertex distance
   *  layer.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param iDist: the distance from the vertex and an element (a
   *polygon in another CATIPolySurface, etc.)
   *@param iProj: the projection of the vertex on the element. The
   *distance iDist is the one between the vertex and its projection
   *iProj.
   *@param iLoc: The location of the projection on the element:
   *inside, on the border, outside (no projection).
   *@param iIndex: index of the element in the CATIPolySurface of
   *reference.
   *@param iIndexSurface: index of the surface of reference (its index
   *in a Poly Body for instance).
   */
  virtual HRESULT SetData(const int iIdxFace, const int iIdxVertex,
                          const double & iDist, const CATMathPoint & iProj,
                          const Location & iLoc, const int & iIndex, const int & iIndexSurface);
  /** Set the distance from the concerned vertex and the distant
   *  element.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param iDist: the distance
   */
  virtual HRESULT SetDistance(const int iIdxFace, const int iIdxVertex, const double & iDist);
  /** Set the projection point of the concerned vertex on the surface
   *  of reference.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param iProj: the projection point.
   */
  virtual HRESULT SetProjection(const int iIdxFace, const int iIdxVertex, const CATMathPoint & iProj);
  /** Set the location of the projection point on the element in the
   *  surface of reference.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param iLoc: the location: inside, on the border, outside (no
   *projection).
   */
  virtual HRESULT SetLocation(const int iIdxFace, const int iIdxVertex, const Location iLoc);
  /** Set the index of the element where is located the projection
   *  point in the surface of reference.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param iIndex: the index of the element in the surface.
   */
  virtual HRESULT SetIdxFacet(const int iIdxFace, const int iIdxVertex, const int & iIndex);
  /** Set the index of the surface that contains the element where is
   *  located the projection point.
   *@param iIdxVertex: the index of the vertex to set distance data in
   *the CATIPolySurface.
   *@param iIndex: the surface of reference.
   */
  virtual HRESULT SetIdxSurface(const int iIdxFace, const int iIdxVertex, const int &iIndex);
  
  /** Get the distance from the concerned vertex and the distant
   *  element.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param oDist: the distance
   */
  virtual HRESULT GetDistance(const int iIdxFace, const int iIdxVertex, double & oDist) const;
  /** Get the projection point of the concerned vertex on the surface
   *  of reference.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param oProj: the projection point.
   */
  virtual HRESULT GetProjection(const int iIdxFace, const int iIdxVertex, CATMathPoint & oProj) const;
  /** Get the location of the projection point on the element in the
   *  surface of reference.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param oLoc: the location: inside, on the border, outside (no
   *projection).
   */
  virtual HRESULT GetLocation(const int iIdxFace, const int iIdxVertex, Location & oLoc) const;
  /** Get the index of the element where is located the projection
   *  point in the surface of reference.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param oIndex: the index of the element in the surface.
   */
  virtual HRESULT GetIdxFacet(const int iIdxFace, const int iIdxVertex, int & oIndex) const;
  /** Get the index of the surface on which the vertex is projected.
   *@param iIdxFace: the index of the face where is the considered
   *vertex in the poly body.
   *@param iIdxVertex: the index of the vertex in the iIdxFace
   *CATIPolySurface/CATPolyFace of the CATPolyBody.
   *@param oIndex: the index of the surface of reference.
   */
  virtual HRESULT GetIdxSurface(const int iIdxFace, const int iIdxVertex, int & oIndex) const;

  /** Get an iterator on every vertex index in the PolyBody used to
   *  construct the distance layer. Allows a direct access to every
   *  distance data contained in the layer.
   */
  HRESULT GetIterator(CATPolyBodyVertexDistanceLayerIterator *& oIterator) const;

  /** Get the CATPolyBody to which the layer is associated.
   */
  HRESULT GetPolyBody(CATPolyBody *& oPolyBody) const;

  /** Export the distance datum, for each vertex, to the normal
   *  coordinates in the CATIPolySurfaceVertexTextureCoordLayer. With
   *  the appropriate shader, allows to get a display of the result as
   *  a coloured surface, from blue (higher distances, little risk of
   *  clash) to red (smaller distances, high risk of clash).
   */
  HRESULT ExportToTextureCoordLayer() const;

private:

  CATPolyBody * _RefPolyBody;
  CATBoolean _IsPreallocatedMesh;
  DistInfo** _DistInfos;
  int _NbFaces;
  CATMapOfIntToInt * _MapVertices;
};

//------------------------------------------------------------------

#endif
