#ifndef CATSYPRunnable_H
#define CATSYPRunnable_H


#include <UIVCoreTools.h>
#include <CATSYPRefCounted.h>

/** @ingroup groupUIVCoreToolsThreading
 * Base interface that represents an action that can be executed.
 *
 * Instances of children classes of this class must be instantiated on
 * heap and are shared between several objects using explicit
 * reference counting provided by @ref #AddRef and @ref #Release
 * member functions. This reference counting is thread safe and the
 * object is destroyed when the reference count reaches @c 0.
 *
 * The action is implemented in the @ref #Run method.
 */
class ExportedByUIVCoreTools CATSYPRunnable : public CATSYPRefCounted
{
public:
  /** 
   * Initialize this class and set the reference count to @c 1.
   */
  CATSYPRunnable();

  /**
   * Do the action.
   */
  virtual void Run() = 0;

protected:
  /** 
   * Destroy this class. 
   */
  virtual ~CATSYPRunnable();

private:
  CATSYPRunnable(const CATSYPRunnable &);
  CATSYPRunnable &operator=(const CATSYPRunnable &);
};


#endif // CATSYPRunnable_H
