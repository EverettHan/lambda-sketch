#ifndef CATVidDnDTarget_H
#define CATVidDnDTarget_H

#include "CATUnicodeString.h"
#include "VisuDialog.h"
#include "CATBaseUnknown_var.h"
#include "CATMathPoint2Df.h"
#include "CATVidDnD.h"

class CATVidDnDEventArgs;
class CATVidCtl;
class CATVidData;
class CATVidEventArgs;

//-----------------------------------------------------------------------------
/** @ingroup groupVidDnD
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
class ExportedByVisuDialog CATVidDnDTarget : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** 
   * Constructor.
   *
   * @param i_pOwner the control whose data needs to be transfered. A weak 
   * reference is kept on the input pointer.
   */
  CATVidDnDTarget(CATVidCtl * i_pOwner);
  /** 
   * @return a not @c NULL pointer on the control accepting drop.
   */
  CATVidCtl * GetOwner() const;
  /**
   * Retreive the source data to initialize the source data pointer.
   */
  void InitializeSourceData();
  /**
   * Updates the style of the mouse cursor (incompatible, move, copy, paste).
   *
   * @param i_pCurrentGP the GP currently under the mouse cursor.
   * @param i_currentPos the current position of the mouse cursor in the 
   * viewer.
   * @param i_effectToApply drag-and-drop effect to apply depending on
   * current keyboard modifiers and available source effects..
   */
  void UpdateMouseCursor(CATVidGP * i_pCurrentGP, 
  const CATMathPoint2Df& i_currentPos,
  CATVidDnD::Effect i_effectToApply);
  /**
   * Dispatches @ref CATVidCtl#CanImport on drop target (owner control) if:
   *
   * @li @c DragMode of source and @c DropMode of target (owner control) are 
   * compatible
   * 
   * @param i_pCurrentGP the GP currently under the mouse cursor.
   * @param i_currentPos the current position of the mouse cursor in the 
   * viewer.
   * @param i_effectToApply drag-and-drop effect to apply depending on
   * current keyboard modifiers and available source effects.
   *
   * @see CATVidCtl#SetDragMode
   * @see CATVidCtl#SetDropMode
   * @see CATVidDnD#Effects
   */
  CATBoolean CanImport(CATVidGP * i_pCurrentGP, 
  const CATMathPoint2Df& i_currentPos, 
  CATVidDnD::Effect i_effectToApply);
  /**
   * Dispatches @ref CATVidCtl#ImportData on drop target (owner control) if 
   * @ref #CanImport is @c TRUE.
   *
   * @param i_pCurrentGP the GP currently under the mouse cursor.
   * @param i_currentPos the current position of the mouse cursor in the 
   * viewer.
   * @param i_effectToApply drag-and-drop effect to apply depending on
   * current keyboard modifiers and available source effects.
   *
   * @see CATVidDnD#Effects
   */
  void Drop(CATVidGP * i_pCurrentGP, 
  const CATMathPoint2Df& i_currentPos,
  CATVidDnD::Effect i_effectToApply);

protected:
  /** Destructor. */
  virtual ~CATVidDnDTarget();

private:
  /**
   * Called on @ref CATVidGP#PreDrop on the drop target (owner control).
   *
   * @param i_pSender the sender of the event.
   * @param i_pArgs arguments of the event.
   */
  void OnPreDrop(CATBaseUnknown * i_pSender, CATVidDnDEventArgs * i_pArgs);
  /**
   * Checks whether @c DragMode of source and @c DropMode of target (owner control) are 
   * compatible.
   * 
   * @return @c TRUE if above condition is met, @c FALSE else.
   *
   * @see CATVidCtl#SetDragMode
   * @see CATVidCtl#SetDropMode
   */
  CATBoolean CanImportDrag();
  /**
   * Dispatches @ref CATVidCtl#CanImportData on drop target (owner control) and
   * return a feedback contained in the event arguments in case the event has
   * been consumed.
   *
   * @param i_pCurrentGP the GP currently under the mouse cursor.
   * @param i_currentPos the current position of the mouse cursor in the 
   * viewer.
   * @param i_effectToApply drag-and-drop effect corresponding to the
   * current keyboard modifiers.
   *
   * @return @c TRUE if the data can be imported, @c FALSE else.
   */
  CATBoolean CanImportData(CATVidGP * i_pCurrentGP, const CATMathPoint2Df& i_currentPos, CATVidDnD::Effect i_effectToApply);
  /**
   * Dispatches @ref CATVidCtl#ImportData on drop target.
   *
   * @param i_pCurrentGP the GP currently under the mouse cursor.
   * @param i_currentPos the current position of the mouse cursor in the 
   * viewer.
   * @param i_effectToApply drag-and-drop effect to apply depending on
   * current keyboard modifiers and available source effects.
   */
  void ImportData(CATVidGP * i_pCurrentGP, const CATMathPoint2Df& i_currentPos, CATVidDnD::Effect i_effectToApply);

private:
  /** @see #GetOwner */
  CATBaseUnknown_var _spOwner;
  /** @see #InitializeSourceData */
  CATVidData * _pSourceData;
};

//-----------------------------------------------------------------------------

#endif
