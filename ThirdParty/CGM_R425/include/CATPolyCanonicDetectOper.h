// COPYRIGHT DASSAULT SYSTEMES 2008-2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicDetectOper.h
//
//===================================================================
//
// Usage notes: Find canonics (planes, cylinders, cones, fillets) 
// in a Mesh
//
//===================================================================
//
// 07  2017 : ANR : Ajout Mesh2BRep_SegmInPlanes=1
// Jan 2011 : MMO : Ajout de la methode IsGDDFillet pour centraliser le code
// Dec 2010 : MMO : Ajout du rayon max pour les Fillets MaxRadius
// Jan 2008 : ZFI : Creation
//===================================================================

#ifndef CATPolyCanonicDetectOper_H
#define CATPolyCanonicDetectOper_H

#include "CATPolyCanonicOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATIPolyMesh.h"
#include "CATMathVector.h" 
#include "CATListOfDouble.h" 
#include "CATListPV.h"
#include "CATMapOfIntToInt.h"
#include "CATLib.h" 
class CATPolyPlaneFinder ;
class CATIPolySurfaceFacetIterator;
class CATPolyIntegerSetPartition;
class CATPolyIntegerSetCover;
class CATPolySegmentLayer;
class CATIPolySurface; 

class CATIPolyCurveVertexIterator;
class CATIPolyCurve;

class CATPolyCanonicOperTol;
class CATPolyCanonicOperOptions;

class CATPolyGeometric2DPatch;  
class CATPolySegmentManager;
class CATPolyCanonicOperData;
class CATPolyPartitionManager;
class CATMathPlane ; 

class CATIPolyMeshTriangleIterator;
class CATPolyPointMeshDistanceAccelerator;
class CATPolyPointMeshDistance;

class CATPolyContour; 
class CATPolyTopoUtil ;
class CATIPolySurfaceVertexFacetNeighborhood ;
class CATPolyBars ;
class CATPolyGeometricForm;

class ExportedByCATPolyCanonicOperators CATPolyCanonicDetectOper
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicDetectOper();
  virtual ~CATPolyCanonicDetectOper();

  /**
  *  Set Tolerance pour le mode digit
  *  iMode = 1 ----> Tesselle
  *  iMode = 2 ----> Digit
  */
  void fitting_tolerance(double itol = 0.5, CATBoolean iMode = 2);

  /**
  *  Set Tolerances
  */
  HRESULT SetToleranceExact(float iTolExact);
  HRESULT SetToleranceSag(float iTolSag);
  HRESULT SetToleranceAlign(float iTolAlign);
  HRESULT SetToleranceAlignExact(float iTolAlignExact);
  HRESULT SetToleranceSNT(float iSNT);
  HRESULT SetFilletMaxRadius(float  iMaxRadius=200.0); // Rayon Maximum pour les Fillets
  HRESULT GetFilletMaxRadius(float &oMaxRadius);
  
  /** 
  *  Set Options
  */
  HRESULT SetBands2Circles(int iActivate);
  HRESULT SetBands1Circle(int iActivate);
  HRESULT SetBandsUniform(int iActivate);
  HRESULT SetBandsRevol(int iActivate);
  HRESULT SetCylinderConeDetection(int iActivate);
  HRESULT SetTorusDetection(int iActivate);
  HRESULT SetFilletDetection(int iActivate);
  HRESULT SetFreeSurfDetection(int iActivate);
  HRESULT SetPlaneSurfDetection(int iActivate);

  /**
  /* UV Interpolation
  */
  HRESULT SetUseUVInterpolation(int iActivate);
 
  // Re-segmenter les FreeSurf
  void SegmFreeSurf(CATBoolean iActivateMode = FALSE) ; 


  //maillage pas vraiment tesselle ou grossier ... Pr CPU dans les etapes de marge
  //WithAllStep = FALSE : On donne que l'init
  //WithAllStep = TRUE : On fait les etapes de merges mais on limite les iteratoins des que la zone est complexe
  void SetProcessingCoarseMesh(CATBoolean iWithAllStep = TRUE) ;


  /**
  * Run
  */
  HRESULT Run(CATIPolySurface &iSurface, 
              CATIPolySurfaceFacetIterator &iFacetIterator , 
              CATPolyIntegerSetPartition& ioFacetPartition,
              CATPolySegmentLayer* ioSegmentLayer=0, 
              CATBoolean iNewVersion=FALSE);


  HRESULT Run(CATIPolyCurve &iCurve, CATIPolyCurveVertexIterator &iVertexIterator , 
              CATPolyIntegerSetCover& ioVerticesCover,CATPolySegmentLayer* ioSegmentLayer=0);

  // ANR : Seulement Pour Debug - Ne pas appeler
  void SetStepMerge(int iStepMerge) ;

  void ForceComputeSag(CATBoolean iMode) ;

  /**
  * Pour Trimer les Fillets : Appel lors de la construction du PolyBody
  */
  int RunTrimFillet(CATIPolySurface *iSurface,  
                        CATPolyIntegerSetPartition   *ioFacetPartition,
                        CATPolySegmentLayer          *ioSegmentLayer);

  // ANR : Seulement Pour Debug - Ne pas appeler
  void Get_ZonesToDebug(CATListPV &oListPolyMesh, CATListOfInt &oListOfType) ;

  void GetPartitionInfos(CATListOfInt &oInfosNbFaces, 
                         CATListOfInt &oInfosNbTriangles, 
                         CATListOfDouble &oInfosCPU,
                         CATListOfDouble &oInfosSmallZones) ;

  // On rend la liste de triangles qui ne sont pas pris dans la segmentation
  void GetSmallAngleTriangles(CATListOfInt &oListOfTr) ;

  // Gets the sag tolerance used while running the operator. If _ComputeAutoSag
  // is true, this may not be the same as the value set by SetToleranceSag.
  double GetToleranceSag() const;

private:
 
  int InitAlloc(CATIPolySurface *iSurface, CATPolyCanonicOperData *idata) ;

  void RemoveDuplicatesFacets(CATPolyCanonicOperData &iData,
                              CATPolyPartitionManager &ipartitionManager,
                              CATPolySegmentManager &isegmentManager) ;

  void EstimateSagFromInit(CATPolySegmentManager &isegmentManager) ;

  void GetNeighborsOfFacet(CATPolyCanonicOperData &iData,
                           int iFacet, CATListOfInt &oNeighb) ;

  // Fonctions dans CATPolyCanonicDetectOperAdvanced.cpp ==================================
  // ======================================================================================
  
  void AnalyseCylinderPatchs(CATIPolyMesh *iPolyMesh, 
                             CATPolyCanonicOperData &iData,
                             CATPolyPartitionManager &ipartitionManager,
                             CATPolySegmentManager &isegmentManager, 
                             double iMinimumArea=0.) ;
  
  void AnalyseConePatchs(CATIPolyMesh *iPolyMesh, 
                         CATPolyCanonicOperData &iData,
                         CATPolyPartitionManager &ipartitionManager,
                         CATPolySegmentManager &isegmentManager, 
                         double iMinimumArea=0.) ;

  void AnalyseConeCylinderPatchs(CATIPolyMesh *iPolyMesh, 
                             CATPolyCanonicOperData &iData,
                             CATPolyPartitionManager &ipartitionManager,
                             CATPolySegmentManager &isegmentManager,
                             CATPolySegmentLayer   *ioSegmentLayer) ;
 
  void AnalyseTorusPatchs(CATIPolyMesh *iPolyMesh, 
                          CATPolyCanonicOperData &iData,
                          CATPolyPartitionManager &ipartitionManager,
                          CATPolySegmentManager &isegmentManager, 
                          double iMinimumArea) ;
      
  void AnalysePlanarPatches(CATIPolyMesh *iPolyMesh,  
                            CATPolyCanonicOperData &iData,
                            CATPolyPartitionManager &ipartitionManager,
                            CATPolySegmentManager &isegmentManager,
                            CATBoolean iOptionNeigb = TRUE) ;

  void RemoveIsolateTriangles(CATIPolyMesh *iPolyMesh,  
                              CATPolyCanonicOperData &iData,
                              CATPolyPartitionManager &ipartitionManager,
                              CATPolySegmentManager &isegmentManager) ;

  void RemoveSmallPatches(CATIPolyMesh *iPolyMesh,  
                          CATPolyCanonicOperData &iData,
                          CATPolyPartitionManager &ipartitionManager,
                          CATPolySegmentManager &isegmentManager) ;

  //void AnalyseSmallPatch(CATIPolyMesh *iPolyMesh,
  //                       CATPolyGeometric2DPatch* ipatch,
  //                       CATListOfInt &iListVrt,
  //                       CATMathVector *iNormals, 
  //                       double iTolAxis,
  //                       CATBoolean &oSameRadius,
  //                       CATBoolean &oSameAxis) ;
 
  void SegmentationOfFreeSurf(CATIPolyMesh *iPolyMesh, 
                              CATPolyCanonicOperData &iData,
                              CATPolyPartitionManager &ipartitionManager,
                              CATPolySegmentManager &isegmentManager,
                              CATPolySegmentLayer   *ioSegmentLayer);

  void CreatePatchFromGeoForm(int IndexPatch,
                              CATPolyCanonicOperData &iData,
                              CATPolyPartitionManager &ipartitionManager,
                              CATPolySegmentManager   &isegmentManager,
                              CATPolySegmentLayer     *ioSegmentLayer,
                              CATPolyGeometricForm    &iForm,
                              CATListOfInt            &iListOfFacets) ;

  // Fonctions dans CATPolyCanonicDetectOperMergesStep.cpp ================================
  // ======================================================================================

  void MergesPlanarPatchs(CATIPolyMesh *iPolyMesh, 
                          CATPolyCanonicOperData &iData,
                          CATPolyPartitionManager &ipartitionManager,
                          CATPolySegmentManager &isegmentManager,
                          double iMinimumArea=0.) ;

  CATBoolean MergesTwoFreeSurf(CATIPolyMesh *iPolyMesh, 
                               CATPolyCanonicOperData &iData,
                               CATPolyPartitionManager &ipartitionManager,
                               CATPolySegmentManager &isegmentManager, 
                               int Index1, int Index2, double iTolFree,
                               CATListOfInt &ioPatchsToRemove) ;

  void MergesFreeSurfPatchs(CATIPolyMesh *iPolyMesh, 
                            CATPolyCanonicOperData &iData,
                            CATPolyPartitionManager &ipartitionManager,
                            CATPolySegmentManager &isegmentManager,
                            double iMinimumArea=0.) ;

  void AnalyseAllPatches(CATIPolyMesh *iPolyMesh, 
                         CATPolyCanonicOperData &iData,
                         CATPolyPartitionManager &ipartitionManager,
                         CATPolySegmentManager &isegmentManager,
                         CATPolySegmentLayer   *ioSegmentLayer,
                         double iMinimumArea=0.) ;

  HRESULT PropagateFacet(int Type, 
                         CATPolyCanonicOperData &iData,
                         CATPolyPartitionManager &ipartitionManager,
                         CATPolySegmentManager &isegmentManager, 
                         int iIdxFacet, int& oIdxPatch, double iTolerance,
                         CATBoolean StopCanonic=FALSE) ;

  HRESULT ConnexePropagateFacet(CATPolyCanonicOperData &iData,
                               CATPolyPartitionManager &ipartitionManager,
                               CATPolySegmentManager &isegmentManager,  
                               int iIdxFacet,
                               CATListOfInt &oConnexeList) ;

  void AnalyseConnexityOfPatch(CATPolyCanonicOperData &iData,
                               CATPolyPartitionManager &ipartitionManager,
                               CATPolySegmentManager &isegmentManager,  
                               int IndexPatch,
                               CATBoolean iFixedPrincipalPatch,
                               CATBoolean &oRemovePatch,
                               CATListOfInt &oIndexOfNewPatch) ;

  void AnalyseConnexity(CATPolyCanonicOperData &iData,
                        CATPolyPartitionManager &ipartitionManager,
                        CATPolySegmentManager &isegmentManager) ;

  void AnalyseConnexity(CATListOfInt &iListToAnalyse,
                        CATPolyCanonicOperData &iData,
                        CATPolyPartitionManager &ipartitionManager,
                        CATPolySegmentManager &isegmentManager) ;


  void CorrectionConeCylinder_SagError(CATIPolyMesh *iPolyMesh, 
                                       CATPolyCanonicOperData &iData,
                                       CATPolyPartitionManager &ipartitionManager,
                                       CATPolySegmentManager &isegmentManager, 
                                       CATPolySegmentLayer   *ioSegmentLayer,
                                       double iTolSharp, double iPropagateTol, CATBoolean StopCanonic=FALSE) ;

  void CorrectionPatchs_SagError(int Type,  
                                 CATIPolyMesh *iPolyMesh,  
                                 CATPolyCanonicOperData &iData,
                                 CATPolyPartitionManager &ipartitionManager,
                                 CATPolySegmentManager &isegmentManager, 
                                 double iTolSharp,
                                 double iPropagateTol,
                                 CATBoolean StopCanonic=FALSE) ;


  void LastMergeOfFreeSurf(CATIPolyMesh *iPolyMesh, 
                            CATPolyCanonicOperData &iData,
                            CATPolyPartitionManager &ipartitionManager,
                            CATPolySegmentManager &isegmentManager) ;


  void ExtrairePlanDuCylindre(CATIPolyMesh *iPolyMesh, 
                              CATPolyCanonicOperData &iData,
                              CATPolyPartitionManager &ipartitionManager,
                              CATPolySegmentManager &isegmentManager,
                              int &iIndexPatch,
                              CATBoolean &oFoundPlanar) ;

  void ExtrairePlanarPatch(CATIPolyMesh *iPolyMesh,  
                           CATPolyCanonicOperData &iData,
                           CATPolyPartitionManager &ipartitionManager,
                           CATPolySegmentManager &isegmentManager,
                           CATBoolean &oFoundPlanar) ;

  void MergeFilletStep(CATIPolyMesh *iPolyMesh,  
                           CATPolyCanonicOperData &iData,
                           CATPolyPartitionManager &ipartitionManager,
                           CATPolySegmentManager &isegmentManager,
                           CATPolySegmentLayer   *ioSegmentLayer) ;


  void TrimFilletStep(CATIPolyMesh *iPolyMesh,  
                           CATPolyCanonicOperData &iData,
                           CATPolyPartitionManager &ipartitionManager,
                           CATPolySegmentManager &isegmentManager,
                           CATPolySegmentLayer   *ioSegmentLayer) ;

  HRESULT ConnexeExpandFacet(CATIPolyMesh *iPolyMesh,
                             CATPolyCanonicOperData &iData,
                             CATPolyTopoUtil *iPolyTopo,
                             CATPolyBars &iBars,
                             int iIdxFacet,
                             CATListOfInt &iStopedList,
                             CATListOfInt &oConnexeList) ;

  // Fonctions dans CATPolyCanonicDetectOperComputeStep.cpp =================================
  // ======================================================================================

  void DetectCanonicsForms(CATIPolyMesh *iPolyMesh, 
                           CATPolyCanonicOperData &iData,
                           CATPolyPartitionManager &ipartitionManager,
                           CATPolySegmentManager &isegmentManager,
                           CATPolySegmentLayer   *ioSegmentLayer,
                           double iRatioArea = 16.) ;

  int FoundInitForDetectTorus(CATIPolyMesh *iPolyMesh,
                              int index,
                              CATPolyGeometric2DPatch* ipatch,
                              double iEstimateRadius,
                              CATPolyCanonicOperData &iData,
                              CATPolyPartitionManager &ipartitionManager,
                              CATPolySegmentManager &isegmentManager,
                              CATListOfDouble &oListOfRadius,
                              CATListOfDouble &oListOfCenter,
                              CATListOfDouble &oListOfAxis) ;


  // Nouvelle approche :
  void DetectCanonicsForms_2(CATIPolyMesh *iPolyMesh,  
                             CATPolyCanonicOperData &iData,
                             CATPolyPartitionManager &ipartitionManager,
                             CATPolySegmentManager &isegmentManager,
                             CATPolySegmentLayer   *ioSegmentLayer,
                             double iRatioArea = 16.) ;
 

  void DetectTypeOfPatch(int *iTypedetect, CATIPolyMesh *iPolyMesh, 
                                                 CATPolyCanonicOperData &iData,
                                                 CATPolyPartitionManager &ipartitionManager,
                                                 CATPolySegmentManager &isegmentManager,
                                                 CATPolySegmentLayer   *ioSegmentLayer,
                                                 double iCurrentArea,
                                                 CATListOfInt &iFacetList,
                                                 CATListOfInt &iVerticesList, 
                                                 CATMathVector *iNormals_p,
                                                 double iRatioArea,
                                                 CATListOfInt &iDistanceVertices,
                                                 int &oNewIndex) ;

  void DetectTypeOfPatchWithInit(int *iTypedetect, 
                                                         CATListOfDouble &InitRadius,
                                                         CATListOfDouble &InitAlpha,
                                                         CATListOfDouble &InitCenter,
                                                         CATListOfDouble &InitAxis, 
                                                         CATIPolyMesh *iPolyMesh, 
                                                         CATPolyCanonicOperData &iData,
                                                         CATPolyPartitionManager &ipartitionManager,
                                                         CATPolySegmentManager &isegmentManager,
                                                         CATPolySegmentLayer   *ioSegmentLayer,
                                                         double iCurrentArea,
                                                         CATListOfInt &iFacetList,
                                                         CATListOfInt &iVerticesList, 
                                                         double iRatioArea,
                                                         CATListOfInt &iDistanceVertices,
                                                         int &oNewIndex) ;


 void NewMethodForDetectCanonicsForms(CATIPolyMesh *iPolyMesh,  
                                      CATPolyCanonicOperData &iData,
                                      CATPolyPartitionManager &ipartitionManager,
                                      CATPolySegmentManager &isegmentManager,
                                      CATPolySegmentLayer   *ioSegmentLayer,
                                      double iRatioArea = 16.) ;


 void DetectOneForm(int indexPatch,
                    CATIPolyMesh *iPolyMesh, 
                    CATPolyCanonicOperData &iData,
                    CATPolyPartitionManager &ipartitionManager,
                    CATPolySegmentManager &isegmentManager,
                    CATBoolean *iDetectionTab, 
                    int &oNewIndex,
                    CATBoolean iForceDetect = FALSE) ;

 void LastCallForDetectForms (CATIPolyMesh *iPolyMesh,  
                                      CATPolyCanonicOperData &iData,
                                      CATPolyPartitionManager &ipartitionManager,
                                      CATPolySegmentManager &isegmentManager) ;

 void  NewMethodForExpandCanonicsForms(CATIPolyMesh *iPolyMesh, 
                                       CATPolyCanonicOperData &iData,
                                       CATPolyPartitionManager &ipartitionManager,
                                       CATPolySegmentManager &isegmentManager,
                                       CATPolySegmentLayer   *ioSegmentLayer) ;


  void ComputeCaracteristicOfConic(double *ioB, CATMathPoint &oCenterSVD, CATMathPoint &oCenterINV, CATMathVector &oAxis) ;

  // Fonctions dans CATPolyCanonicDetectOperCleaner.cpp =================================
  // ======================================================================================
 
  int getEdgeRightTriangle(int a, int b, CATIPolyMesh * PolyMesh) ;

  int ComputeLoopOfPatch(CATIPolyMesh   *MyPolyMesh,
                         CATIPolyMesh   *aPolyMesh,
                         CATPolyContour *PolyContour,
                         int             iNbLoop,
                         CATListOfInt   *iMapContour,
                         int             index, 
                         CATListOfInt   &oStartIndex,
                         CATListOfInt   &oEndIndex,
                         CATListOfInt   &oNeigbSide) ;
 
  void PatchsCleaner_SmallZones(CATIPolyMesh *iPolyMesh,   
                                CATPolyPartitionManager &ipartitionManager, 
                                CATPolySegmentManager &isegmentManager,
                                CATPolyCanonicOperData &iData ) ;

  void PatchsBorderCleaner(CATIPolyMesh *iPolyMesh,   
                           CATPolyPartitionManager &ipartitionManager, 
                           CATPolySegmentManager &isegmentManager,
                           CATPolyCanonicOperData &iData) ;

  void PatchsCleaner_Step0(CATIPolyMesh *iPolyMesh,   
                           CATPolyPartitionManager &ipartitionManager, 
                           CATPolySegmentManager &isegmentManager,
                           CATPolyCanonicOperData &iData,
                           int iIndexPatch, 
                           int *ioVisitedFacets, 
                           CATListOfInt &oModifyPatchs) ;

  void PatchsCleaner_Step1(CATIPolyMesh *iPolyMesh,   
                           CATPolyPartitionManager &ipartitionManager, 
                           CATPolySegmentManager &isegmentManager,
                           CATPolyCanonicOperData &iData,
                           int iIndexPatch,
                           CATListOfInt &oModifyPatchs) ; 

  void PatchsCleaner_Step2(CATIPolyMesh *iPolyMesh,   
                           CATPolyPartitionManager &ipartitionManager, 
                           CATPolySegmentManager &isegmentManager,
                           CATPolyCanonicOperData &iData,
                           int iIndexPatch) ; 

  void AnalyseOscillationsOnContour(CATIPolyMesh *iPolyMesh,    
                                    CATPolySegmentManager &isegmentManager,
                                    int iIndexPatch,
                                    CATMapOfIntToInt *&ioMapOfFixedBorder) ;

  void  PatchsCleaner(CATIPolyMesh *iPolyMesh, 
                      CATPolyPartitionManager &ipartitionManager, 
                      CATPolySegmentManager &isegmentManager,
                      CATPolyCanonicOperData &iData) ;

  // Fonctions dans CATPolyCanonicDetectOperUtilities.cpp =================================
  // ======================================================================================

  void CorrectionPlanarSurf(CATIPolyMesh *iPolyMesh, 
                                                    CATPolyCanonicOperData &iData,
                                                    CATPolyPartitionManager &ipartitionManager,
                                                    CATPolySegmentManager &isegmentManager) ;

  HRESULT PropagateFacetPlane(CATIPolyMesh *iPolyMesh, CATPolyCanonicOperData &iData,
                                                      CATPolyPartitionManager &ipartitionManager,
                                                      CATPolySegmentManager &isegmentManager,  
                                                      int iIdxFacet, CATMathPlane &iRefPlane, double iTolPlane,
                                                      int& oIdxPatch) ;

  CATBoolean VerifNbTriangles(int iTargetNbTriang, CATPolySegmentManager &isegmentManager) ;

  CATBoolean InertialFrame_P (const int      iNbPoints,
                              const double*  iCoords,
                              double         oBarycenter[3],
                              double         oEigenValues[3],
                              double         oEigenVectors[3][3]) ;

  int ComputeMeanPlane_P(int NbPoints, double *VerticesCoords, CATMathPlane &oBasePlane, CATBoolean iTest=FALSE) ;

  double EstimateAreaOfPatch(CATIPolyMesh *iPolyMesh, CATPolyGeometric2DPatch *ipatch) ;
  double EstimateDiagonalOfPatch(CATIPolyMesh *iPolyMesh, CATPolyGeometric2DPatch *ipatch) ;
  int EvalCurvature(double xx, double yy, double zz, double *iB, double &oKK, double &oHH) ;
  int EvalPrincipalCurvature(double xx, double yy, double zz, double *iB, double &ok1, double &ok2) ;

  int ComputeConic(CATIPolyMesh *iPolyMesh, CATListOfInt &VerticesList, CATMathVector *iNormalList, double ioB[] ) ;

  int ComputeConic(int iNbPoints, CATMathPoint *iTabPts, CATMathVector *iNormalList, double ioB[] ) ;

  int ComputeConic_withoutNormal(CATIPolyMesh *iPolyMesh, CATListOfInt &VerticesList, double ioB[] ) ;
 
  void ComputeNormalsOfPatch(CATIPolyMesh *iPolyMesh, CATPolyGeometric2DPatch *ipatch,
                             int &oNbfacets, CATMathVector *&oNormals) ;

  void ComputeNormalsVerticesOfPatch(CATIPolyMesh *iPolyMesh, CATPolyGeometric2DPatch *ipatch,
                                     CATListOfInt &oVerticesList, CATMathVector *&oNormals) ;

  void ComputeNormalsVerticesOfPatch(CATIPolyMesh *iPolyMesh, 
                                     CATPolyGeometric2DPatch *ipatch1, CATPolyGeometric2DPatch *ipatch2,
                                     CATListOfInt &oVerticesList, CATMathVector *&oNormals) ;

  CATBoolean VerifEquation(double iToler, double *iCoeff, CATMathPoint &iPoint ) ;

  CATBoolean HasSameInertialFrame(CATIPolyMesh *iPolyMesh, 
                                  CATPolyGeometric2DPatch *ipatch1, 
                                  CATPolyGeometric2DPatch *ipatch2,
                                  double &othetaNormal,
                                  double AxisTol = 10.) ;

  int sgn(double ivalue, double itolNul) ;

  double MedianFacet(CATIPolyMesh *iPolyMesh, int ifacet) ;
  void MaxMedianPatch(CATIPolyMesh *iPolyMesh, CATPolyGeometric2DPatch *ipatch, double &oMaxMedian, double &oMeanMedian) ;
  CATBoolean ComparePatches(CATIPolyMesh *iPolyMesh, CATPolyGeometric2DPatch *ipatch1, CATPolyGeometric2DPatch *ipatch2, double &oRatio) ;
  CATBoolean AdvancedComparePatches(CATIPolyMesh *iPolyMesh, CATPolyGeometric2DPatch *ipatch1, CATPolyGeometric2DPatch *ipatch2, double &oRatio) ;
  CATBoolean CompareTwoFacets(CATIPolyMesh *iPolyMesh, int ifacet1, int ifacet2, double &oratio ) ;
  CATBoolean AdvancedCompareTwoFacets(CATIPolyMesh *iPolyMesh, int ifacet1, int ifacet2, double &oratio ) ;
  double CompareFacetWithPatch(CATIPolyMesh *iPolyMesh, int ifacet, CATPolyGeometric2DPatch *ipatch, int iNbValuesTest, int iTypeTest) ;

  void UpdateLocateFacet(CATPolySegmentManager &isegmentManager, int iIndexPatch) ;
  void UpdateLocateFacet(CATPolySegmentManager &isegmentManager) ;

  void UpdatePatchTopologyAnr(CATPolyPartitionManager &ipartitionManager,
                                                         CATPolySegmentManager   &isegmentManager,
                                                         CATPolyCanonicOperData &iData,
                                                         int iIdxPatch) ;

  void UpdatePatchNeighborhoodAnr(CATPolyPartitionManager &ipartitionManager,
                                                          CATPolySegmentManager   &isegmentManager,
                                                          CATPolyCanonicOperData &iData,
                                                          int iIdxPatch) ;

  void BoundaryFacetsOfPatch(CATIPolyMesh *iPolyMesh, 
                             CATPolyCanonicOperData &iData,
                             CATPolyGeometric2DPatch *ipatch,
                             CATListOfInt &oBoundaryFacets) ; 
 

  int ApproximatePatchBySphere(CATIPolyMesh *iPolyMesh, CATListOfInt &VerticesList,  CATMathVector *iNormalList,
                               CATMathPoint &oCenter, double &oRadius, CATMathPoint &oPt_MaxCurvature ) ;


  void ComputeSeedOfPatch(CATIPolyMesh *iPolyMesh, 
                          CATPolyGeometric2DPatch *ipatch,
                          int &oTriangleIndex) ;

  CATBoolean DistancePtsToTorus(int iNbPoints, CATMathPoint *iTabOfPoints,
                                double iSmallRadius, double iBigRadius,
                                CATMathPoint &iCenter, CATMathVector &iAxis,
                                double iTolerance, double &oPourc) ;

  CATBoolean DistancePtsToSphere(int iNbPoints, CATMathPoint *iTabOfPoints,
                                 double iRadius, CATMathPoint &iCenter, double iTolerance, double &oPourc) ;

  CATBoolean DistancePtsToCylinder(int iNbPoints, CATMathPoint *iTabOfPoints,
                                 double iRadius, CATMathPoint &iCenter, CATMathVector &iAxis, double iTolerance, double &oPourc) ;

  double MaxDistancePtsToCylinder(int iNbPoints, CATMathPoint *iTabOfPoints,
                                  double iRadius, CATMathPoint &iCenter, CATMathVector &iAxis) ;


  CATBoolean DistancePtsToCone(int iNbPoints, CATMathPoint *iTabOfPoints,
                                double iRadius1, double iRadius2, 
                                CATMathPoint &iCenter1, CATMathPoint &iCenter2, CATMathVector &iAxis, double iTolerance, double &oPourc) ;


  int DistanceFacetToPatch(CATIPolyMesh *iPolyMesh, int iFacet, CATPolyGeometric2DPatch* ipatch,
                           double &odistVrt, double &odistTr) ;

  void ComputeNeighboorOfTwoPatchs(CATIPolyMesh *iPolyMesh, CATPolyCanonicOperData &iData,
                                   CATPolySegmentManager &isegmentManager,
                                   int *iLocateFacetInPatch, int index1, int index2, 
                                   CATListOfInt &oBoundary1, CATListOfInt &oBoundary2) ;

  // oIndexVrt : Vertex le plus proche
  void DistancePointToPolyMesh(CATIPolyMesh *iPolyMesh, CATMathPoint &iPointToProject, 
                               int &oIndexVrt, int &oIndexTr, CATMathPoint &oProjectedPoint) ;

  // iPoints : les 3 sommets du triangles
  CATBoolean AddFacetToCanonicPatch(CATMathVector &iNormalTri, CATMathPoint *iPoints, CATPolyGeometric2DPatch* ipatch) ;

  void ComputeInitForNewton(CATIPolyMesh *iPolyMesh, 
                            CATPolyCanonicOperData &iData,
                            CATPolyGeometric2DPatch* ipatch)  ;

  void PrintResults(CATIPolyMesh *MyPolyMesh, 
                    CATPolySegmentManager &segmentManager,
                    CATPolySegmentLayer   *SegmentLayer,
                    double InitSegmentCPU=0., double MergesSegmentCPU=0., double FilletSegmentCPU=0.) ;

  CATBoolean IsGDDFillet (CATIPolyMesh * iPolyMesh, CATPolyCanonicOperData &iData, 
                          int iIndexPatch[], int iNbFacetsPatchs[], CATListOfInt &iListOfTriangles, double & oRayon );

  int OrderSections(CATIPolyMesh * iPolyMesh, CATPolyCanonicOperData &iData, int iIndexPatch[]) ;

  void CVGOnPatch(CATIPolyMesh *iPolyMesh, CATPolySegmentManager &isegmentManager, int iIndexPatch) ;
  void UpdateParametersOfPatch(CATIPolyMesh *iPolyMesh, CATPolySegmentManager &isegmentManager, int iIndexPatch) ;

  void StartGetCPU() ;
  void EndGetCPU() ;

  void PrintCurrentNbPatches(CATPolySegmentManager &isegmentManager) ;

  void ComputeDistFacetsToPatches(CATIPolyMesh *iPolyMesh, CATPolySegmentManager &isegmentManager) ;

  //
  void ExpandWithNormal(CATIPolyMesh *iPolyMesh, int iIdxFacet, CATMathVector &InitNormal, CATListOfInt &oExpandList);
  void QuickMergesPlanarPatchs(CATIPolyMesh *iPolyMesh, CATPolyCanonicOperData &iData,
                               CATPolyPartitionManager &ipartitionManager, CATPolySegmentManager &isegmentManager);

  //===========================================================================

  static const double _epsg ; 
  static const double _epsf ;  
  static const double _epsx ; 

  CATPolyCanonicOperTol* _Tolerance;
  CATPolyCanonicOperOptions* _Options;
  CATBoolean _UseUVInterpolation;  
 
  double _MaxErrorCylinder, _MinErrorCylinder ;
  CATBoolean _DetectSmallZones ;

  CATBoolean _NewAlgoVersion ;

  int _StepMerge, _CurrentStep ;
  double _EstimateSag ;
  double _EstimateSagCylinder ;
  double _MinimumArea, _AreaOfMesh ;

  CATBoolean _FixedSagFromInit ;
  double     _SagFromInit ; 
  CATBoolean _ComputeAutoSag ;

  int *_LocateFacetInPatch ;

  CATListOfInt _IndexPatches ;
  CATListOfInt _CurrentNbFacets ;

  CATListOfInt _InitCylinders ;
  //CATListOfInt _ExtractPlanes ;
 
  int _PositionWork ;
  CATMapOfIntToInt *_ExtractPlanes ;

  CATBoolean _InitCylinder, _InitCone ;
  CATListOfDouble _RadiusInit, _CenterInit, _AxisInit, _InitSag;

  CATBoolean _ForceDetection ;
  int _StartIndexToExpand ;
  CATListOfInt _NewPatchesDetected ;

  CATBoolean _NewCanonicsDetected ;
  int _StepAnalysis ; 

  CATIPolyMeshTriangleIterator* _TriangleIterator;
  CATPolyPointMeshDistanceAccelerator* _PointMeshDistanceAccelerator;
  CATPolyPointMeshDistance* _PolyPointMeshDistanceOperator;

  CATBoolean _DetectTorus ;
  float _MaxRadius; // Rayon maximum pour les Fillets.

  CATListPV _ListPolyMesh_ToDebug ;
  CATListOfInt _ListOfType_ToDebug ;


  // Comme on fait le calcul a chaque fois, il vaut mieux les calculer des le debut
  int _NbTriangles, _NbVertices;
  CATMathPoint *_Points ;
  CATMathVector *_Normals_T, *_Normals_V ;
  CATMathPoint *_CenterFacets ;
  double *_FacetArea, *_MedianFacet ;


  CATListOfInt _NeighbTr ; // Size = 3*_NbTriangles ;
  int _NeighborOfFacetMode ;

  CATBoolean _TestGeoTr ;

  // Pour debug/Print
  CATListOfInt _InfosNbFaces, _InfosNbTriangles ;
  CATListOfDouble _InfosCPU, _InfosSmallZones ;
 
  int _DebugFacet ;
  int _StepCleanBorder ;
  CATListOfInt _WorkList ;

  double _WorkSagForExpand ;
  int    _WorkIndexPatch ;


  // Parametres de travail pour les fillets
  double _WorkParamForDist ;
  CATBoolean _ProfiledSurf ;
  int _NfOfSections ;
  double *_SectionRadius ;
  CATMathPoint  *_SectionCenter;
  CATMathVector *_SectionAxis;
  CATListOfDouble *_SectionPoints;
 
  CATBoolean _ActivateSegmOnFreeSurf ;

  CATListOfInt _WorkFacetsList_i, _WorkFacetsList_j ; // Pour la propagation
  double      _WorkDistance ;


  CATTimerId _SolveTime ;
  CATULONG32 _cpu ;


  CATMapOfIntToInt *_MapNoExpandCylinder ;
  CATMapOfIntToInt *_MapNoExpandTorus ;


  CATListOfInt _SmallAngleTriangles ;

  double *_distVrtToPatch ;
  double *_distTrToPatch  ;

  double _InitSegmentCPU ;

  //
  CATBoolean _ProcessingCoarseMesh, _WithAllStep  ;

  double _fitting_tol;
  int    _mode_tess_digit;

};

#endif
