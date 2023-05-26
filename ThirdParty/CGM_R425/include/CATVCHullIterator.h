/////////////////////////////////
//
// Creator: G9M 12:11:14
/////////////////////////////////

/** 
* @fullReview D1A G9M 14:11:14 
*/

#ifndef CATVCHullIterator_H
#define CATVCHullIterator_H

#include "CATErrorDef.h" // HRESULT definition on UNIX systems.
#include "CATBoolean.h"
#include "CATPolyConvexHullExport.h"

class CATIPolyMesh;

class ExportedByCATPolyConvexHull CATVCHullIterator
{
public:
  virtual void Release() = 0;
public:
  // Sets the iterator to the beginning.
  virtual CATVCHullIterator& Begin () = 0;

  // Returns TRUE if the iterator has reached the end and FALSE otherwise.
  virtual CATBoolean End () const = 0;

public:

  // Increments the iterator to the next valid element.
  virtual CATVCHullIterator& operator++ () = 0;

public:

  /* Don’t release unless explicit AddRef is called on the output CATIPolyMesh */
  // Get() returns 0 if no or invalid Polymesh  (invalid polymesh-> universe/bounding box of the scene)
  virtual CATIPolyMesh* Get () = 0;
  virtual CATIPolyMesh* operator* () = 0;

protected:
  virtual ~CATVCHullIterator ();
};

#endif // /* CATVCHullIterator_H */
