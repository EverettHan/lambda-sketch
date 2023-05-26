#ifndef CATSetAppArgs_H
#define CATSetAppArgs_H
/*
// COPYRIGHT DASSAULT SYSTEMES 2000
*/

#include "CATLib.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Reserved for Dassault Systemes Internal Usage
 * 
 * CATSetAppArgs is usable only in some very specific 
 * cases and MUST be avoided in all other cases.
 *
 *  Please contact System FW responsible before using
 *  this call in your source
 *
 */ 
ExportedByJS0LIB void CATSetAppArgs (int argc, const char *argv[],
                                     const char *env[]);



#ifdef __cplusplus
};
#endif

#endif
