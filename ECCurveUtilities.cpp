
#include <stdint.h>

#include <CATGeoFactory.h>
#include <CATSoftwareConfiguration.h>
#include <CATBody.h>
#include <CATErrorMacros.h>
#include <CATSurLimits.h>
#include <CATLine.h>
#include <CATCGMJournalList.h>
#include <CATGeometry.h>
#include <CATCGMCellTracker.h>
#include <CATCGMContainerMngt.h>
#include <CATICGMTopWire.h>
#include <CATMathPlane.h>
#include <CATPlane.h>
#include <CATCrvLimits.h>

#include "ECCurveUtilities.h"


CATBody* ECCurveUtilities::MakeWireBody(CATTopData* iTopData, CATCurve* ipCurve, const CATCrvLimits& ipLimit, bool iOrientationPositive)
{
	CATBody* outwire=NULL;

	if(ipCurve!=NULL)
	{
		CATICGMTopWire* pWireOp=NULL;
		CATTry 
		{
			CATCrvLimits limits=ipLimit;
            short orient = 1;

			orient = iOrientationPositive ? 1 : -1;

			pWireOp=CATCGMCreateTopWire(ipCurve->GetContainer(), iTopData, 1, &ipCurve, &limits, &orient);
			if(pWireOp!=NULL)
			{
				pWireOp->Run();
				outwire=pWireOp->GetResult();
			}
		}
		CATCatch(CATError, errobj)
		{
			CATUnicodeString err = errobj->GetNLSMessage();
		}
		CATEndTry

		if(pWireOp!=NULL) 
			pWireOp->Release();
	}
	return outwire;
}
