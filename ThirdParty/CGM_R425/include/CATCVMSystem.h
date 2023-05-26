/* -*-C++-*- */

#ifndef CATCVMSystem_H
#define CATCVMSystem_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) systems
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
#include "CATCVMObject.h"
#include "CATCVMDef.h"
#include "CATCVMLog.h"

#include "ListPOfCATCVMAtom.h"
#include "ListPOfCATCVMPort.h"
#include "ListPOfCATCVMSystem.h"

#include "CATCGMNewArray.h"

class CATCVMComponent;
class CATCVMPort;
class CATCVMAtom;
class CATUnicodeString;
class CATCVMContainer;
class CATCVMCopy;

class ExportedByCATCVMSysObjects CATCVMSystem : public CATCVMObject
{
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMSystem(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor 
  //TODO: must be made protected when migration on correct AddRef/Release is completed
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMSystem();

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
  // CheckUp the CVMSystem
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT CheckUp(int iCVMEvent=CVMLogEvent_Modify);
  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);

  //------------------------------------------------------------------------------
  // Get the number of ports
  //------------------------------------------------------------------------------
  public:
  int GetNbPorts();

  //------------------------------------------------------------------------------
  // Get the port for a given index
  //------------------------------------------------------------------------------
  public:
  CATCVMPort *GetPort(int iIndex);

  //------------------------------------------------------------------------------
  // Add a port
  //------------------------------------------------------------------------------
  public:
  void AddPort(CATCVMPort *iPort);

  //------------------------------------------------------------------------------
  // Remove a port
  //------------------------------------------------------------------------------
  public:
  void RemovePort(int iIndex);

  //------------------------------------------------------------------------------
  // Remove a port
  //------------------------------------------------------------------------------
  public:
  void RemovePort(CATCVMPort *iPort);

  //------------------------------------------------------------------------------
  // Get the number of ports
  //------------------------------------------------------------------------------
  public:
  int GetNbAtoms();

  //------------------------------------------------------------------------------
  // Get the atom for a given index
  //------------------------------------------------------------------------------
  /*
  public:
  CATCVMAtom *GetAtom(int iIndex);
  */
  //------------------------------------------------------------------------------
  // Add a atom
  //------------------------------------------------------------------------------
  public:
  void AddAtom(CATCVMAtom *iAtom, CATCVMObject * iCVMNext=NULL);

  //------------------------------------------------------------------------------
  // Remove a atom
  //------------------------------------------------------------------------------
  public:
  void RemoveAtom(CATCVMAtom *iAtom);

  //------------------------------------------------------------------------------
  // SetOwnerComponent
  //------------------------------------------------------------------------------
  public:
  void SetOwnerComponent(CATCVMComponent *iComponent);

  //------------------------------------------------------------------------------
  // GetOwnerComponent
  //------------------------------------------------------------------------------
  public:
  CATCVMComponent *GetOwnerComponent();

  //------------------------------------------------------------------------------
  // Find the CVM port that points to a given CVM handle
  //------------------------------------------------------------------------------
  //public:
  //CATCVMPort *FindPort(CATCVMHandle *iHandle);

  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  virtual void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  void LocalDataCopy(CATCVMSystem *iCVMPrev);

  //------------------------------------------------------------------------------
  // Swap Definition from CVMPhoto for Undo / Redo Treatment
  //------------------------------------------------------------------------------
  virtual void UndoRedoDataSwapping(CATCVMObject *iCVMObject, int iCVMEvent);

  //------------------------------------------------------------------------------
  // Forget copy information
  //------------------------------------------------------------------------------
  //public:
  //virtual void ForgetCopy(CATCVMCopy *iCopy);

  //------------------------------------------------------------------------------
  // Duplicate all atoms and ports in iToSystem
  //------------------------------------------------------------------------------
  private:
  void DuplicateAtomsAndPorts(CATCVMSystem *iToSystem,
                              CATCVMCopy   *iCopy);

  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  protected:
  virtual void CopyAllData(CATCVMObject *iInitialObject,
                           CATCVMCopy   *iCopy=NULL,
                           int           iLight=0);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();
  
  //------------------------------------------------------------------------------
  // Chain management
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMObject *Get_Atom_Next();
  virtual CATCVMObject *Get_Atom_Prev();
  virtual void Set_Atom_Next(CATCVMObject * iCVMNext);
  virtual void Set_Atom_Prev(CATCVMObject * iCVMPrev);
  CATCVMAtom * GetNextAtom(CATCVMAtom * iAtom = NULL );
  CATCVMAtom * GetNextAtom(CATCVMAtom * iAtom , CATCVMObjectType iObjectType );

  CATCVMAtom * GetPreviousAtom(CATCVMAtom * iAtom = NULL );
  HRESULT SwapAtomLoops(CATCVMSystem *iCVMSystem); // WARNING this method must be used with swap of CGMBody

  //------------------------------------------------------------------------------
  // System chain management
  //------------------------------------------------------------------------------
  protected:
  virtual HRESULT       SetNextSystem         (CATCVMSystem *iNextSystem);
  virtual HRESULT       SetPrevSystem         (CATCVMSystem *iPrevSystem);
  virtual HRESULT       SetAccessSystem       (CATCVMSystem *iAccessSystem);
  virtual HRESULT       SetInternalOwnerSystem(CATCVMSystem *iOwnerSystem);
          HRESULT       SetOwnerSystem        (CATCVMSystem *iOwnerSystem);
  virtual CATCVMSystem *GetInternalNextSystem ();
  virtual CATCVMSystem *GetInternalPrevSystem ();
  
  public:
  virtual CATCVMSystem *GetOwnerSystem ();
  virtual CATCVMSystem *GetAccessSystem();
          CATCVMSystem *GetNextSystem  (CATCVMSystem *iFirstSystem = NULL);
          CATCVMSystem *GetPrevSystem  (CATCVMSystem *iFirstSystem = NULL);
  
  //------------------------------------------------------------------------------
  // Add a sub-system
  //------------------------------------------------------------------------------
  public:
    virtual HRESULT AddSystem(CATCVMSystem *iSystem, CATBoolean IsNew=FALSE );
    HRESULT       RemoveFromSystemLoop();

  public:
    HRESULT       AddToSystemChain     (CATCVMSystem *iOwnerSystem);
    HRESULT       RemoveFromSystemChain();
  
  public : 
  virtual CATCVMObject* FindObjectFromTag (CATULONG32 iTag);

  public :
  virtual void Dump(ostream * iStream=0L, int idecal=0) const;

  //------------------------------------------------------------------------------
  // transfer an object from its current contaienr to a new container
  //------------------------------------------------------------------------------
  public :
  virtual void Transfer(CATCVMContainer     *iTargetContainer,
                        ListPOfCATCVMObject &ioObjectsToTransfer);

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory)=0;
  virtual void    Stream   (CATCVMSysStream* CVMStr)=0;

  virtual void    GetLinkedGeometry (CATCVMSysStream* iCVMStr)=0;
  virtual void    CleanIsStreamed ()=0;

  void   Set_System_Next(CATCVMSystem * iCVMNext);
  void   Set_System_Prev(CATCVMSystem * iCVMPrev);
  CATCVMSystem *Get_System_Next();
  CATCVMSystem *Get_System_Prev();

  //virtual void    GetCATCVMGeoMesh(CATLISTP(CATCVMSystem)& OutGeoMesh )=0;

  protected :
  void UnStreamAtoms (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  void UnStreamPorts (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  void StreamAtoms (CATCVMSysStream* Str);
  void StreamPorts (CATCVMSysStream* Str);
  void GetLinkedGeometryFromAtoms (CATCVMSysStream* Str);
  void GetLinkedGeometryFromPorts (CATCVMSysStream* Str);

  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  protected :
  CATBoolean CompareAtoms (CATCVMSystem *iRef);
  CATBoolean ComparePorts (CATCVMSystem *iRef);

  public :
  // only for debug (cgmreplay)
  virtual CATCVMObject * FindObjectFromName (CATString& iName);


  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  
  protected:
  CATCVMComponent *_OwnerComponent;

  private:
  CATCVMObject * _Atom_Prev;
  CATCVMObject * _Atom_Next;

  CATCVMSystem * _System_Prev;
  CATCVMSystem * _System_Next;
 
  ListPOfCATCVMPort _PortList;

  
};
#endif
