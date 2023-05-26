/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATBeginNotification                                                */
/*                                                                       */
/*  Usage Notes: Event Container of Record Protocole                     */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATBeginNotification
#define _CATBeginNotification
#include "CATNotification.h"
#include "JS0FM.h"

class ExportedByJS0FM CATBeginNotification : public CATNotification
{

 public:

   CATBeginNotification();
   virtual ~CATBeginNotification();

   CATDeclareClass;

   // Set/Get the Notification string
   // -------------------------------
   virtual char* GetNotificationString();
   virtual void  SetNotificationString(const char* name);


 private:

   char * _NotificationName;
};

#endif
