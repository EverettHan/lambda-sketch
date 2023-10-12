#include <stdint.h>

#include "ECWireUtilities.h"

#include <CATGeoFactory.h>
#include <CATSoftwareConfiguration.h>
#include <CATBody.h>
#include <CATErrorMacros.h>
#include <CATCGMJournalList.h>
#include <CATCGMCreateTopAssemble.h>
#include <CATICGMHybAssemble.h>
#include <CATIPGMWireIntersectionChecker.h>
#include <CATPGMCreateWireIntersectionChecker.h>

#include <SWXUtAssert.h>
#include <SWXUtTraceTime.h>

CATBody* ECWireUtilities::MakeWire(CATGeoFactory * ipFactory, CATTopData* ipTopData, CATLISTP(CATBody) & iCurveWires)
{
    CATBody*  pResult = NULL;
	CATICGMHybAssemble * pCTAssem = NULL;
	CATTry 
	{
		pCTAssem = CATCGMCreateTopAssemble(ipFactory, ipTopData, &iCurveWires);
		if(pCTAssem)
		{
			pCTAssem->Run();
			pResult = pCTAssem->GetResult();
		}
	}
	CATCatch(CATError, errobj)
	{
		CATUnicodeString err = errobj->GetNLSMessage();
	}
	CATEndTry

	if ( pCTAssem )
	{
		pCTAssem->Release();
		pCTAssem = NULL; 
	}
	return pResult ;

}


bool ECWireUtilities::CheckSelfIntersection(CATSoftwareConfiguration * ipConfig, CATBody* iBody)
{
	SWX_DEBUG_TRACE("ECWireUtilities::CheckSelfIntersection");

	if(!iBody) return 0;

	CATCGMJournalList* pNewJournal = new CATCGMJournalList();
	CATTopData topdata(ipConfig);
	topdata.SetJournal(pNewJournal);

	CATBoolean AutoIntersectionFound = FALSE;

	CATIPGMWireIntersectionChecker * pWireIntersectionChecker = CATPGMCreateWireIntersectionChecker(iBody->GetContainer(), &topdata, iBody); 

	if (pWireIntersectionChecker)
	{
		CATTry 
		{
			pWireIntersectionChecker->SetTopologicalResultMode(FALSE);
			pWireIntersectionChecker->SetCheckOnlySelfIntersection();
			pWireIntersectionChecker->Run();
    
			AutoIntersectionFound = pWireIntersectionChecker->GetLogicalResult();
		}
		CATCatch(CATError, error)
		{
			CATUnicodeString param1 = error->GetNLSMessage();
		}
		CATEndTry;

		pWireIntersectionChecker->Release();
		pWireIntersectionChecker = NULL;
	}

	if(pNewJournal != NULL)
	{
		delete pNewJournal; 
		pNewJournal = NULL;
	}

	return AutoIntersectionFound ? 1 : 0;
}
