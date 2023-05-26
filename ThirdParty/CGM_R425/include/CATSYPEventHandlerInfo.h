#ifndef CATSYPEventHandlerInfo_H
#define CATSYPEventHandlerInfo_H

#include <UIVCoreTools.h>

#include <CATBaseUnknown.h>

class CATSYPEventHandler;

/** @ingroup groupSypEventRegistration
 * Immutable class used to reference a @ref CATSYPEventHandler in the
 * event handlers registration infrastructure.
 *
 * It points a @ref CATSYPEventHandler and also store registration
 * specific informations. As of today, the only added information is a
 * flag indicating if the handler should be called for consumed
 * events.
 *
 * @par Immutability
 * This class is immutable, i.e. its internal state will not change
 * after it has been built. This enables the dispatching
 * infrastructure to share references to this class without having to
 * make any copy.
 */
class ExportedByUIVCoreTools CATSYPEventHandlerInfo : public CATBaseUnknown
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class 
   *
   * @param i_pHandler the handler to point. Can't be @c NULL. 
   * @c AddRef will be called on this pointer.
   *
   * @param i_handleConsumedEvents @c !=0 if the handler should be
   * called for consumed events.
   */
  CATSYPEventHandlerInfo(CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents);
  /** Destory this class */
  virtual ~CATSYPEventHandlerInfo();
  /**
   * Get the handler pointed by this object.
   *
   * @return the handler. Note that @c AddRef has NOT been called on
   * the returned value; as a consequence the caller must NOT 
   * @c Release this value.
   */
  CATSYPEventHandler *GetHandler() const;
  /**
   * Get the flag indicating if the handler should be called for
   * consumed events.
   *
   * @return @c !=0 if the handler should be called for consumed
   * events.
   */
  int GetHandleConsumedEvents() const;
private:
  CATSYPEventHandlerInfo(const CATSYPEventHandlerInfo &);
  CATSYPEventHandlerInfo &operator=(const CATSYPEventHandlerInfo &);
private:
  /** the handler; @c AddRef has been called on the pointer */
  CATSYPEventHandler * _pHandler;
  /** @c !=0 if the handler should be called for consumed events */
  int _handleConsumedEvents;
};

#endif // CATSYPEventHandlerInfo_H
