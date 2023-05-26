/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2008
#ifndef CATIPLMOperationResult_H
#define CATIPLMOperationResult_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATPLMID;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOperationResult;
#else
extern "C" const IID IID_CATIPLMOperationResult;
#endif

/**
 * This interface defines a protocol enabling to access to the result of a versioning operation performed
 * through the @href CATIPLMNewVersionEngine#RunVersioningOperation or @href CATIPLMCloningEngine#RunCloningOperation.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMOperationResult: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Gets the identifiers of the components the transaction dealt with.
 *
 * <br><b>Role</b>: Gets the @href CATPLMID enabling to identify the previous last version of the component and
 * the created new version of the component.
 *
 * @param oProvidedComponent [out]
 *   The identifier of the component the user asked to have evolved through the versioning operation.
 * @param oVersioningFamilyAncestor [out]
 *   The provided version family identifier. It can be CATPLMID_Null in cas no family is used (Cloning or Injection into new family).
 * @param oResultingComponent [out]
 *   The identifier of resulting new version of the provided component.
 * @param oVersioningFamilyAncestor [out]
 *   The provided version family identifier.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the related identifiers could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  virtual HRESULT GetResultIdentifiers( CATPLMID & oProvidedComponent, CATPLMID & oVersioningFamilyAncestor, CATPLMID & oResultingComponent )=0;
};
CATDeclareHandler(CATIPLMOperationResult, CATBaseUnknown);
#endif
