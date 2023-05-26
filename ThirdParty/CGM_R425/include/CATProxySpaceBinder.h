#ifndef _CATProxySpaceBinder_H
#define _CATProxySpaceBinder_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
 * @level Private
 * @usage U1
 */
 // ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATPLMClientCoreServices          AuthorizedModule
#define CATPLMClientCoreModel          AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to link services from a non-infrastructure module
@error
#endif
#undef CATPLMTos
#undef CATPLMClientCoreServices
#undef CATPLMClientCoreModel

#include "ExportedByCATPLMTos.h"
#include "CATTosMacros.h"
#include "CATProxySpace.h"
#include "CATBoolean.h"

class CATComponentId;
class CATPLMTypeId;
class CATPLMOccurrenceWrapper;

class ExportedByCATPLMTos CATProxySpaceBinder
{
public:
  inline CATProxySpaceBinder(const CATProxySpace & iSpace) :_Space(iSpace) {}
  inline ~CATProxySpaceBinder() {}

  /**
  * Register a newly created component in TOS
  *
  * @param iEntity
  *        The component to be registered
  * @param iOwner
  *        The mandatory owner for PLMPort, PLMConnection and PLMInstance
  * @param iInstanceOf
  *        The mandatory reference for PLMInstance
  * @param iTargetSchema
  *        The PLMType of the component
  * @param oHandle
  *        The associated proxy
  * @return
  *      S_OK   : if succeeded
  *      E_FAIL : if failed
  */
  HRESULT  BindToCreate(CATBaseUnknown       & iEntity,
    CATBaseUnknown       * iOwner,
    CATBaseUnknown       * iInstanceOf,
    const CATPLMTypeId   & iTargetSchema,
    CATComponentId       & oHandle);

  /**
  *
  * Register a newly created component as an Overloaded of an Occurrence (OOD)
  *
  * @param iEntity
  *        The component that overloads the occurrence -- to be registered
  * @param iOccWrap
  *        The wrapper defining the occurrence that will be overloaded.
  * @param iOwner
  *        The mandatory owner for PLMPort, PLMConnection and PLMInstance
  * @param iInstanceOf
  *        The mandatory reference for PLMInstance
  * @param iTargetSchema
  *        The PLMType of the component
  * @param oHandle
  *        The associated proxy
  * @return
  *      S_OK         : if succeeded
  *      E_INVALIDARG : if the arguments are wrong
  *      E_FAIL       : if failed
  */
  HRESULT  BindToCreate(CATBaseUnknown          & iEntity,
    CATPLMOccurrenceWrapper * iOccWrap,
    CATBaseUnknown          * iOwner,
    CATBaseUnknown          * iInstanceOf,
    const CATPLMTypeId      & iTargetSchema,
    CATComponentId          & oHandle);

  /**
  *
  * Remove the overload of an occurence.
  *
  * @param iOccWrap
  *        The wrapper defining the occurrence that was overloaded.
  * @return
  *      S_OK         : if succeeded
  *      E_INVALIDARG : if the arguments are wrong
  *      E_FAIL       : if failed
  */
  HRESULT RemoveOOD(CATPLMOccurrenceWrapper * iOccWrap);

private:

  // Forbidden operators 
  CATProxySpaceBinder(CATProxySpaceBinder&);
  CATProxySpaceBinder& operator=(CATProxySpaceBinder&);

  CATProxySpace _Space;
};

#endif
