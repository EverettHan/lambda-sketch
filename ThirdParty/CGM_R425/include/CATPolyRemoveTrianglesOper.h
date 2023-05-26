// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRemoveTrianglesOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// January 2022 Creation: GH7
//===================================================================
#ifndef CATPolyRemoveTrianglesOper_h
#define CATPolyRemoveTrianglesOper_h

#include "CATPolyRegularizeOperators.h"
#include "CATPolyModOper.h"
#include "CATPolyTriangleSelector.h"

#include "CATListOfInt.h"
#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"

class CATIPolyMesh;
class CATPolyRefineMap;
class CATPolyExactArithmetic;


/**
 *  @brief Try to remove (by collapse) some triangle of this mesh selected on a user criteria.
 * */
class ExportedByCATPolyRegularizeOperators CATPolyRemoveTrianglesOper : public CATPolyModOper
{

public :
    typedef CATPolyTriangleSelector Selector;
    

  CATPolyRemoveTrianglesOper ();

  ~CATPolyRemoveTrianglesOper (void);

  void SetSelector(Selector::SPtr & iSelector);
  Selector::SPtr GetSelector() const;

  HRESULT Run (void);

  HRESULT RunOnSelectedTriangles (const CATListOfInt& triangles);

  const CATListOfInt& GetDeletedTriangles () const;
  const CATListOfInt& GetNewTriangles () const;

private :

  CATCGMSharedPtr<Selector> _Selector;

  CATListOfInt _DeletedTriangles;
  CATListOfInt _NewTriangles;

  
  HRESULT RemoveSelectedTriangles (const CATListOfInt& iTriangles);

};

#endif

