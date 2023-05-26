// COPYRIGHT DASSAULT SYSTEMES 1990
//=============================================================================
//
// CATFrFConvertWireToCCV :
// Declaration of global functions used to convert a Wire into a CompositeCurve
//
//=============================================================================
// Usage notes: 
// sample of use :
// to provide
//
//=============================================================================
// 28/10/05 Creation a partir de CreateAToCompositeCurve  JSX
//=============================================================================

#ifndef CATFrFConvertWireToCCV_H
#define CATFrFConvertWireToCCV_H
//
#include <AdvTopoUtil.h>
#include <CATMathDef.h>
#include <CATTopDef.h>
//
class CATGeoFactory;
class CATTopData;
class CATFrFCompositeCurve;
class CATBody;


ExportedByAdvTopoUtil
CATFrFCompositeCurve * CATFrFConvertWireToCCV(CATGeoFactory * iFactory,
                                              CATTopData    * iTopData, 
                                              const CATBody * iBodyWire,
                                              const CATBody * iBodySupport=0);
#endif 
