#ifndef CATLicenseSettings_H
#define CATLicenseSettings_H
// CATIA Version 5 Release 8 Framework ApplicationFrame
// COPYRIGHT DASSAULT SYSTEMES 2001
//------------------------------------------------------------------------
//
// Abstract : 
// ---------- 
//
//------------------------------------------------------------------------
//
// Usage :    
// -------    
//
//------------------------------------------------------------------------
//
// Inheritance : 
// -----------  
//
//------------------------------------------------------------------------
//
// Main Methods :  
// -------------- 
//
//------------------------------------------------------------------------
//#define CATIAV5R5
#include "CATIAV5Level.h"
#include "CATLib.h"
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14

class Dyn;  // defined in CATLicenseSetting.cpp
class CATTrace;
class CATSettingRepository;

class ExportedByJS0LIB CATLicenseSettings
{
   public:

   ~CATLicenseSettings ( );
   static void UnMake ();

   static const char * GetRepositoryName ();
   static void CommitModification ();
   static void CancelModification ();
   static void ResetUserSettingsValue ();

   // if iDefaultLicenses!=0 and the settings are empty,
   // Get_List returns the default licenses, that is, the visible nodolocked licenses
   static char ** Get_List     ( int & nblic, int iDefaultLicenses=0 );

   static void    Set_List     ( char ** l, int nblic );
   static void    Set_And_Clean_List ( char ** the_lic );
   static CATLONG32    GetLock_List ( char & oLock );
   static CATLONG32    SetLock_List ( char   oLock );

   static float Get_TimeOut     ( );
   static void  Set_TimeOut     ( float to );
   static CATLONG32  GetLock_TimeOut ( char & oLock );
   static CATLONG32  SetLock_TimeOut ( char   oLock );

   static float Get_ContactFrequency     ( );
   static void  Set_ContactFrequency     ( float cf );
   static CATLONG32  GetLock_ContactFrequency ( char & oLock );
   static CATLONG32  SetLock_ContactFrequency ( char   oLock );

   static int GetExpiryAlert();

   enum LicServerInfo
   {
      InfoOff = 0,
      InfoOn
   };
   static CATLicenseSettings::LicServerInfo Get_ServerOpt     ( );
   static void                              Set_ServerOpt     ( CATLicenseSettings::LicServerInfo so );
   static CATLONG32                              GetLock_ServerOpt ( char & oLock );
   static CATLONG32                              SetLock_ServerOpt ( char   oLock );

   enum ItemStatus
   {
      Requested = 0,
      NotRequested,
      Undef
   };
   static CATLicenseSettings::ItemStatus Get_Item ( const char * i, char * l );
   static void                           Set_Item ( const char * i, CATLicenseSettings::ItemStatus s, const char * l );
   static CATLicenseSettings::ItemStatus Get_Dyn_Item ( const char * i );
   static void                           Set_Dyn_Item ( const char * i, CATLicenseSettings::ItemStatus s );
   static void                           Cls_Dyn_Item ( );
   static CATLONG32                           GetLock_Item  ( const char * i, char & oLock );
   static CATLONG32                           SetLock_Item  ( const char * i, char   oLock );

   // INTERNAL USE ONLY 
   static void Dump ();
   // INTERNAL USE ONLY 

   // ----------------------------------------------------------------------------

   protected :
   CATLicenseSettings ( );

   private :
   static void Make ();
   static void CleanLic ( );

   static int Make_not_done;
   static char ** lic;
   static char ** _LicSorted;
   static int nblic;
   static int nbSortedLic;
   static CATLicenseSettings::LicServerInfo so;
   static float                             to;
   static float                             cf;
   static int                               ls;

   static CATTrace * t;
   static Dyn * dyn_lic;
   static CATLONG32 GetLock_Att (const char * att, char & oLock );
   static CATLONG32 SetLock_Att (const char * att, char   oLock, const char * type );

   static CATSettingRepository * rep;
   static char * repname;
};
#endif

