/**
* @level Protected
* @usage U1
*/
/* -*-c++-*- */
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
//
//  New V5R201 PLM Engines in-session run management 
// 
//------------------------------------------------------------------------------
// 05/01/12 Creation                                                         VCS
//------------------------------------------------------------------------------
#ifndef CATOmbPLMPersistService_H
#define CATOmbPLMPersistService_H

#include "CATOmbPersistency.h"

#include <stddef.h> // for NULL symbol

// ObjectModelerBase
#include "CATOmbSessionService.h"
#include "CATOmbPLMActiveContextType.h"
#include "CATOmbPLMImportContextType.h"

#include "CATLISTV_CATComponentId.h"

/**
* Class of services to manage PLM persistency engines in-session activity. 
* <b>Role</b>: This class provides services to store and read a flag on PLM Save/Open
* <br> engines current activity during all the current session life cycle.
* <br> PLM Open and Save Engines flows are already marked with this activity flag.
* <br> It can be read anywhere during CATIA session life cycle to perform treatments
* <br> depending on PLM engines activity.
* <br><i>Always instanciate this object on the stack.</i>
* <br><i>(deletion of this object is implicit at the end of its declaration scope).</i>
*/

class ExportedByCATOmbPersistency CATOmbPLMPersistService : CATOmbSessionService
{

public:

  /**
  * Creates the service on current session. 
  *
  * @param ipSessionContext
  *		A pointer to the session to be used as a context for this service. 
  **/
  CATOmbPLMPersistService(CATOmbSessionContext *ipSessionContext = NULL);

  // destructor is not virtual because it's super-class doesn't declare it as virtual
  // and no override requested, to avoid cost of a function table
  /**
  *	@nodoc
  * Destroys the service.
  **/
  ~CATOmbPLMPersistService() {};

  /**
  * Sets the current persistency context status
  *
  * @param iActiveContext
  *        The persistency context to be set
  * @param iComponents
  *        The list of components which relations have to be binded during open.
  * @return
  * <ul>
  * <li>S_OK  : the context value has been correctly set</li>
  * <li>S_FALSE  : the context is already set to this value</li>
  * <li>E_FAIL: otherwise</li>
  * </ul>
  **/

  HRESULT SetPLMPersistContext(CATPLMActiveContext & iActiveContext, CATLISTV(CATComponentId) * iComponents = NULL);

  /**
  * Gets the current persistency context status
  *
  * @param oActiveContext
  *        The persistency context currently set
  * @return
  * <ul>
  * <li>S_OK  : the context value has been correctly read</li>
  * <li>E_FAIL: otherwise</li>
  * </ul>
  **/
  HRESULT GetPLMPersistContext(CATPLMActiveContext & oActiveContext);

  /**
  * Sets the current import context status
  *
  * @param iImportContext
  *        The import context to be set
  * @return
  * <ul>
  * <li>S_OK  : the context value has been correctly set</li>
  * <li>S_FALSE  : the context is already set to this value</li>
  * <li>E_FAIL: the context value is already set to an active context</li>
  * </ul>
  **/

  HRESULT SetPLMImportContext(CATPLMImportContext & iImportContext);

  /**
  * Gets the current import context status
  *
  * @param oImportContext
  *        The import context currently set
  * @return
  * <ul>
  * <li>S_OK  : the context value has been correctly read</li>
  * <li>E_FAIL: otherwise</li>
  * </ul>
  **/
  HRESULT GetPLMImportContext(CATPLMImportContext & oImportContext);

private:

  // copy constructor is private
  CATOmbPLMPersistService (const CATOmbPLMPersistService& iCopy);

  // = operator is private
  CATOmbPLMPersistService operator=(CATOmbPLMPersistService& iCopy);
};

#endif
