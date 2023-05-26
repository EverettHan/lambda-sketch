#ifndef CATVidFraContextBar_h
#define CATVidFraContextBar_h

// COPYRIGHT Dassault Systemes 2013

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>
#include <CATVid.h>

// Mathematics framework
#include <CATMathVector2Df.h>

// System framework
#include <CATBoolean.h>
#include <CATUnicodeString.h>

/**
 * Class representing a context bar window, used as a container for contextual commands.
 */
class ExportedByVisuDialog CATVidFraContextBar : public CATVidFraWindow
{
  CATDeclareClass;

public:

  /**
   * Constructor
   */
  CATVidFraContextBar();
  CATVidFraContextBar(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
  * Creates a context bar window with the immersive look.
  */
  static CATVidFraContextBar * CreateImmersiveContextBar(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Sets the offset from the mouse cursor position used to position the context bar window
   * when this one is displayed.
   * This offset corresponds to the distance between the mouse cursor and the attached window corner
   * (see @ref #GetAttachedWindowCorner).
   *
   * By default, the MouseCursorOffset property is set to (45, -45), i.e the window is displayed on the 
   * top right of the mouse cursor.
   * This offset is ignored when the window is displayed if the ListenToMouseMoveFlag property is set to FALSE.
   * @see SetVisibleFlag
   * @see SetAttachedWindowCorner
   */
  void SetMouseCursorOffset(const CATMathVector2Df& i_mouseCursorOffset);

  /**
   * Returns the offset from the mouse cursor position used to position the context bar window
   * when this one is displayed.
   */
  CATMathVector2Df GetMouseCursorOffset() const;

  /**
   * Sets the window corner to use to position the context bar window
   * when this one is displayed according to the mouse cursor position.
   * By default, the AttachedWindowCorner property is equal to CATVidFraWindow::BottomLeftCorner.
   * @see SetVisibleFlag
   * @see SetMouseCursorOffset
   */
  void SetAttachedWindowCorner(CATVidFraWindow::WindowCorner i_attachedWindowCorner);

  /**
   * Returns the window corner to use to position the context bar window
   * when this one is displayed according to the mouse cursor position.
   */
  CATVidFraWindow::WindowCorner GetAttachedWindowCorner() const;

  /**
   * Specifies whether the context bar must listen to the mouse move to change its opacity or not.
   * If this property is set to FALSE, the context bar is not positionned according to the mouse position
   * when it is displayed (its position remains unchanged).
   * By default, the ListenToMouseMoveFlag property is set to TRUE.
   */
  void SetListenToMouseMoveFlag(CATBoolean i_listenToMouseMoveFlag);

  /**
   * Returns TRUE if the context bar must listen to the mouse move to change its opacity, FALSE otherwise.
   */
  CATBoolean GetListenToMouseMoveFlag() const;
  CATBoolean GetListenToMouseMoveState() const;

  /**
   * Specifies whether the context bar is draggable or not.
   * When the window is draggable, its position is no more dependent on the mouse position.
   * By default, the DraggableFlag property is set to TRUE on a touch device, to FALSE otherwise.
   */
  void SetDraggableFlag(CATBoolean i_draggableFlag);

  /**
   * Returns TRUE if the context bar is draggable, FALSE otherwise.
   */
  CATBoolean GetDraggableFlag() const;

  /**
   * Specifies whether the context bar is pinned or not.
   * When the window is pinned, its position is no more dependent on the mouse position.
   * By default, the PinnedFlag property is set to FALSE.
   */
  void SetPinnedFlag(CATBoolean i_pinnedFlag);

  /**
   * Returns TRUE if the context bar is pinned, FALSE otherwise.
   */
  CATBoolean GetPinnedFlag() const;

  /**
   * Hides or shows the 'Pin' button.
   * @param i_pinButtonFlag
   * the boolean controling the visibility of the 'Pin' button
   * By default, the PinButtonFlag property is set to TRUE.
   */
  void SetPinButtonFlag(CATBoolean i_pinButtonFlag);

  /**
   * Returns TRUE if the 'Pin' button is visible, FALSE otherwise.
   */
  CATBoolean GetPinButtonFlag() const;
  CATBoolean GetPinButtonState() const;

  /**
   * Specifies whether the zone dedicated to additional commands is visible or not.
   * By default, the AdditionalCommandsVisibleFlag property is set to TRUE on a touch device, 
   * to FALSE otherwise.
   */
  void SetAdditionalCommandsVisibleFlag(CATBoolean i_additionalCommandsVisibleFlag);

  /**
   * Returns TRUE if the zone dedicated to additional commands is visible, FALSE otherwise.
   */
  CATBoolean GetAdditionalCommandsVisibleFlag() const;
  CATBoolean GetAdditionalCommandsVisibleState() const;

  /**
   * Sets the window orientation.
   * By default, the orientation is CATVid::Horizontal.
   */
  void SetOrientation(CATVid::Orientation i_orientation);

  /**
   * Returns the tooltip used by the 'Pin' button.
   */
  CATUnicodeString GetPinButtonTooltip() const;

  void PinUnpinCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);

protected:

  CATVidFraContextBar(CATCommand *i_pParent, const CATString & i_pIdentifier, const CATUnicodeString &i_templateName);
  virtual ~CATVidFraContextBar();

  // Overriden methods
  virtual void WriteWindowPreferences();
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);

private:

  void _Init(const CATUnicodeString &i_templateName);

  virtual void Build();
};

#endif // CATVidFraContextBar_h
