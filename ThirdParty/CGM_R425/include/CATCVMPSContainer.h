/* -*-C++-*- */

#ifndef CATCVMPSContainer_H
#define CATCVMPSContainer_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMPSContainer
//
// Collaborative Variational Modelling (CVM) Container class
// for product structure data
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// April. 2008    Creation                         Alex State
//===================================================================
#include "CATCVMContainer.h"

#include "CATCVMSysObjects.h"
#include "CATCVMSession.h"

#include "CATBoolean.h"
#include "ListPOfCATCVMSystem.h"
#include "ListPOfCATCVMRelation.h"
#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCVMAttrRef.h"
#include "ListPOfCATCVMContainer.h"
#include "CATCVMAttributeDef.h"
#include "CATCVMDef.h"
#include "CATDataType.h"
#include "CATCGMNewArray.h"
#include "CATErrorDef.h"

class CATCVMObject;
class CATCGMStream;
class CATCVMSysStream;
class CATCVMColorRef;
class CATCVMComponent;
class CATSysSimpleHashTable;
class CATCVMReference;
class CATCVMSession;

class ExportedByCATCVMSysObjects CATCVMPSContainer : public CATCVMContainer
{
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
  public:
  CATDeclareClass;

  //------------------------------------------------------------------------------
  // Allocation par pool
  //------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Create a container
  //------------------------------------------------------------------------------
  public:
  static CATCVMPSContainer *CreateContainer(CATCVMSession *iFederator);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMPSContainer(CATCVMSession *iFederator);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMPSContainer();

  //------------------------------------------------------------------------------
  // Clean up
  //------------------------------------------------------------------------------
  public:
  void CleanUp();

  //------------------------------------------------------------------------------
  // Get the root reference
  //------------------------------------------------------------------------------
  public:
  CATCVMReference *GetRootReference();

  //------------------------------------------------------------------------------
  // Set the root reference
  //------------------------------------------------------------------------------
  public:
  HRESULT SetRootReference(CATCVMReference *iRootReference);

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  public:
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L) const;
  // iUnfold : 0 = reuse dump, 1 = unfold dump
  void GraphDump(ostream * iStream=0L, ListPOfCATCVMObject * iHighLight=0, int iUnfold=0) const;
  
  //------------------------------------------------------------------------------
  // Stream/Unstream
  //------------------------------------------------------------------------------
  public:
  virtual void Stream(CATCVMSysStream* Str,CATBoolean iDebug=FALSE);
  virtual void UnStream( CATCVMSysStream* Str, CATBoolean iSuppressMainComponent=FALSE,
                         CATBoolean iKarcherIsolatedVertices=FALSE);

  CATCVMObject* FindObjectFromTag (CATULONG32 iTag);

  protected :
  virtual CATCVMObject * CreateObjectfromType (int iType);

  public : 
  HRESULT GetAllContainers (ListPOfCATCVMContainer & oListe);

  //------------------------------------------------------------------------------
  // methods for cgmreplay only
  //------------------------------------------------------------------------------
public:
  CATCVMObject * FindObjectFromName (CATString& iName);
  void SetNamingForCVMInstances ();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATCVMReference *_RootReference;
};
#endif
