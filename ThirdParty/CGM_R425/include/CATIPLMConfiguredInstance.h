// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMConfiguredInstance.h
// Define the CATIPLMConfiguredInstance interface
//
//===================================================================
//
// Usage notes:
//   New interface: Exposes the behaviors of any configured PLMInstance. 
//
//===================================================================
//
//  Nov 2005  Creation: Code generated by the CAA wizard  LLV
//===================================================================
/**
  * @level Protected
  * @usage U4 CATPLMConfiguredInstanceAdapter 
*/
#ifndef CATIPLMConfiguredInstance_H
#define CATIPLMConfiguredInstance_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMConfiguredInstance;
#else
extern "C" const IID IID_CATIPLMConfiguredInstance ;
#endif

class CATICfgEffectivity;
class CATICfgQuery;
//------------------------------------------------------------------

/**
* Interface used to handle Configuration on an Instance.
* <br><b>Role</b>: Components that implement
* CATIPLMConfiguredInstance are Instances of PLM Model.<br>
* It is used to manage Configuration links between Instances 
* and Effectivity/ StaticMapping Objects.
* These objects are manipulated through these Interfaces: 
* @href CATICfgEffectivity, @href CATICfgQuery. <br>
* Use this Interface only on Instances.
* The methods of this Interface can be used successfully only if Config Information is loaded in session.
*
* <p><b>BOA information</b>: this interface can be implemented
* using the BOA (Basic Object Adapter).
* To know more about the BOA, refer to the CAA Encyclopedia home page.
* Click Middleware at the bottom left, then click the Object Modeler tab page.
* Several articles deal with the BOA.</p>
* 
*/
class ExportedByCATPLMComponentInterfaces CATIPLMConfiguredInstance: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	  /** 
                  * DEPRECATED (use CATIPLMConfigFilterable interface instead)
                  *
	  * Tells if an effectivity is already defined on this Instance.
	  *
	  * <br><b>Role</b>: Even if Configuration data is not loaded in session, 
	  * this method tells if an Effectivity has already been defined on this Instance.
	  *
	  * @return
	  *      A CATBoolean value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>TRUE</tt></dt>
	  *       <dd>An effectivity is already defined on this Instance.</dd>
	  *     <dt><tt>FALSE</tt></dt>
	  *       <dd>No effectivity is defined on this Instance.</dd>
	  *     </dl>
	  *
	  */
	  virtual CATBoolean HasEffectivity() = 0;

	  /** 
                  * DEPRECATED (use CATIPLMConfigFilterable interface instead)
                  *
	  * Gets the Effectivity defined for this Instance.
	  *
	  * <b>Role:</b> 
	  * If an Effectivity has been assigned to this Instance, gets a pointer
	  * on this Effectivity through the @href CATICfgEffectivity interface.
	  *
	  * @param opiEff [out]
	  *   The Effectivity defined on this Instance.
	  *	  NULL if no Effectivity has been set.
	  *
	  * @return
	  *      An HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The effectivity has been successfully retrieved.</dd>
	  *     <dt><tt>E_INVALIDARG</tt></dt>
	  *       <dd>If <tt>opiEff</tt> is not NULL at beginning of method.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>Otherwise.</dd>
	  *     </dl>
	  *     @error CATInternalError BridgeERR001
      *      Configuration bridge is not loaded, impossible to access configuration information.
	  *
	  */
	  virtual HRESULT GetEffectivity(CATICfgEffectivity* & opiEff) = 0;

	  /** 
                  * DEPRECATED (use CATIPLMConfigFilterable interface instead)
                  *
	  * Sets an Effectivity on this Instance.
	  *
	  * <b>Role:</b> 
	  * Sets an Effectivity on this Instance. 
	  * The Effectivity <tt>ipiEff</tt> must belong to the VariabilitySpace defined on the owner if this Instance.
	  * If no VariabilitySpace is defined on owner, this method will add it automatically.
	  * If an Effectivity is already defined on this Instance, it will be replaced by the given one.
      * 
	  * @param ipiEff [in]
	  *   The Effectivity to be defined on this Instance.
	  *
	  * @return
	  *      An HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The effectivity has been successfully set.</dd>
	  *     <dt><tt>E_INVALIDARG</tt></dt>
	  *       <dd>If <tt>ipiEff</tt> is NULL.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>Otherwise.</dd>
	  *     </dl>
	  *     @error CATInternalError BridgeERR001
      *      Configuration bridge is not loaded, impossible to access configuration information.
	  *     @error CATInternalError BridgeERR002
	  *      Effectivity is not defined on the Variability Space associated to the product.
	  *
	  */
	  virtual HRESULT SetEffectivity(CATICfgEffectivity* ipiEff) = 0;

	  /** 
	  * Removes the Effectivity defined on this Instance.
	  *
	  * <b>Role:</b> 
	  * Removes the Effectivity, if it exists.
	  *
	  * @return
	  *      An HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The Effectivity defined on this Instance has been successfully removed.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>No Effectivity has been defined on this Instance.</dd>
	  *     </dl>
	  *
	  */
	  virtual HRESULT RemoveEffectivity() = 0;

	  /** 
	  * Tells if a StaticMapping is already defined on this Instance.
	  *
	  * <br><b>Role</b>: Even if Configuration data is not loaded in session, 
	  * this method tells if a StaticMapping has already been defined on this Instance.
	  *
	  * @return
	  *      A CATBoolean value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>TRUE</tt></dt>
	  *       <dd>A StaticMapping is already defined on this Instance.</dd>
	  *     <dt><tt>FALSE</tt></dt>
	  *       <dd>No StaticMapping is defined on this Instance.</dd>
	  *     </dl>
	  *     @error CATInternalError BridgeERR001
      *      Configuration bridge is not loaded, impossible to access configuration information.
	  *
	  */
	  virtual CATBoolean HasStaticMapping() = 0;

	  /** 
	  * Gets the StaticQuery defined for this Instance.
	  *
	  * <b>Role:</b> 
	  * If a StaticQuery has been assigned to this Instance, gets a pointer
	  * on this StaticQuery through the @href CATICfgQuery interface.
	  *
	  * @param opiQuery [out, CATBaseUnknown#Release]
	  *   The StaticQuery defined on this Instance.
	  *	  NULL if no StaticQuery has been set.
	  *
	  * @return
	  *      An HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The StaticQuery has been successfully retrieved.</dd>
	  *     <dt><tt>E_INVALIDARG</tt></dt>
	  *       <dd>If <tt>opiQuery</tt> is not NULL at beginning of method.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>Otherwise.</dd>
	  *     </dl>
	  *     @error CATInternalError BridgeERR001
      *      Configuration bridge is not loaded, impossible to access configuration information.
	  *
	  */
	  virtual HRESULT GetStaticQuery(CATICfgQuery* & opiQuery) = 0;

	  /** 
	  * Sets a StaticQuery on this Instance.
	  *
	  * <b>Role:</b> 
	  * Sets a StaticQuery on this Instance.
	  * The Query <tt>ipiQuery</tt> must be defined on the Reference if this Instance.
	  * If a StaticQuery is already defined on this Instance, it will be replaced by the given one.
      *
	  * @param ipiQuery [in]
	  *   The StaticQuery to be defined on this Instance.
	  *
	  * @return
	  *      An HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The StaticQuery has been successfully set.</dd>
	  *     <dt><tt>E_INVALIDARG</tt></dt>
	  *       <dd>If <tt>ipiQuery</tt> is NULL.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>Otherwise. The given StaticQuery is not defined on the Reference of this Instance.</dd>
	  *     </dl>
	  *     @error CATInternalError BridgeERR001
      *      Configuration bridge is not loaded, impossible to access configuration information.
	  *     @error CATInternalError BridgeERR003
	  *      Static query is not defined on the Variability Space associated to the product.
	  *
	  */
	  virtual HRESULT SetStaticQuery(CATICfgQuery* ipiQuery) = 0;

	  /** 
	  * Removes the StaticQuery defined on this Instance.
	  *
	  * <b>Role:</b> 
	  * Removes the StaticQuery, if it exists.
	  *
	  * @return
	  *      An HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The StaticQuery defined on this Instance has been successfully removed.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>Otherwise.</dd>
	  *     </dl>
	  *     @error CATInternalError BridgeERR001
      *      Configuration bridge is not loaded, impossible to access configuration information.
	  *
	  */
	  virtual HRESULT RemoveStaticQuery() = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler(CATIPLMConfiguredInstance, CATBaseUnknown );

#endif
