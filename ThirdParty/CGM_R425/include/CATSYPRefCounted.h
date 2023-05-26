#ifndef CATSYPRefCounted_H
#define CATSYPRefCounted_H


#include <UIVCoreTools.h>

/** @ingroup groupUIVCoreToolsThreading
 * Base class for objects that share instances across thread using
 * internal reference counting.
 *
 * This base class provides thread-safe @ref AddRef and @ref Release
 * function to increment/decrement an internal reference count. When
 * this count reaches @c 0 the object is destroyed by calling
 * <code>delete this</code>.
 */
class ExportedByUIVCoreTools CATSYPRefCounted
{
public:
  /** Initialize this class */
  CATSYPRefCounted();

  /**
   * Increment the reference counter.
   *
   * This method is thread-safe.
   */
  void AddRef();

  /**
   * Decrement the reference counter.
   *
   * The object will be destroyed when the reference count reaches 0.
   *
   * This method is thread-safe.
   */
  void Release();

protected:
  /** Destroy this class */
  virtual ~CATSYPRefCounted();

private:
  CATSYPRefCounted(const CATSYPRefCounted &);
  CATSYPRefCounted &operator=(const CATSYPRefCounted &);
private:
  /** the counter of references; this object is destroyed when it reaches 0 */
  int _refCnt;
};


#endif // CATSYPRefCounted_H
