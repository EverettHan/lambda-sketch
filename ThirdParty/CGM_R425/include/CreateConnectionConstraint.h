// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CreateConnectionConstraint :
// Declaration of global functions used to create and destroy
// an instance of the Connection Constraint Object
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Aug. 99  Creation                          tpg
//=============================================================================
#ifndef CreateConnectionConstraint_H
#define CreateConnectionConstraint_H

#include "AdvTopoUtil.h"
#include "CATSkillValue.h"
#include "CATFreeFormDef.h"

class CATConnectionConstraint;
class CATVertex;
class CATMathDirection;

//
typedef const char * CATConnectionConstraintClassId;
//
ExportedByAdvTopoUtil CATConnectionConstraint * CreateConnectionConstraint
                     (CATVertex * iVertex,
					  CATFrFContinuity iContinuity = CATFrFPointCont,
					  double iTangentParameter = 1.,
					  double iCurvatureParameter = 1.,
					  double iBinormalParameter = 1.,
					  CATMathDirection * iDirection = 0);

//
ExportedByAdvTopoUtil CATConnectionConstraint * CreateConnectionConstraint
                     (const CATConnectionConstraint* iToCopy);

//
ExportedByAdvTopoUtil void Remove( CATConnectionConstraint *&iConnectionConstraint );

#endif


