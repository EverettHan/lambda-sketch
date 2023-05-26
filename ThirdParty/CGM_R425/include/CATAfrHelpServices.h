#ifndef CATAfrHelpServices_H
#define CATAfrHelpServices_H
#include "CATAfrFoundation.h"
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2012
//------------------------------------------------------------------------------
// fw AfrFoundation
// CATAfrHelpAndDoc.m
// protected
//------------------------------------------------------------------------------

#include "IUnknown.h" // HRESULT definition under UNIX
#include "CATBoolean.h"

class CATString;
class CATUnicodeString;
class CATDialog;


//---------------------------------------------------------------------------
/**
 * Displays update badge in help menu.
 * @If updateBadgeflag =1 then show new update badge icon
 * @If updateBadgeflag = 0 then show old help menu icon
 *
 */
ExportedByCATAfrFoundation
void CATAfrDisplayUpdateBadge(const int  updateBadgeflag);

//---------------------------------------------------------------------------
/**
 * Displays contextual help.
 * <br><b>Role</b>: This function parses the LongHelpId and displays the expected contextual help.
 * @param iLongHelpId
 *  Old Expected format: iLongHelpId = "[MainHelpId][:MHURL:MainHelpPath][:EHURL:EmbedHelpPath][:DOCM:DocModule]"
 *  New Expected format: iLongHelpId = ":HelpRsc:[HelpRscValue][:ID:ComponentID][:WHURL:WebHelpPath][:PHURL:PanelHelpPath]"
 *   HelpRscValue and ComponentID are used for alternative topic paths depending on the current workbench.
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrDisplayLongHelp (const CATUnicodeString & iLongHelpId);

//---------------------------------------------------------------------------
/**
 * Displays contextual help associated to WebHelp path
 * <br><b>Role</b>: This function displays the contextual help associated to WebHelp
 * in the web help portal.
 * @param iWebHelp
 *  Web Help Topic Path
 * @param iHelpRscValue
 *  Resource file name for possible change depending on the current workbench
 * @param iComponentID
 *  Component ID for possible change depending on the current workbench
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrDisplayWebHelp (const CATUnicodeString & iWebHelp, const CATUnicodeString & iHelpRscValue, const CATUnicodeString & iComponentID);

//---------------------------------------------------------------------------
/**
 * Displays contextual help associated to PanelHelp path
 * <br><b>Role</b>: This function displays the contextual help associated to PanelHelp
 * in the Panel Help window.
 * @param iPanelHelp
 *  Panel Help Topic path
 * @param iWebHelp
 *  Web Help Topic path used for More Help information
 * @param iHelpRscValue
 *  Resource file name for possible change depending on the current workbench
 * @param iComponentID
 *  Component ID for possible change depending on the current workbench
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrDisplayPanelHelp (const CATUnicodeString & iPanelHelp, const CATUnicodeString & iWebHelp, const CATUnicodeString & iHelpRscValue, const CATUnicodeString & iComponentID);

//---------------------------------------------------------------------------
/**
 * Displays contextual help linked to MainHelpId
 * <br><b>Role</b>: This function displays the contextual help associated to MainHelpId (previously known as LongHelpId)
 * in the standard V6 documentation frame.
 * @param iMainHelpId
 *  Main Help Topic LongHelpId
 * @param iDocModule
 *  DocModule for redirection
 * @return
 * Returns always S_OK.
 */
HRESULT CATAfrDisplayMainHelpId (const CATUnicodeString & iMainHelpId, const CATUnicodeString & iDocModule);

//---------------------------------------------------------------------------
/**
 * Displays contextual help linked to MainHelp path
 * <br><b>Role</b>: This function displays the contextual help associated to MainHelpPath
 * in the SolidWorks V6 frame.
 * @param iMainHelp
 *  Main Help Topic path
 * @param iDocModule
 *  DocModule for redirection
 * @return
 * Returns always S_OK.
 */
HRESULT CATAfrDisplayMainHelp (const CATUnicodeString & iMainHelp, const CATUnicodeString & iDocModule);

//---------------------------------------------------------------------------
/**
 * Displays contextual help linked to EmbedHelp path
 * <br><b>Role</b>: This function displays the contextual help associated to EmbedHelp
 * in the Embedded Help window.
 * @param iEmbedHelp
 *  Embedded Help Topic path
 * @return 
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> The Embedded Help window opens if needed and displays contextual help associated to EmbedHelp
 *   <dt> <tt>S_FALSE</tt> <dd> The Embedded Help window already displayed contextual help associated to EmbedHelp
 *   </dl>   
 */
HRESULT CATAfrDisplayEmbeddedHelp (const CATUnicodeString & iEmbedHelp);

//---------------------------------------------------------------------------
/**
 * Decodes a LongHelpId
 * <br><b>Role</b>: This function parses a LongHelpId to retrieve coded information
 * @param iLongHelpId
 *  old-format or new format LongHelpId
 *  <br>old format: MainHelpId:MHURL:MainHelp:EHURL:EmbedHelp:DOCM:DocModule
 *  <br>new format: :HelpRsc:HelpRscValue:ID:ComponentID:WHURL:WebHelp:PHURL:PanelHelp
 * @param oMainHelpId
 *  Simple LongHelpId value
 * @param oMainHelp
 *  MainHelp value
 * @param oEmbedHelp
 *  EmbedHelp value
 * @param oDocModule
 *  DocModule value
 * @param oHelpRscValue
 *  Resource file name for possible redirection
 * @param oComponentID
 *  Component ID for possible redirection
 * @param oWebHelp
 *  WebHelp value
 * @param oPanelHelp
 *  PanelHelp value
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrDecodeLongHelpId (const CATUnicodeString & iLongHelpId,
                                CATUnicodeString & oMainHelpId,
                                CATUnicodeString & oMainHelp,
                                CATUnicodeString & oEmbedHelp,
                                CATUnicodeString & oDocModule,
                                CATUnicodeString & oHelpRscValue,
                                CATUnicodeString & oComponentID,
                                CATUnicodeString & oWebHelp,
                                CATUnicodeString & oPanelHelp);

//---------------------------------------------------------------------------
/**
 * Gets Web Help Topic for current workbench
 * <br><b>Role</b>: This function gets WebHelp topic relative path for current workbench.
 * @param iWebHelp
 *  Default Web Help Topic path
 * @param iHelpRscValue
 *  Resource file name for possible redirection
 * @param iComponentID
 *  Component ID for possible redirection
 * @param oWbWebHelp
 *  Web Help Topic path for current workbench
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetWbWebHelp (const CATUnicodeString & iWebHelp,
                            const CATUnicodeString & iHelpRscValue,
                            const CATUnicodeString & iComponentID,
                            CATUnicodeString & oWbWebHelp);

//---------------------------------------------------------------------------
/**
 * Gets Panel Help Topic for current workbench
 * <br><b>Role</b>: This function gets PanelHelp topic relative path for current workbench.
 * @param iPanelHelp
 *  Default Panel Help Topic path
 * @param iHelpRscValue
 *  Resource file name for possible redirection
 * @param iComponentID
 *  Component ID for possible redirection
 * @param oWbPanelHelp
 *  Panel Help Topic path for current workbench
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetWbPanelHelp (const CATUnicodeString & iPanelHelp,
                              const CATUnicodeString & iHelpRscValue,
                              const CATUnicodeString & iComponentID,
                              CATUnicodeString & oWbPanelHelp);

//---------------------------------------------------------------------------
/**
 * Gets URL to display for a topic path
 * <br><b>Role</b>: This function gets PanelHelp topic relative path for current workbench.
 * @param iHelpPath
 *  Topic path
 * @param oHelpURL
 *  URL to display
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetURLFromPath (const CATUnicodeString & iHelpPath,
                              CATUnicodeString & oHelpURL);

//---------------------------------------------------------------------------
/**
 * Gets LongHelpId from current tooltip
 * <br><b>Role</b>: This function gets LongHelpId associated with command or control under a displayed tooltip, if any.
 * @param oTooltipHelpId
 *  LongHelpId
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetTooltipHelpId (CATUnicodeString & oLongHelpId);

//---------------------------------------------------------------------------
/**
 * Gets LongHelpId from resources
 * <br><b>Role</b>: This function gets LonghelpId in resources.
 * @param iCatalogName
 *  Catalog file name
 * @param iId
 *  Id 
 * @param oTooltipHelpId
 *  LongHelpId
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> LongHelpId found
 *   <dt> <tt>S_FALSE</tt> <dd> LongHelpId not found
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetRscHelpId (const CATString & iCatalogName, const CATUnicodeString & iId, CATUnicodeString & oLongHelpId);

//---------------------------------------------------------------------------
/**
 * Registers transient LongHelpId
 * <br><b>Role</b>: This registers the parameter as the LongHelpId used if contextual help (F1) is triggered.
 * @param iLongHelpId
 *  LongHelpId
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrAddContextualHelp (const CATUnicodeString & iLongHelpId);

//---------------------------------------------------------------------------
/**
 * Unregisters transient LongHelpId
 * <br><b>Role</b>: This unregisters the parameter as the LongHelpId used if contextual help (F1) is triggered.
 * @param iLongHelpId
 *  LongHelpId
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrRemoveContextualHelp (const CATUnicodeString & iLongHelpId);

//---------------------------------------------------------------------------
/**
 * Registers transient LongHelpId
 * <br><b>Role</b>: This uses the LongHelpId got in resources if contextual help (F1) is triggered.
 * @param iCatalogName
 *  Catalog file name
 * @param iId
 *  Id 
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> LongHelpId registered
 *   <dt> <tt>S_FALSE</tt> <dd> LongHelpId not found
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrAddContextualHelp (const CATString & iCatalogName, const CATUnicodeString & iId);

//---------------------------------------------------------------------------
/**
 * Removes contextual help for a dialog object
 * <br><b>Role</b>: This removes the LongHelpId got in resources if contextual help (F1) is triggered.
 * @param iCatalogName
 *  Catalog file name
 * @param iId
 *  Id 
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrRemoveContextualHelp (const CATString & iCatalogName, const CATUnicodeString & iId);

//---------------------------------------------------------------------------
/**
 * Adds contextual help for a dialog object
 * <br><b>Role</b>: This uses the LongHelpId defined for the dialog object if contextual help (F1) is triggered.
 * @param iDialog
 *  The Dialog component
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> LongHelpId registered
 *   <dt> <tt>S_FALSE</tt> <dd> LongHelpId not found
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrAddContextualHelp (CATDialog * iDialog);

//---------------------------------------------------------------------------
/**
 * Removes contextual help for a dialog object
 * <br><b>Role</b>: This removes the LongHelpId defined for the dialog object if contextual help (F1) is triggered.
 * @param iDialog
 *  The Dialog component
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrRemoveContextualHelp (CATDialog * iDialog);

//---------------------------------------------------------------------------
/**
 * Displays URL (without parameters) in a web browser.
 * <br><b>Role</b>: This function opens a web browser to display the URL.
 * @param iURL
 *  URL
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrDisplayURL (const CATUnicodeString & iURL);

//---------------------------------------------------------------------------
/**
* Displays URL (with parameters) in a web browser.
* <br><b>Role</b>: This function opens a web browser to display the URL.
* @param iURL
*  URL
* @return
* Returns always S_OK.
*/
ExportedByCATAfrFoundation
HRESULT CATAfrDisplayURLWithParams (const CATUnicodeString & iURL);

//---------------------------------------------------------------------------
/**
 * Gets Help Home Path
 * <br><b>Role</b>: This function gets Full Path for Help (including topic to display and parameters).
 * @param iHelpHomeLangPath
 *  Online Help Home Path (including Language folder)
 *  <br>Example: http://media.3ds.com/support/documentation/product/V6R2013/en/English
 * @param iContextualHelpTopic
 *  Contextual Help topic to display
 * @param iAdditionalParameters
 *  Additional parameters (ex "&wbcontext=xxx")
 * @param oHelpFullPath
 *  Full Help Path (including topic to display and parameters)
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetHelpFullPath (const CATUnicodeString & iHelpHomeLangPath,
                               const CATUnicodeString & iContextualHelpTopic,
                               CATUnicodeString & iAdditionalParameters,
                               CATUnicodeString & oHelpFullPath);

//---------------------------------------------------------------------------
/**
 * Gets Help Root Path
 * <br><b>Role</b>: This function gets Root Path for Help.
 * @param oHelpRootPath
 *  Help Root Path
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetHelpRootPath (CATUnicodeString & oHelpRootPath);

//---------------------------------------------------------------------------
/**
 * Gets Help Home Path
 * <br><b>Role</b>: This function gets Home Path for Help (before Language folder).
 * @param oHelpHomePath
 *  Help Home Path (before Language folder)
 * @param oHelpHomeLangPath
 *  Help Home Path (including Language folder)
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetHelpHomePath (CATUnicodeString & oHelpHomePath, CATUnicodeString & oHelpHomeLangPath);

//---------------------------------------------------------------------------
/**
 * Gets Local Help Root Path
 * <br><b>Role</b>: This function gets Root Path for Local Help.
 * @param oLocalHelpRootPath
 *  Local Help Root Path
 *  <br>Example: X:\R214rel\BSFDOCEN\Doc.
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetLocalHelpRootPath (CATUnicodeString & oLocalHelpRootPath);

//---------------------------------------------------------------------------
/**
 * Gets Local Help Home Path
 * <br><b>Role</b>: This function gets Home Path for Local Help.
 * @param oLocalHelpHomePath
 *  Local Help Home Path (including Language folder)
 *  <br>Example: X:\R214rel\BSFDOCEN\Doc\English.
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetLocalHelpHomePath (CATUnicodeString & oLocalHelpHomePath);

//---------------------------------------------------------------------------
/**
 * Gets Online Help Root Path
 * <br><b>Role</b>: This function gets Root Path for Online Help.
 * @param oOnlineHelpRootPath
 *  Online Help Root Path
 *  <br>Example: http://media.3ds.com/support/documentation/product.
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetOnlineHelpRootPath (CATUnicodeString & oOnlineHelpRootPath);

//---------------------------------------------------------------------------
/**
 * Gets Online Help Home Paths
 * <br><b>Role</b>: This function gets Home Path for Online Help
 * @param oOnlineHelpHomePath
 *  Online Help Home Path (before Language folder)
 *  <br>Example: http://media.3ds.com/support/documentation/product/V6R2013/en.
 * @param oOnlineHelpHomeLangPath
 *  Online Help Home Path (including Language folder)
 *  <br>Example: http://media.3ds.com/support/documentation/product/V6R2013/en/English.
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetOnlineHelpHomePaths (CATUnicodeString & oOnlineHelpHomePath, CATUnicodeString & oOnlineHelpHomeLangPath);

//---------------------------------------------------------------------------
/**
 * Gets Language used for Help
 * <br><b>Role</b>: This function gets the Language used for Help depending on the availability of the language chosen by the user on the current version.
 * @param oHelpLanguage
 *  Online Help Language
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetHelpLanguage (CATUnicodeString & oHelpLanguage);

//---------------------------------------------------------------------------
/**
 * Gets Context Scope
 * <br><b>Role</b>: This function gets the context scope to filter User Assistance Table of Content.
 * @param oContextScope
 *  Context scope (cloud, swx, onpremise, all)
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetContextScope (CATUnicodeString & oContextScope);

//---------------------------------------------------------------------------
/**
 * Gets SolidWorks Web Help Portal Root Path
 * <br><b>Role</b>: This function gets URL to SolidWorks Portal to display Web Help.
 * @param oSWXWebHelpRootPath
 *  SolidWorks Web Help Portal Root Path
 *  <br>Example: https://help.3ds.com/HelpDS.aspx.
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetSWXWebHelpRootPath (CATUnicodeString & oSWXWebHelpRootPath);

//---------------------------------------------------------------------------
/**
 * Gets SolidWorks WebHelp Home Path
 * <br><b>Role</b>: This function gets SolidWorks WebHelp Home Path.
 * @param oSWXWebHelpHomePath
 *  SolidWorks WebHelp Home Path (including Product, Version and Language parameters)
 *  <br>Example: https://help.3ds.com/HelpDS.aspx?P=11&V=2016x&L=English.
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetSWXWebHelpHomePath (CATUnicodeString & oSWXWebHelpHomePath);

//---------------------------------------------------------------------------
/**
 * Gets SolidWorks Web Help Product number
 * <br><b>Role</b>: This function gets Product value used in SOLIDWORKS Portal for Web Help.
 * @param oProductPath
 *  SolidWorks Web Help Product
 *  <br>Example: 8 for SolidwWorks, 9 for Embed Help, 11 for DSDOC
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetSWXWebHelpProduct (CATUnicodeString & oProductPath);

//---------------------------------------------------------------------------
/**
 * Returns whether help repository is local or not
 * <br><b>Role</b>: This function returns whether help repository is local or online.
 * @param iCheckProxy
 *  Check whether Proxy file on help.3ds.com is reachable
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> Local Help repository
 *   <dt> <tt>S_FALSE</tt> <dd> Online Help repository
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrIsLocalHelp (CATBoolean iCheckProxy=TRUE);

//---------------------------------------------------------------------------
/**
 * Returns whether cloud context must be used or not
 * <br><b>Role</b>: This function returns whether cloud context must be used.
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> cloud context
 *   <dt> <tt>S_FALSE</tt> <dd> not cloud context
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrIsCloudContext ();

//---------------------------------------------------------------------------
/**
 * Returns whether SWX context must be used or not
 * <br><b>Role</b>: This function returns whether SWX (Solidworks) context must be used.
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> SWX context
 *   <dt> <tt>S_FALSE</tt> <dd> not SWX context
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrIsSWXContext ();

//---------------------------------------------------------------------------
/**
 * Returns whether SolidWorks Web Help is activated or not
 * <br><b>Role</b>: This function returns whether SolidWorks Web Help should be used instead of V6 documentation frame.
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> SolidWorks Web Help
 *   <dt> <tt>S_FALSE</tt> <dd> V6 documentation frame
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrIsSWXWebHelp ();

//---------------------------------------------------------------------------
/**
 * Returns whether help repository is local or not
 * <br><b>Role</b>: This function returns whether help repository is local or online.
 * @return
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> CommonId2url.CATNls Mapping file found
 *   <dt> <tt>S_FALSE</tt> <dd> CommonId2url.CATNls Mapping file not found
 *   </dl>   
 */
ExportedByCATAfrFoundation
HRESULT CATAfrCheckMappingFile (CATUnicodeString & iLang,
                                CATUnicodeString & iHelpHomePath);

//---------------------------------------------------------------------------
/**
 * Gets current tutorial
 * <br><b>Role</b>: This function gets the name of the scenario if a tutorial is being played.
 * @param oScenario
 *  The name of the scenario file (without extension)
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetCurrentTutorial (CATUnicodeString & oScenario);

//---------------------------------------------------------------------------
/**
 * Gets formatted resource from new help resources or from resource file
 * <br><b>Role</b>: This function gets resources taking into account new help resources.
 * @param iCatalogName
 *  Name of the command header resource file
 * @param iId
 *  Identifier of the command header
 * @param iHelpKey
 *  Name of the key (Title, ShortHelp or LongHelp)
 * @param ioValue
 *  resource value (you can initialize it with a default value if it does exist)
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetHelpResource (const CATString & iCatalogName, const CATString & iId, const CATString & iHelpKey, CATUnicodeString & ioValue);

//---------------------------------------------------------------------------
/**
 * Formats Help Text Resources
 * <br><b>Role</b>: This function parses the text and removes desireless space characters or tabs.
 * @param ioText
 *  String to be formatted
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrFormatHelpText (CATUnicodeString & ioText);

//---------------------------------------------------------------------------
/**
 * Formats Panel Help URL
 * <br><b>Role</b>: This function removes useless parameters in oder to display plain topic.
 * @param ioURL
 *  String to be formatted
 * @return
 * Returns always S_OK.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrFormatPanelHelpURL (CATUnicodeString & ioURL);

//---------------------------------------------------------------------------
/**
* Gets Help preference for the current workbench
* <br><b>Role</b>: This function returns WebHelp or PanelHelp defined for the current workbench.
* Only one of both should be defined. If both are defined, WebHelp is ignored. 
* @param ioWebHelp
*  WebHelp associated with the current workbench
* @param ioPanelHelp
*  PanelHelp associated with the current workbench
* @return
* Returns always S_OK.
*/
ExportedByCATAfrFoundation
HRESULT CATAfrGetWbHelpPreference (CATUnicodeString & ioWebHelp, CATUnicodeString & ioPanelHelp);

//---------------------------------------------------------------------------
/**
* Push compass service XML content
* <br><b>Role</b>: This function must be called to push MyApps XML content to User Assistance.
* @param iAppXmlContent
*  The XML content as a string
* @return
* Returns always S_OK.
*/
ExportedByCATAfrFoundation
HRESULT CATAfrHelpPushAppXmlContent (const CATUnicodeString & iAppXmlContent);

//---------------------------------------------------------------------------
/**
* Push appsForUser service Json content
* <br><b>Role</b>: This function must be called to push MyApps Json content to User Assistance.
* @param iAppJsonContent
*  The Json content as a string
* @return
* Returns always S_OK.
*/
ExportedByCATAfrFoundation
HRESULT CATAfrHelpPushAppJsonContent (const CATUnicodeString & iAppJsonContent);

#endif
