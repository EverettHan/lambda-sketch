// COPYRIGHT Dassault Systemes 2003, all rights reserved
//===================================================================
//
// CATPolyModOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyModOper_h
#define CATPolyModOper_h

#include "CATPolyModOperators.h"
#include "CATPolyBaseOper.h"
#include "CATListOfInt.h"
#include "CATLISTP_CATPolyMCurve.h"

class CATIPolyMesh;
class CATPolyTopoUtil;
class CATPolyGeoUtil;
class CATPolyRefineMap;


class ExportedByCATPolyModOperators CATPolyModOper : public CATPolyBaseOper
{

public :

  CATPolyModOper ();

  CATPolyModOper (CATIPolyMesh * polyMesh,
                  CATPolyRefineMap * triangleMap = NULL);

  CATPolyModOper (CATIPolyMesh * polyMesh,
                  const CATListPtrCATPolyMCurve & meshCurves,
                  CATPolyRefineMap * triangleMap = NULL);

  ~CATPolyModOper (void);

  /**
   * Sets the polygonal mesh on which the operation is performed.  
   * @param iMesh
   *   The mesh.
   */
  void SetMesh (CATIPolyMesh* iMesh);
  void SetMesh (CATIPolyMesh* iMesh, CATPolyRefineMap* iRefineMap);

  virtual HRESULT Run (void);

  virtual HRESULT RunOnSelectedTriangles (const CATListOfInt & triangles);

  virtual HRESULT RunOnSelectedVertices (const CATListOfInt & vertices);

protected :

  CATIPolyMesh * _polyMesh;
  CATPolyTopoUtil* _TopoUtil;
  CATPolyGeoUtil* _GeoUtil;
  
  CATPolyRefineMap * _refineMap;

  CATListPtrCATPolyMCurve _meshCurves;

};

#endif

