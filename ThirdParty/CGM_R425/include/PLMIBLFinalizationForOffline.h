// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PLMIBLFinalizationForOffline.h
//
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef PLMIBLFinalizationForOffline_H
#define PLMIBLFinalizationForOffline_H

#include "PLMBusinessLogicInterfaces.h"
#include "CATBaseUnknown.h"

class CATListValCATIInstance_var;
class PLMIBLErrorIterator;
class CATIInstance_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMBusinessLogicInterfaces IID IID_PLMIBLFinalizationForOffline;
#else
extern "C" const IID IID_PLMIBLFinalizationForOffline;
#endif

/**
* Interface to launch the integration of the business logic definition related to the PLM identification initialization in offline : PLM Opening ID="PLMFinalizationForOffline".
*/
class ExportedByPLMBusinessLogicInterfaces PLMIBLFinalizationForOffline : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
  * Provides the PLM finalization for offline creation specified by the business logic definition.
  *
  * @param iPLMContextList
  *   List of contextual objects and parameters. Each context may either be NULL or hold the following information:
  *   <ul>
  *       <li> IdString (string): parameter used to pre-valuate the identifier attribute. If not defined then initialized from settings Tools / Options / Identification / Identification String.</li>
  *       <li> AggregatingReference (object): when a PLM Instance is finalized, this parameter provides a pointer to the PLM Reference entity that aggregates the PLM instance. Reading this PLM entity, the BL can finalize the Instance naming based on its aggregating reference name.</li>
  *       <li> Reference (object): when a PLM Instance is finalized, this parameter provides a pointer to the PLM Reference entity of the PLM instance. Reading this PLM entity, the BL can finalize the Instance naming based on its reference name.</li>
  *   </ul>
  * @param iPLMComponentList
  *   List of components on which will be apply the finalizatino
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
  virtual HRESULT RunFinalization(
    CATListValCATIInstance_var & iPLMContextList,
    CATListValCATIInstance_var & ioPLMComponentList) = 0;

  /**
   * Same as previous but unitary
   */
  virtual HRESULT RunFinalization(
    CATIInstance_var & iPLMContext,
    CATIInstance_var & ioPLMComponent) = 0;

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
