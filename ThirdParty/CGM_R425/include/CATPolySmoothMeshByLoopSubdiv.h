#ifndef CATPolySmoothMeshByLoopSubdiv_H
#define CATPolySmoothMeshByLoopSubdiv_H

//===================================================================
// COPYRIGHT Dassault Systemes Provence 2017-2018
//===================================================================
// CATPolySmoothMeshByLoopSubdiv.h 
//===================================================================
//
// Usage notes: 
//
//===================================================================
// HISTORIQUE :
// Oct   2018 : ANR : (deplacement de CATSmgLoopSmoothMesh)
// 17/05/2017 : ANR : Creation 
//===================================================================

#ifndef _AIX_SOURCE

#include "CATSysErrorDef.h" // pour HRESULT
#include "CATListPV.h"
#include "CATMathPoint.h"
#include "CATPolySmoothingOperators.h"

class CATIPolyMesh;
class CATIPolyFactory;

//
class ExportedByCATPolySmoothingOperators CATPolySmoothMeshByLoopSubdiv
{
public:
  CATPolySmoothMeshByLoopSubdiv(CATIPolyMesh *iMesh) ;

  virtual ~CATPolySmoothMeshByLoopSubdiv() ;

  void FreezeBoundaries(CATBoolean iFreeze);

  HRESULT Run(int nIter);

  CATIPolyMesh * GetResult();

private:

  // methods
  CATIPolyMesh* loop_subdivide(CATIPolyMesh * mesh, int nIter) ;
  CATIPolyMesh* loop_subdivide(CATIPolyMesh * mesh) ;

  CATIPolyMesh* clone(CATIPolyMesh * mesh) ;

  void subdivide_interior_edge(CATIPolyMesh * mesh, int  v_tri1[3], int  v_tri2[3],  CATMathPoint& pos);
  void subdivide_boundary_edge(CATIPolyMesh * mesh, int vertex1, int vertex2,  CATMathPoint& pos);

  int CheckAndCleanComponent(CATIPolyMesh *&ioPolygon, CATListPV &oListPolyMesh);

  // members
  CATIPolyMesh *_mMesh;
  CATIPolyMesh *_oMesh;
  CATIPolyFactory* m_factory;

  int _OldNbTriangles, _OldNbVertices;
  int _NewNbTriangles, _NewNbVertices;

  CATListPV _ListOfPolyMesh;

  CATListPV _ListOfSmoothPolyMesh;

  CATBoolean _FreezeBoundaries;
};

#endif // CATPolySmoothMeshByLoopSubdiv_H
#endif
