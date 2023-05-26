// COPYRIGHT Dassault Systemes 2013

#ifndef PLMLinkFacade_H
#define PLMLinkFacade_H

#include "CATObjectModelerBase.h"
#include "PLMPublicLinkFacade.h"
#include "CATOmxPortability.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxVector.h"
#include "CATOmxList.h"

class CATOmbLinkSource;
class CATOmbLink;
class PLMIOmbVirtualObjectDescriptor;
class CATIOmbProxySpecifications;
class CATIOmbFunction;
class CATPLMID;
class CATBaseUnknown;
class CATOmbTargetPath;
class CATOmbPathOfComponentId;

class PLMLinkFacade;
template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<PLMLinkFacade>::manager();

/**
 * Extended API for PLMPublicLinkFacade (DS internal)
 */
class ExportedByCATObjectModelerBase PLMLinkFacade : public PLMPublicLinkFacade
{
public:
  /**
   * returns false if this object is bound to a link.
   * notice that if you build a (valid) PLMLinkFacade and then destroy corresponding link,
   * IsNull will continue to return false even though all methods will fail and return E_PLMLINK_INVALIDFACADE
   */
  inline bool IsNull() const { return !_pImpl; }

  /** default constructor*/
  inline PLMLinkFacade() {}
  /** copy constructor */
  inline PLMLinkFacade(const PLMPublicLinkFacade& iFacade) :PLMPublicLinkFacade(iFacade) {}
  /** copy operator */
  inline PLMLinkFacade &operator = (const PLMPublicLinkFacade& iFacade) { return static_cast<PLMLinkFacade&>(PLMPublicLinkFacade::operator=(iFacade)); }

  /** internal constructor reserved for OSM & PC2 */
  explicit PLMLinkFacade(CATOmbLink* iLink);

  /**
   * Retrieve the target component id (or path of components).
   * Works for an unsolved or broken relation.
   * For a minor-unsensitive relation, the target might be (partially) resolved to a a minor equivalent loaded in current session.
   * @see PLMPublicLinkFacade::GetPointedComponentIdentifiers
   *
   * limitations
   *   does not work for a contextual link
   *   does not work for an intra-component link
   */
  HRESULT GetTargetId(CATPLMID& oId) const;
  CATPLMID GetTargetId() const;

  /**
   * retrieve a PLMIOmbVirtualObjectDescriptor for this link.
   * @param iFold
   *   if false and if the target is a publication then the target publication will be replaced by the publication's target (read that several times until it gets meaning)
   * @param iProxySpecs
   *   proxy specification, ask MechanicalModeler team (optional)
   * @param iFunction
   *   resolution function , ask MechanicalModeler team (optional)
   *
   * @return
   *   a HRESULT which can be analyzed using CATOmbLinkStatusServices::GetLinkStatusFromRc
   */
  HRESULT GetVOD(CATBoolean iFold, CATIOmbProxySpecifications* iProxySpecs, CATIOmbFunction* iFunction, CATOmxSR<PLMIOmbVirtualObjectDescriptor>& oVOD) const;
  CATOmxSR<PLMIOmbVirtualObjectDescriptor> GetVOD(CATBoolean iFold = TRUE, CATIOmbProxySpecifications* iProxySpecs = NULL, CATIOmbFunction* iFunction = NULL) const;


  /**
   * retrieve a PLMIOmbVirtualObjectDescriptor for this link using “Geometrical Reroute”: 
   During this operation, geometric data of the previous topology (estimated center and normal vector) are used to retrieve the new topology in the new body.
   * @return
   *   a HRESULT which can be analyzed using CATOmbLinkStatusServices::GetLinkStatusFromRc
   */
#ifdef CATIAR425
  HRESULT ComputeVODWithProxy(CATOmxSR<PLMIOmbVirtualObjectDescriptor>& oVOD) const;
#endif // 

  

  /**
   * same as GetTargetId but returns PLM components loaded in session
   *
   * contrarily to GetTargetId, fails if target PLM components are not loaded
   *
   * @return
   *   a HRESULT which can be analyzed using CATOmbLinkStatusServices::GetLinkStatusFromRc
   */
  HRESULT GetTargetComponents(CATOmxList<CATBaseUnknown>& oPath) const;

  /**
   * Break APIs.
   * @return
   *   An HRESULT value.
   *   <br><b>Legal values</b>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>It succeeded.</dd>
   *     <dt>E_PLMLINK_INVALIDFACADE</dt>
   *     <dd> The Facade is not valid.</dd>
   *     <dt>E_UNEXPECTED</dt>
   *     <dd>The query failed or partially failed for any other reason.</dd>
   *  </dl>
   */
  HRESULT Break();
  HRESULT BreakBundle();

  /**
  * retrieve the set of links that goes through a semantic relation matching provided arguments:
  * @param iLastTargetComponent
  *   the last element of the path of the pointing relation
  * @param iRole
  *   the role of the pointing relation
  *
  * notice:
  *   contextual links are not supported
  *   intra-component links are not returned
  */
  static CATOmxIter<const PLMLinkFacade> GetPointingLinksThroughRelationLastElementAndRole(const CATBaseUnknown* iLastTargetComponent, const CATUnicodeString& iRole);

  /**
  * retrieve the set of links that goes through a semantic relation matching provided arguments:
  * @param iTargetPath
  *   the target path of the pointing relation
  *   A full match is performed
  *   An input path containing two items [ I1, I2 ] will not match
  *      [ I0, I1, I2 ]
  *      [ I1, I2, I3  ]
  *      [ I2, I1 ]
  * @param iRole
  *   the role of the pointing relation
  *
  * notice:
  *   contextual links are not supported
  *   intra-component links are not returned
  */
  static CATOmxIter<const PLMLinkFacade> GetPointingLinksThroughRelationTargetPathAndRole(const CATOmbTargetPath& iTargetPath, const CATUnicodeString& iRole);

  /**
  * retrieve the set of links that goes through a semantic relation matching provided arguments:
  * @iSourceComponent:
  *   the source PLM component (the PLM component which holds the pointing semantic relation)
  * @param iRole
  *   the role of the pointing relation
  * @param iTargetPath
  *   the target path of the pointing relation
  *   A full match is performed
  *   An input path containing two items [ I1, I2 ] will not match
  *      [ I0, I1, I2 ]
  *      [ I1, I2, I3  ]
  *      [ I2, I1 ]
  *
  * notice:
  *   contextual links are not supported
  *   intra-component links are not returned
  */
  static CATOmxIter<const PLMLinkFacade> GetLinksForSourceRoleAndTargetPath(const CATBaseUnknown* iSourceComponent, const CATUnicodeString& iRole, const CATOmbPathOfComponentId& iTargetPath);
  static CATOmxIter<const PLMLinkFacade> GetLinksForSourceRoleAndTargetPath(const CATBaseUnknown* iSourceComponent, const CATUnicodeString& iRole, const CATOmbTargetPath& iTargetPath);

  /**
   * return the pointing object or null if the link is invalid
   */
  CATOmxSR<CATBaseUnknown> GetPointingObject() const;

  /**
     * Desynchronize the link (See IsSynchronized).
     * @return
     *   An HRESULT value.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *     <dd>The link desynchronization succeeded.</dd>
     *     <dt>S_FALSE</dt>
     *     <dd>The link is already desynchronized.</dd>
     *     <dt>E_PLMLINK_NOSYNCHRONIZATIONBEHAVIOR</dt>
     *     <dd> No Synchronization behavior is defined on the Link.</dd>
     *     <dt>E_PLMLINK_INVALIDFACADE</dt>
     *     <dd> The Facade is not valid.</dd>
     *     <dt>E_UNEXPECTED</dt>
     *     <dd>The query failed for any other reason.</dd>
     *  </dl>
     */
  HRESULT Desynchronize();
};

#endif

