// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATOmbCuteUniversalLink_h
#define CATOmbCuteUniversalLink_h

/**
* @level Protected
* @usage U1
*/
#include "CATObjectModelerBase.h"
#include "CATListPtrCATIPLMComponent.h"
#include "CATPLMTypeH.h"
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"


class CATBaseUnknown;
class CATIOmbUpdateContract;
class CATOmbVOUpdateFlavour;
class CATILinkableObject;
class CATIOmbUniversalLink;
class CATIOmbProxySpecifications;
class CATIOmbFunction;
class PLMIOmbVirtualObjectDescriptor_var;
class CATOmbObjectInContext;
class CATLinkSolver;
class CATStreamDefinition;
class CATPLMID;


struct CATOmbCuteUniversalLink_Attribute
{
  CATOmxKeyString _attributeName;
  CATPLMTypeH _extensionTypeId; // CATPLMTypeId en R212
};

template<> ExportedByCATObjectModelerBase CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbCuteUniversalLink_Attribute>::manager();


/**
* Class to build a make a complex or simple link using t_ext infrastructure.
*/
class ExportedByCATObjectModelerBase CATOmbCuteUniversalLink
{
  friend class XDataFeatureNode;
  friend class CData_CompleteName;
  friend class CData_ComplexName;
  friend class CATOmbTst_Collab_Links;
public:

  /**
  * Creates a Universal Link for a single object.
  * @param iTarget
  *    The target object
  * @param oUniversalLink [CATBaseUnknown#Release]
  *  The build universal link.
  * @param iContract
  *    The link contract.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd> oUniversalLink has been successfully instanciated .</dd>
  *     <dt>E_FAIL</dt>
  *     <dd> otherwise.</dd>
  *   </dl>
  */
  static HRESULT Create(CATBaseUnknown& iTarget, CATIOmbUniversalLink*& oUniversalLink, CATIOmbUpdateContract* iContract = NULL);


  /**
  * Creates a Universal Link for a single object.
  * @param iTarget
  *    The static target or the applicative context for dynamic linking
  * @param iFunction
  *    provide a function to apply for dynamic linking. May be NULL
  * @param iProxySpecs
  *    provide proxy specifications to ask for a proxy. May be NULL
  * @param oUniversalLink [CATBaseUnknown#Release]
  *  The built universal link.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd> oUniversalLink has been successfully instanciated .</dd>
  *     <dt>E_FAIL</dt>
  *     <dd> otherwise.</dd>
  *   </dl>
  */
  static HRESULT Create(CATBaseUnknown& iTarget, CATIOmbFunction* iFunction, CATIOmbProxySpecifications *iProxySpecs, CATIOmbUniversalLink*& oUniversalLink);

  /**
  * Creates a Universal Link to link a virtual object.
  * @param iInstances
  *    The path of first instances describing the context of the pointed target object.
  *    Instances are CoreInstances or and CoreRepInstances
  * @param iTarget.
  *    The target object
  * @param iVOContract
  *    The virtual object contract.
  * @param oUniversalLink [CATBaseUnknown#Release]
  *  The build universal link.
  * @param iContract
  *    The target contract.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd> oUniversalLink has been successfully instanciated .</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd> iInstances and iTarget are simultaneously empty</dd>
  *     <dt>E_FAIL</dt>
  *     <dd> otherwise.</dd>
  *   </dl>
  */
  static HRESULT Create(const CATLISTP(CATIPLMComponent)& iInstances,
    CATBaseUnknown                  * iTarget,
    CATOmbVOUpdateFlavour           & iVOContract,
    CATIOmbUniversalLink           *& oUniversalLink,
    CATIOmbUpdateContract           * iTargetContract = NULL);


  /**
  * Creates a Universal Link to link a virtual object.
  *
  * @param iInstances
  *    The path of first instances describing the context of the pointed target object.
  *    Instances are CoreInstances or and CoreRepInstances
  * @param iTarget
  *    The static target or the applicative context for dynamic linking
  * @param iFunction
  *    provide a function to apply for dynamic linking. May be NULL
  * @param iProxySpecs
  *    provide proxy specifications to ask for a proxy. May be NULL
  * @param iVOContract
  *    The virtual object contract.
  * @param oUniversalLink [CATBaseUnknown#Release]
  *  The built universal link.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd> oUniversalLink has been successfully instanciated .</dd>
  *     <dt>E_FAIL</dt>
  *     <dd> otherwise.</dd>
  *   </dl>
  */
  static HRESULT Create(const CATLISTP(CATIPLMComponent)& iInstances,
    CATBaseUnknown                  * iTarget,
    CATIOmbFunction                 * iFunction,
    CATIOmbProxySpecifications      * iProxySpecs,
    CATOmbVOUpdateFlavour           * iVOContract,
    CATIOmbUniversalLink           *& oUniversalLink);


  /**
  * Creates a Universal Link from a Virtual Object Descriptor.
  *
  *  @param  ispVODescriptor
  *      A valid Virtual Object Descriptor. <br>
  *      Input Parameter. <br>
  *      This parameter MUST NOT be provided by caller as NULL_var. This method returns an error otherwise.
  *  @param  opUniversalLink [CATBaseUnknown#Release]
  *      The created Universal Link. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @param  ipFunction
  *      A function to apply for dynamic linking. <br>
  *      May be NULL.
  *  @param  iProxySpecitfications
  *      The kind of proxy specifications based on the pointed object (the pointed object being the Target object defined in the Virtual Object Descriptor).
  *      If NULL, no proxy is used.
  *  @param  ipContract
  *      The update contract. <br>
  *      If NULL, the update contract will correspond to the relation's one when affecting the Universal Link to a relation.
  *  @return
  *      <code>S_OK</code> if the method succeeds and a Universal Link is created. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  static HRESULT Create(PLMIOmbVirtualObjectDescriptor_var &ispVODescriptor,
    CATIOmbUniversalLink *&opUniversalLink,
    CATIOmbFunction* ipFunction = NULL,
    CATIOmbProxySpecifications *iProxySpecifications = NULL,
    CATOmbVOUpdateFlavour *ipContract = NULL);
  /**
  * Creates a Universal Link from a CATOmbObjectInContext.
  *
  *  @param  ipObjectInContext
  *      A CATOmbObjectInContext. <br>
  *      Input Parameter. <br>
  *      This parameter MUST NOT be provided by caller as NULL. This method returns an error otherwise.
  *  @param  opUniversalLink [CATBaseUnknown#Release]
  *      The created Universal Link. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @param  ipFunction
  *      A function to apply for dynamic linking. <br>
  *      May be NULL.
  *  @param  iProxySpecitfications
  *      The kind of proxy specifications based on the pointed object (the pointed object being the Target object defined in the Virtual Object Descriptor).
  *      If NULL, no proxy is used.
  *  @param  ipContract
  *      The update contract. <br>
  *      If NULL, the update contract will correspond to the relation's one when affecting the Universal Link to a relation.
  *  @return
  *      <code>S_OK</code> if the method succeeds and a Universal Link is created. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  static HRESULT Create(CATOmbObjectInContext* ipObjectInContext,
    CATIOmbUniversalLink *&opUniversalLink,
    CATIOmbFunction* ipFunction = NULL,
    CATIOmbProxySpecifications *iProxySpecifications = NULL,
    CATOmbVOUpdateFlavour *ipContract = NULL);

  /**
  * V2 APIs :
  *       . Create VO for link pointing component(s).
  *       . CANNOT override UpdateFlavour at runtime
  */

  /**
  * Creates a Universal Link from a Virtual Object Descriptor.
  *
  *  @param  ispVODescriptor
  *      A valid Virtual Object Descriptor. <br>
  *      Input Parameter. <br>
  *      This parameter MUST NOT be provided by caller as NULL_var. This method returns an error otherwise.
  *  @param  opUniversalLink [CATBaseUnknown#Release]
  *      The created Universal Link. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @param  ipFunction
  *      A function to apply for dynamic linking. <br>
  *      May be NULL.
  *  @param  iProxySpecitfications
  *      The kind of proxy specifications based on the pointed object
  *      (the pointed object being the Target object defined in the Virtual Object Descriptor).
  *      If NULL, no proxy is used.
  *  @return
  *      <code>S_OK</code> if the method succeeds and a Universal Link is created. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  static HRESULT CreateV2(PLMIOmbVirtualObjectDescriptor_var &ispVODescriptor,
    CATIOmbUniversalLink *&opUniversalLink,
    CATIOmbFunction* ipFunction = NULL,
    CATIOmbProxySpecifications *iProxySpecifications = NULL);
  /**
  * Creates a Universal Link from a CATOmbObjectInContext.
  *
  *  @param  ipObjectInContext
  *      A CATOmbObjectInContext. <br>
  *      Input Parameter. <br>
  *      This parameter MUST NOT be provided by caller as NULL. This method returns an error otherwise.
  *  @param  opUniversalLink [CATBaseUnknown#Release]
  *      The created Universal Link. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @param  ipFunction
  *      A function to apply for dynamic linking. <br>
  *      May be NULL.
  *  @param  iProxySpecitfications
  *      The kind of proxy specifications based on the pointed object
  *      (the pointed object being the Target object defined in the Virtual Object Descriptor).
  *      If NULL, no proxy is used.
  *  @return
  *      <code>S_OK</code> if the method succeeds and a Universal Link is created. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  static HRESULT CreateV2(CATOmbObjectInContext* ipObjectInContext,
    CATIOmbUniversalLink *&opUniversalLink,
    CATIOmbFunction* ipFunction = NULL,
    CATIOmbProxySpecifications *iProxySpecifications = NULL);


  /**
  * Creates a Universal Link from a CATPLMID.
  *
  *  @param  iPLMID
  *      A CATPLMID. <br>
  *      Input Parameter. <br>
  *      This parameter MUST NOT be provided by caller as an empty PLMID. This method returns an error otherwise.
  *  @return
  *      <code>S_OK</code> if the method succeeds and a Universal Link is created. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  static HRESULT CreateFromPLMID(CATPLMID & iPLMID, CATIOmbUniversalLink *&opUniversalLink);


  /**
  * Creates a Universal Link, with a synchro status based attributes, from a Virtual Object Descriptor
  *
  *  @param  ispVODescriptor
  *      A valid Virtual Object Descriptor. <br>
  *      Input Parameter. <br>
  *      This parameter MUST NOT be provided by caller as NULL_var. This method returns an error otherwise.
  *  @param  iAttributeList
    *      A array of attributes which will be used for the synchro status of the link. <br>
  *  @param  opUniversalLink [CATBaseUnknown#Release]
  *      The created Universal Link. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @return
  *      <code>S_OK</code> if the method succeeds and a Universal Link is created. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  static HRESULT CreateSynchroBasedOnAttributesLink(PLMIOmbVirtualObjectDescriptor_var &ispVODescriptor,
    const CATOmxArray <CATOmbCuteUniversalLink_Attribute> & iAttributeList,
    CATIOmbUniversalLink *&opUniversalLink);



private:
  static HRESULT GetUniversalLinkFromCompleteStream(CATStreamDefinition & StreamDefinition, CATIOmbUniversalLink  *& UL);

  static HRESULT _Create(const CATLISTP(CATIPLMComponent)& iInstances,
    CATBaseUnknown                  * iTarget,
    CATIOmbFunction                 * iFunction,
    CATIOmbProxySpecifications      * iProxySpecs,
    CATOmbVOUpdateFlavour           * iVOContract,
    CATIOmbUpdateContract           * iTargetContract,
    CATIOmbUniversalLink           *& oUniversalLink);

  /* forbidden operations */
  CATOmbCuteUniversalLink();
};


#endif
