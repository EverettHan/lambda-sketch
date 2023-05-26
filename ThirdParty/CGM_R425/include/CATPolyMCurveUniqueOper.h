// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMCurveUniqueOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================

#ifndef CATPolyMCurveUniqueOper_h
#define CATPolyMCurveUniqueOper_h

#include "CATPolyMCurveCreateOperators.h"
#include "CATPolyMCurveCreateOper.h"

class CATPolyMCurve;
class CATListPtrCATPolyMCurve;


/**
* This operator is used to find the unique mesh curves in a collection
* of mesh curves. Two mesh curves are considered the same if they have
* the same number of mesh points and all the mesh points are identical.
* Two mesh curves are also identical if a reversed version of one of them
* is the same as the other.
*
* This operator creates mesh curves which must be released by the caller.
*/
class ExportedByCATPolyMCurveCreateOperators CATPolyMCurveUniqueOper : public CATPolyMCurveCreateOper
{

public :

  CATPolyMCurveUniqueOper (void);
  ~CATPolyMCurveUniqueOper (void);

  HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves,
    CATListPtrCATPolyMCurve & newMeshCurves);

};

#endif
