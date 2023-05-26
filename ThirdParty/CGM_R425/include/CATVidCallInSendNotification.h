#ifndef CATVidCallInSendNotification_H
#define CATVidCallInSendNotification_H

#include <VisuDialog.h>

#include <CATCommand.h>

/** @ingroup VIDCore
 * A class that call an action in a callback of a @c
 * CATCommand::SendNotification.
 *
 * It can be used with two different ways:
 *   - synchronously: in that case this class must only be used outside
 *     any @c SendNotification.
 *   - asynchronously: in that case it can be used either inside of 
 *     outside a @c SendNotification.
 *
 * It should never be instantiated, instead the static functions @ref
 * #Call and @ref #DelayedCall should be used.
 *
 * Action must implement the @ref #Action interface.
 */
class ExportedByVisuDialog CATVidCallInSendNotification : public CATCommand
{
  CATDeclareClass;
public:
  /**
   * The interface that actions should implement.
   *
   * It contains only one method to implement, the @ref #Run method.
   */
  class ExportedByVisuDialog Action {
  public:
    /** empty constructor */
    Action();
    
    /** empty destructor */
    virtual ~Action();

    /**
     * Call the action.
     */
    virtual void Call() = 0;
  private:
    Action(const Action&);
    Action &operator=(const Action&);
  };

  /**
   * Synchronous call @c i_action in a callback of @c
   * SendNotification.
   *
   * This function must be called outside any @c SendNotification;
   * else it will fail. It must also be called outside a callback of
   * @c EndTransaction.
   *
   * The action will be called synchronously by this function, as a
   * consequence the caller can assume that as soon as this function
   * returns its action will have been executed. Moreover the lifecyle
   * of the action can be handled by simply creating the action on the
   * stack since no reference on the action will be kept by this
   * function.
   *
   * @param i_action the action.
   *
   * @return @c 0 if failed (for example if called inside a @c
   * SendNotification or if inputs are invalid), else it returns the
   * return @c !=0.
   */
  static int Call(Action &i_action);

  /**
   * Call @c i_action in a callback of @c SendNotification.
   *
   * This function may be called inside a @c SendNotification.
   *
   * The action will be called either synchronously if there is no
   * SendNotification in the stack yet, or asynchronously if there is
   * a SendNotification in the call stack) by this function. As a
   * consequence the caller can't assume that as soon as this function
   * returns its action will have been executed.
   *
   * The lifecyle of the action is handled by this class that will
   * destroy it after having called it using @c delete operator.
   *
   * @param i_pAction the action to execute. Can't be @c NULL. Will be
   * deleted by this class.
   */
  static void DelayedCall(Action *i_pAction);

  /**
   * Check if the caller is outside any @c SendNotification.
   *
   * @return @c !=0 when outside any @c SendNotification.
   */
  static int CanSynchronousCall();
private:
  /** 
   * Initialize this class 
   *
   * @param i_pAction the action. Can't be @c NULL.
   *
   * @param i_synchronous @c !=0 if the call is synchronous (in that
   * case @a i_pAction will not be deleted by this class).
   */
  CATVidCallInSendNotification(Action *i_pAction, int i_synchronous);

  /** Destroy this class */
  virtual ~CATVidCallInSendNotification();

public:
  /** @copydoc CATCommand#AnalyseNotification */
  virtual CATNotifPropagationMode AnalyseNotification(CATCommand * i_pFromClient,
                                                      CATNotification * i_pNotification);
private:
  CATVidCallInSendNotification(const CATVidCallInSendNotification &);
  CATVidCallInSendNotification &operator=(const CATVidCallInSendNotification &);
private:
  /** the action to execute */
  Action *_pAction;

  /** synchronicity */
  const int _synchronous;

  /** set to @c !=0 in @ref #AnalyseNotification */
  int _analysedNotificationCalled;
};

#endif // CATVidCallInSendNotification_H
