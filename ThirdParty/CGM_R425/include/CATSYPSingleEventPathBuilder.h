#ifndef CATSYPSingleEventPathBuilder_H
#define CATSYPSingleEventPathBuilder_H

#include <UIVCoreTools.h>
#include <CATSYPSupportsEventPathBuilder.h>

class CATSYPEventHandlersSupport;
class CATSYPClassEventHandlersSupport;

/** @ingroup groupSypEventDispatching
 * Path builder for a tree of nodes that always contain a single node
 * using @ref CATSYPEventHandlersSupport to store the handlers on its
 * node and @ref CATSYPClassEventHandlersSupport to associate static
 * handlers to classes.
 *
 * This path builder can consequently be used for all components that
 * are not part of a tree but still want to use dispatching events.
 * 
 * @par Specialization
 * This component must not be specialized but instantiated on stack.
 *
 * @see CATSYPSupportsEventPathBuilder
 */
class ExportedByUIVCoreTools CATSYPSingleEventPathBuilder : public CATSYPSupportsEventPathBuilder
{
public:
  /** 
   * Initialize this class.
   *
   * @param i_pEventHandlersSupport the support of event
   * handlers. Can't be @c NULL.
   *
   * @param i_pClassEventHandlerSupport the support of event handlers
   * registered on classes. Can be NULL since this is optional.
   */
  CATSYPSingleEventPathBuilder(CATSYPEventHandlersSupport *i_pEventHandlersSupport,
                               CATSYPClassEventHandlersSupport *i_pClassEventHandlerSupport);

  /** Destroy this class */
  virtual ~CATSYPSingleEventPathBuilder();

protected:
  /** @copydoc CATSYPSupportsEventPathBuilder#GetSupportForNode */
  virtual CATSYPEventHandlersSupport *GetSupportForNode(CATBaseUnknown *i_pNode);

  /** @copydoc CATSYPSupportsEventPathBuilder#GetClassSupportForNode */
  virtual CATSYPClassEventHandlersSupport *GetClassSupportForNode(CATBaseUnknown *i_pNode);
  
  /** @copydoc CATSYPEventPathBuilder#GetParent */
  virtual CATBaseUnknown *GetParent(CATSYPEventArgs *i_pArgs, CATBaseUnknown *i_pNode);

private:
  CATSYPSingleEventPathBuilder(const CATSYPSingleEventPathBuilder &);
  CATSYPSingleEventPathBuilder &operator=(const CATSYPSingleEventPathBuilder &);
private:
  /** the support of event handlers */
  CATSYPEventHandlersSupport *_pEventHandlersSupport;
  /** the support of event handlers registered on classes; can be @c NULL */
  CATSYPClassEventHandlersSupport *_pClassEventHandlerSupport;
};

#endif // CATSYPSingleEventPathBuilder_H
