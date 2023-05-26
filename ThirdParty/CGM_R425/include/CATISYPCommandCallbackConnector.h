#ifndef CATISYPCommandCallbackConnector_H
#define CATISYPCommandCallbackConnector_H

#include "IntroInfra.h"
#include "CATBaseUnknown.h"
#include <CATCommand.h>


extern ExportedByIntroInfra  IID IID_CATISYPCommandCallbackConnector ;

/** Usage notes: Allows the use of a CATCommand and a CATCommandMethod
 * via introspection and Style Processing. 
 * Every class that implements CATISYPTemplate AND that is willing to
 * use CATCommandMethods must have an implementation of this interface,
 * in order to give Style Processor the adequate behavior regarding 
 * CATCommand.
 * An example of implementation is provided in CATDlgDeclarativeManager in
 * the DialogDeclarativeEngine framework
 */

class ExportedByIntroInfra CATISYPCommandCallbackConnector : public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual void ConnectCommandCallback(CATCommand* i_pCmd, const char* i_commandNotificationClassName, CATCommandMethod i_method)=0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( CATISYPCommandCallbackConnector, CATBaseUnknown );

#endif
 
