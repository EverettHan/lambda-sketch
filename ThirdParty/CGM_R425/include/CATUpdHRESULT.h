/**
 * @level Private
 * @usage U1
 */
#ifndef __CATUpdHRESULT_H
#define __CATUpdHRESULT_H

#include <stdlib.h>
#include "IUnknown.h"
#include "CATErrorDef.h"

/**
 * This HRESULT means a cycle (infinitely recursive operation) has been detected.
 */ 
#ifndef E_CYCLE
  #define  E_CYCLE      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xAF02 | 0x0008)
#endif

/**
 * This HRESULT means the inputs of an object have been modified during its build.
 */ 
#ifndef E_REIMPACT
  #define  E_REIMPACT   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xAF01 | 0x0008)
#endif

#endif

