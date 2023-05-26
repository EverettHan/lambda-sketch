#ifndef CATAutoFilletObjectBuilder_H
#define CATAutoFilletObjectBuilder_H
//===================================================================
// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATAutoBaseObjectBuilder.h
// 		
//===================================================================
//  Oct 2003  Creation: JHG
//===================================================================

#include "CATOracleObject.h"
#include "ListPOfCATAutoBaseBuildableObjects.h"
#include "CATCGMNewArray.h"
#include "CATListOfInt.h"

#include "CFSEngine.h"

class CATPersistentCellsJournal;
class CATAutoBaseProgressBar;
class CATAutoBaseConstructionContext;

class ExportedByCFSEngine CATAutoBaseObjectBuilder : public CATOracleObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation
  DEFINE_ADVOP_CLASS(CATAutoBaseObjectBuilder)

  CATAutoBaseObjectBuilder(CATTopOracle &iOracle,
    CATAutoBaseConstructionContext &iConstructionContext,
    CATBoolean iEnableTreeExpansion);

  virtual ~CATAutoBaseObjectBuilder();

  // Append a list of objects to be built
  // example : in many cases,
  // iNumberOfBuildableObjectsPerGroup.Size() = 1 and iNumberOfBuildableObjectsPerGroup[1] = iObjects.Size()
  void AppendObjects(ListPOfCATAutoBaseBuildableObjects &iObjects,
    CATListOfInt &iNumberOfBuildableObjectsPerGroup);

  // builds the CSF
  void Run();

  // specifies objects to be used in order to compute the progress bar
  void SetObjectsForBuildCostComputation(ListPOfCATAutoBaseBuildableObjects *iObjects);

  void GetAllCreatedObjects(ListPOfCATAutoBaseBuildableObjects &oAllCreatedObjects);
  
  void SetPersistentCellsJournal(CATPersistentCellsJournal *iPersistentCellsJournal);
  void SetProgressBar(CATAutoBaseProgressBar *iProgressBar, int iStepId);

  // DEBUG ONLY  !!!
  void SetBuildOnly(CATListOfInt &iBuildOnlyObjectTags);
  void UpdateBuildOnlyObjects();

  CATBoolean IsObjectBeingBuilt(CATAutoBaseBuildableObject *iObject);

private:
  void UpdateBuildObjectList(ListPOfCATAutoBaseBuildableObjects &iObjectsToCheck, ListPOfCATAutoBaseBuildableObjects &ioObjects);
//  void PreliminaryInitAllConstructors();
  ListPOfCATAutoBaseBuildableObjects _Objects;
  CATListOfInt _NumberOfBuildableObjectsPerGroup;

  ListPOfCATAutoBaseBuildableObjects *_ObjectsForBuildCostComputation;
  
  ListPOfCATAutoBaseBuildableObjects _AllCreatedObjects;

  CATPersistentCellsJournal *_PersistentCellsJournal;
  CATAutoBaseProgressBar *_ProgressBar;
  int _ProgressBarStepId;

  CATAutoBaseBuildableObject *_BeingBuiltObject;

  CATAutoBaseConstructionContext &_ConstructionContext;

  CATBoolean _BuildOnly;
  CATListOfInt _BuildOnlyObjectTags;
  ListPOfCATAutoBaseBuildableObjects _BuildOnlyObjects;

  CATBoolean _EnableTreeExpansion;
};

#endif
