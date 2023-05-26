// COPYRIGHT DASSAULT SYSTEMES 1997
//===========================================================================
// CATHelpIdToURL.h:
//===========================================================================
// Jul. 97  Creation                                     AVE
// Nov. 97  Generated HTML help proxy file             AVE
//===========================================================================
#ifndef _CATHelpIdToURL_h
#define _CATHelpIdToURL_h

//===========================================================================
//                      IMPORTED DECLARATIONS
//===========================================================================

//___________ Declaration for Windows
#include "CATAfrFoundation.h"

//___________ Definition of CATMaxPathSize constant
#include "CATLib.h"

#include "CATListOfCATUnicodeString.h"
#include "CATListPV.h"
#include "CATMsgCatalog.h"
#include "CATCallbackManager.h"

// Forward declarations
class CATUnicodeString;
//class CATMsgCatalog;

/**
 *  CATHelpIdToURL is the class used to translate any long help identifier
 *  into the URL correponding to the HTML help page.
**/
class ExportedByCATAfrFoundation CATHelpIdToURL
{
public:
  
  /**
   * Returns the URL associated to a given long help identifier.
   * @param op_URL pointer to the help page URL, on success ;
   *        undefined otherwise. This string must be deallocated
   *        using <code>delete</code> when it is not longuer used.
   * @param iLongHelpId the long help identifier.
   * @param iDocModule the Documentation guide targeted.
   * @return 0 on success, and non-zero on failure.
   **/
  static int GetURL (CATUnicodeString *& op_URL,
                     const CATUnicodeString & iLongHelpId,
                     const char * iDocModule = "",
                     const char * iKey = "DocumentMap.Name");

  /**
   * Intializes HTML help proxy files. 
  **/
  static int InitializeProxyFiles();

  /**
   * Generates the HTML help proxy files which will show the help 
   * windows with help body corresponding to the current contextual
   * help ID.
   * @param iHtmlDocPath Path of the HTML documents base directory. 
   * @param iFileName Path (relative to iHtmlDocPath) of the HTML help body file.
   * @param iDocModule  Doc module to use for multi-guides topics
   * @return 0 if everything worked fine.
   **/
  static int GenerateHelpProxyFiles(const CATUnicodeString& iHtmlDocsPath,
                                    const CATUnicodeString& iFileName,
                                    const char * iDocModule="");
  
  /** Removes the HTML help proxy file. */
  static void RemoveHelpProxyFiles();
  
  /** Indicates Panel Help is under construction. */
  static void SetPanelHelp ();
  
  /** Indicates App Help is under construction. */
  static void SetAppHelp ();
  
  /**
   * Deallocates memory used by the URL mapper. This method should be called when
   * contextual help is no longuer needed, i.e., when CATIA terminates.
   **/
  static void FreeMapper();
  
  /** Retrieves/Set the base path for documentation file tree. */
  static CATUnicodeString GetCATDocViewPath();
  static int SetCATDocViewPath(CATUnicodeString&);
  static int CheckCATDocViewPath(CATUnicodeString& path);
  
  // To enable contextual help on "Undefined" commands :
  static void RegisterHelpId (CATUnicodeString & id);
  static void EmptyRegisteredHelpId();
  static void UnregisterHelpId (CATUnicodeString & id);
  static CATUnicodeString & GetRegisteredHelpId ();
  static void DispatchHelpIdChanged ();
  
  static CATUnicodeString ComputeDocumentationLang();

  /** @nodoc */
  CATDeclareCBEvent (HELP_ID_CHANGED);

private:

  static HRESULT LoadCatalogAndSearchKey(CATUnicodeString& ioMapFile, const CATUnicodeString& iLongHelpId, CATUnicodeString& oFileName);
  
  static CATUnicodeString GetMappingFile (CATUnicodeString, CATUnicodeString);
  
  /** Pointer to the mapping table implementation */
  static CATMsgCatalog * MapTable;
  
  /** base documentation file tree */
  static CATUnicodeString CATDocViewPath;
  
  /** Path of the generated HTML help proxy files. */
  static char m_GeneratedProxyPathForPanelHelp[CATMaxPathSize];
  static char m_GeneratedProxyPathForWebHelp[CATMaxPathSize];
  static char m_GeneratedProxyPathForAppPanelHelp[CATMaxPathSize];
  static char m_GeneratedProxyPathbisAppWebHelp[CATMaxPathSize];

  /** Variable used to determine whether we are using the      **/
  /** default language though a current language is specified  **/
  static int defaultLanguageUsed;

  /** List of help ids registered by undefined commands. */
  static CATListOfCATUnicodeString *RegisteredIds;
  /** List of editors where help ids have been registered. */
  static CATListPV *RegisteredEditors;

  static CATUnicodeString LastLoadedCatalog;
};

#endif 
