#ifndef CATDlgDeclarativeManager_H
#define CATDlgDeclarativeManager_H

#include <DialogDeclarativeEngine.h>
#include <CATCommand.h>
#include <CATUnicodeString.h>
#include "CATDlgUtility.h"

class CATDialog;
class CATDlgWindow;
class CATInteractiveApplication;
class CATSYPTemplateData;

/**
 * @par Mandatory base class of you Dialog template target :
 * This is the base class for any template target of a Dialog declarative view.
 * It can only be used as a base class for view models (template targets) associated
 * to a Dialog template.
 *
 * For a given sypstyle Dialog Template, a template target has to be be referenced.
 * The template target MUST inherit CATDlgDeclarativeManager's behavior.
 *
 * @par Example : Creation of a Dialog template target
 *   -  CPP declaration : To create a Dialog template target, you simply need to create a class
 * that will reference CATDlgDeclarativeManager as its base class.
 * The Dialog template target must implement CATDlgDeclarativeManager as its base component with CATImplementClass.
 * The Dialog template target class must also implement @ref SetTemplatedView AND call CATDlgDeclarativeManager's implementation.(see code snippet below).
 * As a (delightful) consequence, you will be able to use the specificities of a template target.
 * @par
 * The following code snippet shows how a Dialog template target class MUST BE declared :
  * @par Header : DlgTarget.h
 * @code
 * #ifndef DlgTarget_H
 * #define DlgTarget_H
 * 
 * #include <CATDlgDeclarativeManager.h>
 * 
 * // The class definition
 * class DlgTarget : public CATDlgDeclarativeManager
 * {
 *    CATDeclareClass;
 * 
 *    public:
 * 
 *    // Constructor
 *    DlgTarget();
 * 
 *    // Destructor
 *    virtual ~DlgTarget();
 * 
 *    // SetTemplatedView implementation (mandatory)
 *    virtual void SetTemplatedView (CATBaseUnknown_var &i_spView, CATSYPTemplateData *i_pTemplateData);
 * 
 *    // Your properties and Callbacks methods below
 *    // Please add the missing declarations
 *    void ClickButton1 (CATCommand * ipControl, CATNotification  * ipNotification, CATCommandClientData iUsefulData);
 *    void ClickButton2 (CATCommand * ipControl, CATNotification  * ipNotification, CATCommandClientData iUsefulData);
 * 
 *    private:
 *    // Please add your private class members
 * };
 * @endcode
 * 
 * @par
 * The following code snippet shows how a Dialog template target class should be implemented :
  * @par Source : DlgTarget.cpp
 * @code
 * 
 * #include <DlgTarget.h>
 * 
 * // Constructor
 * DlgTarget::DlgTarget()
 *   : CATDlgDeclarativeManager()
 * {  }
 * 
 * // Destructor
 * DlgTarget::~DlgTarget()
 * {  }
 * 
 * // SetTemplatedView implementation (mandatory)
 * void DlgTarget::SetTemplatedView (CATBaseUnknown_var &i_spView, CATSYPTemplateData *i_pTemplateData)
 * {
 *    // CAUTION : The CATDlgDeclarativeManager form MUST BE CALLED before any other code is written here !!!
 *    CATDlgDeclarativeManager::SetTemplatedView(i_spView,i_pTemplateData);
 * 
 *    // Please add your implementation !
 * }
 * 
 * void DlgTarget::ClickButton1
 *      (CATCommand * ipControl, CATNotification  * ipNotification, CATCommandClientData iUsefulData)
 * {
 *    // This callback method is called on "PushBActivate" on "Button 1"
 *    // Please add your implementation !
 * }
 * 
 * void DlgTarget::ClickButton2
 *      (CATCommand * ipControl, CATNotification  * ipNotification, CATCommandClientData iUsefulData)
 * {
 *    // This callback method is called on "PushBActivate" on "Button 2"
 *    // Please add your implementation !
 * }
 * @endcode
 * 
 * @par
 *   -  Introspection : A Dialog template target must have a minimum sypintro file with its name,
 * father (that MUST inherit CATDlgDeclarativeManager) and potentially, our introspectable properties
 * and CommandCallbacks.
 *
 * @par Destruction of a Dialog template target
 * It is you reponsability to call a Release on a CATDlgDeclarativeManager inherited object.
 *
 * @par Usage of a Dialog template target
 * Your CATDlgDeclarativeManager based template target class can encapsulate all the introspectable
 * properties and CommandCallbacks you want to declare for an immediate use  in the associated template (sypstyle view).
 * Each property declared and defined inside your template target must also be referenced in 
 * the template target sypintro file to be bound in your stylesheet.
 */

class ExportedByDialogDeclarativeEngine CATDlgDeclarativeManager: public CATCommand
{
  CATDeclareClass ;

public:

  /** Destructor. */
  virtual ~CATDlgDeclarativeManager ();

  /**
   * Set the style (the view) of an introspectable Dialog template.
   * This method links the target template class (that inherits CATDlgDeclarativeManager) to the view, 
   * described in a template inside a sypstyle declarative file.
   *
   * @param i_templateName is the syp:name of the template (the view) you want to link to your introspectable Dialog (the model).
   *        This information is given in the sysptyle file, as a value the syp:name attribute of the <Template> node.
   *
   * @param i_path is the path of the sypstyle file that contains the template given by i_templateName.
   *
   * @param i_pApp is the CATInteractiveApplication that direclty or indirectly parents the declarative Dialog panel described in the templated view.
   *
   * @param i_fatherWindow is the CATDlgWindow that is the template's father window. Its default value is NULL. If you don't
   *        set it yourself, the CATDlgDeclarativeManager assumes that the root node of your templated view is a CATDlgWindow (a CATDlgDialog for instance).
   *        This means that if you don't set it yourself using this parameter, the Dialog Box HAS TO be EXPLICITELY declared as the root node of the template, 
   *        direclty in the sypstyle file.
   *        If this is not the case (if the template's root node is a CATDlgFrame or a CATDlgContainer for example), this parameter can be set by
   *        the developer in order to parent the templated view to an actual dialog box. 
   */
  void SetStyle(const CATUnicodeString &i_templateName, const CATUnicodeString &i_path, CATInteractiveApplication* i_pApp, CATDlgWindow* i_fatherWindow=NULL);

  /** 
   *@copydoc CATISYPTemplate#SetTemplatedView 
   *
   * This method MUST BE reimplemented in ANY CLASS that inherits CATDlgDeclarativeManager and this form of it MUST BE called
   * before any new implementation. Please read the example in the introduction of this header's documentation for more information. 
   */
  virtual void SetTemplatedView (CATBaseUnknown_var &i_spView, CATSYPTemplateData *i_pTemplateData);

  /**
   * Get a Dialog element that was declared in the template by using its syp:name
   *
   * @param i_name the object's syp:name in the template (from sypstyle file)
   *
   * @return a pointer the requested CATDialog
   * @return NULL if i_name does not match any syp:name in the template.
   */
  CATDialog* GetElementFromSYPName(const CATUnicodeString & i_name);

  /**
   * Get the root node of the template as a Dialog object 
   *
   * @return a pointer on a CATDialog which is the root node of the template
   */
  CATDialog* GetTemplateRoot();

  /**
   * Get the parent CATInteractiveApplication of the template.
   *
   * @return a pointer on the CATInteractiveApplication. 
   */
  CATInteractiveApplication* GetApplication();

    /** @copydoc CATISYPTemplate#SetTemplateName */
  virtual void SetTemplateName (const CATUnicodeString &i_templateName);

  /** @copydoc CATISYPTemplate#GetTemplateName */
  virtual const CATUnicodeString & GetTemplateName () const;

  /** @copydoc CATISYPTemplate#SetVariationName */
  virtual void SetVariationName (const CATUnicodeString &i_variationName);

  /** @copydoc CATISYPTemplate#GetVariationName */
  virtual const CATUnicodeString & GetVariationName () const;

  /** 
   * This is the implementation of CATISYPCommandCallbackConnector.
   * It is called by Style Processor when binding is needed between a command Notification and a command callback for a given CATCommand.
   * 
   * This implementation redirects the given command's CATCommand hiererachy on the CATDlgDeclarativeManager itself 
   * and encapsulates CATCommand's AddAnalyseNotificationCB.
   * 
   * @param i_pCmd the CATCommand who's the sender of the notification.
   * @param i_notificationClassName is the notification's class name.
   * @param i_method is the command callback method, declared in the target class of the template (that inherits CATDlgDeclarativeManager).
   */
  virtual void ConnectCommandCallback(CATCommand* i_pCmd, const char* i_notificationClassName, CATCommandMethod i_method);

protected:

  /** Constructor. */
  CATDlgDeclarativeManager ();

  /** 
   * Copy constructor
   * @param i_toCopy the CATDlgDeclarativeManager to copy
   */
  CATDlgDeclarativeManager (CATDlgDeclarativeManager & i_toCopy);

  /** 
   * Assignement operator. 
   */
  CATDlgDeclarativeManager& operator=(CATDlgDeclarativeManager&);

private:

  /** The template's name */
  CATUnicodeString _pTemplateName;

  /** The template's variation name */
  CATUnicodeString _pVariationName;

  /** The template data used by Style Processor */
  CATSYPTemplateData* _pTemplateData;

  /** The root element of the template, casted to Dialog. */
  CATDialog* _pDlgRoot;

  /** The Dialog father window of the template. 
   * If the template was parented to a CATInteractiveApplication, this attribute is NULL */
  CATDlgWindow* _pDlgFatherWindow;

  /** The CATInteractiveApplication, parent of the template. */
  CATInteractiveApplication* _pApp;

};

#endif
