/* -*-C++-*- */
#ifndef CATCreateCircularBody_H
#define CATCreateCircularBody_H

// COPYRIGHT DASSAULT SYSTEMES  2001

//----------------------------------------------------------------------
//- Software Modifications for Rib-based operators
//----------------------------------------------------------------------
//#include "Ribbon.h"
#include "BONEWOPE.h"
#include "CATMathPoint.h"

class CATBody;
class CATCurve;
class CATPlane;
class CATGeoFactory;
class CATTopData;

/**
 * @nodoc
 */	
ExportedByBONEWOPE CATBody* CATCreateCircularBody(CATGeoFactory * iFactory,
                                                  CATMathPoint  & iCentre,
                                                  CATPlane      * iPlane,
                                                  double          iRadius,
                                                  CATTopData    * iTopData,
                                                  CATBoolean      iNoFreeze=FALSE);

#endif
