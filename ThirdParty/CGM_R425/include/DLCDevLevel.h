/** ******************************************************************************** **/
/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/** ******************************************************************************** **/
/* -*-c++-*- */
//
// @quickReview YWE 19:03:21 ExchangeChannel project
// @quickReview YWE 15:03:31 LoginTicket retrofit at R216 level
//
// COPYRIGHT DASSAULT SYSTEMES 2004
//===========================================================================
// Usage Notes:   
//===========================================================================
// November 2004   Creation                  YWE 
// DataLifeCycle Development flags
// R15 Initilisation
//
// YWE-2017.12-HL_F076822 - Associated Context removal(AssociatedContextRemoval BT flag)
// YWE-2021.06-Move DesignWorkspace/DWS code under R424 PLMBATCHDWS buildTime Flag
//===========================================================================

#ifndef DLCDevLevel_h
#define DLCDevLevel_h


#include "CATUnicodeString.h"
#include "CATGetEnvValue.h"
#include "CATLibEx.h"     // CATIALevelInfo - DO NEVER REMOVE IT ELSE NOTHING WILL WORK ANYMORE!
#include "CATIAV5Level.h" //                - DO NEVER REMOVE IT ELSE NOTHING WILL WORK ANYMORE!
#include "ExportedByDataAdmin.h"

#ifndef CATIAR424 // Level to be synchronized with similar PLMBATCHDWS definition in DLCDevLevel.h CATIAdpPLMBatchContext.h
#define PLMBATCHDWS 
#endif

#ifdef CATIAR422 // 
#define ExchangeChannel 
//#define COEXExchangeChannel - Do not activate - need more specs & integrations
#endif

#ifdef CATIAR420 // #ifdef CATIAR421
//#define AssociatedContextRemoval 
#endif

#undef PLMBatch_Cyrilic
#ifdef CATIAR421 // PLMBatch support Cyrilic 
#define PLMBatch_Cyrilic 
#endif

#undef Keep_ObjectNamingCusto
#ifndef CATIAR420 // Code Clean Up - Remove deprecated UI for Object naming configuration 
#define Keep_ObjectNamingCusto 
#endif

#ifndef IR711889 // for XPDM PCS and Object report improvment activation
#define IR711889  
#endif

// Definition of SingleCode activations
// ------------------------------------
#undef DLC_ODTAttributeMappingActive
#ifdef CATIAR217 // ODT ATTRIBUTE MAPPING_LEVEL_AVAILABILITY
#define DLC_ODTAttributeMappingActive
#endif

#undef DLC_ScaleActive
#ifdef CATIAR216 // SCALE_LEVEL_AVAILABILITY
#define DLC_ScaleActive
#endif

#undef HL_F045947
#ifdef CATIAR417 // SCALE_CONVERSION_AVAILABILITY
#define HL_F045947
#endif

#undef DLC_LoginTicketActive
#ifdef CATIAR216 // LoginTicket_LEVEL_AVAILABILITY
#define DLC_LoginTicketActive
#endif

#undef DLC_V5NativeActive
#ifdef CATIAR216 // V5Native_LEVEL_AVAILABILITY
#define DLC_V5NativeActive
#endif

#undef DLC_ToolBarActive
#ifdef CATIAR215 // TOOLBAR_LEVEL_AVAILABILITY
#define DLC_ToolBarActive
#endif

#undef DLC_XMLReportActive
#ifdef CATIAR417 // XMLReport_LEVEL_AVAILABILITY
#define DLC_XMLReportActive
#endif

#undef DLC_ConnectDisConnectHLActive
#ifdef CATIAR418 // ConnectDisConnectHL_LEVEL_AVAILABILITY
#define DLC_ConnectDisConnectHLActive
#endif

#undef DLC_DeploymentExtSupportedLevel_Active
#ifdef CATIAR417 //deployment extension HL active.
#define DLC_DeploymentExtSupportedLevel_Active
#endif

#undef COEXADMIN_XMLREPORT
#ifdef  CATIAR419 // COEXADMIN XMLReport_LEVEL_AVAILABILITY
#define COEXADMIN_XMLREPORT
#endif

#undef Activate_ContextManagementCmd
#ifdef  CATIAR419 // ContextManagementCmd
#define Activate_ContextManagementCmd
#endif

#undef FlatTableNewMpg
//#ifdef CATIAR424 //OEBFlatTableMpg
//#define FlatTableNewMpg  
//#endif

#undef PLMBatchSavedSearch
#ifdef CATIAR420 //WSREST API not available below 
#define PLMBatchSavedSearch  
#endif

#undef PLMBatchENOStrRefinementSpecification 
#ifdef CATIAR423 //C++ API not available below 
#define PLMBatchENOStrRefinementSpecification   
#endif

/** 
 *  @level Protected 
 *  @usage U1
 */

//########################################################################
//################# PLMBATCH #############################################
//########################################################################
class ExportedByDataAdmin DLCDev {

  public:

	  /**
	  * Check if <A HREF=../_COEX/ExchangeChannel.php>Exchange Channel</A> is supported
	  * depending on the <A HREF=../_Coex/EnvVar_ExchangeChannel.php>ExchangeChannel</A> environment variable.
	  * @return <UL>
	  * <LI>=0: Exchange Channel is not supported
	  * <LI>=1: Exchange Channel is supported.
	  * </UL>
	  */
	  static int IsExchangeChannelActive();

#ifdef DLC_LoginTicketActive // LoginTicket_LEVEL_AVAILABILITY

/**
* Check if <A HREF=../_PLMBatch/PLMBATCHV6_PES_SSOLogin_AsynchronousBatch.php>external authentication</A> is supported
* <BR>Check <A HREF=../_PLMBatch/PLMBATCHV6_PES_SSOLogin_AsynchronousBatch.php>SSO external authentication support</A> in a aynchronous batch submission 
* depending on the <A HREF=../_PLMBatch/EnvVar_PLMBATCH_SSO_SUPPORT.php>PLMBATCH_SSO_SUPPORT</A> environment variable.
* @return <UL>
* <LI>=0: SSO external authentication is not supported
* <LI>=1: SSO external authentication is supported.
* </UL>
*/
static int IsAsynchroPLMBatchSSOSupportActive();
#endif

/**
* Set <A HREF=../_PLMBatch/PLMBATCHV6_PES_AdvancedXMLReporting.php>XML report</A> activity
* <BR>Set the <A HREF=../_PLMBatch/PLMBATCHV6_PES_AdvancedXMLReporting.php>XML report</A> activation 
* @return <UL>
* <LI>=0: XML report is not active (default value) [corresponding to variable=HTML or no export]
* <LI>=1: Only XML report is active. HTML report contains less information (a single link on xml report ...) [corresponding to variable=XML].
* <LI>=2: Both XML and HTML reports are active and complete [corresponding to variable=BOTH].
* </UL>
*/
	static int SetXMLReportActive(CATUnicodeString iValue);

/**
* Check if <A HREF=../_PLMBatch/PLMBATCHV6_PES_AdvancedXMLReporting.php>XML report</A> is active
* <BR>Check if the <A HREF=../_PLMBatch/PLMBATCHV6_PES_AdvancedXMLReporting.php>XML report</A> is active 
* @return <UL>
* <LI>=0: XML report is not active (default value) [corresponding to variable=HTML or no export]
* <LI>=1: Only XML report is active. HTML report contains less information (a single link on xml report ...) [corresponding to variable=XML].
* <LI>=2: Both XML and HTML reports are active and complete [corresponding to variable=BOTH].
* </UL>
*/
	static int IsXMLReportActive();

/**
* Check if <A HREF=../_PLMBatch/PLMBATCHV6_PES_AdvancedXMLReporting.php>XML report</A> is active
* <BR>Check if the <A HREF=../_PLMBatch/PLMBATCHV6_PES_AdvancedXMLReporting.php>HTML report</A> is active 
* depending on the <A HREF=../_PLMBatch/PLMBATCH_AdvancedReporting.php>PLMBATCH_AdvancedReporting</A> environment variable.
* @return <UL>
* <LI>=0: XML report is not active (default value) [corresponding to variable=HTML or no export]
* <LI>=1: Only XML report is active. HTML report contains less information (a single link on xml report ...) [corresponding to variable=XML].
* <LI>=2: Both XML and HTML reports are active and complete [corresponding to variable=BOTH].
* </UL>
* @return <UL>
* <LI>=0: HTML report is not active [corresponding to variable=XML]
* <LI>=1: HTML report is active (default value)
* </UL>
*/
	static int IsHTMLReportActive();

};
#endif
