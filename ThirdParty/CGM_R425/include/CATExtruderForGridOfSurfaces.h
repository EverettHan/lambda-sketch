// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
//CATExtruderForGridOfSurfaces:
// Utility for producing topology from a grid of surfaces
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
//
// ************************************************************
// * CAUTION: parameter change from curves along U and curves *
// * along V to Surfaces must be linear                       *
// ************************************************************

//=============================================================================
// 04 01 99 NLD Creation
// 18 01 99 NLD Suppression de StoreGeomSpec et NumSpecCrvInGeom que
//              l'on prendra desormais dans CATExtruderUtilities 
// 02 04 99 SRO CATPlane => CATSurface dans CreateParallelPCurves
//              et CreateMeridianPCurves
// 19 07 02 ALV Ajout de iSoftwareConfiguration pour versionning de CATExtruder
// 18 10 10 NLD Ajout classe CATExtruderGeomSpecManager pour encapsulation des données
//              de gestion et switch perfos
//              Ajout de _GuidesSpecManager et _ProfilesSpecManager de type CATExtruderGeomSpecManager
//              remplacant _GeomGuides,   _SpecGuides,   _SpecGuideReps
//              et         _GeomProfiles, _SpecProfiles, _SpecProfileReps
//=============================================================================
#ifndef CATExtruderForGridOfSurfaces_H
#define CATExtruderForGridOfSurfaces_H
// Module definition for Windows
#include <FrFTopologicalOpe.h>
//
#include <CATExtruderByMatrix.h>              // For inheritance

// For interface and Data
class CATGeoFactory ;
class CATGeometry ;
class CATSurface ;
class CATFrFCompositeCurve ;
#include <CATListPV.h>                        // Pour listes
#include <CATMathDef.h>                       // Pour typedef CATBoolean
#include <CATSoftwareConfiguration.h>         // pour versionning
#ifndef NULL
#define NULL 0
#endif
#include <CATExtruderUtilities.h>             // For inheritance
//=============================================================================
// Class Definition
//=============================================================================
class ExportedByFrFTopologicalOpe CATExtruderForGridOfSurfaces :
  public CATExtruderByMatrix
{
  public :

  // Default constructor (do not use)
  // NO CATExtruderForGridOfSurfaces() ;

  // Constructor
 CATExtruderForGridOfSurfaces
            (CATGeoFactory          * iFactory,
             CATFrFCompositeCurve   * iCurvesAlongU,
             CATFrFCompositeCurve   * iCurvesAlongV,
             int                      iNumberOfSurfacesAlongU,
             int                      iNumberOfSurfacesAlongV,
             // le 1er indice est l'indice en U, le second l'indice en V
             CATSurface           *** iSurfaces,
             CATSoftwareConfiguration * iSoftwareConfiguration
            ) ;

  // Destructor
  ~CATExtruderForGridOfSurfaces ();

// *********************************
// * Methods needed by CATExtruder *
// *********************************
virtual void SetCenterBody (const CATBody* iCenterBody) ;
virtual void SetProfileBody (const CATBody* iCenterBody) ;
//-------------------------------------------------------------------------
// Create geometry
//-------------------------------------------------------------------------
virtual void CreateParallelSurfaces
                           ( CATLISTP(CATEdgeCurve)  & iProfiles,
                             CATLISTP(CATCrvLimits)  & iProfileLimits,
                             CATLISTP(CATEdgeCurve)  & iCenters,
                             CATLISTP(CATCrvLimits)  & iCenterLimits )  ;


//Non necessaire: on utilise celle de CATExtruderByMatrix                             
virtual void CreateTopSurfaces
                           ( CATLISTP(CATSurface)    & iProfileSurfaces,
                             CATLISTP(CATMacroPoint) & iCenters         ) ;


//Non necessaire: on utilise celle de CATExtruderByMatrix                             
virtual void CreatePCurvesOnTop( CATLISTP(CATPCurve)     & iProfilePCurves,
                                 CATLISTP(CATCrvLimits)  & iProfileLimits,
                                 CATLISTP(CATSurface)    & iProfileSupports,
                                 CATLISTP(CATMacroPoint) & iCenters         );

//-------------------------------------------------------------------------
// The following methods have to be provided only whenever CreateParallelSurfaces 
// may return Plane whose isopars are not parallel to Profile and Center
// (SetParametrizationToNotRegular).
//-------------------------------------------------------------------------
// non necessaires : mettre une implementation bidon
//-------------------------------------------------------------------------
virtual void CreateParallelPCurves
                           ( CATLISTP(CATPointOnEdgeCurve) & iProfiles,
                             CATEdgeCurve*             iCenter,
                             CATCrvLimits*             iCenterLimits,
                             CATSurface*               iSupport  )  ;

virtual void CreateMeridianPCurves
                           ( CATEdgeCurve*             iProfile,
                             CATCrvLimits*             iProfileLimits,
                             CATLISTP(CATPointOnEdgeCurve) & iCenters,
                             CATSurface*               iSupport  )  ;
                            
//-------------------------------------------------------------------------
// Parametrization mapping to be provided by child classes whenever Surface
// parametrization has been set to not linear.
//-------------------------------------------------------------------------
// non necessaire : mettre une implementation bidon
//-------------------------------------------------------------------------
virtual void GetEquivalentPoints
                     ( const CATEdgeCurve*             iProfile,
                       const CATEdgeCurve*             iCenter,
                       const CATSurface*               iProduct,
                       const CATLONG32                      iParamsCount,
                       const CATCrvParam               iProfileParams[],
                       const CATCrvParam               iCenterParams[],
                            CATSurParam               oProductParams[] );
 
//-------------------------------------------------------------------------
// Mandatory method to be provided in order to orient volumic results.
//-------------------------------------------------------------------------
// Etant donnes un point (CATSurParam) trace sur le support du profil
// (un plan n est-ce-pas?), et la courbe guide, trouver quelle est
// la direction de l'extrusion de ce point.
// non necessaire car on est en surfacique: mettre une implementation bidon
virtual void GetDeriv
                     ( const CATSurface              * iSupport, 
                       const CATSurParam             & iLocation,
                       const CATEdgeCurve            * iCenter,
                            CATMathDirection        & oDirectionOfMove );
                           
// *****************************************
// * Methods needed by CATExtruderByMatrix *
// *****************************************
//-------------------------------------------------------------------------
// Get geometric parameters of the extrusion as a transformation Matrix.
//-------------------------------------------------------------------------
// non necessaire car on n'aura pas a tracer de meridiennes 
// par les transformations : mettre une implementation bidon
virtual void GetTransformation
                     (      CATPoint                * iCenter,
                            CATMathTransformation   & oMove   ) ;

//-------------------------------------------------------------------------
// Aggregate
//-------------------------------------------------------------------------
// non necessaire: prendre celle de CATExtruderByMatrix
//virtual CATEdgeCurve* CreateEdgeCurve
//                     ( CATLISTP(CATCurve)     & iCurves,
//                       CATLISTP(CATCrvLimits) & iLimits,
//                       CATListOfInt           & iOrns   ) ;
//-------------------------------------------------------------------------
// Indicates whether several Lim on same geometry is supported
//-------------------------------------------------------------------------
virtual CATBoolean ShareCenterGeometry() const;

//-------------------------------------------------------------------------
// Removes from list the unnecessary surfaces
//-------------------------------------------------------------------------
virtual void FilterExistingSurfaces();
// non necessaire car on n'aura pas d'extrusion de points a faire:
// mettre une implementation bidon
virtual void CreateParallelCurves(CATLISTP(CATPoint) & iProfiles,
                                  CATLISTP(CATEdgeCurve) & iCenters,
                                  CATLISTP(CATCrvLimits) & iCenterLimits );


  private : 
  
  //========================================================================
  // private data
  //========================================================================
  CATGeoFactory*           _Factory ;
  int                      _CallLevel ; 
  CATFrFCompositeCurve*    _CurvesAlongU ;
  CATFrFCompositeCurve*    _CurvesAlongV ;
  int                      _NumberOfSurfacesAlongU ;
  int                      _NumberOfSurfacesAlongV ;
  // le 1er indice est l'indice en U, le second l'indice en V
  CATSurface***            _Surfaces ;
  //
  CATExtruderGeomSpecManager _ProfilesSpecManager;// remplace _GeomProfiles _SpecProfiles et _SpecProfileReps
  CATExtruderGeomSpecManager _GuidesSpecManager;  // remplace _GeomGuides   _SpecGuides   et _SpecGuideReps
  /*
  CATLISTP(CATCurve)       _GeomProfiles;     // Profils stockés dans la geometrie
  CATLISTP(CATCurve)       _GeomGuides  ;     // Guides  stockés dans la geometrie
  CATLISTP(CATEdgeCurve)   _SpecProfiles;     // Liste des profils spécifiés par la topologie
  CATLISTP(CATCurve)       _SpecProfileReps;  // Représentations géométriques de ces profils
  CATLISTP(CATEdgeCurve)   _SpecGuides;       // Liste des guides spécifiées par la topologie
  CATLISTP(CATCurve)       _SpecGuideReps;    // Représentations géométriques de ces guides
  */
                
  //========================================================================
  // private methods
  //========================================================================
  //-----------------------------------------------------------------------------
  // check + trace (debug)
  //-----------------------------------------------------------------------------
  void CheckAll();
  // Verification des donnees
  void     InputDataVerification() ;
  // Initialisations
  void     Init() ;
  // Nettoyage
  void     Clear() ;
  // Methode dans laquelle en theorie on ne passe pas
  void     NotToBeCalled() ;
  // Methode dans laquelle on ne fait pas de traitement
  void     NoTreatment() ;
  // Methode a implementer 
  void     ToBeDone() ;
//-----------------------------------------------------------------------------
// donne le numero d'un profil dans l'objet geometrique
//-----------------------------------------------------------------------------
CATLONG32 NumProfileInGeom (const CATCurve* iProfile) ;
CATLONG32 NumProfileInGeom (const CATEdgeCurve* iProfile) ;
//-----------------------------------------------------------------------------
// donne le numero d'une courbe centre dans l'objet geometrique
//-----------------------------------------------------------------------------
CATLONG32 NumGuideInGeom  (const CATCurve* iCenter) ;
CATLONG32 NumGuideInGeom  (const CATEdgeCurve* iCenter) ;
}  ;
#endif
