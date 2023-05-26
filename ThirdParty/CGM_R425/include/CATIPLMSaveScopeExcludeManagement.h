 /* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2016
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMSaveScopeExcludeManagement_h
#define CATIPLMSaveScopeExcludeManagement_h

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATLISTV(CATComponentId);

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSaveScopeExcludeManagement;
#else
extern "C" const IID IID_CATIPLMSaveScopeExcludeManagement ;
#endif

/**
 * Interface defining the communication protocol between a Save user and the Save engine scope definition.
 * <b>Role</b>: This protocol enables to set up exclude parameters for save scope computing.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMSaveScopeExcludeManagement : public CATBaseUnknown
{
  CATDeclareInterface;

public :

/** 
 * Define the set of components which are excluded from the save scope.
 * <br><b>Role</b>: Enables the user to define for the next save operation the set of Components which have been excluded from the Save scope.
 *
 * @param iComponentsToExclude [in]
 *   The set of Component which must be added to the exclude set.
 * <ul>
 * <li>Behavior is cumulative, the given components will be added to the existing set.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the component was successfully added into the set of components to exclude.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   </ul>
 *
 */
  virtual HRESULT AddExcludedComponents( const CATLISTV(CATComponentId) & iComponentsToExclude )=0;
};
CATDeclareHandler(CATIPLMSaveScopeExcludeManagement, CATBaseUnknown);
#endif
