#ifndef CATEnvironmentStatus_H
#define CATEnvironmentStatus_H

// CATIA Version 5 Release 1 Framework ApplicationFrame
// Copyright Dassault Systemes 1998
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
#include "LicensingFR.h"
#include "CATAdmR.h"
#include "CATLib.h"

#ifdef _WINDOWS_SOURCE
#define USERDEFAULT 	"USERPROFILE"
#define PATHS_DELIMITER	";"
#define DIR_DELIMITER "\\"
#define DROIT_W 	_S_IWRITE
#define DROIT_X 	_S_IEXEC
#define DROIT_R 	_S_IREAD
#else
#define USERDEFAULT 	"HOME"
#define PATHS_DELIMITER	":"
#define DIR_DELIMITER "/"
#define DROIT_W 	S_IWUSR
#define DROIT_R 	S_IRUSR
#define DROIT_X  	S_IXUSR
#endif


class ExportedByLicensingFR CATEnvironmentStatus
{
   public:

   CATEnvironmentStatus ( );
   ~CATEnvironmentStatus ( );

   typedef enum 
   {
      GoodEnvironment          = 1<<0,
      NoEnvironment            = 1<<1, 
      BadEnvironment           = 1<<2, 
      BadUserSettingDir        = 1<<3,
      NoRefSetting             = 1<<4,
      BadRefSettingDirAsAdmin  = 1<<5,
      BadRefSettingConcat      = 1<<6
   } EnvironmentStatus;

   EnvironmentStatus CheckEnvironment ( CUS & Env );

};

#endif
