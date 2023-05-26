/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifierRecord                                                    */
/*                                                                       */
/*  Usage Notes: Event Container of Record Protocole                     */
/*                                                                       */
/*=======================================================================*/
/*  Creation fevrier 1997                                   jpl          */
/*=======================================================================*/
#ifndef _CATNotifierRecord
#define _CATNotifierRecord
#include "CATNotification.h"

#include "JS0FM.h"

class ExportedByJS0FM CATNotificationIdle : public CATNotification
{

 public:

   CATNotificationIdle();
   virtual ~CATNotificationIdle();
   CATDeclareClass;

 private:

};

class ExportedByJS0FM CATNotificationET : public CATNotification
{

 public:

   CATNotificationET();
   virtual ~CATNotificationET();
   CATDeclareClass;

 private:

};

class ExportedByJS0FM CATNotificationFd : public CATNotification
{

 public:

   CATNotificationFd();
   virtual ~CATNotificationFd();
   CATDeclareClass;

 private:

};



#endif
