
///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT DASSAULT SYSTEMES  2000                                         //
// ========================================================================= //
// CATCompanionLauncher:                                                     //
// Launch Companion from CATIA Desktop.                                      //
//                                                                           //
// ========================================================================= //
// Usage Notes:                                                              //
// This class can not be directly allocated, Launch Companion with           //
// static method: Launch(...).                                               //
//                                                                           //
// ========================================================================= //
// Used for Companion Authoring Toolkit.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////


#ifndef _CAT_Companion_Launcher_H
#define _CAT_Companion_Launcher_H

#include "CATUnicodeString.h"
#include "CATMsgCatalog.h"
#include "CATBoolean.h"

#include "CATAfrCompanion.h"

class CATSrvPlugInCommunication;

class ExportedByCATAfrCompanion CATCompanionLauncher
{
public:
	boolean                       Launch( CATUnicodeString longHelpId, boolean force );
	void                          Launch();
	static CATCompanionLauncher*  getCompanionLauncher();
  static CATBoolean             CheckWLSLocation(const CATUnicodeString& iWLSPath);
  
protected:
	CATCompanionLauncher();
	boolean                       isCompanionRunning();
  
private:
	static CATCompanionLauncher*  _launcher;
  
	boolean                       _locationOK;
	boolean                       _id2urlOK;
	boolean                       _httpMode;
	boolean                       _docFirst;

	CATSrvPlugInCommunication*    _BBConnection;
    
	CATUnicodeString              _userPath;
	CATUnicodeString              _WLSLocation;
	CATUnicodeString              _docsURL;
	CATMsgCatalog                 _MsgCatalog;
};

// --------------------------------------------------------------------------
//                             USEFULL CONSTANTS
// --------------------------------------------------------------------------

#ifndef NULL
#define NULL  0
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE  0
#endif

#ifndef CATVARIABLES_PATH
#define CATVARIABLES_PATH "Software\\DASSAULT SYSTEMES\\CATVariables"
#endif

#ifdef _WINDOWS_SOURCE
    #define DIR_DELIMITER		"\\"
#else
    #define DIR_DELIMITER		"/"
#endif

#endif
