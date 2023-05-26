// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHPointCloudVisuAttribute.h
//
//===================================================================
// 2020-10-15   XXC : new
//===================================================================
#ifndef CATBVHPointCloudVisuAttribute_H
#define CATBVHPointCloudVisuAttribute_H

#include "PolyVizUtils.h"
// #include "PolyVisuBVH.h"

class CAT4x4Matrix;
class CATRep;
class CAT3DRep;
class CAT3DPointCloudRep;
class CATRepWeakRef;
class CATRepPath;

// System
#include "CATMutex.h"
#include "CATBoolean.h"

#include "CATBVHAttribute.h"

/**
 * Class of attribute to a CATBVHNode which contains a
 * CAT3DPointCloudRep. The CAT3DPointCloudRep lifecycle is not managed
 * inside. This attribute must be deleted before de
 * CAT3DPointCloudRep.
 */
class ExportedByPolyVizUtils CATBVHPointCloudVisuAttribute : public CATBVHAttribute
{
public:

  CATBVHPointCloudVisuAttribute ();
  virtual ~CATBVHPointCloudVisuAttribute ();

public:

  // Casting methods for privileged attributes.
  virtual CATBVHPointCloudVisuAttribute* CastAsPointCloudVisuAttribute () { return this; }
  virtual const CATBVHPointCloudVisuAttribute* CastAsPointCloudVisuAttribute () const { return this; }

public:

  virtual void FlushComputedData();

  // Visu :
  virtual const CATRep * GetRep() const;
  virtual const CAT3DPointCloudRep * GetPointCloudRep() const;
  virtual CAT4x4Matrix * GetMatrix() const;

  void SetRep(const CATRep * PrEP, int PathId = -1);
  // Matrix is addrefed (and released in destructor)
  void SetMatrix(CAT4x4Matrix * pMat);

  /** @nodoc */
  virtual int GetPathId();
  /** @nodoc */
  // Don't delete this reppath
  virtual CATRepPath * GetRepPath();
  /** @nodoc */
  /** Will be deleted by destructor */
  virtual int SetRepPath(CATRepPath * pRepPath);

private:

  CATRepWeakRef *             _WeakRef;
  int                         _RepPathId;
  CAT4x4Matrix *              _Matrix;
  CATRepPath *                _RepPath;
  static CATMutex             _mutData;
};

#endif
