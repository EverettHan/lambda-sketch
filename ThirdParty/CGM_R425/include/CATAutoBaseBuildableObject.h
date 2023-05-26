#ifndef CATAutoFilletBuildableObject_H
#define CATAutoFilletBuildableObject_H
//===================================================================
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATAutoFilletCATAutoFilletBuildStatus.h
// 		
//===================================================================
//  Feb 2004  Creation: JHG
//===================================================================

#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATCGMNewArray.h"
#include "CATOracleObject.h"
#include "ListPOfCATAutoBaseBuildableObjects.h"
#include "CATCGMOutput.h"

#include "CFSEngine.h"

class CATAutoBaseConstructor;
class CATBuildableObjectSubdivision;
class CATPersistentCellsJournal;
class CATAutoBaseObjectBuilder;
class CATAutoBaseConstructionContext;

enum CATAutoFilletBuildStatus
{
  BsBuilt,
  BsExpecting,
  BsBuildable,
  BsFailure,
  BsUnbuildable//,
//  BsSubdivided
};

class ExportedByCFSEngine CATAutoBaseBuildableObject : public CATOracleObject
{
public:
  DEFINE_ADVOP_CLASS(CATAutoBaseBuildableObject)
  CATCGMNewClassArrayDeclare;      // Pool allocation
// USER METHODS
public: 

  CATAutoBaseBuildableObject(CATTopOracle &iOracle);
  virtual ~CATAutoBaseBuildableObject();

  // specifies the constructor that will be used by the buildable object
  // notice : iConstructor->SetBuildableObject() must be called after this
  void SetConstructor(CATAutoBaseConstructor *iConstructor);

  // method called when the object is set to "built" in order to free some
  // data which is no more needed
  virtual void FreeUselessDataAfterConstruction();

  // this will use a CATAutoBaseWaitConstructor : the object will automatically 
  // be set to "built" when iObjectsToWait are all built
  void UseWaitConstructor(ListPOfCATAutoBaseBuildableObjects &iObjectsToWait);

  // this will use a CATAutoBaseFailureConstructor : the object will automatically 
  // be set to "failure" the next time the system will try to build it
  void UseFailureConstructor();

  // progress bar : must be overidden in order to give the system a relative estimation
  // of the time cost of this object
  virtual double GetBuildCostEstimation();

  CATBoolean IsIndirectlyExpectingObject(CATAutoBaseBuildableObject &iObject, int iMaxDepth) const;

  void SolveCycles();
// SYSTEM METHODS (DO NOT USE) *************************************************
public:
  CATAutoFilletBuildStatus GetStatus();
  virtual void OnFailure();

  void Build(CATAutoBaseObjectBuilder *iObjectBuilder,
    CATAutoBaseConstructionContext &iConstructionContext, CATPersistentCellsJournal *iPersistentCellsJournal);
  void InitConstructor(CATAutoBaseObjectBuilder *iObjectBuilder);

  void MYSTERIOUS_FUNCTION_A(CATAutoBaseConstructor *);//SetBuilt
//  void MYSTERIOUS_FUNCTION_B(CATAutoBaseConstructor *);//SetBuildable
  void MYSTERIOUS_FUNCTION_C(CATAutoBaseConstructor *);//SetFailure
#ifdef AUTOFILLETCOVERAGE
  void MYSTERIOUS_FUNCTION_D(CATAutoBaseConstructor *);//SetUnbuildable
#endif
#ifdef AUTOFILLETCOVERAGE
  void MYSTERIOUS_FUNCTION_E(CATAutoBaseConstructor *, CATBuildableObjectSubdivision *);//SetSubdivided
#endif

  void MYSTERIOUS_FUNCTION_F(CATAutoBaseConstructor *, CATAutoBaseBuildableObject *);//SetExpecting
  void MYSTERIOUS_FUNCTION_G(CATAutoBaseConstructor *, ListPOfCATAutoBaseBuildableObjects &);//SetExpecting
  //void MYSTERIOUS_FUNCTION_H(CATAutoBaseConstructor *, ListPOfCATAutoBaseBuildableObjects &);//UnsetExpecting

  CATBoolean UpdateStatus();

  CATBoolean GetConstructorNeedsInit();

#ifdef AUTOFILLETCOVERAGE
  CATBuildableObjectSubdivision *ReadSubdivision();

  virtual void ManageActivation();
  virtual void ManageDeactivation();

  void Activate();
  void Deactivate();
#endif
  virtual CATBoolean IsNeededForSewing();

  CATBoolean IsActive();
#if 0
  int EstimateBuildCost();
#endif

  virtual void NCGMShow();
  virtual CATBoolean EstimateMiddle(CATMathPoint &oMiddle);

  void GetExpecting(ListPOfCATAutoBaseBuildableObjects &oExpectedObjects);

  void CheckReferenceObject(CATAutoBaseConstructor *iReferenceConstructor, CATBoolean iNeedInit);

  void EndOfConstructionMode();

//  virtual int GetDifficulty();

private:
  CATAutoBaseConstructor *_Constructor;
  CATBoolean _ConstructorNeedsInit;

  CATAutoFilletBuildStatus _BuildStatus;
  ListPOfCATAutoBaseBuildableObjects _ExpectedBuildableObjects;
  int _SetBuildableCount;
#if 0
  CATBuildableObjectSubdivision *_Subdivision;
#endif
  void SetStatus(CATAutoFilletBuildStatus iStatus);

  CATBoolean _Active;
  CATBoolean _BeingBuilt;
  CATBoolean _ConstructionMode;
  void StatusTracking();

  void PrivateSetBuilt();
  void PrivateSetBuildable();
  void PrivateSetFailure();
  void PrivateSetUnbuildable();
#ifdef AUTOFILLETCOVERAGE
  void PrivateSetSubdivided(CATBuildableObjectSubdivision *iSubdivision);
#endif

  void PrivateSetExpecting(ListPOfCATAutoBaseBuildableObjects &iExpectedObjects);
  void PrivateUnsetExpecting(ListPOfCATAutoBaseBuildableObjects &iExpectedObjects);

  void UseUnleashedConstructorOrSetFailure();

protected:
  void DumpConstructor(CATCGMOutput &iOutput);
};

#endif
