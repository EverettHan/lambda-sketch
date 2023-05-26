#ifndef CATVidCtlPopup_h
#define CATVidCtlPopup_h

// COPYRIGHT Dassault Systemes 2005

#include <VisuDialog.h>
#include <CATVidCtl.h>

class CATVidFraDialogBox;
class CATVisuAnimationWeakRef;
class CATVidGPSquare;
class CATVidMouseEventArgs;
class CATVidFraPopupWindowConstraints;
class CATSYPEvent;

/**
* @ingroup VIDControls
*/
class ExportedByVisuDialog CATVidCtlPopup : public CATVidCtl
{
  CATDeclareClass;

public:

  // Standard constructors
  CATVidCtlPopup();
  CATVidCtlPopup(CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetSnapFlag(CATBoolean i_snapFlag);
  CATBoolean GetSnapFlag() const;

  /**@copydoc CATVidFraPopupWindowConstraints#SetLook**/
  void SetLook(const CATUnicodeString& i_look);

  /**@copydoc CATVidFraPopupWindowConstraints#GetLook**/
  const CATUnicodeString& GetLook() const;

  /** 
  * Snaps the popup window to the given side of the popup control.
  */
  void SetSnapSide(CATVid::Side i_snapSide);
  CATVid::Side GetSnapSide() const;

  /**
  * @deprecated, use SetSnapAlignment(CATVid::SnapAlignCenter) instead.
  * By default the SnapCenteredFlag property is set to FALSE.
  */
  void SetSnapCenteredFlag(CATBoolean i_snapCenteredFlag);
  /**
  * @deprecated, use GetSnapAlignment instead.
  * @return TRUE if SnapAlignment is CATVid::SnapAlignCenter.
  */
  CATBoolean GetSnapCenteredFlag() const;

  /**
  * Manages the alignment of the popup window relatively to the popup control.
  * Only used when the SnapFlag is set.
  * The default value is SnapAlignTop.
  * By default, for a SnapSide top or bottom, il will be aligned on top.
  * By default, for a SnapSide left or right, il will be aligned on left.
  * 
  * (In above ascii art, the small box is tht popup control, the big box is the popup window) 
  * 
  * SnapSide : Bottom
  * 
  *       SnapAlignLeft      SnapAlignCenter      SnapAlignRight
  *         (default)
  *        _                       _                       _ 
  *       |_|_____              __|_|__              _____|_|
  *       |       |            |       |            |       | 
  *       |       |            |       |            |       | 
  *       |_______|            |_______|            |_______| 
  * 
  * SnapSide : Top
  * 
  *       SnapAlignLeft      SnapAlignCenter      SnapAlignRight
  *         (default)
  *        _______              _______              _______     
  *       |       |            |       |            |       | 
  *       |       |            |       |            |       | 
  *       |_______|            |_______|            |_______| 
  *       |_|                     |_|                     |_|
  * 
  * SnapSide : Left
  *      
  *       SnapAlignTop      SnapAlignCenter      SnapAlignBottom
  *         (default)
  *         _______ _           _______              _______     
  *        |       |_|         |       |_           |       | 
  *        |       |           |       |_|          |       |_  
  *        |_______|           |_______|            |_______|_|
  *                                                   
  * SnapSide : Right
  *      
  *       SnapAlignTop      SnapAlignCenter      SnapAlignBottom
  *         (default)
  *      _ _______              _______              _______  
  *     |_|       |           _|       |            |       |    
  *       |       |          |_|       |           _|       |    
  *       |_______|            |_______|          |_|_______|    
  *      
  */
  void SetSnapAlignment(const CATVid::SnapAlignment& i_snapAlignment);
  const CATVid::SnapAlignment& GetSnapAlignment() const;

  /**
  * Specifies the popup window dimension.
  */
  void SetPopupDimension(const CATMathPoint2Df& i_popupDimension);
  const CATMathPoint2Df& GetPopupDimension() const;

  /**
  * Specifies whether the popup window is compact or not.
  */
  void SetPopupCompactFlag(CATBoolean i_compactFlag);
  CATBoolean GetPopupCompactFlag() const;

  /**
  * Specifies the Offset to use for positioning the popup window relatively to the popup control.
  * This property is taken into account only when the SnapFlag property is set to FALSE.
  */
  void SetPositionOffset(const CATMathVector2Df& i_offsetPosition);
  const CATMathVector2Df& GetPositionOffset() const;

  /**
  * Sets the autoclose flag that determines if a modal popup should close when a click is performed outside it.
  * @param i_AutoHideFlag the flag to set.
  */
  void SetAutoHideFlag(CATBoolean i_autoHideFlag);

  /**
  * @return the autoclose flag that determines if a modal popup should close when a click is performed outside it.
  * By default the autoclose flag is set to FALSE.
  */
  CATBoolean GetAutoHideFlag() const;

  /** 
   * Sets the flag that determines if a popup must be hidden by receiving ESCAPE key
   */
  void SetHideOnEscapeFlag(CATBoolean i_hideOnEscape);
  /** 
   * Returns the flag that determines if a popup must be hidden by receiving ESCAPE key
   */
  CATBoolean GetHideOnEscapeFlag() const;

  /**
  * Sets whether the popup consumes the mouse events that occur outside its bounding rectangle
  * when it is displayed in Modal mode.
  * @see @ref #GetModalFlag
  */
  void SetConsumeMouseEventFlag(CATBoolean i_consumeMouseEventFlag);

  /**
  * Returns TRUE if the popup consumes the mouse events that occur outside its bounding rectangle
  * when it is displayed in Modal mode, FALSE otherwise.
  * By default, this method returns TRUE.
  * @see @ref #GetModalFlag
  */
  CATBoolean GetConsumeMouseEventFlag() const;

  /**
  * Specifies whether the position of the popup window is limited to its viewer bounding rectangle,
  * whatever its contraints are, or not (in which case the popup window may be clipped).
  * By default the ConstraintUpdateAllowedFlag property is set to TRUE.
  * This property is taken into account only when the SnapFlag property is set to FALSE.
  */
  void SetConstraintUpdateAllowedFlag(CATBoolean i_constraintUpdateAllowedFlag);
  CATBoolean GetConstraintUpdateAllowedFlag() const;

  /**
   * Sets the extracted flag of the window.
   */
  void SetExtractedFlag(CATBoolean i_extractedFlag);

  /**
   * Returns the extracted flag of the popup window.
   */
  CATBoolean GetExtractedFlag() const;

  /**
  * @copydoc CATVidFraWindow#GetExtractableFlag
  */
  CATBoolean GetExtractablePopupWindowFlag() const;

  /**
  * @copydoc CATVidFraWindow#SetExtractableFlag
  */
  void SetExtractablePopupWindowFlag(CATBoolean i_ExtractablePopupWindowFlag);

  /**
  * Returns the @c VisibleStateChanged event.
  * The @c VisibleStateChanged event is emitted whenever the popup window visiblity has changed.
  * @see SetVisibleFlag
  * @par EventProperties
  *   - Name: @c "VisibleStateChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * VisibleStateChanged();

  /**
  * Returns the @c AutoHide event.
  * The @c AutoHide event is emitted whenever the popup is hidden.
  * @par EventProperties
  *   - Name: @c "AutoHide"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATVidPopupAutoHideEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * AutoHide();

  /**
  * Gets popup placement and behavior constraints.
  */
  CATVidFraPopupWindowConstraints& GetConstraints() const;

  virtual void TunnelInformation(const CATVidInformation& i_information);

  virtual void SetPresenterContent(CATVidWidget* i_pWidget);
  virtual CATVidWidget* GetPresenterContent() const;

  virtual CATISYPPresenter_var GetItem();

  virtual void Update();
  /**
  * @deprectated : use AutoHide Event either
  * Notification sent when a autohide popup is getting hidden by automatic behaviour
  * (click on the viewer outside the popup, click outside the application dialog, click on a menu of the application dialog.)
  */
  CATNotification* GetAutoHidePopupNotification() const;
  /** @deprecated use #SetSnapSide(CATVid::Side i_snapSide) instead */
  void SetSnapSide(unsigned int i_snapSide);
  /** @deprecated use #SetAutoHideFlag instead */
  void SetModalFlag(CATBoolean i_modalFlag);  
  /** @deprecated use #GetAutoHideFlag instead */
  CATBoolean GetModalFlag() const;
  /** @deprecated use GetAutoHidePopupNotification instead*/
  CATNotification* GetModalBackgroundPressNotification() const;
  /** @copydoc CATVidFraContextMenu#SetPositionOffsetForSnapping*/
  void SetPositionOffsetForSnapping(const CATMathPoint2Df& i_offset);
  /** @copydoc CATVidFraContextMenu#GetPositionOffsetForSnapping*/
  CATMathPoint2Df GetPositionOffsetForSnapping() const;

  void SetPreventFocusOnExtractedWindowFlag(CATBoolean i_preventFocusOnExtractedWindowFlag);
  CATBoolean GetPreventFocusOnExtractedWindowFlag();

protected:

  virtual ~CATVidCtlPopup ();

  virtual void CleanBeforeDestruction();
  CATVidCtlPopup(CreateLetterFunc i_pCreateLetterFunc);

private:
  // Copy constructor and equal operator
  CATVidCtlPopup (CATVidCtlPopup &);
  CATVidCtlPopup& operator=(CATVidCtlPopup&);

  int _hideOnEscape;
};

#endif // CATVidCtlPopup_h

