/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013

#ifndef CATAdpProtectedVersionMaker_H
#define CATAdpProtectedVersionMaker_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATSysErrorDef.h"
#include "CATBooleanDef.h"
#include "CATSysDataType.h"
#include "CATCollec.h"
class CATAdpProtectedComponentsAssociation;
class CATIAdpErrorMonitor;
class CATIAdpPLMIdentificator;
class CATListPtrCATIAdpPLMIdentificator;
class CATAdpProtectedVersionMakerImpl;
class CATTime;
class CATLISTV(CATPLMID);
class CATPLMIDSet;
class CATPLMID;
class CATOmbLifeCycleRootsBag;

/**
 * Class enabling to perform a new Version of a Component.
 * <br><b>Role</b>: <p>This class creates new Components which are versions of given Components if compliant with Versioning protocol.
 * In IRPC typing, only references and representations can be passed as input.</p>
 *
 * <p>A versioning scope is calculated dynamically. The following components may be transformed
 * (and returned in the result set) if aggregated under a given reference, even if not
 * specified in input :</p><ul>
 *   <li>Duplicated: Instances, Representation Instances, Connections and Ports</li>
 *   <li>Versioned: MonoInstanciated Representations</li></ul>
 *
 * Example of usage :
 * <pre>
 * CATAdpProtectedVersionMaker Versionator;
 * while(<there are components>)
 * {
 *   if(FAILED(Versionator.AddElement(pMyComp))
 *   //Error management
 * }
 * </pre>
 * Then :
 * <pre>
 * if(FAILED(Versionator.RunVersioning())
 * {
 *    CATIAdpPLMErrorMonitor pErrorReviewer = NULL;
 *    Versionator.GetErrorMonitor(pErrorReviewer);
 *    //manage errors
 *    CATSysReleasePtr(pErrorReviewer);
 * }
 * </pre>
 * Or :
 * <pre>
 * CATAdpComponentsAssociation versionedComponents;
 * if(SUCCEEDED(Versionator.RunVersioning(versionedComponents))
 * {
 *   CATAdpComponentsAssociationIter iter(versionedComponents.GetIterator());
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
class ExportedByCATPLMIntegrationAccess CATAdpProtectedVersionMaker
{
public:

  /**
   * Constructor
   * @param iApplicabilityDate [in]
   * The applicability date of the new version of the component.
   * @param iReplaceInSession [in]
   * Enables the user to ask for a replace in Authoring Session of the versioned Components by the new versions of the Components.
   * <ul>
   * <li>This will result in deletion of Instances of old versions and creation of Instances of new versions.</li>
   * <li>The Session is not saved. If you want the replace operation to be performed in the database, a Save operation is needed.<li>
   * </ul>
   * @param iopErrorMonitor [inout]
   * An error monitor dedicated to store and handle all PLM Errors raised during the execution of this service.
   * @see CATIAdpErrorMonitor
   */
  CATAdpProtectedVersionMaker(CATTime & iApplicabilityDate, CATBoolean iReplaceInSession =FALSE, CATIAdpErrorMonitor * iopErrorMonitor=nullptr);

  /**
   * Constructor
   * @param iopErrorReviewer
   * An error reviewer.
   * @see CATIAdpPLMErrorReviewer
   */
  CATAdpProtectedVersionMaker(CATIAdpErrorMonitor * iErrorMonitor=0);

  virtual ~CATAdpProtectedVersionMaker();

  /**
   * Add element to version<br/>
   * <b>Role</b>: Entry point to add elements for Versioning operation. The elements will be versioned only if the Version method is called.
   *
   * @param iComponent [in] : The Component to version.
   *   Elements must be of a PLM type compliant with Versioning protocol, else an error will be put in the error monitor at versioning time.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Component cannot be versioned. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT AddElement(CATIAdpPLMIdentificator * iComponent);
  HRESULT AddElement(const CATPLMID & iComponent);

  /**
   * Add elements to version<br/>
   * <b>Role</b>: Entry point to add elements for Versioning operation. The elements will be versioned only if the Version method is called.
   *
   * @param iComponents [in] : The Components to version.
   *   Elements must be of a PLM type compliant with Versioning protocol, else an error will be put in the error monitor at versioning time.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Components cannot be versioned. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT AddElements(const CATListPtrCATIAdpPLMIdentificator & iComponents);
  HRESULT AddElements(const CATLISTV(CATPLMID) & iComponents);

  /**
   * Launch Versioning operation on the server.<br/>
   *
   * <b>Role</b>: The new Versions are created on the server at this very moment.
   * Elements won't be replaced in session.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no version done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no version done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT RunVersioning();


  /**
   * Launch Versioning operation on the server.<br/>
   *
   * <b>Role</b>: The new Versions are created on the server at this very moment.
   * Elements won't be replaced in session.
   * This method will return the new versions pf the components.
   * The components which were not added to this class but which were versioned/duplicated though (eg. instances, connexions, ports...)
   * will be available in output.
   *
   * @param oComponentsAssociation [out]
   *   Association of original components and versions (output of versioning operation). Every versioned or duplicated component will be here.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no version done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no version done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT RunVersioning(CATAdpProtectedComponentsAssociation & oComponentsAssociation);

  /**
   * Add an Action the operation must be managed under.<br/>
   * <b>Role</b>: Enables the user to set an Action uner witch the operation will be managed.
   *
   * @param iAction [in] : The Action.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Action cannot be set.<dd>
   *   </dl>
   */
  HRESULT AddAction(CATIAdpPLMIdentificator * iAction);
  
	HRESULT AddAction(const CATPLMID & iAction);
	/**
   * Set the ability to version up from any version.<br/>
   * <b>Role</b>: Set the ability to version up from any version.
   *
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Set succeeded <dd>
   *   <dt><code>E_FAIL</code> Action cannot be set.<dd>
   *   </dl>
   */
	HRESULT FromAnyVersion();

	/**
   * Set the ability to replace components in session with the newly last created version.<br/>
   * <b>Role</b>: Set the ability to replace components in session with the newly last created version.
   * <ul>
   * <li>The use of this option will result in the deletion in the session of instances of the versioned component and the creation of instances of the new version.<li>
   * <li>The use of this option will lead to a failure if configuration is applied on instances of the versioned component or if the user has no rights to modify the instances of the versioned component</li>
   * </ul>
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Set succeeded <dd>
   *   <dt><code>E_FAIL</code> Action cannot be set.<dd>
   *   </dl>
   */
	HRESULT SetReplaceInSession();

  /**
   * If set, old and new components will be available in session.<br/>
   * <b>Role</b>: Set the ability to replace components in session with the newly last created version.
   * <ul>
   * <li>The use of this option will put old versions in the bag.<li>
   * <li>The use of this option will transfer modifications to the newly created version.<li>
   * <li>The use of this option will handle configuration</li>
   * </ul>
*
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Set succeeded <dd>
   *   <dt><code>E_FAIL</code> Action cannot be set.<dd>
   *   </dl>
   */
  HRESULT SetTransferModifications(const CATOmbLifeCycleRootsBag & ioBag);

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
  CATAdpProtectedVersionMaker (CATAdpProtectedVersionMaker &);
  /*
   * @nodoc
   */
  CATAdpProtectedVersionMaker& operator=(CATAdpProtectedVersionMaker&);

  CATAdpProtectedVersionMakerImpl *_pImpl;
};

//-----------------------------------------------------------------------

#endif
