// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateCrvCrvSweep :
// Declaration of global functions used to create and destroy
// an instance of the GeneralizedSweep Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// June 98  Creation                           C.Pradal (CPL)
//=============================================================================
#ifndef CreateCrvCrvSweep_H 
#define CreateCrvCrvSweep_H 

#include "FrFAdvancedOpeSur.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATCrvCrvSweep;
class CATFrFCompositeCurve;

// First Guide : MasterGuide
// First Profile : MasterProfile
ExportedByFrFAdvancedOpeSur
CATCrvCrvSweep * CreateCrvCrvSweep(CATGeoFactory * ifactory,
                                   CATFrFCompositeCurve** iGuide,
                                   CATLONG32 iNbGuide,
                                   CATFrFCompositeCurve** iProfile,
                                   CATLONG32 iNbProfile,
                                   CATSkillValue iMode = BASIC);

// Copy Constructor
ExportedByFrFAdvancedOpeSur
CATCrvCrvSweep * CreateCrvCrvSweep(CATCrvCrvSweep* iSweepOp,
                                   CATSkillValue iMode = BASIC);

ExportedByFrFAdvancedOpeSur
void Remove( CATCrvCrvSweep *& ioGeneralizedSweep );



#endif


