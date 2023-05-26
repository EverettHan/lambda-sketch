#ifndef DSYSysOdtLog_H
#define DSYSysOdtLog_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined (__DSYSysOdtTools)
#define ExportedByDSYSysOdtTools DSYExport
#else
#define ExportedByDSYSysOdtTools DSYImport
#endif
#include "DSYExport.h"

//===============================================================
//===============================================================

#define ___DSY_SYS_ODT_START_EXIT_CODE                          \
  DSYSysOdtInitializeReturnCode()

#define ___DSY_SYS_ODT_STOP_EXIT_CODE                           \
  if ( DSYSysOdtEvaluateFinalReturnCode() == EXIT_FAILURE )     \
    exit(EXIT_FAILURE);                                         \
  return EXIT_SUCCESS

#define ___DSY_SYS_ODT_EVAL_RETURN_CODE                         \
  DSYSysOdtEvaluateReturnCode

#define ___DSY_SYS_ODT_EVAL_SUCCESS_RETURNED_CODE               \
  DSYSysOdtEvaluateSuccessReturnedCode

#define ___DSY_SYS_ODT_EVAL_FAILURE_RETURNED_CODE               \
  DSYSysOdtEvaluateFailureReturnedCode

#define ___DSY_SYS_ODT_FORCE_EXIT_CODE                          \
  exit(DSYSysOdtEvaluateFinalReturnCode())                      \

#define ___DSY_SYS_ODT_NEW_LINE                                 \
  DSYSysOdtNewLine()

//===============================================================
//===============================================================

#define ___DSY_SYS_ODT_MAIN_START                               \
  int main(int argc, char** argv)                               \
  {                                                             \
    ___DSY_SYS_ODT_START_EXIT_CODE;

#define ___DSY_SYS_ODT_MAIN_STOP                                \
    ___DSY_SYS_ODT_STOP_EXIT_CODE;                              \
  }

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYSysOdtTools.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/
/// Function to initialize returned conditions
ExportedByDSYSysOdtTools void DSYSysOdtInitializeReturnCode(void);

/// Function to initialize returned conditions
ExportedByDSYSysOdtTools int DSYSysOdtEvaluateFinalReturnCode(void);

/// Function to evaluate returned conditions
ExportedByDSYSysOdtTools bool DSYSysOdtEvaluateReturnCode(bool Condition, const char* pFmt, ...);

/// Function to evaluate true-returned condition
ExportedByDSYSysOdtTools bool DSYSysOdtEvaluateSuccessReturnedCode(const char* pFmt, ...);

/// Function to evaluate false-returned condition
ExportedByDSYSysOdtTools bool DSYSysOdtEvaluateFailureReturnedCode(const char* pFmt, ...);

/// Function to log a new line
ExportedByDSYSysOdtTools void DSYSysOdtNewLine(void);

/// function to flush
ExportedByDSYSysOdtTools void DSYSysOdtFlush(void);

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

#endif  // DSYSysOdtLog_H
