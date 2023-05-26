#ifndef CATPolyComparMeshMeshComparator_H
#define CATPolyComparMeshMeshComparator_H

//====================================================================
// Copyright Dassault Systemes Provence 2016, All Rights Reserved 
//====================================================================
// DESCRIPTION : Comparateur de Mesh a une tolerance donne
//
//=============================================================================
// HISTORIQUE :
//
//  25/05/2016 : RNO     : Creation !!!
//=============================================================================
#include "ExportedByCATPolyComparOperators.h"
#include "CATMathBox.h"
#include "CATPolyComparErrorTypes.h"
#include "CATPolyComparDistanceMapPoints.h"
#include <memory>
#include <array>
class CATIPolyMesh;

typedef std::array<CATPolyComparDistanceMapPoints<double> *,2> DoubleSampling_t;
class ExportedByCATPolyComparOperators CATPolyComparMeshMeshComparator
{
public:
  virtual ~CATPolyComparMeshMeshComparator();
  
  virtual CATPolyComparErrorTypes Run() =0; 

  //Get The result
  CATPolyComparDistanceMapPoints<double> * GetAtoBPointsAndDistances() const {return m_DistancePoints[0];}
  CATPolyComparDistanceMapPoints<double> * GetBtoAPointsAndDistances() const {return m_DistancePoints[1];}

  void SetZMinZMaxSamplingFilter(const std::array<double,2> &iZminZmax){m_SamplingZFilter.first=true; m_SamplingZFilter.second=iZminZmax;}
  void SetSignedDistanceMode(bool iUseSignedDistance) { m_SignedDistanceMode = iUseSignedDistance; };
  //By default the Sampling is done on the Full Mesh, using the above method, only points inside the set box will be kept
  //void SetSamplingBoxFilter(const CATMathBox & iAASamplingFilter){m_SamplingFilterBox.first=true; m_SamplingFilterBox.second=iAASamplingFilter;}
protected :
  CATPolyComparMeshMeshComparator(const CATIPolyMesh * iFirstMesh, const CATIPolyMesh * iSecondMesh,const std::array<double,2> & SamplingTolOnMeshes);
  bool m_SignedDistanceMode = { false };
  std::array< const CATIPolyMesh *,2> m_Meshes;
  DoubleSampling_t m_DistancePoints;
  std::pair<bool,CATMathBox> m_SamplingFilterBox;
  std::pair<bool,std::array<double,2>> m_SamplingZFilter;

  std::array<double,2> m_MeshesSamplingTol;
};


#endif // CATPolyComparMeshMeshComparator_H
