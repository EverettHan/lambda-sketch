/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifyActivated                                                */
/*                                                                       */
/*  Usage Notes: Event Container of CATCommandSelector protocol          */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATNotifyActivated
#define _CATNotifyActivated
#include "CATCommand.h"
#include "CATNotification.h"
#include "CATCommandSelector.h"
#include "JS0FM.h"

class ExportedByJS0FM CATNotifyActivated : public CATNotification
{

 public:

  //===================================================
  // Methods
  //===================================================

   CATNotifyActivated(CATCommandSelector* css = NULL, CATCommand *cmd = NULL );
   virtual ~CATNotifyActivated();

   CATDeclareClass;

  //===================================================
  // Data
  //===================================================

   CATCommandSelector * _ccssource;
   CATCommand * _cmdtarget ;


};

#endif
