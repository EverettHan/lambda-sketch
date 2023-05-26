// COPYRIGHT Dassault Systemes 2003, all rights reserved
//===================================================================
//
// CATPolyModOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolySculptOper_h
#define CATPolySculptOper_h

#include "CATPolySculptOperators.h"
#include "CATPolyBaseOper.h"

class CATIPolyMesh;


class ExportedByCATPolySculptOperators CATPolySculptOper : public CATPolyBaseOper
{

public :

  CATPolySculptOper (CATIPolyMesh * polyMesh);

  ~CATPolySculptOper (void);

  virtual HRESULT Run (void);

protected :

  CATIPolyMesh * _polyMesh;

};

#endif
