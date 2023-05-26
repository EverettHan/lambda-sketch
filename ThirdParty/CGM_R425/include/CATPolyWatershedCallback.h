#ifndef CATPolyWatershedCallback_h__
#define CATPolyWatershedCallback_h__


//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolyWatershedCallback.h
// Header definition of struct CATPolyWatershedCallback
//===================================================================
//
// Usage notes: Allow to share the computation progress 
//
//===================================================================
// HISTORIQUE :
// xx/08/2017 : NUA : Heritage de CATBaseUnknown, rajout des methodes pour indiquer le nombre d'extensions a calculer, et le nombre d'étapes de calcul
// 22/03/2017 : NUA : Creation
//===================================================================

#include "CATBaseUnknown.h"


  #include <unordered_map>
  #include <unordered_set>
  #include <string>


struct CATPolyWatershedCallback : public CATBaseUnknown
{
  /*
  @iOperatorName : name of the current operator (example : SteepestSlopeOpe, RidgeValleyOpe, etc)
  @iFunctionName : name of the function of the current operator that is currently busy making computation
  */
  virtual void SetCurrentStageName(const char * iOperatorName, const char * iFunctionName) = 0;

  /*
  @ival : a value between 0 and 1 that describe the current progress of the computation
  */
  virtual void SetProgress(const double ival, const char * iStepName = NULL) = 0;


  /*
  Interrupt method.
  return a bool : if true, all current computations are stopped
  */
  virtual bool CancelOperation() = 0;

  /*
  Specify the number of extensions (of ridge and valley) will be computed
  */
  virtual void SetNbExtensions(size_t ) {}


  /*
  for watershed operators, the Run method will invoke the SetComputeStageNames method of the CATPolyWatershedCallback class
  It allow to get 
  - the name of the current operator
  - the sub 
  */
  virtual void SetComputeStageNames(const std::string & , const std::unordered_map<std::string, size_t> & ) {}


  enum KindOfWatershedError
  {
    K_NoError,
    K_NullAreaTriangle,                            // some triangles have null triangle (or less than CATTolerance.AreaEpslion)
    K_BadlyOrientedNormal,                         // some triangles have a normal with negative z-component
    K_SelfIntersectionInFlow,                      // two water paths intersect (
    K_InvalidStartPointPosition,
    K_InvalidEndPointPosition,
    K_InvalidContributorSeed,
    K_NonManifoldMesh,
    K_NoPreviousInit,
    K_InvalidBasinDepth,
    K_InvalidBasin,
    K_InvalidBasinBoundary,
    K_InvalidSegmentation,
    K_PathNotReachingOutlet,
    K_NoSlope,
    K_NullPtr,
    K_InvalidFlowDirection,
    K_InvalidVertexSlope,
    K_InvalidPathSegment,
    K_EmptyPath,
    K_ErrCopyMesh,
    K_ErrMeshIterator,
    K_BadVertexIndex,
    K_ErrMeshEdition,
    K_ErrPathExtender,
    K_ErrPathTruncation,
    K_InvalidPolygon,
    K_ErrSubdivisionInsertion,
    K_ErrSubdivisionIndex,
    K_ErrSubdivisionTriangulate,
    K_ErrSubdivisionMakePolygon,
    K_ErrSubdivisionBoundary,
    K_ErrMeshSimplification,
    K_ErrFlatAreaOpe,
    K_ErrGetHoleOpe,
    K_ErrRingOpe,
    K_ErrIndexOpe,
    K_ErrSlopeOpe,
    K_ErrRVOpe,
    K_SaddlePathOpe,
    K_FlowInit,
    K_FlowRun,
    K_Watershed_Init,
    K_Watershed_Merge,
    K_Watershed_Segment,
    K_Watershed_Embeed,
    K_FlatAreaTilterOpe,
    K_InvalidVertexPosition,
    K_TooManyEltsInPath,
    K_NonOrientableMesh,
    K_EmptyMesh
    
  };

  virtual void SetError(KindOfWatershedError k)  {}

};

#endif // CATPolyWatershedCallback_h__
