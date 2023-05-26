// COPYRIGHT Dassault Systemes 2003, all rights reserved
//===================================================================
//
// CATPolyTolerances.h
// Define tolerances for polymeshes.
//
//===================================================================
//
//  sep 2003 Creation: dhp
//===================================================================
#ifndef CATPolyTolerances_H
#define CATPolyTolerances_H

#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"

class CATMathPoint;
class CATMathLine;


// Minimum distance between distinct points.
// CATPolyDistanceEpsilon = 1e-3
extern ExportedByCATPolyMiscellaneous const double CATPolyDistanceEpsilon;

// CATPolyDistanceSquareEpsilon = 1e-6
extern ExportedByCATPolyMiscellaneous const double CATPolyDistanceSquareEpsilon;


/**
* Compares two points.
* @param pnt1
*   The first point.
* @param pnt2
*   The second point.
* @return
*   TRUE if the points are within geometric tolerance of each other and FALSE otherwise.
*/
CATBoolean ExportedByCATPolyMiscellaneous CATPolyComparePoints (const CATMathPoint& pnt1, const CATMathPoint& pnt2);

/**
* Compares a point to a line.
* @param point
*   The point.
* @param line
*   The line.
* @return
*   TRUE if the point is within geometric tolerance to the line and FALSe otherwise.
*/
CATBoolean ExportedByCATPolyMiscellaneous CATPolyComparePointToLine (const CATMathPoint& point, const CATMathLine& line);

#endif
