/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATRetryErrorNotif                                                   */
/*                                                                       */
/*  Usage Notes: Notification of unhandled error                         */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                       sgt      */
/*=======================================================================*/
#ifndef _CATRetryErrorNotif
#define _CATRetryErrorNotif
#include "CATCommand.h"
#include "CATNotification.h"
#include "CATStackTrace.h"
#include "CATErrors.h"
#include "JS0FM.h"

//-------------------------------------------------------------
#define CATRMErrUndefined      0
#define CATRMErrStopProcess    1
#define CATRMErrContinueExec   2

class ExportedByJS0FM CATRetryErrorNotif : public CATNotification
{

 public:

  //===================================================
  // Methods
  //===================================================

   CATRetryErrorNotif(CATError *er,CATStackTrace *ErrStack);
   virtual ~CATRetryErrorNotif();
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
