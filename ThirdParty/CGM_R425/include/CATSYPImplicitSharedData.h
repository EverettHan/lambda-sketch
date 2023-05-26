#ifndef CATSYPImplicitSharedData_H
#define CATSYPImplicitSharedData_H

#include <UIVCoreTools.h>

class CATHashDico;
class CATUnicodeString;

/**
 * Base Class to use when coding copy-on-write class (aka implicit sharing)
 */
class ExportedByUIVCoreTools CATSYPImplicitSharedData
{
public:
  /**
   * Constructor.
   * the refcount is initialized to 1, as we consider that it is created by
   * its first owner.
   */
  CATSYPImplicitSharedData();
  virtual ~CATSYPImplicitSharedData();

  /**
   * Clone itself when the data is shared.
   * @return a cloned object of the current one.
   */
  CATSYPImplicitSharedData* CloneIfShared();
  /**
   * Increment the internal counter. If it is > 1, the data is shared.
   */
  void Attach();
  /**
   * Decrement the internal counter. If it is == 0, the object suicides.
   * Assert if the counter is null when calling this method.
   */
  void Detach();

protected:
  virtual CATSYPImplicitSharedData* Clone() =0;
private:
  int _refcount;
};


#endif
