/* -*-C++-*- */

#ifndef CATCVMInstance_H
#define CATCVMInstance_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMInstance
//
// class for Collaborative Variational Modelling (CVM) instances
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Nov. 2007    Creation                         Alex State
//===================================================================
#include "CATMacForRtti.h"
#include "CATCVMSysObjects.h"
#include "CATCVMSystem.h"
#include "CATCVMDef.h"
#include "CATMathTransformation.h"
#include "CATCGMNewArray.h"

class CATCVMContainer;
class CATCVMPSContainer;
class CATCVMSysStream;
class CATCVMReference;
//class CATCVMOccurrence;

class CATUnicodeString;
class ExportedByCATCVMSysObjects CATCVMInstance : public CATCVMSystem
{

	public:
  CATDeclareClass_Deprec;
  //------------------------------------------------------------------------------
  // CreateComponent
  //------------------------------------------------------------------------------
  public:
  static CATCVMInstance *Create(CATCVMPSContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMInstance(CATCVMPSContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMInstance();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  private:
  void CleanUp();
  
  //------------------------------------------------------------------------------
  // ReleaseData
  //------------------------------------------------------------------------------
  public:
  void ReleaseData();
  
  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *CreateCopy(CATCVMCopy *iCopy=NULL);

  protected:
  void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  void LocalDataCopy(CATCVMInstance * iCVMPrev);
  
  //------------------------------------------------------------------------------
  // Swap Definition from CVMPhoto for Undo / Redo Treatment
  //------------------------------------------------------------------------------
  void UndoRedoDataSwapping(CATCVMObject *iCVMObject, int iCVMEvent);
  
  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  protected:
  void CopyAllData(CATCVMObject *iInitialObject, CATCVMCopy *iCopy=NULL, int  iLight=0);
                          
  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // SetTransformation
  //------------------------------------------------------------------------------
  public:
  HRESULT SetTransformation(CATMathTransformation &iTransformation);
  
  //------------------------------------------------------------------------------
  // GetTransformation (returns _TransformationHasBeenSet)
  //------------------------------------------------------------------------------
  public:
  CATBoolean GetTransformation (CATMathTransformation &oTransformation);

  //------------------------------------------------------------------------------
  // Public system chain management
  //------------------------------------------------------------------------------
  public:
  CATCVMReference *GetCVMReference ();
  CATCVMInstance  *GetNextCVMInstance (CATCVMInstance *iFirstInstance=NULL);

  //------------------------------------------------------------------------------
  // System chain management - do not use!
  //------------------------------------------------------------------------------
  protected:
  HRESULT       SetNextSystem          (CATCVMSystem *iNextSystem);
  HRESULT       SetPrevSystem          (CATCVMSystem *iPrevSystem);
  //HRESULT       SetAccessSystem        (CATCVMSystem *iAccessSystem);
  HRESULT       SetInternalOwnerSystem (CATCVMSystem *iOwnerSystem);
  CATCVMSystem *GetInternalNextSystem  ();
  CATCVMSystem *GetInternalPrevSystem  ();
  public:
  CATCVMSystem    *GetOwnerSystem (); // use GetCVMReference() instead
  //CATCVMSystem    *GetAccessSystem();

  //------------------------------------------------------------------------------
  // transfer an object from its current contaienr to a new container
  //------------------------------------------------------------------------------
  public :
  void Transfer(CATCVMContainer     *iTargetContainer,
                ListPOfCATCVMObject &ioObjectsToTransfer);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATMathTransformation  _Transformation;
  CATBoolean             _TransformationHasBeenSet;
  CATCVMReference       *_OwnerReference;
  CATCVMInstance        *_PrevInstance;
  CATCVMInstance        *_NextInstance;
  //CATCVMOccurrence      *_AccessOccurrence;

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  void    Stream   (CATCVMSysStream* CVMStr);
  void    GetLinkedGeometry (CATCVMSysStream* CVMStr); 
  void    CleanIsStreamed ();

 //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  CATBoolean Compare (CATCVMObject *iRef);
  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L, int idecal=0) const;

  //for cgmreplay
  public :
  virtual CATCVMObject* FindObjectFromTag (CATULONG32 iTag);
  virtual CATCVMObject * FindObjectFromName (CATString& iName);


};
#endif
