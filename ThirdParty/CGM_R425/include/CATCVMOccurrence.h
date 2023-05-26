/* -*-C++-*- */
/*
#ifndef CATCVMOccurrence_H
#define CATCVMOccurrence_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) occurrence
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Nov. 2007    Creation                         Francois Dujardin
//===================================================================
#include "CATCVMSysObjects.h"
#include "CATCVMComponent.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATCVMContainer;
class CATCVMSysStream;
class CATCVMInstance;
class CATUnicodeString;

class ExportedByCATCVMSysObjects CATCVMOccurrence : public CATCVMComponent
{

	public:
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // CreateComponent
  //------------------------------------------------------------------------------
  public:
  static CATCVMOccurrence *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMOccurrence(CATCVMContainer *iContainer);

  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMOccurrence();

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

  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public :
  CATCVMSystem * CreateCopy(CATCVMCopy *iCopy);

  //------------------------------------------------------------------------------
  // UndoRedo method
  //------------------------------------------------------------------------------
  void  UndoRedoDataSwapping (CATCVMObject *iCVMObject, int iCVMEvent);

  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  protected:
  virtual void CopyAllData(CATCVMObject *iInitialObject,
                           CATCVMCopy   *iCopy=NULL,
                           int           iLight=0);

  //------------------------------------------------------------------------------
  // Add a sub-system
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT AddSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Public system chain management
  //------------------------------------------------------------------------------
  CATCVMInstance   * GetCVMInstance();
  CATCVMOccurrence * GetNextCVMOccurrence (CATCVMOccurrence *iFirstOccurrence=NULL);

  //------------------------------------------------------------------------------
  // System chain management - do not use!
  //------------------------------------------------------------------------------
  protected:
  virtual HRESULT       SetNextSystem          (CATCVMSystem *iNextSystem);
  virtual HRESULT       SetPrevSystem          (CATCVMSystem *iPrevSystem);
  virtual HRESULT       SetInternalOwnerSystem (CATCVMSystem *iOwnerSystem);
  virtual CATCVMSystem *GetInternalNextSystem  ();
  virtual CATCVMSystem *GetInternalPrevSystem  ();
  public:
  virtual CATCVMSystem   *GetOwnerSystem (); // use GetCVMInstance() instead

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private :
  CATCVMInstance   * _OwnerInstance;    // Instance of the occurrence
  CATCVMOccurrence * _NextOccurrence; // next in the chain of the occurrences of the parent instance
  CATCVMOccurrence * _PrevOccurrence; // prev in the chain of the occurrences of the parent instance
};
#endif
*/
