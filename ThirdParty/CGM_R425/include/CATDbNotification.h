#ifndef CATDBNOTIFICATION_H
#define CATDBNOTIFICATION_H

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "stdlib.h"
#include "CATNotification.h"
/**
 * Specific notification for database events
 * <b>Role</b>: contains a message specific to a Callback event and the database explainations.
 * 
 */
class ExportedByJS0SCBAK CATDbNotification : public CATNotification
{
  CATDeclareClass;
public: 
  char MessageNotif[80];
  char Cause[512];
};
#endif

