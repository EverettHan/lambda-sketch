/* -*-c++-*- */
/**
* @level Protected
* @usage U4 CATOmbSerializationStrategyAdapter
*/
//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// CATIOmbSerializationStrategy .h
// Define the CATIOmbSerializationStrategy  interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
#ifndef CATIOmbSerializationStrategy_H
#define CATIOmbSerializationStrategy_H

#include "CATOmbSelectiveLoading.h"
#include "CATBaseUnknown.h"

#include "CATOmbStreamDescriptorDefinitionKey.h"
#include "CATListPtrCATOmbStreamDescriptorDefinitionKey.h"
#include "CATOmbImportExportParameters.h"
#include "CATOmxArray.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbSelectiveLoading IID IID_CATIOmbSerializationStrategy;
#else
extern "C" const IID IID_CATIOmbSerializationStrategy;
#endif

//------------------------------------------------------------------

namespace SerializeStream
{
  /**
  * Describes the way the stream serialization is to be handled by OMB infrastructure
  * @param Standard
  *   Ask for stream serialization from its specification inputs: a new occurence of the stream is computed. Default behavior
  * @param KeepPrevious
  *   Ask for keeping the previous serialization of the stream: current occurence of the stream remains the previous one, no new serialization.
  */
  enum Strategy { Standard = 1, KeepPrevious };
}


/**
* Interface to specify a serialization strategy according to the current stream generation inputs
* b>Role:</b> Enables to select among several serialization options: keep previous stream, (re)serialize stream...etc
*             depending on applicative contextual information.
*
* This interface is designed to be:
*  -invoked by ObjectModelerBase at Stream generation time.
*  -implemented only by specific applications acknowledged by OMB as relevant to streaming strategies switch.
*
* It is to be used by authorized applications the following way:
*
*  -Create an implementation class/source file for this interface.
*  -C++ Derivate this implementation class from the interface Adapter CATOmbSerializationStrategyAdapter
*  -Let OMB create an instance of this interface and call the implemented method(s), at Save time, during StreamDescriptor serialization job, just before copying this stream to session cache
*
* --------------------------------------------------------------------------
*  code sample: into ApplicativeImplementation.h
* --------------------------------------------------------------------------
* #include "CATIOmbSerializationStrategyAdapter.h"
*
* class ApplicativeImplementation : public CATIOmbSerializationStrategyAdapter
* {
* public:
*
* 	CATDeclareClass;
*
* 	ApplicativeImplementation();
* 	virtual ~ApplicativeImplementation();
*
*   HRESULT GetSerializationStrategy(CATBaseUnknown& iComponent, const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iLateType, CATOmbImportExportParameters* iParameters, SerializeStream::Strategy& oStrategy);
* };
*
* --------------------------------------------------------------------------
*  code sample: into ApplicativeImplementation.cpp
* --------------------------------------------------------------------------
* #include "CATIOmbSerializationStrategy .h"
* #include "CATOmbLoadableDataUniqueKey.h"
* #include "CATOmbImportExportParameters.h"
*
* // Tie the implementation to its interface
* CATImplementClass(ApplicativeImplementation, Implementation, CATIOmbSerializationStrategy , CATNull);
* CATImplementBOA(CATIOmbSerializationStrategy , ApplicativeImplementation);
* CATCreateAndAddOMFactoryFunction(ApplicativeImplementation)
*  HRESULT ApplicativeImplementation::GetSerializationStrategy(CATBaseUnknown& iComponent, const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iLateType, CATOmbImportExportParameters* iParameters, SerializeStream::Strategy& oStrategy)
* {....}
*
* For to new CATIOmbSerializationStrategy implementators:
* --------------------------------------------------------------------------
*  code sample: into some DeclarationFile.func
*  (OMFactoryFunctionType is an invariant key word)
* --------------------------------------------------------------------------
*   ApplicativeImplementation      OMFactoryFunctionType           libACATApplicativeLib
*
* --------------------------------------------------------------------------
*  code sample: into another DeclarationFile.xDefinition
* --------------------------------------------------------------------------
*   Selector[ApplicativeImplementation]  From[PLMComponentBaseType, SomeLateType]  Interface[CATIOmbSerializationStrategy]
*-------------------------------------------------------------------------
*/

class ExportedByCATOmbSelectiveLoading CATIOmbSerializationStrategy : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Declare the serialization strategy to be applied for current secondary synchronous stream descriptor depending on the current saving context
  * A synchronous secondary stream descriptor is asked to be (re)streamed during Save operations if the stream descriptor it is synchronous with needs to be streamed.
  *
  * @param iComponent [in]
  *    The component which Authoring (explicitely)/Secondary synchronous (implicitely) streams are to be (re) streamed
  * @param iKey [in]
  *   The key handling the synchronous StreamDescriptor which serialization strategy is asked to application
  *   No ask and Standard strategy applied if not an (format:AuthoringVisu, Role:""/Extended/Alternative/CATIAV5INV6) or (format:Authoring, Role:WebFormat) stream descriptor
  * @param ilateType [in]
  *   the late type of the document handling the stream behaviours in session
  * @param iPersisType [in]
  *   the persistency type (=extension) of the streamed document
  *   (empty string for CATIA documents)
  * @param iParameters [in]
  *    Eventual applicative parameters needed to discriminate the streaming strategy to be applied.
  *    For each parameter, specify its name and value using CATOmbImportExportParameters API.
  *    System internal parameter names CATOmbRole, EXPORT_STATUS are not allowed.
  *    All Parameters are optional and defined by application when calling Request*SecondaryFormatGeneration methods.
  * @param oStrategy [out]
  *   serialization strategy returned by application, depending on its own criteria towards current Authoring data modification
  *
  * @return
  *        S_OK   : Successfully ended
  *        E_FAIL : A software error occured
  */
  virtual HRESULT GetSerializationStrategy(CATBaseUnknown& iComponent, const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iLateType, const CATUnicodeString& iPersisType, CATOmbImportExportParameters* iParameters, SerializeStream::Strategy& oStrategy) = 0;

};

//------------------------------------------------------------------
CATDeclareHandler(CATIOmbSerializationStrategy, CATBaseUnknown);

#endif
