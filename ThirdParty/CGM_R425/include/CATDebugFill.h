/* -*-c++-*- */
#ifndef CATDebugFill_H_
#define CATDebugFill_H_

//-----------------------------------------------------------
//  Static Functionnalities For Sweep Debug
//-----------------------------------------------------------
#include "SysDebug.h"
class CATBaseUnknown;

#ifndef NULL
#define NULL 0
#endif


class ExportedBySysDebug CATDebugFill
{
  public :

  //=================================================================
  //   TRACING 
  //
  //    => activation :                              
  //         export CATFILLTRACE=tracelevel    before launching process
	//					set CATFILLTRACE=tracelevel 
  //       or
  //         SetTraceLevel(tracelevel)    (0=OFF)
	//
	//
	//
	//			#include "CATDebugFill.h"
	//			if( CATDebugSweep::TraceOn >=1 ) 
  //=================================================================

  static void SetTraceLevel(int);
  static int  TraceOn;

};


#endif
