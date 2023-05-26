// COPYRIGHT DASSAULT SYSTEMES 1997
//=================================================================
//								   
// CATAdmR
// Basic Include for Administration Representation
//								   
//
//=================================================================
// Usage notes:								   
// This include provides defines for a better understanding
//								   
//=================================================================
//								   
// April  97   JF Buret   Creation
//								   
//=================================================================

#ifndef CATAdmR_h
#define CATAdmR_h

//#include "CATIAV5Level.h"

#define AddCB AddAnalyseNotificationCB
#define RemCB RemoveAnalyseNotificationCB
#define SetVA SetVerticalAttachment
#define SetHA SetHorizontalAttachment

#define CS    CATString
#define CUS   CATUnicodeString
#define CLCUS CATListOfCATUnicodeString
#define CLInt CATListOfInt

#define CTL  CATDlgTopOrLeft
#define CTLR CATDlgTopOrLeftRelative
#define CRB  CATDlgRightOrBottom
#define CRBR CATDlgRightOrBottomRelative
#define CC   CATDlgCenter
#define CCR  CATDlgCenterRelative

#define GetRVFK GetResourceValueFromKey

#ifndef _WINDOWS_SOURCE
#include <stream.h>
#else
#include <io.h>
#endif

//#include "CATIOStream.h"
//#include <unistd.h>

// Bug Tools OPtion : Core Dump a la mode ApplicationFrame.
#ifndef bug_toolsoptions
#define bug_toolsoptions
#endif

#include "CATDlgInclude.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATToken.h"
#include "CATSettingRepository.h"

#endif
