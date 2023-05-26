// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
//CATSweepUtilities:
// Utility for producing sweep surfaces
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
//
//
//=============================================================================
// 25 02 99 NLD Creation
// 24 05 02 NLD/CCK Ajout ComputePlaneNormalPipe1,2,3
//                  sur du code de NLD
//                  calcul de la viewing direction a la maniere du soft v4
//                  en algorithme de secours pour les spines 3D,
//                  avec ameliorations;
// 01 07 02 NLD Ajout argument iCGMLevel aux methodes ComputePlaneNormalPipe*
// 06 07 06 NLD Ajout ComputeMVDBreaks()
// 01 12 06 NLD Argument optionnel ioConnexionContinuity à CheckSpineContinuity()
#ifndef CATSweepUtilities_H
#define CATSweepUtilities_H
// Module definition for Windows
#include <FrFAdvancedOpeSur.h>

// For interface and Data
#include <CATListOfDouble.h>
class CATFrFCompositeCurve ;
class CATMathVector ;
class CATSoftwareConfiguration;
class CATGeoFactory;
#ifndef NULL
#define NULL 0
#endif
//=============================================================================
// Methods Definition
//=============================================================================
//-----------------------------------------------------------------------------
// Checks if spine continuity is ok for producing sweep
// input:
//  iMode
//   modulo(iMode,10) = 0 : error raised if spine continuity incorrect
//   modulo(iMode,10) = 1 : no error raised
// output:
//  oDiag
//   oDiag = 0  : ok
//   oDiag <> 0 : bad continuity
// optional output:
//   ioConnexionContinuity
//-----------------------------------------------------------------------------
ExportedByFrFAdvancedOpeSur
void CheckSpineContinuity
                          (CATFrFCompositeCurve* iSpine,
                           int&                  oDiag,
                           int                   iMode=0,
                           CATListOfInt* ioConnexionContinuity=0);


// Calcul de normale au plan comme le code V4 de PIPE1
// sur une suite de vecteurs normes reduite
// On fournit eventuellement une solution initiale V0 à valider
// ou a remplacer par la solution calculee à partir des N Vecteurs tangents T[*]
ExportedByFrFAdvancedOpeSur
CATMathVector ComputePlaneNormalPipe1(CATMathVector* T,
                                      int            N,
                                      CATMathVector* V0,
                                      int            iCGMLevel=0);

// Calcul de normale au plan comme le code V4 de Pipe2
// reduction du nombre de vecteurs
// NE vecteurs en entree, NS en sortie
ExportedByFrFAdvancedOpeSur
void ComputePlaneNormalPipe2(CATMathVector* T,
                             int           NE,
                             int&          NS,
                             double        TOL,
                             int           iCGMLevel=0);

// Calcul de normale au plan comme le code V4 de Pipe3
// On fournit eventuellement une solution initiale V0 à valider
// ou a remplacer par la solution calculee à partir des N Vecteurs tangents T[*]
// le nombre de vecteurs et le tableau de vecteurs sont modifies
// Le code est versionné a l'aide de la variable iCGMLevel
ExportedByFrFAdvancedOpeSur
CATMathVector ComputePlaneNormalPipe3(CATMathVector* T,
                                      int&           N,
                                      CATMathVector* V0,
                                      int            iCGMLevel=0);


// Calcul de coupures pour multiple viewing direction
// (rend les parametres ou une coupure serait judicieuse)
ExportedByFrFAdvancedOpeSur
void ComputeMVDBreaks(CATGeoFactory* iFactory,
                      CATSoftwareConfiguration* iConfig,
                      CATFrFCompositeCurve* iSpine,
                      CATListOfDouble&      oBreaks) ;
#endif
