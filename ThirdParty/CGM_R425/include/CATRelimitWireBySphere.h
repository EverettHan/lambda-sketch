//===================================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 2002
// 
// DESCRIPTION : Utilitaire pour projection geodesique et parallel 
//               permet de relimiter un wire par une sphere de rayon et centre donnes
//
// oct 02        aov
//===================================================================================

#ifndef CATRelimitWireBySphere_H
#define CATRelimitWireBySphere_H

class CATGeoFactory;
class CATBody;

#include "ParallelLight.h"

ExportedByParallelLight CATBody * RelimitWireBySphere(CATGeoFactory * Facto,
                                                 CATTopData * TopData,
                                                 CATBody * Point,
                                                 CATBody * Wire, 
                                                 double Radius, 
                                                 CATLONG32 interieur=1 /*1 = interieur, 0 = exterieur*/);

#endif


