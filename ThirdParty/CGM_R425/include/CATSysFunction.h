#ifndef CATSysFunction_h
#define CATSysFunction_h

#include "JS0CORBA.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @nodoc
 */
ExportedByJS0CORBA const void * CATSysFuncGetFunction(const char*iKey , const char *iFuncType);

/**
 * @nodoc
 */
#define CATSysGetFunction(iKey,iFuncType) \
((iFuncType)CATSysFuncGetFunction(#iKey,#iFuncType))

#endif // CATSysFunction_h
