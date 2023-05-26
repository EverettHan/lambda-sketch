// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPathPlanningPath.h
//
//===================================================================
//
// Usage notes: A path resulting from the path planning operator. It
// allows to find pathes between two points in a polyhedral scene for
// a spherical object with a given radius.
// It works as an iterator on the different steps of the path.
//
//===================================================================
//
// 2012-01-24 XXC: Creation
//===================================================================

#ifndef CATPolyPathPlanningPath_h
#define CATPolyPathPlanningPath_h

#include "PolyPathPlanning.h"

#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATMathBox.h"
#include "CATListPV.h"

class CATPolyPathPlanningPathElement {

public:

  CATMathBox _box;
  CATMathPoint _point;

public:

  CATPolyPathPlanningPathElement(const CATMathBox & iBox, const CATMathPoint & iPoint);
  CATPolyPathPlanningPathElement(const CATMathBox & iBox);
  ~CATPolyPathPlanningPathElement();
};

class ExportedByPolyPathPlanning CATPolyPathPlanningPath
{
public:

  CATPolyPathPlanningPath();
  ~CATPolyPathPlanningPath();

  void Begin();
  CATBoolean End() const;
  void operator ++();

  unsigned int Size() const;

  CATMathPoint GetPoint() const;

  /** Returns the box of the cell of the current step in the path. The
   *  box is flat if the iteration is between two volumic cells.
   */
  CATMathBox GetBox() const;

  HRESULT Append(CATPolyPathPlanningPathElement * iElt);

  HRESULT Minimize();

private:

  CATListPV _ListOfCells;
  unsigned int _pos;

};

#endif // CATPolyPathPlanningPath_h
