/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATTopExtrudeOperandsChecker:
// Class suplies for services that check coherence of operands for CATTopPrism,
// CATTopRevol.
//
//=============================================================================
// Usage notes:
// DO NOT USE
//
//=============================================================================

//=============================================================================
// HISTORIC & COMMENTS :
// 01 12 99 ALM Creation
// 10 01 00 BHE Creation IsProfileLocallyPerpendicularToRevolutionVector
// 22 03 00 ALM Test d'intersection entre profils : AreProfilesIntersecting
// 20 08 02 ALV Test de fermeture du profil (si c'est une CATSurface)
// 12 05 12 DLP Changes for fix to IR 106957.
//=============================================================================

#ifndef CATTopExtrudeOperandChecker_H
#define CATTopExtrudeOperandChecker_H

#include "BOIMPOPE.h"
#include "CATTopDef.h"
#include "CATMathDef.h"
#include "CATListOfCATSurfaces.h"
#include "CATListOfCATCells.h"
#include "CATMathDirection.h"
#include "CATTopOperator.h"

class CATGeoFactory;
class CATTopologicalOperator;
class CATMathAxis;
class CATMathDirection;
class CATBody;
class CATWire;
class CATCell;
class CATEdge;
class CATFace;
class CATDomain;
class CATError;
class CATMathPlane;
class CATCurve;
class CATTopData;
class CATLoop;
class CATTopExtrudeOperandCheckerSurfFunc;

// Input body types
typedef enum
{
  CATTopExtrudeInputBodyType_Profile=0,
    CATTopExtrudeInputBodyType_Guide,
    CATTopExtrudeInputBodyType_Spine
} CATTopExtrudeInputBodyType;


//-----------------------------------------------------------------------------
class ExportedByBOIMPOPE CATTopExtrudeOperandChecker : public CATTopOperator
{
  public:
  //-------------------------------------------------------------------------
  // Constructor/Destructor
  //-------------------------------------------------------------------------
  CATTopExtrudeOperandChecker(CATGeoFactory  * iFactory,
                              CATTopData     * iTopData,
                              CATLONG32             iNbProfiles,
                              CATBody       ** iProfiles,
                              CATLONG32             iNbGuides,
                              CATBody       ** iGuides,
                              CATBody        * iSpine);
  CATTopExtrudeOperandChecker(CATGeoFactory    * iFactory,
                              CATTopData     * iTopData,
                              CATBody          * iProfile,
                              CATMathDirection * iDirection);
  CATTopExtrudeOperandChecker(CATGeoFactory    * iFactory,
                              CATTopData     * iTopData,
                              CATBody          * iProfile,
                              const CATMathAxis & iAxis);
  virtual ~CATTopExtrudeOperandChecker();

  //-------------------------------------------------------------------------
  // Checks
  //-------------------------------------------------------------------------

  // Basic Checks
  //-------------
  // Profile basic check : the profile has only vertices, wires or shells.
  CATBoolean IsProfileOKForBasicCheck(CATLONG32   iIndex,
                                      CATLONG32 & oNbDomains,
                                      CATLONG32 & oDomainsLowDimension);
  // Guide basic check : the guide is monodomain : a wire or a shell.
  CATBoolean IsGuideOKForBasicCheck(CATLONG32   iIndex,
                                    CATLONG32 & oDomainsLowDimension);
  // Spine basic check : the spine is monodomain : a wire.
  CATBoolean IsSpineOKForBasicCheck();

  // Planeity Checks
  //----------------
  // Profile, guide and spine planeity
  CATBoolean IsProfilePlanar(CATLONG32 iIndex);
  CATBoolean IsGuidePlanar(CATLONG32 iIndex);
//  CATBoolean IsSpinePlanar();

  // Auto-intersetion Checks
  //------------------------
  // Profile, guide and spine auto-intersection : the check is done
  // on the body and not only on each domain.
  CATBoolean IsProfileAutoIntersecting(CATLONG32 iIndex);
  CATBoolean IsGuideAutoIntersecting(CATLONG32 iIndex);
  CATBoolean IsSpineAutoIntersecting();

  // Intersection Checks
  //--------------------
  CATBoolean AreProfilesIntersecting(CATLONG32 & IntersectionDimension,
                                     CATLONG32 & IntersectionSize);

  // Specific Checks
  //----------------
  // Check profile with revol axis - if any
  //   --> The profile only intersect the axis on wires' extremities, or on
  //       faces' sides. All the profile's elements are on the same side.
  //   --> The profile has no tangent perpendicular to the axis.
  CATBoolean IsProfileIntersectingRevolAxis(CATLONG32 iIndex);
  CATBoolean IsProfileLocallyPerpendicularToRevolutionVector(CATLONG32 iIndex);
//  CATBoolean IsProfileOKForExtrapolationUntilAxis(CATLONG32 iIndex);
  // Check profile and prism direction - if any
  CATBoolean IsProfileParallelToPrismDirection(CATLONG32 iIndex);
  CATBoolean IsProfileParallelToPrismDirectionNew(CATLONG32 iIndex);
  // Check profile closure.
  CATBoolean IsProfileClosed(CATLONG32 iIndex);
  // Check if shell to prism relative direction is changing around vertex
  CATBoolean IsShellPrismDirectionChangingAroundVertex_Old(CATLONG32 iIndex);
  CATBoolean IsShellPrismDirectionChangingAroundVertex(CATLONG32 iIndex);
  // Check if shell to revol relative direction is changing around vertex
  CATBoolean IsShellRevolDirectionChangingAroundVertex(CATLONG32 iIndex);

  //-------------------------------------------------------------------------
  // Error management
  //-------------------------------------------------------------------------
  // Get the error list :
  // When a check method is called, errors can be created : the returned CATBoolean
  // value indicates this. When an error is created, the user has to call the GetError
  // method to manage the errors.
  // The CATError array is to be deleted by the caller (delete [] oErrors),
  //    and the errors are to be managed by the caller (throw or flush).
  void GetErrorList(CATLONG32 &oNbErrors, CATError **&oErrors);

  private :

    //===========================
    //    D A T A
    //===========================
    // Input Data
    CATGeoFactory           * _Factory;
    double                    _Tolerance;
    CATBody                ** _Profiles;
    CATBody                ** _Guides;
    CATBody                 * _Spine;
    CATLONG32                      _NbProfiles;
    CATLONG32                      _NbGuides;
    // Protected Data
    CATTopologicalOperator  * _Topo;
    CATLONG32                      _ExtrudeType; // 0 : sweep, 1 : revol, 2 : prism
    // -- basic check
    CATBoolean                _BasicCheckDone;
    CATLONG32                    * _ProfileBasicCheckResult;
    CATLONG32                    * _GuideBasicCheckResult;
    CATLONG32                      _SpineBasicCheckResult;
    CATLONG32                    * _ProfileNbDomains;
    CATLONG32                    * _ProfileDomainsLowDim;
    CATLONG32                    * _GuideDimension;
    // -- revol and prism
    CATBody                 * _Axis;
    CATMathDirection          _Direction;
    CATMathPoint              _OriginAxis;
    // -- profile properties
    CATLONG32                    * _ProfilePlaneityComputed;
    CATSurface             ** _ProfilePlane;
    CATLONG32                    * _IsProfilePlanar;
    // -- guide properties
    CATLONG32                    * _GuidePlaneityComputed;
    CATSurface             ** _GuidePlane;
    CATLONG32                    * _IsGuidePlanar;
    // -- spine properties
    CATLONG32                      _SpinePlaneityComputed;
    CATSurface              * _SpinePlane;
    CATLONG32                      _IsSpinePlanar;
    // -- error management
    CATError               ** _Errors;
    CATLONG32                      _NbErrors;

    //===========================
    //     M E T H O D S
    //===========================
    void AddError(CATError *iError);
    void InitData(CATGeoFactory  * iFactory,
                  CATLONG32 iNbProfiles,CATBody ** iProfiles,
                  CATLONG32 iNbGuides,CATBody ** iGuides,
                  CATBody        * iSpine);
    CATLONG32 ComputeUnderlyingPlane(CATBody * iBody, CATSurface *& oPlane);
    void GetUnderLyingPlanes(CATCell *iCell, CATLISTP(CATSurface) & oPlanes);
    void GetLowestDimensionCurve(CATEdge *iEdge,CATLONG32 & oDimension, CATCurve *& oCurve);
    void BasicCheckOnBody(CATBody * iBody,CATLONG32 & oDiag, CATLONG32 & oNbDomains,
                          CATLONG32 & oDomainsLowDimension);
    CATBoolean IsBodyAutoIntersecting(CATBody * iBody);
    CATBoolean IsWireParallelToPrismDir(CATWire * iWire);
    CATBoolean IsNormalAlongLoopPerpendicularToPrismDir(CATLoop * iLoop, CATBody * iBody);
    CATBoolean HasATangentEqualToLocalRevolutionVector(CATEdge * Edge);
    CATBoolean HasANormalPerpendicularToLocalRevolutionVector(CATEdge * Edge, CATBody * iBody);
    // Get the shell direction around edge extremities
    void GetFunctionValuesAroundEdgeExtremities(CATEdge        * iEdge                    ,
                                           CATDomain      * iDomain                  ,
                                           const int        iIndex                   ,
                                           CATTopExtrudeOperandCheckerSurfFunc  &iEvaluator,
                                           double           oValues[4]        ,
                                           int            & oValidDirectionFound     );
};
#endif
