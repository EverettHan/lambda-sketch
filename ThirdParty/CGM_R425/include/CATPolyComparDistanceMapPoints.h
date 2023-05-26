#ifndef CATPolyComparDistanceMapPoints_H
#define CATPolyComparDistanceMapPoints_H


//====================================================================
// Copyright Dassault Systemes Provence 2016, All Rights Reserved 
//====================================================================
// DESCRIPTION : Container des points pour la carte de distance
//
//=============================================================================
// HISTORIQUE :
//
//  19/02/2016 : RNO     : Creation !!!
//=============================================================================

#include "CATPolyComparCLASSMACROS.h"
#include "CATPolyComparVec3.h"
#include "ExportedByCATPolyComparOperators.h"
#include "CATPolyComparErrorTypes.h"
#include "CATMathInline.h"
#include <vector>

#include<algorithm>

#include <array>
#include <functional>


//Create a container using Create functions below and Destroy it by Release/AddRef

class ExportedByCATPolyComparOperators PolyComparPointLifeCycle
{
public :
 DISALLOW_COPYCTOR_ASSIGN_AND_MOVE(PolyComparPointLifeCycle)
 INLINE PolyComparPointLifeCycle():INITPolyComparBaseDEVIRTUALISED{};
protected :
 virtual ~PolyComparPointLifeCycle(){}
private:
 DECLAREPolyComparBaseDEVIRTUALISED(PolyComparPointLifeCycle)
};

template<typename TReal>
class ExportedByCATPolyComparOperators CATPolyComparDistanceMapPoints : public PolyComparPointLifeCycle
{
public:
  DISALLOW_COPYCTOR_ASSIGN_AND_MOVE(CATPolyComparDistanceMapPoints)
  typedef CATPolyComparVec3<TReal> DistMapPoint;
  CATPolyComparDistanceMapPoints():PolyComparPointLifeCycle(){};
  
  virtual void Reserve(size_t iSize)=0;
  virtual void Resize(size_t iSize)=0;

  virtual size_t GetNbPoints() const =0;

  // operateur capitaine crochet
  virtual DistMapPoint  & operator [] (const size_t iPos) = 0;
  virtual const DistMapPoint & operator [] (const size_t iPos) const = 0;

  //"Iterators"
  virtual DistMapPoint GetPoint(size_t i) const =0;
  virtual DistMapPoint & GetPoint(size_t i) = 0;//non const
  //Get The distance (possibly signed) for the point to the closest triangle
  virtual TReal GetDistanceMin(size_t i) const =0;
  virtual TReal & GetDistanceMin(size_t i) = 0; //non const
  //Get the triangle the closes triangle position that has realized the minimal distance 
  
  
  //Local Setter
  virtual void SetPointCoord(size_t iPointPos, TReal x, TReal y, TReal z) =0;
  virtual void SetPointCoord(size_t iPointPos, DistMapPoint iCoords) =0;
  virtual void SetDistance(size_t iPointPos, TReal value) =0;

  //Given a Point ID (iPointPos) set the Closest Triangle to this Point (iTrianglePos)
  virtual void SetClosestTrianglePosToPoint(size_t iPointPos, size_t iTrianglePos) =0;
  //Given a Point ID (iPointPos) Return the Closest Triangle to this Point (iTrianglePos)
  virtual size_t GetClosestTriangle(size_t iPointPos) const =0;

  //Massive iterators (Warning pointers are const but data are not)
  virtual const DistMapPoint * GetPointsFrom(size_t iStart) const = 0;
  virtual const TReal * GetDistanceMinsFrom(size_t iStart) const = 0;
  //Get the closest triangle position for each point
  virtual const size_t * GetClosestTrianglesPosFrom(size_t iStart) const = 0;

  //Add Point
  virtual void AddPoint(const DistMapPoint & iPoint) =0;
  virtual void AddPoint(TReal x, TReal y, TReal z)=0;

  bool IsFloatBased() const { return std::is_same<float, TReal>::value;}
  bool IsDoubleBased() const { return std::is_same<double, TReal>::value;}

  //Compute AABB 
  virtual void ComputeAABB(DistMapPoint & oLowCorner,DistMapPoint & oHighCorner) const=0;

  //Sort The Array of Points According To the Given Ordering function
  virtual void SortPoints( const std::function<bool (DistMapPoint & iPi1,DistMapPoint & iP2 )> & Order, bool AllowParallelSort=true) =0;

  //Create structure to receive the Projection Vector associated to the source point (Going From Point to MeshPoint)
  virtual void CreateProjectionVectorField() = 0;
  //Given a Point ID (iPointPos) set the Closest Triangle to this Point (iTrianglePos)
  virtual void SetProjectionVector(size_t iPointPos, CATPolyComparVec3<TReal> && iClosestPoint)=0;
  //Given a Point ID (iPointPos) Return the Closest Point to this Point (iTrianglePos)
  virtual const CATPolyComparVec3<TReal> & GetProjectionVector(size_t iPointPos) const = 0;

  //The Second Fields may be used in Signed Distance Mode
  virtual void CreateSecondDistanceFields() = 0;
  //Given a Point ID (iPointPos) set the Closest Triangle to this Point (iTrianglePos)
  virtual void SetSecondClosestTrianglePosToPoint(size_t iPointPos, size_t iTrianglePos) = 0;
  //Given a Point ID (iPointPos) Return the Closest Triangle to this Point
  virtual size_t GetSecondClosestTriangle(size_t iPointPos) const = 0;
  virtual void SetSecondDistance(size_t iPointPos, TReal value) = 0;
  virtual TReal GetSecondDistance(size_t iPointPos) const = 0 ;


protected:
  virtual ~CATPolyComparDistanceMapPoints(){};

};

ExportedByCATPolyComparOperators
  CATPolyComparDistanceMapPoints<double>* CATPolyComparCreateDistanceMapPointsContainer();

ExportedByCATPolyComparOperators
  CATPolyComparDistanceMapPoints<float>* CATPolyComparCreateDistanceMapPointsContainerf();

#endif // CATPolyComparDistanceMapResult_H

