#ifndef CATEnvironmentNLSInformation_H
#define CATEnvironmentNLSInformation_H

#include "CATUnicodeChar.h"
#include "NS0S3STR.h"

// COPYRIGHT DASSAULT SYSTEMES 2001

/**
* Class to get NLS information about the environment.
*/
class ExportedByNS0S3STR CATEnvironmentNLSInformation 
{

 public :

// Get NLS information about the Windows environment.
// Usage: Protection against a partial support of "Windows 2000 Professional MultiLanguage version". 
 static void sGetWindowsInformation (
          int& oOSType,                      /* 0:Unix, 1:Windows .
                                                The remaining arguments are interesting only on 
                                                Windows. */
          int& oWindowsProfessional,         /* 0:Windows 95-98, Windows XP Starter Edition, Windows XP Home Edition ,
                                                  Windows XP Media Center Edition , Windows Vista Starter ,
                                                  Windows Vista Home Basic, Windows Vista Home Premium , 
                                                  Windows Vista Business 
                                                1:Windows NT-2000
                                                2:Windows XP Professional Edition
                                                3:Windows Vista Enterprise or Windows Vista Ultimate .
                                                This output argument is valuated only if oOSType
                                                equals to 1 */
          int& oNewWindowsProfessional,      /* 0:Windows NT 
                                                1:level superior to Windows NT (Windows 2000, 
                                                  Windows XP or Windows Vista)
                                                This output argument is valuated only if 
                                                oWindowsProfessional equals to 1 */   
          int& oMultiLanguageVersion,        /* 0: localized version , 1: multi-language version
                                                This output argument is valuated only if 
                                                oNewWindowsProfessional equals to 1.
                                                The remaining arguments are interesting only if
                                                the Windows version is multi-language */   
          unsigned short& oSystemUILanguage, /* LANGID of the System UI language. 
                                                For information, the System UI language cannot
                                                be changed, even under a Windows multi-language
                                                version */
          unsigned short& oUserUILanguage,   /* LANGID of the User UI language. 
                                                For information, the User UI language can be 
                                                changed on Windows multi-language versions only */
          int& oUserUILanguageAndSystemUILanguageEquality 
                                             /* 1: the user UI language is equal to the system UI
                                                   language
                                                0: the user UI language is not equal to the system
                                                   UI language */
                                    );      
};
#endif 
