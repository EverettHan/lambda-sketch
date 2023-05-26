// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyGetHolesOper.h
// Header definition of CATPolyGetHolesOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// November 2005  Creation: NDO
//===================================================================


// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// PLEASE, SEE ALSO CATPolySurfaceBorderLoopsExtractor.h in PolyhedralObjects\ProtectedInterfaces
// TO USE INSTEAD OF THIS ONE.
// This alternative service manages efficiently tricky configurations with Non Manifold border vertices 
// and leads to a predictable and robust result
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


#ifndef CATPolyGetHolesOper_H
#define CATPolyGetHolesOper_H

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyAnalyzeOper.h"
#include "CATListOfInt.h"
#include "CATListPV.h"

/**
 * This operator extracts the holes from a mesh.
 * It finds the number of holes.  Each hole is represented by a list of vertices (vertex path.)
 * The vertex paths representing the holes are closed (last vertex repeats first vertex)
 * for manifold meshes.  If the mesh is non-manifold, the vertex path may be open and stop at a non-manifold bar.
 */
class ExportedByCATPolyAnalyzeOperators CATPolyGetHolesOper : public CATPolyAnalyzeOper
{

public:

  CATPolyGetHolesOper ();

  virtual ~CATPolyGetHolesOper ();

  /**
   * Runs the operator.
   */
  HRESULT Run ();

  /**
   * Returns the number of holes.
   */
  const int GetNbHoles () const;

  /**
   * Returns the ith hole (between 1 and GetNbHoles () inclusive).
   * The hole is represented by a list of vertices (vertex path.)
   */
  const CATListOfInt& GetHole (const int iHole) const;
  const CATListOfInt* GetHolePtr (const int iHole) const;

private:

  CATListOfInt* ConstructHole (int* flags, const int iTriangle, const int iVertex0, const int iVertex1);
  void CheckAndSplitHole (CATListOfInt* iHole);
  CATListOfInt* SplitHole (CATListOfInt* iHole, const int iVertex);

  CATListPV _Holes;

};

#endif
