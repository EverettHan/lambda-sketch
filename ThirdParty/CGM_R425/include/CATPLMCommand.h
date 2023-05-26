// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMCommand.h
// Header definition of CATPLMCommand
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2003  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Private
* @usage U1
*/
#ifndef CATPLMCommand_H
#define CATPLMCommand_H

#include "CATPLMServicesItf.h"
#include "CATPLMBaseObject.h"

#include "CATBooleanDef.h"

#include "CATDbBinary.h"

class CATString;
class CATIPLMProviderDesc;
class VPMIDicService;
class TSTCATPLMEV5Metadata;

//-----------------------------------------------------------------------

/**
 * To each object type is associated a list of commands which can be execute on the server side.
 */
class ExportedByCATPLMServicesItf CATPLMCommand: public CATPLMBaseObject
{
  friend class TSTCATPLMEV5Metadata;

  CATDeclareClass;

public:
	
	// Standard constructors and destructors
	// -------------------------------------
	CATPLMCommand (CATString *iCommandId,CATUnicodeString *iAlias, CATIPLMProviderDesc * iProvider);
  CATPLMCommand (VPMIDicService *iCommand,CATIPLMProviderDesc * iProvider);
	virtual ~CATPLMCommand ();
	
  /** @nodoc */
  HRESULT GetWriteAccess (boolean &oWriteAccess);

private:
	// Copy constructor and equal operator
	// -----------------------------------
	CATPLMCommand (CATPLMCommand &);
	CATPLMCommand& operator=(CATPLMCommand&);

  HRESULT GetUuid (CATDbBinary &oUuid);
  CATDbBinary _Uuid;

  int _WriteAccess;  // boolean but can check if valid info was found or not
};

//-----------------------------------------------------------------------

#endif
