#ifndef __CATOxDataSetBuilder__
#define __CATOxDataSetBuilder__
/**
* @level Private
* @usage U2
*/

#include "ExportedByCATPLMIdentification.h"
#include "CATPLMID.h"
#include "CATPLMIDCollections.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPLMTypeH.h"

class ExportedByCATPLMIdentification CATOxDataSetBuilder
{
public :

	virtual CATPLMID OwnerPLMID(const CATPLMID &iPLMID) =0;
	virtual CATPLMID ReferencePLMID(const CATPLMID &iPLMID) =0;
	virtual CATPLMIDToArrayUnicodeStringMapIter GetIterator() const =0;

};

#endif
