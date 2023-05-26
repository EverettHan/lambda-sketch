/////////////////////////////////
//
// Creator: G9M 12:11:14
/////////////////////////////////

/** 
* @fullReview D1A G9M 14:11:14 
*/

#ifndef CATVCHullSelector_H
#define CATVCHullSelector_H

#include "CATErrorDef.h" // HRESULT definition on UNIX systems.
#include "CATPolyConvexHullExport.h"
#include "CATIPolyMesh.h"

class CATMathPoint;
class CATVCHullIterator;

//
class ExportedByCATPolyConvexHull CATVCHullSelector
{

public:
  // Based on Input Feed Point
  // Select all HullsOfInterest from a list of hulls & Return a Pointer to PolyMesh/Hull Iterator <-> [for iterating over Hulls of Interest]
  virtual CATVCHullIterator * SelectHull (CATMathPoint &iPoint) = 0;
  // Return all Outermost hulls // No feed point required
  virtual CATVCHullIterator * ReturnAllOuterHulls () = 0;

  virtual HRESULT AddMesh(CATIPolyMesh &iMesh) = 0;

public:
  virtual void Release () = 0;

protected:
  virtual ~CATVCHullSelector ();

};

#endif // !CATVCHullSelector_H
