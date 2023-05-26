/**
 * @usage U1
 * @level Protected
 */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATReporterError_H
#define CATReporterError_H
#include "AD0XXBAS.h"
#include "CATErrors.h"


/**
* This class define the Reporter error from the interface CATIReporterInfo.
* @href 
*/
class ExportedByAD0XXBAS CATReporterError : public CATError
{ 
public:
	CATDeclareErrorClass (CATReporterError, CATError)
  /**
   * Create a specific CATReporterError from a given error.
   * @param iError
   *  The given error.
   */
   CATReporterError (const CATError& iError);
} ;   


#endif      

