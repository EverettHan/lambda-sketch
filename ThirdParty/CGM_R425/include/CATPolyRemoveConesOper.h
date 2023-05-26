// COPYRIGHT Dassault Systemes 2004, all rights reserved
//===================================================================
//
// CATPolyRemoveConesOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  jun 2004 Creation: dhp
//===================================================================
#ifndef CATPolyRemoveConesOper_h
#define CATPolyRemoveConesOper_h

#include "CATPolyRegularizeOperators.h"
#include "CATPolyModOper.h"
#include "CATBooleanDef.h"

class CATIPolyMesh;
class CATPolyRefineMap;


class ExportedByCATPolyRegularizeOperators CATPolyRemoveConesOper : public CATPolyModOper
{

public :

  CATPolyRemoveConesOper (CATIPolyMesh * polyMesh);

  ~CATPolyRemoveConesOper (void);

  HRESULT Run (void);

  int GetNumRemovedCones (void) const;

private :

  CATBoolean RemoveCones (const int vertex);

  int _numRemovedCones;

};

#endif
