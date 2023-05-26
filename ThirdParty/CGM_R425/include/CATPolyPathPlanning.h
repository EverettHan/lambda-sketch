// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPathPlanning.h
//
//===================================================================
//
// Usage notes: Interface for the path planning operator. It allows to
// find pathes between two points in a polyhedral scene for a
// spherical object with a given radius.
//
//===================================================================
//
// 2012-01-24 XXC: Creation
//===================================================================

#ifndef CATPolyPathPlanning_h
#define CATPolyPathPlanning_h

#include "PolyPathPlanning.h"

#include "CATBIHTree.h"
#include "CATMathPoint.h"

#include "CATListPV.h"

class CATPolyPathPlanningTree;
class CATPolyPathPlanningGraph;
class CATPolyPathPlanningGraphNode;
class CATPolyPathPlanningPath;
class CATBVHTree;

class ExportedByPolyPathPlanning CATPolyPathPlanning
{

public:

  CATPolyPathPlanning();
  ~CATPolyPathPlanning();

  /** Sets the geometry where pathes are to be found.
   *@param iPolyBodies: List containing alternatively a CATPolyBody
   * and a CATMathTransformation giving its position. Thus,
   * iPolyBodies[i] has to be a CATPolyBody if i is odd and a
   * CATMathTransformation if i is even.
   */
  void SetGeometry(const CATListPV & iPolyBodies);

  /** Run the operator to find a path between iStart and iArrival.
   *@param iStart: start point of the path to find
   *@param iArrival: end point of the path to find
   *@param iRadius: the path radius, i.e. the minimum distance between
   *the path and the geometry.
   */
  HRESULT Run(const CATMathPoint & iStart, const CATMathPoint & iArrival, FLOAT iRadius);

  /** When a path has been found between two points, returns this
   *  path.
   */
  INLINE CATPolyPathPlanningPath * GetPath() { return _Path; }

private:

  HRESULT TraceBack(const CATPolyPathPlanningGraphNode * iEndNode, const CATMathPoint & iStart, const CATMathPoint & iEnd);

private:

  CATListPV _PolyBodies;
  CATBIHContent * _Model;
  CATPolyPathPlanningTree * _Graph;
  CATPolyPathPlanningPath * _Path;

};

#endif // CATPolyPathPlanning_h
