//====================================================================
// Copyright Dassault Systemes Provence 2008, all rights reserved 
//====================================================================
//
//======================================================================
// 22 Juillet  2008 : Creation                                       ANR
//======================================================================
#ifndef CATPolyMeshCopyOper_H
#define CATPolyMeshCopyOper_H
 
#include "CATPolyTrimOperators.h" 

#include "CATIPolyMesh.h" 
#include "CATMathTransformation.h"
#include "CATMath3x3Matrix.h" 
#include "CATMathVector.h"

class ExportedByCATPolyTrimOperators CATPolyMeshCopyOper
{
public:

  //Constructeur
  CATPolyMeshCopyOper();
  
  //Destructeur
  ~CATPolyMeshCopyOper();
  
  void SetPosition(CATMathTransformation *iTransfo) ;

  void ForceComputeVertexRange(CATBoolean iMode) ;

  //Copie des triangles dans un nouveau maillage
  CATBoolean Run(const CATIPolyMesh* iPolyMesh, const CATListOfInt& iFaceIndices, CATIPolyMesh* oNewPolyMesh);
  CATBoolean Run(const CATIPolyMesh* iPolyMesh, CATIPolyMesh* oNewPolyMesh);

  //Suivi d'un vertex
  int GetNewVertex(const int iOldVertexIndex) const;
  int GetOldVertex(const int iNewVertexIndex) const;

  // ajout anr
  int GetOldNumTriangle(const int iNewNumTriangle) const;
private:

  //Allocation du tableau _VerticesMap
  CATBoolean AllocateVerticesMap(const int iSize);
  CATBoolean AllocateMapVertices(const int iSize);


  //-------- Data:
  int* _VerticesMap;
  int _VerticesMapUsedSize, _VerticesMapMaxSize;
  
  int _NbVertices ;
  int* _MapVertices;
  CATMathTransformation *_Transfo ;
  CATMath3x3Matrix _Matrix ;
  CATMathVector _Vector ;  
  CATBoolean _UsePositionMatrix ;
  CATBoolean _ComputeVertexRange ;

  int *_MapNumTriangles ;
};

#endif

