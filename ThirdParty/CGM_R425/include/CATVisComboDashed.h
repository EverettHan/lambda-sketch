#ifndef CATVisComboDashed_H
#define CATVisComboDashed_H

// Copyright Dassault Systemes 2006

#include "CATVisPropertiesUI.h"

#include "CATDlgCombo.h"
#include "CATUnicodeString.h"

/** 
* Class to create a combo to choose a line type.
* <b>Role</b>:This class constructs a combo to select a line type among 7 types:
* <ol>
* <li>Solid</li>
* <li>Dotted</li>
* <li>Dashed</li>
* <li>Dot-Dashed</li>
* <li>Phantom</li>
* <li>Small Dotted</li>
* <li>JIS Axis</li>
* </ol>
* <br>When a line type is selected, a <tt>CATDlgComboSelectNotification</tt> notification is sent,
* and you can retrieves the index of the line type thanks to the @href #GetSelectedLineType
* @see CATComboColor, CATComboWeight,CATComboSymbol
*/
class ExportedByCATVisPropertiesUI CATVisComboDashed : public CATDlgCombo
{
 
//------------------------------------------------------------------------------
public:

  /** 
  * Constructs a combo to choose a line type.
  * @param iParent
  * The dialog's parent.
  * @param iDialogObjectName
  * The name of the dialog object. 
  * @param iStyle
  * Internal usage. Set NULL the legal value.
  * @param iLineTypeInit
  *  The index of the first line type displayed. The value ranges from 1 to 7, and the
  *  default value is 1 (solid). 
  * @param iAutoComboAvailable
  * Internal usage, set 0 as the default value.
  */
  CATVisComboDashed( CATDialog* iParent, const int iLineTypeInit = 1, unsigned int iAutoComboAvailable = 0);
  virtual ~CATVisComboDashed();
  
  /**
  * Retrieves the line type's index choosen.
  * <br><b>Role</b>: When a line type is choosen , a 
  * <tt>CATDlgComboSelectNotification</tt> notification is sent, and you 
  * can retrieve the selected color using this method.
  * @return 
  * Index of the line type.This value ranges from 1 to 7.
  */
  unsigned int GetSelectedLineType();

  /** @nodoc */
  int GetSelectedLineType(unsigned int & linetype);

  /**
  * Sets the index's line type.
  * @param iLineType
  * Index of the line type.This value ranges from 1 to 7.
  */
  void SetSelectedLineType(const unsigned int iLineType);

  /** @nodoc */
  void AddOtherType(const CATString &, const int mode = 0);
  /** @nodoc */
  void RemoveOtherType();

  /** @nodoc */
  void CreateNoneLine();

  /** @nodoc */
  void DestroyNoneLine();

  /** @nodoc */
  void SetSelectedAuto();

  /** @nodoc */
  void SetSelectedNot();

//------------------------------------------------------------------------------
private:
  
  void Selected (CATCommand *, CATNotification *, CATCommandClientData);
  void Drop     (CATCommand *, CATNotification *, CATCommandClientData);

  int  FindText (const int, CATUnicodeString *);

  CATUnicodeString use_catalog (CATString key,CATString other);

  CATUnicodeString  _TextToDisplay;
  CATUnicodeString  _Undefined;
  CATUnicodeString  _Automatic;
  CATUnicodeString  _NoneDashed;

  CATString _icon;

  unsigned int  _isExtended : 1;
  unsigned int  _isNoneAvailable : 1;
  unsigned int  _isAutoAvailable : 1;
  unsigned int  _isUndefined : 1;

  unsigned int  _numNone : 7;
  unsigned int  _numUndefined : 7;
  unsigned int  _numAutomatic : 7;
  unsigned int  _numDashed : 7;
  
  unsigned int  _Dashed : 7;
  unsigned int  _typeDashed : 2;
};

#endif
