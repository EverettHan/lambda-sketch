#ifndef CATEvalSkinExtrapolDistance_H
#define CATEvalSkinExtrapolDistance_H

// ++++ Includes ++++
#include "CATEvalSkinExtrapolDistanceDef.h"
#include "CATCGMNewArray.h"
#include "AdvTrimOpe.h"
#include "CATSoftwareConfiguration.h"
#include "CATGeoFactory.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATBody.h"
#include "CATEdge.h"
#include "CATFace.h"
#include "CATTopDefine.h"
#include "CATLISTV_CATMathPoint.h"
#include "ListPOfCATVertex.h"
#include "CATMathOBB.h"
#include "CATMathInline.h"

// ++++ Predeclarations ++++

//=============================================================================
// CATEvalSkinExtrapolDistance
// 
// responsable: ZUT
//=============================================================================

//-----------------------------------------------------------------------------
// MAIN CLASS
//-----------------------------------------------------------------------------

class ExportedByAdvTrimOpe CATEvalSkinExtrapolDistance
{
public:
  //---------------------------------------------------------------------------
  // CONSTRUCTEUR(S) / DESTRUCTEUR
  //---------------------------------------------------------------------------

  // Surcharge du new / delete
  CATCGMNewClassArrayDeclare;

  CATEvalSkinExtrapolDistance( CATSoftwareConfiguration & iConfig, CATGeoFactory & iFactory );
  ~CATEvalSkinExtrapolDistance();

  //---------------------------------------------------------------------------
  // METHODES NON-INLINE STATIQUES
  //---------------------------------------------------------------------------

  // Evaluation de la longueur necessaire pour que l'extrapolation de la surface au niveau
  // de l'edge bord donnee atteigne le body objectif
  static HRESULT EvalSkinExtrapolDistance(CATSoftwareConfiguration & iConfig,
                                          CATGeoFactory            & iFactory, 
                                          CATBody                  & iBody,
                                          CATEdge                  & iBorderEdge,
                                          CATBody                  & iTargetBody,
                                          CATESEDOptions             iOptions,
                                          CATESEDResult            & oResult);

  // Determination du cote ou se situe la surface a extrapoler par rapport au body objectif
  // oSide: CATSideRight   si l'orientation du shell objectif pointe en direction de la surface
  //        CATSideLeft    si l'orientation du shell objectif pointe dans la direction opposee a la surface
  //        CATSideUnknown si indetermine
  // Les deux bodies doivent etre surfaciques. Le body objectif doit etre mono-shell.
  static HRESULT EvalSkinToExtrapolSideVsTargetBody(CATSoftwareConfiguration & iConfig,
                                                    CATGeoFactory            & iFactory, 
                                                    CATBody                  & iBody,
                                                    CATEdge                  & iBorderEdge,
                                                    CATBody                  & iTargetBody,
                                                    CATSide                  & oSide);

  static HRESULT IntersectLineBody( CATSoftwareConfiguration &  iConfig, 
                                    CATGeoFactory            &  iFactory,
                                    CATMathPoint             &  iOrigin,
                                    CATMathVector            &  iDirection,
                                    CATBody                  &  iBody,
                                    CATESEDOptions              iOptions,
                                    CATLISTV(CATMathPoint)   &  oIntersectionPoints,
                                    double                   *  oRayLength,
                                    CATBody                  ** oIntersectionBody = NULL );

  static HRESULT EvalExtrapolDistanceFromIntersectLineBodyResult( CATSoftwareConfiguration     & iConfig, 
                                                                  CATGeoFactory                & iFactory,
                                                                  CATMathPoint                 & iOrigin,
                                                                  const CATLISTV(CATMathPoint) & iIntersectionPoints,
                                                                  CATESEDOptions                 iOptions,
                                                                  CATESEDResult                & oResult );

  // Verifie les extremites et le centre de l'edge versus la cible. Si les deux extremites OU le centre
  // font face, on considere que l'edge fait completement face a la cible
  static HRESULT EvalIfIsEntirelyFacingBody(CATSoftwareConfiguration & iConfig,
    CATGeoFactory            & iFactory, 
    CATBody                  & iBody,
    CATEdge                  & iBorderEdge,
    CATBody                  & iTargetBody,
    CATESEDOptions             iOptions,
    CATESEDResult            & oResult);

  //---------------------------------------------------------------------------
  // METHODES NON-INLINE PUBLIQUES
  //---------------------------------------------------------------------------

  HRESULT EvalSkinExtrapolDistance(CATBody        & iBody,
                                   CATEdge        & iBorderEdge,
                                   CATBody        & iTargetBody,
                                   CATESEDOptions   iOptions,
                                   CATESEDResult  & oResult);

  // Argument facultatif iMidStartOrEnd : specifie le point extremite de l'edge a partir duquel faire cette evaluation
  //                                      0 pour le point milieu de l'edge, 1 pour le point start, 2 pour le point end
  // Argument facultatif iTangentDir : Spécifie la direction de lancement de rayon pour l'évaluation
  //                                   0 pour normal, 1 pour tangent
  HRESULT EvalSkinToExtrapolSideVsTargetBody(CATBody & iBody, CATEdge & iBorderEdge, CATBody & iTargetBody, CATSide & oSide, short iMidStartOrEnd = 0, short iTangentDir = 0);

  HRESULT IntersectLineBody(CATMathPoint & iOrigin,
                            CATMathVector & iDirection,
                            CATBody & iBody,
                            CATESEDOptions iOptions,
                            CATLISTV(CATMathPoint) & oIntersectionPoints,
                            double * oRayLength,
                            CATBody ** oIntersectionBody = NULL);

  HRESULT EvalExtrapolDistanceFromIntersectLineBodyResult(CATMathPoint & iOrigin,
                                                          const CATLISTV(CATMathPoint) & iIntersectionPoints,
                                                          CATESEDOptions iOptions,
                                                          CATESEDResult & oResult);

  // Mise en cache d'un OBB associe a un CATBody
  void StoreOBBCache(CATBody * iBody, CATMathOBB & iOrientedBox);

  // Verifie les extremites et le centre de l'edge versus la cible. Si les deux extremites OU le centre
  // font face, on considere que l'edge fait completement face a la cible
  HRESULT EvalIfIsEntirelyFacingBody(CATBody                  & iBody,
    CATEdge                  & iBorderEdge,
    CATBody                  & iTargetBody,
    CATESEDOptions             iOptions,
    CATESEDResult            & oResult);

  //---------------------------------------------------------------------------
  // METHODES INLINE
  //---------------------------------------------------------------------------

private:
  //---------------------------------------------------------------------------
  // METHODES PRIVEES
  //---------------------------------------------------------------------------
  HRESULT EvalSkinExtrapolDistanceImplV1( CATBody                  & iBody,
                                          CATEdge                  & iBorderEdge,
                                          CATBody                  & iTargetBody,
                                          CATESEDOptions             iOptions,
                                          CATESEDResult            & oResult );

  HRESULT EvalSkinExtrapolDistanceImplV2( CATBody                  & iBody,
                                          CATEdge                  & iBorderEdge,
                                          CATBody                  & iTargetBody,
                                          CATESEDOptions             iOptions,
                                          CATESEDResult            & oResult );



  HRESULT EvalMaxDistanceToBodyV1( const CATESEDSubdiv  & iSubdiv,
                                   CATESEDOptions         iOptions,
                                   double                 iMinDistance,
                                   double               & oDistance,
                                   short                  iRecursionDepth = 1 );

  HRESULT EvalMaxDistanceToBodyV2( const CATESEDSubdiv  & iSubdiv,
                                   CATESEDOptions         iOptions,
                                   double                 iMinDistance,
                                   double               & oDistance,
                                   short                  iRecursionDepth = 1 );

  // Calcule la distance a la cible dans la direction iDirectionMode
  // ATTENTION : pour cette fonction, les modes CATESEDDirectionMode sont exclusifs
  HRESULT ComputeDistanceToBody( CATBody                  & iBody,
                                 CATEdge                  & iBorderEdge,
                                 CATFace                  & iBoundedFace,
                                 CATBody                  & iTargetBody,
                                 CATCrvParam              & iCrvParam,
                                 CATESEDOptions             iOptions,
                                 CATESEDResult            & oResult,
                                 CATESEDDirectionMode       iDirectionMode = CATESED_DMODE_NORMAL,
                                 CATEdge                  * iNeighborBorderEdge = 0,
                                 CATCrvParam              * iNeighborCrvParam = 0,
                                 CATFace                  * iNeighborBoundedFace = 0);

  HRESULT GetBoundingSphereParameters( CATBody      & iBody,
                                       CATMathPoint & oOrigin,
                                       double       & oDiameter );

  HRESULT GetOutsideDirection( CATCrvParam              & iECParam,
                               CATEdge                  & iEdge,
                               CATFace                  & iBoundedFace,
                               CATMathPoint             & oOrigin,
                               CATMathVector            & oDirection,
                               CATBoolean               * oCurvatureCorrectionDone = NULL,
                               CATMathVector            * oCurvatureBasedDirection = NULL );

  
  // Indique la direction tangente à l'edge voisine iEdge à l'extrémité oOrigin de l'edge considérée.
  // ATTENTION : iEdge est l'edge voisine à l'edge considérée,
  // iECParam le param correspondant au sommet commun SUR L'EDGE VOISINE iEdge
  HRESULT GetTangentDirection( CATCrvParam   & iNeighborECParam,
                               CATEdge       & iNeighborEdge,
                               CATMathVector & iNormalDirection,
                               CATMathVector & oDirection);

  // Indique la direction intermédiaire entre la normale de l'edge courante et celle de l'edge voisine
  // ATTENTION : iEdge est l'edge voisine à l'edge considérée,
  // iECParam le param correspondant au sommet commun SUR L'EDGE VOISINE iEdge
  HRESULT GetDiagonalDirection( CATCrvParam   & iNeighborECParam,
                                CATEdge       & iNeighborEdge,
                                CATFace       & iNeighborBoundedFace,
                                CATMathVector & iCurrentNormalDirection,
                                CATMathVector & oDiagDirection);

  HRESULT GetNeighborDataForDistanceEval( CATBody      & iBody,
                                          CATCrvParam  & iECParam,
                                          CATEdge      & iEdge,
                                          CATVertex    & iEndVertex,
                                          CATEdge     *& oNeighbourEdge,
                                          CATCrvParam  & oNeighbourCParam,
                                          CATFace     *& oNeighborBoundedFace,
                                          HRESULT      & oAngleCheck,
                                          short       *  oLaunchNormal = 0);


  HRESULT ExtractPointsFromIntersectResult(CATBody                 & iIntersectionBody,
                                           CATBody                 & iImageBody,
                                           CATESEDOptions            iOptions,
                                           CATMathVector           & iRayDirection,
                                           double                    iTolerance,
                                           CATLISTV(CATMathPoint)  & oIntersectionPoints);


  HRESULT EvalSideVsTargetBodyFromIntersectLineBodyResult( CATMathPoint  & iOrigin,
                                                           CATBody       & iIntersectionBody,
                                                           CATBody       & iImageBody,
                                                           CATSide       & oSide );

  HRESULT GetMatterSideAtIntersectionPoint( CATVertex        & iVertex,
                                            CATBody          & iImageBody,
                                            CATMathDirection & oDirection );

  HRESULT GetOneFace(const CATLISTP(CATFace) & iListOfFaces, CATFace *& oChosenFace);

  HRESULT ComputeThickRay( CATMathPoint       & iOrigin,
                           CATMathDirection   & iMainDir,
                           CATMathDirection   & iSecondDir,
                           double               iSize[3],
                           CATESEDThickRay    & oThickRay );

  HRESULT ComputeThickRayVsBodyIntersection( const CATESEDThickRay & iThickRay, CATBody & iBody, short & oIsIntersecting );

  HRESULT EvalIfSubdivIsFacingTargetBody( CATESEDSubdiv & ioSubdiv );

  //---------------------------------------------------------------------------
  // DONNEES MEMBRES
  //---------------------------------------------------------------------------

  CATSoftwareConfiguration & _Config;
  CATGeoFactory            & _Factory;

  //---------------------------------------------------------------------------
  // CACHE
  //---------------------------------------------------------------------------

  struct CATESEDCachedBody
  {
    CATBody    * _Body;
    CATMathOBB * _OBBCache;

    CATESEDCachedBody() : _Body(NULL), _OBBCache(NULL) {}
    ~CATESEDCachedBody() { if ( _OBBCache ) delete _OBBCache; _OBBCache = NULL; }
  };

  struct CATESEDCache
  {
    CATESEDCachedBody * _CachedBodies;
    CATLONG32           _NbCachedBodies;

    CATESEDCache() : _CachedBodies(NULL), _NbCachedBodies(0) {}
    ~CATESEDCache() { if ( _CachedBodies ) delete [] _CachedBodies; _CachedBodies = NULL; _NbCachedBodies = 0; }

    CATLONG32 FindCachedBodyIndex(CATBody * iBody, CATBoolean iCreateIfNecessary = FALSE);
  };

  CATESEDCache _CachedData;
};

//-----------------------------------------------------------------------------
// IMPLEMENTATION METHODES INLINE
//-----------------------------------------------------------------------------

#endif /* CATEvalSkinExtrapolDistance_H */
