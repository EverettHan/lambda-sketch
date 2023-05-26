// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateBiRailSweep :
// Declaration of global functions used to create and destroy
// an instance of the GeneralizedSweep Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// April 98  Creation                          JBX
//=============================================================================
#ifndef CreateBiRailSweep_H 
#define CreateBiRailSweep_H 

#include "FrFAdvancedOpeSur.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATBiRailSweep;
class CATFrFCompositeCurve;

ExportedByFrFAdvancedOpeSur
CATBiRailSweep * CreateBiRailSweep(CATGeoFactory * ifactory,
                                   CATFrFCompositeCurve** iGuide,
                                   CATFrFCompositeCurve* iProfile,
                                   CATSkillValue iMode = BASIC);

ExportedByFrFAdvancedOpeSur
CATBiRailSweep * CreateBiRailSweep (CATGeoFactory *iFactory,
                                    CATFrFCompositeCurve** iGuides,
                                    CATFrFCompositeCurve* iProfile,
                                    int iPositionType= 1,
                                    CATSkillValue iMode = BASIC);


ExportedByFrFAdvancedOpeSur
CATBiRailSweep * CreateBiRailSweep(CATBiRailSweep* iSweepOp,
                                   CATSkillValue iMode = BASIC);

ExportedByFrFAdvancedOpeSur
void Remove( CATBiRailSweep *&ioGeneralizedSweep );

#endif


