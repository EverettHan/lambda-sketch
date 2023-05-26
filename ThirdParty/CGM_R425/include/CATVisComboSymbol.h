#ifndef CATVisComboSymbol_H
#define CATVisComboSymbol_H

// Copyright Dassault Systemes 2006

#include "CATVisPropertiesUI.h"

#include "CATDlgCombo.h"
#include "CATUnicodeString.h"

/** 
* Class to create a combo to choose a symbol point.
* <b>Role</b>:This class constructs a combo to select a symbol among 9 types:
* <ol>
* <li>Cross</li>
* <li>Plus</li>
* <li>Circle</li>
* <li>Double Circle</li>
* <li>Middle Dot</li>
* <li>Full Square</li>
* <li>Star</li>
* <li>Dot</li>
* <li>Small Dot</li>
* </ol>
* <br>When a symbol is selected, a <tt>CATDlgComboSelectNotification</tt> notification is sent,
* and you can retrieves the index of the symbol thanks to the @href #GetSelectedSymbol
* @see CATComboColor, CATComboWeight,CATComboDashed
*/
class ExportedByCATVisPropertiesUI CATVisComboSymbol : public CATDlgCombo
{
 
//------------------------------------------------------------------------------
public:

  /** 
  * Constructs a combo to choose a symbol point.
  * @param iParent
  * The dialog's parent.
  * @param iSymbolInit
  *  The index of the first symbol displayed. The value ranges from 1 to 9, and the
  *  default value is 1 (a cross). 
  * @param iAutoComboAvailable
  * Internal usage, set 0 as the default value.
  */
  CATVisComboSymbol(  CATDialog* iParent, const unsigned int iSymbolInit = 1, unsigned int iAutoComboAvailable = 0);

  virtual ~CATVisComboSymbol();

  /**
  * Retrieves the symbol's index choosen.
  * <br><b>Role</b>: When a symbol is choosen , a 
  * <tt>CATDlgComboSelectNotification</tt> notification is sent, and you 
  * can retrieve the selected color using this method.
  * @return 
  * Index of the symbol.This value ranges from 1 to 9.
  */
  unsigned int GetSelectedSymbol();

  /** @nodoc */
  unsigned int GetSelectedSymbol(unsigned int& symbol);
  
  /**
  * Sets the index's symbol.
  * @param iSymbol
  * Index of the symbol.This value ranges from 1 to 9. 
  */
  void SetSelectedSymbol(const unsigned int iSymbol);
 
//------------------------------------------------------------------------------
private:

  void Selected (CATCommand *, CATNotification *, CATCommandClientData);
  void Drop     (CATCommand *, CATNotification *, CATCommandClientData);
  int  FindText (const int, CATUnicodeString *);

  CATUnicodeString  _Undefined;
  CATUnicodeString  _TextToDisplay;
  CATUnicodeString  _Automatic;

  unsigned int  _Symbol;
  unsigned int  _OldSymbol;
  unsigned int  _isAutoAvailable;
  unsigned int  _isUndefined;
};

#endif
