#ifndef CATOmbObjectInContext_h
#define CATOmbObjectInContext_h
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATOmbObjectInContext.h
//
//===================================================================
//
// Usage notes:
// Class to represent an objects in a context.
//
//===================================================================
//
//  Jun 2009  Creation: frg
//===================================================================
/**
  * @CAA2Level L1
  * @CAA2Usage U1
  */
#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATListPtrCATIPLMComponent.h"

class CATIPLMComponent;
class CATOmbObjectInContext_var;

/**
* Class representing an object in a context.
* <br>Role:</b>This class represents an object in a context. 
* A context means an occurrence or a representation occurrence
* which can be seen as a path of instances and/or a representation instance.
* An object a PLM object other that an instance (a connection, a port, a reference or a representation)
* or an internal object of a representation or of a connection.
* An object in a context means the usage of this object in the context of this occurrence.
*/
class ExportedByCATObjectModelerBase CATOmbObjectInContext : public CATBaseUnknown
{
	CATDeclareClass;

public: 
    /**
     * Creates a CATOmbObjectInContext for an object and a context.
     * @param iPathOfInstances
     *    The path of instances describing the context of the object (optional).
     * @param iRepInstance
     *    The instance of the representation containing the object (optional).
     * @param iObject
     *    The object (optional).
     * @param oObjectInContext [out, CATBaseUnknown#Release]
     *    The built CATOmbObjectInContext representing the object in this context.
     * @return
     *    <ul><li>S_OK if oObjectInContext has been successfully created.</li>
     *        <li>E_INVALIDARG if iPathOfInstances and iRepInstance do not represent a valid context for iObject</li>
     *        <li>E_FAIL otherwise.</li>
     *    </ul>
     */
	static HRESULT CreateObjectInContext(CATLISTP(CATIPLMComponent)& iPathOfInstances, CATIPLMComponent* iRepInstance,
                        CATBaseUnknown* iObject, CATOmbObjectInContext *& oObjectInContext);
    /**
     * Creates a CATOmbObjectInContext_var for an object and a context.
     * @param iPathOfInstances
     *    The path of instances describing the context of the object (optional).
     * @param iRepInstance
     *    The instance of the representation containing the object (optional).
     * @param iObject
     *    The object (optional).
     * @param oObjectInContext
     *    The built CATOmbObjectInContext_var representing the object in this context.
     * @return
     *    <ul><li>S_OK if oObjectInContext has been successfully created.</li>
     *        <li>E_INVALIDARG if iPathOfInstances and iRepInstance do not represent a valid context for iObject</li>
     *        <li>E_FAIL otherwise.</li>
     *    </ul>
     */
	static HRESULT CreateObjectInContext(CATLISTP(CATIPLMComponent)& iPathOfInstances, CATIPLMComponent* iRepInstance,
                        CATBaseUnknown* iObject, CATOmbObjectInContext_var& oObjectInContext);

    /**
     * Gets (if exists) the path of instances defining this CATOmbObjectInContext instance. <br>
     * In the case of a VO Descriptor only composed of an instance, it corresponds to a path of instances composed of a single instance.
     *
     *  @param   oPathOfInstances
     *      A path of instances. <br>
     *      Output parameter. <br>
     *      This list MUST be provided by caller as empty. This method returns an error otherwise. <br>
     *      This list is returned to caller as empty if method fails.
     *      Items in this returned list must be released by the caller after use !!
     *  @return
     *      <code>S_OK</code> if the method succeeds and the path was successfully retrieved. <br>
     *      <code>S_FALSE</code> if the method succeeds but there no defined path. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetPathOfInstances(CATLISTP(CATIPLMComponent) &oPathOfInstances) const = 0;
     /**
     * Gets (if exists) the representation instance defining this CATOmbObjectInContext instance.
     *
     *  @param  opRepresentationInstance [CATBaseUnknown#Release]
     *      A Representation Instance. <br>
     *      Output parameter. <br>
     *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
     *      This parameter is returned to caller as NULL if method fails. <br>
     *      This parameter is valuated if method succeeds.
     *  @return
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there no defined representation instance. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetInstanceOfRepresentation(CATIPLMComponent *&opRepresentationInstance) const = 0;
    /**
     * Gets (if exists) the object defining this CATOmbObjectInContext instance. <br>
     * <u>Note</u>: The object can be a proxy if this CATOmbObjectInContext has been retrieved from a link.
     * 
     *  @param  opObject [CATBaseUnknown#Release]
     *      The object if defined. <br>
     *      Output parameter. <br>
     *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
     *      This parameter is returned to caller as NULL if method fails. <br>
     *      This parameter is valuated if method succeeds.
     *  @param  iIID
     *      The desired interface.
     *  @return
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there no defined object. <br>
     *      <code>E_NOINTERFACE</code> if the method succeeds but there defined object does not adhere to the specified interface. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetObjectOutOfContext(CATBaseUnknown *&opObject, const IID &iIID=IID_CATBaseUnknown) const = 0;
    /**
     * Retrieves the root PLM Reference of the context.
     * The root PLM Reference of the context is retrieved with the following algorithm:
     * <ul>
     * <li>If there is a path of PLM Instances,
     *     the root reference is the PLM Reference aggregating the first PLM Instance of the path</li>
     * <li>If there is no path of PLM Instances but a PLM Representation instance,
     *     the root reference is the PLM Reference aggregating the PLM Representation instance</li>
     * <li>If there is no PLM first instances and no PLM Representation instance,
     *     there is no context and therefore no Context Root Reference.</li>
     * </ul>
     *  @param  oContextRootReference [CATBaseUnknown#Release]
     *      A PLM Reference. <br>
     *      Output parameter. <br>
     *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
     *      This parameter is valuated if method returns S_OK.
     *      This parameter is returned to caller as NULL if method returns S_FALSE. <br>
     *      This parameter is returned to caller as NULL if method fails. <br>
     *  @return
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there no Context Root Reference to return. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>

     */
    virtual HRESULT GetContextRootReference(CATIPLMComponent *&oContextRootReference) const = 0;

    /**
     * Compares this object in context to an other object in context (same path of instances and/or representation instance, same object out of context).
     *
     *  @param  ipObjectInContextToCompare [in]
     *      The object in context to compare with. <br>
     *      This parameter MUST NOT be provided by caller as NULL. This method returns an error otherwise.
     *  @return
     *      <code>S_OK</code> if the method succeeds and the two object in context are identical. <br>
     *      <code>S_FALSE</code> if the method succeeds but the two object in context are different. <br>
     *      <code>E_INVALIDARG</code> if parameter provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */    
    virtual HRESULT Compare (const CATOmbObjectInContext * ipObjectInContextToCompare) const = 0 ;

};


CATDeclareHandler( CATOmbObjectInContext , CATBaseUnknown );


#endif


