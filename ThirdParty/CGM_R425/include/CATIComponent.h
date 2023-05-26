/* -*-c++-*- */
#ifndef CATIComponent_H
#define CATIComponent_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/* 
* @COPYRIGHT DASSAULT SYSTEMES 2004
* ----------------------------------------------------------------------------------------------------------------------
*   Origin              : Local running (inside wintop) of remote persistency entity 
*                            associative kernel change/data set of ... actors ...
*                            made as simple as possible to be affordable for enhanced infrastructure integration
*   Software's Category : Physical Layer (Middleware services) dedicated to client side
*                            (in a kind of software classification similar to the layered OSI Network 
*                             upper (logical) Layer is mainly about two main axis  (
*                                  Modeler (domain) specialisation (for Data and Attributes ...)
*                                  Upper Levering Operand Integration exchange (QEOPS, 
*   Premilinary         : Do not forget to contact your Database Administrators or any other representative
*                            (Authoring definition) for more convenient support 
*                          (Just to be sure that appropriate schema (Table for Data , or Services) are supported 
*                              when reference persistency occured when dealing with local work realized  )
*   Specification       : Simple genuine (re-usable) services about 
*                            - associativity between local insulated implementation and shared remote repository
*                            - synthetic change set (persistency intents)
*   Limitations         : No attributes vocabulary provided to let this current functional component software 
*                              be as comprehensible in specifications
*                         Status is slaved to Modelers deployement and Behaviors
*                             for more detailled specification (UML sequence diagram, statechart, ..)  
*                             consult specialized specifications database relative to upper Logical Software layer 
*                             it means Product Structure Legacy, PLM Client Core, Representation Model
*   Favorites entry-point for developpers :
*                         CATPLMRepositoryName : Repository classification 
*                         CATProxySpace   : Instance of a domain resolution                    
*                         CATComponentId  : Handle on primary associativity between local and remote entity           
* ------------------ ----------------------------------------------------------------------------------------------------
*/

/**
 * @level Protected
 * @usage U4       
 */

/**
* Description  : Interface provided for management of entity representation of a DataBase Object
*  
* This Interface is intended to be implemented 
*    either by a domain modeler or by default by an open data modeler.
*    This allows genuine infrastructure to behave more conviently with standard design pattern,
*      so it has been designed as a kind of controlling interface (two ways) 
*        between a concrete data modeler inside the WinTop client Cache
*        and some generic operations (such as Save/Version/Reroute engines)
*        through associative persistency data structure (TOS)
*
* But be carefull, this Interface is not intended to be used  by tierce actors.
*    More precisely in case of VPMNav, or Viewing/Browsing capabilities, 
*    if you are seeking generic values which are known / managed in TOS repository :
*       the result should be returned directly from  directly the CATComponentId handle,
*       otherwise through CATTosOsmComponent class of services
*       But unpredictible result could be obtained if returned from method of CATIComponent Interface
*       Some known attributes which may be managed as referential inside TOS are :
*          Physical Identity (primary key)
*          Server binary Location (table)
*          PLMType value (logical persistency data shema, not far from Server location)
*          Logical Identity (associativity through Versioning)
*          Concurrent Enginneering Stamp () 
*          Generic ToDo Persistency Intents : ToCreate, ToModify, ToDelete
*    In othercases if you are seeking the attributes/values associated to a specific entity
*       you should acquired the knowledge of appropriate Interface of DataModeler Access.
*       The only concerned about by TOS is about switching from an Handle
*          to the modeler Interface by means of QueryObjectInSession method.
*
* 
* As of 02 March 2006, even if default adhesion through open data modeler is running ...
*   For those who are seeking an implementation through an appropriate adapteur.
*   a review of adapters' sample should  be given on implementing this interface
*   from the most specialized to the more abstract (so poorest) adapter.
*   So if you have to provide this kind of adhesion, 
*   you should make your choice from the most convenient adapter picked among :
*
*     ObjectSpecsModeler\ProtectedInterfaces\CATComponentAdaptorSpec.h
*     ObjectSpecsModeler\ProtectedInterfaces\CATComponentAdaptorSpecRepRef.h
*     ObjectModelerBase\ProtectedInterfaces\CATComponentAdapter.h
*     CATPLMIdentification\ProtectedInterfaces\CATComponentAdaptor.h
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATComponentId.h"
#include "CATPLMTypeId.h"
#include "CATAdpMetaData.h"

#include "CATPLMID_Any.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATLISTV_CATPLMSemanticRelationData.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATVariant.h"
#include "CATOmxCollectionType.h"
#include "CATPLMPersistentUnitBindingMode.h"

class CATOmxAny;
class CATPLMAttributesFilter;
class CATOmxKeyValueBlock;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATIComponent;
#else
extern "C" const IID IID_CATIComponent;
#endif

/**
* Mandatory protocol to be implemented by components
*/
class ExportedByCATPLMTos CATIComponent  : public CATBaseUnknown
{
  friend class CATIComponentSafeAccess;
  friend class CATSpecOleSiteExt;                 // A VIRER
  friend class CATPCCMemPLMRepRef_UpdateStamp;    // A VIRER
  friend class CATPCTModelServices;               // A VIRER
  friend class CATPCCTosServicesProvider;         // A VIRER
  friend class CATOmbRelationImpl;

public:

  CATDeclareInterface;

  // ======================================================================================
  // GORE INTERNALS - TO BE REMOVED AS SOON AS POSSIBLE
  // ======================================================================================

  /** 
  * Determine if current Object is Component (dedicated to PLM associated repository)
  *    
  * @return
  *      S_OK if request succeeded and Object is identified as a Valid <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT IsComponent() const = 0;

  /** 
  * Get the PLM type.
  *
  * @param oTypeReference
  *   The PLM type that must be tested
  *
  * @return
  *      S_OK     if request succeeded <br>
  *      S_FALSE  if request succeed with abstract core type <br>
  *      E_FAIL   if request failed <br>
  */
  virtual HRESULT GetPLMType(CATPLMTypeId & oTypeReference) const = 0;

  // ----------------------------------------------------------------------------------------------------------
  // RESTRICTED ACCESS : ONLY CATPLMIdentification is allowed to invoke methods calling CATIComponentSafeAccess
  // ----------------------------------------------------------------------------------------------------------

protected:

  /** 
  * Acquisition of genuine PLM attribute PLMOwner
  *
  * @param oPLMOwner
  *        The owner
  *    
  * @return
  *      S_OK      if request succeeded with an owner<br>
  *      S_FALSE   if request succeeded without owner<br>
  *      E_FAIL    if request failed <br>
  */
  virtual HRESULT HasPLMOwner(CATComponentId &oPLMOwner) = 0;

  /** 
  * Acquisition of genuine PLM attribute PLMInstanceOf
  *
  * @param oPLMReference
  *        The reference
  *    
  * @return
  *      S_OK      if request succeeded with a reference<br>
  *      S_FALSE   if request succeeded without reference<br>
  *      E_FAIL    if request failed <br>
  */
  virtual HRESULT IsInstanceOf(CATComponentId &oPLMReference) = 0;

  /**
  * Declare if strong relations network is managed at TOS level.
  * The strong network is a combination of ownership and instance-reference relations.
  *
  * @return
  *      FALSE : Network is master at data model level and the result is projected in TOS (Old school).
  *      TRUE  : Network is master at TOS level.
  *              This modelling allows to create hybrid PLM Session which is a prerequisite for Refresh engine.
  */
   virtual CATBoolean IsStrongRelationalMasterInTOS() const = 0;

  // ======================================================================================
  // ATTRIBUTES ACCESS
  // ======================================================================================

  /** 
  * GetAlias,  Something like 
  *   PLMFactoryHeader\ProtectedInterfaces\CATIntegrationCommonDeclaration.h
  *
  * @param oAlias
  *    PLMExternalID PLMinstanceID 
  *    
  * @return
  *      S_OK   if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT HasAlias(CATUnicodeString &oAlias) = 0;

  /**
   * Returns the functional name associated with the component if it exists
   *
   * @param oFunctionalName
   *	The functional name
   *
   * @return
   *      S_OK   if request succeeded <br>
   *      E_FAIL if request failed (component is not a port)<br>
   */
  virtual HRESULT HasFunctionalName( CATUnicodeString &oFunctionalName ) = 0;

  /**
   * Check if component is instantiable only one.
   *
   * @return
   *      S_OK      : Is instantiable only once.
   *      S_FALSE   : Is not instantiable only once.
   *      E_FAIL    : If an unexpected failure.
   *      E_NOTIMPL : If not implemented.
   */
  virtual HRESULT IsOnceInstantiable() = 0;

  /**
   * Give access to public attributes.
   *
   * @param ioAttributeNameList
   *        The list of attributes' internal name.
   *        Empty  : All the public attributes names and values have to be returned.
   *        Filled : Only the values of the attributes which name is in this list have to be returned. In this case the list is not modified.
   * @param oAttributeValueList
   *        The list of attributes' value. It is is cleaned before treatment.
   * @return
   *     S_OK          The list (Empty or Filled) is successfully returned.
   *     E_INVALIDARG  The given ioAttributeNameList contains the name of an invalid attribute.
   *     E_FAIL        The Entity is not valid or the state of the system is not correct for this operation.
   *     E_NOTIMPL     If not implemented.
   */
  virtual HRESULT GetPublicAttributes(CATListOfCATUnicodeString  &  ioAttributeNameList,
                                      CATListOfCATUnicodeString  &  oAttributeValueList) = 0;

/**
 * Retrieves the extensions defined on the component.
 * <br><b>Role:</b>Search on the component the extensions defined and returns it.
 * @param oExtensions [out]
 *   The extensions of the component.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: The extensions are returned.</li> 
 *   <li><tt>S_FALSE</tt>: No extension available on the component.</li>
 *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
 *   </ul>
 */
  virtual HRESULT ListExtensions( CATPLMTypeIds & oExtensions ) = 0;

/**
 * Retrieves the set of attribute identifiers of a component respecting a provided filter.
 * <br><b>Role:</b>This method has two different roles:
 * <li>1. If a context is defined on the @href CATPLMAttributesFilter, it has to enumerate and return the 
 * attribute identifiers defined for this context on the component.</li>
 * <li>2. Il a set of attribute identifiers is provided together with a <code>PARTIAL</code> context, the 
 * availability of provided set must be checked on the component before being returned.</li>
 * @param iExtensionType [in]
 *   The extension of the component needing to be introspected. Basis component must be taken if 
 * <code>CATPLMTypeId_Null</code> is provided.
 * @param iFilter
 *   The filter that has to be applied to the attributes defined on the component.
 * @param oAttributeIds [out]
 *   The set of attribute identifiers needing to be introspected on the component for this context.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: The set is returned.</li> 
 *   <li><tt>S_FALSE</tt>: The provided context or set is invalid for the component.</li>
 *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
 *   </ul>
 */
  virtual HRESULT CheckAttributesMask( const CATPLMTypeId & iExtensionType, const CATPLMAttributesFilter & iFilter,
                                       CATLISTV(CATString) & oAttributeIds ) = 0;

/**
 * Retrieves the attribute value for a provided attribute identifier.
 * <br><b>Role:</b>This method enables to obtain an attribute value of the component or of one of its extensions.
 * @param iExtensionType [in]
 *   The extension of the component needing to be introspected. Basis component must be introspected if 
 * <code>CATPLMTypeId_Null</code> is provided.
 * @param iAttributeId
 *   The attribute identifier of the attribute intropected on the component.
 * @param oAttrValueCType [out]
 *   The kind of collection of the attribute.
 * @param oAttributeValue [out]
 *   The value of the attribute.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: The value was successfully retrieved.</li> 
 *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
 *   </ul>
 */
  virtual HRESULT GetAttributeValue( const CATPLMTypeId & iExtensionType, const CATString & iAttributeId, 
                                     CATOmxCollectionType & oAttrValueCType, CATOmxAny & oAttributeValue ) = 0;


/**
 * Retrieves the attribute block.
 * <br><b>Role:</b>This method enables to obtain the attribute block of the component or of one of its extensions.
 * @param iExtensionType [in]
 *   The extension of the component needing to be introspected. Basis component must be introspected if 
 *   <code>CATPLMTypeId_Null</code> is provided.
 * @param oAttrBlock [out]
 *   The attribute block.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: The value was successfully retrieved.</li> 
 *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
 *   </ul>
 */
  virtual HRESULT GetAttributeBlock( const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock ) = 0;

  // ======================================================================================
  // EXPORT MANAGEMENT
  // ======================================================================================

/**
 * Retrieves the attribute block for export.
 * <br><b>Role:</b>This method enables to obtain the export attribute block of the component or of one of its extensions.
 * @param iExtensionType [in]
 *   The extension of the component needing to be introspected. Basis component must be introspected if 
 *   <code>CATPLMTypeId_Null</code> is provided.
 * @param oAttrBlock [out]
 *   The attribute block.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: The value was successfully retrieved.</li> 
 *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
 *   </ul>
 */
  virtual HRESULT GetAttributeBlockForExport( const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock ) = 0;

  // ======================================================================================
  // PERSISTENT UNIT MANAGEMENT
  // ======================================================================================

  /**
  * Define how is binded persistent units
  * 
  * @param oBindingMode
  *        Define binding mode
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : if failure
  */
  virtual HRESULT GetPersistentUnitBindingMode(CATPLMPersistentUnitBindingMode & oBindingMode) const = 0;

  // DEPRECTED REPLACED BY : GetPersistentUnitBindingMode
  virtual CATBoolean IsPersistentUnitBoundToComponentModel() const = 0;

  // ======================================================================================
  // MASTER STAMP MANAGEMENT
  // ======================================================================================

  /** 
  * Gets Master stamp value
  *
  * @param oMasterStamp
  *      MasterStamp of Object (can be omx_int or omx_uuid)
  *    
  *  @return
  *       S_OK    : successfully and available.
  *       S_FALSE : Master stamp is not managed for this component.
  *       E_FAIL  : a software error occured.
  */
  virtual HRESULT GetMasterStamp(CATOmxAny & oStamp) const = 0;

  /**
  * TO BE REMOVED....
  */
  virtual HRESULT HasMasterStamp(CATLONG32 & oStamp) const = 0;

  /**  
  *  Triggers off MasterStamp incrementation
  *
  *  @param oMasterStampIsModified
  *       TRUE: indicates that UpdateStamp effectively updated and its new value stored.
  *  @return
  *       S_OK   : successfully ended.
  *       E_FAIL : a software error occured.
  */
  virtual HRESULT TouchMasterStamp (CATBoolean & oMasterStampIsModified)= 0;
};

CATDeclareHandler( CATIComponent, CATBaseUnknown );

/* NO DOC */
extern ExportedByCATPLMTos const GUID CLSID_ComponentImplementationExposedInTOS_InternalPurposeOnly ; 

#endif
