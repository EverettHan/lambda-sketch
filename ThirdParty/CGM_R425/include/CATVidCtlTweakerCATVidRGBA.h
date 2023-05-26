#ifndef CATVidCtlTweakerCATVidRGBA_h
#define CATVidCtlTweakerCATVidRGBA_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>
#include <CATUnicodeString.h>

// VisuImmersiveDialog framework
#include <CATVidRGBA.h>

class CATVidCtlTexturedSlider;

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidRGBA : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidRGBA);
  DeclareResource(CATVidCtlTweakerCATVidRGBA, CATVidCtlTweakerCATVidRGBA);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATVidRGBA();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  CATVidColor GetValueAsVidColor() const;
  void SetValueAsVidColor(const CATVidColor& i_color);

  void SetInternalHue(int i_internalHue);
  int GetInternalHue() const;

  CATVidRGB GetValueAsVidRGB() const;
  void SetValueAsVidRGB(const CATVidRGB& i_rgb);

  /** @copydoc CATVidCtlColorCompositePicker::SetColorPickers */
  void SetColorPickers(const CATUnicodeString& i_colorPickerList);
  /** @copydoc CATVidCtlColorCompositePicker::GetColorPickers */
  const CATUnicodeString& GetColorPickers() const;

  /**
  * Specifies whether the tweaker value is unset or not.  
  * By default, the UndefinedFlag property is set to FALSE.
  */
  void SetUnsetFlag(CATBoolean i_unsetFlag);

  void ClickOnUnsetColorButton(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

  void OnDoubleClick(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

  /**
  * Returns TRUE if the tweaker value is unset, FALSE otherwise.
  */
  INLINE CATBoolean GetUnsetFlag() const {return _unsetFlag;}

  /**
  * Specifies whether the tweaker shows the unset color and transparency buttons.
  */
  void SetShowUnsetColorAndAlphaButtonsFlag(CATBoolean i_showUnsetColorAndAlphaButtonsFlag);

  /**
  * Returns TRUE if the tweaker shows the unset color and transparency buttons, FALSE otherwise.
  */
  INLINE CATBoolean GetShowUnsetColorAndAlphaButtonsFlag() const {return _showUnsetColorAndAlphaButtonsFlag;}

	/**
	* Return the color validator class name.
	*/
	CATUnicodeString GetColorValidatorClassName()const;
	/**
	* Set the color validator class name.  
	*/
	void SetColorValidatorClassName(const CATUnicodeString & i_colorValidatorClassName);

	/**
	* Specifies whether the tweaker shows the transparency editor.
	*/
	void SetShowAlphaEditorFlag(CATBoolean i_showAlphaEditorFlag);

	/**
	* Returns TRUE if the tweaker shows the transparency editor, FALSE otherwise.
	*/
	INLINE CATBoolean GetShowAlphaEditorFlag() const {return _showAlphaEditorFlag;}

  void SetUndefinedFlag(CATBoolean i_undefinedFlag);

  INLINE CATBoolean GetUndefinedFlag() const {return _undefinedFlag;}

   void SetUndefinedRGBFlag(CATBoolean i_undefinedRGBFlag);

  INLINE CATBoolean GetUndefinedRGBFlag() const {return _undefinedRGBFlag;}

  void SetUndefinedAlphaFlag(CATBoolean i_undefinedAlphaFlag);

  INLINE CATBoolean GetUndefinedAlphaFlag() const {return _undefinedAlphaFlag;}

protected:

  virtual ~CATVidCtlTweakerCATVidRGBA();
   
  // Overriden methods
  virtual void OnValueChanged();
  void TemplateDataUpdated();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidRGBA (CATVidCtlTweakerCATVidRGBA &);
  CATVidCtlTweakerCATVidRGBA& operator=(CATVidCtlTweakerCATVidRGBA& original);

  //void UpdateColor();
  void UpdateQuickEditSlider();  

  int _internalHue;
  CATVidCtlTexturedSlider* _pQuickEditSlider;
  CATUnicodeString _colorPickers;
  CATBoolean _unsetFlag;  
	CATBoolean _showUnsetColorAndAlphaButtonsFlag;
	CATUnicodeString _colorValidatorClassName;
	CATBoolean _showAlphaEditorFlag;

  CATBoolean _undefinedFlag = false;  
  CATBoolean _undefinedRGBFlag = false;  
  CATBoolean _undefinedAlphaFlag = false;  
};

#endif // CATVidCtlTweakerCATVidRGBA_h
