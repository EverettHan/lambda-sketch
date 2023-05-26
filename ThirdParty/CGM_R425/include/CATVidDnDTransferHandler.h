//=============================================================================
// COPYRIGHT Microsoft 2011/03/18
//=============================================================================
// CATVidDnDTransferHandler.cpp
// Header definition of class CATVidDnDTransferHandler
//=============================================================================
//  2011/03/18 Creation: QJP
//=============================================================================

#ifndef CATVidDnDTransferHandler_H
#define CATVidDnDTransferHandler_H

#include "CATUnicodeString.h"
#include "CATVidDnDDataSupport.h"
#include "CATDlgUtility.h"
#include "VisuDialog.h"
#include "CATBaseUnknown_WR.h"

class CATVidCtl;

//-----------------------------------------------------------------------------
/**
 * @deprecated Use @ref CATVidCtl drag-and-drop instead.
 *
 * This abstract class is a base class for providing support of Drag&Drop 
 * operation on a CID control (@ref CATVidCtl). 
 *
 * @par Purpose
 * Transfer handlers are used to allow a dragged control to be dropped on
 * another control. The transfer handler of the dragged control determines
 * which data is exported from the control and which actions are available
 * (move, copy, link). The transfer handler of the control accepting the drops
 * determines which data it can import from outside and how it is imported.
 *
 * @par Owner
 * The @c Owner of the transfer handler is the control on which Drag&Drop is 
 * activated. The transfer handler describes both:
 * @li what to do if the owner control is dragged: owner control is the drag 
 * source.
 * @li what to do if some control is dragged over the owner control: owner
 * control is the drag target.
 *
 * @par Drag and drop mode
 * When the application is in Drag&Drop mode and events are not emitted
 * by @ref CATVidGP anymore, Drag/Drop notifications of the 
 * @ref CATInteractiveApplication are routed here by the @ref CATVidDnDManager: 
 * they are handled by virtual methods of the class.
 *
 * @par Deriving the class
 * Individual CID controls that support Drag&Drop should have a transfer 
 * handler derived from this class and implement the virtual functions for 
 * custom behavior. A default transfer handler is available for controls
 * that can be dragged and cannot accept drops: 
 * @ref CATVidDefaultTransferHandler. It is installed on most CID controls by
 * default and can be used as a starting point.
 */
class ExportedByVisuDialog CATVidDnDTransferHandler : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** 
   * Constructor.
   *
   * @param i_pOwner the control whose data needs to be transfered. A weak 
   * reference is kept on the input pointer.
   */
  CATVidDnDTransferHandler(CATVidCtl * i_pOwner);
  /** Destructor. */
  virtual ~CATVidDnDTransferHandler();

  //---------------------------------------------------------------------------
  // I. Methods called when the owner control is the drag source
  //---------------------------------------------------------------------------
   /**
    * Called during start of Drag of the owner control (callback of 
    * @ref CATVidGP#Drag). 
    *
    * @param i_actions the DROPEFFECT bits. One or combination 
    * of DROPEFFECT_COPY, DROPEFFECT_MOVE, DROPEFFECT_LINK.
    *
    * @see #GetSourceActions
    */ 
  virtual void StartDrag(unsigned int i_actions);
  /**
   * Called once on press over the owner control. Save all data needed in 
   * case the control is dragged.
   */
  virtual void InitFeedback() {}
  /**
   * Called continuously during drag of the owner control (callback of
   * @ref CATVidDnDManager#OnDragFeedbackCB).
   *
   * @param i_dropEffect the DROPEFFECT bits. One or combination of 
   * DROPEFFECT_COPY, DROPEFFECT_MOVE, DROPEFFECT_LINK. 
   * @param i_xPos the current x position of the mouse cursor, in screen 
   * coordinates
   * @param i_yPos the current y position of the mouse cursor, in screen 
   * coordinates
   *
   * @see #GetSourceActions
   */
  virtual void OnGiveFeedback(DROPEFFECT i_dropEffect, int i_xPos, int i_yPos) {}
  /**
   * Called continuously during drag of the owner control (callback of
   * @ref CATVidDnDManager#RelayKeyStateCB). The key state indicates the
   * preference of the user dragging the object for the action to take on drop:
   *
   * @li empty: move the drag source (DROPEFFECT_MOVE)
   * @li MK_CONTROL: copy the drag source (DROPEFFECT_COPY)
   * @li MK_CONTROL + MK_SHIFT: link the drag source (DROPEFFECT_LINK)
   *
   * This preference may or may not be compatible with the available source
   * actions. Depending on how the @ref #CanImport function of the transfer 
   * handler of the target control has been implemented, either user 
   * preferences will be ignored in favour of an available action or the drop 
   * will be rejected.
   *
   * @param i_dwKeyState the current key state (MK_CONTROL/MK_SHIFT)
   *
   * @see #GetSourceAction
   */
  virtual CATBoolean RelayKeyState(unsigned int i_dwKeyState);
  /**
   * Called when the owner control is a drag source to check wether it exports
   * a given type of data or not (see returned boolean) and fetch it in case
   * it exists (see input parameter).
   *
   * @param i_dataType enum of data type requested 
   * 
   * @return @c TRUE if the data has been fetched, @c FALSE if it is not
   * exported by the control.
   *
   * @see #DataType_e
   */
  CATBoolean IsDataPresent(CATVidDnDDataSupport::DataType_e i_oDataType) const;
  /**
   * Called when the owner control is a drag source, when drag is cancelled 
   * (for eg. by escape key) or after Drag&Drop ends. Callback of
   * @ref CATVidDnDManager#DragEndCB.
   */
  virtual void DragEnd();
  /**
   * Called when the owner control is a drag source, immediately after a drop.
   *
   * @param i_bDropSuccess TRUE if drop was successful. 
   */
  virtual void DropDone(CATBoolean i_bDropSuccess) {}
  /**
   * Used when the owner control is a drag source. 
   *
   * @return a helper entity that manages data operations for the transfer
   * handler.
   */
  virtual CATVidDnDDataSupport * GetSourceDataSupport() const;
  /**
   * Sets a custom helper entity managing data operation for the transfer 
   * handler.
   *
   * @param i_pDataSupport the helper entity.
   */
  virtual void SetSourceDataSupport(CATVidDnDDataSupport* i_pDataSupport);
  /**
   * Called when the owner control is dragged. Gets a DROPEFFECT bit field 
   * (see @ref CATDlgUtility), which describes actions available on the drag 
   * source of the transfer handler:
   *
   * @li DROPEFFECT_COPY: source control is copied in the target control
   * @li DROPEFFECT_MOVE: source control is moved in the target control
   * @li DROPEFFECT_LINK: a link to source control is created in the target 
   * control
   *
   * @return available source drag actions in the form of a DROPEFFECT bit 
   * field.
   */
  unsigned int GetSourceActions() const;
  /**
   * Called when the owner control is dragged.
   *
   * @param i_actions bit field representing available actions for the dragged
   * control.
   *
   * @see #GetSourceActions
   */
  void SetSourceActions(unsigned int i_actions);
  /**
   * Called when the owner control is dragged.
   *
   * @return the keyboard modifier: nothing, MK_CONTROL, or 
   * MK_CONTROL|MK_SHIFT.
   *
   * @see #RelayKeyState
   */
  unsigned int GetKeyModifier() const;

  //---------------------------------------------------------------------------
  // II. Methods called when the owner control is a potential drop target
  //---------------------------------------------------------------------------
  /**
   * Called when the owner control is a target for drop. Continuously checks if 
   * data can be imported during drag, so that the mouse cursor can be updated.  
   *
   * @return @c TRUE if it can import the data exported by the dragged control
   * and @c FALSE if it cannot.
   */
  virtual CATBoolean CanImport() = 0;
  /**
   * Called when the owner control is the drop target. Implements the drag data 
   * import logic. 
   *
   * @return @c TRUE if it can import the data exported by the dragged control
   * and @c FALSE if it cannot.
   */
  virtual CATBoolean ImportData() = 0;
  /**
   * Used when the owner control is the drop target.
   *
   * @param i_posX x coordinate relative to drop target.
   * @param i_posY y coordinate relative to drop target.
   */
  void SetDropLocation(float i_posX, float i_posY);
  /**
   * Used when the owner control is the drop target.
   *
   * @param o_posX x coordinate relative to drop target.
   * @param o_posY y coordinate relative to drop target.
   */
  void GetDropLocation(float& o_posX, float& o_posY) const;

  //---------------------------------------------------------------------------
  // III. Other
  //---------------------------------------------------------------------------
  /** 
   * @return a not @c NULL pointer on the control being dragged with the
   * protocole described by this transfer handler.
   */
  CATVidCtl * GetOwner() const;

protected:
  /**
   * Creates a default data support for the transfer handler. 
   *
   * @return the default data support. Cannot be @c NULL.
   *
   * @see #GetDataSupport
   */
  virtual CATVidDnDDataSupport * CreateDataSupport();
  /**
   * Used when the owner control is a drag source. Does all the necessary 
   * cleanups after a successful drop. 
   */
  virtual void Cleanup();

private:
  /** @see #GetOwner */
  CATBaseUnknown_WR _wrOwner;
  /** @see #GetSourceActions */
  unsigned int _iSrcActions;
  /** @see #GetDropLocation */
  int _dropLocationX;
  /** @see #GetDropLocation */
  int _dropLocationY;
  /** @see #GetKeyModifier */
  unsigned int _keyModifier;
  /** Helper for data operations. @see CATVidDnDDataSupport */
  CATVidDnDDataSupport * _pDragDataSupport; 
};

//-----------------------------------------------------------------------------

#endif
