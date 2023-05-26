// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateCanonicProfileSweep :
// Create Sweep Operator with CanonicProfile Profile.
//
// Declaration of global functions used to create and destroy
// an instance of the GeneralizedSweep Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Sept 98  Creation                           C.Pradal (CPL)
// 19/11/14 NLD Mise au propre et parametrisation du type de profil
//              (suppression des valeurs en dur, puis des valeurs par defaut)
//=============================================================================
#ifndef CreateCanonicProfileSweep_H
#define CreateCanonicProfileSweep_H

#include "FrFAdvancedOpeSur.h"
#include "CATSkillValue.h"

#include "CATCanonicProfileSweep.h"

class CATGeoFactory;
class CATGeometry;
class CATCanonicProfileSweep;
class CATFrFCompositeCurve;
//
// ProfileType==1 : Segment  Sweep
// ProfileType==2 : Circle   Sweep
// ProfileType==3 : Conic    Sweep
// ProfileType==4 : Interpol Sweep
// ProfileType==5 : Blend    Sweep 
// ------------
//
//  A1, A2: Angle Laws
//  R1, R2: Length Laws
//  R: Radius Law
//  LG, MG, FG: Limit, Middle, Functional Guide
//  LS, MS, FS: Limit, Middle, Functional Surface
//
//  Slope (Curve: LG+FG or Surface: LG on Surface or LG+ RefElt)
// Sweep Segment :
// ProfileType==1 
// -------------
//
//          R2         R1
// Case 1: <--*-----*----->   2 Limit Guides
// ------     L2    L1        2 Length Laws
//
//
//           R2  LG  R1
// Case 2:  <-----*----->      1 Limit Guide + 1 Functional Guide
// ------        A \           2 Length Laws + 1 Angle Law
//                  *FG
//
//
//
// Case 3:   LG    MG
// ------     *-----*-----      1 Limit Guide + 1 Middle Guide
//
//
//           R2  LG  R1
// Case 4:  <-----*----->      1 Limit Guide (PCurve)
// ------       |---|S         2 Length Laws +
//                A            1 Angle Law(% Surface Reference)
//
//
//
// Sweep Circle:
// ProfileType==2 
// ------------
//
//
// Case 1: *-----*-----*     3 Limit Guides
// ------  L1    L2    L3    No Laws
//
//
//
// Case 2:  *----------*      2 Limit Guides
// ------   L1    \    L2     1 Radius Law
//                 R
//
// Case 3:     A1 *
// ------     *  / \           1 Middle Guide + 1 Functional Guide
//            | /A2 \          2 Angular Laws
//            *------*
//
//
// Case 4:     ------          1 Middle Guide
// ------     |  R|  |         1 Radius Law
//            |   *  |
//             ______
//
//
//           A1  MG  A2
// Case 5:  <-----*----->      1 Middle Guide
// ------       |---|S         2 Angle Laws (% Surface Reference)
//                R            1 Radius Law
//
//
//
//
// Sweep Conic:
// ProfileType==3 
// ------------
//
//
// Case 1:   5 Limit Guides
// ------    No Laws
//
//
// Case 2:   4 Limit Guides
// ------    1 Slope
//         
//
// Case 3:   3 Limit Guides
// ------    2 Slopes
//       
//
// Case 4:   2 Limit Guides  
// ------    2 Slopes  
//           1 Rho Law
//         
// Sweep Interpol:
// ProfileType==4 
// ------------
// Test Uniquement
//
// Sweep Blend:
// ProfileType==5 
// ------------
//            A1        A2
//         G1 /---------\ G2  
// Case 1:   *           *   
//          |--|S1       |--|S2
//           R             R 
//
//           2 Limit Guides  
//           2 Slopes  
//           2 Length Laws
//
//
ExportedByFrFAdvancedOpeSur 
CATCanonicProfileSweep * CreateCanonicProfileSweep(CATGeoFactory         * iFactory           ,
                                                   CATFrFCompositeCurve  * iMasterGuide       ,
                                                   CATLONG32               iProfileType       , // = CATCanonicProfileSweep::C_P_Sweep_Seg // NLD191114 = 1,
                                                   CATFrFCompositeCurve ** iLimitGuides       = 0,
                                                   CATLONG32               iNbLimitGuides     = 0,
                                                   CATFrFCompositeCurve  * iMiddleGuide       = 0,
                                                   CATFrFCompositeCurve  * iFunctionalGuides  = 0,
                                                   CATGeometry          ** iLimitSurfaces     = 0,
                                                   CATLONG32               iNbLimitSurfaces   = 0,
                                                   CATGeometry           * iMiddleSurface     = 0,
                                                   CATGeometry           * iFunctionalSurface = 0,
                                                   CATSkillValue           iMode              = BASIC);

// Only for Sweep Conic (initially)
// (but generalized to Interpol Seep and Blend Sweep)
ExportedByFrFAdvancedOpeSur
CATCanonicProfileSweep * CreateCanonicProfileSweep(CATGeoFactory         * iFactory           ,
                                                   CATFrFCompositeCurve  * iMasterGuide       ,
                                                   CATLONG32               iProfileType       , // = CATCanonicProfileSweep::C_P_Sweep_Conic, // NLD191114 = 3,
                                                   CATFrFCompositeCurve ** iLimitGuides       = 0,
                                                   CATLONG32               iNbLimitGuides     = 0,
                                                   CATSkillValue           iMode              = BASIC);

// Copy Constructor (not recommended)
ExportedByFrFAdvancedOpeSur
CATCanonicProfileSweep * CreateCanonicProfileSweep(CATCanonicProfileSweep* iSweepOp           ,
                                                   CATSkillValue           iMode              = BASIC);

ExportedByFrFAdvancedOpeSur
void                     Remove                   (CATCanonicProfileSweep*&ioSweepOp          );



#endif


