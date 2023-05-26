// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRemoveDegenerateTrianglesOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2004 Creation: NDO
//===================================================================
#ifndef CATPolyRemoveDegenerateTrianglesOper_h
#define CATPolyRemoveDegenerateTrianglesOper_h

#include "CATPolyRegularizeOperators.h"
#include "CATPolyModOper.h"

#include "CATListOfInt.h"

class CATIPolyMesh;
class CATPolyRefineMap;
class CATPolyExactArithmetic;


class ExportedByCATPolyRegularizeOperators CATPolyRemoveDegenerateTrianglesOper : public CATPolyModOper
{

public :

  CATPolyRemoveDegenerateTrianglesOper (CATPolyExactArithmetic* iExactArithmetic);

  ~CATPolyRemoveDegenerateTrianglesOper (void);

  HRESULT Run (void);

  HRESULT RunOnSelectedTriangles (const CATListOfInt& triangles);

  const CATListOfInt& GetDeletedTriangles () const;
  const CATListOfInt& GetNewTriangles () const;

private :

  CATPolyExactArithmetic* _ExactArithmetic;

  CATListOfInt _DeletedTriangles;
  CATListOfInt _NewTriangles;

  void GetDegenerateTriangles (const CATListOfInt& iTriangles, CATListOfInt & oTriangles) const;

  HRESULT RemoveDegenerateTriangles (const CATListOfInt& iTriangles);

};

#endif

