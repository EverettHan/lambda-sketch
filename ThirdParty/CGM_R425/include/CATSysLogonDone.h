//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2008                                          *
//*===========================================================================*
//*                                                                           *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation fevrier 2008                                   adt              *
//*===========================================================================*
#ifndef CATSYSLOGONDONE_H
#define CATSYSLOGONDONE_H
#include "JS0SETT.h"

#define LOGOFF_SETTINGS_NO_SAVE 0x00000010
#define LOGOFF_SETTINGS_SAVE	0x00000100
#define LOGOFF_SETTINGS_LOCAL_SAVE	0x00001000
#define LOGOFF_SETTINGS_CLEAN	0x00010000

#define NO_PROVIDER "NO_PROVIDER" //provider name for offline setup with cache directory change.


HRESULT ExportedByJS0SETT CATSysLogonDone(char const * iProviderName=NULL);
HRESULT ExportedByJS0SETT CATSysPrepareLogOff(int iFlag);
HRESULT ExportedByJS0SETT CommitSettings(int iFlag);
HRESULT ExportedByJS0SETT DSYSysPushPLMIdInSession();
bool ExportedByJS0SETT IsSettingsInDBActive();

void InitializeLanguageEnvironment();

#endif
