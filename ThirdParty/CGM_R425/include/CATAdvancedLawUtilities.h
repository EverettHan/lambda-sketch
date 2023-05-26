/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2005
//==========================================================================
//
// CATAdvancedLawUtilities: advanced law utilities for sweep
//
//==========================================================================
// Usage notes: Restricted use for sweep,
//              and for law parameterized on [0.0, 1.0]
//========================================================================== 
// 22/04/05 NLD Creation d'apres le code venant de CATCanonicProfileSweepCx2
// 12/05/10 NLD La software configuration est recue par ExtrapolLaw_Run()
// 21/01/11 NLD Ajout CATAdvancedLawUtilities_NumArcLawForEval()
//              (en provenance de CATFrFSegmentProfileCx2)
// 13/07/11 NLD Ajout CATAdvancedLawUtilities_IsConstantLaw()
// 02/10/20 NLD Suppression extern 'C' inutile
//========================================================================== 

#ifndef CATAdvancedLawUtilities_H
#define CATAdvancedLawUtilities_H
// Module definition for Windows
#include <FrFAdvancedOpeUtil.h>

#include <CATDataType.h> // pour CATLONG32
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATLaw;
class CATSoftwareConfiguration;
class CATFrFMovingFrame;
class CATFrFCoupling;

// <NoUselessExternC_NLD021020> 
// Suppression NLD021020 inutile ici; voir mails IK8/NLD sur exceptions      extern "C"

//--------------------------------------------------------------------------
// Law extrapolation for law to refresh after composite curve extrapolation:
// (initial law domains on reference composite curve,
// law updated to fit new composite curve)
//--------------------------------------------------------------------------
// <NoUselessExternC_NLD021020> extern "C"
ExportedByFrFAdvancedOpeUtil
CATLONG32 ExtrapolLaw_Run(CATGeoFactory           *  iFactory ,
                          CATSoftwareConfiguration*  iConfig  ,
                          CATFrFCompositeCurve    *  iGuideRef,
                          CATFrFCompositeCurve    *  iGuide   ,
                          CATLaw                  *& ioLaw    ) ;

//-----------------------------------------------------------------------------
// Numero d'arc à choisir pour une évaluation de loi (0 si pas d'arc particulier)
//-----------------------------------------------------------------------------
// N.B la tolérance interne utilisée suppose que l'on est sur une loi de sweep de domaine [0.0, 1.0]
// ne dépendant pas du scale
// ATTENTION: Moving frame et Coupling sont obligatoires
// <NoUselessExternC_NLD021020> extern "C"
ExportedByFrFAdvancedOpeUtil
int CATAdvancedLawUtilities_NumArcLawForEval(int                 iCGMLevel   ,
                                             CATLaw           *  iLaw        ,
                                             CATFrFMovingFrame*  iMovingFrame,
                                             CATFrFCoupling   *  iCoupling   ,
                                             double            & ioT         );


//-----------------------------------------------------------------------------
// Une loi est-elle constante?
//-----------------------------------------------------------------------------
// 0 : non constante
// 1 : constante et de type CATConstantLaw
// 2 : constante dans la tolerance
//-----------------------------------------------------------------------------
// <NoUselessExternC_NLD021020> extern "C"
ExportedByFrFAdvancedOpeUtil
int CATAdvancedLawUtilities_IsConstantLaw(CATLaw* iLaw                ,
                                          double  iToleranceOnLawValue);

#endif
