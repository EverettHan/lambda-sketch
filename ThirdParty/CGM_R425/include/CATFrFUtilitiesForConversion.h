//=====================================================================================
// Copyright Dassault Systemes Provence 2020, All Rights Reserved
//=============================================================================
//
//=============================================================================
// Usage notes:
// sample of use : services pour Tooling
// to provide
//
//=============================================================================  
//  Sep 2020 : ANR : Creation                          
//=============================================================================
#ifndef CATFrFUtilitiesForConversion_H 
#define CATFrFUtilitiesForConversion_H

#include "CATFrFSmoothing.h"
#include "CATFrFNurbsMultiForm.h"
#include "CATBody.h"
#include "CATDataType.h" 
#include "CATGeoFactory.h"
#include "CATSoftwareConfiguration.h"
#include "CATTopData.h"   
#include "CATFreeFormDef.h"
#include "CATLISTV_CATMathPoint.h"
 
#include "CATEdge.h"
#include "ListPOfCATEdge.h"


class CATBody;
class CATFace;
class CATEdge;
class CATCurve;

//----------------------------------------------------------------------- 
class ExportedByCATFrFSmoothing CATFrFUtilitiesForConversion
{
public: 

  // Pour vde1 : service pour simplifier une courbe : Pour Wire passer par CleanCurve(RNO/MWE)
  static int FittingEdge(CATGeoFactory *iFactory, CATTopData *iTopData, CATEdge *iEdge, int iNbMaxArcs, int iMaxDegree, double ideviation, CATEdge *&oEdge, double &oMaxDeviation, CATFrFContinuity iSideContinuity = CATFrFPointCont);

  //pour Yann
  static int ConvertEdgeCurveToSpline(CATGeoFactory *iFactory, CATTopData *iTopData, CATEdge *iEdge, int iNbMaxArcs, int iMaxDegree, double ideviation, CATFrFNurbsMultiForm *&ioNurbsMultiForm, CATLISTV(CATMathPoint) &oListOfPtsFoSpline);
  //sharpness_tolerance = 60 ?
  static int ConvertWireToSpline(CATGeoFactory *iFactory, CATTopData *iTopData, CATBody *iBody, int iNbMaxArcs, int iMaxDegree, double ideviation, double isharpness_angle, CATLISTV(CATMathPoint) &oListOfPtsFoSpline);
 
  //sharpness_tolerance = 60 ?
  static int ConvertWireToSpline(CATGeoFactory *iFactory, CATTopData *iTopData, CATBody *iBody, int iNbMaxArcs, int iMaxDegree, double ideviation, double isharpness_angle, double imin_dist, CATLISTV(CATMathPoint) &oListOfPtsFoSpline);
   
  // arretons de dupliquer : y a plusieurs appel a cause de l'IdentityCard ---> me semble conforme a l'appel dans FSS
  static void anr_call_connect_checker_oper(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATBody* iBody, int iContinuityOrder, double iTargetTolG0, double iTargetTolG1,
                                            double& oMax_Gap_G0, double& oMax_Gap_G1, CATLISTP(CATEdge)& oListOfEdges_g0_ko, CATLISTP(CATEdge)& oListOfEdges_g1_ko);

  // pour reverse : parfois on a juste une liste.
  static void anr_call_connect_checker_oper(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, ListPOfCATCell& iCellsList, CATBody* iBody, int iContinuityOrder, double iTargetTolG0, double iTargetTolG1,
                                            double& oMax_Gap_G0, double& oMax_Gap_G1, CATLISTP(CATEdge)& oListOfEdges_g0_ko, CATLISTP(CATEdge)& oListOfEdges_g1_ko);


private: 
  // From CATTopTools : Add Orientation
  static CATEdge *CreateEdgeFromCurve(CATGeoFactory *iGeoFactory, CATCurve *iCurve, CATOrientation iOrientation);
  static int Eval_multiform_ends(CATFrFNurbsMultiForm *imultiform, CATMathPoint &oPt1, CATMathPoint &oPt2);
  static int Eval_multiform(CATFrFNurbsMultiForm *imultiform, double iparam, double iTol_param, CATMathPoint &oPoint);

  static int GetEdgeCurveDefaults(CATGeoFactory* ipFactory, CATSoftwareConfiguration* ipConfig, CATEdgeCurve* ipEdgeCurve,
    CATPointOnEdgeCurve* ipStartPOEC, CATPointOnEdgeCurve* ipEndPOEC,
    CATFace* ipFace1, CATPCurve* ipPCurve1, CATFace* ipFace2, CATPCurve* ipPCurve2,
    double& oG0Error, double& oG1Error);

  static int GetEdgeDefaults(CATGeoFactory* ipFactory, CATSoftwareConfiguration* ipConfig, CATEdge* ipEdge, CATBody* ipInBody, CATCrvParam otParamOnRefPcrv[2], double& oG0Error, double& oG1Error);


};

#endif
