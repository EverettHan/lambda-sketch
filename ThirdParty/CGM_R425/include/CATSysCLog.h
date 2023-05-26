
// COPYRIGHT DASSAULT SYSTEMES 2002

#include "JS0CORBA.h"

/**
 * CATSysCLog prints a message in $ADL_ODT_OUT/$ODT_LOG_NAME.clog file or stderr
 * 
 * severity : either 'W' warning, 'E' error, 'F' fatal, 'D' deprecated, 'P' performance
 * stack_depth : limit the following stack
 * id : error identificator ex : FW-0001 , OM-
 * explain_fmt : additionnal format
 */
void ExportedByJS0CORBA CATSysCLog(char severity,unsigned stack_depth, const char *id ,const char *explain_fmt,...);
