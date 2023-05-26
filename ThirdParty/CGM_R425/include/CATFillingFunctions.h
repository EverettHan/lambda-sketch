#ifndef CATFillingFunctions_H
#define CATFillingFunctions_H

#include "CATSurfacicTopoOperators.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATShell;
class CATTopFillingTool;
class CATTopFillingReport;
class CATTopFillingInput;

#include "CATFilletReconfigFillFunction.h"
extern "C" ExportedByCATSurfacicTopoOperators CATLONG32 CATC1SingleFaceFilling(CATGeoFactory*         iCreationFactory,
                                                                               CATTopData*            iTopData,
                                                                               CATTopFillingTool*     iFillingTool, 
                                                                               CATBody*               iCreationBody,     
                                                                               CATShell*              iCreationShell,
                                                                               CATTopFillingInput*    iContour,
                                                                               CATTopFillingReport* & oReport        )  ;    
#endif








