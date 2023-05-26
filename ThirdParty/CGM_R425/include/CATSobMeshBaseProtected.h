//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
// CATSobMeshBaseProtected : 
// Attention ces methodes ne doivent etre utilisees que par les fw de Subdivision 
// Pas par les Clients 
//
//====================================================================
//
// Usage notes:
//
//====================================================================
// Dec  , 2022 : MPS  : Industrialisation proto RJY1 
// April, 2021 : RJY1 : Creation for CATSobMeshBase
//====================================================================
#ifndef CATSobMeshBaseProtected_H
#define CATSobMeshBaseProtected_H

//Pour l'export
#include "CATSobObjects.h"
#include "CATSobVertex.h"
#include "CATBoolean.h"
#include "CATSobVertexTagVertexHashTable.h"


class ExportedByCATSobObjects CATSobMeshBaseProtected
{
public:

  CATSobMeshBaseProtected();

 
  // protected methods of CATSobMeshBase
  
  void SetTagOnVertex(CATSobVertex* iVertex, const unsigned int iTagForVertex, const CATBoolean iIsNewVertex);
  void SetTagOnVertex(CATSobVertex* iVertex, const unsigned int iTagForVertex);

  CATBoolean ExistsSubdivMesh() const;
  void SetExistsSubdivMesh(const CATBoolean iExists = TRUE);

  unsigned int ComputeValenceMax();

  void SetAllVertices(CATLISTP(CATSobVertex)& iAllVertices);
  void SetAllEdges(CATLISTP(CATSobEdge)& iAllEdges);

  double* GetSubdivisionBufferForVertex();
  double* GetSubdivisionBufferForEdges(const int iLevel);
  char* GetIndexBufferForVertex();

  void SetSubdivisionBufferForVertex(double* iBufferForVertex);

  void  SetIndexBufferForVertex(char* IndexBuffer);

  void SetSubdivisionBufferForEdges(double* iBufferForEdge);

  //Freeze du mesh
  void SetFreezeMesh(const CATBoolean iMustFreeze);
  CATBoolean IsMeshFrozen() const;

	 
  void SetTopologyChanged(const CATBoolean iTopoChanged);
 

  CATBoolean HasTopologyChanged() const;
  
  CATBoolean HasListeners() const;
  void SetHasListeners(const CATBoolean iHasListener);

  void ResetArraysForSubdivision();

 
  void OpenTopoModifTransaction();

  CATBoolean IsTopoModifTransactionOpen() const;
 
  void SetUseLocalFrame(const CATBoolean iUseLocalFrame);
  
  CATBoolean GetUseLocalFrame() const;
  
 
  virtual ~CATSobMeshBaseProtected();

  unsigned char GetBinaryInfo() const;
  void SetBinaryInfo(unsigned char iBinary);
  unsigned int GetMaxTagForVertices() const;
 
  void SetMaxTagForVertices(unsigned int iMaxTagForVertices);

  CATSobVertex* GetVertexFromTag(const unsigned int iTag) const;

 void  RemoveFromHashTable(int tag);
 void SetTypeMesh(int iType);

protected:
  /////////////////////////////
  //friend CATSobMeshBase;
  ////////////////////////////

  

private:

  CATBoolean _ExistsSubdivMesh;
  unsigned char _BinaryInfos;
  double* _SubdivisionBufferForVertexSubdivision;
  char* _IndexBufferForVertexSubdivision;
  double* _SubdivisionBufferForEdgesSubdivision;
  char _LevelOfSubdivisionBufferForEdges;
  unsigned int _MaxTagForVertices;
  CATSobVertexTagVertexHashTable _VertexTagVertexHashTable;
  CATLISTP(CATSobVertex) _AllVertices;
  CATLISTP(CATSobEdge) _AllEdges;
  int _TypeMesh;
 
};

#endif


