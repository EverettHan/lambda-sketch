// COPYRIGHT Dassault Systemes 2009
#ifndef CATIOmbUniversalLinkIntrospector_H
#define CATIOmbUniversalLinkIntrospector_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

// --- Forward declaration
class PLMIOmbVirtualObjectDescriptor_var;
class CATOmbVOUpdateFlavour;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbUniversalLinkIntrospector;
#else
extern "C" const IID IID_CATIOmbUniversalLinkIntrospector ;
#endif

//------------------------------------------------------------------

/**
 * This interface allows to introspect the content of a Universal Link.
 *
 *  @href CATIOmbUniversalLink, PLMIOmbVirtualObjectDescriptor
 */
class ExportedByCATObjectModelerBase CATIOmbUniversalLinkIntrospector: public CATBaseUnknown
{
  CATDeclareInterface;

public:

    /**
     * Build a Virtual Object Descriptor from this Universal Link.
     *
     *  @param  ospVODescriptor
     *      A Virtual Object Descriptor. <br>
     *      Output parameter. <br>
     *      This parameter MUST be provided by caller as NULL_var. This method returns an error otherwise. <br>
     *      This parameter is returned to caller as NULL_var if method fails. <br>
     *      This parameter is valuated if method succeeds.
     *  @return
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetVirtualObjectDescriptor(PLMIOmbVirtualObjectDescriptor_var &ospVODescriptor) const = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(CATIOmbUniversalLinkIntrospector, CATBaseUnknown);

//------------------------------------------------------------------

#endif
