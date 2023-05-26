/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2004
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMOpenEngineMediator_H
#define CATIPLMOpenEngineMediator_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATPLMTypeId;
class CATIPLMIntegRecordRead;
class CATIPLMOpenFactoryServices;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOpenEngineMediator;
#else
extern "C" const IID IID_CATIPLMOpenEngineMediator ;
#endif

/**
 * Communication protocol between the factories and the open engine.
 * Defines a set of methods that are used by the factories to access to dedicated factories:
 *   - Bulk factories can access to elementary factories.
 *   - Elementary factories can access to extension data available on the object.
 *   - Elementary factories can access to specialization factories.
 *   - Elementary factories can access to auxiliary factories.
 * This protocol can only be seen by the @href CATPLMIntegrationInterfaces.CATIPLMOpenFactory and
 * @href CATPLMIntegrationInterfaces.CATIPLMOpenBulkFactory behaviors implementations.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMOpenEngineMediator: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
 * Primary and mission critical entry point of the communication protocol. None of the other methods
 * can work if the OpenSingle method was not previously called.
 * Once a bulk factory has sequenced the calls to the elementary factories, it can trigger those on 
 * objects by calling OpenSingle. The open single mediator will match the PLM type of the element 
 * with a factory implementing the @href CATPLMIntegrationInterfaces.CATIPLMOpenFactory behavior.
 *
 * @param <tt>CATIPLMIntegRecordRead * ipRecord</tt>
 * [in] The description of the element to open.
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Similar to @href CATIPLMOpenFactory#Open.
 * <dt> <tt>S_FALSE</tt>  <dd> Similar to @href CATIPLMOpenFactory#Open.
 * <dt> <tt>E_FAIL</tt>   <dd> Similar to @href CATIPLMOpenFactory#Open.
 * </dl>
 */
  virtual HRESULT OpenSingle( CATIPLMIntegRecordRead * ipRecord ) = 0;
  
/**
 * Restricted access: @see CATIPLMOpenEngineMediator#OpenSingle.
 * Finds the specialization type described in the record currently treated through the OpenSingle entry point.
 *
 * @param <tt>CATPLMTypeId & oSpecializationType</tt>
 * [out] The PLM type of the specialization.
 *
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Success, a specialization is returned
 * <dt> <tt>S_FALSE</tt>  <dd> No specialization associated to the basic type
 * <dt> <tt>E_FAIL</tt>   <dd> Failure
 * </dl>
 */
  virtual HRESULT GetSpecializationType( CATPLMTypeId & oSpecializationType ) = 0;

/**
 * Restricted access: @see CATIPLMOpenEngineMediator#OpenSingle.
 * Enables the elementary factory to ask for the specialization factory to take the control of the operation.
 * The mediator will match the provided PLM type with a dedicated factory implementing the
 * @href CATPLMIntegrationInterfaces.CATIPLMSpecializationOpenFactory behavior.
 *
 * Warning: The specialization factory creates the specialized object, does not registers it in the TOS and 
 *          returns it to the elementary factory, that is assessed to do the registration job.
 *
 * @param iSpecializationType [in]
 *   The PLM type of the specialization
 * @param ipBaseServices [in]
 *   Factory services provided by the elementary factory to the extension factories.
 * @param oCreatedObject [out, CATBaseUnknown#Release]
 *   The created component.
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Success
 * <dt> <tt>E_FAIL</tt>   <dd> Failure
 * </dl>
 */
  virtual HRESULT OpenSpecialization( const CATPLMTypeId & iSpecializationType,
                                      CATIPLMOpenFactoryServices * ipBaseServices, CATBaseUnknown *& oCreatedObject ) = 0;

/**
 * Restricted access: @see CATIPLMOpenEngineMediator#OpenSingle.
 * Finds number of auxiliary types described in the record currently treated through the OpenSingle entry point.
 *
 * @param <tt>int & oNbAuxiliaryTypes</tt>
 * [out] The number of auxiliary types described in the record [0..n].
 *
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Success (even if the number of auxiliary extensions is 0)
 * <dt> <tt>E_FAIL</tt>   <dd> Failure
 * </dl>
 */
  virtual HRESULT AuxiliaryCount( int & oNbAuxiliaryTypes ) = 0;

/**
 * Restricted access: @see CATIPLMOpenEngineMediator#OpenSingle.
 * Finds the auxiliary PLM type at the iIndex position in the record.
 *
 * @param <tt>int iIndex</tt>
 * [in] Index of the asked auxiliary extension PLM type [1..n].
 * @param <tt>CATPLMTypeId & oAuxiliaryType</tt>
 * [out] The PLM type of the auxiliary extension.
 *
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Success, a specialization is returned
 * <dt> <tt>E_FAIL</tt>   <dd> Failure
 * </dl>
 */
  virtual HRESULT GetAuxiliaryType( int iIndex, CATPLMTypeId & oAuxiliaryType ) = 0;

/**
 * Restricted access: @see CATIPLMOpenEngineMediator#OpenSingle.
 * Enables the elementary factory to ask for the auxiliary factory to create the auxiliary extension and 
 * match it with the basic element.
 * The mediator will match the provided PLM type with a dedicated factory implementing the
 * @href CATPLMIntegrationInterfaces.CATIPLMAuxiliaryOpenFactory behavior.
 *
 * @param <tt>CATBaseUnknown * iObjectToExtand</tt>
 * [in] The base object that needs to be extended.
 * @param <tt>const CATPLMTypeId & iAuxiliaryType</tt>
 * [in] The PLM type of the auxiliary extension to be added.
 *
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Success
 * <dt> <tt>E_FAIL</tt>   <dd> Failure
 * </dl>
 */
  virtual HRESULT OpenAuxiliary( CATBaseUnknown * iObjectToExtand, const CATPLMTypeId & AuxiliaryType) = 0;

/**
 * Restricted access: @see CATIPLMOpenEngineMediator#OpenSingle.
 * Enables to the factories to provide to the switch engine a component that will have to be called back 
 * later for streaming management by the switch engine.
 *
 * <br><b>Role</b>: Adds the provided component to the switch engine.
 *
 * @param CATBaseUnknown * iObject [in]
 *   The provided component.

 * @return
 * 
 * <dt> <code>HRESULT</code>     <dd> @see CATIOmiSwitchEngine#AddObjectToTreat
 *
 */
  virtual HRESULT AddToSwitchEngine( CATBaseUnknown * iObject ) = 0;
};
CATDeclareHandler( CATIPLMOpenEngineMediator, CATBaseUnknown );
#endif
