// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPCartesianProduct.h
//
//===================================================================
//
// Usage notes: Abstract description of a space of configurations in
// the nD Path Planning solver, as the cartesian product of many
// topological spaces CATPolyPPTopologicalSpace.
//
//===================================================================
//
// 2013-01-04 XXC: Creation
// 2013-09-12 JXO: Getter for Phoenix
// 2013-09-26 JXO: L2 & C-DIST
// 2013-10-07 JXO: Clamp method
// 2017-01-26 JXO: new GetRandomPosition methods
// 2018-08-10 JXO: Now refcounted.
//===================================================================

#ifndef CATPolyPPCartesianProduct_HH
#define CATPolyPPCartesianProduct_HH

#include "PolyPathPlanning.h"
#include "CATPolyRefCounted.h"
#include "CATMathInline.h"
#include "CATListPV.h"
#include "CATMath.h"
#include "CATErrorDef.h"
#include "CATPolyConcentricIterator.h"

#include "CATCGMSharedPtr.h"

#ifdef _AIX_SOURCE
#undef throw
#undef try
#undef catch
#endif

#include <vector>

#ifdef _AIX_SOURCE
#define throw ERROR
#define try ERROR
#define catch ERROR
#endif

class CATPolyPPTopologicalPoint;
class CATPolyPPTopologicalSpace;
class CATPolyPPPosition;
class CATPolyPPConfigurationDistance;

/** Class designed to represent a space of configurations defined as
 *  the cartesian product of several topological spaces
 *  CATPolyPPTopologicalSpace. Includes basic operations on
 *  configurations such as the distance and interpolation between two
 *  configurations.
 */
class ExportedByPolyPathPlanning CATPolyPPCartesianProduct : public CATPolyRefCounted
{
public:

  /** Constructor of a space by product of many topological spaces.
   * @param iListOfTopoSpaces: the list of topological spaces that, by
   * a cartesian product, define the new larger space.
   * @param pDistance For C-DISP distance or other user defined distances
   */
  CATPolyPPCartesianProduct(CATListPV & iListOfTopoSpaces, CATPolyPPConfigurationDistance * pDistance, bool iDeleteDistanceop = false);

  /**
    Create a new CATPolyPPPosition initialized with the value in iinput
    @param iinput value of the point iinput.size() must be <= to Dimension (if < 0 is put in CATPolyPPPosition[i])
  */
  CATCGMSharedPtr<CATPolyPPPosition > CreatePosition(const std::vector<double> &iinput=std::vector<double>()) const;
  /** Get a random position in the space.
   * @return A uniformly distributed random position in the range space.
   */
  virtual CATPolyPPPosition * GetRandomPosition() const;
  /** Get a random position in the space.
   * @return A uniformly distributed random position in the range
   * space constrained by other limits with a tolerance.
   */
  virtual CATPolyPPPosition * GetRandomPosition(const double ** iLimits, double iTolerance) const;
  /** Get a random position in the neighborhood of a given reference.
   * @return A uniformly distributed random position in the space
   * around iRef. TODO: get be better I suppose.
   */
  virtual CATPolyPPPosition * GetRandomPosition(CATPolyPPPosition * iRef, double iNeighborhood) const;

  /**
   * Get a random position in the sphere crust from a given reference, for the uniform random extractor
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
   */
  virtual CATPolyPPPosition * GetRandomPosition(CATPolyPPPosition * iRef, double iMinimumRadius, double iMaximumRadius, CATPolyConcentricIterator* Iterator, double iRotationMode) const;

  /**
   * Get a position on a sphere of radius  from a given reference, for the uniform random extractor
   * @param iRef
   *        origin of the sphere
   * @param iRadius
   *        Radius of the sphere
   * @param Iterator
   *        iterator of point into the sphere (layer by layer for example)
   * @param iRotationMode
   *        0.  no rotation
   *        0.5 share rotation with translation
   *        1.  expand rotation from translation
   */
  virtual CATPolyPPPosition * GetPosition( CATPolyPPPosition * iRef, double iRadius, CATPolyConcentricIterator* Iterator, double iRotationMode) const;


  /**
   * @return Space dimension (as the sum of every topological space dimension)
   */
  unsigned int Dimension() const;

  /** Computes the distance between two given positions.
   *  It uses the passed CATPolyPPConfigurationDistance if available,
   *  and falls back to L2 distance if not.
   * @param iPosition1 the first position.
   * @param iPosition2 the second position.
   * @param iCDIST if true use the distance operator provided by the user in the constructor CATPolyPPConfigurationDistance
   * @return The distance between iPosition1 and iPosition2.
   */
  /*INLINE*/ double Distance(const CATPolyPPPosition & iPosition1, const CATPolyPPPosition & iPosition2, bool iCDIST = true) const;

  /** Computes the square distance between two given positions.
   *  It uses the passed CATPolyPPConfigurationDistance if available,
   *  and falls back to L2 distance if not.
   * @param iPosition1: the first position.
   * @param iPosition2: the second position.
   * @param iCDIST if true use the distance operator provided by the user in the constructor CATPolyPPConfigurationDistance
   * @return The square distance between iPosition1 and iPosition2.
   */
  double SquareDistance(const CATPolyPPPosition & iPosition1, const CATPolyPPPosition & iPosition2, bool iCDIST = true) const;

  /** Computes the L2 distance between two given positions.
   * @param iPosition1: the first position.
   * @param iPosition2: the second position.
   * @return The distance between iPosition1 and iPosition2.
   */
  INLINE double L2Distance(const CATPolyPPPosition & iPosition1, const CATPolyPPPosition & iPosition2) const;

  /** Computes the square L2 distance between two given positions.
   *  It uses the passed CATPolyPPConfigurationDistance if available,
   *  and falls back to L2 distance if not.
   * @param iPosition1: the first position.
   * @param iPosition2: the second position.
   * @return The square distance between iPosition1 and iPosition2.
   */
  double SquareL2Distance(const CATPolyPPPosition & iPosition1, const CATPolyPPPosition & iPosition2) const;

  /** For particular purpose of nearest neightbor searching, evaluate
   * the square distance of a value to an interval inside the given
   * dimension/subspace. Note: this always uses L2 distance.
   * @param iDim: the index of the dimension/subspace where the
   * interval is defined.
   * @param iRef: the coordinate of a point in the given dimension.
   * @param iInf: inferior limit of the interval.
   * @param iSup: superior limit of the interval.
   * @return The square distance between the value iRef and the
   * interval [iInf;iSup]. Returns 0 if the value is inside the
   * interval.
   */
  double SqDistanceInterval(unsigned int iDim, double iRef, double iInf, double iSup) const;

  /** Interpolation between two positions. Returns iNbSteps positions,
   *  dividing input segment in iNbSteps+1 small segments by inserting
   *  uniformly iNbSteps positions between iPoint1 and iPoint2 (iPoint1
   *  and iPoint2 are not returned in the result). Each returned position
   *  has to be deleted, as the returned array.
   * @param iPoint1: first position of the segment.
   * @param iPoint2: second position of the segment.
   * @param iNbSteps: number of positions to insert between iPoint1 and
   * iPoint2.
   * @return An array of iNbsteps positions pointers.
   */
  virtual CATPolyPPPosition ** Interpolate(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, unsigned int iNbSteps) const;
/**
   * easier Acces to Interpolate(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, unsigned int iNbSteps) const;
  */
  std::vector<CATCGMSharedPtr<CATPolyPPPosition >> Interpolates(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, unsigned int iNbSteps) const;


  /**
   * @brief InterpolateCached same as Interpolate except a cache of positions is used
   *
   * @param iPoint1 first position of the segment.
   * @param iPoint2 second position of the segment.
   * @param iNbSteps number of positions to insert between iPoint1 and iPoint2.
   * @param iPPCache cache of position to perform the interpolation
   *
   */
  void InterpolateCached(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, unsigned int iNbSteps, std::vector< CATPolyPPPosition* >& iPPCache ) const;

  /** Interpolation between two positions. Returns an array of oNbSteps
   *  positions uniformly dividing the input segment in oNbSteps+1 small
   *  segments (iPoint1 and iPoint2 are not returned in the
   *  result). The number oNbSteps of positions is computed internaly as
   *  the minimum number of positions necessary to divide the segment in
   *  uniform segments with length smaller or equal to iDistMax. Each
   *  returned position has to be deleted, as the returned array.
   * @param iPoint1: first position of the segment.
   * @param iPoint2: second position of the segment.
   * @param iDistMax: the maximum length of sub-segments or maximum
   * distance between each couple of successive positions in the returned
   * array.
   * @param oNbSteps: number of positions to insert between iPoint1 and
   * iPoint2.
   * @param iCDIST if true use the distance operator provided by the user in the constructor CATPolyPPConfigurationDistance
   * @return An array of oNbSteps positions pointers.
   */
  virtual CATPolyPPPosition ** Interpolate(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, double iDistMax, unsigned int & oNbSteps, bool iCDIST = true ) const;
  /**
   * easier Acces to CATPolyPPPosition ** Interpolate(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, double iDistMax, unsigned int & oNbSteps, bool iCDIST = true )
  */
  std::vector<CATCGMSharedPtr<CATPolyPPPosition >> Interpolates(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, double iDistMax,  bool iCDIST = true) const;

  /**
   * @brief Computes interpolation step between two positions, same as Interpolate
   *
   * @param iPoint1 first position of the segment.
   * @param iPoint2 second position of the segment.
   * @param iDistMax maximum length of sub-segments or maximum distance between each couple of successive positions in the returned
   * @param iCDIST use user metric or L2 metric
   *
   * @return nb step
   */
  virtual unsigned GetInterpolationStep(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, double iDistMax, bool iCDIST = true ) const;


  /** Interpolation between two positions. Returns a position between
   *  the weighted positions iPoint1 and iPoint2. The weight, in the
   *  range [0;1] is given by iParam. 0 stands for iPoint1, 1 stands
   *  for iPoint2 and any other value stand for the linearly
   *  interpolated position between iPoint1 and iPoint2.
   * @param iPoint1: first position of the segment.
   * @param iPoint2: second position of the segment.
   * @param iParam: the weight for linear interpolation between iPoint1
   * and iPoint2.
   * @return A point linearly interpolated between iPoint1 and iPoint2.
   */
  virtual CATPolyPPPosition * Interpolate(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, double iParam) const;

  INLINE unsigned int IdxSubSpace(int idx) const;
  INLINE unsigned int IdxDim(int idx) const;

  /** Access to the space limits in each dimension. The given box must
   *  be preallocated.
   * @param box: the preallocated box that will be instanciated to the
   * space limits for each dimension. This box must have the following
   * shape : box is an array of size 2 for the minimum and the maximum
   * values in each dimension respectively. Then, box[0] (min values)
   * and box[1] (max values) are both arrays of size Dimension().
   */
  void GetSpaceLimits(double ** box) const;
  
  /**
   * @param iDimension dimension to change limit (index start at 1)
   **/
  HRESULT SetSpaceLimits(unsigned int iDimension, double iMin, double iMax);
  /**
   * @param iDimension dimension to change limit (index start at 1)
   **/
  HRESULT GetSpaceLimits(unsigned int iDimension, double &oMin, double &oMax) const;
  
  /** Clamps given point to the limits of the space */
  HRESULT ClampToLimits(CATPolyPPPosition & ioPoint);

  INLINE const std::vector<CATPolyPPTopologicalSpace*> & GetListOfTopoSpaces() const;

  unsigned int * _DimCorrespondances;
  unsigned int _Dimension;
  std::vector<CATPolyPPTopologicalSpace*> _TopoSpaces;
  CATPolyPPConfigurationDistance * m_pDistance;
  bool _CleanDistanceOper = false;

  /** idxSubSpace begins at 1 */
  const CATPolyPPTopologicalPoint * GetSubPoint(const CATPolyPPPosition & iPoint, int idxSubSpace);

  virtual CATPolyPPCartesianProduct * Clone() const ;

// Change to protected once application has migrated on Release
  
  public:
  virtual ~CATPolyPPCartesianProduct();
};

INLINE unsigned int CATPolyPPCartesianProduct::IdxSubSpace(int idx) const
{
  return _DimCorrespondances[2*idx];
}
INLINE unsigned int CATPolyPPCartesianProduct::IdxDim(int idx) const
{
  return _DimCorrespondances[2*idx+1];
}

INLINE double CATPolyPPCartesianProduct::Distance(const CATPolyPPPosition & iPosition1, const CATPolyPPPosition & iPosition2, bool iCDIST /* = true */) const
{
    return !iCDIST ? CATSqrt(SquareL2Distance(iPosition1, iPosition2)) : CATSqrt(SquareDistance(iPosition1, iPosition2, true));
}

INLINE double CATPolyPPCartesianProduct::L2Distance(const CATPolyPPPosition & iPosition1, const CATPolyPPPosition & iPosition2) const
{
  return CATSqrt(SquareL2Distance(iPosition1, iPosition2));
}

INLINE const std::vector<CATPolyPPTopologicalSpace*> & CATPolyPPCartesianProduct::GetListOfTopoSpaces() const
{
  return _TopoSpaces;
}

#endif
