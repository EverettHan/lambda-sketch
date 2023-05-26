#ifndef CATVisCIDComboColor_H
#define CATVisCIDComboColor_H

#include "CATVisCIDPanel.h"

#include "CATVidCtl.h"
#include "CATVisCIDComboTools.h"
#include "CATRenderingAttribut.h"

class CATVidCtlCustomCombo;
class CATVisCIDComboColorData;
class CATVidCtlColorCompositePicker;

class ExportedByCATVisCIDPanel CATVisCIDComboColor: public CATVidCtl
{
  enum ColorComboType 
  {
    Saturated=0,
    Pastel
  };

  CATDeclareClass;
public:
  /**
  * iRed/iGreen/iBlue, valid range 0...255
  * iType: internal use
  *  0 : normal behavior of the combo color
  *    Automatic
  *    custo colors[0...16]
  *    basic colors[16]
  *    more...
  *    (none)
  *
  *  1 : behavior with customizable item but without interaction with custom colors' repositary.
  *    Undefined
  *    customizable
  *    custo colors[0...16]
  *    basic colors[16]
  *    more...
  *
  *  2 : behavior with customizable item and interaction with custom colors' repositary.
  *    customizable
  *    custo colors[0...16]
  *    basic colors[16]
  *    more...
  */
  CATVisCIDComboColor(CATCommand *i_pParent, const CATString & i_pIdentifier, 
    const unsigned char iRed = 255, const unsigned char iGreen = 255, const unsigned char iBlue = 255,
    CATBoolean iAutoAvailable = FALSE, 
    const CATVisCIDComboColor::ColorComboType iType = Saturated);

  virtual ~CATVisCIDComboColor();

  // 1...9
  void SetSelectedColor(const unsigned char iRed, const unsigned char iGreen, const unsigned char iBlue);

  // Valid inputs: Auto or None
  // Set only if corresponding entries are already created in combo
  void SetSpecialValue(const CATVisCIDComboValueType iType); 

  // returns type of value set
  // valid return values for type Value: 255 (for 0%), 190 (for 25%), 127 (for 50%), 63 (for 75%), 0 for (100%)
  CATVisCIDComboValueType GetSelect(unsigned char &oRed, unsigned char &oGreen, unsigned char &oBlue);
    
   /**
   * Get the @c Selected event.
   * 
   * The @c Selected event is emitted when user selected opacity value from combo
   *  
   * @par EventProperties
   *   - Name: @c "Selected"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * Selected();

  void CreateNoneLine();
  void DestroyNoneLine();
  
  /**
  * Internal use only...May be removed in future...
  */
  static void GetCustomColors(CATSYPDynArray<CATVidRGBA> & oCustomColors);

//------------------------------------------------------------------------------
private:
  void UpdateHelpMessage(const CATVisCIDComboValueType iValueType, const unsigned char iRed=0, const unsigned char iGreen=0, const unsigned char iBlue=0);
  void ComboSelect(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void ComboDrop(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void ComboMore(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void ColorEditorBtnClick(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs); 
  void GetBasicComboLines(CATSYPDynArray<CATBaseUnknown_var>& oComboLines);
  void GetCustomComboLines(CATSYPDynArray<CATBaseUnknown_var>& oComboLines);
  
  int IsInBasicColor(const unsigned char iR, const unsigned char iG, const unsigned char iB);
  int IsInCustomColor(const unsigned char iR, const unsigned char iG, const unsigned char iB);
  int IsInColorList(const unsigned char iR, const unsigned char iG, const unsigned char iB, const int *pColorList, int szColorList, int strid);
  CATVisCIDComboValueType GetColorAt(int iIndex, unsigned char &oRed, unsigned char &oGreen, unsigned char &oBlue);

 private:
  CATUnicodeString  _autoStr, _noneStr, _undefStr;
  CATBoolean _isAutoAvailable, _isNoneAvailable, _isUndefAvailable,_bTriggerEvents;
  unsigned int	_autoIndex, _undefIndex, _noneIndex, _currentColorIndex, _stdColorHeaderIndex, _custColorHeaderIndex;

  ColorComboType _type;

  int _basicColors[144], _custColors[100];

  CATVidCtlCustomCombo *_pCombo;
  CATVidCtlColorCompositePicker *_pColorEditor;
};

#endif
