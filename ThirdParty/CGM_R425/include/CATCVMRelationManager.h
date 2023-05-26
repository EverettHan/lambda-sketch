/* -*-C++-*- */

#ifndef CATCVMRelationManager_H
#define CATCVMRelationManager_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMRelationManager
//
// class for Collaborative Variational Modelling (CVM) RelationManager operator
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Aug. 2006    Creation                         AAD
//===================================================================

#include "CATCVMSysOperators.h"
#include "CATCVMSysOperator.h"
#include "ListPOfCATCVMHandle.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATCVMSystem;
class CATCVMRelation;
class CATCVMComponent;
class CATCVMComponent;
class CATCVMContainer;

class ExportedByCATCVMSysOperators CATCVMRelationManager : public CATCVMSysOperator
{
public:
    static CATCVMRelationManager *Create(CATCVMContainer *iContainer, CATCVMRelation * ioRelation);

protected:
    CATCVMRelationManager(CATCVMContainer *iContainer, CATCVMRelation * ioRelation);

public:
    virtual ~CATCVMRelationManager();

public:
   /**
    *Set iHandle to be added to the Relation during Run of this operator
    *Fot iRole definition, see class CATCVMRelation main comments
    */
    void SetHandleToAdd(CATCVMHandle *iHandle, int iRole);
    void SetHandleToSwap(CATCVMHandle *iNewHandle, CATCVMHandle *iOldHandle);
    void SetHandleToRemove(CATCVMHandle *iHandle);
/*    void SetRemove();
    void ToggleActivity();*/
    void Run();

private:
    void FindComponent();
    void AddRemoveHandles();
    void NestHandles();
    CATCVMComponent * FindNearestCommonAncestor(CATCVMComponent * iComponent, ListPOfCATCVMHandle & iHandleList);
    void Nest(CATCVMSystem * iSystem);
    void CheckHandles();

protected:
    CATCVMRelation * _Relation;
    ListPOfCATCVMHandle _HandleListToAdd;
    CATListOfInt _RoleToAdd;
    ListPOfCATCVMHandle _HandleListToSwapNew;
    ListPOfCATCVMHandle _HandleListToSwapOld;
    ListPOfCATCVMHandle _HandleListToRemove;
/*    CATBoolean _Remove;
    CATBoolean _ToggleActivation;*/
    CATCVMComponent * _NestingComponent;

};
#endif
