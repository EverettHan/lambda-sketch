#ifndef CATVisComboColor_H
#define CATVisComboColor_H

// Copyright Dassault Systemes 2007

#include "CATVisPropertiesUI.h"

#include "CATDlgCombo.h"

class CATColorChooserPanel;

#define BASIC_COLORS_TABLE_SIZE 144

/**
 * Class to create a combo to select a color.
 * <b>Role</b>:This class constructs a combo to select color among predefined color or custom color.
 * <br>The editor's combo displays the selected color. At the creation of the combo you
 * can set a specific color otherwise the white color is displayed. 
 * <br>To select a new color,the drop down list proposes in this order:
 * <ul>
 * <li>The current selected color</li>
 * <li>The defined "custom" colors</li>
 * <li>The first 16 "basic" colors </li> 
 * <li>To see more color</li>
 * </ul>  
 * When you click "more color" a second dialog object appears: you see the 48
 * "basic" colors and the 16 boxes for the "custom" colors.
 * <br>You can choose a color in selecting a box and in clicking "OK", or you can defined 
 * (or redefined) a "custom" color thanks to a third dialog object.
 * <br><br>When a color is selected, a <tt>CATDlgComboSelectNotification</tt> notification is sent,
 * and you can retrieves the color thanks to the @href #GetSelectedColor 
 * @see CATComboSymbol, CATComboWeight,CATComboDashed
 */
class ExportedByCATVisPropertiesUI CATVisComboColor : public CATDlgCombo
{
//------------------------------------------------------------------------------
public:

  /**
  * Constructs the combo to select a color.
  * @param iParent
  * The dialog's parent.
  * @param iRed
  * It's defined the red component of the first selected color.The value ranges from 0 to 255.
  * @param iGreen
  * It's defined the green component of the first selected color.The value ranges from 0 to 255.
  * @param iBlue
  * It's defined the blue component of the first selected color.The value ranges from 0 to 255.
  * @param iUsage
  * Internal usage, set 0 as the default value. 
  * @param iAutoComboAvailable
  * Internal usage, set 0 as the default value. 
  * @param iTypeOfColorTable
  * Internal usage, set 0 as the default value. 
  */

  CATVisComboColor( CATDialog * iParent,
                    const unsigned iRed = 255, 
                    const unsigned iGreen = 255,
                    const unsigned iBlue = 255,
                    unsigned int iAutoComboAvailable = 0,
                    unsigned int iTypeOfColorTable = 0);

  virtual ~CATVisComboColor();

  /**
   * Specifies the items contained in the combo color.
   * <br><b>iUsage</b>:
   *  0 : normal behavior of the combo color
   *    selected color
   *    Automatic
   *    custo colors
   *    basic colors
   *    more
   *    (none)
   *
   *  1 : behavior with customizable item but without interaction with custom colors' repositary.
   *    Undefined
   *    customizable
   *    selected color
   *    custo colors
   *    basic colors
   *    more
   *
   *  2 : behavior with customizable item and interaction with custom colors' repositary.
   *    customizable
   *    selected color
   *    custo colors
   *    basic colors
   *    more
   */
  void BuildComboContent(const unsigned int iUsage);

  /** 
   * Retrieves the selected color.
   * <br><b>Role</b>: When a color is choosen , a 
   * <tt>CATDlgComboSelectNotification</tt> notification is sent, and you 
   * can retrieve the selected color using this method.
   * @param iRed
   * It's defined the red component of the selected color.The value ranges from 0 to 255
   * @param iGreen
   * It's defined the green component of the selected color.The value ranges from 0 to 255
   * @param iBlue
   * It's defined the blue component of the selected color.The value ranges from 0 to 255
   */
  int GetSelectedColor(unsigned int * iRed, unsigned int * iGreen, unsigned int * iBlue);
  
  /** 
   * Sets the selected color.
   * <br>This color appears in the editor and at the first place in the drop down list.
   * @param iRed
   * It's defined the red component of the color.The value ranges from 0 to 255
   * @param iGreen
   * It's defined the green component of the color.The value ranges from 0 to 255
   * @param iBlue
   * It's defined the blue component of the color.The value ranges from 0 to 255
   */
  void SetSelectedColor(const unsigned int iRed, const unsigned int iGreen, const unsigned int iBlue);

  /** @nodoc */
  int GetSelectedColor(unsigned int *, unsigned int *, unsigned int *, CATUnicodeString *);

  /** @nodoc */
  void UnicodeStringToColor(CATUnicodeString&);

  /** @nodoc */
  void CreateNoneLine();

  /** @nodoc */
  void DestroyNoneLine();

  /** @nodoc */	
  enum CATVisComboColorSelectionEnum
  {
    CATNone,
    CATUndefined,
    CATCustomizable,
    CATMore,
    CATAuto
  };

  /** @nodoc */
  void SetSpecialSelection(CATVisComboColorSelectionEnum sel, int notif=0);

//------------------------------------------------------------------------------
protected:

  virtual void GetCustomizableShortHelp(CATUnicodeString& oCustomizable);
  virtual void CustomizableItemSelected();
  virtual void CustomizableItemUnselected();

  CATUnicodeString use_catalog (CATString catalog, CATString key,CATString other="");

  int _Usage;

  // tables des couleurs
  const int* _ConvertColorsTable;
  int _BasicColorsTable[BASIC_COLORS_TABLE_SIZE];//UMR-3088263
  int _CustomColorsTable[100];

  int _Nbcust;
  int _OldNbcust;  
  int _Tabcust[26]; //its size will be 17=16 +1, 1=for free space management

  // couleur courante selectionnee
  unsigned int _Red;
  unsigned int _Green;
  unsigned int _Blue;

  int SetSelectedColor(const unsigned int iRed, const unsigned int iGreen, const unsigned int iBlue, int notif);

//------------------------------------------------------------------------------
private:

  void FillCombo();

  int FindText (const int, CATUnicodeString *);

  void Drop     (CATCommand * command = NULL, CATNotification * notification=NULL, CATCommandClientData data=NULL);
  void Selected (CATCommand *, CATNotification *, CATCommandClientData);

  // _ColorChooser 
  CATColorChooserPanel  *_ColorChooser;

  void ColorChooserOk     (CATCommand *, CATNotification *, CATCommandClientData);
  void ColorChooserApply  (CATCommand *, CATNotification *, CATCommandClientData);
  void ColorChooserCancel (CATCommand *, CATNotification *, CATCommandClientData);

  int IsInCustomColorsTable(const unsigned int, const unsigned int, const unsigned int);
  int IsInBasicColorsTable(const unsigned int, const unsigned int, const unsigned int);

  void ReloadCustomColors();

  //-------------------------------------------
  // textes pour les bulles d'aides
  //-------------------------------------------
  CATUnicodeString _Automatic;
  CATUnicodeString _NoneColor;
  CATUnicodeString _Undefined;
  CATUnicodeString _MoreColors;
  CATUnicodeString _Customizable;
  CATUnicodeString _ColorText;

  //-------------------------------------------
  // options de creation du combo
  //-------------------------------------------
  unsigned int _isCurrentAvailable;
  unsigned int _isAutoAvailable;
  unsigned int _isUndefinedAvailable;
  unsigned int _isMoreAvailable;
  unsigned int _isNoneAvailable;
  unsigned int _isCustomizableAvailable;

  //-------------------------------------------
  // selection courante
  //-------------------------------------------

  // ligne selectionnee
  int _NumSelected;
  int _OldNumSelected;

  // flag pour savoir si une ligne a ete selectionne ou non
  unsigned int _NoneSelected;
  unsigned int _MoreSelected;
  unsigned int _AutoSelected;
  unsigned int _CurrentSelected;
  unsigned int _UndefinedSelected;
  unsigned int _CustomizableSelected;	
  unsigned int _DefaultColorSelected;
  unsigned int _CustoColorSelected;

  // texte de la bulle d'aide associee a la selection courante
  CATUnicodeString _TextToDisplay;
  CATUnicodeString _OldTextToDisplay;

  //--------------------------------------------
  // numero de lignes
  //--------------------------------------------
  void ComputeLineNumbers();

  int _NumCurrent;
  int _NumAuto;
  int _NumUndefined;
  int _NumCustomizable;
  int _NumCusto1, _NumCusto2;
  int _NumDefault1, _NumDefault2;
  int _NumMore;
  int _NumNone;
  int _NumMax;
};

#endif
