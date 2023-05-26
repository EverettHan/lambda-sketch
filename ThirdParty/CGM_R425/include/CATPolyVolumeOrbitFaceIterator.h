// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyVolumeOrbitFaceIterator
//
//=============================================================================
// June 2022 - NDO
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyVolumeOrbit.h"
#include "CATPolyBody.h"


/**
 * Iterator through all the faces across a volume-orbit.
 * This iterator traverses all the faces across the orbit once and only once.
 */
class ExportedByPolyMODEL CATPolyVolumeOrbitFaceIterator
{

public:

  inline CATPolyVolumeOrbitFaceIterator (const CATPolyVolumeOrbit* orbit = 0);
  inline ~CATPolyVolumeOrbitFaceIterator ();

public:

  inline CATPolyVolumeOrbitFaceIterator& Begin ();
  CATPolyVolumeOrbitFaceIterator& Begin (const CATPolyVolumeOrbit* orbit);
  inline CATPolyVolumeOrbitFaceIterator& Begin (const CATPolyVolumeOrbit& orbit);
  inline bool End () const;
  inline CATPolyVolumeOrbitFaceIterator& operator++ ();

public:

  /**
   * Returns the current face.
   */
  inline CATPolyFace* operator* () const;

  /**
   * Returns the current face.
   */
  inline CATPolyFace* GetFace () const;

  /**
   * Returns the current face orientation in the volume.
   */
  inline int GetFaceOrientation () const;

  /**
   * Returns the volume-orbit qualifier.
   */
  inline Poly::OrbitQualifier GetQualifier () const;

  /**
   * Returns the adjacent volume across the face (may be null.)
   */
  inline CATPolyVolume* GetAdjacentVolume () const;

#ifndef _AIX_SOURCE
private:
#else
public:
#endif

  class VolumeOrbitFaceIterator
  {
  public:
    virtual ~VolumeOrbitFaceIterator () {}
    virtual bool End () const = 0;
    virtual void operator++ () = 0;
    virtual CATPolyFace* GetFace () const = 0;
    virtual int GetFaceOrientation () const = 0;
    virtual CATPolyVolume* GetAdjacentVolume () const = 0;

    virtual size_t Dimension () const = 0;
    virtual void* GetDart () const = 0;

    //virtual VolumeOrbitFaceIterator* Clone () const = 0;
  };

  const CATPolyVolumeOrbit* _Orbit;
  VolumeOrbitFaceIterator* _Iterator;

  friend class CATPolyDartHelpers;
  template<class DART> friend class VolumeOrbitFaceIteratorImpl;

  template<class DART>
  inline DART* GetDart () const;
};


inline CATPolyVolumeOrbitFaceIterator::CATPolyVolumeOrbitFaceIterator (const CATPolyVolumeOrbit* orbit) :
  _Orbit (0),
  _Iterator (0)
{
  Begin (orbit);
}

inline CATPolyVolumeOrbitFaceIterator::~CATPolyVolumeOrbitFaceIterator ()
{
  _Orbit = 0;
  delete _Iterator;
  _Iterator = 0;
}

inline CATPolyVolumeOrbitFaceIterator& CATPolyVolumeOrbitFaceIterator::Begin ()
{
  return Begin (_Orbit);
}

inline CATPolyVolumeOrbitFaceIterator& CATPolyVolumeOrbitFaceIterator::Begin (const CATPolyVolumeOrbit& orbit)
{
  return Begin (&orbit);
}

inline bool CATPolyVolumeOrbitFaceIterator::End () const
{
  return _Iterator ? _Iterator->End () : true;
}

inline CATPolyVolumeOrbitFaceIterator& CATPolyVolumeOrbitFaceIterator::operator++ ()
{
  if (_Iterator)
    ++(*_Iterator);
  return *this;
}

inline CATPolyFace* CATPolyVolumeOrbitFaceIterator::operator* () const
{
  return _Iterator ? _Iterator->GetFace () : 0;
}

inline CATPolyFace* CATPolyVolumeOrbitFaceIterator::GetFace () const
{
  return _Iterator ? _Iterator->GetFace () : 0;
}

inline int CATPolyVolumeOrbitFaceIterator::GetFaceOrientation () const
{
  return _Iterator ? _Iterator->GetFaceOrientation () : 0;
}

inline Poly::OrbitQualifier CATPolyVolumeOrbitFaceIterator::GetQualifier () const
{
  return _Orbit ? _Orbit->GetQualifier () : Poly::NoQualifier;
}

inline CATPolyVolume* CATPolyVolumeOrbitFaceIterator::GetAdjacentVolume () const
{
  return _Iterator ? _Iterator->GetAdjacentVolume () : 0;
}

template<class DART>
inline DART* CATPolyVolumeOrbitFaceIterator::GetDart () const
{
  return _Iterator && _Iterator->Dimension () == DART::Dimension () ? (DART*)_Iterator->GetDart () : 0;
}
