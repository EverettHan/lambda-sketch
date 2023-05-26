#ifndef CATVisComboWeight_H
#define CATVisComboWeight_H

// Copyright Dassault Systemes 2006

#include "CATVisPropertiesUI.h"

#include "CATDlgCombo.h"

class CATSettingRepository;

/** 
* Class to create a combo to choose a weight (thickness) of a line.
* <b>Role</b>:This class constructs a combo to select a line weigth among 63 values.
* <br>These 63 values follow the thicknesses displayed and modifiable in 
* Tools/Options/Display/Thickness. 
* <br><br>When a weight  is selected, a <tt>CATDlgComboSelectNotification</tt> notification is sent,
* and you can retrieves the index of the weight type thanks to the @href #GetSelectedThickness
* @see CATComboColor, CATComboDashed,CATComboSymbol
*/
class ExportedByCATVisPropertiesUI CATVisComboWeight : public CATDlgCombo
{
 
//------------------------------------------------------------------------------
public:

  /** 
  * Constructs a combo to choose a weight of a line.
  * @param iParent
  * The dialog's parent.
  * @param iWeightInit
  *  The index of the first weight displayed. The value ranges from 1 to 63, and the
  *  default value is 1 . 
  * @param iAutoComboAvailable
  * Internal usage, set 0 as the default value.
  */
  CATVisComboWeight(  CATDialog*        iParent, 
                      const int         iWeightInit = 1,
                      unsigned int      iAutoComboAvailable = 0,
                      bool              iDefaultWeightList = true);

  virtual ~CATVisComboWeight();
  
  /**
  * Retrieves the index of the weight choosen.
  * @return 
  * Index of the weight.This value ranges from 1 to 63.
  */
  unsigned int GetSelectedThickness();

  /** @nodoc */
  int GetSelectedThickness(unsigned int & thickness);

  /**
  * Sets the index of the weight.
  * @param iWeight
  * Index of the weight.This value ranges from 1 to 63.
  */
  void SetSelectedThickness(const unsigned int iWeight);

  /** @nodoc */
  void CreateNoneLine();

  /** @nodoc */
  void DestroyNoneLine();

  /** @nodoc */
  void SetSelectedAuto();

  /** @nodoc */
  void SetSelectedNot();

  /** @nodoc */
  void CkeModified (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
//------------------------------------------------------------------------------
private:

  void Selected (CATCommand *, CATNotification *, CATCommandClientData);
  void Drop     (CATCommand *, CATNotification *, CATCommandClientData);

  int  FindText (const int, CATUnicodeString *);

  void UpdateCombo();
  void ConvertToRightUnit(float *, char *);

  CATCallback         _ckeCB;
  CATSettingRepository *_Repository;

  CATUnicodeString  _TextToDisplay;
  CATUnicodeString  _Automatic;
  CATUnicodeString  _NoneWeight;
  CATUnicodeString  _Undefined;

  int  _index;

  unsigned int  _isNoneAvailable:1;
  unsigned int  _isAutoAvailable:1;
  unsigned int  _isUndefined:1;
  unsigned int  _numNone : 6;
  unsigned int  _numAuto : 6;
  unsigned int  _numUndefined : 6;
  unsigned int  _numThickness : 6;
  unsigned int  _Weight : 6;
  unsigned int  _typeWeight : 2;
  bool          _isDefaultWeightList:1;
};


#endif
