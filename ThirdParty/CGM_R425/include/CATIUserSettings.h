#ifndef CATI_USER_SETTINGS_H
#define CATI_USER_SETTINGS_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATEditor
 */

#include "CATAfrProperties.h"
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATEditorPage.h>
#include "CATString.h"

class CATSettingRepository;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrProperties IID IID_CATIUserSettings;
#else
extern "C" const IID IID_CATIUserSettings;
#endif

/**
 * Interface to create a Tools Options property page.
 * <b>Role</b>: Each property page of the Tools Options
 * command corresponds to an implementation of the
 * <tt>CATIUserSettings</tt> interface. 
 * <p>
 * <b>Step by step:</b> CATUserSettingsManager implements the 
 * factory <tt>IMyPropertyEdtFactory</tt> interface. 
 * This Factory creates a <tt>MyPropertyEdt</tt> instance class. This class implements the 
 * <tt>CATIUserSettings</tt> interface.
 * <ol>
 * <li> Create the factory <tt>IMyPropertyEdtFactory</tt> interface which 
 *      derives from @href CATIGenericFactory </li>
 * <li> Implement this factory interface using macros </li>
 * <br>
 *     This implementation, <tt>MyPropertyEdtFactory</tt>, is done in the module myModule 
 *     thanks to 2 macros: 
 *     @href CAT_EDITOR_DECLARE_FACTORY and @href CAT_EDITOR_DEFINE_FACTORY2 
 * <ol> 
 * <li>The header file <tt>MyPropertyEdtFactory.h</tt> must contain these two lines: </li>
 * 
 * <pre> 
 *       #include "CATEditorFactory.h"
 *       #include "MyPropertyEdt.h"
 * 
 *       #define ExportedByNOTHING
 *
 *       CAT_EDITOR_DECLARE_FACTORY(NOTHING, MyPropertyEdt, MyPropertyEdt);
 * </pre>
 *
 * <li>The source file <tt>MyPropertyEdtFactory.cpp</tt> must contain these lines:</li>
 *
 * <pre> 
 *        #include "MyPropertyEdtFactory.h"
 *
 *        CAT_EDITOR_DEFINE_FACTORY2(MyPropertyEdt, MyPropertyEdt);
 *
 *        #include "TIE_IMyPropertyEdtFactory.h"
 *        TIE_IMyPropertyEdtFactory(MyPropertyEdtFactory);
 *
 * </pre>
 * </ol>
 * <li>To declare that CATUserSettingsManager implements IMyPropertyEdtFactory,  
 *       insert the following line in the <b>interface dictionary</b>: </li>
 * <pre> 
 *       <b>CATUserSettingsManager</b>    IMyPropertyEdtFactory  myModule 
 * </pre>
 * <li>To declare that the factory creates an instance of the MyPropertyEdt class, 
 *       insert the following line in the <b>factory dictionary</b>: </li>
 * <pre> 
 *       MyPropertyEdt            IMyPropertyEdtFactory      
 * </pre>
 * <li> Implement the CATIUserSettings interface, describe here, with a class which derives from the adapter class @href CATEditor
 * </ol> 
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 */
class  ExportedByCATAfrProperties CATIUserSettings : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:

  /**
   * Builds the dialog inside the property sheet.
   * <br><b>Role</b>: This method should instantiate an object 
   * derived from @href CATDlgFrame giving <tt>iParent</tt>
   * as it's parent.
   * @param iParent
   *   The dialog parent.
   */
  virtual void BuildEditor(CATEditorPage * iParent) = 0; 

  /** 
   * Displays the parameter values.
   * <br><b>Role</b>: This method requests the dialog object
   * to display the correct parameter values, usually according to
   * a @href CATSettingRepository object content.
   * @param iRepository
   *   Not used.
   */
  virtual void SetUserSettingsValue (CATSettingRepository * iRepository) = 0;

  /**
   * Applies the modified parameter values.
   * <br><b>Role</b>: This method saves the modifications made
   * to parameter values in the property page. The usual
   * implementation is to call the 
   * @href CATSettingRepository#SaveRepository method of a setting
   * object. 
   * <br>This method must not use any pointer to the dialog object 
   * built in the @href #BuildEditor method, since it may have been
   * destroyed.
   * @param iRepository
   *   Not used.
   */
  virtual void CommitModification(CATSettingRepository * iRepository) = 0;
  
  /** 
   * Cancels the modifications brought to parameter values.
   * <br><b>Role</b>: This methods cancels the modifications brought
   * to the parameter values. It is called whenever the end user clicks
   * Cancel. The usual implementation is to call the
   * @href CATSettingRepository#Rollback method and then the
   * @href CATSettingRepository#Commit method of a setting object.
   * <br>This method must not use any pointer to the dialog object 
   * built in the @href #BuildEditor method, since it may have been
   * destroyed.
   * @param iRepository
   *   Not used.
   */
  virtual void CancelModification( CATSettingRepository * iRepository) = 0;

  /**
   * @nodoc
   * Closes secondary dialog objects.
   * <br><b>Role</b>: In the case that the dialog object associated with
   * the property sheets creates a secondary window,
   * this method must provide a way to close it.
   */
  virtual void CloseWindowFromEditor() = 0;

  /**
   * Resets parameter values to default.
   * <br><b>Role</b>: This method resets the parameter values to default 
   * ones, usually by calling the @href CATSettingRepository#WriteSetting
   * method of a setting object. The defaults values must be consistent
   * with those used when called the @href CATSettingRepository#ReadSetting
   * for the first time.
   * <br> The <tt>ResetUserSettingsValue</tt> method is called when 
   * end user clicks reset.
   * <br>This method must not use any pointer to the dialog object 
   * built in the @href #BuildEditor method, since it may have been
   * destroyed.
   */
  virtual void ResetUserSettingsValue () = 0;
} ;
CATDeclareHandler(CATIUserSettings, CATBaseUnknown ) ;
#endif
