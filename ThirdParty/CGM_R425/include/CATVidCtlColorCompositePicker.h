// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATVidCtlColorCompositePicker.h
// Header definition of CATVidCtlColorCompositePicker
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  QJP created.
//===================================================================
#ifndef CATVidCtlColorCompositePicker_H
#define CATVidCtlColorCompositePicker_H

#include "VisuDialog.h"
#include "CATVidCtlColorPicker.h"

class CATVidColor;
class CATVidRGBA;
class CATSYPEventArgs;


static const char* s_VidDefaultColorPickers = "ColorSquareH|ColorWheel";

/**
 * This is the standard class for creating a VID Color Picker.
 * It embeds a choice of color pickers (square, sliders, circles, wheels, ...).
 * It embeds also a Color Comparator between a reference color, and the one you're modifying.
 * Main functions : #SetReference Color, for defining the reference color.
 * And #GetRGBAColor, for retrieving the color modified by the @c ColorCompositePicker.
 * 
 * @par C++ creation code example
 * <code>
 * #include "CATVidCtlColorCompositePicker.h"
 * #include "CATVidRGBA.h"
 * 
 * CATVidCtlColorCompositePicker* pColorPicker = CATVidCtlColorCompositePicker::CreateColorPicker();
 * pColorPicker->SetReferenceColor(CATVidRGBA(40,50,80,255));
 * </code>
 * 
 * @par syptyle creation example
 * <code>
 * <CATVidCtlColorCompositePicker ReferenceColor="40 50 80 255" />
 * </code>
 * 
 * @par C++ callback
 * You can suscribe to the event CATVidCtlColor::ColorChange, and call #GetRGBAColor
 * @see http://codewiki/codewiki/index.php/VID_:_Propagating_Events
 * 
 * @par Binding in C++
 * <code>
 * // "MyColor" is a property of type CATVidRGBA.
 * CATSYP::Connect(pColorPicker, "RGBAColor", this, "MyColor");
 * </code>
 * 
 * @par Binding in sypstyle
 * <code>
 * <CATVidCtlColorCompositePicker ReferenceColor="40 50 80 255" RGBAColor="@MyColor Mode=TwoWays" />
 * </code>
 *
 * @par ReferenceColor usage
 * The reference color is a color you have to set manually.
 * Set one at the creation of the component, and each time you "use" the color (for example, to paint a shape).
 * It's up to you to set it when you want.
 *
 * @par Tabs management
 * By default, when creating a CATVidCtlColorCompositePicker, there are two tabs : ColorSquareH and ColorWheel.
 * You can set different tabs with the factory #CreateColorCompositePicker or the method #SetColorPickers.
 * 
 * You can use the default set we propose, or use your own DataTemplates.
 * Available tabs set we propose (for now) :
 * - ColorWheel : a hue wheel, with a triangle inside.
 * - ColorSquareH : a square color picker, with a hue slider.
 * - ColorSquareS : a square color picker, with a saturation slider.
 * - ColorSquareV : a square color picker, with a value slider.
 * - ColorCircle : a circular color picker.
 * - ColorSpinBoxes : 3 spinboxes for rgb, hsl, or hsv.
 * - ColorSliders : 3 sliders for rgb, hsl, or hsv.
 * - ColorSlidersAndSpinBoxes : 3 spinboxes and 3 sliders for rgb, hsl, or hsv.
 * - ColorPaletteSimpleColors : a set of 30 colors (5 hues).
 * - ColorPaletteCATIAColors : legacy "CATIA colors".
 * - ColorPaletteWebColors : standard web colors (a.k.a. X11 colors).
 * - ColorHistory : the history of "user colors" i.e. colors "used" (when a call to SetReferenceColor is made). These are stored in preferences.
 *
 * @par Adding a custom tab
 * Each tab name correspond to the name of a DataTemplate, whose view must only contain
 * an object inheriting CATVidCltColorPicker.
 * For now, the view must have exactly the size 201x186, not more, not less.
 * This size will be checked, and it will assert if it is not correct.
 * 
 * @see CATVidCtlColorPicker
 * @see http://codewiki/codewiki/index.php/VID_:_Color_Picker
 */
class ExportedByVisuDialog CATVidCtlColorCompositePicker: public CATVidCtlColorPicker
{
  CATDeclareClass;
  DeclareResource(CATVidCtlColorCompositePicker, CATVidCtlColorCompositePicker);

public:
  /**
   * This method builds a styled CATVidCtlColorCompositePicker, with given color pickers in a tab.
   * @see #SetColorPickers
   */
  static CATVidCtlColorCompositePicker * CreateColorPicker (const CATUnicodeString& i_colorPickers=s_VidDefaultColorPickers, const CATUnicodeString& iCustomColorsSettingsFile="VIDColorPicker", const int & iCustomColorNumber = 10);
  /**
   * This method builds a styled CATVidCtlColorCompositePicker, with given color pickers in a tab.
   * It also sets the father command, and the Name.
   * In most cases, use the other CreateColorPicker method.
   * @see #SetColorPickers
   */
  static CATVidCtlColorCompositePicker * CreateColorPicker (CATCommand * i_pParent, const CATString & i_pIdentifier, const CATUnicodeString& i_colorPickers=s_VidDefaultColorPickers, const CATUnicodeString& iCustomColorsSettingsFile="VIDColorPicker", const int & iCustomColorNumber = 10);

  CATVidCtlColorCompositePicker ();
  virtual ~CATVidCtlColorCompositePicker ();

  /**
   * The color of reference of the Composite color picker.
   * It is used to be compared to the color currently modified in the composite color picker.
   * You should update the reference color whenever the color you're trying to modify change (for example, those of your object).
   */
  void SetReferenceColor( const CATVidRGBA & i_referenceColor);
  /**
   * @see #SetReferenceColor
   */
  CATVidRGBA GetReferenceColor( void ) const;

  /*
  * Set to undefined reference color.
  */
  void SetUndefinedReferenceColor(const CATBoolean & i_undefinedReferenceColor);

  /*
  * Get the undefined reference color flag value.
  */
  CATBoolean GetUndefinedReferenceColor();

  /*
  * Set to undefined reference transparency.
  */
  void SetUndefinedReferenceTransparency(const CATBoolean & i_undefinedTransparency);

  /*
  * Get the undefined reference transparency flag value.
  */
  CATBoolean GetUndefinedReferenceTransparency();

  /**
  * Return the color of currently selected swatch in custom colors palette.
  * returned value : 
  *                 -No custom color is selected : 0
  *                 -A custom color is selected : 1
  */
  int GetSelectedCustomColor(CATVidRGBA & o_SelectedCustomColor);
  /**
   * The list of color pickers you want in the composite color picker
   * Availables : ColorSquareH, ColorSquareS, ColorSquareV, ColorWheel, ColorSliders.
   * Syntax : "aaaaa|bbbbb|cccccc"
   */
  void SetColorPickers(const CATUnicodeString& i_colorPickers);
  /**
   * @see #SetColorPickers
   */
  const CATUnicodeString& GetColorPickers() const;   
  /**
   * Show a comparator between the reference color and the currently edited color.
   * Default is TRUE.
   */
  void SetShowColorComparatorFlag(const CATBoolean& i_showColorComparatorFlag);  
  /**
   * @see SetShowColorComparatorFlag
   */
  CATBoolean GetShowColorComparatorFlag() const;
  /**
   * When the ColorComparator is visible (see #SetShowColorComparatorFlag),
   * it will display or hide the ReferenceColor.
   * Default is TRUE.
   */
  void SetShowReferenceColorFlag(const CATBoolean& i_showReferenceColorFlag);  
  /**
   * @see SetShowReferenceColorFlag
   */
  CATBoolean GetShowReferenceColorFlag() const;
  /**
   * Show an hex editor for modifying the current color.
   * Default is TRUE.
   */
  void SetShowHexEditorFlag(const CATBoolean& i_showHexEditorFlag);  
  /**
   * @see SetShowHexEditorFlag
   */
  CATBoolean GetShowHexEditorFlag() const;
  /**
   * Show a combo for modifying the current profile color.
   * Default is FALSE.
   */
  void SetShowColorProfileSelectorFlag(const CATBoolean& i_showColorProfileSelectorFlag);  
  /**
   * @return the boolean indicating if the color profile selector is shown.
   */
  CATBoolean GetShowColorProfileSelectorFlag() const;

  /**
  * Show a combo for modifying the current profile color.
  * Default is FALSE.
  */
  void SetShow_sRGBEditorFlag(const CATBoolean& i_Show_sRGBEditorFlag);
  /**
  * @return the boolean indicating if the color profile selector is shown.
  */
  CATBoolean GetShow_sRGBEditorFlag() const;
  /**
   * If TRUE, displays a slider for controlling the transparency of the currently edited color,
   * as well as a preview of the color transparency.
   */
  void SetShowAlphaEditorFlag(const CATBoolean& i_showAlphaEditorFlag);  
  /**
   * @see SetShowAlphaEditorFlag
   */
  CATBoolean GetShowAlphaEditorFlag() const;

  /**
   * If TRUE, displays a customed color palette.
   */
  void SetShowCustomColors(const CATBoolean& i_showCustomColors);
  /**
   * @see SetShowAlphaEditorFlag
   */
  CATBoolean GetShowCustomColors() const;

  /**
  * If TRUE, alpha channel is used on Custom color. Otherwise, only RGB are used and alpha is the current one
  */
  void SetStoreTransparencyOnCustomColorsFlag(const CATBoolean& i_storeTransparencyOnCustomColorsFlag);
  /**
  * @see SetStoreTransparencyOnCustomColorsFlag
  */
  CATBoolean GetStoreTransparencyOnCustomColorsFlag() const;

  /**
  * Return the name of the composite picker custom color settings file.
  */
  CATUnicodeString GetCustomColorsSettingsFile() const;
  /**
  * Set the custom colors settings file name.
  * WARNING : if you set your own custom color file, you MUST implement the CATIVidCustomColorSettingsFile itf on following late type : 
  * CATVidCustomColor_CustomColorsSettingsFile, where "CustomColorsSettingsFile" is the name of your file.
  * You can see an example in CATVidCustomColor_VIDColorPicker implementation (don't forget calling the macro funtion CATCreateAndAddOMFactoryFunction and fill your ".func" dictionary).
  */
  void SetCustomColorsSettingsFile(CATUnicodeString iCustomColorsSettingsFile);

  /**
  * Return the array of custom colors.
  */
  CATSYPDynArray<CATVidRGBA> GetCustomColors();

  /**
  * Return the number of custom colors.
  */
  int GetCustomColorsNumber()const;

  /**
  * Set the number of custom colors.  
  */
  void SetCustomColorsNumber(int iCustomColorNumber);

  /**
  * Return the color editor show flag value.
  */
  CATBoolean GetShowColorEditorFlag()const;

  /**
  * Set the color editor show flag value.  
  */
  void SetShowColorEditorFlag(const CATBoolean & i_showColorEditorFlag);

  /**
  * Return the undefine color and transparency buttons show flag value.
  */
  CATBoolean GetShowUnsetColorAndAlphaButtonsFlag()const;

  /**
  * Set the undefine color and transparency buttons show flag value.  
  */
  void SetShowUnsetColorAndAlphaButtonsFlag(const CATBoolean & i_showUnsetColorAndAlphaButtonsFlag);

  /**
  * Return the maximum custom colors visible rows number. If number of rows of the custom colors are greater than this number, a scrollbar will be displayed.
  */
  int GetMaxCustomColorsVisibleRowsNumber()const;

  /**
  * Get the maximum custom colors visible rows number.
  */
  void SetMaxCustomColorsVisibleRowsNumber(const int & i_maxCustomColorsVisibleRowsNumber);

  /**
   * Sets the current color to the ReferenceColor.
   * It can be used to "cancel" the current modifications of the color.
   */
  void ResetColorToReference();
  /**
   * Sets the dimension of the tabs.
   * It is bound to minimum dimensions, but it is expected that clor pickers inside tabs
   * doesn't take more space than their RequestedMinimumDimension, for consistency of the component.
   * It may not change the view when decreasing the value, if the composite color picker is not in a compact dialog.
   */
  //void SetTabsDimension(const CATMathPoint2Df& i_tabsDimension);
  /**
   * @see SetTabsDimension
   */
  //CATMathPoint2Df GetTabsDimension() const;


  /**
  * Add a custom color to custom palette
  */
  void ClickOnCustomColorsButton(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

  /**
  * Remove some custom colors from custom palette
  */
  void ClickOnResetCustomColorsButton(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

  /**
  * undefine the color.
  */
  void ClickOnUndefineColorCB(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

  /**
  * undefine the transparency.
  */
  void ClickOnUndefineTransparencyCB(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs);

  /**
   * Confirm reset of custom colors
   */
  void ResetCustomColorsConfirmed(CATBaseUnknown *ipSender, CATSYPEventArgs *ipArgs);
  
public:
  /**
   * @see CATVidCtl#TemplateDataUpdated
   */
  void TemplateDataUpdated();
  /**
   * @see CATVidWidget#TunnelInformation
   */
  void TunnelInformation(const CATVidInformation& i_information); 

protected:
  CATVidCtlColorCompositePicker (CreateLetterFunc i_pCreateLetterFunc);

public: // DEPRECATED
  /**
  * @deprecated use SetRGBAColor instead
  */
  void SetNewColor( const CATVidColor & i_topColor);
  /**
  * @deprecated use GetRGBAColor instead
  */
  CATVidColor GetNewColor( void ) const;
  /**
  * @deprecated use SetReferenceColor instead
  */
  void SetCurrentColor( const CATVidColor & i_bottomColor);
  /**
  * @deprecated use GetReferenceColor instead
  */
  CATVidColor GetCurrentColor( void ) const;

private:

  CATVidCtlColorCompositePicker (CATVidCtlColorCompositePicker &);
  CATVidCtlColorCompositePicker& operator=(CATVidCtlColorCompositePicker&);

  void UpdateResetButtonDisplay();  
  
  CATBoolean _showColorComparatorFlag  :1;
  CATBoolean _showReferenceColorFlag   :1;
  CATBoolean _showHexEditorFlag        :1;
  CATBoolean _showAlphaEditorFlag      :1;
  CATBoolean _showCustomColors         :1;
  CATBoolean _storeTransparencyOnCustomColorsFlag : 1;
  CATBoolean _showQuickSelectorFlag    :1;
  CATBoolean _showUnsetColorButtonFlag :1;
  CATBoolean _unsetFlag                :1;
  CATBoolean _showUnsetColorAndAlphaButtonsFlag :1;
  CATBoolean _showColorEditorFlag      :1;  
  CATBoolean _showColorProfileSelectorFlag :1;
  CATBoolean _show_sRGBEditorFlag :1;
  CATUnicodeString _customColorsSettingsFile;
  int _customColorsNumber;
	int _maxCustomColorsVisibleRowsNumber;

  CATMathPoint2Df _tabsDimension;
  CATVidRGBA _lastSetColor;
  unsigned char _lastSetTransparency;


};

//-----------------------------------------------------------------------

#endif
