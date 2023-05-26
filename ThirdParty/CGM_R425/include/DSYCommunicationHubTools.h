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
#ifndef __DSYCOMMUNICATIONHUB
#define __DSYCOMMUNICATIONHUB

#include "CATHttp.h"
#include "DSYString.h"

extern "C" ExportedByJS0HTTP int GetDSYCommunicationHubPort();
extern "C" ExportedByJS0HTTP bool IsDSYCommunicationHubOn();
extern "C" ExportedByJS0HTTP int SetDSYCommunicationHubEnv(const CATUnicodeString& iCusPort);
extern "C" ExportedByJS0HTTP HRESULT StartDSYCommunicationHub(CATUnicodeString *iPath=NULL);

#endif 
