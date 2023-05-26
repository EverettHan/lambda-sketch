// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceOrbitEdgeIterator
//
//=============================================================================
// May 2019 - NDO
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyFaceOrbit.h"


/**
 * Iterator through all the edges around a face-orbit.
 * This iterator cycles through the edges around the orbit once and only once.
 */
class ExportedByPolyMODEL CATPolyFaceOrbitEdgeIterator
{

public:

  inline CATPolyFaceOrbitEdgeIterator (const CATPolyFaceOrbit* orbit = 0);
  inline ~CATPolyFaceOrbitEdgeIterator ();

public:

  CATPolyFaceOrbitEdgeIterator& Begin ();
  inline CATPolyFaceOrbitEdgeIterator& Begin (const CATPolyFaceOrbit* orbit);
  inline CATPolyFaceOrbitEdgeIterator& Begin (const CATPolyFaceOrbit& orbit);
  inline bool End () const;
  inline CATPolyFaceOrbitEdgeIterator& operator++ ();

public:

  /**
   * Returns the current edge.
   */
  inline CATPolyEdge* operator* () const;

  /**
   * Returns the current edge.
   */
  inline CATPolyEdge* GetEdge () const;

  /**
   * Returns the current edge orientation in the face.
   */
  //inline int GetEdgeOrientation () const;

  /**
   * Returns the face-orbit qualifier.
   */
  inline Poly::OrbitQualifier GetQualifier () const;

  /**
   * Returns the surface-vertex line associated to the current edge on this face.
   */
  inline CATIPolySurfaceVertexLine* GetSurfaceVertexLine () const;

  /**
   * Returns a vertex from the edge in the sequence of the edges around the orbit.
   * @param k
   *   0 or 1
   */
  inline CATPolyVertex* GetVertex (unsigned int k) const;

  /**
   * Returns a vertex from the edge in the sequence of the edges around the orbit.
   */
  inline CATPolyVertex* GetVertex () const { return GetVertex (0); }

  /**
   * Returns the point associated to the matching vertex seen from the edge and the face.
   * See GetVertex (unsigned int k) above.
   * @param k
   *   0 or 1
   */
  inline CATIPolyPoint* GetPoint (unsigned int k) const;

  /**
   * Returns the point associated to the current vertex seen from the edge and the face.
   */
  inline CATIPolyPoint* GetPoint () const { return GetPoint (0); }

  /**
   * Returns the surface-vertex associated to the matching vertex seen from the edge and the face.
   * See GetVertex (unsigned int k) above.
   * @param k
   *   0 or 1
   */
  inline CATIPolySurfaceVertex* GetSurfaceVertex (unsigned int k) const;

  /**
   * Returns the surface-vertex associated to the current vertex seen from the edge and the face.
   */
  inline CATIPolySurfaceVertex* GetSurfaceVertex () const { return GetSurfaceVertex (0); }

  /**
   * Returns the adjacent face through the manifold edge (may be null.)
   * The edge may be non-manifold but there is only one face adjacent to
   * to the input face via the manifold edge.
   */
  inline CATPolyFace* GetAdjacentFace () const;

#ifndef _AIX_SOURCE
private:
#else
public:
#endif

  class FaceOrbitEdgeIterator
  {
  public:
    virtual ~FaceOrbitEdgeIterator () {}
    virtual bool End () const = 0;
    virtual void operator++ () = 0;
    virtual CATPolyEdge* GetEdge () const = 0;
    virtual CATIPolySurfaceVertexLine* GetSurfaceVertexLine () const = 0;
    virtual CATPolyVertex* GetVertex (unsigned int i) const = 0;
    virtual CATIPolyPoint* GetPoint (unsigned int i) const = 0;
    virtual CATIPolySurfaceVertex* GetSurfaceVertex (unsigned int i) const = 0;
    virtual CATPolyFace* GetAdjacentFace () const = 0;

    virtual size_t Dimension () const = 0;
    virtual void* GetDart () const = 0;

    //virtual FaceOrbitEdgeIterator* Clone () const = 0;
  };

private:

  const CATPolyFaceOrbit* _Orbit;
  FaceOrbitEdgeIterator* _Iterator;

  friend class CATPolyDartHelpers;
  template<class DART> friend class FaceOrbitEdgeIteratorImpl;

  template<class DART>
  inline DART* GetDart () const;
};


inline CATPolyFaceOrbitEdgeIterator::CATPolyFaceOrbitEdgeIterator (const CATPolyFaceOrbit* orbit) :
  _Orbit (orbit),
  _Iterator (0)
{
  Begin ();
}

inline CATPolyFaceOrbitEdgeIterator::~CATPolyFaceOrbitEdgeIterator ()
{
  _Orbit = 0;
  delete _Iterator;
  _Iterator = 0;
}

inline CATPolyFaceOrbitEdgeIterator& CATPolyFaceOrbitEdgeIterator::Begin (const CATPolyFaceOrbit* orbit)
{
  _Orbit = orbit;
  return Begin ();
}

inline CATPolyFaceOrbitEdgeIterator& CATPolyFaceOrbitEdgeIterator::Begin (const CATPolyFaceOrbit& orbit)
{
  _Orbit = &orbit;
  return Begin ();
}

inline bool CATPolyFaceOrbitEdgeIterator::End () const
{
  return _Iterator ? _Iterator->End () : true;
}

inline CATPolyFaceOrbitEdgeIterator& CATPolyFaceOrbitEdgeIterator::operator++ ()
{
  if (_Iterator)
    ++(*_Iterator);
  return *this;
}

inline CATPolyEdge* CATPolyFaceOrbitEdgeIterator::operator* () const
{
  return _Iterator ? _Iterator->GetEdge () : 0;
}

inline CATPolyEdge* CATPolyFaceOrbitEdgeIterator::GetEdge () const
{
  return _Iterator ? _Iterator->GetEdge () : 0;
}

inline Poly::OrbitQualifier CATPolyFaceOrbitEdgeIterator::GetQualifier () const
{
  return _Orbit ? _Orbit->GetQualifier () : Poly::NoQualifier;
}

inline CATIPolySurfaceVertexLine* CATPolyFaceOrbitEdgeIterator::GetSurfaceVertexLine () const
{
  return _Iterator ? _Iterator->GetSurfaceVertexLine () : 0;
}

inline CATPolyVertex* CATPolyFaceOrbitEdgeIterator::GetVertex (unsigned int i) const
{
  return _Iterator ? _Iterator->GetVertex (i) : 0;
}

inline CATIPolyPoint* CATPolyFaceOrbitEdgeIterator::GetPoint (unsigned int i) const
{
  return _Iterator ? _Iterator->GetPoint (i) : 0;
}

inline CATIPolySurfaceVertex* CATPolyFaceOrbitEdgeIterator::GetSurfaceVertex (unsigned int i) const
{
  return _Iterator ? _Iterator->GetSurfaceVertex (i) : 0;
}

inline CATPolyFace* CATPolyFaceOrbitEdgeIterator::GetAdjacentFace () const
{
  return _Iterator ? _Iterator->GetAdjacentFace () : 0;
}

template<class DART>
inline DART* CATPolyFaceOrbitEdgeIterator::GetDart () const
{
  return _Iterator && _Iterator->Dimension () == DART::Dimension () ? (DART*) _Iterator->GetDart () : 0;
}
