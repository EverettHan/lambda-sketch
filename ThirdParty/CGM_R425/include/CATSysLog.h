#ifndef __CATSysLog_h
#define __CATSysLog_h									

/* COPYRIGHT DASSAULT SYSTEMES 2001 */

//#include <fstream.h> 
#include "JS0LIB.h"  // exported by..

#define MaxLength 4096

class CATUnicodeString;

//=================================================================================
class ExportedByJS0LIB CATSysLog
//=================================================================================
{
   public :
   ~CATSysLog ( );
   static void Write ( CATUnicodeString m );
   static void Write ( const char * m );
   static void Clean ( );
   static const char * SetLogFileName ( const char * );
   static const char * SetLogFileDir  ( const char * );
   static void UnMake ();    

   enum FileType
   {
      Session          = 1 << 0,
      Log              = 1 << 1,
   };
   static void SetLogFileType ( const FileType t );

   enum EnvLogType
   {
      USER_ENV_LOG     = 1 << 0,
      GLOBAL_ENV_LOG   = 1 << 1
   };
   static void SetEnvLogFile (const CATSysLog::EnvLogType t);

   protected :
   CATSysLog ( ); // pour le couverture de test

   private :
   static void Make ();    
   static const char * SetupLogFileName ( const char * );
   static void SetupVars ();    
   static const char * GetFileName ();    
   static const char * GetLogFileName ();

   static int        Verbose;
   static unsigned int FileHandle;
   static int        Make_not_done;
   static CATSysLog::FileType AppliDefinedFileType;
   static char       Full_LogFileName         [MaxLength];
   static char       LogFileName              [MaxLength];
   static char       AppliDefined_LogFileName [MaxLength];
   static char       CmdLine_LogFileName      [MaxLength];
   static char       CmdLine_LogFileDir       [MaxLength];
   static char       AppliName                [MaxLength];
   static char       UserStatus               [MaxLength];
};
#endif

