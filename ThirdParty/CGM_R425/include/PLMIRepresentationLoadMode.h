// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// PLMIRepresentationLoadMode.h
// Define the PLMIRepresentationLoadMode interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jan 2008  Creation: Code generated by the CAA wizard  LVT
//===================================================================
#ifndef PLMIRepresentationLoadMode_H
#define PLMIRepresentationLoadMode_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMModelerRepInterfaces.h"
#include "PLMRepLoadMode.h"

// --- System framework
#include "CATBaseUnknown.h"

// --- Forward declaration

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerRepInterfaces IID IID_PLMIRepresentationLoadMode;
#else
extern "C" const IID IID_PLMIRepresentationLoadMode ;
#endif

//------------------------------------------------------------------

/**
 * Interface to compute and change the loading mode of a Representation Reference.
 *
 * <br><b>Role</b>: This interface enables you to use the Selective Loading mechanism on the Representation Reference object.<br>
 * The loading mode of a Representation Reference corresponds to the Stream Descriptor type attached to the Representation Reference.
 */
class ExportedByCATPLMModelerRepInterfaces PLMIRepresentationLoadMode: public CATBaseUnknown
{
  CATDeclareInterface;

public:

    /**
     * Computes the loading mode.
     *
     * @param  oLoadMode
     *      The loading mode of the Representation Reference. <br>
     *      Output parameter.
     * @return 
     *      <code>S_OK</code> if the loading mode of the Representation Reference has been successfully computed. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT ComputeLoadingMode (PLMRepLoadMode & oLoadMode) = 0;
	
    /**
     * Changes the loading mode. <br>
     * According to the Representation kind, the change of mode can succeed but the Representation
     * can be in a different loading mode than the desired one. In this case, the loading mode can be retrieved
     * with the @href #ComputeLoadingMode method.<br>
     *
     * @param  iNewMode
     *      The new loading mode to be changed to. <br>
     *      Input parameter.
     * @return 
     *      <code>S_OK</code> if the loading mode of the Representation Reference has been successfully changed. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT ChangeLoadingMode (PLMRepLoadMode iNewMode) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(PLMIRepresentationLoadMode, CATBaseUnknown);

//------------------------------------------------------------------

#endif
