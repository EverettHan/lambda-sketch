// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCDSEnums.h
// Header definition of CATCDSEnums
//
//===================================================================
//
// Usage notes:
//  These values are used as result of
//  CATConstraintSolver::GetStatus() methods.
//
//===================================================================
//
//  Sep 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================

#ifndef CATCDSEnums_H
#define CATCDSEnums_H

#include "CATCDSAdvancedEnums.h"
#include "CATCDSArray.h"
#include "CATCDSListP.h"

#include <cstring> // memset

/* Constraint descriptor used in auto-constraining */
class ExportedByCDSInterface CATCSConstraintDescr
{
public:
  CATCSType _type;
  CATCDSBoolean _bLogical;
  CATCSGeometryLeaf *_aArgs[3];
  double _aHelpPoints[3][3];
  double _aHelpParameters[2];
  double _dValue;
  double _dWeight;
  CATCDSBoolean _HasWeight;
  CATCSConstraintDescr() : _dValue(0.), _dWeight(0.), _HasWeight(FALSE) {memset(_aHelpPoints, 0, sizeof(_aHelpPoints)); memset(_aHelpParameters, 0, sizeof(_aHelpParameters));}
};

CATCDSARRAY_DECLARE(CATCSConstraintDescr);
CATCDSLISTP_DECLARE_EXPORTED(CATCDSBoolean, ExportedBySolverInterface);


//-----------------------------------------------------------------------

#endif
