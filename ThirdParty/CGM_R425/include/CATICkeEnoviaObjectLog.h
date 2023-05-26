// COPYRIGHT Dassault Systemes 2002/2003
// Creator DRL

#ifndef CATICkeEnoviaObjectLog_H
#define CATICkeEnoviaObjectLog_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATICkeParm_var;
class CATIInstance_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATICkeEnoviaObjectLog;
#else
extern "C" const IID IID_CATICkeEnoviaObjectLog ;
#endif

//------------------------------------------------------------------

class ExportedByKnowledgeItf CATICkeEnoviaObjectLog: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	enum WarningType { Creation, Modification, Deletion, LinkModification };
	
	virtual HRESULT LogObject (const WarningType iMessage, const CATUnicodeString& info = CATUnicodeString()) = 0;
	
	// info = 0 si on n'a pas loggué, 1 si creation, 2 si modification, 3 si suppression
	virtual HRESULT GetLoggedInfo(int &info) = 0;
};

//------------------------------------------------------------------
CATDeclareHandler(CATICkeEnoviaObjectLog, CATBaseUnknown);

#endif
