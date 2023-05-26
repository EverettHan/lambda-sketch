//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1996                                          
//===========================================================================
//                                                                           
//  CATSettingRepository                                                     
//                                                                           
//  Usage Notes: Environment Managing                                                 
//===========================================================================
//  Creation decembre 1996                                 adt              
//===========================================================================
#ifndef __CATSETTINGENVMGR
#define __CATSETTINGENVMGR

#include "CATLib.h"
#include "JS0SETT.h"
#include "CATSysTSListOfUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATGetEntryPoint.h"
#include "DSYSettingsCache.h"
#ifdef _WINDOWS_SOURCE
#define SEPAR ";"
#define DIR_SEPAR '\\'
#define DIRSEPAR "\\"
#else
#define DIR_SEPAR '/'
#define DIRSEPAR "/"
#define SEPAR ":"
#endif


#define DEFAULT_ENVNAME "DefaultEnv"



//--------------------------------------------------------------------------
class ExportedByJS0SETT  CATSettingEnv
{

public:
  //----------------
  // Constructors 
  //----------------
  CATSettingEnv(); 
  CATSettingEnv(const char* iPath,char iMode=0,CATUnicodeString * iEnvName=NULL,DSYSettingsCache * piCacheManager=NULL);
  CATSettingEnv(char iMode,CATUnicodeString & iEnvName);
  //-----------
  //Destructor
  //------------
  virtual ~CATSettingEnv();

  char ** _String;
  int _Nb;
  CATUnicodeString _envName;
  DSYSettingsCache * _pCacheManager;
 
  char  _mode;
  static int InitEnv( CATUnicodeString & iEnvName,char iMode,char &oMode,DSYSettingsCache * pCacheMan, CATSettingEnv *&oRef, CATSettingEnv *&oUser); 
  HRESULT CheckHierarchy();   			
  static HRESULT ReadEnvInfo(CATUnicodeString & oProjectId,CATUnicodeString & oRoleId,CATUnicodeString & oOrgId, CATUnicodeString & oPLMLoginUserID, CATUnicodeString & oPLMLoginUserName);
  
   
};

#endif 
