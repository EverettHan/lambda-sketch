//====================================================================
// Copyright Dassault Systemes Provence 2017 , All Rights Reserved 
//====================================================================

#ifndef CATSurfMeshCleaner_h
#define CATSurfMeshCleaner_h

#include "MathMeshOpe.h"

class CATIPolyMesh;
class CATMeshCleanerVertexClusterToKeep;


class ExportedByMathMeshOpe CATSurfMeshCleaner
{
public:
  
  virtual ~CATSurfMeshCleaner();
  
  virtual void SetMaxBarLength (const double iMaxBarLength)=0;

  //advanced use
  virtual void SetVertexOptim(const double iWithVertexPositionOptim) = 0;

  //Force a stric contol of deviation
  virtual void SetDeviationOnly() = 0;
  
  ////// return 0 if OK
  // virtual int RunEdgeLengthOnly(const bool iCompactMesh = true)=0;

  // return 0 if OK
  virtual int RunEdgeLengthAndChordalError(const double iMeshAccuracy, const bool iCompactMesh = true)=0;

  virtual void SetVertexClusterToKeep(CATMeshCleanerVertexClusterToKeep *ipVertexClusterToKeep) = 0;

  virtual void AddVertexSolution(const int iIndexSurfacicVertex) = 0;

  static CATSurfMeshCleaner* Create(CATIPolyMesh *iMesh);

};

#endif
