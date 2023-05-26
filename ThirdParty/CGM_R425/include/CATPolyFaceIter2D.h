// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFaceIter2D.h
// Header definition of CATPolyFaceIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2006 Creation: ndo
//===================================================================
#ifndef CATPolyFaceIter2D_H
#define CATPolyFaceIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATBoolean.h"
#include "CATPolyPolygon2D.h"

class CATPolyPolygon2D;
class CATPolyFace2D;
class CATPolyFaceBuckets2D;
template<class> class CATPolyBucket2D;

/**
Iterator.
Iterates through all the faces of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyFaceIter2D
{

public :

  // Construction of an iterator to go through the faces of a CATPolyPolygon2D object. 
  // An option specifies whether to skip the hole faces or not.
  // By default, all faces including hole faces are returned.
  CATPolyFaceIter2D (const CATPolyPolygon2D& iPolygon, const CATBoolean iSkipHoleFaces = /*FALSE*/ TRUE);

  // Reset the operator.
  // ** Wrong default value.  TO DO: change default value from TRUE to FALSE. **
  // (By default, all faces including hole faces are returned.)
  HRESULT Reset (const CATBoolean iSkipHoleFaces = TRUE);

  // Cycle through the next valid face of the CATPolyPolygon2D object.
  CATPolyFace2D* Next ();

public:

  // DEPRECATED. ** DO NOT USE **
  CATPolyFaceIter2D (CATPolyPolygon2D* iPolygon, const CATBoolean iSkipHoleFaces = TRUE);

private :
  // Keep static method for compiler optimizations (see Next implementation)
  static void Reset(CATPolyFaceBuckets2D const& iFaces, CATPolyBucket2D<CATPolyFace2D> *&oBucket, unsigned char &oIndex);
  static CATPolyFace2D& PrivateNext(CATPolyBucket2D<CATPolyFace2D>*& ioBucket, unsigned char& ioIndex);
  static bool IsHoleFace(CATPolyFace2D const&);

  CATPolyFaceBuckets2D* _Faces;
  CATPolyBucket2D<CATPolyFace2D>* _FaceBucket;
  unsigned char _Index;
  bool _SkipHoleFaces;
};

inline CATPolyFaceIter2D::CATPolyFaceIter2D(const CATPolyPolygon2D& iPolygon, const CATBoolean iSkipHoleFaces)
  : _Faces(iPolygon.GetFaceBuckets())
  , _SkipHoleFaces(iSkipHoleFaces)
{
  Reset(*_Faces, _FaceBucket, _Index);
}

inline CATPolyFaceIter2D::CATPolyFaceIter2D(CATPolyPolygon2D* iPolygon, const CATBoolean iSkipHoleFaces)
{
  if (iPolygon)
  {
    _Faces = iPolygon->GetFaceBuckets();
    Reset(*_Faces, _FaceBucket, _Index);
  }
  else
  {
    _Faces = 0;
    _FaceBucket = 0;
  }
  _SkipHoleFaces = iSkipHoleFaces;
}

inline HRESULT CATPolyFaceIter2D::Reset(const CATBoolean iSkipHoleFaces)
{
  if (!_Faces)
    return E_FAIL;

  Reset(*_Faces, _FaceBucket, _Index);
  _SkipHoleFaces = iSkipHoleFaces;
  return S_OK;
}

inline CATPolyFace2D* CATPolyFaceIter2D::Next()
{
  while (1)
  {
    if (!_FaceBucket)
      return 0;
    // Use local stack int enables msvc optimization when _SkipHoleFaces is false
    // Compiler is able to remove useless test !_SkipHoleFaces || IsHoleFace
    CATPolyBucket2D<CATPolyFace2D>* FaceBucket = _FaceBucket;
    unsigned char index = _Index;
    CATPolyFace2D& res = PrivateNext(FaceBucket, index);
    _FaceBucket = FaceBucket;
    _Index = index;
    if (!_SkipHoleFaces || !IsHoleFace(res))
      return &res;
  }
}

#endif
