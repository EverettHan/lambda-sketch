// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyVolumeCellIterator
//
//=============================================================================
// 2022-12-16 NDO: New
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"

#include "CATPolyCellOrbit.h"  // Poly::OrbitQualifier


/**
 * Iterates through the cells belonguing to an orbit of a volume.
 * It iterates through:
 *   * Outer, inner or full faces 
 *   * Full edges
 *   * Full vertices
 * The iterator ignores cells incident to higher dimensional cells other than the volume.
 */
class ExportedByPolyMODEL CATPolyVolumeCellIterator
{

public:

  inline CATPolyVolumeCellIterator (CATPolyVolume* VLM = 0);
  inline CATPolyVolumeCellIterator (const CATPolyVolumeCellIterator& iRHS);
  inline ~CATPolyVolumeCellIterator ();

public:

  CATPolyVolumeCellIterator& Begin (CATPolyVolume* VLM);
  inline CATPolyVolumeCellIterator& Begin (CATPolyVolume& VLM);
  inline bool End () const;
  inline CATPolyVolumeCellIterator& operator++ ();

public:

  inline CATPolyVertex* GetVertex () const;

  inline CATPolyEdge* GetEdge () const;

  inline CATPolyFace* GetFace () const;

  inline CATIPolyPoint* GetPoint () const;

  inline CATIPolyCurve* GetCurve () const;

  inline CATIPolySurface* GetSurface () const;

  /**
   * Returns the current face orientation in the volume.
   */
  inline int GetFaceOrientation () const;

  /**
   * Returns the volume-orbit qualifier.
   */
  inline Poly::OrbitQualifier GetQualifier () const;

#ifndef _AIX_SOURCE
private:
#else
public:
#endif

  class VolumeCellIterator
  {
  public:
    virtual ~VolumeCellIterator () {}
    virtual void Begin (CATPolyVolume& VLM) = 0;
    virtual bool End () const = 0;
    virtual void operator++ () = 0;
    virtual CATPolyVertex* GetVertex () const = 0;
    virtual CATPolyEdge* GetEdge () const = 0;
    virtual CATPolyFace* GetFace () const = 0;
    virtual CATIPolyPoint* GetPoint () const = 0;
    virtual CATIPolyCurve* GetCurve () const = 0;
    virtual CATIPolySurface* GetSurface () const = 0;
    virtual int GetFaceOrientation () const = 0;
    virtual Poly::OrbitQualifier GetQualifier () const = 0;

    virtual VolumeCellIterator* Clone () const = 0;
  };

  VolumeCellIterator* _Iterator;

  template<class DART> friend class VolumeCellIteratorImpl;
};

inline CATPolyVolumeCellIterator::CATPolyVolumeCellIterator (CATPolyVolume* VLM) :
  _Iterator (0)
{
  Begin (VLM);
}

inline CATPolyVolumeCellIterator::CATPolyVolumeCellIterator (const CATPolyVolumeCellIterator& iRHS) :
  _Iterator (0)
{
  if (iRHS._Iterator)
    _Iterator = iRHS._Iterator->Clone ();
}

inline CATPolyVolumeCellIterator::~CATPolyVolumeCellIterator ()
{
  delete _Iterator;
  _Iterator = 0;
}

inline CATPolyVolumeCellIterator& CATPolyVolumeCellIterator::Begin (CATPolyVolume& VLM)
{
  return Begin (&VLM);
}

inline bool CATPolyVolumeCellIterator::End () const
{
  return _Iterator ? _Iterator->End () : true;
}

inline CATPolyVolumeCellIterator& CATPolyVolumeCellIterator::operator++ ()
{
  if (_Iterator)
    ++(*_Iterator);
  return *this;
}

inline CATPolyVertex* CATPolyVolumeCellIterator::GetVertex () const
{
  return _Iterator ? _Iterator->GetVertex () : 0;
}

inline CATPolyEdge* CATPolyVolumeCellIterator::GetEdge () const
{
  return _Iterator ? _Iterator->GetEdge () : 0;
}

inline CATPolyFace* CATPolyVolumeCellIterator::GetFace () const
{
  return _Iterator ? _Iterator->GetFace () : 0;
}

inline CATIPolyPoint* CATPolyVolumeCellIterator::GetPoint () const
{
  return _Iterator ? _Iterator->GetPoint () : 0;
}

inline CATIPolyCurve* CATPolyVolumeCellIterator::GetCurve () const
{
  return _Iterator ? _Iterator->GetCurve () : 0;
}

inline CATIPolySurface* CATPolyVolumeCellIterator::GetSurface () const
{
  return _Iterator ? _Iterator->GetSurface () : 0;
}

inline int CATPolyVolumeCellIterator::GetFaceOrientation () const
{
  return _Iterator ? _Iterator->GetFaceOrientation () : 0;
}

inline Poly::OrbitQualifier CATPolyVolumeCellIterator::GetQualifier () const
{
  return _Iterator ? _Iterator->GetQualifier () : Poly::NoQualifier;
}
