#ifndef CATFrmDropSource_H_
#define CATFrmDropSource_H_
#include "CATAfrFoundation.h"

// CATIA Version 5 Release 1 Framework ApplicationFrame
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  object used by an editor to manage the source in a 
//             Drag and Drop mechanism
//
//-----------------------------------------------------------------
//
//  Usage :    this interface is derived to define several types 
//  -------    of visualisation  ( 3D, 2D,... )
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATFrmDropSource
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
#include "CATEventSubscriberTypedefs.h"
#include "CATDlgInclude.h"

class CATPathElement;
class CATFrmEditor;

class ExportedByCATAfrFoundation CATFrmDropSource : public CATBaseUnknown
{
  CATDeclareClass;
  
public :
  
  CATFrmDropSource(CATFrmEditor * Editor = NULL);
  virtual ~CATFrmDropSource();
  
  virtual void StartDrag();
  virtual void EndDrop  (DROPEFFECT DropEffect);
  virtual void CancelDrag();
  virtual int IsDragged();

protected:

  CATFrmEditor     * _Editor;

private:

  void EditorClosed (CATCallbackEvent, void * ,CATNotification *, CATSubscriberData, CATCallback);
  
};

#endif
