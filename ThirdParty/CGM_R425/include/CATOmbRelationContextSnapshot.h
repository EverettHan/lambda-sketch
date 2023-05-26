#ifndef CATOmbRelationContextSnapshot_H
#define CATOmbRelationContextSnapshot_H

// COPYRIGHT Dassault Systemes 2007

/**
* @level Protected
* @usage U1
*/

// BSFBuildtimeData
#include "CATIAV5Level.h"
// CATPLMIdentificationAccess
#include "CATListPtrCATIAdpPLMIdentificator.h"
#include "CATListPtrCATIPLMComponent.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"
#include "CATOmbRelationInformation.h"

class CATUnicodeString;

/**
* Snapshot of a relation context state
* <br><b>Role</b>: Aggregated by a @href CATOmbRelationSnapshot,
* the way to access this interface is CATOmbRelationSnapshot#GetContext.
* This class allows to retrive information on the context of a given relation.
* Object life cycle using AddRef () / Release () mechanism.
* @see CATOmbRelationSnapshot
*/
#if defined(CATIAR425)
#include "CATOmxSharable.h"
class ExportedByCATObjectModelerBase CATOmbRelationContextSnapshot : public CATOmxSharable
#else
#include "CATOmbUnknown.h"
class ExportedByCATObjectModelerBase CATOmbRelationContextSnapshot : public CATOmbUnknown
#endif
{
public:
  /**
  * Get the path of in session instances.
  * <br><b>Role</b>: The pointed component of a relation context is a
  * path of instances, this method is used to retrive it.
  * @param oInstance [out]
  *   The list of PLM instances retrived as a list of pointers
  *   (AddRef is done on each element). WARNING : only loaded instances are listed.
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>S_FALSE</code> if everything ran ok, but some instances are not loaded in session.
  *      Retrived list gives instances in session (it could be a empty list).
  */
  virtual HRESULT GetInstance(CATLISTP(CATIPLMComponent) & oInstance) const = 0;

  /**
   * Get the Adp PLM Identificators of the instances.
   * @param opiADpPLMIdentificator [out]
   *   The list of instances Adp PLM Identificators retrived as a list of pointers (AddRef is done on each
   *   element).
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if failed.
   */
  virtual HRESULT GetInstanceAdpPLMId(CATLISTP(CATIAdpPLMIdentificator) & opiADpPLMIdentificator) const = 0;

  /**
   * Get the alias of the instances.
   * @param oAlias [out]
   *   The returned alias, as a concatenation of each instances alias, separated by slash characters.
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>S_FALSE</code> if everything ran ok, but some pointed components are not loaded in session,
   *      and the corresponding alias are retrived from the cache of the last known alias.
   *   <code>E_FAIL</code> if failed.
   */
  virtual HRESULT GetInstanceAlias(CATUnicodeString & oAlias) const = 0;

  /**
  * Get information on context resolution and synchronization status.
  * @param oStatus [out]
  *   Enumerate value about resolution status, see CATOmbRelationInformation.h.
  * @param oSynchroStatus [out]
  *   Enumerate value about synchronization status, see CATOmbRelationInformation.h.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
  */
  virtual HRESULT GetRelationContextStatus(CATOmbRelationStatus & oStatus, CATOmbRelationSynchroStatus & oSynchroStatus) const = 0;
};

#endif
