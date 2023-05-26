/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2003
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMSaveFactoryServices_H
#define CATIPLMSaveFactoryServices_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"


class CATComponentId;
class CATIPLMIntegRecordWrite;
class CATIPLMLogState;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSaveFactoryServices;
#else
extern "C" const IID IID_CATIPLMSaveFactoryServices;
#endif

/**
 * An argument of this type is passed in to the specialization save factory when called for Save
 * It offers them services provided by the factory of the basic type.
 * Specific basic type factory may offer (and document) additional set of service in the form of
 * another interface that can be queried for from this one
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMSaveFactoryServices: public CATBaseUnknown
{
  CATDeclareInterface;

public:


/**
 * Asks the factory of the basic type to save the basic type.
 * <p>Used by specialization factories when specialization is performed either by a feature derivation of the basic type.
 * or by a feature extension added to the feature of the basic type
 *
 *   @param iLogObject  The object to save as described in the LOG
 *   @param ipRecordWrite  Protocol for recording update information in the save MSG
 *
 *   @return  S_OK:   Success
 *   @return E_FAIL: Failure
 * 
 */

  virtual HRESULT SaveBasicTypetoPDM(const CATIPLMLogState * iLogObject,
                                     CATIPLMIntegRecordWrite* iRecordWrite) = 0 ; 
};

CATDeclareHandler( CATIPLMSaveFactoryServices, CATBaseUnknown );

#endif
