// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PLMIRepresentationsLoadModeServices.h
// Define the PLMIRepresentationsLoadModeServices interface
//
//===================================================================
#ifndef PLMIRepresentationsLoadModeServices_H
#define PLMIRepresentationsLoadModeServices_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "PLMRepLoadMode.h"
#include "CATPLMModelerRepInterfaces.h"
#include "CATListValCATPLMOccurrenceWrapper.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerRepInterfaces IID IID_PLMIRepresentationsLoadModeServices;
#else
extern "C" const IID IID_PLMIRepresentationsLoadModeServices ;
#endif


//------------------------------------------------------------------

/**
 * Interface providing services related to representations loading mode
 *
 * @example
 *  PLMIRepresentationsLoadModeServices* pLoadModeServices = NULL;
 *  if (SUCCEEDED(::CATGetPLMLoadModeServices(pLoadModeServices)) && pLoadModeServices)
 *  {
 *    ...
 *  }
 *  CATSysReleasePtr(pLoadModeServices);
 */
class ExportedByCATPLMModelerRepInterfaces PLMIRepresentationsLoadModeServices: public CATBaseUnknown
{
  CATDeclareInterface;

public:

	   /**
     * Changes the loading mode of a list of Representation Reference. <br>
     * According to the Representation kind, the change of mode can succeed but the Representation
     * can be in a different loading mode than the desired one. In this case, the loading mode can be retrieved
     * with the @href #ComputeLoadingMode method.<br>
     *
     * @param  iNewMode
     *      The new loading mode to be changed to. <br>
     *      Input parameter.
		 * @param		iRepresentationsList
		 *			List of components to be switched. <br>
		 *			This list should only contain PLM Representations or Occurrence Representations. Other components are ignored.
     * @return 
     *      <code>S_OK</code> if the loading mode of given components has been successfully changed. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT ChangeLoadingMode(const CATLISTV(CATBaseUnknown_var)& iRepresentationsList, PLMRepLoadMode iNewMode) = 0;
   

	   /**
     * Changes the loading modeof a list of Representation Occurrence. <br>
     * According to the Representation kind, the change of mode can succeed but the Representation
     * can be in a different loading mode than the desired one. In this case, the loading mode can be retrieved
     * with the @href #ComputeLoadingMode method.<br>
     *
     * @param  iNewMode
     *      The new loading mode to be changed to. <br>
     *      Input parameter.
		 * @param		iRepOccurrenceList
		 *			List of components to be switched. <br>
		 *			This list should only contain PLM Representations or Occurrence Representations. Other components are ignored.
     * @return 
     *      <code>S_OK</code> if the loading mode of given components has been successfully changed. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT ChangeLoadingMode(const CATLISTV(CATPLMOccurrenceWrapper)& iRepOccurrenceList, PLMRepLoadMode iNewMode) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(PLMIRepresentationsLoadModeServices, CATBaseUnknown);

//------------------------------------------------------------------

#endif
