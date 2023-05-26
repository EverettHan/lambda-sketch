#ifndef CATAdpCorrectionOperationAccess_H
#define CATAdpCorrectionOperationAccess_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
* @level Private
* @usage U3
*/
#include "CATPLMIntegrationAccess.h"

#include "CATAdpOperationDatum.h"

/**
* Class to represent a modification in a history
**/
class CATPLMID;

class ExportedByCATPLMIntegrationAccess CATAdpCorrectionOperationAccess
{
public:
	CATAdpCorrectionOperationAccess(const CATAdpOperationDatum &iDatum);
	virtual ~CATAdpCorrectionOperationAccess();

	/**
	*/
	HRESULT GetSnapshotID(CATPLMID &oPLMID);
private:
  CATAdpOperationDatum _BaseDatum;
};

#endif
