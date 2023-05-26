#ifndef _CATSysParamMap_h
#define _CATSysParamMap_h

/** @CAA2Required */
/***********************************************************************/
/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */
/***********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2003
#include "JS0SETT.h"

class ExportedByJS0SETT CATSysParamMap 
{
public:
  CATSysParamMap (CATSysParamMap **iRoot, char ** iTab);
  ~CATSysParamMap() {};

  char ** _Param;
  CATSysParamMap* _Next;
};



#endif
