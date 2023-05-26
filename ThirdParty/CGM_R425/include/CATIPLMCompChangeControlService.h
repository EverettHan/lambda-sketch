// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMCompChangeControlService.h
// Interface to run Procedures.
//
//===================================================================
//
// Usage notes:
//   Use this interface to execute a Procedure thanks to the method LaunchProcedure.
//   To get a pointer on this interface, use the static method
//                  CATPLMComponentServices::GetProcedureCallService
//
//===================================================================
//
//  Dec 2008  Creation:  MQV
//===================================================================
/**
 * @level Protected
 * @usage U3
 */
#ifndef CATIPLMCompChangeControlService_H
#define CATIPLMCompChangeControlService_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#include "CATCollec.h"
class CATString;
class CATLISTV(CATPLMID);

class CATIPLMCompRecordReadSet;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompChangeControlService;
#else
extern "C" const IID IID_CATIPLMCompChangeControlService ;
#endif

/**
 * Use this interface to set or unset the AuthorityControl flag of a list of PLMID.
 * To retrieve a valid pointer on this interface, use the static method 
 * @href CATPLMComponentServices#GetChangeControlService .<br>
 */
class ExportedByCATPLMServicesItf CATIPLMCompChangeControlService: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Sets the authority control flag on a list of PLM objects.
  */
  virtual HRESULT ActivateModificationUnderAction (const CATLISTV(CATPLMID) & iIds, CATIPLMCompRecordReadSet **oRRS ) = 0;

  /**
  * Unsset the authority control flag on a list of PLM objects.
  */
  virtual HRESULT DeactivateModificationUnderAction (const CATLISTV(CATPLMID) & iIds, CATIPLMCompRecordReadSet **oRRS ) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

#endif
