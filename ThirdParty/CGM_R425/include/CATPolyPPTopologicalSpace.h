// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPTopologicalSpace.h
//
//===================================================================
//
// Usage notes: Abstract description of a topological spaces in the nD
// Path Planning solver.
//
//===================================================================
//
// 2013-01-04 XXC: Creation
// 2013-10-07 JXO: Clamp method
// 2017-01-26 JXO: new GetRandomPoint methods
//===================================================================

#ifndef CATPolyPPTopologicalSpace_HH
#define CATPolyPPTopologicalSpace_HH

#include "CATBoolean.h"
#include "PolyPathPlanning.h"
#include "CATMathInline.h"
#include "CATErrorDef.h"
#include "CATPolyConcentricIterator.h"

class CATPolyPPTopologicalPoint;
class CATPolyUniformRandomGenerator;

/**
 * represent a topoligical space of n dimension,
 * this class must be overide to represent 2,3,.. topological space
 * */
class ExportedByPolyPathPlanning CATPolyPPTopologicalSpace
{
public:
  /**
   * construct a topological space of iDimension
   * @param  iDimension
   *    number of dimension of the space
   */
  CATPolyPPTopologicalSpace(unsigned int iDimension);

  /**
   * construct a space by copy
   * @param iOther
   *    space to copy
   * */
  CATPolyPPTopologicalSpace( const CATPolyPPTopologicalSpace& iOther );


  virtual ~CATPolyPPTopologicalSpace();

  INLINE unsigned int Dimension() const { return _Dimension; }

  /**
   * Construct a point with random coordinate in this space
   * */
  virtual CATPolyPPTopologicalPoint * GetRandomPoint() = 0;

  /**
   * Construct a point with random coordinate in some limits and iTolerance in this space
   *
   * @param[in] iMin
   *    array of size Dimension containing the min limit
   * @param[in] iMax
   *    array of size Dimension containing the max limit
   * @param[in] iTolerance
   *    the tolerance allow around iMin,iMax
   * @return a random point in [iMin-iTolerance, iMax+iTolerance]
   */
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const double * iMin, const double * iMax, double iTolerance) = 0;

  /**
   * Construct a point with random coordinate in this space  but int the  Neighborhood of iRef.
   * The distance between iRef and the newpoint will be <=iNeighborhood
   * @param[in] iRef
   *    reference point
   * @param[in] iNeighborhood
   *    distance of Neighborhood
   * */
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iNeighborhood) = 0;

   /**
   * Get a random point in the sphere crust from a given reference, for the uniform random extractor
   * @param iRef
   *        origin of the sphere
   * @param iMinimumRadius
   *        minRadius of the sphere
   * @param iMaximumRadius
   *        maximumRadius of the sphere
   * @param Iterator
   *        iterator of point into the sphere (layer by layer for example)
   * @param iRotationMode
   *        0.  no rotation
   *        0.5 share rotation with translation
   *        1.  expand rotation from translation
   * @param oJequi ?
   * @param v_rotation ?
   */
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iMinimumRadius, double iMaximumRadius, CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation) = 0;
  virtual CATPolyPPTopologicalPoint * GetPoint(const CATPolyPPTopologicalPoint * iRef, double iRadius, CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation) = 0;

  /**
   * operator of distance of this space
   * @param[in] iPoint1
   *    start point
   * @param[in] iPoint2
   *    end point
   * @return the square distance between the 2 point
   * */
  virtual double SqDistance(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2) const = 0;

  virtual double SqDistanceInterval(unsigned int iDim, double iRef, double iInf, double iSup) const = 0;

  /**
   * create  iNbSteps intermediate step between iPoint1 and iPoint2
   * @param[in] iPoint1
   *    start point
   * @param[in] iPoint2
   *    end point
   * @param[in] iNbSteps
   *    number of intermediate point to create
   * @return an array of CATPolyPPTopologicalPoint* of dimension iNbSteps;
   * */
  virtual CATPolyPPTopologicalPoint ** Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, unsigned int iNbSteps);

  /**
   * create point with the interpolation between iPoint1,iPoint2 at param iParam
   * @param[in] iPoint1
   *    start point
   * @param[in] iPoint2
   *    end point
   * @param[in] iParam
   *    position of interpolation between [0,1]
   * @return
   *    point with the interpolated value
   * */
  virtual CATPolyPPTopologicalPoint * Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam) = 0;

  /**
   * modify the ioPoint value with the interpolation between iPoint1,iPoint2 at param iParam
   * @param[in] iPoint1
   *    start point
   * @param[in] iPoint2
   *    end point
   * @param[in] iParam
   *    position of interpolation between [0,1]
   * @param[inout] ioPoint
   *    point modifiy with the interpolated value
   * */
  virtual void Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam, CATPolyPPTopologicalPoint& ioPoint) = 0;


  /**
   * Set the limit of each dimension of the space
   * @param iDimension
   *  index of the dimension
   *  @warning dimension start at 1 not 0
   * @param iMin
   *  The limit min of this dimension
   * @param iMax
   *  The limit max of this dimension
   * */
  virtual HRESULT SetLimits(unsigned int iDimension, double iMin, double iMax);
   /**
   * Get the limit of each dimension of the space
   * @param iDimension
   *  index of the dimension
   *  @warning dimension start at 1 not 0
   * @param oMin
   *  The limit min of this dimension
   * @param oMax
   *  The limit max of this dimension
   * */
  virtual HRESULT GetLimits(unsigned int iDimension, double & oMin, double & oMax);

  /**
   * check if a point is in the limits of this space
   * @param iPoint
   *    The point to check
   * @return true if point is in limits
   * */
  virtual CATBoolean IsInsideLimits(const CATPolyPPTopologicalPoint & iPoint) const;
  /**
   * Clamps given point to the limits of the space
   * @param ioPoint
   *     point to clamp
   * */
  virtual HRESULT ClampToLimits(CATPolyPPTopologicalPoint & ioPoint) const = 0;

  /**
   * duplicate this Space
   * */
  virtual CATPolyPPTopologicalSpace* Clone( CATPolyUniformRandomGenerator & iRandomGenerator ) const = 0;
  virtual CATPolyPPTopologicalSpace* Clone( /*reuse internal generator of cloned element*/ ) const = 0;

protected:
  unsigned int _Dimension; //! Dimension of the space
  double * _Limits[2];     //! Limits of the space limits[0]=MinLimit  limits[1]=MawLimit
  double * _Scales;
};

#endif
