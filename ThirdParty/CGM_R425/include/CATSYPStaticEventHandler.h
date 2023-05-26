#ifndef CATSYPStaticEventHandler_H
#define CATSYPStaticEventHandler_H

#include <UIVCoreTools.h>

#include <CATSYPTypedArgEventHandler.h>
#include <CATSYPCheck.h>

class CATSYPEvent;

/** @ingroup groupSypEventHandlers
 * An event handler that calls a static member function or a regular
 * function.
 *
 * The implementation of @ref #ShouldAutoRemove always returns @c 0
 * since static functions are always valid.
 *
 * @tparam ArgsType the type of @ref CATSYPEventArgs that are handled
 * by this handler.
 */
template <class ArgsType>
class CATSYPStaticEventHandler : public CATSYPTypedArgEventHandler<ArgsType>
{
public:
  /** 
   * Initialize this class 
   *
   * @param i_pFunc the static member function or regular function to
   * call when this handler is called.
   */
  CATSYPStaticEventHandler(void (*i_pFunc)(CATBaseUnknown *, ArgsType *))
    : _pFunc(i_pFunc) {
    CHECK_TRUE(_pFunc != NULL); // _pFunc is a function pointer so we
                                // can't use CHECK_POINTER
  }

  /** @copydoc CATSYPEventHandler#ShouldAutoRemove */
  virtual int ShouldAutoRemove() {
    return 0;
  }

protected:
  /** @copydoc CATSYPTypedArgEventHandler#TypedCall */
  virtual void TypedCall(CATBaseUnknown *i_pSender, ArgsType *i_pArgs) {
    CHECK_TRUE_RET(_pFunc != NULL); // _pFunc is a function pointer so
                                    // we can't use CHECK_POINTER
    _pFunc(i_pSender, i_pArgs);
  }

private:
  CATSYPStaticEventHandler(const CATSYPStaticEventHandler &);
  CATSYPStaticEventHandler &operator=(const CATSYPStaticEventHandler &);
private:
  /** the static member/regular function */
  void (*_pFunc)(CATBaseUnknown *, ArgsType *);
};

/** @ingroup groupSypEventHandlers
 * Add a static function as handler for a given event on a given
 * support.
 *
 * This function is a shortcut to instantiating a @ref
 * CATSYPStaticEventHandler and registering it using @a
 * i_pAddHandlerFunc member function of @a i_pSupport.
 *
 * Note that if you want to be able to remove this handler before the
 * death of this component, you should instantiate the handler
 * yourself to be able to use the `RemoveHandler' function of the
 * support.
 *
 * @par Example
 * @code
 * static void Callback__(CATBaseUnknown *i_pSender, MyEventArgs *i_pArgs)
 * {
 *   ...
 * }
 *
 * void MyClass::Init()
 * {
 *   ...
 *   MyWidget * const pWidget = ...;
 *   // note: MyWidget::Evt event uses arguments of type MyEventArgs
 *   CHECK_TRUE(AddCATSYPStaticEventHandler(static_cast<Widget>(pWidget), 
 *                                          &Widget::AddHandler,
 *                                          MyWidget::Evt(), &Callback__));
 *   ...
 * }
 * @endcode
 *
 * @par Template Parameters Deduction
 * Due to the deduction of function template arguments there is
 * generally no need to declare explicitely template arguments when
 * using this function.<br/>
 * A know issue is when using member functions that are inherited by
 * the class (see example above with the support pointer). To solve
 * this issue you may use a @c static_cast to cast @c i_pSupport to
 * the parent class that defines @a i_pAddHandlerFunc.
 *
 * @note
 * You should use the other signature of this function if the member
 * function of the support used to add handlers is called @c
 * AddHandler. Using this other signature would also solve the issue
 * with template parameter deduction if the @c AddHandler function is
 * inherited from a parent class.
 *
 * @tparam SupportClassType the type of the support class that
 * contains @a i_pAddHandlerFunc member function.
 *
 * @tparam ArgsType the type of arguments (@ref CATSYPEventArgs)
 * accepted by @a i_pFunc function. It must be compatible with the
 * type of arguments of @a i_pEvent (i.e. it must be a super-class
 * of the class of arguments returned by @ref
 * CATSYPEvent#GetArgumentType).
 *
 * @param i_pSupport the support of event handlers. Can't be @c NULL.
 *
 * @param i_pAddHandlerFunc the member function of @a i_pSupport to
 * use to add handlers. Can't be @c NULL.
 *
 * @param i_pEvent the event that we are interested in. Note that @c
 * AddRef will be called on the event. Can't be @c NULL.
 *
 * @param i_pFunc the static member function or regular function to
 * call when this handler is called.
 * 
 * @param i_handleConsumedEvents @c !=0 if the handler should be
 * called for consumed events.
 *
 * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
 * invalid input or internal error (in that case a @ref FAILURE has
 * been raised).
 */
template <class SupportClassType, class ArgsType>
int AddCATSYPStaticEventHandler(SupportClassType *i_pSupport,
                                int (SupportClassType::*i_pAddHandlerFunc)(CATSYPEvent *, CATSYPEventHandler *, int),
                                CATSYPEvent *i_pEvent, 
                                void (*i_pFunc)(CATBaseUnknown *, ArgsType *), 
                                int i_handleConsumedEvents = 0) {
  CHECK_POINTER_RETV(i_pSupport, 0);
  CHECK_TRUE_RETV(i_pAddHandlerFunc != NULL, 0); // i_pAddHandlerFunc is a function pointer, we can't use CHECK_POINTER_RETV
  CHECK_POINTER_RETV(i_pEvent, NULL);
  CHECK_TRUE_RETV(i_pFunc != NULL, 0); // i_pFunc is a function pointer, we can't use CHECK_POINTER_RETV
  CATSYPEventHandler * const pHandler = new CATSYPStaticEventHandler<ArgsType>(i_pFunc);
  const int rc = (i_pSupport->*i_pAddHandlerFunc)(i_pEvent, pHandler, i_handleConsumedEvents);
  pHandler->Release();
  return rc;
}

/** @ingroup groupSypEventHandlers
 * Shortcut to call the other signature of
 * @c AddCATSYPStaticEventHandler using @c
 * &SupportClassType::AddHandler for @c i_pAddHandlerFunc parameter.
 *
 * You should use this signature if the support function to add
 * handlers is named @c AddHandler.
 *
 * @par Example
 * @code
 * static void Callback__(CATBaseUnknown *i_pSender, MyEventArgs *i_pArgs)
 * {
 *   ...
 * }
 *
 * void MyClass::Init()
 * {
 *   ...
 *   MyWidget * const pWidget = ...;
 *   // note: MyWidget::Evt event uses arguments of type MyEventArgs
 *   CHECK_TRUE(AddCATSYPStaticEventHandler(pWidget, MyWidget::Evt(), &Callback__));
 *   ...
 * }
 * @endcode
 */
template <class SupportClassType, class ArgsType>
int AddCATSYPStaticEventHandler(SupportClassType *i_pSupport,
                                CATSYPEvent *i_pEvent, 
                                void (*i_pFunc)(CATBaseUnknown *, ArgsType *), 
                                int i_handleConsumedEvents = 0) {
  CHECK_POINTER_RETV(i_pSupport, 0);
  CHECK_POINTER_RETV(i_pEvent, NULL);
  CHECK_TRUE_RETV(i_pFunc != NULL, 0); // i_pFunc is a function pointer, we can't use CHECK_POINTER_RETV
  CATSYPEventHandler * const pHandler = new CATSYPStaticEventHandler<ArgsType>(i_pFunc);
  const int rc = i_pSupport->AddHandler(i_pEvent, pHandler, i_handleConsumedEvents);
  pHandler->Release();
  return rc;
}


/** @ingroup groupSypEventHandlers
 * Add a static function as handler for a given event, a given
 * class and a given register function.
 *
 * This function is a shortcut to instantiating a @ref
 * CATSYPStaticEventHandler and registering it using @a
 * i_pAddClassHandlerFunc.
 *
 * Note that if you want to be able to remove this handler before
 * the death of this component, you should instantiate the handler
 * yourself to be able to use `RemoveClassHandler' function.
 *
 * @note
 * Due to the deduction of function template arguments there is
 * generally no need to declare explicitely template arguments when
 * using this function.
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
 * @param i_pClass the class. Can't be @c NULL.
 *
 * @param i_pEvent the event that we are interested in. Note that @c
 * AddRef will be called on the event. Can't be @c NULL.
 *
 * @param i_pFunc the static member function or regular function to
 * call when this handler is called.
 * 
 * @param i_handleConsumedEvents @c !=0 if the handler should be
 * called for consumed events.
 *
 * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
 * invalid input or internal error (in that case a @ref FAILURE has
 * been raised).
 *
 * @see CATSYPStaticEventHandler
 */
template <class ArgsType>
int AddSCATSYPStaticEventHandler(int (*i_pAddClassHandlerFunc)(CATMetaClass *, CATSYPEvent *, CATSYPEventHandler *, int),
                                 CATMetaClass *i_pClass,
                                 CATSYPEvent *i_pEvent, 
                                 void (*i_pFunc)(CATBaseUnknown *, ArgsType *), 
                                 int i_handleConsumedEvents = 0) {
  CHECK_TRUE_RETV(i_pAddClassHandlerFunc != NULL, 0); // i_pAddClassHandlerFunc is a function pointer, we can't use CHECK_POINTER_RETV
  CHECK_POINTER_RETV(i_pClass, 0);
  CHECK_POINTER_RETV(i_pEvent, 0);
  CHECK_TRUE_RETV(i_pFunc != NULL, 0); // i_pFunc is a function pointer, we can't use CHECK_POINTER_RETV
  CATSYPEventHandler * const pHandler = new CATSYPStaticEventHandler<ArgsType>(i_pFunc);
  const int rc = i_pAddClassHandlerFunc(i_pClass, i_pEvent, pHandler, i_handleConsumedEvents);
  pHandler->Release();
  return rc;
}

#endif // CATSYPStaticEventHandler_H
