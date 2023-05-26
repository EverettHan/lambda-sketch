
#ifndef XPDMPCSTracker_H
#define XPDMPCSTracker_H

#include "CATIAV5Level.h"

#include "CATTime.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByXPDMServices.h"

class ExportedByXPDMServices XPDMPCSTracker
{

	struct Compo
	{
		CATUnicodeString key;
		CATTime t;
	};

	Compo _components[500];
	int _tab_count;
	int _calls_count;
	int _limit;
public:

	static XPDMPCSTracker * getInstance();

	static void kill();

	HRESULT startProcess(CATUnicodeString iProcessKey, int log_level = -1);
	HRESULT endProcess(CATUnicodeString iProcessKey);
	void setReportPathAndCaluclateLimit(const CATUnicodeString & iReportPath);

private:

	static XPDMPCSTracker * _TimeLoggerDataSingleton;
	XPDMPCSTracker();
	~XPDMPCSTracker();
	
	CATUnicodeString _reportPath;
};
#endif
