/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpSpecialSaverImpl_h
#define CATAdpSpecialSaverImpl_h

#include "CATPLMIntegrationAccess.h"
#include "CATUnicodeString.h"
#include "CATOmxBaseMap.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOMap.h"
#include "CATAdpAttributeSet.h"
#include "CATOmxClassManager.h"
#include "CATOmxKernel.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATLISTV_CATPLMID.h"
#include "CATIPLMComponent.h"

class CATIAdpPLMErrorReviewer;
class CATIPLMComponent;
class CATIInstance_var;
class CATIPLMCloningEngine;
class CATListPtrCATBaseUnknown;
class CATAdpSpecialSaverData;
class CATPLMBag;

class ExportedByCATPLMIntegrationAccess CATAdpSpecialSaverImpl
{
public:
  /**
  * If iErrorReviewer is left NULL, an internal will be created. In both cases, the error reviewer
  * used in the PLMAction can be retrieved through GetErrorReviewer
  */
  CATAdpSpecialSaverImpl(CATIAdpPLMErrorReviewer * iErrorReviewer);
  ~CATAdpSpecialSaverImpl();

  /**
  * Adds an objet to save as new. During the save as new process, the new component will be initialised
  * using the Identification Initialization Business Logic with OperationId set to "Cloning". The IdCloningString
  * parameter value will be the iPrefix value.
  */
  HRESULT AddObjectToSaveAsNew(CATIPLMComponent * iComponent, const CATUnicodeString & iPrefix="");

  /**
  * Adds an objet to save as new. During the save as new process, the new component will be initialized
  * using the Identification Initialization Business Logic with OperationId set to "Cloning". The IdCloningString
  * parameter value will be the iPrefix value. After this initialization, the various attributes contained in
  * iAttrs will be applied to the new component. They may overwrite values set by the Identification Initialization
  * Business Logic
  */
  HRESULT AddObjectToSaveAsNew(CATIPLMComponent * iComponent, const CATAdpAttributeSet & iAttrs, const CATUnicodeString & iPrefix="");

  /**
  * Runs the various PLM operations necessary to save the components given through the AddObjectToSaveAsNew methods.
  * Note that for a given reference, other objects may also saved as new during the process. Those components
  * will be initialised using the Identification Initialization Business Logic with OperationId set to "Cloning".
  * The IdCloningString parameter value will be the iPrefix value associated with the reference that triggered the
  * cloning of the component.
  *
  * @returns <dl>
  *   <dt>S_OK</dt><dd>All operations has succeeded. The error reviewer will be empty.</dl>
  *   <dt>S_FALSE</dt><dd>No operation to run. The error reviewer will be empty.</dl>
  *   <dt>E_FAIL</dt><dd>At least one operation failed. The error reviewer will hold the various errors encoutered.</dl>
  */
  HRESULT RunSpecialSaveOperations();

  /**
  * Returns the associated error reviewer, even if no errors has been encountered.
  * Only PLM errors are recorded in the reviewer.
  * @param oErrorReviewer [out, CATBaseUnknown#Release]
  *
  * @returns <dl>
  *   <dt>S_OK</dt><dd>The error reviewer has been retrieved.</dl>
  *   <dt>E_FAIL</dt><dd>Internal error. The error reviewer hasn't been retrieved.</dl>
  */
  HRESULT GetErrorReviewer(CATIAdpPLMErrorReviewer *& oErrorReviewer);

private:
  /**
  * Copy constructor and equal operator are forbidden on CATAdpSpecialSaverImpl
  */
  CATAdpSpecialSaverImpl( const CATAdpSpecialSaverImpl & );
  CATAdpSpecialSaverImpl & operator =( const CATAdpSpecialSaverImpl & );

  CATIAdpPLMErrorReviewer * _errorReviewer;
  CATAdpSpecialSaverData * _objectsToSaveAsNew;

  HRESULT CheckComponentValidity(CATIPLMComponent * iComponentToCheck, CATPLMID & oPlmID);

  HRESULT RunCloneOperations();
  HRESULT RetrieveAggregatedReps();
  HRESULT EnsureAggregatedRepsAreOpened(CATPLMBag & iBag);
  HRESULT UpdateCloneScope();
  HRESULT CloneElems();

  HRESULT SaveElems();
  HRESULT ComputeSaveScope(CATListPtrCATBaseUnknown & oElemsToSave);
  void AddSaveError();
};
#endif
