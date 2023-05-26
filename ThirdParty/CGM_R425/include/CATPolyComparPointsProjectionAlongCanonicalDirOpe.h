#ifndef CATPolyComparPointsProjectionAlongCanonicalDirOpe_h__
#define CATPolyComparPointsProjectionAlongCanonicalDirOpe_h__
//============================================================================================
// Copyright Dassault Systemes Provence 2018, All Rights Reserved
//============================================================================================
//
// CATMASComputeSupportZone.h
//
//============================================================================================
//
// Usage notes : Operator to Compute (FAST) the projection of points 
//               on a Mesh along a canonical direction (X,Y or Z)
//   /!\    The Direction is Unoriented (the projection is done on the line along +Infinity or -Infinity ) 
//
//============================================================================================
// 25/10/2018 : RNO : Creation
//============================================================================================
/*!
 * \class CATPolyComparPointsProjectionAlongCanonicalDirOpe
 *
 * \ingroup GroupName
 *
 * \brief 
 *
 * TODO: Operator to Compute (FAST) the projection of points
 *               on a Mesh along a canonical direction (X,Y or Z)
 *   /!\    The Direction is Unoriented (the projection is done on the line along +Infinity or -Infinity)
 *
 * \note 
 *
 * \author RNO
 *
 * \version 1.0
 *
 * \date October 2018
 *
 * Contact: rno@3DS.com
 *
 */

#include "ExportedByCATPolyComparOperators.h"
#include "CATPolyComparCLASSMACROS.h"
#include "CATTolerance.h"
#include  <deque>
class CATMathPoint;
class CATIPolyMesh;
class CATMathPoint2D;
static const double DefaultMergingTolerance = CATGetDefaultTolerance().GetResolution();
class ExportedByCATPolyComparOperators CATPolyComparPointsProjectionAlongCanonicalDirOpe
{
public:
  DISALLOW_COPYCTOR_ASSIGN_AND_MOVE(CATPolyComparPointsProjectionAlongCanonicalDirOpe);
  /*! Direction of the projection */
  enum Direction
  {
    XDir=0,
    YDir=1,
    ZDir=2
  };
  /*! Direction of the projection */
  enum MeshOverlap
  {
    MeshHasNoOverlapOnThisDir=false,/*! The projection is INJECTIVE (any line parallel to the Direction will meet only ONCE a triangle of the Mesh (FAST)) */
    MeshMayHaveOverlapOnThisDir=true /*! THE PROJECTION WILL NOT BE INJECTIVE (some line may cross several time the mesh (than the projector would give the closest point to the input point (SLOWER)) */ 
  };


  CATPolyComparPointsProjectionAlongCanonicalDirOpe() {};/*! See CATPolyComparCreatePointsProjectionAlongCanonicalDirOpe */
  /*!
   * @method ~CATPolyComparPointsProjectionAlongCanonicalDirOpe
   * @FullMethod CATPolyComparPointsProjectionAlongCanonicalDirOpe::~CATPolyComparPointsProjectionAlongCanonicalDirOpe
   * @access virtual public 
   * @return 
   * @qualifier
   */
   virtual ~CATPolyComparPointsProjectionAlongCanonicalDirOpe() {}
    /*!
     * @method ComputeProjection : Compute the Projection of a point onto the mesh following the canonical direction (thread-safe)
     * @FullMethod CATPolyComparPointsProjectionAlongCanonicalDirOpe::ComputeProjection
     * @access virtual public 
     * @return bool true if the point reach a triangle and has been projected; false if the line in iDir from iPointToProject do not reach a triangle
     * @qualifier const
     * @parameter const CATMathPoint & iPointToProject The point to project
     * @parameter CATMathPoint & oProjectedPoint : The projected point (set if return is true)
     */
     virtual bool ComputeProjection(const CATMathPoint & iPointToProject, CATMathPoint & oProjectedPoint) const =0;


     /*!
      * @method ComputeIntersectionsWithRay : Compute all the intersections of the ray in the canonical direction iDir passing through iRayOrigin (in the ray's  orthoganal plane) 
      * @FullMethod CATPolyComparPointsProjectionAlongCanonicalDirOpe::ComputeIntersectionsWithRay
      * @access virtual public 
      * @return bool
      * @qualifier const
      * @parameter const CATMathPoint2D & iRayOrigin
      * @parameter std::deque<double> & oOrderedRayIntersections : Sorted Interection from iRayOrigin (heighth 0.) to +infinity (aka THE RESULT)
      * @parameter  iFusionTol = 0.001 : Minimal Allowed Interval between two real Layers 
      * @parameter iUseExactPredicates : (availaable from CATIAV5R32 or CATIAR423) a boolean to force the use of a robust point-in-triangle predicates
      */
      virtual bool ComputeIntersectionsWithRay(const CATMathPoint2D & iRayOrigin, std::deque<std::pair<double, int>> & oOrderedRayIntersections, double iFusionTol = DefaultMergingTolerance, bool iUseExactPredicates = false) const =0;
public:
protected:

private:
};

/*!
 * @method CATPolyComparCreatePointsProjectionAlongCanonicalDirOpe : Create an instance of the Operator
 * @FullMethod CATPolyComparCreatePointsProjectionAlongCanonicalDirOpe
 * @access public 
 * @return ExportedByCATPolyComparOperators
CATPolyComparPointsProjectionAlongCanonicalDirOpe *
 * @qualifier
 * @parameter const CATIPolyMesh * iMesh
 * @parameter Direction iDir
 * @parameter MeshOverlap iHasOverlap
 */
 ExportedByCATPolyComparOperators
CATPolyComparPointsProjectionAlongCanonicalDirOpe * CATPolyComparCreatePointsProjectionAlongCanonicalDirOpe(const CATIPolyMesh * iMesh, 
                                                CATPolyComparPointsProjectionAlongCanonicalDirOpe::Direction iDir, 
                                                CATPolyComparPointsProjectionAlongCanonicalDirOpe::MeshOverlap iHasOverlap,
                                                const CATTolerance & iTolerance=CATGetDefaultTolerance());


#endif // CATPolyComparPointsProjectionAlongCanonicalDirOpe_h__
