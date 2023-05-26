// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATHTableOfCATPolyMCurve.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATHTableOfCATPolyMCurve_h
#define CATHTableOfCATPolyMCurve_h

#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"

#include "CATHashTable.h"

#include "CATLISTP_CATPolyMCurve.h"

class CATPolyMCurve;

class ExportedByCATPolyMiscellaneous CATHTableOfCATPolyMCurve
{

public :

  CATHTableOfCATPolyMCurve (int size);
  ~CATHTableOfCATPolyMCurve (void);

  CATBoolean Insert (CATPolyMCurve * meshCurve);

  CATBoolean Locate (CATPolyMCurve * meshCurve) const;

  CATBoolean Remove (CATPolyMCurve * meshCurve);

  CATBoolean RemoveAll (void);

  CATBoolean GetMeshCurves (CATListPtrCATPolyMCurve & meshCurves) const;

  // The mesh curves obtained from this map are copied.  They must be released!
  CATBoolean GetMeshCurvesCopy (CATListPtrCATPolyMCurve & meshCurves) const;

private :

  void Clear (void);

  CATHashTable _hashTable;

};

#endif

