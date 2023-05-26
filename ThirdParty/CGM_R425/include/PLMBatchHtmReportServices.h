/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002
//===========================================================================
// Usage Notes:   
//===========================================================================
// September 2002   Creation                  YWE 
// Moteur de PLMBatch
//===========================================================================
/** @level Protected 
* @usage U1
*/

#ifndef PLMBatchHtmReportServices_h
#define PLMBatchHtmReportServices_h

#include "ExportedByPLMBatchInfraServices.h"
#include "DLCDevLevel.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#ifdef HL_F045947 // SCALE_CONVERSION_AVAILABILITY
#include "CATCkeScale.h"
#endif
class CATXMLReporter ;
#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY
  class PLMExchangeSet ;
#endif  // XMLReport_LEVEL_AVAILABILITY

// ============================================================================


/**
* This static class exposes internal PLMBatch methods dealing with htm/xml reporting access.
* <P>To minimize bad htm usage, most of the methods are exposed as Private and limited to the friend class PLMBatchWebReport & CATPLMBatchConnexionImpl
*/

class ExportedByPLMBatchInfraServices PLMBatchHtmReportServices 
{
public:
	friend class PLMBatchWebReport ;
	friend class CATPLMBatchConnexionImpl ;
//	friend class CoexXMLReporting ; // tempo

/**
 * Format an Htm message for reports
 * @param Msg information to write in the htm report
 * @param iMsgTyp Severity to attach to the correspondant Msg:<UL>
 * <LI>=-1: Internal debug information message to write in the htm report (default)
 * <BR>Will be written as '<I><FONT COLOR=BLUE>internal debug Information Message</FONT></I>'. This message doesn't need to support NLS.
 * <LI>=-2: Internal debug Warning message to write in the htm report
 * <BR>Will be written as '<I><FONT COLOR=ORANGE>internal debug Warning Message</FONT></I>'. This message doesn't need to support NLS.
 * <LI>=-3: Internal Debug Error message to write in the htm report
 * <BR>Will be written as '<I><FONT COLOR=RED>internal debug Error Message</FONT></I>'. This message doesn't need to support NLS.
 * <LI>=1: information message to write in the htm report (default)
 * <BR>Will be written as '<FONT COLOR=BLACK>Information Message</FONT>'. This message is NLS support
 * <LI>=2: Warning message to write in the htm report
 * <BR>Will be written as '<FONT COLOR=ORANGE>Warning Message</FONT>'. This message is NLS support
 * <LI>=3: Error message to write in the htm report
 * <BR>Will be written as '<FONT COLOR=RED>Error Message</FONT>'. This message is NLS support
 * </UL>
 * return
 * The formated message
*/
static CATUnicodeString BuildHtmMessage (CATUnicodeString Msg ,int iMsgType ) ;

/**
* Activate Section ressources
* <BR>Allow to declare that reports will use Sections 
*/
static void ActivateSection() ;
/**
* Start a Section
* @param iSectionTitle the title of the Section
* @param iAlign the alignment (not implemented)
* <DD>Set the <IMG SRC=../_GIF/Report/Data/Plus.gif> to command the section at the right, or at the left of the iSectionTitle
* @param iFormat  the format/font/classname? to apply to the iSectionTitle (not implemented)
* @return The HTML Message to add in the report to initialise the Section
* <BR>Then a <IMG SRC=../_GIF/Report/Data/Plus.gif> button is added just after the SectionTitle to 
* open (<IMG SRC=../_GIF/Report/Data/Plus.gif>) and 
* close(<IMG SRC=../_GIF/Report/Data/Minus.gif>) dynamically the section in the web browser
* <BR>Sample:
* <?php $SECTIONNAME="SectionTitle" ; ?>
* <?php $SECTIONALIAS="SectionTitle" ; ?> 
* <?php include '../dlc_services/xSection.php' ;  ?>
* <BR>Add your HTML Text here
* <?php include '../dlc_services/EndSection.php' ;  ?>
* 
*/
static CATUnicodeString StartSection(CATUnicodeString iSectionTitle, int iAlign) ;

/**
* Close a Section
* @return The HTML Message to add in the report to close the section
*/
static CATUnicodeString CloseSection() ;
#ifdef HL_F045947 // SCALE_CONVERSION_AVAILABILITY
/**
* Scale conversion
* @return The HTML name of a scale to write in a Report
*/
static CATUnicodeString GetScale(CATCkeScale iScale) ;
#endif

  /*x
Section XML web Reporting 
Abstract Following methods are used to manage  XML web reporting with the CATXMLReporter object.
x*/

/**
 * Report the PLMBatch Env Var list
 * <BR>RSave the list of activated PLMBatch environment variables in the XML report
 * under the xxxx node
 * @return 
*/
static HRESULT AddPLMBatchEnvVarList( CATXMLReporter * TheXMLReporter ) ;
/**
* Copy Resource
* <BR>Copy css, jss, Minus.gif & Plus.gif minimal resource under the Report directory
*/
static CATListOfCATUnicodeString GetMandatoryResource() ;

/**
* Create the XML Global Node
* <BR>Create the XML Global Node for global PLMBatch information
*/
//static PLMExchangeSet * CreatePLMBatchXMLGlobalNode() ;
static HRESULT CreatePLMBatchXMLGlobalNode() ;

/**
* Add Info under the XML Global Node
* <BR>Add PLMBatch global information under the XML Global Node 
*/
static HRESULT AddPLMBatchXMLGlobalNodeInfo(int iNotifType,CATUnicodeString & InfoName,CATUnicodeString & InfoValue) ;

protected:
  /**
* Copy the ressources
* <BR>Copy the needed ressources for PLMBatch htm report in the ResourceDir\Data directory
* @param ResourceDir The directory
* <BR>Directory is created when it does not exist
*/

static void InitResource(CATUnicodeString ResourceDir) ;

#ifdef PLMBatch_Cyrilic
/**
* Open a file with specific char
*/
static HRESULT PLMBatchFOpen(CATUnicodeString &iFileName, const char *iMode, unsigned int* oFileDesc);
#endif

private: 
/**
 * Title generation
 * <BR>Write in the report the header 
 * @param RptFile the File in which header has to be written
 * @param Title The title of the page
 * @iPLMBatchName The name of the batch oner of the report
 * @iRefreshActive if the report needs to be automatically refreshed (for intermediate reports only)
 * <UL>
 * <LI>!=0: automatic refresh active every 3 seconds, adding <?php echo $KBD ?>&lt;meta http-equiv= « refresh » content= « 3.0adl_ » &gt;<?php echo $EKBD ?> 
 * <LI>==0: no refresh
 * <P>Generated header is as follow:
 * <P><TABLE BORDER=0 WIDTH=95% HEIGHT=80 CELLPADDING=5 CELLSPACING=0 BACKGROUND=<?php echo $ROOTUrl ?>_GIF/PLMBatch_DSBanner_V6R2014.jpg BGCOLOR=BLUE>
 * <TR><TD HEIGHT=75>&nbsp;<TD HEIGHT=50><I><B><FONT SIZE=+2 COLOR=WHITE>
 * Title
 * </FONT></I></B></TD>
 * <TD ALIGN=RIGHT><I><FONT SIZE=+0 COLOR=WHITE>
 * <A HREF=../_PLMBatch/Code_CATIBatchAppl.php#GetName>iPLMBatchName</A>
 * <BR>
 * Report generated on Thursday, 28 May 2009 at 12.12.12
 * </FONT></I></TD>
 * </TR></TABLE>
 *  
*/
#ifdef PLMBatch_Cyrilic
	static void PrintTitle(unsigned int RptFile, CATUnicodeString Title, CATUnicodeString iPLMBatchName, int iRefreshActive = 0);
#else
	static void PrintTitle(FILE * RptFile, CATUnicodeString Title, CATUnicodeString iPLMBatchName, int iRefreshActive = 0);
#endif

/**
* Print specific char
*/
#ifdef PLMBatch_Cyrilic
	static void PrintWChar(unsigned int RptFile, CATUnicodeString iStr);
	static void PrintSChar(unsigned int RptFile, CATUnicodeString iStr);
#else
	static void PrintWChar(FILE*& RptFile, CATUnicodeString iStr);
	static void PrintSChar(FILE*& RptFile, CATUnicodeString iStr);
#endif

/**
* Return the Current Date
*/
static CATUnicodeString GetCurrentDate() ;

/**
* Return the Report Copyright
*/
static CATUnicodeString GetCopyright() ;



	static  CATUnicodeString _fmtDate ;
	static  CATUnicodeString _DataDirectory ;
	static  int _UseSection ;

#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY
  static PLMExchangeSet    * _PLMBatchGlobalNode;
#endif  // XMLReport_LEVEL_AVAILABILITY

} ;

#endif


