// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAnalyzeOper.h
//
//===================================================================
// Dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyAnalyzeOper_h
#define CATPolyAnalyzeOper_h

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyBaseOper.h"

class CATIPolyMesh;


class ExportedByCATPolyAnalyzeOperators CATPolyAnalyzeOper : public CATPolyBaseOper
{

public :

  CATPolyAnalyzeOper (void) {_polyMesh = 0;}
  CATPolyAnalyzeOper (const CATIPolyMesh& iMesh) : _polyMesh (&iMesh) {}

  ~CATPolyAnalyzeOper (void) {_polyMesh = 0;}

  /**
   * Sets the polyhedral mesh on which the operation is performed.  
   * @param iMesh
   *   The mesh.
   */
  inline void SetMesh (const CATIPolyMesh* iMesh) {_polyMesh = iMesh;}

public:

  virtual HRESULT Run (void);

public:

  // Deprecated.
  CATPolyAnalyzeOper (CATIPolyMesh* iMesh) : _polyMesh (iMesh) {}

protected :

  const CATIPolyMesh* _polyMesh;

};

#endif
