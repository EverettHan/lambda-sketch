/**
 * @level Protected
 * @usage U1
 */
#ifndef CATIAttributServices_h
#define CATIAttributServices_h

#include "ExportedByCATIAEntity.h"
#include <CATIAEntity.h>
#include <CATIAEntityAttribut.h>

ExportedByCATIAEntity int GetListOfAttributes   ( CATIAEntity * const, int &,REFERENCE *& );

ExportedByCATIAEntity int GetListOfPrjAttributes( CATIAEntity * const, int &,REFERENCE *& );

ExportedByCATIAEntity int IsAttributesDefined   ( CATIAEntity * const );

ExportedByCATIAEntity int GetDiscretValues      (  CATIAEntity * const, const string17 , int &, string71 *&);

#endif
