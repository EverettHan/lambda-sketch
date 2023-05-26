#ifndef _CATSYSSTATISTICSMTTHEMATIC
#define _CATSYSSTATISTICSMTTHEMATIC

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIStatsThematics.h"
#include "JS03TRA.h"


enum CATSysMonitoringSeverityLevel
{
	CATSysMonitoringComment=10,
	CATSysMonitoringWarning=30,
	CATSysMonitoringCriticalError=50,
	CATSysMonitoringAbend=60
};



/*
	Begin a Statistics event
o	IStatsName is the thematics name; possible value are: ERRORLOG, PCS, AUDIT, ACTIVITY
o	IoRefKey is a pointer to the thematics interface; if not given, it is valuated by the CATSysStatMTStatisticsBeginEvent method;
this parameter purpose is to avoid calculating this pointer each time. It improves performance and thread safety.
o	ilevel is the activation level of the event (compulsory for PCS and ErrorLog ; not used by Audit and Activity Statistics)
o	This method initialises all parameters of an statistic event
o	The return value is an event id that will be used in CATSysStatMTStatisticsAddField and CATSysStatMTStatisticsEndEvent methods
o	Additional field can be added by the application; those fields are optional; the maximum number of added fields is 5
*/
CATStatsEventId ExportedByJS03TRA CATSysStatMTStatisticsBeginEvent (	const char * iStatsName, void **ioRefKey, int ilevel=-1,
													const char *iField1=NULL, const char * iValue1=NULL,
													const char *iField2=NULL, const char * iValue2=NULL,
													const char *iField3=NULL, const char * iValue3=NULL,
													const char *iField4=NULL, const char * iValue4=NULL,
													const char *iField5=NULL, const char * iValue5=NULL);
/*
	Adds fields to a statistical event
*/
HRESULT ExportedByJS03TRA CATSysStatMTStatisticsAddField (const char * iStatsName, void **ioRefKey,CATStatsEventId * iId, const char *iField1, const char * iValue1);

/*
	Ends a statistical event
*/
HRESULT ExportedByJS03TRA CATSysStatMTStatisticsEndEvent (const char * iStatsName, void **ioRefKey, CATStatsEventId * iId);

/*
	Generates an instantaneous statistical event
*/
HRESULT ExportedByJS03TRA CATSysStatsMTInstantEvent (const char * iStatsName, void **ioRefKey, int iLevel=-1,
									const char *iField1=NULL, const char * iValue1=NULL,
									const char *iField2=NULL, const char * iValue2=NULL,
									const char *iField3=NULL, const char * iValue3=NULL,
									const char *iField4=NULL, const char * iValue4=NULL,
									const char *iField5=NULL, const char * iValue5=NULL);


/*
	Tells if the thematic and level is active
o	Returns 1 if the thematics iStatsName is active, 0 if not
*/

CATBoolean ExportedByJS03TRA CATSysStatMTIsThematicActive (const char * iStatsName, void **ioRefKey,  int level=-1);

/*
 * provides the name of the aplication that emits the CBE logs
*/
HRESULT ExportedByJS03TRA CATSysStatisticsMTDeclareApplicationName(const char * iStatsName, void **ioRefKey,const char * iApplicationName);

#endif /* _CATSYSSTATISTICSMTTHEMATIC */


