// COPYRIGHT DASSAULT SYSTEMES 2004-2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyUtil.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyUtil_h
#define CATPolyUtil_h

#include "CATPolyMiscellaneous.h"
#include "CATListPV.h"
#include "CATLISTP_CATPolyMCurve.h"


class ExportedByCATPolyMiscellaneous CATPolyUtil
{

public:

  /*
   * Releases the objects contained on the list.
   */
  static void ReleaseObjects (CATListPV& ioObjectList);
  static void ReleaseObjects (CATLISTP(CATPolyMCurve)& meshCurves);
  static void ReleaseCATListOfInt (CATListPV& ioListOfIntList);
  static void ReleaseCATListOfDouble (CATListPV& ioListOfDouble );
  static void ReleaseCATMathSetOfPoints (CATListPV& ioListOfPointSet );
  static void ReleaseCATListPtrCATPolyMCurve (CATListPV & listOfMeshCurves);
  static void ReleaseCATPolyPolygon2Ds (CATListPV& ioListOfCATPolyPolygon2Ds);

};

#endif
