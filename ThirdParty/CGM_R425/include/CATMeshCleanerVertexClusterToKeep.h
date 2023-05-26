//====================================================================
// Copyright Dassault Systemes Provence 2015 , All Rights Reserved 
//====================================================================
// class CATMeshCleanerVertexClusterToKeep
//
//
//=============================================================================
// HISTORIQUE :
//
// September 2016  ALA creation 
//
//=============================================================================
//
//
//////////////////////////////////////////////////////////////
#ifndef CATMeshCleanerVertexClusterToKeep_h
#define CATMeshCleanerVertexClusterToKeep_h

#include "MathMeshOpe.h"


class  ExportedByMathMeshOpe CATMeshCleanerVertexClusterToKeep
{
public :
  // 
  
  virtual ~CATMeshCleanerVertexClusterToKeep() {};

  virtual void AddVertexToKeep(const int iIndexSurfacicVertex)=0;
  virtual void AddVertexToKeep(const int iIndexSurfacicVertex, const int iIndexVolumicVertex)=0;
  virtual void RemoveVertex(const int iIndexSurfacicVertex)=0;
  virtual bool IsVertexToKeep(const int iIndexSurfacicVertex) const=0;
  virtual int GetSizeMap() const = 0;
  virtual void Clear()=0;

  static CATMeshCleanerVertexClusterToKeep* CreateVertexClusterToKeep();
  //
protected:
  CATMeshCleanerVertexClusterToKeep() {}
  
};

#endif
