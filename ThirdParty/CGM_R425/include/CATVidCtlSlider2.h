// COPYRIGHT Dassault Systemes 2021
#ifndef CATVidCtlSlider2_H
#define CATVidCtlSlider2_H

#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <vector>
class CATVidCtlSlider2ReplayValues;

class ExportedByVisuDialog CATVidCtlSlider2 : public CATVidCtl
{
  CATDeclareClass;
public:
  /**
   * Constructs a Immersive styled CATVidCtlSlider2.
   * @param i_pParent
   *   The parent of the button.
   * @param i_pIdentifier
   *   The name of the button.
   */
  static CATVidCtlSlider2* CreateImmersiveSlider(CATCommand* i_pParent, const CATString& i_pIdentifier);

  /** Constructor */
  CATVidCtlSlider2();

  /**
   * Sets the maximum value of the slider. Will modify the value if value > maximum value.
   */
  void SetMaximumValue(double i_maximumValue);
  /** @return the maximum value */
  double GetMaximumValue() const;
  /**
   * Sets the minimum value . Will modify the value if value < minimal value.
   */
  void SetMinimumValue(double i_minimumValue);
  /** @return the minimum value */
  double GetMinimumValue() const;
  /** Sets the value of the slider, after checking that minimal value < i_value < maximal value.*/
  void SetValue(double i_value, int i_index=0);
  /** @return the value*/
  double GetValue(int i_index=0) const;

  void SetValues(const std::vector<double> &i_values);
  const std::vector<double> &GetValues() const;
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
   * Sets the orientation of the widget. 
   * This will involve a rebuild of the interface by the style processor.
   */
  void SetOrientation(CATVid::Orientation i_orientation);
  /** @return the orientation of the widget */
  CATVid::Orientation GetOrientation() const;
  /** Sets the step incremented or decremented by the arrow keys as a double.*/
  void SetSingleStep(double i_singleStep);
  /** @return the single step property as a double*/
  double GetSingleStep() const;
  /** Sets the step incremented or decremented by the PageUp and PageDowwn keys .*/
  void SetPageStep(double i_pageStep);
  /** @return the page step property */
  double GetPageStep() const;
  /**
   * Sets the value of the flag for displaying popup.
   */
  void SetShowPopupFlag(CATBoolean i_showPopupFlag);
  /**
    * @return TRUE if popup is displayed, FALSE otherwise 
    */
  CATBoolean GetShowPopupFlag() const;
  /**
   * @return the value of the popup 
   */
  CATUnicodeString GetValuePopup() const;
  /**
    * Sets the value of the flag which permit to align with a single step : if single step = 10 no value possible between 0 and 10 when we released
    */
  CATBoolean GetAdjustOnStepFlag() const;
  /**
    * @return TRUE if value is adjust with the single step FALSE otherwise
    */
  void SetAdjustOnStepFlag(CATBoolean i_adjustOnStepFlag);

  /**
   * Sets the value of the flag for displaying ticks.
   */
  void SetShowTicksFlag(CATBoolean i_showTicksFlag);
  /**
    * @return TRUE if Ticks are displayed, FALSE otherwise 
    */
  CATBoolean GetShowTicksFlag() const;
  /**
  * Sets the value interval beetween two marks as an int.
  * @see CATVidCtlAbstractSlider#SetValue
  */
  void SetTickInterval(double i_tickInterval);
  /** @return the value interval beetween two ticks as an int*/
  double GetTickInterval() const;

  void StepUp(int i_index=0);
  void StepDown(int i_index=0);

  void PageUp(int i_index=0);
  void PageDown(int i_index=0);


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
  static CATSYPEvent *ValueChanged();

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
  static CATSYPEvent *DragStarted();

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
  static CATSYPEvent *DragEnded();
  /** @copydoc CATVidWidget#PreInteractionRecord */
  int PreInteractionRecord(CATVidInteractionRecorderData &i_recorder);
  /** @copydoc CATVidWidget#InteractionReplay */
  void InteractionReplay(CATVidInteractionReplayerData &i_replayer);
  /** @copydoc CATVidWidget#InteractionReplay */
  void PostInteractionRecord(CATVidInteractionRecorderData &i_recorder, const CATSYPProperties &i_delayedRecordingData);

  virtual void Update() override;

protected:
  virtual ~CATVidCtlSlider2();

private:
  CATVidCtlSlider2(CATVidCtlSlider2 &);
  CATVidCtlSlider2 &operator=(CATVidCtlSlider2 &);
};

#endif
