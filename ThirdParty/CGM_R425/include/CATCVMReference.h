/* -*-C++-*- */

#ifndef CATCVMReference_H
#define CATCVMReference_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMReference
//
// class for Collaborative Variational Modelling (CVM) references
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Nov. 2007    Creation                         Alex State
//===================================================================
#include "CATCVMSysObjects.h"
#include "CATCVMComponent.h"
#include "CATCVMDef.h"
#include "CATDataType.h"
#include "CATCGMNewArray.h"
#include "CATMathBox.h"

class CATCVMInstance;
class CATCVMContainer;
class CATCVMPSContainer;
class CATCVMSysStream;


class CATUnicodeString;
class ExportedByCATCVMSysObjects CATCVMReference : public CATCVMComponent
{

	public:
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // Create Reference
  //------------------------------------------------------------------------------
  public:
  static CATCVMReference *Create(CATCVMPSContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMReference(CATCVMPSContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMReference();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  private:
  void CleanUp();
  
public:
  virtual void SetBoundingBox(CATMathBox & iBoundingBox);
  virtual CATBoolean GetBoundingBox(CATMathBox & oBoundingBox);

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
  // Set name
  //------------------------------------------------------------------------------
  public:
  void SetRefName(CATUnicodeString &iName);

  //------------------------------------------------------------------------------
  // Get name
  //------------------------------------------------------------------------------
  public:
  void GetRefName(CATUnicodeString &oName);
  
  //------------------------------------------------------------------------------
  // Set HasBeenImportedInSession
  //------------------------------------------------------------------------------
  public:
  void  SetHasBeenImportedInSession (CATBoolean HasBeenImported=TRUE);
  CATBoolean GetHasBeenImportedInSession ( );
  
  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *CreateCopy(CATCVMCopy *iCopy=NULL);

  protected:
  void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  void LocalDataCopy(CATCVMReference * iCVMPrev);
  
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
  // Copy a system and add it as subsystem
  //------------------------------------------------------------------------------
  protected:
  CATCVMSystem *CopyAsSubSystem(CATCVMSystem *iSystem,
                                CATCVMCopy   *iCopy);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Add a sub-system
  //------------------------------------------------------------------------------
  public:
  HRESULT AddSystem(CATCVMSystem *iSystem, CATBoolean IsNew=FALSE );

  //------------------------------------------------------------------------------
  // Remove a sub-system
  //------------------------------------------------------------------------------
  public:
  void RemoveSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Set the data container (safe method for external use)
  //------------------------------------------------------------------------------
  public:
  HRESULT SetDataContainer(CATCVMContainer *iDataContainer);
  HRESULT SetDataContainerSafe(CATCVMContainer *iDataContainer);

  //------------------------------------------------------------------------------
  // Set the data container
  //------------------------------------------------------------------------------
  private:
  void PrivateSetDataContainer(CATCVMContainer *iDataContainer);

  //------------------------------------------------------------------------------
  // Get the data container
  //------------------------------------------------------------------------------
  public:
  CATCVMContainer *GetDataContainer();

  //------------------------------------------------------------------------------
  // Get number of GeoReps
  //------------------------------------------------------------------------------
  public:
  int GetNbGeoReps();

  //------------------------------------------------------------------------------
  // IsRootReference
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsRootReference();

 // for debug only (cgmreplay)
  public :
  virtual CATCVMObject* FindObjectFromTag (CATULONG32 iTag);
  virtual CATCVMObject * FindObjectFromName (CATString& iName);


  //------------------------------------------------------------------------------
  // System chain management
  //------------------------------------------------------------------------------
  protected:
  virtual HRESULT       SetAccessSystem(CATCVMSystem *iAccessSystem);
  public:
  virtual CATCVMSystem *GetAccessSystem();

  //------------------------------------------------------------------------------
  // Get access instance
  //------------------------------------------------------------------------------
  public:
  CATCVMInstance *GetAccessInstance();

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream   (CATCVMSysStream* CVMStr);
  
  //------------------------------------------------------------------------------
  // transfer an object from its current contaienr to a new container
  //------------------------------------------------------------------------------
  public :
  void Transfer(CATCVMContainer     *iTargetContainer,
                ListPOfCATCVMObject &ioObjectsToTransfer);

  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  virtual void Dump(ostream * iStream=0L, int idecal=0) const;

  //------------------------------------------------------------------------------
  // CATSysSimpleHashTable management
  //------------------------------------------------------------------------------

  // If you want to look for a CATCVMReference with a tag:
  //   CATULONG32 QueriedTag = ...;
  //   CATCVMReference::_QueriedTagPtr = &QueriedTag;
  //   <use CATSysSimpleHashTable::Locate>
  //   CATCVMReference::_QueriedTagPtr = NULL; // DON'T FORGET!!!
  static CATULONG32 *_QueriedTagPtr;
  static int SimpleCompare (void * ipFirst , void * ipSecond);
  static unsigned  int  Hash ( void * ipRef );
  //------------------------------------------------------------------------------

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATCVMInstance  *_AccessInstance;
  CATCVMContainer *_DataContainer;
  int              _NbGeoReps;
  CATBoolean       _HasBeenImportedInSession;
  CATMathBox _BoundingBox;
  CATBoolean _IsBoundingBoxSet;

  CATUnicodeString _RefName;
};

#endif
