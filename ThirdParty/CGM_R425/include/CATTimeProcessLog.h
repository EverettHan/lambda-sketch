/** WARNING: YWE 16:01:20 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES  2001
//===========================================================================
// January. 2016   Creation                                 Y.Wallier
// Class CATTimeProcessLog : Objet de Gestion des Versions CATIA supportees
//===========================================================================

#ifndef CATTimeProcessLog_h
#define CATTimeProcessLog_h
 
#include "DLCDevLevel.h"

/** 
 *  @level Protected 
 *  @usage U1
 */

#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATLibEx.h" // CATIALevelInfo
//#include "ExportedByCATXMLReporter.h"
#include "ExportedByPLMBatchInfraServices.h"

/**
 * This class contains a number of static methods designed to log sub-process time in a specific xml log 
 */

class ExportedByPLMBatchInfraServices CATTimeProcessLog {
  public:
	friend class PLMBatchToolBox ;

/*x
Section Execution log
Abstract This section contains static methods to manage times and get stacks in log.
x*/

 /**
 * Activate the Log.
 * <BR>Activate the xml time log file
 * @return 
 *		Flag indicating status of operation 
 * <UL>
 * <LI>=0: ProcessTimeLog.xml log has been successfully activated
 * <LI>!=0: An error occured, Log not activated
 * </UL>
 */
    static int Activate ();
/**
 * Start a time point
 * <BR>Initialises a time point for an operation
 * @param  iPointName the name of the point
 * <BR>Any point open must be closed using EndPoint method to get a valid xml structure
 * @return 
 *		Flag indicating status of operation 
 * <UL>
 * <LI>=0: the point has been successfully initialized in the Log file
 * <LI>!=0: An error occured, The point can not be written in the Log file 
 * </UL>
 */
    static int StartPoint (CATUnicodeString iPointName);

 /**
 * Close a time point
 * <BR>Closes a time point for an operation
 * @param  iPointName the name of the point
 * @return 
 *		Flag indicating status of operation 
 * <UL>
 * <li>=0: the point has been successfully closed in the Log file
 * <LI>!=0: An error occured, The point can not be closed in the Log file 
 * <UL>
 * <LI>=1: Depth of the structure is already null, this point (or another one) hasn't been opened before closing 
 * </UL>
 * </UL>
 */
    static int EndPoint (CATUnicodeString iPointName);

protected:
/**
 * Initialise the Log.
 * <BR>Initialises the xml time log file
 * @param  iLogReportName the directory in which the log has to be written
 * <BR>Without final '/'
 * @return 
 *		Flag indicating status of operation 
 * <UL>
 * <li>=0: ProcessTimeLog.xml log has been successfully initialized in the iLogReportName directory
 * <LI>!=0: An error occured, ProcessTimeLog.xml log has not been initialized in the iLogReportName directory
 * <UL>
 * <LI>=1: null input directory</LI>
 * <LI>=2: a log has already been initialized in another directory</LI>
 * <LI>=3: directory doesn't exist</LI>
* </UL>
 * </UL>
 */
    static int Init (CATUnicodeString & iLogReportName);
/**
 * Close the Log.
 * <BR>Close the xml time log file
 * @return 
 *		Flag indicating status of operation 
 * <UL>
 * <LI>=0: ProcessTimeLog.xml log has been successfully closed
 * <LI>!=0: An error occured, ProcessTimeLog.xml log has not been closed but may contain invalid structure
 * <UL>
 * <LI>=1: Final depth is not 0 - a tag hasn't been closed</LI>
 * </UL>
 * </UL>
 */
    static int End ();

/**
 * Get the Log process File path.
 * <BR>Get the Log process File path
 * @return 
 *		the path of the current LogReportName  
 */
    static CATUnicodeString GetLogFilePath ();

private:

/**
 * Write an info in the TimeProcessLog
 * @param iTypInfo the type of information to write.
 * <UL>
 * <LI>=0: a Header information, no specific format
 * <LI>=1: a START time information 
 * <LI>=2: a END time information 
 * </UL>
 * @param iInfo the information to write
 * @return 
 *		Flag indicating status of operation 
 * <UL>
 * <LI>=0: the information has been successfully written in the TimeProcessLog
 * <LI>!=0: An error occured, The information can not be written in the TimeProcessLog 
 * <UL>
 * <LI>=1: 
 * </UL>
 * </UL>
 */
    static int WriteTimeProcessInfo (int iTypInfo, CATUnicodeString iInfo );

    static CATUnicodeString _LogReportFile ;
    static int _iDepth ;
    static int _isActive ;
    static int _isActiveTrk ;
    static int _iNbInfo ;
    static int _lDepth1 ;
    static int _lDepth2 ;
    static int _lDepth3 ;
    static int _lDepth4 ;
    static int _lDepth5 ;
    static int _lDepth6 ;
    static int _lDepth7 ;
    static int _lDepth8 ;
	};
#endif
