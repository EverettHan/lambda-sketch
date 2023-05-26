// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfCATPolyMCurve.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// sep 2004 Creation: dhp
//===================================================================
#ifndef CATMapOfCATPolyMCurve_h
#define CATMapOfCATPolyMCurve_h

#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"

#include "CATHashTable.h"

#include "CATLISTP_CATPolyMCurve.h"
#include "CATListPV.h"

class CATPolyMCurve;

class ExportedByCATPolyMiscellaneous CATMapOfCATPolyMCurve
{

public :

  CATMapOfCATPolyMCurve (int size);
  ~CATMapOfCATPolyMCurve (void);

  CATBoolean Insert (CATPolyMCurve * meshCurve,
    void * value);

  CATBoolean Locate (CATPolyMCurve * meshCurve,
    void *& value) const;

  CATBoolean Locate (CATPolyMCurve * meshCurve) const;

  CATBoolean GetKeysAndValues (CATListPtrCATPolyMCurve & meshCurves,
    CATListPV & values) const;

  int GetNumItems (void) const;

  CATBoolean Remove (CATPolyMCurve * meshCurve,
    void *& value);

  CATBoolean RemoveAll (void);

  CATBoolean RemoveAll (CATListPV & values);

private :

  void Clear (void);

  CATHashTable _hashTable;

};

#endif

