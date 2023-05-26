// COPYRIGHT Dassault Systemes 2009
#ifndef PLMIOmbVirtualObjectDescriptor_H
#define PLMIOmbVirtualObjectDescriptor_H

/**
 * @level Protected
 * @usage U3
 */
 // ObjectModelerCollection
#include "CATOmxList.h"
#include "CATOmxSR.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"
#include "PLMIOmbLegacyVirtualObjectDescriptor.h"

class CATOmbObjectInContext;
class CATIPLMComponent;
class PLMIOmbVirtualObjectDescriptor_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_PLMIOmbVirtualObjectDescriptor;
#else
extern "C" const IID IID_PLMIOmbVirtualObjectDescriptor;
#endif

//------------------------------------------------------------------

/**
 * This interface describes a Virtual Object Descriptor: It designates a virtual occurrence of an object. <br>
 * It can be retrieved from a relation allowing to introspect the pointing result. <br>
 * It can be used to build a pointing specification (a Universal Link) that will be used to valuate a relation.
 *
 *  @href PLMIOmbVirtualObjectDescriptorFactory
 */
class ExportedByCATObjectModelerBase PLMIOmbVirtualObjectDescriptor : public PLMIOmbLegacyVirtualObjectDescriptor
{
  CATDeclareInterface;
public:
  /**
   * Creates an empty Virtual Object Descriptor.
   * returned object is invalid and must be filled (SetPathOfInstances, SetInstanceOfRepresentation, SetTarget...)
   */
  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> MakeEmptyDescriptor();

  

  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> MakeDescriptor(CATOmxList<CATIPLMComponent> const & iPathOfInstances, CATIPLMComponent * iRepresentationInstance, CATBaseUnknown * iTarget);
  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> MakeDescriptor(const PLMIOmbVirtualObjectDescriptor& iVOD);
  /*
    Return the VOD held by the ObjectInContext
  */
  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> GetDescriptorFromObjectInContext(CATOmbObjectInContext & iobjectInContext);


  /**
  * Creates a Virtual Object Descriptor from an existing concrete or virtual object retrieved from a relation.
  *
  *  @param  ipConcreteOrVirtualObject
  *      A concrete or virtual object <u>retrieved from a relation</u>: <br>
  *      - A concrete object corresponds to a PLM object or a pointable object located inside a stream. <br>
  *      - A virtual object designates a composite object that does not have a real existence (an object adhering to CATIOmbVirtualObject). <br>
  *      Input Parameter. <br>
  *      This parameter MUST NOT be provided by caller as NULL. This method returns an error otherwise.
  */
  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> MakeDescriptorFromConcreteOrVirtualObject(CATBaseUnknown const & iConcreteOrVirtualObject);

  /**
   * Gets (if exists) the path of instances defining the Virtual Object Descriptor. <br>
   * In the case of a VO Descriptor only composed of an instance, it corresponds to a path of instances composed of a single instance.
   *
   *  @param   oPathOfInstances
   *      A path of instances. <br>
   *      Output parameter. <br>
   *      This list MUST be provided by caller as empty. This method returns an error otherwise. <br>
   *      This list is returned to caller as empty if method fails.
   *  @return
   *      <code>S_OK</code> if the method succeeds and the path was successfully retrieved. <br>
   *      <code>S_FALSE</code> if the method succeeds but there is no defined path. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT GetPathOfInstances(CATOmxList<CATIPLMComponent> & oPathOfInstances) const = 0;

  /**
   * Sets the path of instances defining the Virtual Object Descriptor. <br>
   * In the case of a VO Descriptor only composed of an instance, it corresponds to a path of instances composed of a single instance.
   *
   *  @param   iPathOfInstances
   *      A path of instances. <br>
   *      Input Parameter. <br>
   *      This list can be provided by caller as empty.
   *  @return
   *      <code>S_OK</code> if the method succeeds. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT SetPathOfInstances(CATOmxList<CATIPLMComponent> const & iPathOfInstances) = 0;

  /**
  * Gets (if exists) the representation instance defining the Virtual Object Descriptor.
  *
  *  @param  oRepresentationInstance [out]
  *      A Representation Instance. <br>
  *      Output parameter. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @return
  *      <code>S_OK</code> if the method succeeds. <br>
  *      <code>S_FALSE</code> if the method succeeds but there is no defined representation instance. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetInstanceOfRepresentation(CATOmxSR<CATIPLMComponent> & oRepresentationInstance) const = 0;

  /**
   * Sets the representation instance defining the Virtual Object Descriptor.
   *
   *  @param  iRepresentationInstance
   *      A Representation Instance. <br>
   *      Input Parameter. <br>
   *      This parameter can be provided by caller as NULL.
   *  @return
   *      <code>S_OK</code> if the method succeeds. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT SetInstanceOfRepresentation(CATIPLMComponent * iRepresentationInstance) = 0;

  /**
   * Gets (if exists) the final target defining the Virtual Object Descriptor. <br>
   * <u>Note</u>: The target can be a proxy if this Virtual Object Descriptor has been retrieved from a relation.
   *
   *  @param  oFinalTarget
   *      The target if defined. <br>
   *      Output parameter. <br>
   *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
   *      This parameter is returned to caller as NULL if method fails. <br>
   *      This parameter is valuated if method succeeds.
   *  @param  iIID
   *      The desired interface.
   *  @return
   *      <code>S_OK</code> if the method succeeds. <br>
   *      <code>S_FALSE</code> if the method succeeds but there is no defined target. <br>
   *      <code>E_NOINTERFACE</code> if the method succeeds but the defined target does not adhere to the specified interface. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT GetTarget(CATOmxSR<CATBaseUnknown> & oFinalTarget, const IID & iIID = IID_CATBaseUnknown) const = 0;

  /**
   * Sets the final target defining the Virtual Object Descriptor. <br>
   *
   *  @param  ipTarget
   *    A pointable object that can be: <br>
   *      - A PLM object: Port, Connection Reference or Representation Reference. <br>
   *      - A pointable object located inside a stream. <br>
   *      Input Parameter. <br>
   *      This parameter can be provided by caller as NULL.
   *  @return
   *      <code>S_OK</code> if the method succeeds. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT SetTarget(CATBaseUnknown * iTarget) = 0;

  /**
   * Returns if possible the Reference 'aggregating' the described Virtual Object. <br>
   * If a path of instances is defined, it corresponds to the reference aggregating the first instance of the path. <br>
   * If no path of instances is defined but a representation instance is defined, it corresponds to the reference aggregating the representation instance. <br>
   * If only a target is defined, the behavior is the following one: <br>
   *   - For a Connection or a Port, it corresponds to the reference aggregating the previous object. <br>
   *   - For a Representation Reference or a pointable object inside a stream of a Representation Reference, it corresponds to the Representation Reference. <br>
   *   - For a Reference, it corresponds to the Reference itself. <br>
   *   - For a pointable object inside a stream of a connection, it corresponds to the reference aggregating the PLM object owner of the stream. <br>
   * For any other cases, no reference is returned.
   *
   * @param  oRootReference
   *      A reference. <br>
   *      Output parameter. <br>
   *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
   *      This parameter is returned to caller as NULL if method fails. <br>
   *      This parameter is valuated if method succeeds.
   * @return
   *      <code>S_OK</code> if the method succeeds and a reference is returned. <br>
   *      <code>S_FALSE</code> if the method succeeds but there is no reference 'aggregating' the virtual object. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT GetRootReference(CATOmxSR<CATIPLMComponent> & oRootReference) const = 0;

  /**
   * @deprecated V6R2013 : see new signature below
   *
   * Returns a synthetic description of the Virtual Object Descriptor.
   *
   *  @param  oPathOfInstances
   *     <code>TRUE</code> if a path of instances is defined. <br>
   *     <code>FALSE</code> otherwise.
   *  @param  oInstanceOfRepresentation
   *     <code>TRUE</code> if an instance of representation is defined. <br>
   *     <code>FALSE</code> otherwise.
   *  @param  oTarget
   *     <code>TRUE</code> if a target is defined and adheres to the specified interface. <br>
   *     <code>FALSE</code> otherwise.
   *  @param  iTargetIID
   *      The interface filtering the target (if exists). <br>
   *      IID_CATBaseUnknown by default.
   */
  virtual void GetKind(CATBoolean & oPathOfInstances, CATBoolean & oInstanceOfRepresentation, CATBoolean & oTarget, const IID & iTargetIID = IID_CATBaseUnknown) const = 0;

  /**
   * Checks the validity of the Virtual Object Descriptor. <br>
   * A valid Virtual Object Descriptor can be used to build a pointing specification (Universal Link).
   *
   *  @return
   *      <code>S_OK</code> if the method succeeds and the Virtual Object Descriptor is valid. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT CheckValidity() const = 0;

  /**
   * Resets the content of this Virtual Object Descriptor. <br>
   * It will correspond to an empty Virtual Object Descriptor.
   *
   * @return
   *      <code>S_OK</code> if the method succeeds and the virtual object descriptor has been reset. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT Reset() = 0;

  /**
   * Compares this Virtual Object Descriptor to an other Virtual Object Descriptor.
   *
   *  @param  iVOD
   *      The Virtual Object Descriptor to compare with. <br>
   *      Input Parameter. <br>
   *  @return
   *      <code>true</code>  if the two Virtual Object Descriptors are identical. <br>
   *      <code>false</code> if the two Virtual Object Descriptors are not identical. <br>
   */
  virtual bool IsIdenticalTo(PLMIOmbVirtualObjectDescriptor const & iVOD) const = 0;

  /**
   * Compares the Paths of Instances of two Virtual Object Descriptors.
   *
   *  @param  iVOD
   *      The Virtual Object Descriptor to compare with. <br>
   *      Input Parameter. <br>
   *  @return
   *      <code>true</code>  if the two Paths of Instances are identical. <br>
   *      <code>false</code> if the two Paths of Instances are different. <br>
   */
  virtual bool ArePathsOfInstancesIdentical(PLMIOmbVirtualObjectDescriptor const & iVOD) const = 0;

  /**
   * Compares the Instances of Representation of two Virtual Object Descriptors.
   *
   *  @param  iVOD
   *      The Virtual Object Descriptor to compare with. <br>
   *      Input Parameter. <br>
   *  @return
   *      <code>true</code>  if the two Instances of Representation are identical. <br>
   *      <code>false</code> if the two Instances of Representation are different. <br>
   */
  virtual bool AreInstancesOfRepresentationIdentical(PLMIOmbVirtualObjectDescriptor const & iVOD) const = 0;

  virtual bool AreRelationalTargetIdentical(PLMIOmbVirtualObjectDescriptor_var & iVOD)const = 0;
  virtual bool AreRelationalTargetIdentical(PLMIOmbVirtualObjectDescriptor const & iVOD) const = 0;

  /**
   * Compares the Targets of two Virtual Object Descriptors.
   *
   *  @param  iVOD
   *      The Virtual Object Descriptor to compare with. <br>
   *      Input Parameter. <br>
   *  @return
   *      <code>true</code>  if the two Targets are identical. <br>
   *      <code>false</code> if the two Targets are different. <br>
   */
  virtual bool AreTargetsIdentical(PLMIOmbVirtualObjectDescriptor const & iVOD) const = 0;

  /**
   * For a valid Virtual Object Descriptor, gets the equivalent CATOmbObjectInContext
   *  @param  oObjectInContext [out]
   *      The equivalent CATOmbObjectInContext. <br>
   *      Output Parameter. <br>
   *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
   *      This parameter is returned to caller as NULL if method fails. <br>
   *      This parameter is valuated if method succeeds.
   *  @return
   *      <code>S_OK</code> if the method succeeds and a CATOmbObjectInContext is returned. <br>
   *      <code>E_INVALIDARG</code> if input parameter oObjectInContext is not provided as NULL. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT GetObjectInContext(CATOmxSR<CATOmbObjectInContext> & oObjectInContext) = 0;

  /**
  * Gets (if exists) the path of context instances (including if necessary an instance of representation) defining
  * the Virtual Object Descriptor relative context. <br>
  *
  *  @param   oPathOfContextInstances
  *      A path of instances. <br>
  *      Output parameter. <br>
  *      This list MUST be provided by caller as empty. This method returns an error otherwise. <br>
  *      This list is returned to caller as empty if method fails.
  *  @return
  *      <code>S_OK</code> if the method succeeds and the path was successfully retrieved. <br>
  *      <code>S_FALSE</code> if the method succeeds but there is no defined path. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetPathOfContextInstances(CATOmxList<CATIPLMComponent> & oPathOfContextInstances) const = 0;

  /**
   * Sets the path of context instances (including if necessary an instance of representation) defining
   * the Virtual Object Descriptor relative context. <br>
   *
   *  @param   iPathOfContextInstances
   *      A path of instances. <br>
   *      Input Parameter. <br>
   *      This list can be provided by caller as empty.
   *  @return
   *      <code>S_OK</code> if the method succeeds. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT SetPathOfContextInstances(CATOmxList<CATIPLMComponent> const & iPathOfContextInstances) = 0;

  /**
  * Gets (if exists) the context representation instance defining the Virtual Object Descriptor relative context.
  *
  *  @param  oContextRepresentationInstance [out]
  *      A Representation Instance. <br>
  *      Output parameter. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @return
  *      <code>S_OK</code> if the method succeeds. <br>
  *      <code>S_FALSE</code> if the method succeeds but there is no defined representation instance. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetContextInstanceOfRepresentation(CATOmxSR<CATIPLMComponent> & oContextRepresentationInstance) const = 0;

  /**
   * Sets the context representation instance defining the Virtual Object Descriptor relative context.
   *
   *  @param  iContextRepresentationInstance
   *      A Representation Instance. <br>
   *      Input Parameter. <br>
   *      This parameter can be provided by caller as NULL.
   *  @return
   *      <code>S_OK</code> if the method succeeds. <br>
   *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  virtual HRESULT SetContextInstanceOfRepresentation(CATIPLMComponent * iContextRepresentationInstance) = 0;

  /**
   * Compares the Paths of Context Instances of two Virtual Object Descriptors.
   *
   *  @param  iVOD
   *      The Virtual Object Descriptor to compare with. <br>
   *      Input Parameter. <br>
   *  @return
   *      <code>true</code>  if the two Paths of Instances are identical. <br>
   *      <code>false</code> if the two Paths of Instances are different. <br>
   */
  virtual bool ArePathsOfContextInstancesIdentical(PLMIOmbVirtualObjectDescriptor const & iVOD) const = 0;

  /**
   * Compares the context Instances of Representation of two Virtual Object Descriptors.
   *
   *  @param  iVOD
   *      The Virtual Object Descriptor to compare with. <br>
   *      Input Parameter. <br>
   *  @return
   *      <code>true</code>  if the two Instances of Representation are identical. <br>
   *      <code>false</code> if the two Instances of Representation are different. <br>
   */
  virtual bool AreContextInstancesOfRepresentationIdentical(PLMIOmbVirtualObjectDescriptor const & iVOD) const = 0;

  /**
  * Returns a synthetic description of the Virtual Object Descriptor.
  *
  *  @param  oPathOfInstances
  *     <code>TRUE</code> if a path of instances is defined. <br>
  *     <code>FALSE</code> otherwise.
  *  @param  oInstanceOfRepresentation
  *     <code>TRUE</code> if an instance of representation is defined. <br>
  *     <code>FALSE</code> otherwise.
  *  @param  oTarget
  *     <code>TRUE</code> if a target is defined and adheres to the specified interface. <br>
  *     <code>FALSE</code> otherwise.
  *  @param  oPathOfContextInstances
  *     <code>TRUE</code> if a path of context instances is defined. <br>
  *     <code>FALSE</code> otherwise.
  *  @param  oContextInstanceOfRepresentation
  *     <code>TRUE</code> if an context instance of representation is defined. <br>
  *     <code>FALSE</code> otherwise.
  *  @param  iTargetIID
  *      The interface filtering the target (if exists). <br>
  *      IID_CATBaseUnknown by default.
  */
  virtual void GetKind(CATBoolean & oPathOfInstances, CATBoolean & oInstanceOfRepresentation, CATBoolean & oTarget, CATBoolean & oPathOfContextInstances, CATBoolean & oContextInstanceOfRepresentation, const IID & iTargetIID = IID_CATBaseUnknown) const = 0;

  USINGPLMIOMBLEGACYVIRTUALOBJECTDESCRIPTORMETHODS;
};

CATDeclareHandler(PLMIOmbVirtualObjectDescriptor, CATBaseUnknown);

#endif
