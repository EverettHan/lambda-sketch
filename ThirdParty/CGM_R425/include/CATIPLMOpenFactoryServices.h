/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2004
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMOpenFactoryServices_H
#define CATIPLMOpenFactoryServices_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATIPLMIntegRecordRead;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOpenFactoryServices;
#else
extern "C" const IID IID_CATIPLMOpenFactoryServices;
#endif

/**
 * An argument of this type is passed in to the specialization open factory when called for open
 * It exposes services dedicated to the management of specialization extensions.
 * It is dedicated to be implemented by the elementary factory.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMOpenFactoryServices: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
 * Asks the elementary factory to construct and initialize the basic type.
 * After that construction, the specialization factory will specialize the basic type either
 * with a specific protocol in accordance with between the basic type and the specialization,
 * or by adding to that basic type a feature extension.
 *
 * It should be noticed that this function should not declare the created object in TOS. This will be done
 * later by the elementary factory (@see CATPLMIntegrationInterfaces.CATIPLMOpenFactory).
 *
 * @param <tt>CATIPLMIntegRecordRead * ipRecord</tt>
 * [in] The record describing the complete PLM element.
 * @param <tt>CATBaseUnknown ** opBasic</tt>
 * [out] The contructed object for the basic type.
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Success
 * <dt> <tt>E_FAIL</tt>   <dd> Failure
 * </dl>
 */
  virtual HRESULT CreateBasicType( CATIPLMIntegRecordRead * ipRecord, CATBaseUnknown *& opBasic ) = 0;

/**
 * Asks the elementary factory to initialize with basic type information an already created specialization object.
 * It should be used when the specialization is implemented by a feature derivation of the basic type.
 * The specialization factory constructs the derivated object and then asks the basic factory to
 * initialize it with basic type information.
 *
 * @param <tt>CATIPLMIntegRecordRead * ipRecord</tt>
 * [in] The record describing the complete PLM element.
 * @param <tt>CATBaseUnknown * ipSpecialized</tt>
 * [out] The constructed specialized object to be initialized with basic type information.
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Success
 * <dt> <tt>E_FAIL</tt>   <dd> Failure
 * </dl>
 */
  virtual HRESULT InitializeBasicType(CATIPLMIntegRecordRead * ipRecord,CATBaseUnknown * ipSpecialized) = 0;
};
CATDeclareHandler( CATIPLMOpenFactoryServices, CATBaseUnknown );
#endif
