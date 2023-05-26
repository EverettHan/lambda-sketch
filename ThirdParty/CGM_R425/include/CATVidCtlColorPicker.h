// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATVidCtlColorPicker.h
// Header definition of CATVidCtlColorPicker
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  QJP created.
//===================================================================
#ifndef CATVidCtlColorPicker_H
#define CATVidCtlColorPicker_H

#include <CATVidCtl.h>
#include <VisuDialog.h>
#include <CATVidRGBA.h>
#include <CATSYPDeclareEnumFactory.h>


//-----------------------------------------------------------------------

/**
 * Base class for color pickers.
 * @see CATVidCtlColorCompositePicker for use.
 */
class ExportedByVisuDialog CATVidCtlColorPicker: public CATVidCtl
{
  CATDeclareClass;

  DeclareResource(CATVidCtlColorPicker, CATVidCtl);

public:
  /** Color profile preview supported by ColorPicker*/
  enum RgbProfile {NoProfile=0, sRGB};

  // Standard constructors and destructors
  // -------------------------------------
  CATVidCtlColorPicker ();
  virtual ~CATVidCtlColorPicker ();
  
  /**
   * Sets the color of the color picker in RGBA regarding the current profile.
   * Sends a @ColorChange event.
   */
  void SetRGBAColor(const CATVidRGBA & i_Color);
  /**
   * Retrieves the color of the color picker in RGBA regarding the current profile.
   */
  const CATVidRGBA& GetRGBAColor() const;
  /**
  * Sets the color of the color picker in RGBA as a sRGB color
  * Sends a @ColorChange event.
  */
  void SetsRGBAColor(const CATVidRGBA & i_Color);
  /**
  * Retrieves the color of the color picker in RGBA as a sRGB color
  */
  CATVidRGBA GetsRGBAColor() const;  
  /**
    * Sets the color of the color picker in RGBA as a linear color
    * Sends a @ColorChange event.
    */
  void SetLinearRGBAColor(const CATVidRGBA & i_Color);
  /**
  * Retrieves the color of the color picker in RGBA as a sRGB color
  */
  CATVidRGBA GetLinearRGBAColor() const;

  /**
   * Sets the preview RGB profile. Default is NoProfile.
   * No consequence on model.
   */
  void SetRGBProfile(CATVidCtlColorPicker::RgbProfile i_RGBProfile);
  /**
   * @return the color profile used in the color picker
   */
  CATVidCtlColorPicker::RgbProfile GetRGBProfile()const;

  /**
  * Do not use...use SetRGBAColor instead.
  * 
  */
  void SetVIDColor(const CATVidColor & i_Color);
  /**
  * Do not use...use GetRGBAColor instead.
  * 
  */
  const CATVidColor& GetVIDColor() const;
  /**
   * Sets the opacity of the color, independantly of other values.
   */
  void SetAlpha(const unsigned char& i_alpha);
  /**
   * Equivalent to GetRGBAColor().GetA().
   * @see SetAlpha
   */
  unsigned char GetAlpha() const;
  /**
   * Sets the transparency of a color, it is an equivalent of 255-alpha.
   */
  void SetTransparency(const unsigned char& i_transparency);
  /**
   * Equivalent to 255-GetRGBAColor().GetA().
   * @see SetTransparency
   */
  unsigned char GetTransparency() const;
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
  * Return the undefine transparency flag value of color picker
  */
  CATBoolean GetUndefinedTransparencyFlag()const;
  /**
  * Set the undefine transparency flag to color picker.  
  */
  void SetUndefinedTransparencyFlag(const CATBoolean & i_undefinedTransparencyFlag);
  /**
  * Return the color validator class name.
  */
  CATUnicodeString GetColorValidatorClassName()const;
  /**
  * Set the color validator class name.  
  */
  void SetColorValidatorClassName(const CATUnicodeString & i_colorValidatorClassName);

	/**
   * Get the @c ColorChange event.
   * 
   * The @c ColorChange event is emitted when the selected color changed
   * 
   * @par EventProperties
   *   - Name: @c "ColorChange"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.dep
   */
  static CATSYPEvent * ColorChange();
  
  /**
   * Returns the @c ColorEditingStarted event.
   * The @c ColorEditingStarted event is emitted whenever the ColorPicker starts a long edition transaction.
   * @par EventProperties
   *   - Name: @c "UpOrDownButtonPressed"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* ColorEditingStarted();

  /**
   * Returns the @c ColorEditingFinished event.
   * The @c ColorEditingFinished event is emitted whenever the ColorPicker ends a long edition transaction.
   * @par EventProperties
   *   - Name: @c "ColorEditingFinished"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* ColorEditingFinished();


  /**
  * Returns the @c ColorDoubleClick event.
  * The @c ColorDoubleClick event is emitted whenever color is doublecliked.
  * @par EventProperties
  *   - Name: @c "ColorDoubleClick"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* ColorDoubleClick();

  /**
  * Returns the @c UndefinedColorFlagChanged event.
  * The @c UndefinedColorFlagChanged event is emitted just after the UndefinedFlag changed.
  * @par EventProperties
  *   - Name: @c "UndefinedColorFlagChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* UndefinedColorFlagChanged();

    /**
  * Returns the @c UndefinedTransparencyFlagChanged event.
  * The @c UndefinedTransparencyFlagChanged event is emitted just after the UndefinedTransparencyFlag changed.
  * @par EventProperties
  *   - Name: @c "UndefinedTransparencyFlagChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* UndefinedTransparencyFlagChanged();

protected:
  /**
   * @copydoc CATVidCtlColorPicker::StartColorEditing
   */
  void StartColorEditing();
  /**
   * @copydoc CATVidCtlColorPicker::EndColorEditing
   */
  void EndColorEditing();
  
public:
  /** @copydoc CATVidWidget::TunnelInformation */
  virtual void TunnelInformation(const CATVidInformation& i_information);
  /**
   * Handles the ColorEditingStarted event dispatched by some color pickers.
   * Reemits a ColorEditingStarted event.
   */
  void OnColorEditingStarted(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs); 
  /**
   * Handles the ColorEditingFinished event dispatched by some color pickers.
   * Reemits a ColorEditingFinished event.
   */
  void OnColorEditingFinished(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs); 
  /**
  * Handles the ColorDoubleClick event dispatched by some color pickers.
  * Reemits a ColorDoubleClick event.
  */
  void OnColorDoubleClicking(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  
protected:
  CATVidCtlColorPicker (CreateLetterFunc i_pCreateLetterFunc);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlColorPicker (CATVidCtlColorPicker &);
  CATVidCtlColorPicker& operator=(CATVidCtlColorPicker&);

public:
  /** @deprecated, use ColorChange instead */
  static CATSYPEvent * ColorSelected();
};
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlColorPicker__RgbProfile);

//-----------------------------------------------------------------------

#endif
