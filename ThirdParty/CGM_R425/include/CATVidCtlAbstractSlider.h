#ifndef CATVidCtlAbstractSlider_h
#define CATVidCtlAbstractSlider_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATVid.h>

#include <nlohmann/json_fwd.hpp>

class CATVidMouseEventArgs;
class CATSYPEvent;
class CATVidMouseWheelEventArgs;
class CATVidCtlSlidingButton;

/**
 * @ingroup VIDControls
 * This widget is a base component for slider and scrollbar, that provides
 * an double value within a range. The main properties of the class are the 
 * minimum, maximum and current values, and the step values for the keyboard managment.
 *
 * @par Styling your slider
 * Here are the mandatory "syp:named" objects that must be found in
 * the template of your ".sypstyle" file:
 * @li Background [CATVidGP]: a GP with @c UseManipulatorFlag="1", @c
 * Press="@HandleBackgroundDrag" and @c Drag="@HandleBackgroundDrag"
 * that is used to scroll pages when user clicked in outside the
 * slidder.<br/>
 * Note that as of today this is only mandatory for interaction
 * recording.
 *
 * Here are the mandatory names (the @c "Name" property) that must be
 * found in the template of your ".sypstyle" file:
 * @li SlidingButton [CATVidCtlSlidingButton]: a sliding button.<br/>
 * Note that as of today this is only mandatory for interaction
 * recording.
 */
class ExportedByVisuDialog CATVidCtlAbstractSlider: public CATVidCtl
{
  CATDeclareClass;

public:

  /** Constructor*/
  CATVidCtlAbstractSlider();
  /** Constructor*/
  CATVidCtlAbstractSlider(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /* 
   * Initialize variable and add handler
   */
  void Init();

  /** 
   * Sets if the slider shows its values inverted. If the false, the minimum and maximum 
   * dimensions at they standard position, otherwise they will be displayed at their opposite
   * position.
   */
  void SetInvertedAppearanceFlag(CATBoolean i_invertedAppearanceFlag);

  /** @return the inverted appearence status */
  CATBoolean GetInvertedAppearanceFlag() const;

   /** 
   * Sets if the slider wheel is inverted. If the flag is false and orientation is horizontal, when the wheel increases,
   * the value increases. If the flag is false and the orientation is vertical, when the wheel increases, the value decreased.
   */
  void SetInvertedWheelFlag(CATBoolean i_invertedWheelFlag);

  /** @return the inverted wheel status */
  CATBoolean GetInvertedWheelFlag() const;

  /** Sets if a ValueChanged event is sent during slider translation.
   * If the parameter is FALSE, an event is sent only at the slider release.
   * Default is TRUE.
   */
  void SetTrackingFlag(CATBoolean i_trackingFlag);

  /** @return the tracking flag property */
  CATBoolean GetTrackingFlag() const;

  /** Sets if the slider works with double value or int value.
  * If the parameter is TRUE, slider value will be in double. In this case, use API methods ending with AsDouble
  * when dealing with values properties (mininimumValue, maximumValue, value, step, pageStep)
  * Default is FALSE.
  */
  void SetDoubleSliderFlag(CATBoolean i_doubleSliderFlag);
  /** @return the double slider flag property */
  CATBoolean GetDoubleSliderFlag();

  /**
   * Sets the maximum value of the slider as an int. Will modify the value if value > maximum value.
   */
  void SetMaximumValue(int i_maximumValue);

  /** @return the maximum value as an int*/
  int GetMaximumValue() const;

  /**
  * Sets the maximum value of the slider as a double. Will modify the value if value > maximum value.
  */
  void SetMaximumValueAsDouble(double i_maximumValue);

  /** @return the maximum value as a double*/
  double GetMaximumValueAsDouble() const;

  /**
   * Sets the minimum value as an int. Will modify the value if value < minimal value.
   */
  void SetMinimumValue(int i_minimumValue);

  /** @return the minimum value as an int*/
  int GetMinimumValue() const;

  /**
  * Sets the minimum value as a double. Will modify the value if value < minimal value.
  */
  void SetMinimumValueAsDouble(double i_minimumValue);

  /** @return the minimum value as a double*/
  double GetMinimumValueAsDouble() const;

  /** Sets the value of the slider as an int, after checking that minimal value < i_value < maximal value.*/
  void SetValue(int i_value, int i_sendValueChangedEvent = 1);

  /** @return the value as an int*/
  int GetValue() const;

  /** Sets the value of the slider as a double, after checking that minimal value < i_value < maximal value.*/
  void SetValueAsDouble(double i_value, int i_sendValueChangedEvent = 1);

  /** @return the value as a double*/
  double GetValueAsDouble() const;

  /** 
   * Sets the orientation of the widget. 
   * This will involve a rebuild of the interface by the style processor.
   */
  void SetOrientation(CATVid::Orientation i_orientation);

  /** @return the orientation of the widget */
  CATVid::Orientation GetOrientation() const;

  /** Sets the percentage of the slider, for internal managment. Prefer the Value property.*/
  void SetPercentage(float i_percentage);

  /** @return the percentage property*/
  float GetPercentage() const;

  /** Sets the step incremented or decremented by the arrow keys as an int.*/
  void SetSingleStep(int i_singleStep);

  /** @return the single step property as an int*/
  int GetSingleStep() const;

  /** Sets the step incremented or decremented by the arrow keys as a double.*/
  void SetSingleStepAsDouble(double i_singleStep);

  /** @return the single step property as a double*/
  double GetSingleStepAsDouble() const;

  /** Sets the step incremented or decremented by the PageUp and PageDowwn keys as an int.*/
  void SetPageStep(int i_pageStep);

  /** @return the page step property as an int*/
  int GetPageStep() const;

  /** Sets the step incremented or decremented by the PageUp and PageDowwn keys as a double.*/
  void SetPageStepAsDouble(double i_pageStep);

  /** @return the page step property as a double*/
  double GetPageStepAsDouble() const;

  bool StepUp();
  bool StepDown();

  bool PageUp();
  bool PageDown();

  /**
   * Specifies whether the slider value is undefined or not.
   * When a value is undefined, the slider view is made slightly transparent until the end user enters a value.
   * By default, the UndefinedFlag property is set to FALSE.
   */
  void SetUndefinedFlag(CATBoolean i_undefinedFlag);
  /**
   * Returns TRUE if the slider value is undefined, FALSE otherwise.
   */
  CATBoolean GetUndefinedFlag() const;

  /**
   * @deprecated
   * Get the slider drag notification
   */
  CATNotification *GetSliderMovedNotification() const;

  /**
   * Returns the @c ValueChanged event.
   * 
   * The @c ValueChanged event emission depends on the TrackingFlag (whose default is true) :
   *  - if it is TRUE, the ValueChanged event is emitted on the drag of the slider.
   *  - if it is FALSE, the ValueChanged event is emitted only on the release of the slider
   * 
   * @par EventProperties
   *   - Name: @c "ValueChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * ValueChanged();

   /**
    * Returns the @c DragStarted event.
    * 
    * The @c DragStarted event is emitted at the beginning of the drag of the slider, when the mouse is pressed.
    * @par EventProperties
    *   - Name: @c "DragStarted"
    *   - Type of propagation: @c NoPropagation
    *   - Type of argument: @ref CATSYPEventArgs
    * 
    * @return the event instance. @c AddRef has NOT been called on
    * the returned pointer.
    */
  static CATSYPEvent * DragStarted();

   /**
    * Returns the @c DragEnded event.
    * 
    * The @c DragEnded event is emitted at the end of the drag of the slider, when the mouse is released,
    * even if the value does not change
    * @par EventProperties
    *   - Name: @c "DragEnded"
    *   - Type of propagation: @c NoPropagation
    *   - Type of argument: @ref CATSYPEventArgs
    * 
    * @return the event instance. @c AddRef has NOT been called on
    * the returned pointer.
    */
  static CATSYPEvent * DragEnded();

  /** @copydoc CATVidWidget#PreInteractionRecord */
  int PreInteractionRecord(CATVidInteractionRecorderData &i_recorder);
  /** @copydoc CATVidWidget#InteractionReplay */
  void InteractionReplay(CATVidInteractionReplayerData &i_replayer);

  void HandleAbstractSliderEvent(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  virtual void HandleBackgroundPress(CATBaseUnknown *i_pSender, CATVidMouseEventArgs *i_pArgs);
  void HandleBackgroundRelease(CATBaseUnknown *i_pSender, CATVidMouseEventArgs *i_pArgs);
  /**
   * Handles drag event on background in order to have an easier slider to handle
   */
  void HandleBackgroundDrag(CATBaseUnknown* i_pSender, CATVidMouseEventArgs* i_mouseArgs);

  /**
   * Sets the value of the flag for displaying magnifier.
   */
  void SetShowMagnifierFlag (CATBoolean i_showMagnifierFlag);

  /**
    * @return TRUE if magnifier is displayed, FALSE otherwise 
    */
  CATBoolean GetShowMagnifierFlag() const;

  /**
   * Sets the value of the magnifier.
   */
  void SetValueMagnifier(CATUnicodeString i_valueMagnifier);

  /**
   * @return the value of the magnifier 
   */
  CATUnicodeString GetValueMagnifier() const;

  /**
   * Sets the side of the magnifier: TOP/Bottom for Horizontal slider and Left/right for Vertical slider
   */
   int GetMagnifierSideAlignment() const;

   /** 
    * @return the alignement of the magnifier 
    */
   void SetMagnifierSideAlignment(CATVid::Side i_magnifierSideAlignment);

   /**
    * Get the value of the flag which permit to align with a single step : if single step = 10 no value possible between 0 and 10 when we released
    */
   CATBoolean GetAdjustOnStepFlag() const;

   /**
    * @return TRUE if value is adjust with the single step FALSE otherwise
    */
   void SetAdjustOnStepFlag(CATBoolean i_adjustOnStepFlag);

   /*
   * Get the value of AdjustCursorOnStepFlag.
   */
   CATBoolean GetAdjustCursorOnStepFlag() const;

   /**
   * Warning. This option is taken in account if AdjustOnStepFlag is TRUE!!!!!
   * @return TRUE if value is adjust with the single step for cursor. FALSE otherwise
   */
   void SetAdjustCursorOnStepFlag(CATBoolean i_adjustCursorOnStepFlag);

   enum VisualState { Out = 0, PressedAndOut, Hover, PressedAndHover};
   CATVidCtlAbstractSlider::VisualState GetVisualState();

protected:

  /** Constructor*/
  CATVidCtlAbstractSlider(CreateLetterFunc i_pCreateLetterFunc);
  /** Constructor*/
  CATVidCtlAbstractSlider(CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);
  /** Destructor*/
  virtual ~CATVidCtlAbstractSlider();
  void UpdatePercentageFromValue();

private:

  // Copy constructor and equal operator
  CATVidCtlAbstractSlider (CATVidCtlAbstractSlider &);
  CATVidCtlAbstractSlider& operator=(CATVidCtlAbstractSlider& original);


  void UpdateValueFromPercentage(int i_sendValueChangedEvent = 1);
  void UpdateSlidingButtonPosition();

  virtual void UpdateDocumentLength() {};
  virtual void TemplateDataUpdated();

  /**
   * Implementation of @ref #PreInteractionRecord for mouse
   * interactions on the background GP.
   *
   * @param i_recorder the recorder
   */
  void PreInteractionRecordBackground(CATVidInteractionRecorderData &i_recorder);

  /**
   * Implementation of @ref #InteractionReplay for mouse interactions
   * on the background GP.
   *
   * @param i_replayer the replayer
   */
  void InteractionReplayBackground(CATVidInteractionReplayerData &i_replayer);
    /** 
   * Handler for @ref CATVidGP#MouseWheelm event
   * called when a mouse wheel is done over a widet, consumes the event.
   *
   * This handler must only be registered on a CATVidLayScrollable.
   */ 
  void HandleMouseWheel(CATBaseUnknown *i_pSender, CATVidMouseWheelEventArgs *i_pArgs);

  /**
   * Called when mouse enter or leave the widget to modify visual look
   */
  void OnMouseHoveringChanged(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);


  virtual nlohmann::json GetComputedPropertyInJSON(const std::string& i_propertyName) const;
  virtual nlohmann::json GetPropertyOnChildInJSON(const CATBaseUnknown_var& iChild, const std::string& i_propertyName);

protected:
  /**
   * Set the backgroundPressedFlag
   */
  void SetBackgroundPressedFlag(const CATBoolean &i_backgroundPressedFlag);

  /**
   * Indicates if the background of the slider has been pressed
   * Do not take into account the press state of the sliding button
   */
  CATBoolean GetBackgroundPressedFlag() const;

private:

  CATUnicodeString _valueMagnifier;
  CATVid::Orientation _orientation;
  double _minimumValue;
  double _maximumValue;
  double _value;
  float _percentage;
  double _pageStep;
  double _singleStep;
  unsigned int _backgroundPressedFlag  : 1;
  unsigned int _adjustOnStepFlag       : 1;
  unsigned int _adjustCursorOnStepFlag : 1;
  unsigned int _showMagnifierFlag      : 1;
  unsigned int _invertedAppearanceFlag : 1;
  unsigned int _invertedWheelFlag      : 1;
  unsigned int _trackingFlag           : 1;
  unsigned int _valueLock              : 1;
  unsigned int _undefinedFlag          : 1;
  unsigned int _doubleSliderFlag       : 1;
  unsigned int _magnifierSideAlignment : 2;
  unsigned int _percentageLock         : 21;

  CATVidCtlSlidingButton *_pSlidingButton;
  CATVidCtlSlidingButton *_pSlidingButtonUndefined;

private:
  int ApplyOrientationAsStyle();
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlAbstractSlider__VisualState);

#endif // CATVidCtlAbstractSlider_h
