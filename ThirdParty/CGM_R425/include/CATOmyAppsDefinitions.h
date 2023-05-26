#ifndef CATOMYAPPSDEFINITIONS_H_
#define CATOMYAPPSDEFINITIONS_H_

#include "CATIAV5Level.h"

#if defined(CATIAR420)
#define MYAPPS_NEW_LANGUAGE_HEADER
#endif

#define MYAPPS_KOALA_RETVAL

#define MYAPPS_LOG if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::GetOmsXmlTracer("MyApps","Info",InfoMessage(),0,"ITG")
#define MYAPPS_LOG_ERR if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::GetOmsXmlTracer("MyApps","Error",InfoMessage(),0,"ITG") 

#endif
