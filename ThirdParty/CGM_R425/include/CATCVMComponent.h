/* -*-C++-*- */

#ifndef CATCVMComponent_H
#define CATCVMComponent_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) components
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2006    Creation                         Alex State
//===================================================================
#include "CATCVMSysObjects.h"
#include "CATCVMSystem.h"
#include "CATCVMDef.h"
#include "ListPOfCATCVMRelation.h"
#include "ListPOfCATCVMSystem.h"
#include "ListPOfCATCVMComponent.h"

class CATCVMContainer;
class CATCVMSysStream;
#define   CVMComponent_Structure_Optimization_2010_09_22

class CATUnicodeString;
class ExportedByCATCVMSysObjects CATCVMComponent : public CATCVMSystem
{

	public:
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // CreateComponent
  //------------------------------------------------------------------------------
  public:
  static CATCVMComponent *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMComponent(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMComponent();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  private:
  void CleanUp();
  
  //------------------------------------------------------------------------------
  // ReleaseData
  //------------------------------------------------------------------------------
  public:
  virtual void ReleaseData();
  
  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Get the number of relations
  //------------------------------------------------------------------------------
  public:
  int GetNbRelations();

  //------------------------------------------------------------------------------
  // Get the relation for a given index
  //------------------------------------------------------------------------------
  public:
  CATCVMRelation *GetRelation(int iIndex);

  //------------------------------------------------------------------------------
  // Add a relation
  //------------------------------------------------------------------------------
  public:
  void AddRelation(CATCVMRelation *iRelation);

  //------------------------------------------------------------------------------
  // Remove a relation
  //------------------------------------------------------------------------------
  public:
  void RemoveRelation(int iIndex);

  //------------------------------------------------------------------------------
  // Remove a relation
  //------------------------------------------------------------------------------
  public:
  void RemoveRelation(CATCVMRelation *iRelation);

  //------------------------------------------------------------------------------
  // Get the number of sub-systems
  //------------------------------------------------------------------------------
  public:
  int GetNbSystems();

  //------------------------------------------------------------------------------
  // Get the sub-system for a given type
  //------------------------------------------------------------------------------
  public:
  CATCVMSystem * GetNextSystemInComponent(CATCVMSystem * iPrev , CATCVMObjectType iObjectType );
  CATCVMSystem * GetNextSystemInComponent(CATCVMSystem * iPrev );
  CATCVMSystem * GetPreviousSystemInComponent(CATCVMSystem * iPrev );
  
  CATCVMSystem *GetSystem(int iIndex); // deprecated 

  //------------------------------------------------------------------------------
  // Add a sub-system
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT AddSystem(CATCVMSystem *iSystem, CATBoolean IsNew=FALSE );

  //------------------------------------------------------------------------------
  // Remove a sub-system
  //------------------------------------------------------------------------------
  public:
  virtual void RemoveSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // SetOldReference
  //------------------------------------------------------------------------------
  //public:
  //void SetOldReference(CATCVMComponent *iReference);

  //------------------------------------------------------------------------------
  // GetOldReference
  //------------------------------------------------------------------------------
  //public:
  //CATCVMComponent *GetOldReference();

  //------------------------------------------------------------------------------
  // Get the number of instances
  //------------------------------------------------------------------------------
  //public:
  //int GetNbInstances();

  //------------------------------------------------------------------------------
  // Get the instance for a given index
  //------------------------------------------------------------------------------
  //public:
  //CATCVMComponent *GetInstance(int iIndex);

  //------------------------------------------------------------------------------
  // Add a instance
  //------------------------------------------------------------------------------
  //public:
  //void AddInstance(CATCVMComponent *iInstance);

  //------------------------------------------------------------------------------
  // Remove a instance
  //------------------------------------------------------------------------------
  //public:
  //void RemoveInstance(int iIndex);

  //------------------------------------------------------------------------------
  // Remove a instance
  //------------------------------------------------------------------------------
  //public:
  //void RemoveInstance(CATCVMComponent *iInstance);

  //------------------------------------------------------------------------------
  // Get all the relations (including those under any subcomponents)
  //------------------------------------------------------------------------------
  public:
  void GetAllRelations(ListPOfCATCVMRelation &oRelationList, CATBoolean iOnlyActive);

  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *CreateCopy(CATCVMCopy *iCopy=NULL);

  protected:
  void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  void LocalDataCopy(CATCVMComponent * iCVMPrev);
  
  //------------------------------------------------------------------------------
  // transfer an object from its current contaienr to a new container
  //------------------------------------------------------------------------------
  public :
  void Transfer(CATCVMContainer     *iTargetContainer,
                ListPOfCATCVMObject &ioObjectsToTransfer);

  //------------------------------------------------------------------------------
  // UndoRedo method
  //------------------------------------------------------------------------------
  virtual void  UndoRedoDataSwapping (CATCVMObject *iCVMObject, int iCVMEvent);
  
  //------------------------------------------------------------------------------
  // Forget copy information
  //------------------------------------------------------------------------------
  //public:
  //virtual void ForgetCopy(CATCVMCopy *iCopy);

  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  virtual void CopyAllData(CATCVMObject *iInitialObject,
                           CATCVMCopy   *iCopy=NULL,
                           int           iLight=0);

  //------------------------------------------------------------------------------
  // Copy a system add and it as subsystem
  //------------------------------------------------------------------------------
  protected:
  virtual CATCVMSystem *CopyAsSubSystem(CATCVMSystem *iSystem,
                                        CATCVMCopy   *iCopy);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream   (CATCVMSysStream* CVMStr);
  virtual void    GetLinkedGeometry (CATCVMSysStream* CVMStr); 

  public : 
  virtual CATCVMObject* FindObjectFromTag (CATULONG32 iTag);
  virtual void CleanIsStreamed ();
  
  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L) const;
  
  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATCVMComponent        *_Reference;
  ListPOfCATCVMRelation   _RelationList;
  int                     _NbSystems;
  //ListPOfCATCVMSystem     _SystemList;
  //ListPOfCATCVMComponent  _InstanceList;

};
#endif
