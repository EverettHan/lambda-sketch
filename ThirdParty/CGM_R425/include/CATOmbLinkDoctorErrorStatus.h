/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATOmbLinkDoctorErrorStatus_h
#define CATOmbLinkDoctorErrorStatus_h

/**
 * @level Protected
 * @usage U3
 */


#include "CATObjectModelerBase.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

class CATOmbLinkInterface;


class ExportedByCATObjectModelerBase CATOmbLinkDoctorErrorStatus
{
  friend class CATOmbLinkDoctorGlobalStatus;

public:
  enum TypeOfError { PointingOutsideV6Repository, NotAuthoringPointedInRep, NotAuthorizedTypeOfLinkForExternal, UnableToRetrieveSymbolPropertyOnExternal, NotCompliantWithV6PLMSave, UnexpectedError };
  enum TypeOfRepair { Isolate, NoRepair };

  /**
  * This method gives access to the error
  */
  virtual TypeOfError GetTypeOfError() = 0;
  virtual CATUnicodeString ErrorDescription() = 0;

  /**
  * This method gives access to the Proposal that will be performed
  * during the repair phase
  */
  virtual TypeOfRepair GetTypeOfProposal() = 0;
  virtual CATUnicodeString ProposalDescription() = 0;

  /**
  * This method indicated if the error was actually repaired
  */
  virtual CATBoolean IsErrorRepaired() = 0;
};
#endif
