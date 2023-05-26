// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyVolumeFaceIterator
//
//=============================================================================
// 2022-08-29 NDO
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"

#include "CATPolyCellOrbit.h"  // Poly::OrbitQualifier


/**
* Iterates through all the faces of a CATPolyVolume.
*
* Example:
* \code
* CATPolyVolumeFaceIterator it;
* for (it.Begin (volume); !it.End (); ++it)
* {
*   CATPolyFace* F = it.GetFace ();
* }
* \endcode
*
*/
class ExportedByPolyMODEL CATPolyVolumeFaceIterator
{

public:

  inline CATPolyVolumeFaceIterator (CATPolyVolume* iVolume = 0);
  inline ~CATPolyVolumeFaceIterator ();

public:

  CATPolyVolumeFaceIterator& Begin (CATPolyVolume* iVolume);
  inline CATPolyVolumeFaceIterator& Begin (CATPolyVolume& iVolume);
  inline bool End () const;
  inline CATPolyVolumeFaceIterator& operator++ ();

public:

  /**
   * Returns the face.  The iterator cycles though the faces once and only once.
   */
  CATPolyFace* GetFace () const;

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

  class VolumeFaceIterator
  {
  public:
    virtual ~VolumeFaceIterator () {}
    virtual void Begin (CATPolyVolume& iVolume) = 0;
    virtual bool End () const = 0;
    virtual void operator++ () = 0;
    virtual CATPolyFace* GetFace () const = 0;
    virtual int GetFaceOrientation () const = 0;
    virtual Poly::OrbitQualifier GetQualifier () const = 0;

    //virtual VolumeFaceIterator* Clone () const = 0;
  };

  VolumeFaceIterator* _Iterator;

  template<class DART> friend class VolumeFaceIteratorImpl;
};

inline CATPolyVolumeFaceIterator::CATPolyVolumeFaceIterator (CATPolyVolume* iVolume) :
  _Iterator (0)
{
  Begin (iVolume);
}

inline CATPolyVolumeFaceIterator::~CATPolyVolumeFaceIterator ()
{
  delete _Iterator;
  _Iterator = 0;
}

inline CATPolyVolumeFaceIterator& CATPolyVolumeFaceIterator::Begin (CATPolyVolume& iVolume)
{
  return Begin (&iVolume);
}

inline bool CATPolyVolumeFaceIterator::End () const
{
  return _Iterator ? _Iterator->End () : true;
}

inline CATPolyVolumeFaceIterator& CATPolyVolumeFaceIterator::operator++ ()
{
  if (_Iterator)
    ++(*_Iterator);
  return *this;
}

inline CATPolyFace* CATPolyVolumeFaceIterator::GetFace () const
{
  return _Iterator ? _Iterator->GetFace () : 0;
}

inline int CATPolyVolumeFaceIterator::GetFaceOrientation () const
{
  return _Iterator ? _Iterator->GetFaceOrientation () : 0;
}

inline Poly::OrbitQualifier CATPolyVolumeFaceIterator::GetQualifier () const
{
  return _Iterator ? _Iterator->GetQualifier () : Poly::NoQualifier;
}
