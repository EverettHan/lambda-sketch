#ifndef CATDynLicenseSettings_H
#define CATDynLicenseSettings_H
// CATIA Version 5 Release 10 Framework System
// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATLib.h"
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14

class LicDyn;  // defined in CATDynLicenseSetting.cpp
class CATTrace;
class CATSettingRepository;

class ExportedByJS0LIB CATDynLicenseSettings
{
   public:

   ~CATDynLicenseSettings ( );
   static void UnMake ();

   static const char * GetRepositoryName ();
   static void CommitModification ();
   static void CancelModification ();
   static void ResetUserSettingsValue ();

   static CATLONG32 GetLock_List ( char & oLock );
   static CATLONG32 SetLock_List ( char   oLock );

   enum ItemStatus
   {
      Requested = 0,
      NotRequested,
      Undef
   };
   static CATDynLicenseSettings::ItemStatus Get_Item ( const char * i );
//   static void                              Set_Item ( const char * i, CATDynLicenseSettings::ItemStatus s );
   static CATDynLicenseSettings::ItemStatus Set_Item ( const char * i, CATDynLicenseSettings::ItemStatus s );
   static CATLONG32                              GetLock_Item  ( const char * i, char & oLock );
   static CATLONG32                              SetLock_Item  ( const char * i, char   oLock );

   // INTERNAL USE ONLY 
   static void Dump ();
   // INTERNAL USE ONLY 

// ----------------------------------------------------------------------------

   protected :
   CATDynLicenseSettings ( );

   private :
   static void Make ();
   static void CleanLic ( );

   static CATLONG32 GetLock_Att ( const char * att, char & oLock );
   static CATLONG32 SetLock_Att ( const char * att, char   oLock, const char * type );

   static int                    _Make_not_done;
   static CATTrace             * _t;
   static LicDyn               * _dyn_lic;
   static CATSettingRepository * _rep;
   static char                 * _repname;
   static int                    _ls;

};
#endif

