// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// PLMIBLCommandInput.h
//
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef PLMIBLCommandInput_H
#define PLMIBLCommandInput_H

#include "PLMBusinessLogicInterfaces.h"
#include "CATBaseUnknown.h"

class CATString;
class CATListValCATIInstance_var;
class PLMIBLErrorIterator;
class CATIInstance_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMBusinessLogicInterfaces IID IID_PLMIBLCommandInput;
#else
extern "C" const IID IID_PLMIBLCommandInput;
#endif

/**
* Interface to launch the integration of the business logic definition related to the validation of interactive command input argument 
* For this BL, PLM Opening ID="PLMCommandInputCheck".
*/
class ExportedByPLMBusinessLogicInterfaces PLMIBLCommandInput : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
  * Tells whether the launched command is valid for the selected object from the business logic point of view.
  *
  * @param iCmdId
  *   launched interactive command. 
  *   Supported command list as of interface creation time: 
  *   <ul>
  *      <li> InsertNew </li>
  *      <li> InsertExisting </li>
  *      <li> ReplaceByExisting </li>
  *      <li> Copy </li>
  *      <li> Cut </li>
  *      <li> Paste </li>
  *      <li> Delete </li>
  *      <li> Reparent </li>
  *      <li> CopyByDragNDrop</li>
  *   </ul>
  *   For additional commands support, please contact team in charge of this BL definition and deployment.
  *
  * @param iListInputObjects
  *   List of objects (either components or occurrences, depending on command) which the interactive command will take as selected input
  * @param oListValidObjects
  *   List of objects (either components or occurrences, depending on command) for which the interactive command is valid
  *
  * @return
  *   <ul>
  *       <li> S_OK     if the business logic is OK for all objects </li>
  *       <li> S_FALSE  if the business logic is OK for a subset of all input objects </li> 
  *       <li> E_FAIL   if an error occured or if no object has been accepted by the Business Logic for the command. The following error classes and error identifiers can be associated with:
  *           <ul>
  *               <li>  @error PLMBLCommandInputError PLMBLCommandInputError::RunValidation::InternalError
  *                     The business logic access service failed
  *               </li>
  *               <li>  @error PLMBLCommandInputError PLMBLCommandInputError::RunValidation::ExecutionError
  *                     The business logic definition execution failed
  *               </li>
  *               <li>  @error PLMBLCommandInputError PLMBLCommandInputError::RunValidation::RefusedByBL
  *                     The business logic definition refused the object
  *               </li>
  *               <li>  @error PLMBLCommandInputError PLMBLCommandInputError::RunValidation::RefusedByUser
  *                     The business logic definition requested user decision and the user refused the object
  *               </li>
  *           </ul>
  *       </li>
  *   </ul>
  */
  virtual HRESULT RunValidation(const CATString& iCmdId,
    CATListValCATIInstance_var & iListInputObjects,
    CATListValCATIInstance_var & oListValidObjects) = 0;

};

#endif
