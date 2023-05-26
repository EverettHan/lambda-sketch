// COPYRIGHT Dassault Systemes 2005
//===================================================================
//  Oct 2005  Creation: Code generated by the CAA wizard  bes
//===================================================================
#ifndef CATOmbSdsInitialisationServices_H
#define CATOmbSdsInitialisationServices_H

/**
* @level  Protected
* @usage   U1
*/

#include "CATPLMStreamDescriptorForAll.h"
#include "CATOmbSessionService.h"

#include "CATOmbSelectiveLoading.h"
#include "CATVVSUrl.h"

class CATBaseUnknown;
class CATIPLMIntegRecordRead;
class CATUnicodeString;
class CATIPLMEngineErrorReporter;
class CATOmyCioUrlUsageCtx;

class CATOmbSessionContext;

/**
* Class providing services for Selective Loading on Representation Reference objects.
*/
class ExportedByCATPLMStreamDescriptor CATOmbSdsInitialisationServices : public CATOmbSessionService
{
public:

  /**
  * Constructor
  */
  CATOmbSdsInitialisationServices(CATOmbSessionContext *ipSessionContext = NULL) : CATOmbSessionService(ipSessionContext) {};

  /**
  * Destructor
  */
  virtual ~CATOmbSdsInitialisationServices() {};

  /** 
  * This method inits a RepRef for selective loading with the data retrieved at the open step. 
  *
  * <b>Role</b>
  * This method creates and inits the ObjecModelerBase data structure using the information retrieved in the PLM Message exchanged with the 
  * Database. 
  * 
  *
  * @param ioComp [inout]
  *   The RepRef for which the selective loading will be set up. 
  * @param iRecord [in]
  *   The record built from the open query on the Enovia Database. 
  * @param iopiErrorReporter [inout]
  *   The error reporter that will be filled in case of error. 
  *
  * @return
  *   <code>S_OK</code>     the Selective loading data structure has been created with success
  *   <code>E_FAIL</code>   unexpected error. 
  *
  */
  HRESULT InitComponentForOpenFactory(CATBaseUnknown& ioComp, CATIPLMIntegRecordRead& iRecord, CATIPLMEngineErrorReporter * ioErrorReporter = NULL);

  /** 
  * This method inits a created RepRef with the necessary data for selective loading. 
  *
  * <b>Role</b>
  * This method creates and inits the ObjecModelerBase data structure in a default mode. 
  * Only one authoring SD of the given latetype is created. 
  *
  *
  * @param ioComp [inout]
  *   The RepRef for which the selective loading will be set up. 
  * @param iAuthoringType [in]
  *   Late type of the authoring Stream Descriptor that will be added to the RepRef. 
  * @param iContentUrl [in]
  *   This parameter is used only for Non CATIA StreamDescriptor. It provides an access to the stream. 
  *
  * @return
  *   <code>S_OK</code>     the Selective loading data structure has been created with success
  *   <code>E_FAIL</code>   unexpected error. 
  *
  */
  HRESULT InitComponentForCreationFactory(CATBaseUnknown& ioComp, const CATUnicodeString& iAuthoringType, const CATVVSUrl &iContentUrl = CATVVSUrl());
 
  HRESULT InitComponentForCreationFactory(CATBaseUnknown& ioComp, const CATUnicodeString& iAuthoringType, const CATOmyCioUrlUsageCtx* iCtx);
  /** 
  * This method inits a created Technological RepRef with the necessary data for selective loading. 
  *
  * <b>Role</b>
  * This method creates and inits the ObjecModelerBase data structure in a default mode. 
  * Only one authoring SD is created. 
  *
  *
  * @param ioComp [inout]
  *   The Technological RepRef for which the selective loading will be set up. 
  * 
  * @return
  *   <code>S_OK</code>     the Selective loading data structure has been created with success
  *   <code>E_FAIL</code>   unexpected error. 
  *
  */
  HRESULT InitTechnoComponentForCreationFactory(CATBaseUnknown& ioComp);

};


#endif
