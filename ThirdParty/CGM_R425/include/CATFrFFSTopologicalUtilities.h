#ifndef CATFrFFSTopologicalUtilities_H
#define CATFrFFSTopologicalUtilities_H
//
//===================================================================
// Copyright Dassault Systemes Provence 2009-2016, all rights reserved
//===================================================================
//
// CATFrFFSTopologicalUtilities :
// Implementation class for styling fillet approximation
//
//=============================================================================
// Usage notes:
//
//===================================================================
// 07/10/19 : NLD ; Passage de la SoftwareConfiguration à GetSequenceOfFaces() et GetConnectionQuality()
// 05/09/16 : HLN ; Nouv. methode ComputeGap
// 22/02/16 : HLN ; XScale : suppression valeur par defaut des tol. en argument
// 10/02/15 : HLN ; Add iFixedSurf option in signature of HermetizeJunction
// 06/01/15 : HLN ; Ajout iSoftConf dans signature de HermetizeJunction
// 15/10/13 : HLN ; Ajout methode AdjustTraceCurves
// 16/09/13 : HLN ; Ajout tol dans signature de HermetizeJunction
// 28/06/13 : HLN ; Ajout methode GetFaceFromBody
// 17/07/12 : HLN ; Ajout methode HermetizeJunction
// 23/04/12 : HLN ; Ajout methode GetGNQual
// 02/07/09 : MWE ; Creation d'apres CATClassATopoOperators\ProtectedInterfaces\CATCltTopologicalUtilities.h
//===================================================================
#include "CATFrFFilletStyle.h"

class CATMathPoint;
class CATMathVector;
class CATCrvLimits;
class CATSurLimits;
class CATSurParam;
class CATFace;
class CATEdge;
class CATBody;
class CATDomain;
class CATSurface;
class CATNurbsSurface;
class CATCurve;
class CATGeoFactory;
class CATFrFFSFaceBoundary;
class CATPCurve;
class CATGeometry;
class CATSoftwareConfiguration;

#include "CATListOfInt.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATCell.h"
#include "CATTopDefine.h"
#include "CATIsoParameter.h"
#include "CATBoolean.h"
#include "CATConnectCheckerDef.h"

class ExportedByCATFrFFilletStyle CATFrFFSTopologicalUtilities
{
public:
  // Standard constructors and destructors
  // -------------------------------------
                     CATFrFFSTopologicalUtilities();
  virtual           ~CATFrFFSTopologicalUtilities();

  static void        Get2DFaceBoundingBox(CATFace *iFace, CATSurLimits &oFaceBound, CATBoolean MorePrecise = FALSE);

  static CATFace    *GetIthFaceFromBody( CATBody *iBody, int iIndex ); // returns the iIndex th face of the body

  static CATSurface *GetSurfaceFromBody(CATBody *iBody, int iIndex);

  static CATCurve   *GetCurveFromBody(CATBody *iBody, int iIndex, CATCrvLimits *oLimits = NULL);

  static void        GetFaceFromBody(CATBody *iBody, CATSurface *iSurf, CATLISTP(CATFace) &olFace);

  // loopNo : 0 : ExternalBoundary
  //        > 0 : internal Loop Number to compute 
  static CATBoolean  ComputeBoundary(CATFace *iFace, int loopNo, CATFrFFSFaceBoundary *oBoundary);

  static void        ComputeExternalBoundary(CATFace *iFace, CATFrFFSFaceBoundary *oBoundary);

  static void        ComputeBoundary(CATFace *iFace, CATDomain *iDomain, CATBoolean external,
                                     int &NrOfCurves, CATPCurve** &CurveList,
                                     CATCrvLimits * &CurveLimits, short* &CurveOrient);

  static void        ComputeExternalBoundary(CATFace *iSurf, int &NrOfCurves, CATPCurve** &CurveList,
                                      CATCrvLimits * &CurveLimits, short* &CurveOrient);

  static void        GetSequenceOfFaces(CATSoftwareConfiguration* iSoftConf,                   // NLD100718 passage de la configuration
                                        CATLISTP(CATFace) &iFaceList, CATBody *iBodyOfFaces,
                                        CATListOfInt &oSequence, CATListOfInt &oOrientation, 
                                        CATListOfInt &oConnectQual,
//hln22022016                                 double PosTol = 0.01, double TanTol = 0.01,
//hln22022016                                 double CrvTol = 0.1, double G3Tol = 0.1);
                                 double PosTol, double TanTol,
                                 double CrvTol, double G3Tol);

  // computes connection quality of the given faces at the given edge
  // return value -1 :   position continuity is violated
  //               0 :   position continuity is satisfied inside the given tolerance and
  //                     at least tangent continuity is violated
  //               1 :   tangent continuity is satisfied inside the given tolerance and
  //                     at least curvature continuity is violated
  //               2 :   curvature continuity is satisfied inside the given tolerance and
  //                     G3 continuity is violated
  //               3 :   G3 continuity is satisfied inside the given tolerance 
  static int         GetConnectionQuality(CATSoftwareConfiguration* iSoftConf,                   // NLD100718 passage de la configuration
                                          CATEdge *iEdge, CATFace *iFace1, CATFace *iFace2,
                                          CATBoolean &AtStart1, CATBoolean &AtStart2,
//hln22022016                                  double PosTol = 0.01, double TanTol = 0.01,
//hln22022016                                  double CrvTol = 0.1, double G3Tol = 0.1);
                                           double PosTol, double TanTol,
                                           double CrvTol, double G3Tol);

  static int         GetGNQual           (CATGeoFactory *iFactory, CATSoftwareConfiguration *iSoftConf,
                                          const int &iDiscrType, const CATCommandOption &iAnalyzisType,
                                          CATPCurve *irefCrv, CATPCurve *iscndCrv,
                                          const double &iEpsGap, const double &iEpsTan);

  static int         ComputeGap          (CATGeoFactory *iFactory, CATSoftwareConfiguration *iSoftConf,
                                          const int &iDiscrType, const CATCommandOption &iAnalyzisType,
                                          CATPCurve *irefCrv, CATPCurve *iscndCrv,
                                          const double &iEpsGap, const double &iEpsTan,
                                          CATMathPoint oPointMax[2], double &oGap,
                                          CATMathPoint &oPointAngMax, CATMathVector &oNormalAngMax, double &oAngle);

  // iFixedSurf = 0 correction repartie sur les 2 surfaces, 1 ioSurfa fixe, 2 ioSurfb fixe
  static int         HermetizeJunction   (CATSoftwareConfiguration *iSoftConf, CATNurbsSurface *ioSurfa, CATNurbsSurface *ioSurfb,
                                          double iTol, int iFixedSurf = 0);

  static int         FindGeometryInBody  (CATBody *iBody, CATGeometry *iGeometry, int iDimOfCells = -1); // return index of Body     in CellList; (0 : not found)

  static int         FindGeometryInCellList(CATLISTP(CATCell) &CellList, CATGeometry *iGeometry);        // return index of Geometry in CellList; (0 : not found)

  // extract the original traces of the fillet from the CATFilletSurface limited to the face support
  static int         ExtractOriginalTraceCurves(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig,
                                                CATGeometry *iFilletG1, // either CATSurface or CATFace
                                                CATSurface *iFilletSurfaceG2, CATIsoParameter iFilOrientG2,
                                                CATPCurve *&oTrace1, CATPCurve *&oTrace2);

  static int         AdjustTraceCurves         (CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig,
                                                CATSurface *iFilletSurfaceG2, CATSurLimits & iFilLimits, CATIsoParameter iFilOrient,
                                                CATSurParam & iStartTraceOnSurfG2, CATSurParam & iEndTraceOnSurfG2,
                                                CATPCurve *iTrimCurves[2], CATPCurve *ioTraces[2]);
};

#endif

