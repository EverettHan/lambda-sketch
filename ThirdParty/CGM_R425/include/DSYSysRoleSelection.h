#ifndef DSYSysRoleSelection_h
#define DSYSysRoleSelection_h

/*
XXXXXXX  XXX XXX  XXXXXX    XXXXX   XXXXXX    XXXXXX  XXXXXXX  XXXXXX
 XX   X   XX XX    XX  XX  XX   XX   XX  XX   X XX X   XX   X   XX  XX
 XX X      XXX     XX  XX  XX   XX   XX  XX     XX     XX X     XX  XX
 XXXX       X      XXXXX   XX   XX   XXXXX      XX     XXXX     XX  XX
 XX X      XXX     XX      XX   XX   XX XX      XX     XX X     XX  XX
 XX   X   XX XX    XX      XX   XX   XX  XX     XX     XX   X   XX  XX
XXXXXXX  XXX XXX  XXXX      XXXXX   XXX  XX    XXXX   XXXXXXX  XXXXXX


 XXXXX   XX   XX  XXXX     XX    XX
XX   XX  XXX  XX   XX       XX  XX
XX   XX  XXXX XX   XX        XXXX
XX   XX  XX XXXX   XX         XX
XX   XX  XX  XXX   XX         XX
XX   XX  XX   XX   XX  XX     XX
 XXXXX   XX   XX  XXXXXXX    XXXX


XXXXXXX   XXXXX   XXXXXX
 XX   X  XX   XX   XX  XX
 XX X    XX   XX   XX  XX
 XXXX    XX   XX   XXXXX
 XX X    XX   XX   XX XX
 XX      XX   XX   XX  XX
XXXX      XXXXX   XXX  XX


XX   XX    XXXX    XX  XX
XX   XX     XX     XX  XX
XX   XX     XX     XX  XX
 XX XX      XX     XX  XX
 XX XX      XX     XX  XX
  XXX       XX     XX  XX
   X       XXXX     XXXX
*/


#include "WebLogonPanel.h"
#include "CATUnicodeString.h"
#include "CATHttpClient.h"
#include "CATTSLib.h"
#include "CATLib.h"
#include "DSYSysPLMServerInfo.h"
#include "JS0TSSTUBS.h"


#ifdef _WINDOWS_SOURCE
#include "WebLogonPanel.h"
#endif

ExportedByJS0TSSTUBS HRESULT DSYSysSetASecurityContextForPLM1();

#endif
