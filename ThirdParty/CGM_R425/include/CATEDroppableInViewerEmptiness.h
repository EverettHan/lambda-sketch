// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATEDroppableInViewerEmptiness.h
// Header definition of CATEDroppableInViewerEmptiness
//
//===================================================================
//
// Usage notes: Adapter for the CATIDroppableInViewerEmptiness interface.
//
//===================================================================
//
//  Sep 2008  Creation: ERS
//===================================================================
#ifndef CATEDroppableInViewerEmptiness_H
#define CATEDroppableInViewerEmptiness_H

#include "CATInteractiveInterfaces.h"
#include "CATIDroppableInViewerEmptiness.h"

class CATDrop;
class CATPreDrop;
class CATBeginPreDrop;
class CATEndPreDrop;
class CATDlgCancelDragNotification;
class CATViewer;

//-----------------------------------------------------------------------

/**
  * Adapter for the CATIDroppableInViewerEmptiness interface .
  * <b>Role :</b> This base class provides usefull services making 
  * the management of drag and drop on viewer backgrounds.
  * <br>
  * Implementing CATIDroppableInViewerEmptiness just consists in subclassing the 
  * CATEDroppableInViewerEmptiness class and simply override the methods you want.
  * Do not forget to implement the CATIDroppableInViewerEmptiness interface
  * using : CATImplementBOA(CATIDroppableInViewerEmptiness, CATEDroppableInViewerEmptiness).
  * <br>
  * <br> Here follows the way your object will be called on this interface:
  * <br> Begin of drag: DragBegins(notif, sourceEditor, sourceEditor)
  * <br> Drag on emptyness: DragInProgress(notif)
  * <br> Entering a graphic rep: DragEnds(NULL)
  * <br> Leaving the graphic rep: DragBegins(notif, sourceEditor, currentEditor)
  * <br> Entering an immersive dialog: DragEnds(notif)
  * <br> Leaving the immersive dialog: DragBegins(notif, sourceEditor, currentEditor)
  * <br> Entering an element of the specs graph: DragEnds(notif)
  * <br> Leaving the element of the specs graph: DragBegins(NULL, sourceEditor, currentEditor)
  * <br> Leaving the current window: DragEnds(notif)
  * <br> Entering a window: DragBegins(notif, sourceEditor, currentEditor)
  * <br> Dropping outside of a viewer:DragCanceled(notif)
  * <br> Dropping in a viewer, on a rep in specs graph: DragCanceled(NULL)
  * <br> Dropping in a viewer, on a graphic rep: DragCanceled(NULL)
  * <br> Dropping in a viewer, on an immersive dialog: DragCanceled(notif)
  * <br> Dropping in a viewer, on nothing: DropInViewerEmptyness(notif)
  */
class ExportedByCATInteractiveInterfaces CATEDroppableInViewerEmptiness: public CATIDroppableInViewerEmptiness
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     CATEDroppableInViewerEmptiness ();
     virtual ~CATEDroppableInViewerEmptiness ();

  // CATIDroppableInViewerEmptiness methods. See CATIDroppableInViewerEmptiness.h for comments
     CATBoolean IsDroppable();
     void DropInViewerEmptiness (CATDrop * ipDropNotif);
     void DragBegins (CATBeginPreDrop * ipBeginPreDropNotif, CATViewer * ipSourceViewer, CATViewer * ipCurrentViewer);
     void DragInProgress (CATPreDrop * ipPreDropNotif);
     void DragEnds (CATEndPreDrop * ipendPreDropNotif);
     void DragCanceled (CATDlgCancelDragNotification * ipCancelDragNotif);


  private:

  // Copy constructor and equal operator are not implemented
  // -----------------------------------
  CATEDroppableInViewerEmptiness (CATEDroppableInViewerEmptiness &);
  CATEDroppableInViewerEmptiness& operator=(CATEDroppableInViewerEmptiness&);
};

//-----------------------------------------------------------------------

#endif
