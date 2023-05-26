#ifndef __CATSysLevelManager_h
#define __CATSysLevelManager_h									

//-----------------------------------------------------------------------
// DEPARTEMENT SAD
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------

#include "JS0LIB.h"  // exported by..
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14
class CATSysEnv;
class CATTrace;

//=================================================================================
class ExportedByJS0LIB CATSysLevelManager
//=================================================================================
{
   public :

   ~CATSysLevelManager ( );
	  
   static const char * CATGetLevel         ( const char * varname );
   static const char * CATGetLevelName     ( );
   static const char * CATGetLevelFileName ( );
   static void         UnMake ();    // Pour sortir proprement.
   static CATSysEnv  * CATGetBaseLevel ();
   static const char * CATGetLevelTempDirectory();

   protected :

   CATSysLevelManager ( );

   private :

   static void         Make2 ();
   static const char * GetLevelFileName ( const char * full_path );
   static char * GetLevelTempDirectory();  
   static CATSysEnv * BaseLevel;
   static int         first;
   static char      * False;

   static CATTrace  * t;
   static int         cpt;
   static char      * fichier_du_choix;
   static char      * runtime_level;
   static char      * temp_directory;
};
#endif

