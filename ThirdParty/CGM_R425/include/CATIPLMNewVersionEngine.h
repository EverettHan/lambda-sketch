/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
#ifndef CATIPLMNewVersionEngine_H
#define CATIPLMNewVersionEngine_H


/**
 * @level Protected
 * @usage U3
 */


#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMVersioningEngineAbstract.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMNewVersionEngine;
#else
extern "C" const IID IID_CATIPLMNewVersionEngine;
#endif

/**
 * This interface defines the unique protocol of communication between the users and the new version engine.
 * Use @href CATPLMIntegration.CATPLMEngineToolbox#GetNewVersionEngine to get a pointer on the new version engine.
 * Globally, the user can:
 * <ul>
 * <li>Ask for a new version operation to be performed on a component and specify a set of parameters for this new version operation.</li>
 * <li>Retrieve the new components available after the operation.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMNewVersionEngine: public CATIPLMVersioningEngineAbstract
{
  CATDeclareInterface;

public:

/**
 * Description of the two modes for new version.
 * <dt> <code>Classical</code>                              <dd> The default use mode.
 * <ul>
 * <li> The operation will concern a versioning of last versions of components versioning families.</li>
 * <li> The current version in client session is not changed. No modification is performed in the authoring session.</li>
 * </ul>
 * <dt> <code>Classical_WithSessionModification</code>      <dd> The new version is going to be used in the current authoring session instead of the old version.
 * <ul>
 * <li> The operation will concern a versioning of last versions of components versioning families.</li>
 * <li> It results as a destruction of the instance of the old version of the component in the session.</li>
 * <li> It results as a creation of an instance of the new version of the component in the session and its aggregation under the owner of the old version.</li>
 * <li> These operations will be propagated to the server on next @href CATIPLMSaveEngine#Save call.</li> 
 * </ul>
 * <dt> <code>FromAnyVersion</code>                         <dd> Advanced use.
 * <ul>
 * <li> The operation will concern a versioning of any component of components versioning families.</li>
 * <li> It means that the data of the new version will be initialized from the old version provided.</li>
 * <li> The current version in client session is not changed. No modification is performed in the authoring session.</li>
 * </ul>
 * <dt> <code>FromAnyVersion_WithSessionModification</code> <dd> Advanced use.
 * <ul>
 * <li> The operation will concern a versioning of any component of components versioning families.</li>
 * <li> It means that the data of the new version will be initialized from the old version provided.</li>
 * <li> It results as a destruction of the instance of the old version of the component in the session.</li>
 * <li> It results as a creation of an instance of the new version of the component in the session and its aggregation under the owner of the old version.</li>
 * <li> These operations will be propagated to the server on next @href CATIPLMSaveEngine#Save call.</li> 
 * </ul>
 * <dt> <code>IntoFamily</code>                             <dd> Advanced use.
 * <ul>
 * <li> The operation will concern a versioning of a component by injecting this component into an existing or a new version family.</li>
 * <li> It means that the data of the new version will be initialized both from the component provided and the component defining the version family to enrich.</li>
 * <li> The current component in client session is not changed. No modification is performed in the authoring session.</li>
 * <li> This mode won't be available together with the "WithSessionModification" flag. </li>
 * </ul>
 */
  enum VersioningMode { Classical=0, Classical_WithSessionModification=1, 
                        FromAnyVersion=2, FromAnyVersion_WithSessionModification=3,
                        IntoFamily=4,
                        /*deprecated, seen as Classical*/Simple=0, 
                        /*deprecated, seen as Classical_WithSessionModification*/WithSessionModification=1,
                        Classical_TransferModifications = 7,
                        FromAnyVersion_TransferModifications = 8};

/** 
 * Adds a versioning datum for further treatment by the engine.
 *
 * <br><b>Role</b>: Enables to add a versioning datum in the set of data which will be treated when calling the 
 * @href CATIPLMVersioningEngineAbstract#RunVersioningOperation.
 * <ul>
 * <li> This entry point can only be used in other mode than IntoFamily. A call to this entry point in IntoFamily
 * mode will result in a E_ACCESSDENIED return.</li> 
 * </ul>
 *
 * @param iComponent [in]
 *   The component which will have to be versioned. Its family (major version, version id, logical id) will be kept on the result.  
 * <ul>
 * <li> The identifier must not be CATPLMID_Null. Otherwise, the call will result in a E_INVALIDARG return.</li> 
 * </ul>
 * @param iAction [in]
 *   The action which must be applied on the new version. If no action is available, use CATPLMID_Null as argument.
 * @param iApplicabilityDate [in]
 *   The applicability date for the new version availability.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the component can be taken into account by the engine. It was added to the set of data to be treated by the engine. </li> 
 *   <li><tt>E_INVALIDARG</tt> if one of the provided entry is invalid.</li>
 *   <li><tt>E_ACCESSDENIED</tt> if this entry point is not compatible with the versioning mode.</li>
 *   <li><tt>E_FAIL</tt> if the operation failed.</li>
 *   </ul>
 */
  virtual HRESULT AddVersioningDatum( const CATPLMID & iComponent, 
                                      const CATPLMID & iAction, const CATTime & iApplicabilityDate ) = 0;

/** 
 * Adds a versioning datum for further treatment by the engine.
 *
 * <br><b>Role</b>: Enables to add a versioning datum in the set of data which will be treated when calling the 
 * @href CATIPLMNewVersionEngine#RunVersioningOperation.
 * <ul>
 * <li> This entry point can only be used in IntoFamily mode. A call to this entry point in a different
 * mode will result in a E_ACCESSDENIED return.</li> 
 * </ul>
 *
 * @param iComponent [in]
 *   The component needing to be evolved by integrating a defined version family. 
 * <ul><li> The identifier must not be CATPLMID_Null. Otherwise, the call will result in a E_INVALIDARG return.</li></ul>
 * @param iIntoFamilyOfComponent [in]
 *   The identifier of the component defining the version family the provided component must join.
 * <ul>
 * <li> If CATPLMID_Null is provided, the operation on the component will result in the creation of a new version family.</li>
 * <li> Otherwise, the operation on the component will result in the creation of a new version (last version) in the family of iIntoFamilyOfComponent.</li>
 * <li> iIntoFamilyOfComponent must be from the same PLM type than iComponent. Otherwise, the call will result in a E_INVALIDARG return.</li> 
 * <li> iIntoFamilyOfComponent might not be the last version of the family. The invariant data of the family will therefore be 
 * taken from this component and it might not be the values of the last version of the family.</li> 
 * </ul>
 * @param iAttributes [in]
 *   The set of attributes needing to be applied in case of a new version family creation (iIntoFamilyOfComponent set to CATPLMID_Null).
 *   <ul><li> In case iIntoFamilyOfComponent is not CATPLMID_Null, this parameter won't be taken into account.</li></ul>
 * @param iAction [in]
 *   The action which must be applied on the new version. If no action is available, use CATPLMID_Null as argument.
 * @param iApplicabilityDate [in]
 *   The applicability date for the new version availability.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the component can be taken into account by the engine. It was added to the set of data to be treated by the engine. </li> 
 *   <li><tt>E_INVALIDARG</tt> if one of the provided entry is invalid.</li>
 *   <li><tt>E_ACCESSDENIED</tt> if this entry point is not compatible with the versioning mode.</li>
 *   <li><tt>E_FAIL</tt> if the operation failed.</li>
 *   </ul>
 */
  virtual HRESULT AddVersioningDatum( const CATPLMID & iComponent, const CATPLMID & iIntoFamilyOfComponent,
                                      CATIPLMAttributeSet * iAttributes,
                                      const CATPLMID & iAction, const CATTime & iApplicabilityDate ) = 0;
};
CATDeclareHandler( CATIPLMNewVersionEngine, CATBaseUnknown );

#endif
