// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIOmyRecordAuthorizationErrorReporter.h
// Define the CATIOmyRecordAuthorizationErrorReporter interface
//
#ifndef CATIOmyRecordAuthorizationErrorReporter_H
#define CATIOmyRecordAuthorizationErrorReporter_H

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYBaseSession IID IID_CATIOmyRecordAuthorizationErrorReporter;
#else
extern "C" const IID IID_CATIOmyRecordAuthorizationErrorReporter ;
#endif

/**
* @level Protected
* @usage U4 CATIOmySessionRecordManager
* Interface representing a reporter for authorization errors (licencing) in PLMMaintenance context.
*/
class ExportedByCATOMYBaseSession CATIOmyRecordAuthorizationErrorReporter: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
  * Reports that an authorization error has been encoutered
  */
  virtual void ReportAuthorizationError()=0;
  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};
CATDeclareHandler(CATIOmyRecordAuthorizationErrorReporter,CATBaseUnknown);
#endif
