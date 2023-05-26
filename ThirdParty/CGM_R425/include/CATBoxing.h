#ifndef _CATBoxing_H
#define _CATBoxing_H

#include <CATBaseUnknown.h>
#include <IntroInfra.h>
#include <CATISYPValues.h>
#include <CATSYPHashMap.h>

#include <CATSYPDeclareBoxing.h>
#include <CATSYPImplementBoxing.h>


#ifndef CATBoxExport
#define CATBoxExport
#endif

#define CATDeclareBox( I_TYPE )\
  CATSYP_DECLARE_BOXING(CATBoxExport, I_TYPE)         

  
#define CATImplementBoxWithComparator( I_TYPE , comparatorClass) \
  CATSYP_IMPLEMENT_BOXING_WITH_COMPARATOR( I_TYPE , comparatorClass)
  

#define CATImplementBox( I_TYPE)\
  CATSYP_IMPLEMENT_BOXING( I_TYPE) 

#endif
