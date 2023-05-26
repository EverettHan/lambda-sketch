/* -*-C++-*- */

#ifndef CATCVMObject_H
#define CATCVMObject_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// generic class for Collaborative Variational Modelling (CVM) objects
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2006    Creation                         Alex State
//===================================================================
#include "CATMacForRtti.h"
#include "CATCVMSysObjects.h"
#include "CATCVMDef.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"
#include "ListPOfCATCVMAttribute.h"
#include "ListPOfCATCVMAttrRef.h"
#include "CATCVMAttribute.h"
#include "CATCVMAttributeDef.h"
#include "CATCGMNewArray.h"
#include "CATErrorDef.h"

#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

class CATCVMContainer;
class CATCVMSysStream;
class CATCVMCopy;

class ExportedByCATCVMSysObjects CATCVMObject : public CATBaseUnknown 
{
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
  public:
  CATDeclareClass_Deprec;

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMObject(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMObject();

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  virtual void Dump(ostream * iStream=0L) const;

  virtual void ExtendedDump(CATUnicodeString & oExtendedDump) const;

  //------------------------------------------------------------------------------
  // GetUseCount
  //------------------------------------------------------------------------------
  public:
  int GetUseCount();

  //------------------------------------------------------------------------------
  // GetTag
  //------------------------------------------------------------------------------
  public:
  CATULONG32 GetTag();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType) = 0;

  public:
  virtual CATCVMObjectType GetType() = 0;


  //------------------------------------------------------------------------------
  // AddCVMRef & ReleaseCVMRef
  //------------------------------------------------------------------------------
  // Recommended to use:
  // CVMObject->AddRef       (this, "thisClassName");
  // ReleaseCVMRef(CVMObject, this, "thisClassName");

  // Mandatory:
  //  CVMObject->AddRef       (this or unique integer);
  //  ReleaseCVMRef(CVMObject, this or unique integer);
  //------------------------------------------------------------------------------
  public:
  void AddCVMRef(const void* iMe, const char* iMyId = NULL); 

  public:
  static void ReleaseCVMRef(CATCVMObject* iObject, const void* iMe, const char* iMyId = NULL,CATBoolean iRemoveIfPossible=TRUE);

  //------------------------------------------------------------------------------
  // Release data
  // This method may be called in two situations:
  // 1) when the destructor of this object is called
  // 2) when all the elements aggregated by this object are deleted; in this case
  //    object is still valid (not deleted) and has a valid tag
  //------------------------------------------------------------------------------
  public:
  virtual void ReleaseData();
  
  private:
  virtual void ReleaseAttribut();

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Set name
  //------------------------------------------------------------------------------
  public:
  void SetName(CATString &iName);

  //------------------------------------------------------------------------------
  // Get name
  //------------------------------------------------------------------------------
  public:
  void GetName(CATString &oName);

  //------------------------------------------------------------------------------
  // Set name on datum feature
  //------------------------------------------------------------------------------
  public:
  void AddToName(CATString &iString);

  //------------------------------------------------------------------------------
  // Create for copied object
  //------------------------------------------------------------------------------
  public:
  void CreateNameForCopy(CATString &oName,
                         int        iExtensionIncrementValue = 1);

  //------------------------------------------------------------------------------
  // Set CVM container
  //------------------------------------------------------------------------------
  protected:
  void SetContainer(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Get CVM container
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMContainer *GetContainer();
  //------------------------------------------------------------------------------
  // Test CPU
  //------------------------------------------------------------------------------
  virtual CATCVMObject  * GetCVMObjectImage();
  virtual void SetCVMObjectImage(CATCVMObject * iCVMObjectImage);

  //DO NOT USE
  public:
  void SetTag(CATULONG32 iTag);
 
  //------------------------------------------------------------------------------
  // Add/Remove Attribute
  //------------------------------------------------------------------------------
  void AddAttribute(CATCVMAttribute * iAttr);
  void RemoveAttribute(CATCVMAttribute * iAttr);
  virtual CATCVMAttribute * GetAttribute (CATCVMAttributeType iType);
  virtual CATCVMAttribute * CreateAttribute (CATCVMAttributeType iType);   // Must be derivated
  virtual CATCVMAttribute * GetOrCreateAttribute (CATCVMAttributeType iType);
  ListPOfCATCVMAttribute * GetAttributeList(); 
  HRESULT GetAttributeReferences(ListPOfCATCVMAttrRef * ioAttrRefList); 

  //------------------------------------------------------------------------------
  // Get/Set color
  //------------------------------------------------------------------------------
  virtual HRESULT SetRVBAlpha(double r, double v, double b, double alpha);
  virtual HRESULT GetRVBAlpha (double &oR, double &oG, double &oB, double &oAlpha);

  //------------------------------------------------------------------------------
  // Copy extension and additionnal datas
  //------------------------------------------------------------------------------
  void CopyData(CATCVMObject * iInitialObject , CATCVMCopy *iCopy=NULL , int iLight=0 );

  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  virtual void CopyAllData(CATCVMObject *iInitialObject,
                           CATCVMCopy   *iCopy=NULL,
                           int           iLight=0);

  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMObject *CreateCopy(CATCVMCopy *iCopy) = 0;
  virtual void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  
  //------------------------------------------------------------------------------
  // Swap Definition from CVMPhoto for Undo / Redo Treatment
  //------------------------------------------------------------------------------
  virtual void UndoRedoDataSwapping(CATCVMObject *iCVMObject, int iCVMEvent)=0;
  CATBoolean IsUndoable();
  void SetUndoMode(CATULONG32 iUndoMode);
  //------------------------------------------------------------------------------
  // Update texture position
  //------------------------------------------------------------------------------
  private:
  virtual void UpdateTexturePosition(CATCVMObject    *iInitialObject,
                                     CATCVMAttribute *iNewTextureAttribute,
                                     CATCVMCopy      *iCopy=NULL );
  //------------------------------------------------------------------------------
  // Chain Management
  //------------------------------------------------------------------------------
  public: 
  virtual void Set_Atom_Next(CATCVMObject * iCVMNext);
  virtual void Set_Atom_Prev(CATCVMObject * iCVMPrev);
  virtual CATCVMObject *Get_Atom_Next();
  virtual CATCVMObject *Get_Atom_Prev();
  
  private:
  CATCVMObject(const CATCVMObject &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMObject &);

  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory)=0;
  virtual void    Stream   (CATCVMSysStream* Str)=0;
  virtual void    GetLinkedGeometry (CATCVMSysStream* iCVMStr)=0;

  CATBoolean IsStreamed ();
  void       SetIsStreamed ();
  void       CleanIsStreamed ();

  //------------------------------------------------------------------------------
  // transfer an object from its current contaienr to a new container
  //------------------------------------------------------------------------------
  public :
  virtual void Transfer(CATCVMContainer     *iTargetContainer,
                        ListPOfCATCVMObject &ioObjectsToTransfer);

  //------------------------------------------------------------------------------
  // Copy extension and additionnal datas (attributes...)
  // ioCopyObject MUST have been copied already
  //------------------------------------------------------------------------------
  private:
  void InternalCopyData(CATCVMObject * iInitialObject , CATCVMCopy * ipCopy , int iLight,
                        CATBoolean iIdenticalCopyMode);

  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
	virtual CATBoolean Compare (CATCVMObject *iRef)=0;
	//------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATULONG32             _Tag;
  int                    _UseCount;
  CATULONG32             _UndoMode;
  CATCVMContainer *      _Container;
  ListPOfCATCVMAttribute _AttrList;
  CATCVMObject    *      _CVMObjectImage;
  CATBoolean             _IsStreamed;
  CATString              _Name;
};
#endif
