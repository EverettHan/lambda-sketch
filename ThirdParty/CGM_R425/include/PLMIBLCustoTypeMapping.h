// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// PLMIBLCustoTypeMapping.h
// Define the PLMIBLCustoTypeMapping interface
//
//===================================================================
//
// Usage notes:
//   Interface to launch the integration of the business logic definition related to the PLM Custo Type Mapping.
//
//===================================================================
//
//  Jul 2009  Creation: Code generated by the CAA wizard  PIR
//===================================================================
/**
* @level Protected
* @usage U3
*/

#ifndef PLMIBLCustoTypeMapping_H
#define PLMIBLCustoTypeMapping_H

#include "PLMBusinessLogicInterfaces.h"
#include "CATBaseUnknown.h"

class CATListValCATIInstance_var;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMBusinessLogicInterfaces IID IID_PLMIBLCustoTypeMapping;
#else
extern "C" const IID IID_PLMIBLCustoTypeMapping ;
#endif

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Component that implement
* PLMIBLCustoTypeMapping is PLMEBLCustoTypeMapping
* <p>
* Do not use the PLMIBLCustoTypeMapping interface for such and such

*
* @example
*  // example is optional
*  PLMIBLCustoTypeMapping* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_PLMIBLCustoTypeMapping,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByPLMBusinessLogicInterfaces PLMIBLCustoTypeMapping: public CATBaseUnknown
{
  CATDeclareInterface;

public:

    /** List of supported operation Id.*/
    enum OperationId {
		Coexistence = 0,
        FBDIImport = 1,
        BriefcaseImport = 2	,
				DataExchangeImport =3
    };

    /** OML deprecated -> to remove once all caller have replaced this method by the one which gives oCustoPolicy
    * Provides the PLM Custo Types Mapping specified by the business logic definition. 
    *
    * @param iOperationId
    *   Operation Id to differentiate the contextual usage. Authorized values are:
    *   <ul>
	*		<li> PLMIBLCustoTypeMapping::Coexistence (for PLM Coexistence scenario) </li>
    *       <li> PLMIBLCustoTypeMapping::FBDIImport (for PLM Import CATIA File command) </li>
    *       <li> PLMIBLCustoTypeMapping::BriefcaseImport (for any other request) </li>
    *   </ul>
    * @param iPLMContextList
    *   List of contextual objects and parameters. Each context may either be NULL or hold the following information:
    *   <ul>
    *       <li> SourceObject (object): parameter valuated when OperationId="Coexistence". This is a proxy object of the original PLM entity to transfer. Reading this PLM entity, the BL can retrieve its type and original attributes values.</li>
    *   </ul>
    * @param iPLMComponentList
    *   List of component proxies on which will be applied the custo type mapping.
	*
	* @param oCustoType
    *   The output customization type computed by the rule.
	*
	* @param oCustoDiscipline
    *   The output custo discipline type computed by the rule.
	*
    *
    * @return
    *   <ul>
    *       <li> S_OK     if the business logic is successfully integrated </li>
    *       <li> S_FALSE  if their is no business logic to integrate for at least one component </li>
    *       <li> E_FAIL   if an error occurs. The following error classes and error identifiers can be associated with:
    *           <ul>
    *               <li>  @error PLMBLCustoTypeMappingError PLMBLCustoTypeMappingError::RunMapping::InternalError
    *                     The business logic access service failed
    *               </li>
    *               <li>  @error PLMBLCustoTypeMappingError PLMBLCustoTypeMappingError::RunMapping::ExecutionError
    *                     The business logic definition execution failed
    *               </li>
    *           </ul>
    *       </li>
    *   </ul>
    */
    virtual HRESULT RunMapping(PLMIBLCustoTypeMapping::OperationId iOperationId,
                                      CATListValCATIInstance_var & iPLMContextList,
                                      CATListValCATIInstance_var & ioPLMComponentList,
									  CATUnicodeString& oCustoName,
									  CATUnicodeString& oCustoDiscipline) = 0;

	    /**
    * Provides the PLM Custo Types Mapping specified by the business logic definition. 
    *
    * @param iOperationId
    *   Operation Id to differentiate the contextual usage. Authorized values are:
    *   <ul>
	*		<li> PLMIBLCustoTypeMapping::Coexistence (for PLM Coexistence scenario) </li>
    *       <li> PLMIBLCustoTypeMapping::FBDIImport (for PLM Import CATIA File command) </li>
    *       <li> PLMIBLCustoTypeMapping::BriefcaseImport (for any other request) </li>
    *   </ul>
    * @param iPLMContextList
    *   List of contextual objects and parameters. Each context may either be NULL or hold the following information:
    *   <ul>
    *       <li> SourceObject (object): parameter valuated when OperationId="Coexistence". This is a proxy object of the original PLM entity to transfer. Reading this PLM entity, the BL can retrieve its type and original attributes values.</li>
    *   </ul>
    * @param iPLMComponentList
    *   List of component proxies on which will be applied the custo type mapping.
	*
	* @param oCustoType
    *   The output customization type computed by the rule.
	*
	* @param oCustoDiscipline
    *   The output custo discipline type computed by the rule.
	*
	* @param oCustoPolicy
    *   The output policy type computed by the rule.
	*
    *
    * @return
    *   <ul>
    *       <li> S_OK     if the business logic is successfully integrated </li>
    *       <li> S_FALSE  if their is no business logic to integrate for at least one component </li>
    *       <li> E_FAIL   if an error occurs. The following error classes and error identifiers can be associated with:
    *           <ul>
    *               <li>  @error PLMBLCustoTypeMappingError PLMBLCustoTypeMappingError::RunMapping::InternalError
    *                     The business logic access service failed
    *               </li>
    *               <li>  @error PLMBLCustoTypeMappingError PLMBLCustoTypeMappingError::RunMapping::ExecutionError
    *                     The business logic definition execution failed
    *               </li>
    *           </ul>
    *       </li>
    *   </ul>
    */
    virtual HRESULT RunMapping(PLMIBLCustoTypeMapping::OperationId iOperationId,
                                      CATListValCATIInstance_var & iPLMContextList,
                                      CATListValCATIInstance_var & ioPLMComponentList,
									  CATUnicodeString& oCustoName,
									  CATUnicodeString& oCustoDiscipline,
									  CATUnicodeString& oCustoPolicy) = 0;
	/**
    * Provides the name of the source and target providers to give a context to the mapping. 
    *
    * @param iSource
    *   The name of the source provider to differentiate the contextual usage.
	*
	* @param iTarget
    *   The name of the target provider to differentiate the contextual usage.
	*
    */
	virtual void SetSourceAndTarget(CATUnicodeString& iSource, CATUnicodeString& iTarget) = 0;

	/**
    * Provides the name of the source obect type. 
    *
    * @param iSourceTypeName
    *   The name of the source obect type.
	*
    */
	virtual void SetSourceTypeName(CATUnicodeString& iSourceTypeName) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif