//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATPolyBodySurfaceNormalsChecker
//
// Check if the normal layer of the CATIPolySurfaces is coherent with the 
//       triangles orientations
//
//=============================================================================
// 2016-06-27 JXO: New.
//=============================================================================
#ifndef CATPolyBodySurfaceNormalsChecker_H
#define CATPolyBodySurfaceNormalsChecker_H

#include "PolyBodyBVHOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATTolerance.h"

class CATPolyBody;
class CATPolyFace;
class CATPolyBodyGeoCheckerObserver;


/**
 * This class checks each face of a CATPolyBody, looks for the normal layer, and if set looks to see if vertex normals
 * are coherent with the triangle normals.
 */
class ExportedByPolyBodyBVHOperators CATPolyBodySurfaceNormalsChecker
{
public:
  /**
   * Checks each face of a CATPolyBody, looks for the normal layer, and if set looks to see if vertex normals
   * are coherent with the triangle normals.
   * To check a single mesh, see CATPolyMeshNormalsChecker.
   * @param iBody
   *        Body to check
   * @param pObserver
   *        Optional observer to get the not valid faces
   */
  static HRESULT Check(const CATPolyBody & iBody, CATPolyBodyGeoCheckerObserver * pObserver = 0);

protected:
  CATPolyBodySurfaceNormalsChecker ();
  ~CATPolyBodySurfaceNormalsChecker ();
};


#endif // !CATPolyBodySurfaceNormalsChecker_H
