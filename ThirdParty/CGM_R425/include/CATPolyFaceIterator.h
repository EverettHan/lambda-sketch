// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceIterator
//
//=============================================================================
// 2022-11-03 JXO
//=============================================================================

#pragma once
#include "PolyMODEL.h"
#include "CATPolyCellOrbit.h"

class CATPolyFace;
class CATIPolySurface;


class ExportedByPolyMODEL CATPolyFaceIterator
{
public:

  virtual CATPolyFaceIterator& Begin () = 0;
  virtual bool End () const = 0;
  virtual CATPolyFaceIterator& operator++ () = 0;

public:

  virtual CATPolyFace* Get () const = 0;
  virtual CATIPolySurface* GetSurface () const = 0;
  virtual int GetFaceOrientation() const = 0;
  virtual Poly::OrbitQualifier GetQualifier() const = 0;  // Returns the volume-orbit qualifier.

public:

  CATPolyFaceIterator();
  virtual ~CATPolyFaceIterator();

};
