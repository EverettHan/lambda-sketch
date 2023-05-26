#ifndef CATVidDnDSource_H
#define CATVidDnDSource_H

#include "CATUnicodeString.h"
#include "CATDlgUtility.h"
#include "VisuDialog.h"
#include "CATBaseUnknown_var.h"
#include "CATVidDnDData.h"
#include "CATEventSubscriber.h"
#include "CATVidMouseEventArgs.h"
#include "CATVidDnD.h"
#include <CATSysWeakRef.h>

class CATVidDnDEventArgs;
class CATVidCtl;

/** @ingroup groupVidDnD
 *
 * This helper class provides support of the drag part of the drag-and-drop 
 * operation on a CID control (@ref CATVidCtl). It allows its owner control 
 * (the drag source) to export data after a prolongated drag, in order to be 
 * dropped onto a compatible control (drop target associated to a
 * @ref CATVidDnDTarget). 
 *
 * @see CATVidCtl#SetDnDMode
 * @see CATVidDnDSourceFactory
 */
class ExportedByVisuDialog CATVidDnDSource : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** 
   * Constructor.
   *
   * @param i_pOwner the control whose data needs to be transfered. A weak 
   * reference is kept on the input pointer. Cannot be @c NULL.
   * @param i_pSourceData data exported for drag-and-drop. The pointer will be
   * @c AddRef-ed. Cannot be @c NULL. 
   */
  CATVidDnDSource(CATVidCtl * i_pOwner, CATVidDnDData * i_pSourceData);
   /**
    * Called during start of drag of the owner control (callback of 
    * @ref CATVidGP#Drag). Calls the @ref CATInteractiveApplication to start
    * the drag loop (unless the drag mode is @ref CATVidDnD#Clipboard).
    *
    * @param i_possibleEffects the effects supported by the drag source.
    */ 
  void StartDrag(CATVidDnD::Effects i_possibleEffects);
  /**
   * @return the data exported by the drag source for drag-and-drop.
   */
  CATVidData * GetSourceData() const;
  /**
   * @return a bit field representing the drag-and-drop effects supported by 
   * the drag source.
   *
   * @see CATVidDnD#Effects
   */
  CATVidDnD::Effects GetSourceEffects() const;
  /** 
   * @return a not @c NULL pointer on the control being dragged with the
   * protocole described by this transfer handler, ie. the drag source control.
   */
  CATVidCtl * GetOwner() const;

protected:
  /** 
   * Destructor.
   *
   * Called when the owner control is a drag source, when drag is cancelled 
   * (for eg. by escape key) or after drag-and-drop ends. Callback of
   * @ref CATVidDnDManager#DragEndCB.
   */
  virtual ~CATVidDnDSource();
  /**
   * @param i_requestedEffect the effect corresponding to the current key
   * modifiers.
   *
   * @see #OnQueryContinueDragCB
   * @see CATVidDnD#Effects
   */
  virtual void OnQueryContinueDrag(CATVidDnD::Effect i_requestedEffect);

private:
 /**
   * Callback function that listens to the 
   * @c CATDlgQueryContinueDragNotification 
   * sent by @c l_CATInteractiveApplication::QueryContinueDrag(). Useful when
   * dropping outside CID or dragging from outside.
   *
   * Called continuously during drag of the owner control (see 
   * COleDropSource::QueryContinueDrag).
   */
  void OnQueryContinueDragCB(CATCallbackEvent i_event, void * i_publisher, 
    CATNotification * i_pNotification, CATSubscriberData i_usefulData, 
    CATCallback i_callBackID);
  /**
   * Callback function that listens to the @c CATDlgDragFeedbackNotification 
   * sent by @c l_CATInteractiveApplication::DragFeedback(). Useful when
   * dropping outside CID or dragging from outside. Could be used to override
   * win32 default DnD cursor in case the l_CATInteractiveApplication did
   * not always return @c DRAGDROP_S_USEDEFAULTCURSORS.
   *
   * Called continuously during drag of the owner control as long as we are 
   * over a win32 drop target (see COleDropSource::GiveFeedback).
   */
  void OnDragFeedbackCB(CATCallbackEvent i_event, void * i_publisher, 
    CATNotification * i_pNotification, CATSubscriberData i_usefulData, 
    CATCallback i_callBackID);

private:
  /** @see #GetOwner */
  CATSysWeakRef* _pOwnerWR;
  /** The data exported for drag-and-drop. */
  CATVidDnDData * _pSourceData; 
  /** Drag availability of the application before drag-and-drop. */
  CATBoolean _dragAvailability;
};

//-----------------------------------------------------------------------------

#endif
