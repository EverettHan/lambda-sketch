// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFlipNormalOper.h
// Header definition of CATPolyFlipNormalOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2005  Creation: NDO
//===================================================================
#ifndef CATPolyFlipNormalOper_H
#define CATPolyFlipNormalOper_H

#include "CATPolyModOper.h"
#include "CATPolyModOperators.h"


/**
 * This operator flips the normal of all the triangles.
 */
class ExportedByCATPolyModOperators CATPolyFlipNormalOper : public CATPolyModOper
{

public :

  /**
   * Constructor
   */
  CATPolyFlipNormalOper ();

  /**
   * Destructor
   */
  virtual ~CATPolyFlipNormalOper ();

  HRESULT Run ();

};

#endif
