#ifndef CATFrFFilletStyleGlobalNurbsOpe_H
#define CATFrFFilletStyleGlobalNurbsOpe_H
//
//=============================================================================
// Copyright Dassault Systemes Provence 2009-2015, all rights reserved
//=============================================================================
//
// CATFrFFilletStyleGlobalNurbsOpe: Operator for approximation of fillet surface
//                                  one by one or together as concatenation.
//
//=============================================================================
// Usage notes:
//=============================================================================
// 10/03/15 : HLN ; Add CATCGMProgressBar + Interruption management
// 26/06/14 : HLN ; Add GetWarningStatus
// 13/09/11 : HLN ; Add SetSimplify to be able not to simplify (FALSE)
// 02/07/09 : MWE ; Creation 
//=============================================================================
#include "CATFrFFilletStyle.h"
#include "CATDataType.h"
#include "CATCGMOperator.h"
#include "CATListOfCATSurfaces.h"
#include "CATListOfCATCurves.h"
#include "CATFreeFormDef.h"
#include "CATFrFFSError.h"
class CATBody;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATFrFFSFilletDevInfo;
class CATFrFImproveFilletSurfaces;
class CATCGMProgressBar;

//-----------------------------------------------------------------------------
class ExportedByCATFrFFilletStyle CATFrFFilletStyleGlobalNurbsOpe : public CATCGMOperator
{
public:
  // don't use
  // use CATCreateFrFFilletStyleGlobalNurbsOpe, see below
  CATFrFFilletStyleGlobalNurbsOpe (CATGeoFactory *iFactory);

  virtual ~CATFrFFilletStyleGlobalNurbsOpe(){};

  //Default value =2
  virtual void SetConnectionContinuity(const CATFrFContinuity iContinuity) = 0;

  // geometric join for the approximation 
  // Default value = 1 (0=no join, 1=join)
  virtual void SetGeometricJoin(int iJoin) = 0;

  //Default values:
  // iApproxTol= resolution
  // iOrder = 6
  // iMaxSeg = 1000
  virtual void SetApproxParameter(double iApproxTol, int iOrder, int iMaxSeg) = 0;

  //Default values:
  // Postol= resolution=0.001
  // TanTol = 0.2 degre 
  // CrvTol = 0.05  i.e. 5%
  // G3Tol = 0.2 degre 
  virtual void SetGapTolerances(double iPosTol, double iTanTol, double iCrvTol, double iG3Tol) = 0;
  
  // iSmallSurfMode:   
  // 0 no skipping of small surfaces
  // 1 small surfaces will be stitched to its neighbour with the highest continuity
  // 2 small surfaces will be ripped up on its diagonal and stiched to its neigbour
  // iSmallSurfTol : minimum length of the accepted small face, all under this length are removed
  virtual void RemoveSmallFaces(double iSmallSurfTol, int iSmallSurfMode = 1) = 0;

  // iMode=0 : no improvement; =1 improvment by PlateFE
  // iImproveFillets is an instance of CATFrFImproveFilletSurfaces created by CATCreateFrFFSImproveFilletSurfaces in SurfacicGeoOperators
  virtual void SetImproveConnections(int iMode, CATFrFImproveFilletSurfaces * iImproveFillets=NULL) = 0;

  // If improvment by PlateFE, it allows to define the constraints with a MapX instead of 3D curve
  // 0 Without MapX Default
  // 1 With MapX
  virtual void SetMapXConstraint(int iWithMapX) = 0;

  // to merge successive fillets having the same support surface 1 and 2
  virtual void SetSimplify(CATBoolean iSimplify = TRUE) = 0;

  virtual CATLISTP(CATSurface) *GetResult() = 0;

  virtual CATFrFFSError::Error GetStatus() = 0;

  virtual CATFrFFSWarning::Warning GetWarningStatus() = 0;

  // oResOfFillet : index defining the order of the resulting list according to iFilletFaces
  //                oResOfFillet[i] = j : the ith result surface corresponds to the jth cell of the input body
  // oResOfBase1 : index of the support in iBaseBody1
  //                oResOfBase1[i] = j : the ith result surface is on the jth cell of the input body
  // oResOfBase2 : index of the support in iBaseBody2
  virtual void GetIndexOfFilletAndBases(CATListOfInt &oResOfFillet ,CATListOfInt &oResOfBase1, CATListOfInt &oResOfBase2) = 0;
 
  virtual void GetTracesOfFillets(CATLISTP(CATCurve) &oTracesOnBase1 ,CATLISTP(CATCurve) &oTracesOnBase2) = 0;
  virtual void GetQualityOfConnections(CATListOfInt &oConnectionQuality) = 0;
  virtual CATFrFFSFilletDevInfo *GetDeviationOnBase1() = 0;
  virtual CATFrFFSFilletDevInfo *GetDeviationOnBase2() = 0;
  
  virtual void SetParentProgressBar(CATCGMProgressBar *iParentProgressBar) = 0;
};

//-----------------------------------------------------------------------------
//Creation functions :
ExportedByCATFrFFilletStyle  
CATFrFFilletStyleGlobalNurbsOpe *CATCreateFrFFilletStyleGlobalNurbsOpe (CATGeoFactory *iFactory,
                                                        CATSoftwareConfiguration *iConfig,
                                                        CATBody *iBaseBody1,
                                                        CATBody *iBaseBody2,
                                                        CATBody *iFilletBody);
#endif

