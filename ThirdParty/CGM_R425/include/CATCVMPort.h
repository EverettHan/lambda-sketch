/* -*-C++-*- */

#ifndef CATCVMPort_H
#define CATCVMPort_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) ports
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
#include "CATCVMHandle.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATCVMSystem;
class CATCVMCopy;

class ExportedByCATCVMSysObjects CATCVMPort : public CATCVMHandle
{
  //------------------------------------------------------------------------------
  // CreatePort
  //------------------------------------------------------------------------------
  public:
  static CATCVMPort *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  private:
  CATCVMPort(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMPort();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // SetHandle
  //------------------------------------------------------------------------------
  public:
  void SetHandle(CATCVMHandle *iHandle);

  //------------------------------------------------------------------------------
  // GetHandle
  //------------------------------------------------------------------------------
  public:
  CATCVMHandle *GetHandle();

  //------------------------------------------------------------------------------
  // Create a copy (the pointed handle must already be duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMPort *CreateCopy(CATCVMCopy   *iCopy);

  //------------------------------------------------------------------------------
  // UndoRedo method
  //------------------------------------------------------------------------------
  void  UndoRedoDataSwapping (CATCVMObject *iCVMObject, int iCVMEvent);
  
  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  CATCVMHandle *_Handle;
  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream (CATCVMSysStream* CVMStr);
  virtual void    GetLinkedGeometry (CATCVMSysStream* CVMStr); 

  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);
};
#endif
