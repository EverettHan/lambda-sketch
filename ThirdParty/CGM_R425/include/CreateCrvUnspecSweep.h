// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateCrvUnspecSweep :
// Declaration of global functions used to create and destroy
// an instance of the GeneralizedSweep Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// March 98  Creation                           C.Pradal (CPL)
//=============================================================================
#ifndef CreateCrvUnspecSweep_H
#define CreateCrvUnspecSweep_H

#include "FrFAdvancedOpeSur.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATCrvUnspecSweep;
class CATFrFCompositeCurve;

// Si iPositionType==1, le profil est bien positionne
// Si iPositionType==2, positionnement par intersection entre plan
//   du profil et la guide
// Si iPositionType==3, positionnement automatique:
//   z: normale au plan moyen
//   x: vecteur reliant les points extremites,ou si profile ferme
//      tgte en fin
ExportedByFrFAdvancedOpeSur
CATCrvUnspecSweep * CreateCrvUnspecSweep(CATGeoFactory * ifactory,
                                         CATFrFCompositeCurve* iGuide,
                                         CATFrFCompositeCurve* iProfile,
                                         CATLONG32 iPositionType= 1,
                                         CATSkillValue iMode = BASIC);

ExportedByFrFAdvancedOpeSur
CATCrvUnspecSweep * CreateCanonicCrvUnspecSweep(CATGeoFactory * ifactory,
                                                CATFrFCompositeCurve* iGuide,
                                                CATFrFCompositeCurve* iProfile,
                                                CATLONG32 iPositionType= 1,
                                                CATSkillValue iMode = BASIC);

ExportedByFrFAdvancedOpeSur
CATCrvUnspecSweep * CreateCrvUnspecSweep(CATCrvUnspecSweep* iSweepOp,
                                         CATSkillValue iMode = BASIC);

ExportedByFrFAdvancedOpeSur
void Remove( CATCrvUnspecSweep *&ioGeneralizedSweep );


#endif


