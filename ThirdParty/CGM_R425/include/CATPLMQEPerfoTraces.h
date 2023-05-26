/*
* CATPLMQEPerfoTraces.h
*
*  Created on: Apr 3, 2013
*      Author: PJQ
*/

#ifndef CATPLMQEPerfoTraces_H_
#define CATPLMQEPerfoTraces_H_
#include "CATPLMIntegrationAccess.h"
#include "CATLib.h"
#include "CATUnicodeString.h"
#include "CATSysErrorDef.h"
#include "CATIStatsThematics.h"

class ExportedByCATPLMIntegrationAccess CATPLMQEPerfoTraces
{


public:



  static HRESULT Start(int & iCounter, CATUnicodeString & iQEChain, CATTimerId & iologTimer, CATUnicodeString & logId);



  static HRESULT Stop(CATTimerId & ilogTimer, CATUnicodeString & ilogId, CATUnicodeString & iMsg);


};
#endif /* CATPLMQEPerfoTraces_H_ */
