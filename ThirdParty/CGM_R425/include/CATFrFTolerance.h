// COPYRIGHT DASSAULT SYSTEMES 2006
//==========================================================================
//
// CATFrFTolerance:
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// 07/12/06 JSX Creation
// 09/02/17 NLD Programmation plus correcte et perenne, a iso-fonctionnement, de Epsl_C_Sq_Fun()
//==========================================================================
//
#ifndef CATFrFTolerance_H
#define CATFrFTolerance_H
//
//#include "FrFObjects.h"
#include "CATCGMVirtual.h"
#include "CATDataType.h"


class CATGeoFactory;
class CATTolerance;
#include "CATTolerance.h"
#include "CATGetTolerance.h"

// Les Epsilons a la sauce FreeForm
//===================================
// i => iepsilon / g => epsg  / l => LargeEpsg  
// L Length      / R Relative / A Angle / C courbure
// Sq=Square  SqR=SquareRoot

//#define TESTTEST(f) (CATGetTolerance(f).EpsilonForLengthTest())
//#define TESTTEST2 TESTTEST(_Factory)
// Proportionel au scale
#define Epsi_L     Epsi_L_func()         //  1e-15  *scl
#define Epsg_L     Epsg_L_func()         //  1e-12  *scl
#define Epsl_L     Epsl_L_func()         //  1e-06  *scl
#define Epsi_L_Sq  Epsi_L_Sq_func()      //  1e-30  *scl*scl
#define Epsg_L_Sq  Epsg_L_Sq_func()      //  1e-24  *scl*scl
#define Epsl_L_Sq  Epsl_L_Sq_func()      //  1e-12  *scl*scl
#define Epsi_L_SqR Epsi_L_SqR_func()     //  sqrt(1e-15) *sqrt(scl)
#define Epsg_L_SqR Epsg_L_SqR_func()     //  1e-6        *sqrt(scl)

// Relatif ( independant du scale )
#define Epsi_R     Epsi_R_func()         //  1e-15  
#define Epsg_R     Epsg_R_func()         //  1e-12  
#define Epsl_R Epsl_R_func()             //  1e-06  
#define Epsi_R_Sq  Epsi_R_Sq_func()      //  1e-30  
#define Epsg_R_Sq  Epsg_R_Sq_func()      //  1e-24
#define Epsl_R_Sq  Epsl_R_Sq_func()      //  1e-12
#define Epsi_R_SqR Epsi_R_SqR_func()     //  sqrt(1e-15)
#define Epsg_R_SqR Epsg_R_SqR_func()     //  1e-06
                                           
// Comparaison Angulaire ( independant du scale )
#define Epsi_A     Epsi_A_func()         //  1e-15   
#define Epsg_A     Epsg_A_func()         //  1e-12  
#define Epsl_A     Epsl_A_func()         //  1e-06  
#define Epsi_A_Sq  Epsi_A_Sq_func()      //  1e-30  
#define Epsg_A_Sq  Epsg_A_Sq_func()      //  1e-24  
#define Epsi_A_SqR Epsi_A_SqR_func()     //  sqrt(1e-15)
#define Epsg_A_SqR Epsg_A_SqR_func()     //  1e-06

// Special pour la courbure ( inversement proportionel au scale )
#define Epsg_C     Epsg_C_func()        //  1e-12 /scl
#define Epsl_C_Sq  Epsl_C_Sq_Fun()      //  1e-12 /(scl*scl)
 
// Acces au scale pour les cas moins courants
#define FrFFactoryScale FrFFactoryScale_func()


#ifdef FACTORY_NAME
#undef FACTORY_NAME
#endif

#ifndef TOLERANCE_NAME
#define FRF_TOLERANCE_NAME (CATGetTolerance(FACTORY_NAME))
#else
#define FRF_TOLERANCE_NAME TOLERANCE_NAME
#endif
//#define FACTORY_NAME _Factory

#define   Epsi_L_func()     (FRF_TOLERANCE_NAME.EpsilonForLengthTest())
#define   Epsg_L_func()     (FRF_TOLERANCE_NAME.EpsgForLengthTest())
#define   Epsl_L_func()     (FRF_TOLERANCE_NAME.LargeEpsgForLengthTest())
#define   Epsi_L_Sq_func()  (FRF_TOLERANCE_NAME.EpsilonForSquareLengthTest())
#define   Epsg_L_Sq_func()  (FRF_TOLERANCE_NAME.EpsgForSquareLengthTest())
#define   Epsl_L_Sq_func()  (FRF_TOLERANCE_NAME.LargeEpsgForLengthTest()* FRF_TOLERANCE_NAME.LargeEpsgForLengthTest() )
#define   Epsi_L_SqR_func() (FRF_TOLERANCE_NAME.EpsilonForSqrtLengthTest())
#define   Epsg_L_SqR_func() (FRF_TOLERANCE_NAME.EpsgForSqrtLengthTest())

#define   Epsi_R_func()     (FRF_TOLERANCE_NAME.EpsilonForRelativeTest())
#define   Epsg_R_func()     (FRF_TOLERANCE_NAME.EpsgForRelativeTest())
#define   Epsl_R_func()     (FRF_TOLERANCE_NAME.LargeEpsgForAngleTest()) // ! Utilisation de la methode sur les angles, LargeEpsgForRelativeTest n'existe pas
#define   Epsi_R_Sq_func()  (FRF_TOLERANCE_NAME.SquareEpsilonForRelativeTest())
#define   Epsg_R_Sq_func()  (FRF_TOLERANCE_NAME.SquareEpsgForRelativeTest())
#define   Epsl_R_Sq_func()  (FRF_TOLERANCE_NAME.EpsgForRelativeTest())   // SquareLargeEpsgForRelativeTest n'existe pas
#define   Epsi_R_SqR_func() (FRF_TOLERANCE_NAME.SqrtEpsilonForRelativeTest())
#define   Epsg_R_SqR_func() (FRF_TOLERANCE_NAME.SqrtEpsgForRelativeTest())

#define   Epsi_A_func()     (FRF_TOLERANCE_NAME.EpsilonForAngleTest())
#define   Epsg_A_func()     (FRF_TOLERANCE_NAME.EpsgForAngleTest())
#define   Epsl_A_func()     (FRF_TOLERANCE_NAME.LargeEpsgForAngleTest())
#define   Epsi_A_Sq_func()  (FRF_TOLERANCE_NAME.EpsilonForSquareAngleTest())
#define   Epsg_A_Sq_func()  (FRF_TOLERANCE_NAME.EpsgForSquareAngleTest())
#define   Epsi_A_SqR_func() (FRF_TOLERANCE_NAME.EpsilonForSqrtAngleTest())
#define   Epsg_A_SqR_func() (FRF_TOLERANCE_NAME.EpsgForSqrtAngleTest())

#define   Epsg_C_func()     (FRF_TOLERANCE_NAME.EpsgForRelativeTest()/FRF_TOLERANCE_NAME.GetScale())
// je modifie la definition historique: on n'est pas DU TOUT cense savoir ici que EpsgForRelativeTest
// est le carre de LargeEpsgForRelativeTest()
// NLD090217
// #define   Epsl_C_Sq_Fun()   (FRF_TOLERANCE_NAME.EpsgForRelativeTest()/FRF_TOLERANCE_NAME.GetSquareScale())
#define   Epsl_C_Sq_Fun()   (FRF_TOLERANCE_NAME.LargeEpsgForRelativeTest()*FRF_TOLERANCE_NAME.LargeEpsgForRelativeTest()/FRF_TOLERANCE_NAME.GetSquareScale())
//
#define   FrFFactoryScale_func()  (FRF_TOLERANCE_NAME.GetScale())
//
#endif

