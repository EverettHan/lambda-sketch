/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2014

#ifndef CATAdpProtectedAdvancedDuplicator_H
#define CATAdpProtectedAdvancedDuplicator_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATSysErrorDef.h"
#include "CATBooleanDef.h"
#include "CATSysDataType.h"
#include "CATCollec.h"
#include "CATOmxOHMap.h"
#include "CATPLMID.h"
class CATAdpProtectedComponentsAssociation;
class CATIAdpErrorMonitor;
class CATIAdpPLMIdentificator;
class CATListPtrCATIAdpPLMIdentificator;
class CATAdpProtectedAdvancedDuplicatorImpl;
class CATTime;
class CATLISTV(CATPLMID);
class CATPLMIDSet;
class CATAdpStdAttributeSet;

/**
 * Class enabling to perform an advanced duplicate of a set of Components.
 * <br><b>Role</b>: <p>This class creates new Components which are duplicates of given Components if compliant with duplicate protocol.
 * In IRPC typing, only references and representations and instances can be passed as input.</p>
 *
 * <p>A duplication scope is calculated dynamically. The following component may be duplicated
 * (and returned in the result set) if aggregated under a given reference, even if not
 * specified in input :</p><ul>
 *   <li>Connections and Ports</li>
 *   <li>MonoInstanciated Representations if associated instance is given as input</li></ul>
 *   <li>Only Instances given as input will be duplicated</li>
 *
 * <p>If defined, the relevant PLMIdentificationInitialization business logic with 'Cloning'
 * OperationId will be called on every impacted reference or representation. If not defined
 * a default logic is applied by adding the given IdCloningString to the first string
 * attribute of the identifier set (most of the time the attribute PLM_ExternalID).</p>
 *
 * <p>If a specific attribute set is associated to a given component, those attributes will be
 * applied after the attributes defined by the previous business logic. It may overwrite some
 * of them.</p>
 *
 * Behavior description base on following existing structure (please refer to Server PES for PLMCopy command for enhanced behaviors):
 *
 * Ref1
 * + MonoRepInst1 - MonoRep1
 * + MonoRepInst2 - MonoRep2
 * + Inst21 - Ref2
 *            + Inst31 - Ref3
 *                       + RepInst11 - RepRef1
 * + Inst41 - Ref4
 *            + Inst51 - Ref5
 *                       + RepInst21 - RepRef2
 * + Cnx1 (pointing: Ref3)
 * + Cnx2 (pointing: Ref5)
 *
 * *** Input (Ref1, Inst21, Ref2, Inst31, Ref3, RepInst11, RepRef1, Inst41, Ref4, Inst51), Result is:
 * Ref1A
 * + Inst21A - Ref2A
 *             + Inst31A - Ref3A
 *                         + RepInst11A - RepRef1A
 * + Inst41A - Ref4A
 *             + Inst51A - Ref5
 * + Cnx1A (pointing: Ref3A)
 * + Cnx2A (pointing: OutOfScope)
 *
 * *** Input (Ref1, MonoRepInst1, MonoRep1, MonoRepInst2), Result is:
 * Ref1A
 * + MonoRepInst1A - MonoRep1A
 * + Cnx1A (pointing: OutOfScope)
 * + Cnx2A (pointing: OutOfScope)
 *
 * *** Input (Ref1, Inst21, Ref2, Inst31, Ref3), Result is:
 * Ref1A
 * + Inst21A - Ref2A
 *             + Inst31A - Ref3A
 * + Cnx1A (pointing: Ref3A)
 * + Cnx2A (pointing: OutOfScope)
 *
 * Example of usage :
 * <pre>
 * CATAdpProtectedAdvancedDuplicator Duplicator;
 * while(<there are components>)
 * {
 *   if(FAILED(Duplicator.AddComponentToDuplicate(pMyComp))
 *   //Error management
 * }
 * </pre>
 * Then :
 * <pre>
 * if(FAILED(Duplicator.RunDuplicate())
 * {
 *    CATIAdpPLMErrorMonitor pErrorReviewer = NULL;
 *    Versionator.GetErrorMonitor(pErrorReviewer);
 *    //manage errors
 *    CATSysReleasePtr(pErrorReviewer);
 * }
 * </pre>
 * Or :
 * <pre>
 * CATAdpProtectedComponentsAssociation duplicatedComponents;
 * if(SUCCEEDED(Duplicator.RunDuplicate(duplicatedComponents))
 * {
 *   CATAdpProtectedComponentsAssociationIterator iter(duplicatedComponents.GetIterator());
 *   CATIAdpPLMIdentificator *pSource, *pEvolved = NULL;
 *   while(S_OK == iter.NextComponent(pSource, pEvolved))
 *   {
 *      //Do something
 *      CATSysReleasePtr(pSource);
 *      CATSysReleasePtr(pEvolved);
 *   }
 * }
 * else
 * {
 *    CATIAdpErrorMonitor *pErrorReviewer = NULL;
 *    Evolutor.GetErrorMonitor(pErrorReviewer);
 *    //manage errors
 *    CATSysReleasePtr(pErrorReviewer);
 * }
 *</pre>
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedAdvancedDuplicator
{
public:

  /**
   * Constructor
   * @param iIdCloningString [in]
   * Default logic to be applied.
   * @param iApplicabilityDate [in]
   * The applicability date of the new component.
   * @param iErrorMonitor
   * An error reviewer.
   * @see CATIAdpErrorMonitor
   */
  CATAdpProtectedAdvancedDuplicator(const CATUnicodeString & iIdCloningString, const CATTime & iApplicabilityDate, CATIAdpErrorMonitor * iErrorMonitor);

  /**
   * Constructor
   * @param iErrorMonitor
   * An error reviewer.
   * @see CATIAdpErrorMonitor
   */
  CATAdpProtectedAdvancedDuplicator(CATIAdpErrorMonitor * iErrorMonitor=0);

  virtual ~CATAdpProtectedAdvancedDuplicator();

  /**
   * Add element to duplicate<br/>
   *
   * <b>Role</b>: Entry point to add elements to duplication. The elements will be duplicated only if the Duplicate method is called.
   * When using this method, it is recommended that you also specify a non empty and unique iIdCloningString in the constructor. This
   * string will be passed as input to the PLMIdentificationInitialization business logic or be set as prefix of the identifier set if
   * no relevant business logic is found. If iIdCloningString is not specified and components are add this way, naming conflicts may
   * prevent the cloning operation.
   * Please note that CAA attributes are always copied.
   *
   * @param *iComponent [in] : The element to duplicate.
   *   Elements must be of duplicable type (Reference, RepReference, Instance, RepInstance), else an error will be put in the error monitor at duplication time.
   *   In cas of Instance or RepInstance, you must specify last parameter (Reference or RepReference owner)

   * @param &iOwner [in] : 
   *   Specify instance with its Owner, only in case of Instance or RepInstance. 
   *   In case of iComponent being a Reference or RepReference, parameter will be ignored.
   * 
   * Important notice
   * If instance's owner is not specified, owner will be searched in session or in database if not provided. 
   * This is a legacy API workaround, you should specify owner in map second parameter in case of instance, and CATPLMID_Null or nullptr in other case.

   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT AddComponentToDuplicate(CATIAdpPLMIdentificator * iComponent, CATIAdpPLMIdentificator* iOwner = nullptr);
  HRESULT AddComponentToDuplicate(const CATPLMID & iComponent, const CATPLMID &iOwner = CATPLMID_Null);


  /**
   * Add element to duplicate with specific attributes to be set on the clone.<br/>
   *
   * <b>Role</b>: Entry point to add elements to duplication. The elements will be duplicated only if the Duplicate method is called.
   * The attribute set @href CATAdpAttributeSet is associated to the adp identificator @href CATIAdpPLMIdentificator. The given attributes
   * will complete and may overwrite the ones retrieved through the PLMIdentificationInitialization business logic.
   * Please note that CAA attributes are always copied.
   *
   * @param *iComponent [in] : The element to duplicate.
   *   Elements must be of duplicable type (Reference, RepReference, Instance, RepInstance), else an error will be put in the error monitor at duplication time.
   *   In cas of Instance or RepInstance, you must specify last parameter (Reference or RepReference owner)
   *
   * @param &iAdpAttributeSet [in] : The attributes which will be overriden.
   *
   * @param &iOwner [in] : 
   * Specify instance with its Owner, only in case of Instance or RepInstance. 
   * In case of iComponent being a Reference or RepReference, parameter will be ignored.
   * 
   * Important notice
   * If instance's owner is not specified, owner will be searched in session or in database if not provided. 
   * This is a legacy API workaround, you should specify owner in map second parameter in case of instance, and CATPLMID_Null or nullptr in other case.
   * 
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT AddComponentToDuplicate(CATIAdpPLMIdentificator * iComponent, const CATAdpStdAttributeSet &iAdpAttributeSet, CATIAdpPLMIdentificator* iOwner = nullptr);
  HRESULT AddComponentToDuplicate(const CATPLMID & iComponent, const CATAdpStdAttributeSet &iAdpAttributeSet, const CATPLMID& iOwner = CATPLMID_Null);

  /**
   * @deprecated R423 AddComponentsToDuplicate
   * Use methods with maps
   */
  HRESULT AddComponentsToDuplicate(const CATListPtrCATIAdpPLMIdentificator & iComponents);
  HRESULT AddComponentsToDuplicate(const CATLISTV(CATPLMID) & iComponents);

  /**
   * Add elements to duplicate<br/>
   *
   * <b>Role</b>: Entry point to add elements to duplication. The elements will be duplicated only if the Duplicate method is called.
   * When using this method, it is recommended that you also specify a non empty and unique iIdCloningString in the constructor. This
   * string will be passed as input to the PLMIdentificationInitialization business logic or be set as prefix of the identifier set if
   * no relevant business logic is found. If iIdCloningString is not specified and components are add this way, naming conflicts may
   * prevent the cloning operation.
   * Please note that CAA attributes are always copied.
   *
   * @param &iCompToOwner [in] : 
   * Specify instance with its Owner, only in case of instance. 
   * Or specify reference without any association (association will be ignored in this case)
   * 
   * Important notice
   * If instance's owner is not specified, owner will be searched in session or in database if not provided. 
   * This is a legacy API workaround, you should specify owner in map second parameter in case of instance, and CATPLMID_Null or nullptr in other case.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT AddComponentsToDuplicate(const CATOmxOHMap<CATPLMID, CATPLMID> & iCompToOwner);
  HRESULT AddComponentsToDuplicate(const CATOmxOHMap<CATIAdpPLMIdentificator*, CATIAdpPLMIdentificator*>& iCompToOwner);

  /**
   * Launch duplication.<br/>
   *
   * <b>Role</b>: The duplication is done on the server at this very moment.
   * Elements are allowed to be in session.
   * Elements won't be replaced in session.
   * This method won't return the cloned components.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT RunDuplicate();


  /**
   * Launch duplication.<br/>
   *
   * <b>Role</b>: The duplication is done on the server at this very moment.
   * Elements are allowed to be in session.
   * Elements won't be replaced in session.
   * This method will return the cloned components.
   * The components which were not added to this class but which were duplicated though (ie. instances, connexions, ports...)
   * will be present in output.
   *
   * @param oComponentsAssociation [out]
   *   Association of original components and duplicata (output of duplication). Every duplicated component will be here.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no duplication done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT RunDuplicate(CATAdpProtectedComponentsAssociation & oComponentsAssociation);

	/**
   * Set the ability to keep the family of the given components.<br/>
   * <b>Role</b>: Set the ability to keep on the clone the family of the given component.
   *
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Set succeeded <dd>
   *   <dt><code>E_FAIL</code> failure.<dd>
   *   </dl>
   */
	HRESULT KeepFamily();

  /**
   * Get the error monitor.
   * @param oErrorMonitor [out, CATBaseUnknown#Release]
   *   Reviewer containing errors
   * @see CATIAdpErrorMonitor
   */
  HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorMonitor);

private:
  /*
   * @nodoc
   */
  CATAdpProtectedAdvancedDuplicator (CATAdpProtectedAdvancedDuplicator &);
  /*
   * @nodoc
   */
  CATAdpProtectedAdvancedDuplicator& operator=(CATAdpProtectedAdvancedDuplicator&);

  CATAdpProtectedAdvancedDuplicatorImpl *_pImpl;
};
#endif
