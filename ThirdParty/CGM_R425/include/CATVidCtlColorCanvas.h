// COPYRIGHT DASSAULT SYSTEMES 2021
#pragma once

#include <VisuDialog.h>
#include <CATVidCtl.h>

#include <array>

#define CATDeclareVIDProperty(PropertyName, ArgType) \
  void Set##PropertyName(const ArgType &i_arg);      \
  ArgType Get##PropertyName() const;                 \

class ExportedByVisuDialog CATVidCtlColorCanvas : public CATVidCtl
{
  CATDeclareClass;

public:
  CATVidCtlColorCanvas ();
  virtual ~CATVidCtlColorCanvas ();
  /*
  * Sets the value as HSV, with first float between 0 and 360, and two others between 0 and 100
  */
  void SetValueAsHSV(const std::array<float, 3>& i_valueAsHSV);
  const std::array<float, 3>& GetValueAsHSV() const;
  /*
  * Sets the value as undefined.
  * This flag does not reset the value returned by the GetValueXXX method, the undefined state is a semantic
  */
  CATDeclareVIDProperty(UndefinedFlag, bool);
  /*
  * Sets the X coordinate attribute of the canvas. May be "Hue", "Saturation", "Value", "Lightness", "Red", "Green", "Blue"
  */
  CATDeclareVIDProperty(SubColorAttributeX, CATUnicodeString);
  /*
  * Sets the Y coordinate attribute of the canvas. May be "Hue", "Saturation", "Value", "Lightness", "Red", "Green", "Blue"
  */
  CATDeclareVIDProperty(SubColorAttributeY, CATUnicodeString);
  /*
  * Sets the modulation value to apply to the canvas.
  * If "Hue", value must be between 0 and 360
  * If "Value", "Saturation", "Lightness", value must be between 0 and 100
  * If "Red", "Green"; "Blue", value must be between 0 and 255
  */
  CATDeclareVIDProperty(ModulationValue, float);

public:
  /**
  * Get the @c ValueChanged event.
  * The @c ValueChanged event is emitted whenever the value is modified.
  * @par EventProperties
  *   - Name: @c "ValueChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent *ValueChanged();

  /**
  * Get the @c EditionStarted event.
  * The @c EditionStarted event is emitted whenever the user is starting to modify the value.
  * @par EventProperties
  *   - Name: @c "EditionStarted"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent *EditionStarted();

  /**
  * Get the @c EditionFinished event.
  * The @c EditionFinished event is emitted whenever the user has finished to modify the value.
  * @par EventProperties
  *   - Name: @c "EditionFinished"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent *EditionFinished();

  /**
  * Get the @c UndefinedFlagChanged event.
  * The @c UndefinedFlagChanged event is emitted when the value is set as undefined.
  * @par EventProperties
  *   - Name: @c "UndefinedFlagChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent *UndefinedFlagChanged();
  /** @copydoc CATVidWidget#PreInteractionRecord */
  int PreInteractionRecord(CATVidInteractionRecorderData &i_recorder);
  /** @copydoc CATVidWidget#InteractionReplay */
  void InteractionReplay(CATVidInteractionReplayerData &i_replayer);
  /** @copydoc CATVidWidget#InteractionReplay */
  void PostInteractionRecord(CATVidInteractionRecorderData &i_recorder, const CATSYPProperties &i_delayedRecordingData);

  virtual void Update();
private:
  CATVidCtlColorCanvas(CATVidCtlColorCanvas &);
  CATVidCtlColorCanvas& operator=(CATVidCtlColorCanvas&);
};
