#ifndef CATSysEnvPattern_H
#define CATSysEnvPattern_H
/* COPYRIGHT DASSAULT SYSTEMES 2002 */
/*
Remplace les methodes : 
   CATSysEnvFileManager::ReadReferenceFile ()
   CATSysEnvFileManager::GenerateEnvFromPattern ()
   CATSysEnvFileManager::Read () (la fin)
*/
//------------------------------------------------------------------------------------------------------------------------
#include "CATLib.h"  // ExportedBy
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14

class CATSysEnv;
class CATSysEnvPatternData;
class CATUnicodeString;
class CATTrace;

class ExportedByJS0LIB CATSysEnvPattern
{
   public :
   enum CATSysEnvPatternStatus
   {
      NoStatus                    = 0,
      Generate_From_Pattern_OK    = 1<<0,
      Generate_From_Pattern_KO    = 1<<1,
      Generate_From_MinPattern_OK = 1<<2,
      Generate_From_MinPattern_KO = 1<<3,
      GetBackwardCompatibility_OK = 1<<4,
      GetBackwardCompatibility_KO = 1<<5,
      Bad_Arguments               = 1<<6,
      Bad_Pattern                 = 1<<7,
      Cannot_Initialize_Pattern   = 1<<8
   };
   static CATSysEnvPatternStatus GetEnvFromPattern    ( CATSysEnv * ioEnv, CATUnicodeString * iConcatPath );
   static CATSysEnvPatternStatus GetEnvFromMinPattern ( CATSysEnv * ioEnv, CATUnicodeString * iConcatPath );
   static int IsAnOfficialVariable ( const char * iVar );
#ifndef _WINDOWS_SOURCE
   static CATSysEnvPatternStatus GetBackwardCompatibility ( char * & oCompShell );
#endif
   static int Unmake( int irc );

   private :
   CATSysEnvPattern();
   ~CATSysEnvPattern();
   void                   GetPattern             ( const char ** iFilepath, const char * iVar, CATSysEnvPatternData * &ioHandle );
#ifndef _WINDOWS_SOURCE
   void                   GetBCShell             ( const char ** iFilepath, const char * iVar, char * &ioHandle );
#endif
   void                   GetMinPattern          ( CATSysEnvPatternData * &ioHandle );
   CATSysEnvPatternStatus GenerateEnvFromPattern ( CATSysEnv * ioEnv, CATUnicodeString * iConcatPath, int iMinPattern=0 );
   void                   MakeConcat             ( CATUnicodeString iConcat, CATUnicodeString iExt, CATUnicodeString &oConcat );
//   void                   Dump                   ( CATSysEnvPatternData * iHandle );

   static CATSysEnvPattern * _anchor;
   static CATTrace * _t;
   static CATSysEnvPatternData * _handle_inter;
   static CATSysEnvPatternData * _handle_server;
   static CATSysEnvPatternData * _handle_min;
#ifndef _WINDOWS_SOURCE
   static char * _handle_compshell;
#endif
};
#endif
