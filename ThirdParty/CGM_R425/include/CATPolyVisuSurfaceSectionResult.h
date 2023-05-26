// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuSurfaceSectionResult.h
//
//===================================================================
// March 2016  Creation: JXO
//===================================================================
#ifndef CATPolyVisuSurfaceSectionResult_H
#define CATPolyVisuSurfaceSectionResult_H

#include "PolyVisuClash.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATIAV5Level.h"

class CATPolyBody;
class CATMathTransformation;

class CAT3DRep;
class CAT4x4Matrix;
class CATRepPath;


/**
 * This operator calculates a surface section of a rep given its spatial hierarchy (CATBVHTreeSet) and 
 * returns the result in the form of an observer.
 */
class ExportedByPolyVisuClash CATPolyVisuSurfaceSectionResult

{
public:
  /** Destructor */
  ~CATPolyVisuSurfaceSectionResult();

  /** Get the result as a CAT3DRep
   * @param oId
   *   The Id in the BVHTreeSet of the rep that generated this result
   * @param oResultRep
   *   The result CAT3DRep.
   * @param oPosition
   *   If different from null, the position of the CAT3DRep result.
   * @param oRepPath
   *   The rep path, from the root first operand representation to the rep that generated this result.
   */
  virtual void Result (int oId, CAT3DRep & oResultRep, const CAT4x4Matrix * oPosition, const CATRepPath * oRepPath) = 0;

  /** Get the result as a CATPolyBody
   * @param oId
   *   The Id in the BVHTreeSet of the rep that generated this result
   * @param oPolyBody
   *   The result CATPolyBody.
   *   The reference count must be incremented when keeping a reference.
   * @param oPosition
   *   If different from null, the position of the CATPolyBody result.
   */
  virtual void Result (int oId, CATPolyBody& oPolyBody, const CATMathTransformation* oPosition, const CATRepPath * oRepPath) = 0;

protected:
  /** Constructor */
  CATPolyVisuSurfaceSectionResult();

};
#endif
