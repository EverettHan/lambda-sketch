/* -*-C++-*- */

#ifndef CATCVMSession_H
#define CATCVMSession_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMSession
//
// Collaborative Variational Modelling (CVM) Container class
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2006    Creation                         Alex State
//===================================================================
#include "CATBaseUnknown.h"
#include "CATCGMNewArray.h"

#include "CATCVMSysObjects.h"
#include "CATCVMAttrRef.h"
#include "CATCVMDef.h"
#include "CATCVMSession.h"

#include "ListPOfCATCVMAttrRef.h"
#include "ListPOfCATCVMContainer.h"
#include "ListPOfCATCVMSysUndoRedoMemento.h"

#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATErrorDef.h"

class CATCVMPSContainer;
class CATCVMContainer;
//class CATCVMSysUndoRedoMemento;

class ExportedByCATCVMSysObjects CATCVMSession : public CATBaseUnknown
{
  //------------------------------------------------------------------------------
  // CreateCVMSession
  //------------------------------------------------------------------------------
  public:
  static CATCVMSession *Create();
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
  public:
  CATDeclareClass;

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  private:
  CATCVMSession();
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMSession();

  //------------------------------------------------------------------------------
  // Clean up
  //------------------------------------------------------------------------------
  public:
  void CleanUp();

  //------------------------------------------------------------------------------
  // Get the product structure container
  //------------------------------------------------------------------------------
  public:
  CATCVMPSContainer * GetPSContainer();

  //------------------------------------------------------------------------------
  // Get the CVMMemento List
  //------------------------------------------------------------------------------
  void GetCVMMementoList (ListPOfCATCVMSysUndoRedoMemento & oCVMMementoList);


  //------------------------------------------------------------------------------
  // init for CVMSession
  //------------------------------------------------------------------------------
  static CATCVMSession * InitCVMSession( CATBaseUnknown  * iObjToDelete=NULL, CATBoolean iFirstToDelete=FALSE);
  static CATCVMSession * ResetCVMSession( CATBaseUnknown * iObjToDelete, CATBoolean iFirstToDelete=FALSE);
  
  static CATCVMSession * InitCVMSession( CATCVMPSContainer * iObjToDelete);
  static CATCVMSession * ResetCVMSession( CATCVMPSContainer * iObjToDelete);
  
  static CATCVMSession * InitCVMSession( CATCVMSysUndoRedoMemento * iObjToDelete);
  static CATCVMSession * ResetCVMSession( CATCVMSysUndoRedoMemento * iObjToDelete);

  static CATCVMSession * InitCVMSession( CATCVMContainer * iObjToDelete);
  static CATCVMSession * ResetCVMSession( CATCVMContainer * iObjToDelete);
  //------------------------------------------------------------------------------
  // libération de la session
  //------------------------------------------------------------------------------
  //static CATCVMSession * ReleaseData( );
  static CATCVMSession * FlushCVMSession( );
  
  //------------------------------------------------------------------------------
  // libération de la session sous condition uniquement pour CATIALive
  //------------------------------------------------------------------------------
  static CATCVMSession * ReleaseCVMSession();
  
  //------------------------------------------------------------------------------
  // gestion des objets attached to CVMSession
  //------------------------------------------------------------------------------
  private:
  
  void AddToolsToDelete(CATBaseUnknown* iObjToDelete,CATBoolean iFirstToDelete=FALSE);
  void ForgetToolsToDelete(CATBaseUnknown* iObjToDelete,CATBoolean iFirstToDelete=FALSE);
  
  void AddToolsToDelete(CATCVMPSContainer* iObjToDelete);
  void ForgetToolsToDelete(CATCVMPSContainer* iObjToDelete);
  
  void AddToolsToDelete(CATCVMSysUndoRedoMemento* iObjToDelete);
  void ForgetToolsToDelete(CATCVMSysUndoRedoMemento* iObjToDelete);

  void AddContainerInLoop(CATCVMContainer * iObjToDelete);
  void RemoveContainerFromLoop(CATCVMContainer *  iObjToDelete);

  //------------------------------------------------------------------------------
  // AttrRef management
  //------------------------------------------------------------------------------
  public:
  void       GetCVMAttrRefList (ListPOfCATCVMAttrRef  & oCVMAttrRefList);
  CATULONG32 GetCVMAttrRefListSize();
  CATULONG32 AddCVMAttrRef(CATCVMAttrRef * iCVMAttrRef);
  
  CATCVMAttrRef * GetAttributeRefFromPos(int iPos);
  CATCVMAttrRef * GetSameCVMAttrRef(CATCVMAttrRef * iAttrRef, int * oPos=NULL);
  CATCVMAttrRef * GetAttrRefFromID(CATUnicodeString iID, int *oPos=NULL);

  CATBoolean     RemoveAttributeRef(CATCVMAttrRef * iCVMAttrRef);

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  //public:
  //void Dump(ostream * iStream=0L) const;
  
  //------------------------------------------------------------------------------
  // Stream/Unstream
  //------------------------------------------------------------------------------
  //public:
  //virtual void    Stream( CATCVMSysStream* Str,CATBoolean iDebug=FALSE)   = 0 ;
  //virtual void    UnStream( CATCVMSysStream* Str ) = 0 ;

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
private :
  CATCVMPSContainer              *_PSContainer;
  CATCVMContainer                *_FirstGeoContainer;
  
  // List of all the Attribute Ref 
  ListPOfCATCVMAttrRef            _CVMAttrRefInSession;
  
  CATListPV                       _TabObjToRelease;
  CATListPV                       _TabObjToReleaseFirst;
  ListPOfCATCVMSysUndoRedoMemento _CVMMementoList;
  
  ListPOfCATCVMContainer          _CVMPSContainerList;
};
#endif
