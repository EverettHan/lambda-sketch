// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceVolumeIterator
//
//=============================================================================
// 2022-08-26 NDO
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"

#include "CATPolyBody.h"  // Poly::OrbitQualifier.


/**
* Iterator through all the volumes incident to a CATPolyFace.
*
* Example:
* \code
* CATPolyFaceVolumeIterator it;
* for (it.Begin (face); !it.End (); ++it)
* {
*   CATPolyVolume* volume = it.GetVolume ();  // Incident volume.
* }
* \endcode
*
*/
class ExportedByPolyMODEL CATPolyFaceVolumeIterator
{

public:

  inline CATPolyFaceVolumeIterator (CATPolyFace* iFace = 0);
  //inline CATPolyFaceVolumeIterator (const CATPolyFaceVolumeIterator& iRHS);
  inline ~CATPolyFaceVolumeIterator ();

public:

  CATPolyFaceVolumeIterator& Begin (CATPolyFace* iFace);
  inline CATPolyFaceVolumeIterator& Begin (CATPolyFace& iFace);
  inline bool End () const;
  inline CATPolyFaceVolumeIterator& operator++ ();

public:

  /**
   * Returns the incident volume.
   */
  inline CATPolyVolume* GetVolume () const;

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

  class FaceVolumeIterator
  {
  public:
    virtual ~FaceVolumeIterator () {}
    virtual void Begin (CATPolyFace& iFace) = 0;
    virtual bool End () const = 0;
    virtual void operator++ () = 0;
    virtual CATPolyVolume* GetVolume () const = 0;
    virtual int GetFaceOrientation () const = 0;
    virtual Poly::OrbitQualifier GetQualifier () const = 0;

    //virtual FaceVolumeIterator* Clone () const = 0;
  };

  FaceVolumeIterator* _Iterator;

  template<class DART> friend class FaceVolumeIteratorImpl;
};


inline CATPolyFaceVolumeIterator::CATPolyFaceVolumeIterator (CATPolyFace* iFace) :
  _Iterator (0)
{
  Begin (iFace);
}

//inline CATPolyFaceVolumeIterator::CATPolyFaceVolumeIterator (const CATPolyFaceVolumeIterator& iRHS) :
  //_Iterator (0)
//{
  //if (iRHS._Iterator)
    //_Iterator = iRHS._Iterator->Clone ();
//}

inline CATPolyFaceVolumeIterator::~CATPolyFaceVolumeIterator ()
{
  delete _Iterator;
  _Iterator = 0;
}

inline CATPolyFaceVolumeIterator& CATPolyFaceVolumeIterator::Begin (CATPolyFace& iFace)
{
  return Begin (&iFace);
}

inline bool CATPolyFaceVolumeIterator::End () const
{
  return _Iterator ? _Iterator->End () : true;
}

inline CATPolyFaceVolumeIterator& CATPolyFaceVolumeIterator::operator++ ()
{
  if (_Iterator)
    ++(*_Iterator);
  return *this;
}

inline CATPolyVolume* CATPolyFaceVolumeIterator::GetVolume () const
{
  return _Iterator ? _Iterator->GetVolume () : 0;
}

inline int CATPolyFaceVolumeIterator::GetFaceOrientation () const
{
  return _Iterator ? _Iterator->GetFaceOrientation () : 0;
}

inline Poly::OrbitQualifier CATPolyFaceVolumeIterator::GetQualifier () const
{
  return _Iterator ? _Iterator->GetQualifier () : Poly::NoQualifier;
}
