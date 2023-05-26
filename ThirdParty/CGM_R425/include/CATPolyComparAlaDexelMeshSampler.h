#ifndef CATPolyComparAlaDexelMeshSampler_H_
#define CATPolyComparAlaDexelMeshSampler_H_

//====================================================================
// Copyright Dassault Systemes Provence 2016, All Rights Reserved 
//====================================================================
// DESCRIPTION : Sampling de mesh a la sauce dexel
//
//=============================================================================
// HISTORIQUE :
//
// 31/01/2020 : RNO : For migration purpose i've bypassed the PowderBedSmapler inheritence
// 12/05/2016 : NUA : Fork depuis StockInitializer
//=============================================================================


#include "ExportedByCATPolyComparOperators.h"
#include "CATPolyComparErrorTypes.h"
#include "CATPolyComparDistanceMapPoints.h"
class ListOfTriangles;
class CATIPolyMesh;

//class CATPolyComparDeviceContext;

#include "CATMathOBB.h"
#include "CATMathPoint.h"
#include <vector>
#include <memory>
#include <set>


class ExportedByCATPolyComparOperators CATPolyComparAlaDexelMeshSampler
{
public:

  //
  CATPolyComparAlaDexelMeshSampler(double iTol, CATIPolyMesh * iMesh);
  ~CATPolyComparAlaDexelMeshSampler();


  //override this method to filter some points
  virtual bool IsPointInSamplingZone(const CATMathPoint &p) const { return true; }//No Filtering by Default
  // parameters

  virtual std::vector<CATMathPoint> Sample() const;

  CATPolyComparDistanceMapPoints<double> * SampleForDistanceMapDouble() const;
  CATPolyComparDistanceMapPoints<float> * SampleForDistanceMapFloat() const;

  
protected:

  template<typename T>
  void SampleForDistanceMap(CATPolyComparDistanceMapPoints<T> * oResult) const;

  
private:
  double m_Tol;
  const CATIPolyMesh * m_Mesh;
  std::vector<int> m_TriangleIndices;
  //
  std::set<int> m_VerticesToBeSampled;
  typedef int VertexInd;
  std::set<std::pair<VertexInd, VertexInd> > m_EdgesToBeSampled;

  ///////////////////////
  // methodes utilitaires
  ///////////////////////
  
  // Liste pour chaque block les triangles qui le coupent
  CATPolyComparErrorTypes InitializeTriangleByBlock2 () const;

  // Pour le griddage
  CATPolyComparErrorTypes InitializeShift();

  // pour gridder les points
  CATPolyComparErrorTypes GridSolidPoints() const;

  // Grid un float
  template<int iCoord>
  float GridFloat ( float iFloat )
  {
    *m_pParanoidFload = iFloat + m_Shift[iCoord];
    return ( m_ParanoidFload  - m_ShiftPtr[iCoord]);
  }

  CATMathBox m_BoundingBox;
  CATMathOBB m_OBBox;
  //
  double m_MinBox[3];
  double m_MaxBox[3];
  mutable std::vector< std::vector<int> > m_AllListOfSolidsTriangles;

  
  
  /////////////////////////// pour gridder les points
  float * m_pParanoidFload;
  float m_ParanoidFload;
  
  float * m_ShiftPtr;
  float m_Shift[3];

  unsigned int m_NbDexelBlocks ;
  unsigned int m_NbBlocksXYZ[3][2];
  double m_DeltaByDexelXYZ[3][2];
  

  mutable std::vector<unsigned int> m_MaxTrianglesByBlock;
  mutable std::vector<CATMathPointf> m_SolidsPointsInLocalRep;

  
};

#endif
