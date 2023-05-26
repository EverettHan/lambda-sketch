// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyNormalizeOper.h
// Header definition of CATPolyNormalizeOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2005  Creation: NDO
//===================================================================
#ifndef CATPolyNormalizeOper_H
#define CATPolyNormalizeOper_H

#include "CATPolyGriddingTools.h"
#include "CATPolyModOper.h"
#include "CATErrorDef.h"

class CATPolyExactArithmetic;
class CATIPolyMesh;
class CATIPolyCurve;
class CATMathBox;


/**
 * This operator normalizes the coordinates of the vertices of the polymesh for its use 
 * by exact arithmetic operators.
 */
class ExportedByCATPolyGriddingTools CATPolyNormalizeOper : public CATPolyModOper
{

public:

  CATPolyNormalizeOper (const CATPolyExactArithmetic& iExactArithmetic);

  /**
   * Destructor
   */
  virtual ~CATPolyNormalizeOper ();

  // Normalize a polymesh.
  HRESULT Normalize (CATIPolyMesh* ioPolyMesh) const;

  // Normalize a polycurve.
  HRESULT Normalize (CATIPolyCurve* ioPolyCurve) const;

  // Normalize the polymesh that has been set into the operator.
  HRESULT Run ();

public:

  // Deprecated.
  CATPolyNormalizeOper (const CATPolyExactArithmetic* iExactArithmetic);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;

};

#endif
