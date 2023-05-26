#ifndef CATTopRevolForGetAngle_H 
#define CATTopRevolForGetAngle_H 

// COPYRIGHT DASSAULT SYSTEMES  2015

//class CATTopRevol;
#include "AdvExtrude.h" // NLD270917 #include "AdvVolSweep.h"
#include "CATTopRevol.h"
//class CATGeoFactory;
//class CATTopData;
//class CATBody;
//class CATMathAxis;
//typedef double CATAngle;


ExportedByAdvExtrude CATTopRevol* CATCreateTopRevolForGetAngles(CATGeoFactory     * iGeoFactory,
                                                                CATTopData        * iData,
                                                                CATBody           * iProfBody,
                                                                CATMathAxis       * iAxis,
                                                                CATAngle            iStartAngle,
                                                                CATAngle            iEndAngle);

#endif
