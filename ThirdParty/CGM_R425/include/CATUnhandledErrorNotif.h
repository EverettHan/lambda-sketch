/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATUnhandledErrorNotif                                                */
/*                                                                       */
/*  Usage Notes: Event Container of CATCommandSelector protocol          */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef _CATUnhandledErrorNotif
#define _CATUnhandledErrorNotif
#include "CATCommand.h"
#include "CATNotification.h"
#include "CATStackTrace.h"
#include "CATErrors.h"
#include "JS0FM.h"

#define CATUErrUndefined      0
#define CATUErrStopProcess    1
#define CATUErrContinueExec   2
class ExportedByJS0FM CATUnhandledErrorNotif : public CATNotification
{

 public:

  //===================================================
  // Methods
  //===================================================

   CATUnhandledErrorNotif(CATError *er,CATStackTrace *ErrStack);
   virtual ~CATUnhandledErrorNotif();
   void SetStatus(int NewStatus);
   int  GetStatus();
   CATStackTrace *  GetErrorStack();
   CATError      *  GetError();

   CATDeclareClass;

  private:
  //===================================================
  // Data
  //===================================================

   CATStackTrace *_Stack; // Stacktrace de l'erreur
   CATError      *_UErr ; // Unhandled error       
   int           _Status;


};

#endif
