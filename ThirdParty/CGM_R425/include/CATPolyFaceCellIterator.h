// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceCellIterator
//
//=============================================================================
// 2017-02-13 New -NDO
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"

#include "CATPolyCellOrbit.h"  // Poly::OrbitQualifier


/**
 * Iterates through the cells belonguing to an orbit of a face.
 * It iterates through:
 *   * Outer, inner or full edges
 *   * Full vertices
 * The iterator ignores vertices incident to edges.
 *
 * Example:
 * \code
 * CATPolyFaceCellIterator it;
 * for (it.Begin (MyFace); !it.End(); ++it)
 * {
 *   CATPolyVertex* V = it.GetVertex ();
 *   CATPolyEdge* E = it.GetEdge ();
 *   CATIPolySurfaceVertexLine* svl = it.GetSurfaceVertexLine ();  // If cell is a CATPolyEdge.
 *   CATIPolySurfaceVertex* sv = it.GetSurfaceVertex ();  // If cell is a CATPolyVertex.
 * }
 */

/**
* Iterates through all the cells of dimensions 0 (CATPolyVertex) or 1 (CATPolyEdge)
* incident to a CATPolyFace. The iterator cycles through the edges and vertices if and only if
* these vertices are not incident to any edge.
* The start and end vertices of edges are not cycled through by the iterator.
*/
class ExportedByPolyMODEL CATPolyFaceCellIterator
{

public:

  inline CATPolyFaceCellIterator (CATPolyFace* F = 0);
  inline CATPolyFaceCellIterator (const CATPolyFaceCellIterator& iRHS);
  inline ~CATPolyFaceCellIterator ();

public:

  CATPolyFaceCellIterator& Begin (CATPolyFace* F);
  inline CATPolyFaceCellIterator& Begin (CATPolyFace& F);
  inline bool End () const;
  inline CATPolyFaceCellIterator& operator++ ();

public:

  inline CATPolyVertex* GetVertex () const;

  inline CATPolyEdge* GetEdge () const;

  inline CATIPolySurfaceVertex* GetSurfaceVertex () const;

  inline CATIPolySurfaceVertexLine* GetSurfaceVertexLine () const;

  /**
   * Returns the face-orbit qualifier.
   */
  inline Poly::OrbitQualifier GetQualifier () const;

#ifndef _AIX_SOURCE
private:
#else
public:
#endif

  class FaceCellIterator
  {
  public:
    virtual ~FaceCellIterator () {}
    virtual void Begin (CATPolyFace& F) = 0;
    virtual bool End () const = 0;
    virtual void operator++ () = 0;
    virtual CATPolyVertex* GetVertex () const = 0;
    virtual CATPolyEdge* GetEdge () const = 0;
    virtual CATIPolySurfaceVertex* GetSurfaceVertex () const = 0;
    virtual CATIPolySurfaceVertexLine* GetSurfaceVertexLine () const = 0;
    virtual Poly::OrbitQualifier GetQualifier () const = 0;

    virtual FaceCellIterator* Clone () const = 0;
  };

  FaceCellIterator* _Iterator;

  template<class DART> friend class FaceCellIteratorImpl;
};

inline CATPolyFaceCellIterator::CATPolyFaceCellIterator (CATPolyFace* F) :
  _Iterator (0)
{
  Begin (F);
}

inline CATPolyFaceCellIterator::CATPolyFaceCellIterator (const CATPolyFaceCellIterator& iRHS) :
  _Iterator (0)
{
  if (iRHS._Iterator)
    _Iterator = iRHS._Iterator->Clone ();
}

inline CATPolyFaceCellIterator::~CATPolyFaceCellIterator ()
{
  delete _Iterator;
  _Iterator = 0;
}

inline CATPolyFaceCellIterator& CATPolyFaceCellIterator::Begin (CATPolyFace& F)
{
  return Begin (&F);
}

inline bool CATPolyFaceCellIterator::End () const
{
  return _Iterator ? _Iterator->End () : true;
}

inline CATPolyFaceCellIterator& CATPolyFaceCellIterator::operator++ ()
{
  if (_Iterator)
    ++(*_Iterator);
  return *this;
}

inline CATPolyVertex* CATPolyFaceCellIterator::GetVertex () const
{
  return _Iterator ? _Iterator->GetVertex () : 0;
}

inline CATPolyEdge* CATPolyFaceCellIterator::GetEdge () const
{
  return _Iterator ? _Iterator->GetEdge () : 0;
}

inline CATIPolySurfaceVertex* CATPolyFaceCellIterator::GetSurfaceVertex () const
{
  return _Iterator ? _Iterator->GetSurfaceVertex () : 0;
}

inline CATIPolySurfaceVertexLine* CATPolyFaceCellIterator::GetSurfaceVertexLine () const
{
  return _Iterator ? _Iterator->GetSurfaceVertexLine () : 0;
}

inline Poly::OrbitQualifier CATPolyFaceCellIterator::GetQualifier () const
{
  return _Iterator ? _Iterator->GetQualifier () : Poly::NoQualifier;
}
