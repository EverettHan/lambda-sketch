/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifyCancel                                                      */
/*                                                                       */
/*  Usage Notes: Event Container of CATCommandSelector protocol          */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATNotifyCancel
#define _CATNotifyCancel
#include "CATCommandStandardMsg.h"
#include "JS0FM.h"

class ExportedByJS0FM CATNotifyCancel : public CATCommandStandardMsg
{

 public:

   //--------------------------------------
   // Methods
   //--------------------------------------
      CATNotifyCancel();
      virtual ~CATNotifyCancel();
      CATDeclareClass;
};

#endif
