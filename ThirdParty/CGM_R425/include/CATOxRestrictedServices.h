#ifndef CATOxRestrictedServices_H 
#define CATOxRestrictedServices_H
//
// COPYRIGHT DASSAULT SYSTEMES 2009

/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMTos.h"
#include "IUnknown.h"
#include "CATDataType.h"
#include "CATBoolean.h"


class CATComponentId;
class CATOmxAny;
class CATUnicodeString;

/**
* Usage is restricted.
*/
class ExportedByCATPLMTos CATOxRestrictedServices
{
    friend class CATOmbRelationProperties ;
    friend class CATOxiMasterStampDirtyfication;
    friend class CATPCCFactoryServices;
    friend class CATOsmFastenerServices ;
    friend class CATOsmDumpAsMap ;
    friend class CATPLMOperationInput ;
private:

  /**
  * Returns stamp on a simple component
  * 
  * @param iSimpleComponent
  *        Simple component to work on
  * @param oMasterStamp
  *        The associated master stamp
  * @return
  *        S_OK     : if stamp available
  *        E_PENDING: if pointed object not found
  *        E_FAIL   : if stamp access failed
  */
    static HRESULT GetMasterStamp (const CATComponentId & iSimpleComponent, CATOmxAny & oMasterStamp) ;


 /**
  * Returns whether MasterStamp has been dirtyfied since open
  * 
  * @param iSimpleComponent
  *        Simple component to work on
  * @param iMasterStamp
  *        Current component master stamp
  * @param oIsMasterStampDirty
  *        TRUE     : Component's master stamp has been touched or component has just been created in session
  *        FALSE    : MasterStamp has not been touched since last open
  * @return
  *        S_OK           : everything went fine
  *        E_INVALIDARG   : failed to retrieve component
  */
    static HRESULT IsMasterStampDirtySinceOpen (const CATComponentId & iSimpleComponent, 
                                                CATOmxAny &iMasterStamp,
                                                CATBoolean & oIsMasterStampDirty) ;

    /**
     * Checks the discipline attribute value as cached on the componentId.
     * For complex componentIds, the attribute of the last element is retrieved.
     *
     * @param iComponent [in]
     *        Simple component to work on
     * @param oDiscipline [out]
     *        Current component master stamp
     * @return
     *        S_OK   : the attribute is found
     *        E_FAIL : failed to retrieve component or attribute not available.
     */
    static HRESULT GetDiscipline(const CATComponentId & iComponent, CATUnicodeString & oDiscipline);
};

#endif
