/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpProtectedDuplicator_H
#define CATAdpProtectedDuplicator_H

#include "CATPLMIntegrationAccess.h"

#include "IUnknown.h"
#include "CATOmxOSet.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxOHMap.h"
#include "CATOmxSet.h"
#include "CATPLMID.h"
#include "CATLISTV_CATPLMID.h"
class CATUnicodeString;
class CATTime;
class CATIAdpErrorMonitor;
class CATIAdpPLMIdentificator;
class CATAdpCloneRequest;
class CATOmbLifeCycleRootsBag;
class CATAdpStdAttributeSet;
class CATAdpProtectedDuplicatorImpl;


/**
 * Class to duplicate (also known as plm clone) elements.
 * <br><b>Role</b>: <p>This class duplicates elements passed as input if they are duplicable.
 * Only references and representations can be passed as input.</p>
 *
 * <p>A duplication scope is calculated dynamically. The following component may be duplicated
 * (and returned in the result set) if aggregated under a given reference, even if not
 * specified in input :</p><ul>
 *   <li>Instances, Representation Instances, Connections and Ports</li>
 *   <li>MonoInstanciated Representations and their associated instance</li></ul>
 *
 * <p>If defined, the relevant PLMIdentificationInitialization business logic with 'Cloning'
 * OperationId will be called on every impacted reference or representation. If not defined
 * a default logic is applied by adding the given IdCloningString to the first string
 * attribute of the identifier set (most of the time the attribute PLM_ExternalID).</p>
 *
 * <p>If a specific attribute set is associated to a given component, those attributes will
 * applied after the attributes defined by the previous business logic. It may overwrite some
 * of them.</p>
 *
 * Example of usage :
 * <pre>
 * CATAdpProtectedDuplicator duplicator;
 * while(<there are components>)
 * {
 *   CATAdpAttributeSet attributeSet;
 *   // Code which specifies attributes to change, like attributes in the identificator set
 *   // ...
 *   if(FAILED(duplicator.AddElement(pMyComp, attributeSet))
 *   //Error management
 * }
 * </pre>
 * Then :
 * <pre>
 * if(FAILED(duplicator.Duplicate())
 * {
 *    CATIAdpPLMErrorReviewer pErrorReviewer = NULL;
 *    duplicator.GetErrorReviewer(pErrorReviewer);
 *    //manage errors
 *    CATSysReleasePtr(pErrorReviewer);
 * }
 * </pre>
 * Or :
 * <pre>
 * CATAdpComponentsAssociation duplicatedComponents;
 * if(SUCCEEDED(duplicator.Duplicate(duplicatedComponents))
 * {
 *   CATAdpComponentsAssociationIter iter(duplicatedComponents.GetIterator());
 *   CATOmxSR<CATIAdpPLMIdentificator> pSource, pDuplicated;
 *   while(S_OK == iter.NextComponent(SafePtrPtr(pSource), SafePtrPtr(pDuplicated)))
 *   {
 *      //Do something
 *   }
 * }
 * else
 * {
 *    CATOmxSR<CATIAdpPLMErrorReviewer> pErrorReviewer;
 *    duplicator.GetErrorReviewer(pErrorReviewer.AsPtrRef());
 *    //manage errors
 * }
 *</pre>
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedDuplicator
{
public:

  /**
   * It is recommended that you specify a non empty and unique iIdCloningString in the constructor.This
   * string will be passed as input to the PLMIdentificationInitialization business logic or be set as prefix of the identifier set if
   * no relevant business logic is found.If iIdCloningString is not specified and components are add this way, naming conflicts may
   * prevent the cloning operation.
   * @param iApplicabilityDate [in]
   * The applicability date of the new version of the component. If you don't know what's its purpose, just use the other constructor
   * @param iIdCloningString [in]
   * Cloning string applied to BLs. See above.
   * @param iopErrorMonitor [inout]
   * An error monitor dedicated to store and handle all PLM Errors raised during the execution of this service.
   * see @href CATIAdpErrorMonitor   */
  CATAdpProtectedDuplicator(const CATUnicodeString & iIdCloningString, const CATTime &iApplicabilityDate, CATIAdpErrorMonitor * iErrorMonitor = nullptr);

  // This is equivalent to specifying an empty applicability date. See @href CATAdpDuplicator::CATAdpDuplicator
  CATAdpProtectedDuplicator(const CATUnicodeString & iIdCloningString, CATIAdpErrorMonitor * iErrorMonitor = nullptr);

  /**
  * Add element to cloning<br/>
  * <b>Role</b>: Entry point to add elements for cloning operation. Those elements will be versioned only if the cloning method is called.
  *
  * @param iComponent [in] : The Component to version.
  *   Elements must be of duplicable type (Reference, RepReference, Entity...), else an error will be put in the error monitor at duplication time.
  *   Also see @href CATAdpCloneRequest
  * @return
  *   <dl>
  *   <dt><code>S_OK</code> Operation succeeded <dd>
  *   <dt><code>E_FAIL</code> Component cannot be versioned. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
  *   </dl>
  */
  HRESULT AddElement(const CATIAdpPLMIdentificator *iComponent);
  HRESULT AddElement(const CATIAdpPLMIdentificator *iComponent, const CATAdpStdAttributeSet &iAttrs);
  HRESULT AddElement(const CATPLMID & iComponent);
  HRESULT AddElement(const CATPLMID & iComponent, const CATAdpStdAttributeSet &iAttrs);
  
  /**
  * Add elements to cloning<br/>
  * <b>Role</b>: Entry point to add elements for cloning operation. Those elements will be versioned only if the cloning method is called.
  *
  * @param iComponents [in] : The Components to version.
  *   Elements must be of duplicable type (Reference, RepReference, Entity...), else an error will be put in the error monitor at duplication time.
  *   Also see @href CATAdpCloneRequest
  * @return
  *   <dl>
  *   <dt><code>S_OK</code> Operation succeeded <dd>
  *   <dt><code>E_FAIL</code> Component cannot be duplicated. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
  *   </dl>
  */
  HRESULT AddElements(const CATOmxSet<CATIAdpPLMIdentificator> & iComponents);
  HRESULT AddElements(const CATOmxOHMap<CATIAdpPLMIdentificator *, CATAdpStdAttributeSet> & iComponents);
  HRESULT AddElements(const CATOmxOrderedOSet<CATPLMID> & iComponents);
  HRESULT AddElements(const CATOmxOHMap<CATPLMID, CATAdpStdAttributeSet> & iComponents);

  /*
  * Set to keep the logical family on the resulting component.
  */
  HRESULT SetKeepFamily();

  /**
   * If set, old and new components will be available in session.<br/>
   * New object is created, and keeps the modifications. New objects are held by the input bag.
   * You can manually replace objects after is needed, using Replace operator (see @href PLMReplaceOperator).
   * <b>Role</b>: Set the ability to replace components in session with the newly last created version.
   * <ul>
   * <li>The use of this option will put old versions in the bag.<li>
   * <li>The use of this option will transfer modifications to the newly created version.<li>
   * <li>The use of this option will handle configuration</li>
   * </ul>
   */
  HRESULT SetTransferModifications(const CATOmbLifeCycleRootsBag & ioBag);

  /**
 * Set the ability to replace components in session with the newly last created version.<br/>
 * <b>Role</b>: Set the ability to replace components in session with the newly last created version.
 * <ul>
 * <li>The use of this option will result in the deletion in the session of instances of the versioned component and the creation of instances of the new version.<li>
 * <li>The use of this option will lead to a failure if configuration is applied on instances of the versioned component or if the user has no rights to modify the instances of the versioned component</li>
 * </ul>
 */
  HRESULT SetReplaceByNewInSession();

  /**
   * Launch duplication.<br/>
   *
   * <b>Role</b>: The duplication is done on the server at this very moment.
   * Elements are allowed to be in session.
   * See SetTransferModifications and SetReplaceByNewInSession if you want to make session operations like having new components in session, or replace old components by the new components.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>S_FALSE</code> Operation succeeded but at least one element has been removed from the duplication scope<dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT Duplicate();


  /**
  * Get the components which have been created during the transaction. This set includes the new clones of the input components
  * and the aggregated components which have been cloned together with the given input.
  * @output oIds: the new components.
  */
  HRESULT GetNewComponents(CATOmxOrderedOSet<CATPLMID> &oNewComponents);

  /**
  * Get every cloned components, each old being a key and each new clone being the corresponding value.
  * This map may contain more elements than passed in input (ie. the aggregated components which have been cloned together
  * with the given input).
  * You can get every source of versionned components using Keys() method on the map, and every result versionned components using Values() method on the map.
  * You can also get corresponding versionned elements using key and corresponding values.
  * You can also iterate on each pair of versions.
  * see @href CATOmxOHMap for more information on map usage.
  * @output oResults: map assiociation between old (source) and versionned components. It contains every versionned components.
  */
  HRESULT GetResults(CATOmxOHMap<CATIAdpPLMIdentificator*, CATIAdpPLMIdentificator*> & oComponentsAssociation);
  HRESULT GetResults(CATOmxOHMap<CATPLMID, CATPLMID> & oComponentsAssociation);

  /*
  * An error monitor is always created (if not specified in constructor, a new one is created)
  * @param oErrorMonitor [out, CATBaseUnknown#Release]
  *   Monitor containing errors
  * see @href CATIAdpErrorMonitor
  */
  HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorMonitor);


  ~CATAdpProtectedDuplicator();
private:
  CATAdpProtectedDuplicatorImpl *m_impl{ nullptr };
};
#endif
