/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1997                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATCCSModeOnNotification                                             */
/*                                                                       */
/*                                                                       */
/*  Notification emitted by the CATCommandSelector when it changes       */
/*  its selector mode because a CATCommand requested the focus           */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATCCSModeOnNotification_H
#define _CATCCSModeOnNotification_H
#include "CATNotification.h"
#include "JS0FM.h"

class ExportedByJS0FM CATCCSModeOnNotification : public CATNotification
{

 public:

  //===================================================
  // Methods
  //===================================================

   CATCCSModeOnNotification();
   virtual ~CATCCSModeOnNotification();

   CATDeclareClass;



};

#endif
