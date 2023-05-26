

// COPYRIGHT DASSAULT SYSTEMES 2000

// NLS services relating to catalog messages

#ifndef CATNLSUtilities_H
#define CATNLSUtilities_H
#include "CATMsg.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATCollec.h"
#include "CATSysErrorDef.h" // HRESULT
#include <stdlib.h>
#include <stdio.h>
 
/**
 * Get the name of the User Interface Language.
 * <br><b>Role</b>: Get the name of the User Interface Language. When installing CATIA, if you choosed to install
 * all the user interface files, and if you did not update later your run-time view with message catalog files
 * corresponding to a language for which CATIA do not deliver any message catalog file, the possible function return
 * values will be:
 * <ul>
 * <li>English</li>
 * <li>French</li>
 * <li>German</li>
 * <li>Italian</li>
 * <li>Japanese</li>
 * <li>Simplified_Chinese</li>
 * <li>Korean</li>
 * </ul>
 * <p><b>Note</b>: About locales and languages in CATIA, you have to know that the locales whose use with CATIA has been
 * validated is stored in the following file, on Windows, for example:
 * <pre>
 *   intel_a\reffiles\NLS\SUPPLANG_V6
 * </pre>
 * The first column of this file contains the name (it is an english name) of the language associated to the locale.
 * The terminology is the same as the one of the sub-folder of (for example on Windows):
 * <pre>
 *    intel_a\resources\msgcatalog
 * </pre>
 * containing the translated messages.</br>
 * The CATIA documentation precises also the locales whose use with CATIA has been validated, in the following
 * documentation:<br>
 * <pre>
 * Infrastructure
 *   CATIA Infrastructure User Guide
 *     Basic Tasks
 *       Starting Version 5
 *         Starting a Session in a Language Other than English on Windows
 *       and
 *         Starting a Session in a Language Other than English on UNIX
 * </pre>
 * <br>
 * CATIA displays messages catalog strings in a User Interface Language. To determine the User Interface Language, CATIA
 * proceeds the following way:
 * <ul>
 * <li>it determines if Tools\Customize\Options\"User Interface Language" precises a User Interface language. 
 * Here, the language appears under the same naming as the first column as the SUPPLANG_V6 file mentioned above.
 * <ul>
 * <li>If the corresponding folder for message catalogs exists in the run-time view (in intel_a\resources\msgcatalog
 * on Windows, for example), then, the User Interface Language precised in the current field will be effectively taken
 * into account</li>
 * <li>otherwise, English is taken</li>
 * </ul>
 * <li>if Tools\Customize\Options\"User Interface Language" is set to "Environment Language (default)"), which is the
 * common case, then, the User Interface Language will be the language associated to the thread locale (language named
 * obtained consulting the first column of the SUPPLANG_V6 file mentioned above)</li>
 * </ul>
 * Nevertheless, if, for example, the "User Interface Language" is "Japanese", (the Japanese folder exists in the
 * run-time view), when a message catalog string must be displayed:
 * <ul>
 * <li>if the Japanese version of the message catalog does not exist in the run-time view (for example because Japanese
 * message catalogs for the current product are not provided), the english version of the message is taken</li>
 * <li>if  the  the Japanese version exists, but the given message is not present in the file (you have to know that,
 * when delivering Service Packs, new message catalog strings are only translated one service pack upon two), the
 * english version of the message is taken</li>
 * </ul>
 * <p>CATIA distinguishes two locale types:   
 * <ul>
 * <li>the thread locale. On Windows, this locale can be set using the the General\"Settings for the current user" field
 * of the "Control Panel"\"Regional Options" window.</br>
 * CATIA uses this locale:
 * <ul>
 * <li>for the appearance of floats ("2.1" in english, "2,1" in french), dates ... in the user interface</li>
 * <li>to access resources linked to the system (fonts for the specification tree and for the messages on Unix...).
 * </br>From the thread locale, CATIA, parsing the SUPPLANG_V6 file, determines the language name associated to the thread
 * locale. This name is used to determine the @href CATRscCatalog files containg resources linked to the system.</li>
 * </ul></li>
 * <li>the locale associated to the User Interface Language. This is the locale used to parse message catalogs
 * files</li>
 * </ul>
 * <p>
 *  @return
 *    The returned User Interface Language. 
 *    <br><b>Lifecycle rules deviation</b>: The caller must not deallocate the return value.
 */
 // Note that, in Dassault Systemes, the "NlsTest" and "DbcsTest" languages are also supported. For the Virtual NLS
 // Environment, see the documentation obtained surfing the folowing way:
 //   http://dsinteraction/
 //     Developer Workshop
 //       Tools Support
 //         Documentation
 //           V5 development tools 
 //             Other tools 
 //               Virtual NLS environment
ExportedByNS0S1MSG extern  void GetUserInterfaceLanguageName(CATString& oLanguage);

/**
 * DSYGetUILocaleNameForHttp.
 * Returns the locale name corresponding to the process's UI language in a format that is suitable to build "Accept-Language" HTTP headers.
 * @param [out] oLocaleName will contain the locale string in case of success.
 * @return S_OK if the session is valid.
 * @return E_FAIL in case of error.
 */
extern "C" {
	ExportedByNS0S1MSG HRESULT DSYGetUILocaleNameForHttp(CATUnicodeString &oLocaleName);
}

/**
 * Get the name of the User Interface Language, old version.
 * <br><b>Role</b>: This function does the same processing as the GetUserInterfaceLanguageName, except that:
 * <ul>
 * <li>in the case of the English language, an empty string is returned</li>
 * <li>in the case of the NlsTest language, the thread UI language is returned</li>
 * <li>in the case of the DbcsTest language, the thread UI language is returned</li>
 * </ul>
 */
ExportedByNS0S1MSG extern const char* ComputeLang ();

/**
 * Get the english name of the language associated to the thread locale.
 * <br><b>Role</b>: Get the name, in english, of the language (first column of the SUPPLANG_V6 file) corresponding to the
 * thread locale. Possible values are:
 * <ul>
 * <li>"" (empty string): English</li>
 * <li>French</li>
 * <li>German</li>
 * <li>Italian</li>
 * <li>Japanese</li>
 * <li>Simplified_Chinese</li>
 * <li>Korean</li>
 * </ul>
 * <p>About locales and languages in CATIA, see the note in @href ComputeLang .
 *  @return
 *    The returned language name. 
 */
ExportedByNS0S1MSG extern  void GetThreadLocaleLanguageName(CATString& oLanguage);

/**
 * Get the name of the language associated to the thread locale in the User Interface Language.
 * <br><b>Role</b>: Get the name of the language (first column of the SUPPLANG_V6 file) corresponding to the
 * thread locale, in the User Interface Language. For example, if the thread locale is the korean locale, and the
 * User Interface Language is the German language, the return value will be "Koreanisch".
 * <p>About locales and languages in CATIA, see the note in @href ComputeLang .
 *  @return
 *    The returned language name. 
 */
// ExportedByNS0S1MSG extern const CATUnicodeString GetThreadLocaleDialogIdentifier();

/**
 * Computes the code page name associated to a language name.
 * <br><b>Role</b>: Computes the code page name (see @href CATCodePage ) associated to a given language name. For
 * example, on Windows, if iLanguage is equal to "Italian", oCodePage will be equal to "1252". 
 * <p>About locales and languages in CATIA, see the note in @href ComputeLang .
 * @param iLanguage
 *   Language name. Possible values are:
 * <ul>
 * <li>English</li>
 * <li>French</li>
 * <li>German</li>
 * <li>Italian</li>
 * <li>Japanese</li>
 * <li>Simplified_Chinese</li>
 * <li>Korean</li>
 * </ul>
 * @param oCodePage
 *   Associated code page name. 
 *   <br>About possible values, see the @href CATCodePage Constructor from a given code page name.
 */
// Note that, in Dassault Systemes, the "NlsTest" and "DbcsTest" languages are also supported.
ExportedByNS0S1MSG extern  void GetLanguageNameCodePage(CATString& iLanguage,CATString& oCodePage);

/**
 * Get the english code page name.
 * <br><b>Role</b>: Get the english code page name (see @href CATCodePage ). 
 * <p>About locales and languages in CATIA, see the note in @href ComputeLang .
 * @param oEnglishCodePageName
 *   English code page name. 
 *   <br>About code page names, depending we are on Windows or Unix, see the @href CATCodePage Constructor from a given
 *   code page name.
 */
ExportedByNS0S1MSG extern  void GetEnglishCodePage(CATString& oEnglishCodePageName);

/**
 * Get, from the integer identification code of a language, the name of the language in the User Interface Language.
 * <br><b>Role</b>: Get, from the integer identification code of a language, the name of the language in the User
 * Interface Language. For example, if the User Interface Language is the German language, and
 * iLanguageIdentificationCode equals to 608 (which corresponds to the Korean language), then, the return value will be
 * "Koreanisch".
 * <p>About locales and languages in CATIA, see the note in @href ComputeLang .
 * @param iLanguageIdentificationCode
 *   Language integer identification code. See the second parameter of @href GetUILanguageList .
 * @param oUILanguageCharacterSetDescribedByThreadLanguageFont
 *   Specifies whether the corresponding language character set is described by the thread language font. 
 *   <br>If, for example, on AIX, the thread locale is en_US, and iLanguageIdentificationCode is equal to 807
 *   (Japanese), the value for this parameter will be 0. This corresponds to the fact that japanese characters cannot
 *   be displayed when the thread locale is the english locale on AIX.
 *   <br><b>Legal values</b>: <tt>0</tt> not described, or <tt>1</tt> described.
 *  @return
 *    Name of the language in the User Interface Language.
 */
ExportedByNS0S1MSG extern const CATUnicodeString GetToolsOptionsUILanguageDialogIdentifier(
                     int iLanguageIdentificationCode,
                     int* oUILanguageCharacterSetDescribedByThreadLanguageFont=NULL);

/**
 * Get the list of values for the "Tools"\"Customize"\"Options"\"User Interface Language" combo.
 * <br><b>Role</b>: Get the list of values for the "Tools"\"Customize"\"Options"\"User Interface Language" combo. This
 * function is called by the "Tools"\"Customize" software. For example, if the following message catalog files are
 * installed:
 * <ul>
 * <li>NlsTest message catalog files</li>
 * <li>DbcsTest message catalog files</li>
 * <li>English message catalog files</li>
 * <li>Japanese message catalog files</li>
 * <li>Korean message catalog files</li>
 * </ul>
 * then, oLanguageIdentificationCode will contain:
 * <pre>
 * 0    : Environment Language (default)
 * 714  : English
 * 807  : Japanese
 * 608  : Korean
 * </pre>
 * <br>About locales and languages in CATIA, see the note in @href ComputeLang .
 * @param oLanguageIdentificationCode
 *   Language identification code list. See the second parameter of @href GetUILanguageList .
 */
// Note that, in Dassault Systemes, the following languages are also supported:
//   718  : NlsTest
//   796  : DbcsTest
ExportedByNS0S1MSG extern void GetToolsOptionsUILanguageSettingsIdentifierList(CATListOfInt& oLanguageIdentificationCode); 

/**
 * Get the list of names of installed User Interface Languages.
 * <br><b>Role</b>: Get the list of names of installed User Interface Languages. The output language list comprises:
 * <ul>
 * <li>the intersection between:
 * <ul>
 * <li>the list obtained adding:
 * <ul>
 * <li>the first supplang column for the current OS</li>
 * <li>NlsTest</li>
 * <li>DbcsTest</li>
 * </ul></li>
 * <li>the CATInstallPath\resources\msgcatalog directory name list (such as "Japanese") containing a General.CATNls
 * file</li>
 * </ul></li>
 * <li>English</li>
 * </ul>
 * <p>About locales and languages in CATIA, see the note in @href ComputeLang .
 * @param oLanguageCount
 *   Language count. 
 * @param ioLanguageIdentificationCode
 *   Language identification code list. Supported language identifiers are linked to an internal algorithm which 
 *   associates a unique integer identification code to a string. Values are comprised between 0 and 10000 . Here are
 *   some integer identification codes:
 *   <pre>
 *   English  : 714
 *   German   : 602
 *   Japanese : 807
 *   </pre>
 *   The ioLanguageIdentificationCode list length is equal to oLanguageCount.
 * @param ioLanguageName
 *   Language names (in english). To a given element of ioLanguageIdentificationCode is associated the corresponding
 *   element of ioLanguageName.
 *   <br>The ioLanguageName list length is equal to oLanguageCount.
 */
// Note that, in Dassault Systemes, the following languages are also supported:
//   718  : NlsTest
//   796  : DbcsTest
ExportedByNS0S1MSG extern void GetUILanguageList(int& oLanguageCount,CATListOfInt& ioLanguageIdentificationCode,
                                                 CATListOfCATString& ioLanguageName);
#endif
