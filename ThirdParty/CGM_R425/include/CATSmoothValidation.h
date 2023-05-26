/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 2000
 
 DESCRIPTION : Smoothify method Check the validity of the result according the specifications

=============================================================================
*/
#ifndef CATSmoothValidation_H
#define CATSmoothValidation_H

#include "CATDataType.h"
#include "Parallel.h"

class CATGeoFactory;
class CATBody;

ExportedByParallel CATLONG32 SmoothValidation(CATGeoFactory * Builder, CATBody * SmoothBody,CATBody * Support1,CATBody * Support2);


#endif
