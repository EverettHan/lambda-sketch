// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMCurveGroupOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================

#ifndef CATPolyMCurveGroupOper_h
#define CATPolyMCurveGroupOper_h

#include "CATIAV5Level.h"
#ifdef CATIAV5R15

#include "CATPolyMCurveCreateOperators.h"
#include "CATPolyMCurveCreateOper.h"

#include "CATBoolean.h"

#include "CATLISTP_CATPolyMCurve.h"

#include "CATListOfInt.h"

class CATPolyMCurve;

/**
* Class used to group a collection of mesh curves together.
*/
class ExportedByCATPolyMCurveCreateOperators CATPolyMCurveGroupOper : public CATPolyMCurveCreateOper
{

public :

  /**
  * Default constructor.
  */
  CATPolyMCurveGroupOper (void);

  /**
  * Destructor.
  */
  ~CATPolyMCurveGroupOper (void);

  /**
  * Separates the list of mesh curves into groups.
  * @param meshCurves
  *   The mesh curves to group.
  * @param newMeshCurves
  *   New mesh curves which have been grouped. It's the responsibility
  *   of the caller to release memory for these curves.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves,
    CATListPtrCATPolyMCurve & newMeshCurves);

private :

  void RemoveContainedMeshCurves (CATListPtrCATPolyMCurve & meshCurves) const;

  int FindMeshCurve (CATPolyMCurve * meshCurve) const;

  int FindUnaddedMeshCurve (void) const;

  CATListPtrCATPolyMCurve _meshCurves;

  CATListOfInt _meshCurveAdded;

};

#endif
#endif
