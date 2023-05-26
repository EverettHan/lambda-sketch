/**
 *  @quickReview SCA 02:01:29
 *  @quickReview ERS-JAC 01:11:29
 */
#ifndef CATDLGLOCK_H
#define CATDLGLOCK_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// Abstract: The base class for Lock Button
//
//------------------------------------------------------------------------------
// Inheritance: CATDlgCheckButton
//                CATDlgControl
//                  CATDialog
//
//--------------------------------------------------------------------------
//
#include "CATDlgCheckButton.h"

#include "CATDialog.h"

//include System
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATSettingInfo.h"

class CATString;
class l_CATDialog;
class CATDlgContextualMenu;
class CATDlgDialog;

/**
 * Base class to create a lock button.
 * <b>Role</b>:This class is useful to set lock button before attributs that are
 * managed by an administrator.<br>
 * @see CATSettingRepository
 */
//--------------------------------------------------------------------------
class ExportedByDI0PANV2 CATDlgLock : public CATDlgCheckButton
{

  //--------------------------------------------------------------------------
public:
  /**
   * @nodoc
   * @param iParent
   * The parent widget.
   * @param iObjectName
   * The internal name of the button.
   * @param iStyle
   * The style of the button. Should be NULL which is the default value.
   * @param iRepository
   * The repository where is stored the state of the lock.
   * @param iAttributeName
   * The name of the attribute in the iRepository repository where the state is saved.
   */
  CATDlgLock(CATDialog *pParent, const CATString& rObjectName, CATDlgStyle nStyle,
             CATSettingRepository* iRepository, char * iAttributeName);


  /**
   * @nodoc
   * @param iParent
   * The parent widget.
   * @param iObjectName
   * The internal name of the button.
   * @param iStyle
   * The style of the button. Should be NULL which is the default value.
   * @param iRepository
   * The repository where is stored the state of the lock.
   * @param iAttributeNameArray
   * An array of attributes' name in the iRepository repository that are to be locked or unlocked.
   * @param iNumberOfAttributes
   * The size of iAttributeNameArray
   */
  CATDlgLock(CATDialog *pParent, const CATString& rObjectName, CATDlgStyle nStyle,
             CATSettingRepository* iRepository, 
             char ** iAttributeNameArray, const int iNumberOfAttributes);

  /**
   * Constructs an instance.
   * @param iParent
   * The parent widget.
   * @param iObjectName
   * The internal name of the button.
   * @param iSettingInfo
   * This information comes from the setting repository.  
   * @param iStyle
   * The style of the button. Should be NULL which is the default value.
   */
  CATDlgLock(CATDialog *pParent, const CATString& rObjectName,
             const CATSettingInfo & iSettingInfo, CATDlgStyle iStyle= NULL);


  /**
   * Constructs an instance.
   * @param iParent
   * The parent widget.
   * @param iObjectName
   * The internal name of the button.
   * @param iSettingInfoArray
   * Array of information concerning the attributes to be locked or kept unlocked. Those attributes must refer to the same setting repository.  
   * @param iNumberOfSettings
   * The size of iSettingInfoArray
   * @param iStyle
   * The style of the button. Should be NULL which is the default value.
   */
  CATDlgLock(CATDialog *pParent, const CATString& rObjectName, 
             const CATSettingInfo* iSettingInfoArray, const int iNumberOfSettings,
             CATDlgStyle iStyle= NULL);

  /**
   * @nodoc
   * Constructor to avoid using.
   * @param iParent
   * The parent widget.
   * @param iObjectName
   * The internal name of the button.
   * @param iStyle
   * The style of the button. Should be NULL which is the default value.
   */
  CATDlgLock(CATDialog        *iParent,
             const CATString  &iObjectName, 
             CATDlgStyle       iStyle=NULL);

  virtual ~CATDlgLock();

  
  /**
   * Sets the lock button style.
   * <b>Role:</b> Sets the lock button style, and returns the style that should have associated Dialog objects.
   * <br><br>This method should be used only for information purpose, since the @href #AddAssociatedDialog does the same job.
   * <br><br>In administrator mode, the button can be green, orange or red.
   * <br>In end-user mode, the button can only be red, or grey (disabled green).
   * <br>With no administration, the button is not represented.
   * <br>
   * @return 
   * The returned style is to be used to set the sensitivity of the attribut Dialog's object.
   * @param iAttributLockState
   * The state of the attribut to lock. Calls @href CATSettingRepository#GetLock method to get
   * this parameter.
   * <br>
   * <pre>
   *  Example of use: 
   * <tt>
   *   _MyDialogObjectToLock = new CATDlgCombo(..)
   *   _MyDialogObjectButtonLock = new CATDlgLock(..)
   * </tt>
   * <u><i>First choice:</i></u><tt>
   *   char mystate 
   *   _mysettingrepository->GetLock("Myattribut",mystate)
   *
   *   CATULong <b>style</b> = _MyDialogObjectButtonLock->ViewLock(mystate)
   *
   *   _MyDialogObjectToLock->SetSensibility(<b>style</b>)
   * </tt><br><br>
   * <u><i>Second choice:</i></u> This is a preferable alternative.<tt>
   *   _MyDialogObjectButtonLock->AddAssociatedDialog(_MyDialogObjectToLock); </tt>
   * </pre>
   */  
  CATULong ViewLock( char iAttributLockState);

  /**
   * Associates a Dialog object to the lock.
   * <br>This method has to be called for each object under the responsability of a given CATDlgLock.
   * @param iAssociatedDialog
   * The associated dialog object will be disabled if the lock is on.
   */
  void AddAssociatedDialog(CATDialog* iAssociatedDialog);

  /**
   * @nodoc
   * Returns the sensitivity applied to all the associated Dialog objects, 
   * which is linked to the state of the CATDlgLock.
   * @param oSensitivity
   * The sensitivity applied to all the Dialog objects associated to this CATDlgLock instance.
   */
  HRESULT GetAssociatedDialogSensitivity(CATULong &oSensitivity);

  /**
   * @nodoc
   * Requests the ClassName, IsA, and IsAKindOf methods to be created.
   */
  CATDeclareClass ;
private:
  //Surcharge du constructeur par copie et de l'opérateur =
  CATDlgLock(const CATDlgLock&);
  CATDlgLock& operator = (const CATDlgLock&);

  void OnLockCB(CATCommand *from, CATNotification *notif, CATCommandClientData);
  //void Init( char ** iAttributeNameArray);
  void Init();

  void MenuItem1CB(CATCommand*, CATNotification*, CATCommandClientData);
  void CloseInformationPanelCB(CATCommand*, CATNotification*, CATCommandClientData);

  void MessageDInsulte(int type);

  CATSettingInfo  * _SettingInfoArray;
  int               _numberOfAttributes;
  
/****
  CATSettingRepository    *  _Repository;
  char                    ** _attributeNameArray;
  int                        _numberOfAttributes;
***/
  CATULong                   _style;
  
  static CATUnicodeString   _ShortHelp;
  CATDlgContextualMenu    * _ContextualMenu;
  CATDlgDialog            * _InformationPanel;

  static CATBoolean _administrationAlreadyTested;
  static CATBoolean _administration;  
};
#endif
