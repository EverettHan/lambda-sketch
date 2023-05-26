#ifndef __CATA5Util_h__
#define __CATA5Util_h__

#include "CATA5ParserExport.h"
#include <time.h>

class CATOmxUTF8String;

namespace CATA5 
{
  /** 
   * Converting a string to time_t according to the tcl format
   * YYYY/MM/DD@HH:MM:SS:GMT
   */
  ExportedByCATA5Parser time_t convert_date(const char *iDate);

  /**
   * Converting a string to time_t according to the tcl format
   * YYYY-MM-DDTHH:MM:SSZ
   */
  ExportedByCATA5Parser time_t convert_date_ISOA8601(const char *iDate);
  ExportedByCATA5Parser CATOmxUTF8String convert_date(time_t iEpoch) ;
}

#endif
