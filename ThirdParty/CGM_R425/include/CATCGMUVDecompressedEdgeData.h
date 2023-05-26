/*
// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVDecompressedFaceData.cpp
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Feb 2013  Creation NHD
//===================================================================

#ifndef CATCGMUVDecompressedEdgeData_H
#define CATCGMUVDecompressedEdgeData_H

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListOfDouble.h"
#include "CATCGMUVParamSubdivision1D.h"
//#include "CATCGMUVDecompressedMesh.h"

class CATFace;
class CATCGMUVEdgeMeshBuffersItf2;
class CATUVEdgeCacheReader;
class CATPolyIntDoublyLinkedList;

class CATCGMUVDecompressedEdgeData
 // : public CATCGMUVEdgeMeshBuffersItf
{
public:
  inline CATCGMUVDecompressedEdgeData();
  HRESULT Initialize(const CATUVEdgeCacheReader& iMesh,CATEdge* iEdge, CATBoolean iLockMemPool,const CATLONG32& iCreateDummyParams);
  
public :
    //Geometry  
  int GetNbIndices0()const{return _NbIndices0;}

  double* GetParams()const{return _Params;}

  int GetSens()const {return _Sens;}
  void SetSens(int iSens){_Sens=iSens;}  

  double* GetPositionsToUpdate(){return _Positions;}
  double* GetTangentsToUpdate(){return _Tangents;}
    
  const double* GetPositions()const{return _Positions;}
  const double* GetTangents()const{return _Tangents;}
  
  void SetPositions(double* iPositions){_Positions=iPositions;}
  void SetTangents(double* iTangents){_Tangents=iTangents;}
  void AllocatePositionsAndTangents(CATBoolean iWithTangents);
  
  void SetParams(double* iParams, unsigned int iNbParams)
  {
    _NbIndices0=iNbParams;
    _Params = iParams;
  }

  void SetParams(const CATListOfDouble& iParams,const CATPolyIntDoublyLinkedList& iIndexMap);
 
 
public:

  int _Sens;

  int _NbIndices0;


//  CATBoolean _ReleasePosTan;
  double* _Positions;
  double* _Tangents;
  double* _Params;
  CATCGMUVParamSubdivision1D _ParamSubdivision;
 // CATListOfDouble _Params;

public  :
  virtual ~CATCGMUVDecompressedEdgeData();
};

inline 
CATCGMUVDecompressedEdgeData::CATCGMUVDecompressedEdgeData()
{
  _NbIndices0 = 0;
  
  _Positions  = 0;
  _Tangents   = 0;
  _Params     = 0;
}

#endif 


*/
