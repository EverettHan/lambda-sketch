#ifndef __CATIProgressTask_h
#define __CATIProgressTask_h

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBaseUnknown.h"
#include "CATAfrProgressTask.h"

class CATIProgressTaskUI;
class CATString;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrProgressTask IID IID_CATIProgressTask;
#else
extern "C" const IID IID_CATIProgressTask;
#endif

/**
  * Interface describing an interruptible task.
  * <b>Role</b>:Objects executing a long process implement this interface
  * to benefit from a user interface indicating the progression 
  * of the task. The process must be launched by the 
  * @href CATTaskController#Schedule method.
  * <br>The user interface is a dialog box which contains:
  * <ul>
  * <li>A title</li>
  * <li>A Progress bar</li>
  * <li>An icon symbolizing the task</li>
  * <li>The name of the object concerned  by the task</li>
  * <li>A comment just above the progress bar</li>
  * <li>If the task is interruptible, a Cancel button is added 
  * and the end user can stop the process.</li>
  * <li>A percentage indicating the progression</li>
  * <li>An estimate of the remaining time</li>
  * </ul>
  * @see CATIProgressTaskUI, CATTaskController
  */
class ExportedByCATAfrProgressTask CATIProgressTask: public CATBaseUnknown {

  CATDeclareInterface;

public:

  /**
    * Executes the task.
    * <br><b>Role:</b> This method is called by the <tt>CATTaskController</tt> to
    * execute the task. 
    * <br>In most cases the code of the method is the following:
    * <ul>
    * <li>Set the range of the progression: @href CATIProgressTaskUI#SetRange </li>
    * <li>If the object concerned by the task is not fixed, 
    * use the @href CATIProgressTaskUI#SetObject method to customize it at run time, otherwise
    * the name set in the NLS file with the keyword <tt>ProgressTaskUI.ObjectName</tt> will 
    * be used.</li>
    *
    * <li>At each step</li>
    *   <ul>
    *   <li>Set the current position in the progression:
    *      @href CATIProgressTaskUI#SetProgress </li>
    * <li>If the comment displayed just above the progress bar is dependant on the step,
    * use the @href CATIProgressTaskUI#SetComment to customize it at run time, otherwise 
    * the name set in the Nls file with the keyword <tt>ProgressTaskUI.Comment</tt> will 
    * be used.</li>
    * <li> Check if the task has been interrupted in 
    * using the @href CATIProgressTaskUI#IsInterrupted method. If it is the case, return
    * E_FAIL to end the process.</li>
    * </ul>
    * </ul>
    * @param iUI
    * The task's user interface. 
    * @param iUserData
    * This data comes from the third argument of
    * the @href CATTaskController#Schedule method
    * @return
    * <ul>
    * <li>S_OK: The task ends normally. </li>
    * <li>E_FAIL: Used to stop the task in case of end user interruption</li>
    * </ul>
    * Both, the dialog box is closed and deleted automatically.
    */  
  virtual HRESULT PerformTask    (CATIProgressTaskUI  * iUI, void * iUserData) = 0;

  /**
    * Returns the NLS filename.
    * <br><b>Role:</b>This NLS file contains the information needed to customize the
    * dialog box. The keywords are the following:
    * <ul>
    * <li>The title : <tt>ProgressTaskUI.Title</tt></li>
    * <li>The comment above the progress bar: <tt>ProgressTaskUI.Comment</tt></li>
    * <li>The Object concerned by the task : <tt>ProgressTaskUI.ObjectName</tt></li>
    * </ul>
    * The comment and object can be customized at run time by using 
    * the @href CATIProgressTaskUI#SetComment and  @href CATIProgressTaskUI#SetObject methods. 
    * @param oCatalogName
    * The NLS filename without the suffix can be found in the 
    * CNext/resources/msgcatalog directory. 
    */  
  virtual HRESULT GetCatalogName (CATString           * oCatalogName) = 0;

  /**
    * Returns the icon name.
    * @param oIcon
    * The icon displayed in the dialog box symbolizing the task. The
    * name of the icon can be found in the CNext/resources/graphic/icons/normal 
    * directory, without the <tt>".bmp"</tt> suffix. 
    */  
  virtual HRESULT GetIcon        (CATString           * oIcon) = 0;

};


CATDeclareHandler (CATIProgressTask, CATBaseUnknown);


#endif//__CATIProgressTask_h
