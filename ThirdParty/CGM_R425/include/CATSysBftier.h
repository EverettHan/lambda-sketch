#ifndef CATSysBftier_H
#define CATSysBftier_H
/**
//==============================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//==============================================================
**/

#include "JS03TRA.h"
/**
// -----------------------------------------
// reserved for CGM use
// -----------------------------------------
// generate a message if bftier debug mode is
// active
// -----------------------------------------
**/
#ifdef __cplusplus
extern "C"
{
  ExportedByJS03TRA void CATSysBftier( int iVal, const char *iMsg, int iPassedBy=0);
}
#else
  ExportedByJS03TRA void CATSysBftier( int iVal, const char *iMsg, int iPassedBy);
#endif
#endif
