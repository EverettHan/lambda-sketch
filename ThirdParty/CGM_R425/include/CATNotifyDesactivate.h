/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifyDesactivate                                                 */
/*                                                                       */
/*  Usage Notes: Event Container of CATCommandSelector protocol          */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATNotifyDesactivate
#define _CATNotifyDesactivate
#include "CATCommandStandardMsg.h"
#include "JS0FM.h"

class ExportedByJS0FM CATNotifyDesactivate : public CATCommandStandardMsg
{

 public:

   //--------------------------------------
   // Methods
   //--------------------------------------
      CATNotifyDesactivate();
      virtual ~CATNotifyDesactivate();
      CATDeclareClass;
};

#endif
