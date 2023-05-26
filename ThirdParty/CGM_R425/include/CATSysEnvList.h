#ifndef __CATSYSENVLIST_H
#define __CATSYSENVLIST_H
#include "CATSysEnv.h"
#include "JS0LIB.h"  // exported by...
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14
class CATTrace;
class CATUnicodeString;

/* COPYRIGHT DASSAULT SYSTEMES 2002 */

//========================================================================
class ExportedByJS0LIB CATSysEnvList
//========================================================================
{
   public:

      CATSysEnvList ( );
      ~CATSysEnvList ( );

      void                   Add   ( CATSysEnv  * Env01 );
      CATSysEnv *            Get   ( CATUnicodeString Name, CATSysEnv::Mode Mode  );
      CATSysEnv *            Get   ( CATUnicodeString Name, CATUnicodeString Path );
      CATSysEnv::ReturnCode  Remove( CATUnicodeString Name, CATSysEnv::Mode Mode  );
      CATSysEnv::ReturnCode  Remove( CATUnicodeString Name, CATUnicodeString Path );
      int                    GetNbOfEnv();

   private:
      static CATTrace * Trace_EL;    
      static int NbOfEnv;
      static CATSysEnvList *  FirstEnvInList;
      static CATSysEnvList *  LastEnvInList;
      CATSysEnv *CSEnv;
      CATSysEnvList *next;
      CATSysEnvList *previous;
};
#endif
