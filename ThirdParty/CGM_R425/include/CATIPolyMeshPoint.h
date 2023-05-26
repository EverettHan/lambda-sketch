// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyMeshPoint.h
//
//===================================================================
// June 2016  Creation NDO
//===================================================================
#pragma once

#include "PolyhedralModel.h"
#include "CATIPolyPoint.h"

class CATIPolyMesh;
class CATPolyMeshPointDef;


/**
 * Interface to a polyhedral mesh-point.
 *
 * A mesh-point is a CATIPolyPoint that lies on a CATIPolyMesh.  
 * Implementations of this interface should be thread-safe for use with the polyhedral operators.
 */
class ExportedByPolyhedralModel CATIPolyMeshPoint : public CATIPolyPoint
{

public:

/** @name Casting Methods.
    @{ */

  /**
   * Casts a CATIPolyCurve into a CATIPolyMeshCurve.
   */
  inline static CATIPolyMeshPoint* Cast (CATIPolyPoint* P);

  /**
   * Casts a const CATIPolyCurve into a const CATIPolyMeshCurve.
   */
  inline static const CATIPolyMeshPoint* Cast (const CATIPolyPoint* P);

/** @} */

public:

  /**
   * Returns the mesh on which the mesh-point is defined.
   */
  virtual const CATIPolyMesh& GetMesh () const = 0;

public:

/** @name Mesh-Point Definition
    @{ */

  /**
   * Returns the definition of the mesh-point.
   * @param oMP
   *   The output definition of the mesh-point.
   */
  virtual HRESULT GetMeshPoint (CATPolyMeshPointDef& oMP) const = 0;

/** @} */

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:

  const CATIPolyMeshPoint* CastToMeshPoint () const;
  CATIPolyMeshPoint* CastToMeshPoint ();

#endif
};

inline CATIPolyMeshPoint* CATIPolyMeshPoint::Cast (CATIPolyPoint* P)
{
  return P ? P->CastToMeshPoint () : 0;
}

inline const CATIPolyMeshPoint* CATIPolyMeshPoint::Cast (const CATIPolyPoint* P)
{
  return P ? P->CastToMeshPoint () : 0;
}
