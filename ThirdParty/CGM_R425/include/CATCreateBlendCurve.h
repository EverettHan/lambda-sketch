// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateBlendCurve :
// Declaration of global functions used to create and destroy
// an instance of the Analytic Blend Curve operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// 09/97  Creation                          Tuan Phung
//=============================================================================
#ifndef CreateBlendCurve_H 
#define CreateBlendCurve_H 

#include "FrFOpeCrv.h"

#include "CATSkillValue.h"

class CATGeoFactory;
class CATCurve;
class CATCrvParam;
class CATBlendCurve;


ExportedByFrFOpeCrv
CATBlendCurve * CATCreateBlendCurve(      CATGeoFactory  *  iFactory  ,
                                    const CATCurve       *  iCurve1   ,
                                    const CATCrvParam     & iCrvParam1,
                                    const CATCurve       *  iCurve2   ,
                                    const CATCrvParam     & iCrvParam2,
                                          CATSkillValue     iMode     = BASIC);

#endif


