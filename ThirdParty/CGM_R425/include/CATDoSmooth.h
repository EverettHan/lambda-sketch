/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 1998
 
 DESCRIPTION : Smoothify method
               Assemble two wires thanks to a third wire tangent to others

=============================================================================
*/
#ifndef CATDoSmooth_H
#define CATDoSmooth_H

#include "Parallel.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATBody;
class CATPointOnCurve;
class CATCGMJournalList;
class CATSoftwareConfiguration;
class CATTopData;


ExportedByParallel
void CATDoSmoothTgts(CATGeoFactory * Builder, CATTopData * iData, CATBody * TangentBody,
               CATBody * Support1, CATBody * PtCrv1, 
               CATBody * Support2, CATBody * PtCrv2, CATBody * & SmoothBody,CATLONG32 iTrimFirst=1,CATLONG32 iTrimLast=1);

#endif
