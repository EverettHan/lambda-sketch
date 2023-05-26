#ifndef CATFrmDropTarget_H_
#define CATFrmDropTarget_H_
#include "CATAfrFoundation.h"

// CATIA Version 5 Release 1 Framework ApplicationFrame
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  object used by an editor to manage the target in a 
//             Drag and Drop mechanism
////
//-----------------------------------------------------------------
//
//  Usage :    this interface is derived to define several types 
//  -------    of visualisation  ( 3D, 2D,... )
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATFrmDropTarget
//  -------------     CATBaseUnknown
//
//-----------------------------------------------------------------
//
//  Main methods :   
//  -------------    
//                    IsDraggable
//                    IsDroppable
//                    ExecuteDrag
//
//-----------------------------------------------------------------

#include "CATBaseUnknown.h"
#include "CATDlgInclude.h"
#include  "CATLISTP_CATBaseUnknown.h"
#include  "CATBaseUnknown_WR.h"

class CATCommandHeader;
class CATFormat;
class CATPathElement;
class CATFrmEditor;
class CATViewer;
class CATDrop;
class CATBeginPreDrop;
class CATPreDrop;
class CATEndPreDrop;
class CATPreDrop;
class CATDlgCancelDragNotification;
class CATIAfrDnDExternalObjects;

extern ExportedByCATAfrFoundation int CATNoEffectOnPurpose;

class ExportedByCATAfrFoundation CATFrmDropTarget : public CATBaseUnknown
{
  CATDeclareClass;
  
public :
  
  CATFrmDropTarget(CATFrmEditor * Editor= NULL);
  virtual ~CATFrmDropTarget();
  
  virtual void DragEnter(CATDialog  * Target,
			 DWORD        keyModifier,
			 POINTL       Cursor,
			 DWORD        PossibleEffect,
			 DROPEFFECT & CurrentEffect);
  virtual void DragOver (CATDialog  * Target,
			 DWORD        keyModifier,
			 POINTL       Cursor,
			 DWORD        PossibleEffect,
			 DROPEFFECT & CurrentEffect);
  virtual void Drop     (CATDialog  * Target,
			 DWORD        keyModifier,
			 POINTL       Cursor,
			 DWORD        PossibleEffect,
			 DROPEFFECT & CurrentEffect);
  virtual void DragLeave(CATDialog  * Target);
  
  // No Cursor position for DragOverRep because it should not be useful.
  // If you need the cursor position you can use the following notification:
  //  - _pDragBegin is set only when a drag begins on a Rep
  //  - _pDrag is set only while dragging on a rep.
  virtual void DragOverRep(CATDialog * Target,
			   DWORD keyModifier,
			   CATPathElement * Path,
			   DWORD PossibleEffect,
			   DROPEFFECT& CurrentEffect);
  virtual void DropOverRep(CATDialog * Target,
			   DWORD keyModifier,
			   CATPathElement * Path,
			   DWORD PossibleEffect,
			   DROPEFFECT& CurrentEffect);
  virtual void Initialize (CATDialog  * Target,
			   DWORD        keyModifier,
			   DWORD        PossibleEffect,
			   DROPEFFECT & CurrentEffect);
  void CancelDrag (CATDlgCancelDragNotification *ipDragCancel);

  virtual int FatalErrorIssued();

  void SetDropNotif (CATDrop *ipDrop);
  void SetDragBeginNotif (CATBeginPreDrop *ipBeginPreDrop);
  void SetDragNotif (CATPreDrop *ipPreDrop);
  void SetDragEndNotif (CATEndPreDrop *ipEndPreDrop);
  static const CATUnicodeString sPrefixForHeaderDnD;
    
protected:
  
  void SetEditor(CATFrmEditor *iEd);
  CATFrmEditor * GetEditor();

  CATPathElement   * _Path;
  CATCommandHeader * _Header;
  DROPEFFECT    _SavedEffect; // DBE feb 2018
  int                _first;
  const CATFormat  * _TextFormat;
  int                _fatalErrorCode;

  // Members used for d&d on viewer emptiness
  //   Notifications set by Select command before calling drag and drop methods
  CATDrop *_pDrop;
  CATBeginPreDrop *_pDragBegin;
  CATPreDrop *_pDrag;
  CATEndPreDrop *_pDragEnd;
  //   To avoid sending the same notif several times
  enum DragState {DragBegin, DragInProgress, DragEnd, NoCurrentDrag};
  static DragState _dragState; //needs to be static because several CATFrmDropTarget occurrence exist when dragging between different editors.



private:

  void EditorClosed (CATCallbackEvent, void * ,CATNotification *, CATSubscriberData, CATCallback);
  void ResetNotifs ();
  static CATLISTP(CATBaseUnknown) GetCATIAfrDnDExternalObjectsImpl(CATPathElement * ipPath, CATFrmEditor * ipEditor, CATListOfCATUnicodeString * ipFilePaths);
  static CATString GetUniqueExtension(CATListOfCATUnicodeString * ipFilePaths);

  CATBaseUnknown_WR  _EditorWR;
  static CATFrmEditor *_pDragSourceEditor; //to find dragged objects when drag ends.
  static CATViewer    *_pDragSourceViewer; //to find the viewer where the drag began.
  CATUnicodeString IsolatePrefix(CATUnicodeString *stringtoIsolate);
};

#endif
