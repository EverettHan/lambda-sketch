// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateInterpolCrvToNurbsSur:
// Declaration of global functions used to create and destroy
// an instance of the CATInterpolCrvToNurbsSur  operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Oct. 97     Creation                   DHN
//=============================================================================
#ifndef CreateInterpolCrvToNurbsSur_H
#define CreateInterpolCrvToNurbsSur_H 

class CATGeoFactory;
class CATNurbsCurve;
class CATNurbsSurface;
class CATKnotVector;
class CATInterpolCrvToNurbsSur;

#include "FrFOpeSur.h"
#include "CATDataType.h"
#include "CATSkillValue.h"


ExportedByFrFOpeSur
CATInterpolCrvToNurbsSur* CreateInterpolCrvToNurbsSur( CATGeoFactory  *iFactory,
                                           const CATNurbsCurve **iCurve,
                                           const CATLONG32 &iNbCurves,
                                           CATKnotVector *iKnotVectorLongitudinal,
                                           CATSkillValue iMode = BASIC);

ExportedByFrFOpeSur
void Remove( CATInterpolCrvToNurbsSur *&ioCATInterpolCrvToNurbsSur );



#endif


