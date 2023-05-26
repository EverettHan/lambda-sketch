#ifndef CATSYPMainLoop_H
#define CATSYPMainLoop_H


#include <UIVCoreTools.h>
class CATSYPRunnable;

// friendship protection
#undef CATSYPTstMainLoop
#undef CATSYPMainLoopMQ
#undef private

/** @ingroup groupUIVCoreToolsThreading
 * Classes provided services for interaction of threads with the main
 * event loop of interactive applications.
 *
 * @par Runnable Invocation
 * The static function @ref #InvokeLater can be used by any thread to
 * execute an action on the main thread. Note that it can also be used
 * in the main thread itself to defer the execution of an action to a
 * next iteration of the main thread's events loop.
 *
 * @par
 * When this function is called, an event is appended in the main
 * thread's events queue. When this event is poped from the queue by
 * the main thread events loop the action is executed in the main
 * thread.
 *
 * @par
 * Note that if this function is used in a non interactive application
 * then the actions will never be executed (they will leak since they
 * won't be released).
 *
 * @par
 * There is no guarantee that actions will ever get executed before
 * the end of the application since there is no way to know that the
 * main event loop will have the occasion to execute after the call to
 * @ref #InvokeLater. For example actions put in the queue during the
 * end of the application will never get executed (or even released).
 *
 * @par
 * If a local event loop is executed in the main-thread (for example
 * when a modal dialog is displayed, e.g. @ref
 * CATDlgNotify#DisplayBlocked) then the pending actions may be
 * executed by this local events loop. As a consequence, when using
 * @ref #InvokeLater from the main-thread itself to defer an action,
 * you may not rely on the assumption that your action won't be
 * executed before you returned the control flow to your caller. For
 * example:
 * @code
 * {
 *   ...
 *   // defer execution of MyAction
 *   CATSYPMainLoop::InvokeLater(new MyAction(), 1);
 *   
 *   // display a modal dialog
 *   CATDlgNotify * const pNotif = new CATDlgNotify(...);
 *   pNotif->DisplayBlocked(...);
 * 
 *   // when we reach this point MyAction may have been executed 
 *   // during the local events loop triggered 
 *   // by CATDlgNotify::DisplayBlocked
 * @endcode
 *
 * @par
 * To support unit testing it is possible in tests to execute pending
 * actions by an explicit call to @ref
 * CATSYPTstMainLoop#ExecutePendingActions. This function is only
 * avaiable for tests, not for production code.
 */
class ExportedByUIVCoreTools CATSYPMainLoop
{
  friend class CATSYPTstMainLoop;
  friend class CATSYPMainLoopCallback;
public:
  /**
   * Put an event is main thread's event queue that will execute @a
   * i_pRunnable when the main thread's events loop will pop this
   * event.
   *
   * Please see class documentation for details and limitations.
   *
   * @par Usage
   * @code
   * CATThreadsReturnCode MyThreadFunction(void*) {
   *   ...
   *   const int result = ...;
   *
   *   class UpdateUI : public CATSYPRunnable {
   *     int result;
   *   public:
   *     UpdateUI(int result) : result(result) {}
   *     virtual void Run() {
   *       // here we are call in main thread so we can 
   *       // update user-interface with result
   *       ...
   *     }
   *   };
   *   
   *   // update the user interface with the result
   *   CATSYPMainLoop::InvokeLater(new UpdateUI(result), 1);
   * }
   * @endcode
   *
   * @param i_pRunnable the action; can't be @c NULL. The reference
   * count of the action will be incremented.
   *
   * @param i_release call @ref CATSYPRunnable#Release on @a
   * i_pRunnable when @c !=0. This argument can be used to tell to
   * this function that it should steal the reference to @a
   * i_pRunnable instead of incrementing the reference count.
   */
  static void InvokeLater(CATSYPRunnable *i_pRunnable, int i_release);
private:
  /**
   * Execute the pending action added by @ref #InvokeLater.
   *
   * This function should only be called from the main thread.
   */
  static void ExecutePendingActions();
private:
  CATSYPMainLoop();
  ~CATSYPMainLoop();
  CATSYPMainLoop(const CATSYPMainLoop &);
  CATSYPMainLoop &operator=(const CATSYPMainLoop &);
};


#endif // CATSYPMainLoop_H
