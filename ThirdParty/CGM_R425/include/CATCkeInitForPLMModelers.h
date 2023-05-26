#ifndef CATCkeInitForPLMModelers_H
#define CATCkeInitForPLMModelers_H

#include "CATLifSpecs.h"

// For HRESULT
#include "CATSysErrorDef.h"

class ExportedByCATLifSpecs CATCkeInitForPLMModelers
{
public:
	/**
	* Dictionary initialization for PLM modelers ONLY !!!
	* To be called only from CATIPLMClientCoreModelerInitialisation::Init methods
	* Any other usage is invalid.
	*/
	static HRESULT ForceInit();

private:
	CATCkeInitForPLMModelers(const CATCkeInitForPLMModelers&);
	CATCkeInitForPLMModelers& operator=(const CATCkeInitForPLMModelers&);
};

#endif
