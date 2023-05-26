/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATPLMSaveFactoryAdaptor.h
// Header definition of CATPLMSaveFactoryAdaptor
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2004  Creation: Code generated by the CAA wizard  son
//===================================================================
/**
* @level Protected
* @usage U2
*/
#ifndef CATPLMSaveFactoryAdaptor_H
#define CATPLMSaveFactoryAdaptor_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMSaveFactory.h"
#include "CATIPLMSaveFactoryServices.h"


//-----------------------------------------------------------------------


/**
 * This class is the adaptor corresponding to the  CATIPLMSaveFactory interface.
 * <br>This adaptor is supplied only for a better flexibility of CATIPLMSaveFactory; CATPLMSaveFactoryAdaptor:'s methods are not really implemented.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMSaveFactoryAdaptor: public CATIPLMSaveFactory
{
  public:

    // Standard constructors and destructors
    // -------------------------------------
    CATPLMSaveFactoryAdaptor ();
    virtual ~CATPLMSaveFactoryAdaptor ();

    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMSaveFactory#WriteMetadata
    */
    virtual HRESULT WriteMetadata( CATIPLMLogState * iLogObject, 
      CATIPLMIntegRecordWrite* iRecordWrite, 
      CATIPLMSpecializationSaver * ipSpecSaver, 
      const CATUuid & iTransId ,
      CATIPLMEngineErrorReporter * iopiErrorReporter) ;

    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMSaveFactory#ExploitReturnMsg
    */
    virtual HRESULT ExploitReturnMsg(CATIPLMIntegRecordRead * iRecRead,
      CATIPLMSpecializationSaver * ipSpecSaver, 
      const CATUuid & iTransId ,
      CATIPLMEngineErrorReporter * iopiErrorReporter);

    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMSaveFactory#EndSaveTransaction
    */
    virtual HRESULT EndSaveTransaction( const CATUuid & iTransId , CATBoolean iSuccess, CATIPLMEngineErrorReporter * iopiErrorReporter)  ;

    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMSaveFactory#EndLocalSaveTransaction
    */

     virtual HRESULT EndLocalSaveTransaction( const CATUuid & iTransId , EndSaveStatus iSaveStatus, CATIPLMEngineErrorReporter * iopiErrorReporter);


    /**
    * @see CATPLMIntegrationInterfaces.CATIPLMSaveFactory#TryInterpretation
    */
    virtual HRESULT TryInterpretation(CATIPLMError * iPLMErrorToInterpret,
                                      CATIPLMEngineErrorReporter * iopiErrorReporter) ;

};

//-----------------------------------------------------------------------

#endif