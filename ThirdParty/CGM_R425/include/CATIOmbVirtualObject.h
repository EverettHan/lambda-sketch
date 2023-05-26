#ifndef CATIOmbVirtualObject_h
#define CATIOmbVirtualObject_h
// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbVirtualObject.h
//
//===================================================================
//
// Usage notes:
// Interface to manage persistent linkability in CATIA session.
//
//===================================================================
//
//  Sept 2006  Creation: pbv 
//===================================================================
/**
  * @CAA2Required                   
  */
#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATListPtrCATIPLMComponent.h"

class CATOmbObjectInContext;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbVirtualObject;
#else
extern "C" const IID IID_CATIOmbVirtualObject;
#endif

/**
 * Interface representing link objects. 
 * <b>Role</b>: When a universal link is created with a path of PLM first instances,
 * the pointing object is linked to a virtual object. This object can retrieved :
 * <ul>
 * <li>Before the link is set, by calling @href CATIOmbUniversalLink#GetReferencedObject</li>
 * <li>Once the link is established (with @href CATISpecAttrAccess#SetExternalLink), by calling @href CATISpecAttrAccess#GetExternalObject</li>
 * <br>Refer to Object Modeler technical article for more information.
*/
class ExportedByCATObjectModelerBase CATIOmbVirtualObject : public CATBaseUnknown
{
  CATDeclareInterface;

public:

 /**
  * Returns the path of PLM first instances describing the context of the link target.
  * 
  *   @param oPathOfFirstInstance
  *      The path of PLM first instances [out, CATBaseUnknown#Release]
  *   @return
  *      <ul><li>S_OK if the path was successfully retrieved</li>
  *          <li>S_FALSE if there is no associated path</li>
  *          <li>E_INVALIDARG if output list size is not null</li>
  *          <li>E_FAIL otherwise</li>
  *      </ul>
  */
  virtual HRESULT GetPathOfFirstInstances (CATLISTP(CATIPLMComponent) & oPathOfFirstInstance) =0;

  /**
   * Retrieves the PLM instance of the representation containing the link target. 
   * 
   *   @param opRepInstance [out, CATBaseUnknown#Release]
   *      The PLM Representation instance.
   *   @return
   *      <ul><li>S_OK if the PLM Representation Instance was successfully retrieved</li>
   *          <li>S_FALSE if there is no associated PLM Representation instance</li>
   *          <li>E_INVALIDARG if output parameter is not null</li>
   *          <li>E_FAIL otherwise</li>
   *      </ul>
   */
  virtual HRESULT GetRepInstance (CATIPLMComponent *& opRepInstance) =0;

  /**
   * Retrieves the target of the link.
   * 
   *   @param opTarget [out, CATBaseUnknown#Release]
   *      The link target object.
   *   @return
   *      <ul><li>S_OK if the target object was successfully retrieved</li>
   *          <li>S_FALSE if there is no associated target</li>
   *          <li>E_INVALIDARG if output parameter is not null</li>
   *          <li>E_FAIL otherwise</li>
   *      </ul>
   */
  virtual HRESULT GetTarget (CATBaseUnknown *& opTarget) =0;

  /**
   * Retrieves the root PLM component.
   *
   * The root PLM component depends on the type of the first pointing PLM component.
   * If the first pointing component is a PLM Reference or a PLM Representation Reference it will
   * be directly returned, otherwise it is the aggregating PLM component.
   * The root PLM component is retrieved with the following algorithm:
   * <ul>
   * <li>If there is a path of PLM first instances,
   *     the root is the PLM Reference aggregating the first element</li>
   * <li>If there is no PLM first instances but a PLM Representation instance,
   *     the root is the PLM Reference aggregating the PLM Representation instance</li>
   * <li>If there is no PLM first instances and no PLM Representation instance
   * <ul>
   *    <li>and the target is a PLM Port or a PLM Connection: 
   *        the root is the aggregating PLM Reference</li>
   *    <li>and the target is a PLM Representation Reference or an element inside it:
   *        The root is the PLM Representation Reference itself</li>
   * </ul>
   * </li>
   * </ul>
   * 
   *   @param opRoot [out, CATBaseUnknown#Release]
   *      The PLM root component
   *   @return
   *      <ul><li>S_OK if the PLM root component was successfully retrieved</li>
   *          <li>E_INVALIDARG if output parameter not null</li>
   *          <li>E_FAIL if no PLM root component is found.</li>
   *      </ul>
   */
  virtual HRESULT GetRoot (CATIPLMComponent *& opRoot) =0;

    /**
     * Creates an CATOmbObjectInContext representing the current CATIOmbVirtualObject.
     * @param oObjectInContext [out, CATBaseUnknown#Release]
     *    The built CATOmbObjectInContext representing the CATIOmbVirtualObject.
     * @return
     *    <ul><li>S_OK if oObjectInContext has been successfully created.</li>
     *        <li>E_INVALIDARG if output parameter not null</li>
     *        <li>E_FAIL otherwise.</li>
     *    </ul>
     */
  virtual HRESULT GetObjectInContext(CATOmbObjectInContext *& oObjectInContext) = 0;
};

CATDeclareHandler(CATIOmbVirtualObject,CATBaseUnknown);

#endif
