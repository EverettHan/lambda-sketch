#ifndef __CATOmxAssert_h
#define __CATOmxAssert_h

// Note : except the error message, these three macros have the same implementation.
// You must choose, but choose wisely.

// Assertion that won't be catched by CATCatch in case of failure
#define CATOmxAssert(assertion) ((void) ((assertion) || (CATOmxAssertImpl(#assertion, __FILE__, __LINE__, ASSERT), 0)))
// Precondition that won't be catched by CATCatch in case of failure
#define CATOmxExpects(assertion) ((void) ((assertion) || (CATOmxAssertImpl(#assertion, __FILE__, __LINE__, PRECOND), 0)))
// Postcondition that won't be catched by CATCatch in case of failure
#define CATOmxEnsures(assertion) ((void) ((assertion) || (CATOmxAssertImpl(#assertion, __FILE__, __LINE__, POSTCOND), 0)))

// --

#include "CATOmxKernel.h"
#include "CATOmxCxxPortability.h"

enum CATOmxAssertionType { ASSERT, PRECOND, POSTCOND };
/* Do not use this, use macro above*/
OMX_Cxx11_NORETURN void ExportedByCATOmxKernel CATOmxAssertImpl(char const * assertionStr, char const * file, int line, CATOmxAssertionType type);

#endif
