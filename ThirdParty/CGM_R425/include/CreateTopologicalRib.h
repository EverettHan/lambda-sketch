// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateTopologicalRib :
// Declaration of global functions used to create and destroy
// an instance of the TopologicalRib operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// December 98  Creation                          JBX
// 12/07/16 Suppression de l'ancien Create sans TopData
//          Rapatriement du Create avec TopData
//=============================================================================
#ifndef CreateTopologicalRib_H 
#define CreateTopologicalRib_H 
//
#include "FrFTopologicalOpe.h"
#include "CATSkillValue.h"
#include "CATGeoToTopOperator.h"
//
class CATTopologicalRib;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATPlane;

//
ExportedByFrFTopologicalOpe
CATTopologicalRib * CreateTopologicalRib (CATGeoFactory     * iFactory,
                                          CATTopData        * iData   ,
                                          CATPlane          * iSupport,
                                          CATBody           * iCurve  );

//
/*
ExportedByFrFTopologicalOpe
CATTopologicalRib * CreateTopologicalRib (CATGeoFactory     * iFactory,
                                          CATPlane          * iSupport,
                                          CATBody           * iCurve,
                                          CATBody           * iTargetBody=0,
                                          CATCGMJournalList * iReport    =0,
                                          CATSkillValue       iMode   = BASIC,
                                          CATBodyFreezeMode  bodyfreezemode=CATBodyFreezeOn);
*/
//
ExportedByFrFTopologicalOpe
void Remove( CATTopologicalRib *&iTopologicalRib );
//
#endif


