#ifndef CATOxHRESULT_H
#define CATOxHRESULT_H

#include "CATErrorDef.h"

/**  HRESULT encoding. */
#define TOS_MAKE_HRESULT(severity,id) MAKE_HRESULT(severity, FACILITY_ITF, (0xFE00 | ((id) & 0xff)))

/** failure return codes */
#define TOS_MAKE_HRESULT_ERROR(id) TOS_MAKE_HRESULT(SEVERITY_ERROR, id)

/** A minor conflict occurred. */
constexpr HRESULT E_TOS_MINORCONFLICT = TOS_MAKE_HRESULT_ERROR(1);

/** Attempting to create a multi-tos link */
constexpr HRESULT E_TOS_INTERTOSLINK = TOS_MAKE_HRESULT_ERROR(2);

/** Attempting to create a cycle in instance/reference DAG */
constexpr HRESULT E_TOS_CYCLE = TOS_MAKE_HRESULT_ERROR(3);

/** composed object has no composer */
constexpr HRESULT E_TOS_NO_COMPOSER = TOS_MAKE_HRESULT_ERROR(4);

/** composed object has several composers */
constexpr HRESULT E_TOS_SEVERAL_COMPOSERS = TOS_MAKE_HRESULT_ERROR(5);

#undef TOS_MAKE_HRESULT_ERROR


/** success return codes */
#define TOS_MAKE_HRESULT_SUCCESS(id) TOS_MAKE_HRESULT(SEVERITY_SUCCESS, id)

/** component is composed using M1 native composition (through a unique 'compositional' relation) */
constexpr HRESULT S_TOS_M1COMPOSITION = TOS_MAKE_HRESULT_SUCCESS(1);

/** port or connection is composed (M1 composition but the compositional relation is hidden client-side) */
constexpr HRESULT S_TOS_PORTORCONNECTION_COMPOSITION = TOS_MAKE_HRESULT_SUCCESS(2);

/** representation is composed using V_isOnceInstantiable pattern */
constexpr HRESULT S_TOS_ONCEINSTANCIABLE_COMPOSITION = TOS_MAKE_HRESULT_SUCCESS(3);

#undef TOS_MAKE_HRESULT_SUCCESS

#undef TOS_MAKE_HRESULT

#endif
