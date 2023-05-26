#ifndef __CATIProgressTaskUI_h
#define __CATIProgressTaskUI_h

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATAfrProgressTask.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrProgressTask IID IID_CATIProgressTaskUI;
#else
extern "C" const IID IID_CATIProgressTaskUI;
#endif


/**
  * Interface to customize user interface for an interruptible task.
  * <b>Role</b>This interface is used in the @href CATIProgressTask#PerformTask method.
  * @see CATIProgressTask, CATTaskController
  */
class ExportedByCATAfrProgressTask CATIProgressTaskUI: public CATBaseUnknown {

  CATDeclareInterface;

public:

	/**
    * Sets minimal and maximal range of the progress bar.
    * <br><b>Role:</b>This method sets the bounds of the progress bar. If the maximum value 
    * is lower than the minimum value, the dialog box is not displayed. 
    * @param iMinValue
    * The lower bound of the interval displayed by the progress bar. The default value
    * is 0.
    * @param iMaxValue
    * The upper bound of the interval displayed by the progress bar. The default
    * value is 100.
    * 
    * @return 
    * S_OK in all cases
    */
  virtual HRESULT SetRange       (long iMinValue, long iMaxValue) = 0;

  /**
    * Sets the current progress indicator's value.
    * <br><b>Role</b>:This value is used to define:
    *  <ul>
    *  <li>The current value of the progress control. </li>
    *  <li>The percentage of process executed:</li>
    *  <p><tt> p = (iValue-min)/(max-min)</tt></p>
    *   <p>where "min" and "max" define the range set by the @href #SetRange method</p>
    *  <li>The estimated remaining time:</li>
    *  <p><tt> t= EllapsedTimeAlreadyPassed * (1-p)/p </tt></p>
    * </ul>
    * @param iValue
    * The range of the value must be between the minimum and maximum bounds. if iValue is greated
    * than the maximum value, the step progression is the maximum value. If the ivalue is less 
    * than the minimum value, the step progression is the minimum value.
    * @return 
    * S_OK in all cases 
    */
  virtual HRESULT SetProgress    (long iValue) = 0;

  /**
    * Tells whether a task interruption is requested.
    * @param oInterrupted
    *  TRUE if the task has been interrupted, otherwise FALSE. If the task is
    * not interruptible, see the second argument of the
    * @href CATTaskController#Schedule method, the value returned is FALSE.
    */
  virtual HRESULT IsInterrupted  (CATBoolean * oInterrupted) = 0;

  /**
    * Sets a runtime comment.
    * <br><b>Role:</b>The default comment is the one set in the NLS file
    * defined by @href CATIProgressTask#GetCatalogName. The keyword associated 
    * with this message is <tt>CATIProgressTask.Comment</tt>. With this method, you can 
    * customize the comment at the beginning of a task or during a step. See the
    * @href CATIProgressTask#PerformTask method.
    */
  virtual HRESULT SetComment     (const CATUnicodeString & iComment) = 0;

  /**
    * Sets a runtime object name concerned by the task.
    * <br><b>Role:</b>The default object name is the one set in the NLS file defined by
    * @href CATIProgressTask#GetCatalogName. The keyword associated with this message is
    * <tt>CATIProgressTask.ObjectName</tt>. With this method, you can customize an object name
    * at the beginning of a task, or during a step; See the
    * @href CATIProgressTask#PerformTask method.
    */
  virtual HRESULT SetObject      (const CATUnicodeString & iObject) = 0;

   /**
    * Indicates to the user interface to manage automatically the flush.   
    * @param iAutoFlush 
    * <ul>
    *   <li>FALSE : Indicates to the user interface to stop managing automatically 
    *      the flushing.</li>
    *   <li>TRUE : The flushing is automatically called after each
    *      @href #SetProgress call (default behaviour).</li>
    * </ul>
    * @see #Flush
    */
  virtual HRESULT SetAutoFlush   (CATBoolean   iAutoFlush) = 0;

   /**
    * Gets the auto flush state.
    * @param oAutoFlush
    * The state of the auto flush.
	*/
  virtual HRESULT GetAutoFlush   (CATBoolean * oAutoFlush) = 0;
	
   /**
	* Commits the UI's modifications.
    * <br><b>Role</b>: Modifies the user interface to take account of the range,
    * progress, comment and object; See 
    * the <tt>SetRange</tt>, <tt>SetProgress</tt>, 
    * <tt>SetComment</tt> and <tt>SetObject</tt> methods.
    * <br>This method must be called with care, since it may be costly in 
	* performance.
	*/
	virtual HRESULT Flush         () = 0;

   /**
	* Sets the interruptible state of the progress bar.
    * <br><b>Role</b>: Modifies the interruptible state of the progress bar.
    * The progress bar has to be defined as interruptible in CATTaskController::Schedule.
    * At any step, this method changes the interruptible state
    * by disabling/enabling the Cancel button of the progress bar dialog box.
    * @param iInter
    * The interruptible state : TRUE to set the state to "interruptible", FALSE to set the state to "not interruptible".
    */
    virtual HRESULT Interruptible (CATBoolean iInter) = 0;

};

CATDeclareHandler (CATIProgressTaskUI, CATBaseUnknown);

#endif//__CATIProgressTaskUI_h
