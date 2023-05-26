/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 2000
 
 DESCRIPTION : Smoothify method Check the validity of the result according the specifications

=============================================================================
*/
#ifndef CATCGMSmoothValidation_H
#define CATCGMSmoothValidation_H

#include "ParallelLight.h"


class CATGeoFactory;
class CATBody;

ExportedByParallelLight CATLONG32 SmoothValidation(CATGeoFactory * Builder, CATBody * SmoothBody,CATBody * Support1,CATBody * Support2);


#endif
