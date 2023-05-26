#ifndef _CATIGraphicsOptimizer_H
#define _CATIGraphicsOptimizer_H

//COPYRIGHT DASSAULT SYSTEMES 2012

#include "CATVisItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIGraphicsOptimizer;
#else
extern "C" const IID IID_CATIGraphicsOptimizer;
#endif

/**
 * Interface to manage communication with the Graphics Optimizer component.
 * <strong>Role</strong>: The interface allows checking the current graphics hardware configuration to determine if the Graphics Optimizer has to be executed anew.
 *
 * @example
 * <pre>
 *  // Sample code showing how to communicate with the Graphics Optimizer component.
 * 
 *  CATIGraphicsOptimizer* pIGraphicsOptimizer = NULL;
 *  if (SUCCEEDED(CATInstantiateComponent("GraphicsOptimizer", IID_CATIGraphicsOptimizer, (void**)&pIGraphicsOptimizer)) && pIGraphicsOptimizer)
 *  {
 *    // Check if hardware graphics configuration has changed
 *    CATBoolean bLaunchGraphicsOptimizer = CATFalse;
 *    if (FAILED(pIGraphicsOptimizer->HasGraphicsConfigurationChanged(bLaunchGraphicsOptimizer)))
 *    {
 *      bLaunchGraphicsOptimizer = CATTrue;
 *    }
 *
 *    // Launch Graphics Optimizer anew
 *    if (bLaunchGraphicsOptimizer)
 *    {
 *      int OptimizerExitStatus = 0;
 *      HRESULT ReturnCode = pIGraphicsOptimizer->LaunchGraphicsOptimizer("MyGraphicsOptimizer", CATFalse, OptimizerExitStatus);
 *
 *      // Handle here ReturnCode and OptimizerExitStatus
 *      // ...
 *    }
 *
 *    pIGraphicsOptimizer->Release();
 *    pIGraphicsOptimizer = NULL;
 *  }
 * </pre>
 *
 */
class ExportedByCATVisItf CATIGraphicsOptimizer : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:

  /**
   * Call this method to check if any change occurred in the Graphics Optimizer configuration.
   * The current hardware graphics configuration (graphics card name, driver and package) is compared to the last one used by the Graphics Optimizer to perform its tests.
   * If any information has changed, it means that the Graphics Optimizer has to be executed anew. 
   *
   * @param [out] obChanged
   *   The created @href IVisREPresentation instance.
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>The current hardware graphics configuration has been successfully retrieved and compared with the previous one</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>If any error occurred in the graphics configuration retrieval or comparison processes. In that case, it is recommended to execute the Graphics Optimizer anew.</dd>
   *   </dl>
   */
  virtual HRESULT HasGraphicsConfigurationChanged(CATBoolean& obChanged) = 0;

  /**
   * Call this method to execute the Graphics Optimizer.
   *
   * @param [in] ipOptimizerName
   *   The name of the Graphics Optimizer application to execute, without the .exe file extension.
   * @param [in] ibAdminMode
   *   Determines if the Graphics Optimizer application has to be executed in administration mode (CATTrue) or not.
   * @param [out] oExitStatus
   *   The return code of the Graphics Optimizer application execution.
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>If the specified Graphics Optimizer application has been successfully launched.</dd>
   *     <dt>E_INVALIDARG</dt>
   *     <dd>If the specified Graphics Optimizer application name is incorrect or if it has not been found.</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>If any error occurred in the Graphics Optimizer launching process.</dd>
   *   </dl>
   */
  virtual HRESULT LaunchGraphicsOptimizer(const char* ipOptimizerName, const CATBoolean ibAdminMode, int& oExitStatus) = 0;
};

#endif // _CATIGraphicsOptimizer_H
