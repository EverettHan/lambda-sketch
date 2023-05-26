// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySwapOper.h
// Header definition of CATPolySwapOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// February 2005  Creation: NDO
//===================================================================
#ifndef CATPolySwapOper_H
#define CATPolySwapOper_H

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"

#include "CATListOfInt.h"


/**
 * This operator finds the triangles from the mesh that are not included on an input list.
 */
class ExportedByCATPolyAnalyzeOperators CATPolySwapOper : public CATPolyAnalyzeOper
{

public :

  /**
   * Constructor
   */
  CATPolySwapOper (CATIPolyMesh* iPolyMesh);

  /**
   * Destructor
   */
  virtual ~CATPolySwapOper ();

  /**
   * Given a list of triangles, find the triangles from the mesh that are not on the list of triangles.
   * @return
   *   S_OK if the method runs successfully and E_FAIL otherwise.
   */
  HRESULT SwapTriangles (const CATListOfInt& iTriangles, CATListOfInt& oSwapTriangles) const;

};

#endif

