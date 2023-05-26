#ifndef CATAutoFilletConstructor_H
#define CATAutoFilletConstructor_H
//===================================================================
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATAutoFilletCATAutoFilletBuildStatus.h
// 		
//===================================================================
//  Feb 2004  Creation: JHG
//===================================================================

#include "CATOracleObject.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATCGMNewArray.h"
#include "CATCGMOutput.h"
#include "ListPOfCATAutoBaseBuildableObjects.h"
#include "ListPOfCATAutoBaseConstructors.h"

#include "CFSEngine.h"

class CATAutoBaseBuildableObject;
class CATPersistentBody;
class CATPersistentCellsJournal;
class CATAutoBaseObjectBuilder;
class CATBuildableObjectSubdivision;
class CATAutoBaseConstructionContext;

class ExportedByCFSEngine CATAutoBaseConstructor : public CATOracleObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation
  DEFINE_ADVOP_CLASS_NAME("CATAutoBaseConstructor")

// USER METHODS
public:
  CATAutoBaseConstructor(CATTopOracle &iOracle);
  virtual ~CATAutoBaseConstructor();

  // returns attached BuildableObject
  CATAutoBaseBuildableObject *GetBuildableObject();

  // to be overriden : this method is called whenever its attached object
  // is ready to be built
  // -> if the status of the object is not "built" at the end of the method,
  //    it is set to failure (if no unleashed constructor is available)
  // allowed methods : SetBuilt(), SetFailure()
  virtual void ConstructBuildableObject(CATAutoBaseConstructionContext &iConstructionContext, 
    CATPersistentCellsJournal *iPersistentCellsJournal) = 0;

  // METHODS to be called only inside ConstructBuildableObject()

    // sets the status of attached buildable object to "built"
    void SetBuilt();
    // sets the status of attached buildable object to "failure"
    void SetFailure();

  // END OF METHODS to be called only inside ConstructBuildableObject()

  // to be overriden : Sets the dependancies of attached BuildableObject
  // allowed methods : SetUnbuildable(), SetExpecting()
  virtual void Init() = 0;

  // METHODS to be called only inside Init()
    // sets the status of attached buildable object to "unbuildable"
    // -> no ConstructBuildableObject() will be ever called
    void SetUnbuildable();
    // SetExpecting() methods set the status of attached buildable object to "unbuildable"
    // and adds expected objects
    // -> ConstructBuildableObject() will be called only when all expected objects have
    //    "built" status
    void SetExpecting(CATAutoBaseBuildableObject *iExpectedObject); // adds one single expected object
    void SetExpecting(ListPOfCATAutoBaseBuildableObjects &iExpectedObjects); // adds a list expected object
  // END OF METHODS to be called only inside Init().
  
  // to be overriden (if needed)
  // returns a new constructor that will be given to the buildable object
  // if this one fails
  virtual CATAutoBaseConstructor *CreateUnleashedConstructor(ListPOfCATAutoBaseConstructors &oOtherUnleashedConstructors);

  virtual CATBoolean IsGeneratingAnExpectingCycle(const ListPOfCATAutoBaseBuildableObjects &iCurrentExpectings,
    ListPOfCATAutoBaseBuildableObjects &oExpectingsToRemoved);

  CATBoolean WouldExpectingLinkCreationCreateACycle(CATAutoBaseBuildableObject &iObject, int iMaxDepth) const;

// END OF USER METHODS



// SYSTEM METHODS (DO NOT USE) ********************************************************
public:
  virtual const char *GetClassDesc();
  
  //virtual int EstimateBuildCost();

  void Dump(CATCGMOutput &iOutput);

  void CallInit(CATAutoBaseObjectBuilder *iObjectBuilder);

  CATBoolean IsBeingInited();

#ifdef AUTOFILLETCOVERAGE
  void SetSubdivided(CATBuildableObjectSubdivision *iSubdivision);
#endif

  void SetBuildableObject(CATAutoBaseBuildableObject *iBuildableObject);
private:
  // SetBeingInited MUST remain private
  void SetBeingInited(CATBoolean iBeingInited);

  CATAutoBaseBuildableObject *_BuildableObject;
  CATBoolean _BeingInited;
};

#endif
