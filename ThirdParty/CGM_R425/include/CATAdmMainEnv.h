#ifndef CATAdmMainEnv_h
#define CATAdmMainEnv_h
/* */									
//-----------------------------------------------------------------------
// DEPARTEMENT SAD
// CNEXT
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------
//
//  Ressources de base des applications:
//  - Recuperation des arguments (fonctionne aussi lors de l'init des statiques)
// TO BE REMOVED IN R8
//  - Positionnement de l'environnement par defaut
// TO BE REMOVED IN R8
//
//-----------------------------------------------------------------------

#include "CATLib.h"
#include "JS0LIB.h"  // exported by...
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14

#define MaxLength 4096

//#ifdef _WINDOWS_SOURCE
//#define DIRSEP "\\"
//#else
//#define DIRSEP "/"
//#endif

class CATTrace;
#define  _USE_SERVER_ENV_ARG
class ExportedByJS0LIB CATAdmMainEnv
{
   public:
   CATAdmMainEnv ( );
   ~CATAdmMainEnv ( );
   void         GetArgcArgv ( int & argc, char ** & argv );
   const char * GetOS ();
// TO BE REMOVED IN R8
   void         SetMinEnv ();  // DOIT DISPARAITRE EN R8
// TO BE REMOVED IN R8
   const char * GetPath();  // @deprecated R420 (use GetPathU)
   const char * GetPathU(); // ++IK8 17:09:04 Unicode support
   const char * GetModulePath();

   enum Option {
      EnvName = 0,
      EnvDir,
      LogName,
      LogDir,
  	  ServerEnvName,
      ServerEnvDir
   };
   const char * GetOption ( CATAdmMainEnv::Option ); 
   const char * GetOption ( const char * ); 

   enum Command {
      Regserver = 0,
      Unregserver,
      Help,
      CatiaAdmin 
   };
   enum Answer {
      NoCmd = 0,
      Yes,
      No,
      Undef
   };
   const Answer IsCommand     ( CATAdmMainEnv::Command ); 
   const Answer IsCommand     ( const char * ); 

   typedef enum {
      User = 0,
      Admin
   } Status;
   const Status IsSystemAdmin ();

private :
   static int argc;
   static char ** argv;
   static char s_path[MaxLength];
   static char s_pathUtf8[MaxLength];
   static char os[MaxLength];
   static char module_path[MaxLength];

// TO BE REMOVED IN R8
   static char c1_cmd[MaxLength]; // putenv !!!
   static char c2_cmd[MaxLength]; // putenv !!!
   static char c3_cmd[MaxLength]; // putenv !!!
   static char c4_cmd[MaxLength]; // putenv !!!
   static char c5_cmd[MaxLength]; // putenv !!!
// TO BE REMOVED IN R8

   void SetID ();
   int  IsOpt ( char * (* &av), const char * opt, char * (&value) );
   int  IsCmd ( char * (* &av), const char * cmd, char ** r, int def, int * value );
   void AnalyseArguments ();

   static char * Opt_EnvName;
   static char * Opt_EnvDir ;
   static char * Opt_ServerEnvName;
   static char * Opt_ServerEnvDir ;
   static char * Opt_LogName;
   static char * Opt_LogDir ;

   static Answer Cmd_C_Admin;
   static Status Cmd_S_Admin;
   static Answer Cmd_Reg    ; 
   static Answer Cmd_Unreg  ; 
   static Answer Cmd_Help   ; 

   void DumpArgcArgv     ( CATTrace * trace );
   void DumpStatus       ( CATTrace * trace );
   void DumpOptions      ( CATTrace * trace );

   static CATTrace * Trace;
   static CATTrace * TraceTools;
   static int OnceOnly;
   static int cpt;
};

#endif
