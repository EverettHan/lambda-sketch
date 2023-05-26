// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMREBriefcaseExportExtend.h
// Define the CATIPLMREBriefcaseExportExtend interface
//
//===================================================================
//
//  Apr 2008  Creation: PA
//===================================================================
#ifndef CATIPLMREBriefcaseExportExtend_H
#define CATIPLMREBriefcaseExportExtend_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMREBriefcaseExportExtend;
#else
extern "C" const IID IID_CATIPLMREBriefcaseExportExtend ;
#endif

#include "CATCollec.h"

class CATPLMID;

//------------------------------------------------------------------

/**
  * Interface exposing replication engine services dedicated to the extension of the export operation.
  * <br><b>Role</b>: This interface allows to extend the export capabilities of the replication engine.
  *
  */

class ExportedByCATPLMIntegrationInterfaces CATIPLMREBriefcaseExportExtend: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
  * Declare the applicative id to be exported in the PLM briefcase in link with the PLM component.
  * <br><b>Role:</b>Declare the applicative id to be exported in the PLM briefcase in link with the PLM component.
  *
  * @param iComponent
  *   PLM component 
  * @param oAppId
  *   Applicative Id for this PLM component 
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>Declaring the applicative id to be exported in the PLM briefcase in link with the PLM component succeeded.</dd>
  *   <dt>E_FAIL</dt><dd>Declaring the applicative id to be exported in the PLM briefcase in link with the PLM component failed.</dd>
  * <br>
  */ 

  virtual HRESULT DeclareApplicativeIdToExportInPLMBriefcase  ( const CATPLMID &iComponent, CATString &oAppId ) = 0;  

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMREBriefcaseExportExtend, CATBaseUnknown );

#endif
