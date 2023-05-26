/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 1998
 
 DESCRIPTION : CATGetBoundingWires Operator

=============================================================================
*/
#ifndef CATGetBoundingWires_H
#define CATGetBoundingWires_H

#include "ParallelLight.h"


class CATBody ;
class CATGeoFactory;
class CATTopData;

ExportedByParallelLight int CATGetBoundingWires(CATGeoFactory * CurFacto, CATTopData * iData, CATBody * CurShell, CATBody * & BoundingWires );

#endif
