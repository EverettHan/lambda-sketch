#ifndef CATPolyComparManyPointsToMeshDistanceOpe_H
#define CATPolyComparManyPointsToMeshDistanceOpe_H
//====================================================================
// Copyright Dassault Systemes Provence 2011-2016, All Rights Reserved 
//====================================================================
// DESCRIPTION : Projection/Distance de plein de points sur un bon gros maillage
//               using OpenCL !!! (or CUDA si c'est oblige)
//
//=============================================================================
// HISTORIQUE :
//  02/03/2016 : RNO : Remise au gout du jour 
//  23/02/2011 : RNO  : Creation !!!
//=============================================================================
#include "ExportedByCATPolyComparOperators.h"
#include "CATMathBox.h"
//class CATPolyComparKernelManager;
//class CATMathPoint;
#include "CATTolerance.h"
class CATIPolyMesh;
class CATMathOBB;
class CATPolyComparPerfo;
#include "CATPolyComparDistanceMapPoints.h"

//class CATPolyComparDeviceContext;

#undef max
namespace CATPolyComparManyPointsToMeshDistanceOpeNS
{
  const double DefaultMinSquareDistanceFilter = CATGetDefaultTolerance().SquareEpsilonForRelativeTest(); //1.e-8;
  const double DefaultMaxSquareDistanceFilter = std::numeric_limits<double>::max();
};

class ExportedByCATPolyComparOperators CATPolyComparManyPointsToMeshDistanceOpe
{

public:

  //The target Mesh can be set only once
  virtual void SetTargetMesh(const CATIPolyMesh * iTargetMesh) =0;

  //Operator support multi run (Same Mesh with different Points)
  virtual void SetPointsToProject(CATPolyComparDistanceMapPoints<double> * iPointsContainer) =0;
  virtual void SetSignedDistanceMode(bool iNeedSignedDistance) = 0;
  //Pour ne calculer que les carres des distances (default:FALSE), un peu plus rapide
  virtual void SetSquareDistanceMode(bool iSquareDistanceOnly) =0;

  //   SetSquareDistanceFilterThresholds
  //Cette methode permet d'acclererer les calculs quand on a essentiellement besoin de savoir si un point est en dessus ou dessous d'un seuil sans connaitre la distance exacte
  //                   iMinThreshold<= d^2 <= iMaxThreshold ( Attention les seuils sont donnes en distance au carre.)
  // On ne va chercher a connaitre que les vrais distances  dans l'intervalle de distance donnees.
  // Par exemple  :si l'on a deja trouve un triangle a une distance plus proche que iMinThreshold, on va arreter de chercher un second triangle encore plus proche.
  // De meme si l'on sait que les triangles les plus proches sont plus loin que iMaxThreshold on va arreter les calculs.
  //                                            ATTENTION 
  // Pour les points dont la distance d est d^2<iMinThreshold ou d^2>iMaxThreshold :
  //   o La distance obtenue est approchee, 
  //   o le vecteur de projection donne n'est pas forcement le plus proche (correct pour les points iMinThreshold<= d^2 <= iMaxThreshold)
  //   o Le triangle associe n'est pas forcement le plus proche  (correct pour les points iMinThreshold<= d^2 <= iMaxThreshold)
  //   o dans le cas d'un distance signee le signe des distances peut etre faux (correct pour les points iMinThreshold<= d^2 <= iMaxThreshold)
  virtual void SetSquareDistanceFilterThresholds(double iMinThreshold = CATPolyComparManyPointsToMeshDistanceOpeNS::DefaultMinSquareDistanceFilter,
                                                 double iMaxThreshold = CATPolyComparManyPointsToMeshDistanceOpeNS::DefaultMaxSquareDistanceFilter) =0;

  //If Enable the Closest point on the Mesh will be computed and can be retrieve via the PointContainer
  virtual void SetEnableProjectionVectorComputation(bool iComputeProjectionVector) = 0;//!NOT AVAILABLE ON THE GPU


  //Attention par defaut un intervalle de filtrage de [1.e-6,Infini] est applique (cf SetSquareDistanceFilterThresholds)
  virtual CATPolyComparErrorTypes Run() =0;
  
  //// If the Mesh has to be expressed in a special coordinate frame the operator can apply the transformation
  //// (of course if your points are already in this frame)
  //virtual void SetOBB( const CATMathOBB & iOBB)=0;

  //SetCallBack
  //Allow the user to track the computation progress (will be called with the percentage 0<=p<=100)
  // The Callback will be could more or less every 10% (never for short computation)
  //Callback return : 
  // - 0 to continue computation
  // - 1 to break the computation
  virtual void SetCallBack(const std::function<int(double)> iCallBack) = 0;

  virtual void SetSpy(CATPolyComparPerfo* MRSSpy){}
  virtual ~CATPolyComparManyPointsToMeshDistanceOpe(){};
protected :
  
  CATPolyComparManyPointsToMeshDistanceOpe(){};
private:
  //No copy
  CATPolyComparManyPointsToMeshDistanceOpe(const CATPolyComparManyPointsToMeshDistanceOpe &);
  CATPolyComparManyPointsToMeshDistanceOpe & operator =( const CATPolyComparManyPointsToMeshDistanceOpe & iFrom);
};


#endif
