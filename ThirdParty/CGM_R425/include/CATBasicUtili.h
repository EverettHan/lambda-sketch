/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 1998
 
 DESCRIPTION : CATParallelUtili Operator

=============================================================================
*/
#ifndef CATBasicUtili_H
#define CATBasicUtili_H

#include "ParallelLight.h"
#include "CATTopData.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"

class CATBody;
class CATGeoFactory;
class CATWire;
class CATEdge;
class CATTopOperator;


// simplification du body en cours
ExportedByParallelLight
void ParallSimplif(CATGeoFactory * CurFacto, CATTopData * iData, CATLONG32 * Cells, CATBody *& ToSimpl);
// calcul des extremites en (X,Y,Z)

ExportedByParallelLight void GetMathWireExtremity(CATWire * CCV, CATLONG32 iexts,
                     CATMathPoint & PtDeb, CATMathPoint &PtFin);

ExportedByParallelLight void GetMathWireTangent(CATBody * CCVBod, CATLONG32 iext, CATMathVector & VectDeb,CATEdge * & CurEdge);
 
//modif AOV wk 29 2005:ajout option lay down pour empecher simplification dans le CATlayDownWires dans parallele sans clean
ExportedByParallelLight void LayDownForParallel(CATGeoFactory * iFacto, CATTopData * iData,CATBody * iCurve,CATBody * iSupport,
                        CATBody *& oCurveLaid, double iLayToler=0.0, CATBoolean SimplifLayDown=TRUE);

ExportedByParallelLight void BooleanCleanerForParallel(CATGeoFactory * iFacto, CATTopData * iData,CATBody * iSupport, CATTopOperator * iOpe);

#endif
