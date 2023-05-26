/* -*-C++-*- */

#ifndef CATCVMLog_H
#define CATCVMLog_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMLog
//
// generic class for Collaborative Variational Modelling (CVM) log
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Dec. 2006    Creation                         Alex State
//===================================================================

#include "CATCVMSysObjects.h"
#include "CATCGMVirtual.h"

#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCVMSystem.h"

#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATCVMDef.h"
#include "CATCGMHashTableWithAssoc.h"
#include "CATCGMNewArray.h"

class CATCVMContainer;
class CATCVMObject;
enum CVMLogEvent
{
    CVMLogEvent_None    = 0,
    CVMLogEvent_Create  = 1,
    CVMLogEvent_Modify  = 10,
    CVMLogEvent_Release = 100,
};
class ExportedByCATCVMSysObjects CATCVMLog : public CATCGMVirtual
{
  //------------------------------------------------------------------------------
  // Create a log
  //------------------------------------------------------------------------------
  public:
  static CATCVMLog *Create(CATCVMContainer *iContainer=NULL);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  private:
  CATCVMLog();

  //-----------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMLog();

  //------------------------------------------------------------------------------
  // Pool allocation
  //------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;
  
  //------------------------------------------------------------------------------
  // Set if LogEvent must to forwarded to UndoRedo treatment (TRUE by default)
  //------------------------------------------------------------------------------
  CATBoolean SetUndoRedoMode  (CATBoolean iMode);
  //------------------------------------------------------------------------------
  // Check if Log is Empty
  //------------------------------------------------------------------------------
  CATBoolean IsEmpty ();
  //------------------------------------------------------------------------------
  // Tass de la Log
  //------------------------------------------------------------------------------
  void Tass();
  //------------------------------------------------------------------------------
  // Log new/released and Modified object
  //------------------------------------------------------------------------------
  void LogNewObject     (CATCVMObject *iObject, CATCVMObject *iAssociatedObject=NULL, CATBoolean SingleObjectMode=FALSE);
  void LogReleasedObject(CATCVMObject *iObject, CATCVMObject *iAssociatedObject=NULL, CATBoolean SingleObjectMode=FALSE);
  void LogModifiedObject(CATCVMObject *iObject, CATCVMObject *iAssociatedObject=NULL, CATBoolean SingleObjectMode=FALSE);
  
  void LogModifiedObject(ListPOfCATCVMObject *iObjectList);

  //------------------------------------------------------------------------------
  // For UndoRedo
  //------------------------------------------------------------------------------
  static void AnalyzeEvent(int iEvent, CATBoolean & oIsNew, CATBoolean & oIsModified, CATBoolean & oIsReleased);
  //------------------------------------------------------------------------------
  // Check if an object is new/released or modified
  //------------------------------------------------------------------------------
  CATBoolean IsNewObject     (CATCVMObject *iObject, int *oIndex = NULL);
  CATBoolean IsReleasedObject(CATCVMObject *iObject, int *oIndex = NULL);
  CATBoolean IsModifiedObject(CATCVMObject *iObject, int *oIndex = NULL);

  //------------------------------------------------------------------------------
  // Get the CVM objects that are been Logged during the run 
  // Please note: this must be called after the Run method
  //------------------------------------------------------------------------------
  void GetLoggedCVMObjects (ListPOfCATCVMObject &oCVMObjectList, CATListOfInt &oCVMEventType,
                            ListPOfCATCVMObject &oCVMPhotoList);
  //------------------------------------------------------------------------------
  // PostProcess LoggedCVMObjects MultiBody and CVMInstance/CVMReferences
  //------------------------------------------------------------------------------
  void GetLoggedCVMObjects (ListPOfCATCVMSystem &oCVMBodyList, CATListOfInt &oCVMObjectNumber,
                            ListPOfCATCVMObject &oCVMObjectList);
  //------------------------------------------------------------------------------
  // Get new / released or modified objects
  //------------------------------------------------------------------------------
  void GetNewObjects     (ListPOfCATCVMObject &oCVMObjectList, CATCVMObjectType iType);
  void GetReleasedObjects(ListPOfCATCVMObject &oCVMObjectList, CATCVMObjectType iType);
  void GetModifiedObjects(ListPOfCATCVMObject &oCVMObjectList, CATCVMObjectType iType);

  //------------------------------------------------------------------------------
  // Find the Associated of a given object
  //------------------------------------------------------------------------------
  void GetAssociatedCVMObjects(CATCVMObject        *iOriginalObject,
                               ListPOfCATCVMObject &oAssociatedObjectList);
  CATCVMObject * GetAssociatedObject(int iEventPosition);
  //------------------------------------------------------------------------------
  // Merge two CVMLog
  //------------------------------------------------------------------------------
  void Merge(CATCVMLog * iOther, CATBoolean iPhoto=FALSE);
  //------------------------------------------------------------------------------
  // Invert one Log for visualization treatement 
  //------------------------------------------------------------------------------
  void Invert();
  //------------------------------------------------------------------------------
  // Substract two CVMLog for visualization treatement  iCVMLogA - iCVMLogB 
  //------------------------------------------------------------------------------
  void Substract(CATCVMLog * iCVMLogA, CATCVMLog * iCVMLogB);
  //------------------------------------------------------------------------------
  // Dump
  //------------------------------------------------------------------------------
  void Dump(ostream * iStream=0L);
  //------------------------------------------------------------------------------
  // SetEventAndPhoto
  //------------------------------------------------------------------------------
  void SetEventAndPhoto(CATCVMObject *iCVMObject , int iEvent , CATCVMObject *iCVMPhoto);
  
  //------------------------------------------------------------------------------
  // Debug
  //------------------------------------------------------------------------------
  public:
  CATCVMObject * GetItem  (int iCVMTag , int &oEvent);
  
  private:
  int  GetEvent      (CATCVMObject *iCVMObject , int &oEvent);
  void CleanUp();

  int InsertNewEvent(CATCVMObject *iCVMObject , int iEvent );
  int LogEvent      (CATCVMObject *iCVMObject , int iEvent );
  void GetObjectList(ListPOfCATCVMObject & oTarget, const int  EventFilter, CATCVMObjectType iFilter);
  //------------------------------------------------------------------------------
  // Get / Create / Delete Associated objects list
  //------------------------------------------------------------------------------
  ListPOfCATCVMObject *GetAssociatedList(int iEventPosition);
  ListPOfCATCVMObject *CreateAssociatedList(int iEventPosition);
  void DeleteAssociatedList(int iEventPosition);

  //------------------------------------------------------------------------------
  // Undo Redo
  //------------------------------------------------------------------------------
  void SetAssociatedPhoto(int iEventPosition, CATCVMObject *iCVMObject);
  CATCVMObject * GetAssociatedPhoto(int iEventPosition);
  
  //------------------------------------------------------------------------------
  // Necessary to prevent unwanted automatic creation by compiler
  //------------------------------------------------------------------------------
  CATCVMLog(const CATCVMLog &);
  void operator = (const CATCVMLog &);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATCGMHashTableWithAssoc *_CVMLogHashTab;
  CATListPV                 _AssociatedObjectLists;
  ListPOfCATCVMObject       _AssociatedPhoto;
  int                       _NbCVMLogObjects;
  CATBoolean                _UndoRedoLogMode;
};
#endif
