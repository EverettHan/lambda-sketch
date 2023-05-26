/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATRecordDriver                                                      */
/*                                                                       */
/*  Usage Notes:  Driver Record for Capture/Replay                       */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl          */
/*=======================================================================*/
#ifndef __CATRecordDriver
#define __CATRecordDriver

#include "JS0FM.h"
#include "CATCommand.h"

// All Record modes
// ----------------
enum CATRecordMod  { CATRecordModeCapture        =1,
                     CATRecordModeReplay         =2,
                     CATRecordModeCaptureReplay  =4,
                     CATRecordModeOff            =0,
                     CATRecordModeOn             =3 };


#define CATRecordEnvCapture                  "CATRECORDCAPTURE"
#define CATRecordEnvReplay                   "CATRECORDREPLAY"

class ExportedByJS0FM CATRecordDriver  : public CATCommand
{


   public :

      //===================================================
      // Methods
      //===================================================

      // Instanciation
      //--------------
      CATRecordDriver ( );
      virtual ~CATRecordDriver () ;

      void Init(CATRecordMod imode);

      // Start a new CATRecord mode
      // --------------------------
      int BeginMode ( CATRecordDriver * ,CATRecordMod );

      // End a CATRecord mode
      // --------------------
      int EndMode ( CATRecordDriver *, CATRecordMod );

      // Get Driver mode
      // --------------------
      virtual int GetDriverMode ( );

      // Connect record file
      // -------------------
      virtual int ROpen(int);

      // Disconnect record file
      // ----------------------
      virtual int RClose(int);

      // Get Datas in record file
      // ------------------------
      virtual int RRead(void**, int*);

      // Put Datas in record file
      // ------------------------
      virtual int RWrite(void* ,int);

      // Flush Datas in record file
      // ------------------------
      virtual int RFlush();

      // Record File Informations
      // ------------------------
      virtual int RInfo(char &Machine,int &FileVersion);

private:
      int _replayfd; //DBE Nov 2015
};


#endif
