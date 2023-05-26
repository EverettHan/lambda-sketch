/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifyAnalyse                                                     */
/*                                                                       */
/*  Usage Notes: Event Container of CATCommandSelector protocol          */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATNotifyAnalyse
#define _CATNotifyAnalyse
#include "CATCommandStandardMsg.h"
#include "JS0FM.h"

class ExportedByJS0FM CATNotifyAnalyse : public CATCommandStandardMsg
{

 public:

   //--------------------------------------
   // Methods
   //--------------------------------------
      CATNotifyAnalyse();
      virtual ~CATNotifyAnalyse();
      CATDeclareClass;
};

#endif
