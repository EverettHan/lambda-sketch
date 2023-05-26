// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPointToPolyLineDistanceOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyPointToPolyLineDistanceOper_h
#define CATPolyPointToPolyLineDistanceOper_h

#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"
#include "CATMathSetOfPoints.h"

class CATMathPoint;

/**
 * This geometry operator computes the shortest distance from a point to 
 * a polyline in 3d space
 */

class ExportedByCATPolyMiscellaneous CATPolyPointToPolyLineDistanceOper
{

public:

   CATPolyPointToPolyLineDistanceOper (const CATMathSetOfPoints & polyLine);

   ~CATPolyPointToPolyLineDistanceOper (void);

   HRESULT Run (const CATMathPoint &iPoint);

   void GetProjectInfo (double & distance,
     int & segment,
     CATMathPoint & point) const;

   double GetDistance (void) const;

   int GetSegment (void) const;

   CATMathPoint GetPoint (void) const;

private:

  double _distance;
  int _segment;
  CATMathPoint _point;

  int _numPoints;
  CATMathPoint * _points;

};

#endif
