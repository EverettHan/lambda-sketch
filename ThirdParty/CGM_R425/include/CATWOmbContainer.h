/**
 * @level Private
 * @usage U1
 */
#ifndef __CATWOmbContainer_H
#define __CATWOmbContainer_H

#include "AD0XXBAS.h"
#include "CATOmxIter.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATUuid.h"
#include "CATOmxQIPtr.h"
class CATIOmbPlug;
class CATDocument;

#define OMB_WCONT_RECURSIVE    0x1
#define OMB_WCONT_INCLUDE_THIS 0x2

/** 
 * Wrapper on a container.
 * Aim is to simplify and centralize use of various historical interfaces
 * CATIContainer/CATIPersistStorage/CATIUuid/CATIUserId/CATIAscendant/CATILinkableObject and CATDocument
 * Notice that it is not guaranteed to give the same results as classical interfaces.
 */
class ExportedByAD0XXBAS CATWOmbContainer
{
  CATOmxQIPtr<CATIOmbPlug> m_container;
public:
  /**default constructor*/
  inline CATWOmbContainer() {}
  /**Initialize from a container*/
  CATWOmbContainer(const CATBaseUnknown* iContainer) {this->operator=(iContainer);}
  /**Copy constructor*/
  CATWOmbContainer(const CATWOmbContainer& iContainer) {this->operator=(iContainer);}
  /**Initialize from a container*/
  CATWOmbContainer& operator=(const CATBaseUnknown* iContainer);
  /**Copy operator*/
  CATWOmbContainer& operator=(const CATWOmbContainer& iContainer);

  /**Initialize from root container of input document (CATDocument::GetRootContainer)*/
  CATWOmbContainer& BindToRootContainer(const CATDocument* iDocument);

  /**Initialize from compound container of input document (CATDocument::GetCompoundContainer)*/
  CATWOmbContainer& BindToCompoundContainer(const CATDocument* iDocument);

  /**Initialize to first applicative container of input document (under compound container) corresponding to UserId, does not load it*/
  CATWOmbContainer& BindToApplicativeContainer(const CATDocument* iDocument,const CATUnicodeString& iUserId);

  /**Returns container's document (CATILinkableObject::GetDocument)*/
  CATDocument* GetDocument();

  //Returns the container CATBaseUnknown
  CATOmxSR<CATBaseUnknown> GetContainer();

  /**Returns container's father (CATIAscendant::GetFather)*/
  CATOmxSR<CATBaseUnknown> GetParent(CATBoolean iHideCATModel = TRUE);

  /**Returns container's document root container (CATDocument::GetRootContainer)*/
  CATOmxSR<CATBaseUnknown> GetRootContainer();

  /**Returns container's document compound container (CATDocument::GetCompoundContainer)*/
  CATOmxSR<CATBaseUnknown> GetCompoundContainer();

  /**
   * Returns aggregated containers (CATIContainer::ListMembers/GetListContainers)
   * @param iFlags
   *   combination of 
   *     OMB_WCONT_RECURSIVE (recursively list container children)
   *     OMB_WCONT_INCLUDE_THIS (include this as first item in returned iterator)
   *   GetListContainers behavior can be emulated by using OMB_WCONT_RECURSIVE|OMB_WCONT_INCLUDE_THIS flags.
   */
  CATOmxIter<CATBaseUnknown> GetSubContainers(int iFlags = 0);

  /**
   * list all root "applicative" containers, ie containers directly under "the" compound container
   */
  static CATOmxIter<CATBaseUnknown> GetApplicativeContainers(const CATDocument* iDocument);

  /**
   * Check load state (CATIPersistStorage::IsLoaded).
   * returns
   *   S_OK: container is loaded
   *   S_FALSE: container is not loaded
   *   E_INVALIDARG: not a valid container
   *   E_ACCESSDENIED: container is being loaded
   *   E_FAIL: container failed to load
   */
  HRESULT IsLoaded();

  /**
   * Load container (CATIPersistStorage::Load).
   * returns
   *   S_OK: container has been loaded
   *   S_FALSE: container is yet loaded
   *   E_INVALIDARG: not a valid container
   *   E_ACCESSDENIED: container is being loaded
   *   E_FAIL: container failed to load
   */
  HRESULT Load();

  /**Returns TRUE if wrapper is bound a non CATBaseUnknown::IsNull container.*/
  CATBoolean IsValid();

  /**Returns late type of the container.*/
  CATUnicodeString GetLateType();

  /**Returns uuid of the container (CATIUuid::GetUuid).*/
  CATUuid GetUuid();

  /**Returns uuid of the container (CATIUserId::GetUserId).*/
  CATUnicodeString GetUserId();

  /**Returns implementation of the container.*/
  CATBaseUnknown* GetImpl();

  /**
   * Returns TRUE if container is an applicative container (aggregated by compound container).
   * @param iIsDirectCompoundChild
   *  if TRUE, returns TRUE if container is directly aggregated by compound container
   *  if FALSE, returns TRUE if container is directly or indirectly aggregated by compound container
   */
  CATBoolean IsApplicative(CATBoolean iIsDirectCompoundChild = FALSE);

  /** Returns TRUE if container is a root container.*/
  CATBoolean IsRoot();

  /** Returns TRUE if container is a compound container container.*/
  CATBoolean IsCompound();
};




#endif
