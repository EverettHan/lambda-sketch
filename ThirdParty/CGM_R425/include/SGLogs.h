#pragma once

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "SGLogsInfra.h"
#include "CATTime.h"
#include "list.h"

/**
* SG logging mecanism.
* Usage
* SGLOG<<"My log:"<<MyDoubleValue<<" another value:"<<charptr<<" and now a rep: "<<myCATRepPtr<<SGENDLOG
* You can replace SGLOG by SGLOGINFO, SGLOGWARNING or SGLOGERROR.
* You can also use SGLOGGROUP("MyGroup"); and SGENDLOGGROUP("MyGroup") to group logs in the output file
* and automatically get the elapsed time of the group
**/

class CATRep;
typedef void * _SGLoggerNop;

#define SG_LOG_LOG		0
#define SG_LOG_INFO		10
#define SG_LOG_WARNING  20
#define SG_LOG_ERROR		30

class ExportedBySGLogsInfra _SGLogger
{
private:
	CATUnicodeString _CurLog;
	CATUnicodeString _TimeStamp;
	CATUnicodeString _LogsOut;
	CATUnicodeString _CurGroup;
	CATUnicodeString _ActiveGroup;
	double 			 _ActiveGroupTime;
	CATBoolean	_Console;

	CATULONG32 _Id;
    CATULONG32 _LogsOutFileDesc;

	CATListOfCATUnicodeString	_NestedGroupsTree;		// List of CATUnicodeString containing the name of the previously stored Groups
	double					*	_NestedGroupsTime;		// Double buffer storing the GroupTime of each group
	unsigned int				_NestedGroupBufferSize;	// The number of values that can be stored in the _NestedGroupsTime buffer
	unsigned int				_NestLevel;				// the number of nested groups

	void RawLog(const CATUnicodeString & p_Str) const;

	/**
	 * Store the current values of _ActiveGroup and _ActiveGroupTime inside a 
	 * CATListOfCATUnicodeString and a double buffer in order to retrieve them
	 * later.
	 * This function is called inside the "StartGroup" method when there is 
	 * already an Active Group. The informations about it are saved and the new
	 * one can then "overwrite" them.
	 */
	HRESULT NestGroup();

	/**
	 * Retrieve the values previously stored by the "NestGroup" method in order
	 * to use them to write into the log file.
	 */
	HRESULT UnNestGroup();

public:
	_SGLogger();
	~_SGLogger();

	void StartLog(unsigned int iLogLevel, char * iFilename, unsigned int iLineNum);
	void LogHRESULT(HRESULT iHr);
	void EndLog();
	void StartGroup(const char * p_Grp, char * iFilename, unsigned int iLineNum);
	void EndGroup(const char * p_Grp);
	inline unsigned char IsLoggingActive() {return _LogsOut!="";}

	friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, const char *);
	friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, double);
	friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATRep *);
	friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, const _SGLoggerNop&);
	/*friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATLONG64);
	friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATULONG64);
	friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATLONG32);
	friend ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATULONG32);	*/

};
extern ExportedBySGLogsInfra _SGLogger g_Logger; // singleton

ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, const char *);
ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, double);
/*ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATLONG64);
ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATULONG64);
ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATLONG32);
ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATULONG32);*/
ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, CATRep *);
ExportedBySGLogsInfra _SGLogger & operator <<(_SGLogger &, const _SGLoggerNop&);


#define SGLOG {if(g_Logger.IsLoggingActive()) {g_Logger.StartLog(SG_LOG_LOG,__FILE__, __LINE__);g_Logger
#define SGLOGINFO {if(g_Logger.IsLoggingActive()) {g_Logger.StartLog(SG_LOG_INFO,__FILE__, __LINE__);g_Logger
#define SGLOGWARNING {if(g_Logger.IsLoggingActive()) {g_Logger.StartLog(SG_LOG_WARNING,__FILE__, __LINE__);g_Logger
#define SGLOGERROR {if(g_Logger.IsLoggingActive()) {g_Logger.StartLog(SG_LOG_ERROR,__FILE__, __LINE__);g_Logger
#define HR2LOG(hr) (_SGLoggerNop)1;g_Logger.LogHRESULT(hr);g_Logger

#define SGENDLOG (_SGLoggerNop)0;g_Logger.EndLog();}}
#define SGLOGGROUP(GrpName) g_Logger.StartGroup(GrpName,__FILE__, __LINE__);
#define SGENDLOGGROUP(GrpName) g_Logger.EndGroup(GrpName);
