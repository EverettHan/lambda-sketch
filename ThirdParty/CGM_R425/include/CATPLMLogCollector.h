#ifndef CATPLMLogCollector_H 
#define CATPLMLogCollector_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMLog                         AuthorizedModule
#define osmMetaModelerProtocol            AuthorizedModule
#define CATOxiStreamModDispatching        AuthorizedModule
#define CATPLMClientCoreModel             AuthorizedModule
#define CATOmbLinks                       AuthorizedModule // Dirty for Ticket Synchro
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMLogCollector from a non-infrastructure module
@error 
#endif
#undef CATPLMLog
#undef osmMetaModelerProtocol
#undef CATOxiStreamModDispatching
#undef CATPLMClientCoreModel
#undef CATOmbLinks
// ----------------------------------------------------------------------------------------------------------------------
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATComponentId;


/**
* Collect data model modifications
*/
class ExportedByCATPLMTos CATPLMLogCollector
{
public:

  /**
  * Dispatch SD modification.
  *
  * @param iComponent
  *        The associated component.
  * @return
  *        S_OK    if request succeeded <br>
  *        E_FAIL  if request failed <br>
  */
  static HRESULT DispatchStreamModification (const CATComponentId & iComponent );

  /**
  * Dispatch Attribute modification.
  *
  * @param iComponent
  *        The associated component.
  * @return
  *        S_OK    if request succeeded <br>
  *        E_FAIL  if request failed <br>
  */
  static HRESULT DispatchAttributeModification (const CATComponentId & iComponent );

  /**
  * Dispatch Relation modification.
  *
  * @param iComponent
  *        The associated component.
  * @return
  *        S_OK    if request succeeded <br>
  *        E_FAIL  if request failed <br>
  */
  static HRESULT DispatchRelationModification (const CATComponentId & iComponent );

private :
  CATPLMLogCollector();
  ~CATPLMLogCollector();
};

#endif
