/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifyActivate                                                    */
/*                                                                       */
/*  Usage Notes: Event Container of CATCommandSelector protocol          */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATNotifyActivate
#define _CATNotifyActivate
#include "CATCommandStandardMsg.h"
#include "JS0FM.h"

class ExportedByJS0FM CATNotifyActivate : public CATCommandStandardMsg
{

 public:

   //--------------------------------------
   // Methods
   //--------------------------------------
      CATNotifyActivate();
      virtual ~CATNotifyActivate();
      CATDeclareClass;
};

#endif
