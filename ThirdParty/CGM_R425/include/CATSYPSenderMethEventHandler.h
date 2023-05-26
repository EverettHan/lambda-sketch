#ifndef CATSYPSenderMethEventHandler_H
#define CATSYPSenderMethEventHandler_H

#include <CATSYPAbstractMethEventHandler.h>
#include <CATSYPCheck.h>
#include <CATSysMacros.h>

class CATSYPEvent;

/** @ingroup groupSypEventHandlers
 * This template implements @ref CATSYPEventHandler for calling a
 * member function of the sender on which this handler has been registered.
 *
 * The sender must be an instance of class @c ClassType that accepts a
 * given type of argument @c ArgsType.
 *
 * It implements @ref #Call by casting the arguments to @c ArgsType
 * and casting the sender to @c ClassType.  Then it calls the member
 * function identified by the pointer given to the constructor of this
 * class. Note that if this handler is called with the wrong type of
 * arguments or if it has been registered on a component that is not a
 * child component of @c ClassType, then it will raise a @ref FAILURE.
 *
 * @note
 * This handler is typically used to add as a class handler (see @ref
 * CATSYPClassEventHandlersSupport) that calls a non-static member
 * function of the class.
 *
 * @tparam ClassType the class that contains the function to call and
 * that must also be the parent class of the class of the sender
 * (i.e. the object to which this handler is registered).
 *
 * @tparam ArgsType the type of @ref CATSYPEventArgs that are handled
 * by this handler.
 */
template <class ClassType, class ArgsType>
class CATSYPSenderMethEventHandler : public CATSYPAbstractMethEventHandler<ClassType, ArgsType>
{
public:
  /** 
   * Initialize this class.
   *
   * @param i_pMemberFunc the member function to call. Can't be @c NULL.
   */
  CATSYPSenderMethEventHandler(void (ClassType::*i_pMemberFunc)(CATBaseUnknown *, ArgsType *))
    : CATSYPAbstractMethEventHandler<ClassType, ArgsType>(i_pMemberFunc) {
  }
  /** @copydoc CATSYPEventHandler#ShouldAutoRemove */
  virtual int ShouldAutoRemove() {
    return 0;
  }
protected:
  /** @copydoc CATSYPAbstractMethEventHandler#GetObject */
  virtual ClassType *GetObject(CATBaseUnknown *i_pSender) {
    CHECK_POINTER_RETV(i_pSender, NULL);

    // cast the sender to the class type
    ClassType * const pObj = CAT_DYNAMIC_CAST(ClassType, i_pSender);
    CHECK_POINTER_RETV_MSG(pObj, NULL, "The sender is not of the expected type");

    // call AddRef before returning the pointer
    pObj->AddRef();
    return pObj;
  }
private:
  CATSYPSenderMethEventHandler(const CATSYPSenderMethEventHandler &);
  CATSYPSenderMethEventHandler &operator=(const CATSYPSenderMethEventHandler &);
};

/** @ingroup groupSypEventHandlers
 * Add a member function of a component as handler for a given event,
 * the component class and a given register function.
 *
 * This function is a shortcut to instantiating a @ref
 * CATSYPSenderMethEventHandler and registering it using @a
 * i_pAddClassHandlerFunc.
 *
 * Note that if you want to be able to remove this handler before
 * the death of this component, you should instantiate the handler
 * yourself to be able to `RemoveClassHandler' function.
 *
 * @par Example
 * @code
 * class CATVidTstEventsIntegration_WidgetSelf : public CATVidCtl
 * {
 *   CATDeclareClass;
 * public:
 *   CATVidTstEventsIntegration_WidgetSelf();
 * private:
 *   void MyEvtCallback(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs) {
 *     ...
 *   }
 *   static void staticConstructor() {
 *     CHECK_TRUE(AddSCATSYPSenderMethEventHandler(&CATVidWidget::AddClassHandler,
 *                                                 CATVidTstEventsIntegration_WidgetA::MyEvt(),
 *                                                 &CATVidTstEventsIntegration_WidgetSelf::MyEvtCallback));
 *   }
 * };
 * 
 * CATImplementClass(CATVidTstEventsIntegration_WidgetSelf, Implementation, CATVidCtl, CATNull);
 *
 * STATIC_CONSTRUCTOR_DEF(CATVidTstEventsIntegration_WidgetSelf, staticConstructor);
 *
 * CATVidTstEventsIntegration_WidgetSelf::CATVidTstEventsIntegration_WidgetSelf() {
 *   STATIC_CONSTRUCTOR(CATVidTstEventsIntegration_WidgetSelf, staticConstructor);
 * }
 * @endcode
 *
 * @note
 * Due to the deduction of function template arguments there is
 * generally no need to declare explicitely template arguments when
 * using this function.
 *
 * @tparam ClassType the type of the widget class that contains the
 * member function to call and also the class to register for the
 * event; it must be a sub-class of CATBaseUnknown.
 *
 * @tparam ArgsType the type of arguments (@ref CATSYPEventArgs)
 * accepted by @a i_pFunc function. It must be compatible with the
 * type of arguments of @a i_pEvent (i.e. it must be a super-class
 * of the class of arguments returned by @ref
 * CATSYPEvent#GetArgumentType).
 *
 * @param i_pAddClassHandlerFunc the function to call to register the
 * class handler. Can't be @c NULL.
 *
 * @param i_pEvent the event that we are interested in. Note that @c
 * AddRef will be called on the event. Can't be @c NULL.
 *
 * @param i_pMemberFunc the member function to call. Can't be @c NULL.
 *
 * @param i_handleConsumedEvents @c !=0 if the handler should be
 * called for consumed events.
 *
 * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
 * invalid input or internal error (in that case a @ref FAILURE has
 * been raised).
 *
 * @see CATSYPSenderMethEventHandler
 */
template <class ClassType, class ArgsType>
int AddSCATSYPSenderMethEventHandler(int (*i_pAddClassHandlerFunc)(CATMetaClass *, CATSYPEvent *, CATSYPEventHandler *, int),
                                     CATSYPEvent *i_pEvent, 
                                     void (ClassType::*i_pMemberFunc)(CATBaseUnknown *, ArgsType *),
                                     int i_handleConsumedEvents = 0) {
  CHECK_TRUE_RETV(i_pAddClassHandlerFunc != NULL, 0); // i_pAddClassHandlerFunc is a function pointer, we can't use CHECK_POINTER_RETV
  CHECK_POINTER_RETV(i_pEvent, 0);
  CHECK_TRUE_RETV(i_pMemberFunc != NULL, 0); // i_pMemberFunc is a function pointer, we can't use CHECK_POINTER_RETV
  CATSYPEventHandler * const pHandler = new CATSYPSenderMethEventHandler<ClassType, ArgsType>(i_pMemberFunc);
  const int rc = i_pAddClassHandlerFunc(ClassType::MetaObject(), i_pEvent, pHandler, i_handleConsumedEvents);
  pHandler->Release();
  return rc;
}

#endif // CATSYPSenderMethEventHandler_H
