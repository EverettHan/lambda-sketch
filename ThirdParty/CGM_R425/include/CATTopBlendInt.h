/* -*-C++-*- */
#ifndef CATTopBlendInt_h
#define CATTopBlendInt_h
//=============================================================================
//
//  RESPONSABLE  : J. Saloux
//  
//  DESCRIPTION  : Wire-Wire Blend Operator Implementation
//                 Interface interne : Permet de tester les nouveautes sur un niveau inferieur
//                 au niveau CAA cible
//=============================================================================
//   /12/03 JSX Creation
//   /12/05 JSX Ajout SetDevelopOptions()
// 08/03/16 NLD Smart indent
// 26/04/16 NLD Ajout SetPlanesDetection() et SetCanonicSurfacesDetection()
//=============================================================================
// Implementation du code dans CATTopBlendCx2 (3 lignes )
//=============================================================================
#include "CATTopBlend.h"
class CATMathPoint;
class CATFrFTopologicalSweep;

// Mode supplementaire de coupling
// 1) infos JSX
// - Reste a -1 tant qu'il reste caché
//   CATTopBlendCouplingMode_Develop le remplace avantageusement et de maniere visible
// 2) infos NLD080316
// - Cependant il y a VRAIMENT necessite de le conserver pour le UnStream de vieux CGMReplays
//   (voir CATLoadTopBlend)
//   partout ailleurs je vais m'efforcer d'en supprimer l'utilisation
// - notons aussi que non pas l'identificateur mais explicitement la valeur -1 est encore
//   utilises dans CATGSMBlend au 080316
//   la correction (migration vers CATTopBlendCouplingMode_Develop) y est faite en R419 et R27 mais ni R418 ni R26
#define TopBlendCouplingMode_Develop -1

 
class CATTopBlendInt : public CATTopBlend
  {
  CATCGMVirtualDeclareClass(CATTopBlendInt);
  public:
    virtual                         ~CATTopBlendInt          ();

                                     CATTopBlendInt          (CATGeoFactory* iFactory            ,
                                                              CATTopData   * iTopData            );

    virtual void                     SetSpine                (CATGeometry  * iSpine              )       = 0 ;

    virtual CATBoolean               SetActivateTolerantBlend(CATBoolean     iActivate           = TRUE) = 0 ;

    virtual void                     SetRadiusLaw            (CATLaw       * iRadiusLaw          )       = 0 ;

    virtual void                     SetDevelopOptions       (double         Develop_Clearance   ,
                                                              CATLONG32      Develop_CutCone     )       = 0;

    virtual void                     GetMaxGaussianCurvature (double       & MaxGaussianCurvature,
                                                              CATMathPoint & MaxPosition         )       = 0; 

    virtual void                     SetAligneClosure        (CATLONG32      iAligneClosure      )       = 0;

/**
 * Sets the plane detection mode.
 * @param iPlanesDetection
 * The plane detection mode.
 * <br><b>Legal values</b>: <tt>TRUE</tt> for replacing planar surfaces by planes,
 * <tt>FALSE</tt> otherwise (default mode at the operator creation).
 */
    virtual void                     SetPlanesDetection      (CATBoolean     iPlanesDetection    = CATBoolean(1)) = 0;
/**
 * Sets the canonic surfaces detection mode (cones/cylinders/planes).
 * @param iCanonicSurfacesDetection
 * The canonic surface detection mode.
 * <br><b>Legal values</b>: <tt>TRUE</tt> for replacing nurbs surfaces by canonic surfaces,
 * <tt>FALSE</tt> otherwise (default mode at the operator creation).
 */
    virtual void                     SetCanonicSurfacesDetection(CATBoolean  iCanonicSurfacesDetection = CATBoolean(1)) = 0;

// ??? interessant mais ne construit pas l'operateur Sweep (que cela permettrait de parametrer sous la ceinture)
//     et se contente de rendre son pointeur, inutilisable donc avant le Run.
//     but initial de cette methode jamais appelee?  NLD260416
    virtual CATFrFTopologicalSweep * GetTopologicalSweep     ()                                          = 0;

  } ;
#endif
