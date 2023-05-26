// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATPLMSpaceServices.h
// Define the CATPLMUFOLogRegistrationServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Nov 2005  Creation: Code generated by the CAA wizard  JS6
//===================================================================
/**
* @level Protected
* @usage U1
*/

#ifndef  CATPLMUFOLogRegistrationServices_H
#define CATPLMUFOLogRegistrationServices_H

#include "CATPLMIdentificationAccessRestrictedCCM.h"
#include "CATSysErrorDef.h"
#include "CATListPtrCATIPLMComponent.h"

class CATIPLMComponent;
class CATUnicodeString;

class ExportedByCATPLMIdentificationAccessRestrictedCCM CATPLMUFOLogRegistrationServices
{
public:
  /**
   * Register modification of applicability
   *
   * @param iUpdatedApplicability
   *
   * @return
   *      S_OK if request succeeded <br>
   *      E_FAIL if request failed <br>
   */
  static HRESULT RegisterModifyApplicability(const CATIPLMComponent & iUpdatedApplicability);

  /**
 * Register an operation on the last event for a given component
 *
 * @param iComponent
 * @param iOperation, the name of the operation
 *
 * @return
 *      S_OK if request succeeded <br>
 *      E_FAIL if request failed <br>
 */
  static HRESULT RegisterOperation(const CATListPtrCATIPLMComponent & iComponents, const CATUnicodeString & iOperation);
  static HRESULT RegisterOperation(const CATIPLMComponent & iComponent, const CATUnicodeString & iOperation);

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
  static HRESULT RegisterSplitAndUpdateOldConnection(const CATIPLMComponent & iNewConnection, const CATIPLMComponent & iOldConnection, const CATIPLMComponent & iOldInstance, const CATIPLMComponent & iNewInstance);


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
  static HRESULT RegisterSplitAndCreateOldConnection(const CATIPLMComponent & iNewConnection, const CATIPLMComponent & iOldConnection, const CATIPLMComponent & iOldInstance, const CATIPLMComponent & iNewInstance);


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
  static HRESULT RegisterLogicalCloneAndCreateOldConnection(const CATIPLMComponent & iNewConnection, const CATIPLMComponent & iOldConnection, const CATIPLMComponent & iOldInstance, const CATIPLMComponent & iNewInstance);

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
  static HRESULT RegisterLogicalCloneAndUpdateOldConnection(const CATIPLMComponent & iNewConnection, const CATIPLMComponent & iOldConnection, const CATIPLMComponent & iOldInstance, const CATIPLMComponent & iNewInstance);

};

#endif
