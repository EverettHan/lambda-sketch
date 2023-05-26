// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMChangeControl.h
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
#ifndef CATIPLMChangeControl_H
#define CATIPLMChangeControl_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#include "CATCollec.h"
class CATString;
class CATLISTV(CATPLMID);

class CATIPLMRecordReadSet;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMChangeControl;
#else
extern "C" const IID IID_CATIPLMChangeControl ;
#endif

/**
 * Use this interface to set or unset the AuthorityControl flag of a list of PLMID.
 * To retrieve a valid pointer on this interface, use the static method 
 * @href CATPLMComponentServices#GetChangeControlService .<br>
 */
class ExportedByCATPLMServicesItf CATIPLMChangeControl: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Sets the authority control flag on a list of PLM objects.
  */
  virtual HRESULT ActivateModificationUnderAction (const CATLISTV(CATPLMID) & iIds, CATIPLMRecordReadSet **oRRS ) = 0;

  /**
  * Unsset the authority control flag on a list of PLM objects.
  */
  virtual HRESULT DeactivateModificationUnderAction (const CATLISTV(CATPLMID) & iIds, CATIPLMRecordReadSet **oRRS ) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

#endif
