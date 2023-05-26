#ifndef CATPLMUFORegistrationServicesForConfig_H 
#define CATPLMUFORegistrationServicesForConfig_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define PLMModelerBaseConfigInternal            AuthorizedModule
#define CATOxiUFOLog                      AuthorizedModule
#define CATOxiUFOSaveLog                      AuthorizedModule
#define CATPLMTransaction                AuthorizedModule
#define CATCfgIntegrationAuthoring                AuthorizedModule
#define CATOxiLifeCycle                   AuthorizedModule
#define CATOxUFOCMMTestLib                AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMUFORegistrationServicesForConfig from a non-infrastructure module
@error
#endif
#undef CATPLMTos
#undef PLMModelerBaseConfigInternal 
#undef CATOxiUFOLog
#undef CATOxiUFOSaveLog
#undef CATPLMTransaction
#undef CATCfgIntegrationAuthoring
#undef CATOxiLifeCycle
#undef CATOxUFOCMMTestLib

// ----------------------------------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATComponentId;

class ExportedByCATPLMTos CATPLMUFORegistrationServicesForConfig
{
public:
  enum OpreationType { Split, InsertLogicalClone };
  /**
  * Register instance split
  *  - Associates same logical family
  *  - Creates an historical dependency between new and old instance
  *
  * @param iNewInstance
  * @param iOldInstance
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterSplitInstances(const CATComponentId & iNewInstance, const CATComponentId & iOldInstance);

  /**
  * Register instance split
  *  - Associates same logical family
  *  - Creates an historical dependency between new and old connection.
  *  - Creates an historical dependency between new aconnection and old instance.
  *
  * @param iNewConnection
  * @param iOldConnection
  * @param iOldInstance
  * @param iNewInstance
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterSplitConnections(const CATComponentId & iNewConnection, const CATComponentId & iOldConnection, const CATComponentId & iOldInstance, const CATComponentId & iNewInstance);

  /**
  * Register reroute connection by CCM
  *  - Updates the UFO log
  *
  * @param iConnection
  *   The connection rerouted by CCM
  *
  * @param iNewInstance
  *   The instance that was created by split
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterSplitRerouteConnectionByCCM(const CATComponentId & iConnection, const CATComponentId & iNewInstance);

  /**
  * Register deleted connection by CCM
  *  - Updates the UFO log
  *
  * @param iConnection
  *   The connection deleted by CCM
  *
  * @param iNewInstance
  *   The instance that was created by split
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterSplitDeleteConnectionByCCM(const CATComponentId & iConnection, const CATComponentId & iNewInstance);

  /**
  * Register that CCM client foudn that the connection should not be ducplicated
  * because it would be useless in effectivity.
  *  - TEMPORARY SOLUTION: add create and delete actions, derived from
  *    the connexion. Thus CCM server will not duplicate it.
  *    Waiting for a real solution from server.
  *
  * @param iConnection
  *   The connection ignored by CCM
  *
  * @param iNewInstance
  *   The instance that was created by split
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterSplitIgnoreConnectionByCCM(const CATComponentId & iConnection, const CATComponentId & iNewInstance);

  /**
  * Register connection split and update of the old connection
  *  - Associates same logical family
  *  - Creates an historical dependency between new and old connection.
  *  - Creates an historical dependency between new aconnection and old instance.
  * Registers in log:
  * create(iNewConnection), update(iOldConnection), iOldConnection --> iNewConnection
  *
  * @param iNewConnection
  * @param iOldConnection
  * @param iOldInstance
  * @param iNewInstance
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterSplitAndUpdateOldConnection(const CATComponentId & iNewConnection, const CATComponentId & iOldConnection, const CATComponentId & iOldInstance, const CATComponentId & iNewInstance);


  /**
  * Register connection split and create of the old connection
  *  - Associates same logical family
  *  - Creates an historical dependency between new and old connection.
  *  - Creates an historical dependency between new aconnection and old instance.
  * Registers in log:
  * create(iNewConnection), create(iOldConnection), iOldConnection --> iNewConnection
  *
  * @param iNewConnection
  * @param iOldConnection
  * @param iOldInstance
  * @param iNewInstance
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterSplitAndCreateOldConnection(const CATComponentId & iNewConnection, const CATComponentId & iOldConnection, const CATComponentId & iOldInstance, const CATComponentId & iNewInstance);

  /**
    * Register a new instance for a logical clone
    *  - Associates same logical family
    *  - Creates an historical dependency between new and old instance
    *
    * @param iNewInstance
    * @param iOldInstance
    *
    * @return
    *      S_OK if request succeeded <br>
    *      E_FAIL if request failed <br>
    */
  static HRESULT RegisterInsertLogicalCloneInstances(const CATComponentId & iNewInstance, const CATComponentId & iOldInstance);

  /**
  * Register a new instance for a logical clone
  *  - Associates same logical family
  *  - Creates an historical dependency between new and old connection.
  *  - Creates an historical dependency between new aconnection and old instance.
  *
  * @param iNewConnection
  * @param iOldConnection
  * @param iOldInstance
  * @param iNewInstance
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterInsertLogicalCloneConnections(const CATComponentId & iNewConnection, const CATComponentId & iOldConnection, const CATComponentId & iOldInstance, const CATComponentId & iNewInstance);

  /**
* Register reroute connection by CCM
*  - Updates the UFO log
*
* @param iConnection
*   The connection rerouted by CCM
*
* @param iNewInstance
*   The instance that was created by the command insert a new logical clone
*
* @return
*      S_OK if request succeeded <br>
*      E_FAIL if request failed <br>
*/
  static HRESULT RegisterInsertLogicalCloneRerouteConnectionByCCM(const CATComponentId & iConnection, const CATComponentId & iNewInstance);

  /**
* Register deleted connection by CCM
*  - Updates the UFO log
*
* @param iConnection
*   The connection deleted by CCM
*
* @param iNewInstance
*   The instance that was created by the command insert a new logical clone
*
* @return
*      S_OK if request succeeded <br>
*      E_FAIL if request failed <br>
*/
  static HRESULT RegisterInsertLogicalCloneDeleteConnectionByCCM(const CATComponentId & iConnection, const CATComponentId & iNewInstance);

  /**
  * Register that CCM client foudn that the connection should not be ducplicated
  * because it would be useless in effectivity.
  *  - TEMPORARY SOLUTION: add create and delete actions, derived from
  *    the connexion. Thus CCM server will not duplicate it.
  *    Waiting for a real solution from server.
  *
  * @param iConnection
  *   The connection ignored by CCM
  *
  * @param iNewInstance
  *   The instance that was created by the command insert a new logical clone
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterInsertLogicalCloneIgnoreConnectionByCCM(const CATComponentId & iConnection, const CATComponentId & iNewInstance);

  /**
* Register connection after a logical clone and create of the old connection
*  - Associates same logical family
*  - Creates an historical dependency between new and old connection.
*  - Creates an historical dependency between new aconnection and old instance.
* Registers in log:
* create(iNewConnection), create(iOldConnection), iOldConnection --> iNewConnection
*
* @param iNewConnection
* @param iOldConnection
* @param iOldInstance
* @param iNewInstance
*
* @return
*      S_OK if request succeeded <br>
*      E_FAIL if request failed <br>
*/
  static HRESULT RegisterInsertLogicalCloneAndCreateOldConnection(const CATComponentId & iNewConnection, const CATComponentId & iOldConnection, const CATComponentId & iOldInstance, const CATComponentId & iNewInstance);

  /**
* Register connection after a logical clone and update of the old connection
*  - Associates same logical family
*  - Creates an historical dependency between new and old connection.
*  - Creates an historical dependency between new aconnection and old instance.
* Registers in log:
* create(iNewConnection), update(iOldConnection), iOldConnection --> iNewConnection
*
* @param iNewConnection
* @param iOldConnection
* @param iOldInstance
* @param iNewInstance
*
* @return
*      S_OK if request succeeded <br>
*      E_FAIL if request failed <br>
*/
  static HRESULT RegisterInsertLogicalCloneAndUpdateOldConnection(const CATComponentId & iNewConnection, const CATComponentId & iOldConnection, const CATComponentId & iOldInstance, const CATComponentId & iNewInstance);
};

#endif
