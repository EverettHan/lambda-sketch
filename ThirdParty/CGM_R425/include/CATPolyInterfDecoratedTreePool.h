// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfDecoratedTreePool.h
//
//===================================================================
//
// Usage notes: Manage allocation and deallocation of
// CATPolyInterfDecoratedTree's.
//
//===================================================================
//
// 2010-10-18 XXC: Creation
//===================================================================

#ifndef CATPolyInterfDecoratedTreePool_h
#define CATPolyInterfDecoratedTreePool_h

#include "CATMapOfPtrToPtr.h"
#include "CATPolyInterfClashContactOper.h"

class CATPolyInterfDecoratedTree;

class CATPolyInterfDecoratedTreePool {

public:

  CATPolyInterfDecoratedTreePool();
  ~CATPolyInterfDecoratedTreePool();

  CATPolyInterfDecoratedTree * GetTree(CATBVHTree  &ioTree, int iInputId,
                                       CATPolyInterfClashContactOper::AccuracyChooser * ioAccuracyChooser,
                                       const CATTolerance & iTol,
                                       const CATMathTransformation * iInitialPos = NULL);

  void FlushAllTrees();

private:

  CATMapOfPtrToPtr _TreePool;
};

#endif // CATPolyInterfDecoratedTreePool_h
