//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2013
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 2013-05-13 - T6L : Creation
//==============================================================================================================


#ifndef CATExpIntersectionPredicates_H
#define CATExpIntersectionPredicates_H

#include "CATExpIntersectionPoint.h"

#include <vector>
#include <deque>
#include <cstddef>
#include <initializer_list>

#if defined(__CATExpIntersectionPredicates)
#define ExportedByCATExpIntersectionPredicates DSYExport
#else
#define ExportedByCATExpIntersectionPredicates DSYImport
#endif
#include "DSYExport.h"

class CATExpIntersectOptions
{
public:
  CATExpIntersectOptions()
    : compute_crossings_orientations(false)
    , order_intersections(false)
    , exit_on_degeneracy(false)
    , crossings_on_extremities(false)
    , accurate_estimate(false)
  {}

  bool compute_crossings_orientations;
  bool order_intersections;
  bool exit_on_degeneracy;
  bool crossings_on_extremities;
  bool accurate_estimate;
};

class CATExpObject2D;
class CATExpLazinessControl;

/**
* @return the number of intersections between object1 and the objects,
*   and store in intersection_points some data relative to the intersection points.
* @return -3 if one of the objects is degenerate and exit_on_degeneracy is set.
*   If exit_on_degeneracy is not set, ignore the degenerate objects.
* @return -2 if the computation fails for lack of accuracy (this will not happen if laziness_control.attempt_exact is set to true).
* @return -1 if a degenerate intersection is found (overlap, tangency, multiple point) and exit_on_degeneracy is set.
*   If exit_on_degeneracy is not set, in case of overlap, only end extremities are recorded.
* @pre The input deque of intersection points should be empty.
* @param compute_crossings_orientations asks for computing the intersections' orientations if true.
* @param order_intersections asks for ordering intersections if true.
* @param intersection_points will contain the proper intersection points
*   and degenerate intersection points corresponding to overlapping objects (the end extremities belonging to the other object).
* @param laziness_control asks for attempting computations using dynamic, interval and/or exact arithmetic.
*   and records statistics on the successful levels of computations.
* @param crossings_on_extremities asks for computing the intersections' orientations on extremities.
*/
int ExportedByCATExpIntersectionPredicates CATExpIntersect(const CATExpObject2D& object1, const std::vector<CATExpObject2D*>& objects, CATExpIntersectOptions const& iOptions,
  CATExpLazinessControl& laziness_control, std::deque<CATExpIntersectionPoint>& intersection_points);

int ExportedByCATExpIntersectionPredicates CATExpIntersect(const std::vector<CATExpObject2D*>& objects, CATExpIntersectOptions const& iOptions, CATExpLazinessControl& laziness_control, 
  std::vector<std::deque<CATExpIntersectionPoint> >& intersection_points);

/**
* Compute the intersections between objects1 and objects2, but neither inside objects1 nor inside objects2. 
*/
int ExportedByCATExpIntersectionPredicates CATExpIntersect(const std::vector< CATExpObject2D*>& objects1, const std::vector< CATExpObject2D*>& objects2,
  CATExpIntersectOptions const& iOptions, CATExpLazinessControl& laziness_control,
  std::vector<std::deque<CATExpIntersectionPoint> >& intersection_points1,
  std::vector<std::deque<CATExpIntersectionPoint> >& intersection_points2);

/**
* @warning The intersection points pt1 and pt2 may be invalid (if they do not exist).
* If there is only 1 intersection point, it is recorded in pt1.
*/
int ExportedByCATExpIntersectionPredicates CATExpIntersect(const CATExpObject2D& object1, const CATExpObject2D& object2,
  CATExpIntersectOptions const& iOptions, CATExpLazinessControl& laziness_control, CATExpIntersectionPoint& pt1, CATExpIntersectionPoint& pt2);

/**
* Compute the intersections between the pair of objects
*/
int ExportedByCATExpIntersectionPredicates CATExpIntersect(const std::initializer_list<std::pair<CATExpObject2D const*, CATExpObject2D const*>>& objects,
  CATExpIntersectOptions const& iOptions, CATExpLazinessControl& laziness_control, std::vector<CATExpIntersectionPoint>& intersection_points);

/**
* Checks whether pt1 lies before pt2 on the given arc / segment.
* @pre pt1 and pt2 lie on the given arc / segment.
* @warning This is a rough check not using exact arithmetic. Should be used only for debug.
*/
bool ExportedByCATExpIntersectionPredicates CheckOrder(const CATExpIntersectionPoint &pt1, const CATExpIntersectionPoint &pt2, const CATExpObject2D &object);

bool ExportedByCATExpIntersectionPredicates CheckOrder 
  (const std::deque<CATExpIntersectionPoint> &points, const CATExpObject2D &object);

inline int CATExpIntersect(
  const CATExpObject2D& object1, const std::vector<CATExpObject2D*>& objects,
  bool compute_crossings_orientations, bool order_intersections, bool exit_on_degeneracy,
  CATExpLazinessControl& laziness_control, std::deque<CATExpIntersectionPoint>& intersection_points,
  bool crossings_on_extremities = true)
{
  CATExpIntersectOptions options;
  options.compute_crossings_orientations = compute_crossings_orientations;
  options.order_intersections = order_intersections;
  options.exit_on_degeneracy = exit_on_degeneracy;
  options.crossings_on_extremities = crossings_on_extremities;
  options.accurate_estimate = true;
  return CATExpIntersect(object1, objects, options, laziness_control, intersection_points);
}

inline int CATExpIntersect(
  const std::vector<CATExpObject2D*>& objects,
  bool compute_crossings_orientations, bool order_intersections, bool exit_on_degeneracy,
  CATExpLazinessControl& laziness_control, std::vector<std::deque<CATExpIntersectionPoint> >& intersection_points,
  bool crossings_on_extremities = true)
{
  CATExpIntersectOptions options;
  options.compute_crossings_orientations = compute_crossings_orientations;
  options.order_intersections = order_intersections;
  options.exit_on_degeneracy = exit_on_degeneracy;
  options.crossings_on_extremities = crossings_on_extremities;
  options.accurate_estimate = true;
  return CATExpIntersect(objects, options, laziness_control, intersection_points);
}

inline int CATExpIntersect(
  const std::vector< CATExpObject2D*>& objects1, const std::vector< CATExpObject2D*>& objects2,
  bool compute_crossings_orientations, bool order_intersections, bool exit_on_degeneracy,
  CATExpLazinessControl& laziness_control,
  std::vector<std::deque<CATExpIntersectionPoint> >& intersection_points1,
  std::vector<std::deque<CATExpIntersectionPoint> >& intersection_points2,
  bool crossings_on_extremities = true)
{
  CATExpIntersectOptions options;
  options.compute_crossings_orientations = compute_crossings_orientations;
  options.order_intersections = order_intersections;
  options.exit_on_degeneracy = exit_on_degeneracy;
  options.crossings_on_extremities = crossings_on_extremities;
  options.accurate_estimate = true;
  return CATExpIntersect(objects1, objects2, options, laziness_control, intersection_points1, intersection_points2);
}

inline int CATExpIntersect(const CATExpObject2D& object1, const CATExpObject2D& object2,
  bool compute_crossings_orientations, bool order_intersections, bool exit_on_degeneracy,
  CATExpLazinessControl& laziness_control,
  CATExpIntersectionPoint& pt1, CATExpIntersectionPoint& pt2,
  bool crossings_on_extremities = true)
{
  CATExpIntersectOptions options;
  options.compute_crossings_orientations = compute_crossings_orientations;
  options.order_intersections = order_intersections;
  options.exit_on_degeneracy = exit_on_degeneracy;
  options.crossings_on_extremities = crossings_on_extremities;
  options.accurate_estimate = true;
  return CATExpIntersect(object1, object2, options, laziness_control, pt1, pt2);
}

#endif 
