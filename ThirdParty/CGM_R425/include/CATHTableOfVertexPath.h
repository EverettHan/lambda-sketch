// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATHTableOfVertexPath.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// may 2006 Creation: tie
//===================================================================
#ifndef CATHTableOfCATListOfInt_h
#define CATHTableOfCATListOfInt_h

#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"
#include "CATHashTable.h"
#include "CATPolyVertexPathUtil.h"


class ExportedByCATPolyMiscellaneous CATHTableOfVertexPath
{

public :

  CATHTableOfVertexPath (int size);
  ~CATHTableOfVertexPath (void);

  CATBoolean Insert (CATListOfInt * vertexPath);

  CATBoolean Locate (CATListOfInt * vertexPath) const;

  CATBoolean Remove (CATListOfInt * vertexPath);

  CATBoolean RemoveAll (void);

  CATBoolean GetVertexPaths (CATListOfVertexPath & vertexPaths) const;

  CATBoolean GetVertexPathsCopy (CATListOfVertexPath & vertexPaths) const;

private :

  void Clear (void);

  CATHashTable _hashTable;

};

#endif

