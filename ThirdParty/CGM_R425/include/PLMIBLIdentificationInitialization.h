// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// PLMIBLIdentificationInitialization.h
// Define the PLMIBLIdentificationInitialization interface
//
//===================================================================
// Apr 2007  Creation: Code generated by the CAA wizard DOV
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef PLMIBLIdentificationInitialization_H
#define PLMIBLIdentificationInitialization_H

// Export
#include "PLMBusinessLogicInterfaces.h"

// Inheritance
#include "CATBaseUnknown.h"

class CATListValCATIInstance_var;
class PLMIBLErrorIterator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMBusinessLogicInterfaces IID IID_PLMIBLIdentificationInitialization;
#else
extern "C" const IID IID_PLMIBLIdentificationInitialization;
#endif

/**
* Interface to launch the integration of the business logic definition related to the PLM identification initialization : PLM Opening ID="PLMIdentificationInitialization".
*/
class ExportedByPLMBusinessLogicInterfaces PLMIBLIdentificationInitialization: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /** List of supported operation Id.*/
  enum OperationId {
    New = 0,
    Implicit = 1,
    Cloning = 2,
    ImportAsNew =3,
    Default = 4,
    NewFrom = 5,
    ImportAsRef = 6
  };

  /** List of supported operation details.*/
	enum OperationDetail {
		NoOperationDetail = 0,
		Create = 1,
		CopyPaste = 2,
		ConfiguredSplit =3,
		ReplaceReference = 4,
		CloneDistantData = 5,
		WorkspaceSynchronization =6, //nodoc LA
		WorkspaceDelivery =7, //nodoc LA  
		NewEvolution=8, 
		AssemblySymmetry =9,
		ProductFiltering=10,
		ProductFilteringAndMerging=11,
		ProductSimplificationAndMerging=12,
    InsertLogicalClone = 13 // Insert as New Variant
	};

  /**
  * Provides the PLM identification initialization specified by the business logic definition.
  *
  * @param iOperationId
  *   Operation Id to differentiate the contextual usage. Authorized values are:
  *   <ul>
  *       <li> PLMIBLIdentificationInitialization::New (for PLM new command) </li>
  *       <li> PLMIBLIdentificationInitialization::Implicit (for modeler implicit factories) </li>
  *       <li> PLMIBLIdentificationInitialization::Cloning (for any duplication operation: Save As New, Duplicate, ...) </li>
  *       <li> PLMIBLIdentificationInitialization::ImportAsNew (for import operations) </li>
  *       <li> PLMIBLIdentificationInitialization::Default (for any other request) </li>
  *   </ul>
  * @param iPLMContextList
  *   List of contextual objects and parameters. Each context may either be NULL or hold the following information:
  *   <ul>
  *       <li> IncSessionId (integer): DEPRECATED</li>
  *       <li> IdString (string): parameter used to pre-valuate the identifier attribute. If not defined then initialized from settings Tools / Options / Identification / Identification String.</li>
  *       <li> IdCloningString (string): parameter valuated when OperationId="Cloning". This is a string which can be optionally filled by the duplicate dialogs.</li>
  *       <li> CopyFrom (object): parameter valuated when OperationId="Cloning". This a proxy object of the original PLM entity to clone. Reading this PLM entity, the BL can retrieve original attributes values.</li>
  *       <li> CoupledRef (object): when a couple PLM Part Reference/Representation Reference is created in one shot, this parameter provides a proxy object of the aggregating Part Reference. Reading this PLM entity, the BL can to initialize the Representation naming based on the aggregating Reference's one.</li>
  *       <li> AggregatingReference (object): when a PLM Instance is created, this parameter provides a pointer to the PLM Reference entity that will aggregate the PLM instance. Reading this PLM entity, the BL can initialized the Instance naming based on its aggregating reference name. </li>
  *       <li> Reference (object): when a PLM Instance is created, this parameter provides a pointer to the PLM Reference entity of the PLM instance. Reading this PLM entity, the BL can initialized the Instance naming based on its reference name.</li>
  *   </ul>
  * @param iPLMComponentList
  *   List of component proxies on which will be apply the identification initialization
  * @param iOperationDetail
  *   Operation Id to differentiate the contextual usage. Authorized values are:
  *   <ul>
  *       <li> PLMIBLIdentificationInitialization::NoOperationDetail (when called by the commands not specified afterwards) </li>
  *       <li> PLMIBLIdentificationInitialization::Create (when called by the commands insert New or Insert Existing) </li>
  *       <li> PLMIBLIdentificationInitialization::CopyPaste (when called by the commands copy-paste, cut-paste, drap and drop) </li>
  *       <li> PLMIBLIdentificationInitialization::ConfiguredSplit ( when called by the command Configured Split) </li>
  *        <li> PLMIBLIdentificationInitialization::InsertLogicalClone ( when called by the command Insert as New Variant) </li>
  *       <li> PLMIBLIdentificationInitialization::ReplaceReference ( when called by the commands Replace By Existing, Replace By Version, Replace Global) </li>
  *       <li> PLMIBLIdentificationInitialization::CloneDistantData ( when called by the commands Duplicate ) </li>
  *   </ul>
  *
  * @return
  *   <ul>
  *       <li> S_OK     if the business logic is successfully integrated </li>
  *       <li> S_FALSE  in following cases :
  *           <ul>
  *               <li>  if their is no business logic to integrate for at least one component </li>
  *               <li>  if there are some truncation problems : warnings risen by knowledge on attribute valuation 
  *                     according to dictionary. In this case , the caller has to ignore or to deal with the truncation
  *               </li>
  *           </ul>
  *       <li> E_FAIL   if an error occurs. The following error classes and error identifiers can be associated with:
  *           <ul>
  *               <li>  @error PLMBLIdentificationInitializationError PLMBLIdentificationInitializationError::RunInitialization::InternalError
  *                     The business logic access service failed
  *               </li>
  *               <li>  @error PLMBLIdentificationInitializationError PLMBLIdentificationInitializationError::RunInitialization::ExecutionError
  *                     The business logic definition execution failed
  *               </li>
  *           </ul>
  *       </li>
  *   </ul>
  */
  virtual HRESULT RunInitialization(PLMIBLIdentificationInitialization::OperationId iOperationId,
    CATListValCATIInstance_var & iPLMContextList,
    CATListValCATIInstance_var & ioPLMComponentList,
    PLMIBLIdentificationInitialization::OperationDetail iOperationDetail = PLMIBLIdentificationInitialization::NoOperationDetail) = 0;
 /**
  * Provides the list of attributes on which there is a problem of truncation.
  *
  * @param oBLErrorIterator
  *   The handle on which you are able to acces to attributes with truncation problems
  *
  * @return
  *   <ul>
  *       <li> S_OK     if the iterator is successfully returned </li>
  *       <li> S_FALSE  if no truncation problem has occured  </li>
  *       <li> E_FAIL   if an error occurs. 
  *       </li>
  *   </ul>
  */
  virtual HRESULT GetBLValuationErrorIterator(PLMIBLErrorIterator *& oBLErrorIterator) = 0;
};

#endif