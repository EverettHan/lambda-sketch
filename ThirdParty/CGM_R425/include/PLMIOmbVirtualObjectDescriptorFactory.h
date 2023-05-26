// COPYRIGHT Dassault Systemes 2009
#ifndef PLMIOmbVirtualObjectDescriptorFactory_H
#define PLMIOmbVirtualObjectDescriptorFactory_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

// --- Forward declaration
class PLMIOmbVirtualObjectDescriptor_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_PLMIOmbVirtualObjectDescriptorFactory;
#else
extern "C" const IID IID_PLMIOmbVirtualObjectDescriptorFactory;
#endif

/**
 * obsolete
 */
#define VirtualObjectDescriptorFactory "PLMOmbVirtualObjectDescriptorFactory"

//------------------------------------------------------------------

/**
 * obsolete
 * @href PLMIOmbVirtualObjectDescriptor
 */
class ExportedByCATObjectModelerBase PLMIOmbVirtualObjectDescriptorFactory : public CATBaseUnknown
{
  CATDeclareInterface;
public:
    /**
     * obsolete
     * use PLMIOmbVirtualObjectDescriptor::CreateEmptyDescriptor
     */
  virtual HRESULT CreateEmptyDescriptor(PLMIOmbVirtualObjectDescriptor_var &ospVODescriptor) = 0;

  /**
  * obsolete
  * use PLMIOmbVirtualObjectDescriptor::CreateDescriptorFromConcreteOrVirtualObject
  */
  virtual HRESULT CreateDescriptorFromConcreteOrVirtualObject(const CATBaseUnknown *ipConcreteOrVirtualObject, PLMIOmbVirtualObjectDescriptor_var &ospVODescriptor) = 0;
};

CATDeclareHandler(PLMIOmbVirtualObjectDescriptorFactory, CATBaseUnknown);

//------------------------------------------------------------------

#endif
