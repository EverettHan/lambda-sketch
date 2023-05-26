// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyEdgeOrbitFaceIterator
//
//=============================================================================
// January 2023 - NDO
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyEdgeOrbit.h"
#include "CATPolyFaceOrbit.h"


/**
 * Iterator through all the faces around an edge-orbit.
 * This iterator cycles through all the distinct pairs (face, SVL) around the orbit once and only once.
 */
class ExportedByPolyMODEL CATPolyEdgeOrbitFaceIterator
{

public:

  inline CATPolyEdgeOrbitFaceIterator (const CATPolyEdgeOrbit* orbit = 0);
  inline ~CATPolyEdgeOrbitFaceIterator ();

public:

  CATPolyEdgeOrbitFaceIterator& Begin ();
  inline CATPolyEdgeOrbitFaceIterator& Begin (const CATPolyEdgeOrbit* orbit);
  inline CATPolyEdgeOrbitFaceIterator& Begin (const CATPolyEdgeOrbit& orbit);
  inline bool End () const;
  inline CATPolyEdgeOrbitFaceIterator& operator++ ();

public:

  /**
   * Returns the current face orbit.
   */
  inline CATPolyFaceOrbit* GetFaceOrbit () const;

  /**
   * Returns the current face.
   */
  inline CATPolyFace* operator* () const;

  /**
   * Returns the current face.
   */
  inline CATPolyFace* GetFace () const;

  /**
   * Returns the face-orbit qualifier.
   */
  //inline Poly::OrbitQualifier GetQualifier () const;

  /**
   * Returns the surface-vertex line associated to the edge on the current face.
   */
  inline CATIPolySurfaceVertexLine* GetSurfaceVertexLine () const;

#ifndef _AIX_SOURCE
private:
#else
public:
#endif

  class EdgeOrbitFaceIterator
  {
  public:
    virtual ~EdgeOrbitFaceIterator () {}
    virtual bool End () const = 0;
    virtual void operator++ () = 0;
    virtual CATPolyFaceOrbit* GetFaceOrbit () const = 0;
    virtual CATIPolySurfaceVertexLine* GetSurfaceVertexLine () const = 0;

    virtual size_t Dimension () const = 0;
    virtual void* GetDart () const = 0;

    //virtual FaceOrbitEdgeIterator* Clone () const = 0;
  };

private:

  const CATPolyEdgeOrbit* _Orbit;
  EdgeOrbitFaceIterator* _Iterator;

  friend class CATPolyDartHelpers;
  template<class DART> friend class EdgeOrbitFaceIteratorImpl;

  template<class DART>
  inline DART* GetDart () const;
};


inline CATPolyEdgeOrbitFaceIterator::CATPolyEdgeOrbitFaceIterator (const CATPolyEdgeOrbit* orbit) :
  _Orbit (orbit),
  _Iterator (0)
{
  Begin ();
}

inline CATPolyEdgeOrbitFaceIterator::~CATPolyEdgeOrbitFaceIterator ()
{
  _Orbit = 0;
  delete _Iterator;
  _Iterator = 0;
}

inline CATPolyEdgeOrbitFaceIterator& CATPolyEdgeOrbitFaceIterator::Begin (const CATPolyEdgeOrbit* orbit)
{
  _Orbit = orbit;
  return Begin ();
}

inline CATPolyEdgeOrbitFaceIterator& CATPolyEdgeOrbitFaceIterator::Begin (const CATPolyEdgeOrbit& orbit)
{
  _Orbit = &orbit;
  return Begin ();
}

inline bool CATPolyEdgeOrbitFaceIterator::End () const
{
  return _Iterator ? _Iterator->End () : true;
}

inline CATPolyEdgeOrbitFaceIterator& CATPolyEdgeOrbitFaceIterator::operator++ ()
{
  if (_Iterator)
    ++(*_Iterator);
  return *this;
}

inline CATPolyFaceOrbit* CATPolyEdgeOrbitFaceIterator::GetFaceOrbit () const
{
  return _Iterator ? _Iterator->GetFaceOrbit () : 0;
}

inline CATPolyFace* CATPolyEdgeOrbitFaceIterator::operator* () const
{
  CATPolyFaceOrbit* FO = GetFaceOrbit ();
  return FO ? FO->GetFace () : 0;
}

inline CATPolyFace* CATPolyEdgeOrbitFaceIterator::GetFace () const
{
  return **this;
}

//inline Poly::OrbitQualifier CATPolyEdgeOrbitFaceIterator::GetQualifier () const
//{
  //return _Orbit ? _Orbit->GetQualifier () : Poly::NoQualifier;
//}

inline CATIPolySurfaceVertexLine* CATPolyEdgeOrbitFaceIterator::GetSurfaceVertexLine () const
{
  return _Iterator ? _Iterator->GetSurfaceVertexLine () : 0;
}

template<class DART>
inline DART* CATPolyEdgeOrbitFaceIterator::GetDart () const
{
  return _Iterator && _Iterator->Dimension () == DART::Dimension () ? (DART*) _Iterator->GetDart () : 0;
}
