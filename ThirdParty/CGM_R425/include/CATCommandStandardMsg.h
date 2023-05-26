/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATCommandStandardMsg                                                */
/*                                                                       */
/*  Usage Notes: Event Container of CATCommandSelector protocol          */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATCommandStandardMsg
#define _CATCommandStandardMsg
#include "CATCommand.h"
#include "CATNotification.h"
#include "JS0FM.h"

class ExportedByJS0FM CATCommandStandardMsg : public CATNotification
{

 public:

  //===================================================
  // Methods
  //===================================================

   CATCommandStandardMsg(CATCommandMsg Event);
   virtual ~CATCommandStandardMsg();

   CATDeclareClass;

  //===================================================
  // Data
  //===================================================

   CATCommandMsg _Type;  // Notification type


};

#endif
