#ifndef CATOmyErrorData_H
#define CATOmyErrorData_H

#include "CATOmyIncidentCollect.h"
#include "CATError.h"
#include "CATDataType.h"

namespace CATOmyErrorExtensions
{
  /**
   * Set a tag on a CATError
   * By default the value consists in incrementing a global counter
   */
  ExportedByCATOmyIncidentCollect void SetTag(CATError& iError, CATULONG64 tag = 0);

  /**
   * retrieve tag set using SetTag
   * return 0 if no tag has been set
   */
  ExportedByCATOmyIncidentCollect CATULONG64 GetTag(const CATError& iError);

  /**
   * return true if input error is actually an error (not a warning nor an "information")
   */
  inline bool IsError(const CATError& error)
  {
    CATErrorType severity = const_cast<CATError&>(error).GetInformationOnErrorType();
    return severity != CATErrorTypeWarning || severity == CATErrorTypeInformation;
  }
}

#endif
