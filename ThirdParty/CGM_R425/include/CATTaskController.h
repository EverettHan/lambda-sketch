/**
 * @fullreview SCA-ERS 02:03:07
 * @error MISC  Y manque class CATUnicodeString et include CATBoolean
 * @error MISC N pas de constructeur par copie et pas d'operateur =
*/
#ifndef __CATTaskController_h
#define __CATTaskController_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATAfrProgressTask.h"

class CATIProgressTask;
class CATIProgressTaskUI;
class CATIProgressTaskUIImpl;
class CATProgressTaskPanel;
class CATProgressTaskAsyncPanel;
class CATFrmEditor;
class CATFrmWindow;

/**
* Class to launch an interruptible task.
* <b>Role:</b>This class enables the launching of a task associated with 
* a dialog box in order to indicate the progression of the process. To do this,
* create an instance of 
* this class and call the @href #Schedule method.
* @see CATIProgressTask, CATIProgressTaskUI
*/
class ExportedByCATAfrProgressTask CATTaskController: public CATBaseUnknown {

  CATDeclareClass;

public:

  /**
  * Constructs a default task controller.
  */
  CATTaskController ();

  virtual ~CATTaskController ();
  /**
  * Interrupt mode.
  * <br>If the task is interruptible (iInterruptible argument of Schedule = TRUE),
  * this enum lists the possible values of the interrupt button of the progress bar dialog.
  * <br> CancelProgressTask will display a Cancel button. Use this value when you want the task to be undone if the user interrupts it.
  * <br> StopProgressTask will display a Stop button. Use this value when you want the task to be stopped
  * and the partial result to be kept if the user interrupts it.
  */
  enum CATAfrProgressTaskInterruptMode {CancelProgressTask, StopProgressTask};

  /**
  * Launches the task.
  * @param  iTask
  * Interface pointer on the object which implements @href CATIProgressTask. 
  * @param  iInterruptible
  * If the task is interruptible (TRUE) an interrupt button is displayed in the dialog box;
  * so that 
  * the end user can interrupt the task, otherwise the value is FALSE.
  * @param  iUserData
  * This data is the input argument of the @href CATIProgressTask#PerformTask method.
  * @param iAutoFlushUI
  * If the boolean is TRUE, the dialog box will be automatically updated after each 
  * @href CATIProgressTaskUI#SetProgress call. Otherwise, you should use the
  * @href CATIProgressTaskUI#Flush to make manually the modification.
  * @param HideProgressBar
  * If the boolean is TRUE the user gets an interrupt panel without progress bar.
  * @param iPnlHiddenTime
  * Time during which the task panel stays hidden.
  * @param iInterruptMode
  * Behavior of the interrupt button. Does not take sense if iInterruptible is set to FALSE.
  */
  HRESULT Schedule (CATIProgressTask * iTask, CATBoolean iInterruptible = TRUE, void * iUserData = 0,
                    CATBoolean iAutoFlushUI = TRUE, CATBoolean HideProgressBar = FALSE, double iPnlHiddenTime = 0,
                    CATAfrProgressTaskInterruptMode iInterruptMode = CancelProgressTask );
  
  /** @nodoc */
  static void Interrupt ();

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATTaskController (const CATTaskController &);
  CATTaskController & operator= (const CATTaskController &);

  CATProgressTaskPanel        * _panel;
  CATProgressTaskPanel        * _oldPanel;
  CATIProgressTaskUI          * _ui;
  CATIProgressTaskUIImpl      * _uiImpl;
  static CATProgressTaskPanel * _currentPanel;
  CATBoolean                    _HeaderMode;
  CATProgressTaskAsyncPanel*    _AsyncPanel;
  CATFrmEditor*                 _pEditor;
  CATFrmWindow*                 _pFrmWindow;
};

#endif//__CATTaskController_h
