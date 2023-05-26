#ifndef CATPolyMeshWatershedCallback_h__
#define CATPolyMeshWatershedCallback_h__

#include "CATPolyMeshWatershedOperators.h"

//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolyMeshWatershedCallback.h
// Header definition of struct CATPolyMeshWatershedCallback
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

#ifdef _WINDOWS_SOURCE
  #include <unordered_map>
  #include <unordered_set>
  #include <string>
#endif

struct ExportedByCATPolyMeshWatershedOperators CATPolyMeshWatershedCallback : public CATBaseUnknown
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
  virtual void SetNbExtensions(size_t iNb) {}

#ifdef _WINDOWS_SOURCE
  /*
  for watershed operators, the Run method will invoke the SetComputeStageNames method of the CATPolyMeshWatershedCallback class
  It allow to get 
  - the name of the current operator
  - the sub 
  */
  virtual void SetComputeStageNames(const std::string & iOpeName, const std::unordered_map<std::string, size_t> & iStageName) {}
#endif

};

#endif // CATPolyMeshWatershedCallback_h__
