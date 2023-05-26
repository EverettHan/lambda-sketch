// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATPLMREPlugCreateOptions.h
// Optional parameters of the plug creation APIs
//
//===================================================================
//
//
//===================================================================
//
//  Jan 2008  Creation: LED
//===================================================================

#ifndef _CATPLMREPlugCreateOptions_H
#define _CATPLMREPlugCreateOptions_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATUnicodeString.h"

/**
* Object holding optional parameters of the plug creation APIs.
* <br><b>Role</b>: This object allows to define optional parameters for @href CATIPLMReplicationEnginePlugServices#CreateInitialPlug and CATIPLMReplicationEnginePlugServices#CreateConnectedPlug services.
*
* @see CATIPLMReplicationEnginePlugServices
*/
class ExportedByCATPLMIntegrationInterfaces CATPLMREPlugCreateOptions
{

public:
  CATPLMREPlugCreateOptions();
  virtual ~CATPLMREPlugCreateOptions();

  /**
  * Allows to provide a display name for the plug.
  * <br><b>Role:</b>Display name is optional. By default, plugs have no display name. 
  * @param iDisplayName
  *   The display name for the plug. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt>  
  * <br>
  */ 
  HRESULT SetDisplayName(const CATUnicodeString &iName );

private:

  friend class CATPLMREPlugServicesImpl;
	friend class CATPLMRECreateInitialPlugTask;
	friend class CATPLMRECreateConnectedPlugTask;

  CATPLMREPlugCreateOptions& operator=(const CATPLMREPlugCreateOptions &); // not implemented
  CATPLMREPlugCreateOptions(const CATPLMREPlugCreateOptions &); // not implemented

  CATUnicodeString _plugDisplayName;
};

#endif
