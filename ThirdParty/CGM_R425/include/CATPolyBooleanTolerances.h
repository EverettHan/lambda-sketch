// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanTolerances.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2004 Creation: NDO
//===================================================================
#ifndef CATPolyBooleanTolerances_H
#define CATPolyBooleanTolerances_H

#include "CATPolyBooleanOperators.h"


/*
 * Tolerances use by the boolean operators to filter the constructions and to regularize the result mesh.
 * Tolerances are exported just for the ODTs not for any other use!
 */
class ExportedByCATPolyBooleanOperators CATPolyBooleanTolerances 
{

public:
  
  // Needle tolerance.  A length to test needle triangles.
  // If one bar in a triangle is smaller than this tolerance, the triangle is a needle.
  static const double NeedleTolerance;

  // Cap tolerance.  A length to test cap triangles.
  // If a height in a triangle is smaller than this tolerance, the triangle is a cap.
  static const double CapTolerance;

  // Small angle tolerance.  An angle in radian to test small angle triangles.
  // If one angle in a triangle is smaller than this tolerance, the triangle is a small angle triangle.
  static const double SmallAngleTolerance;

  // Vertex construction tolerance.  
  // A tolerance used to attract constructed points to a vertex. -RXU
  //static const double VertexTolerance;

  // Bar construction tolerance. 
  // A constructed bar point should be within this tolerance to the bar.
  // A tolerance used to attract constructed points to a bar. -RXU
  //static const double BarTolerance;

  // Triangle construction tolerance. 
  // A constructed triangle point should be within this tolerance to the triangle.
  // (Debugging purposes; same as bar tolerance.)
  //static const double TriangleTolerance;

};

#endif

