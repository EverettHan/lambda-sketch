//
// COPYRIGHT Dassault Systemes 2008
//

#ifndef CATPLMExecuteProcedureServices_h
#define CATPLMExecuteProcedureServices_h

/**
 * @level Protected
 * @usage U1  
 */

#include "IUnknown.h"
#include "CATPLMAdapterEKLBinding.h"
#include "CATCollec.h"

class CATString;
class CATLISTV(CATPLMID);
class CATIAdpErrorMonitorAbstract;


class ExportedByCATPLMAdapterEKLBinding CATPLMExecuteProcedureServices
{

public:
	
	/**
	* Executes a procedure
	* <br><b>Role:</b> Execute a procedure described in an EKL script. 
	* @param iProcedureName
	*      The name of the procedure.
	* @param iListPLMID 
	*      The list of input PLMIDs necessary for the procedure.
	* @param oListPLMID
	*      The list of PLMIDs returned by the procedure.
	* @return
	*		 S_OK : The procedure was successfully executed.
	*	<br> E_FAIL : The execution of the procedure failed.
	*/
	static HRESULT ExecutePLMProcedure(const CATString& iProcedureName,
                                     CATLISTV(CATPLMID) &iListPLMID,
                                     CATLISTV(CATPLMID) &oListPLMID,
                                     CATIAdpErrorMonitorAbstract * ioErrorMonitorAbstract = NULL) ;
};

#endif


