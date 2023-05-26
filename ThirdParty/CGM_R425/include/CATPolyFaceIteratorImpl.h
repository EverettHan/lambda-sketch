// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceIteratorImpl
//
//=============================================================================
// 2022-11-03 JXO
//=============================================================================

#ifndef CATPolyFaceIteratorImpl_H
#define CATPolyFaceIteratorImpl_H

#include "PolyMODEL.h"
#include "CATPolyFaceIterator.h"

class CATPolyBody;
class CATPolyFace;
class CATIPolySurface;
class CATPolyVolume;
#include "CATPolyCellOrbit.h"

#include "CATPolyBodyFaceIterator.h"
#include "CATPolyVolumeFaceIterator.h"

class ExportedByPolyMODEL CATPolyFaceIteratorImpl : public CATPolyFaceIterator
{
public:

  CATPolyFaceIteratorImpl(const CATPolyBody* iBody);
  CATPolyFaceIteratorImpl(const CATPolyBody* iBody, const CATPolyVolume* iVolume);
  ~CATPolyFaceIteratorImpl();

  virtual CATPolyFaceIterator& Begin ();
  virtual bool End () const;
  virtual CATPolyFaceIterator& operator++ ();

public:

  virtual CATPolyFace* Get() const;
  virtual CATIPolySurface* GetSurface () const;
  virtual int GetFaceOrientation() const;
  virtual Poly::OrbitQualifier GetQualifier() const;


private:
  const CATPolyBody * m_body;
  const CATPolyVolume * m_volume;
  CATPolyBodyFaceIterator m_biter;
  CATPolyVolumeFaceIterator m_viter;
};

#endif

