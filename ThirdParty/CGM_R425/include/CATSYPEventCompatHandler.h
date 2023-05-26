#ifndef CATSYPEventCompatHandler_H
#define CATSYPEventCompatHandler_H

#include <UIVCoreTools.h>

#include <CATSYPEventHandler.h>
#include <CATBaseUnknown_WR.h>
#include <CATSYPEventArgs.h>
#include <CATBaseUnknown_var.h>
#include <CATSYPCheck.h>
#include <CATUnicodeString.h>
#include <CATSYPEvent.h>
#include <CATSysMacros.h>

/** @ingroup groupSypEventEvent
 * An event handler that can call a regular (or static member)
 * function that will itself call a member function of an
 * introspectable class that has not yet updated its
 * <tt>.sypintro</tt> and still use the old signature for event
 * handlers.
 *
 * After the introduction of @ref CATSYPEvent, introspectable objects
 * that want to expose event handlers have to provide a member
 * function that takes a @ref CATBaseUnknown and a @ref
 * CATSYPEventArgs.
 * 
 * Until all classes have migrated on the new event architecture, we
 * still need to support old event handler definitions that use the
 * event name.
 *
 * As a consequence we need this handler to be able to call this old
 * handlers.
 *
 * We don't use a member function pointer but instead use a regular
 * function whose code will be generated. This ensures that even if
 * the handler signature was not exactly the expected one it will
 * still compile.
 * 
 * This handler will point the object of class @a ClassType with a
 * weak-reference. It will support @ref #ShouldAutoRemove mechanism by
 * returning @c true when this weak-reference is invalid.<br/>
 * The function @ref #GetArgsType returns @ref CATSYPEventArgs.<br/>
 * The function @ref #Call will only call the regular function when @c
 * i_pSender is the same object as @c i_pArgs->GetOrigin(). This
 * ensures that when using an old event handler with an event that has
 * been migrated and that is now propagating only handlers registered
 * on the origin will be called.<br/>
 * Old event handlers are based on event names (the new system is
 * based on CATSYPEvent identity). As a consequence we use @ref
 * CATSYPEvent#GetName as an event name. Note that this is dangerous
 * and may fail if the event has not the expected name.
 *
 * @tparam ClassType the class that contains the old handler function
 * to call.
 */
template <class ClassType>
class CATSYPEventCompatHandler : public CATSYPEventHandler
{
public:
  /** 
   * Initialize this class
   *
   * @param i_pObj the instance of @c ClassType to reference. Only a
   * weak-reference will be kept on this object. As a consequence,
   * i_pObj must be an Object Modeler @c Implementation (note that if
   * you inherit from @ref CATBaseUnknown without using
   * CATDeclareClass & CATImplementClass, then you can't build a
   * weak-reference). It will be checked in this constructor by check
   * that @c i_pObj->GetImpl()==i_pObj. Can't be @c NULL.
   *
   * @param i_pFunc the regular function that is expected to call the
   * object event handler. The first argument will be a pointer on the
   * object.
   */
  CATSYPEventCompatHandler(ClassType *i_pObj,
                           void (*i_pFunc)(ClassType *, 
                                           const CATUnicodeString &,
                                           const CATBaseUnknown_var &,
                                           const CATBaseUnknown_var &))
    : _pFunc(i_pFunc) {
    CHECK_POINTER_RET(i_pObj);
    CHECK_TRUE_RET_MSG(i_pObj->GetImpl() == i_pObj, 
                       "i_pObj may be an extension; referencing an extension with a weak-ref is not possible.");
    _wrObj = i_pObj;
    CHECK_TRUE(_pFunc != NULL); // _pFunc is a function pointer so we
                                // can't use CHECK_POINTER
  }

  /** @copydoc CATSYPEventHandler#Call */
  virtual void Call(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs) {
    CHECK_POINTER_RET(i_pSender);
    CHECK_POINTER_RET(i_pArgs);
    CHECK_TRUE_RET(_pFunc != NULL); // _pFunc is a function pointer,
                                    // we can't use CHECK_POINTER_RET

    // get an hard reference on the object
    CATBaseUnknown_var spObj = _wrObj;
    if (spObj == NULL_var)
      return;

    // cast it to the class type
    ClassType * const pObj = CAT_DYNAMIC_CAST(ClassType, spObj);
    CHECK_POINTER_RET(pObj);

    // check that the origin of the event is the sender; we only call
    // old handlers in that case
    if (! i_pSender->IsEqual(i_pArgs->GetOrigin()))
      return;

    // get the event for its event name
    CATSYPEvent * const pEvent = i_pArgs->GetEvent();
    CHECK_POINTER_RET(pEvent);

    // call the regular function
    _pFunc(pObj, pEvent->GetName(), i_pSender, NULL_var);
  }

  /** @copydoc CATSYPEventHandler#GetArgsType */
  virtual CATMetaClass *GetArgsType() {
    return CATSYPEventArgs::MetaObject();
  }

  /** @copydoc CATSYPEventHandler#ShouldAutoRemove */
  virtual int ShouldAutoRemove() {
    // get an hard reference on the object
    CATBaseUnknown_var spObj = _wrObj;

    // check if there is still an object
    return spObj == NULL_var;
  }

private:
  CATSYPEventCompatHandler(const CATSYPEventCompatHandler &);
  CATSYPEventCompatHandler &operator=(const CATSYPEventCompatHandler &);

private:
  /** the component to call */
  CATBaseUnknown_WR _wrObj;
  
  /** the regular function to use to call the member function of @c ClassType */
  void (*_pFunc)(ClassType *, 
                 const CATUnicodeString &,
                 const CATBaseUnknown_var &,
                 const CATBaseUnknown_var &);
};

#endif // CATSYPEventCompatHandler_H
