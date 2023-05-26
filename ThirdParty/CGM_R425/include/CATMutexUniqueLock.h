#ifndef CATMutexUniqueLock_h_
#define CATMutexUniqueLock_h_

// SystemTS (PublicInterfaces)
#include "CATMutex.h"
#include "CATBoolean.h"

// SGInfra (PublicInterfaces)
#include "SGInfra.h"

/**
* Like 'std::unique_lock' but for CATMutex:
* 1) Constructor does NOT lock the mutex
* 2) Call 'Lock' to lock the mutex
* 3) Destructor will unlock the mutex (but you can also manually call 'Unlock' before destruction).
*/
class ExportedBySGInfra CATMutexUniqueLock
{
public:
    CATMutexUniqueLock(CATMutex& iMutex);
    ~CATMutexUniqueLock();

    void Lock();
    void Unlock();

private:
    CATMutex&   _mutex;
    CATBoolean  _isLocked;
};

#endif // !CATMutexUniqueLock_h_
