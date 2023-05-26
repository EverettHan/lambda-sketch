/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotificationRecord                                                */
/*                                                                       */
/*  Usage Notes: Event Container of Record Protocole                     */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATNotificationRecord
#define _CATNotificationRecord
#include "CATNotification.h"

#include "JS0FM.h"

// Return code of SaveState and RestoreState methods
// -------------------------------------------------
enum CATCommandSaveSate  { CATRecordSave        =1,
			   CATRecordNoSave      =2 ,
			   CATRecordRestore     =3 ,
			   CATRecordNoRestore   =4 };

class ExportedByJS0FM CATNotificationRecord : public CATNotification
{

 public:

   CATNotificationRecord();
   virtual ~CATNotificationRecord();

   CATDeclareClass;

   // Set/Get the Notification string
   // -------------------------------
   virtual char* GetNotificationString();
   virtual void  SetNotificationString(const char* name);

   // Set/Get the block indent
   // -------------------------------
   virtual char* GetBlockIndent();
   virtual void  SetBlockIndent(char* blockIndent);

 private:

   char * _NotificationName;
   char * _BlockIndent;
};

#define CATRECORDSAVEOBJECT(notif)   \
{                                    \
  if ( notif == NULL )               \
    return CATRecordSave;   \
}

#define CATRECORDNOSAVEOBJECT(notif)   \
{                                      \
  if ( notif == NULL )                 \
    return CATRecordNoSave;   \
}
#endif
