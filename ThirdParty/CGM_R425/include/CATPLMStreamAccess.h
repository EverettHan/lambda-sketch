#ifndef _CATPLMStreamAccess_H
#define _CATPLMStreamAccess_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------


#define AuthorizedModuleForExport 887

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForExport  
#error Module declared as authorized by another header  
// Fatal error on solaris
@error 
#endif    

#define CATPLMTos                         AuthorizedModuleForExport
#define CATPLMExternals                   AuthorizedModuleForExport
#define CATPLMClientCoreLinkTrader        AuthorizedModuleForExport
#define CATPLMCollabMgt                   AuthorizedModuleForExport
#define CATPLMIntegration                 AuthorizedModuleForExport
#define CATOmbLinkTrader                  AuthorizedModuleForExport
#define CATOmbTransientServices           AuthorizedModuleForExport
#define CATPLMIdentification_PLM          AuthorizedModuleForExport
#define CATPLMTosManager                  AuthorizedModuleForExport
// ODT
#define SelectiveLoadingTST_SimulateCollab AuthorizedModuleForExport

#if _MK_MODNAME_ == AuthorizedModuleForExport

#else

#error Forbidden Access To CATPLMStreamAccess Services from a non-OMB module
// Fatal error on solaris
@error 
#endif
#undef CATPLMTos
#undef CATPLMExternals
#undef CATPLMClientCoreLinkTrader
#undef CATPLMCollabMgt
#undef CATPLMIntegration
#undef CATOmbLinkTrader
#undef CATOmbTransientServices
#undef CATPLMIdentification_PLM
#undef CATPLMTosManager
// ODT
#undef SelectiveLoadingTST_SimulateCollab

#if _MK_MODNAME_ == AuthorizedModuleForExport
#error Declared Module has not been undeclared correctly
// Fatal error on solaris
@error 
#endif 
// ----------------------------------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"
#include "CATComponentId.h"
#include "CATITosIterator.h"

class CATPLMStreamingContext;
class CATPLMStreamingResult;
class CATVVSURLConnection;
class CATITosStreamDescriptorStreamAccess_var;

/**
* Access to PLM attributes
*/
class ExportedByCATPLMTos CATPLMStreamAccess
{
public:

  /**
  * ctor
  */
  inline CATPLMStreamAccess(const CATComponentId & iCID):_CID(iCID) {}

  /**
  * Get iterator providing access to stream descriptors
  *
  * Interfaces implemented by stream descriptors :
  *   CATITosStreamDescriptor (basic view)
  *   CATITosStreamDescriptorStreamAccess (specific access for persistency management)
  *
  * @return 
  *     The iterator
  */
  CATITosIterator_var GetIterator();

  /**
  * Asks for a component to stream into a cache its binary view.
  * <br><b>Role:</b>This method enables to stream the data of a component into the cache for a late send to
  * a specific repository.
  * @param iContext [in]
  *   The context the streams must be created for.
  * @param oResult [out]
  *   The result of the streaming operation.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: The stream were succesfully generated.</li> 
  *   <li><tt>S_FALSE</tt>: The component has no streams to generate.</li>
  *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
  *   </ul>
  */
  HRESULT StreamInCache( const CATPLMStreamingContext & iContext, CATPLMStreamingResult & oResult );

  /**
  * Asks for a component to unstream from a cache its binary view.
  * <br><b>Role:</b>This method enables to unstream the data of a component from the cache
  * @param ihStreamDesc [in]
  * @param iConnection [in]
  *   The context the streams must be created for.
  * @param oResult [out]
  *   The result of the streaming operation.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: if succeeded.</li> 
  *   <li><tt>E_FAIL</tt>: if failure.</li>
  *   </ul>
  */
  HRESULT UnstreamFromCache( const CATITosStreamDescriptorStreamAccess_var & ihStreamDesc, CATVVSURLConnection * iConnection);

private:
  const CATComponentId _CID;

  CATPLMStreamAccess (CATPLMStreamAccess&);
  CATPLMStreamAccess& operator=(CATPLMStreamAccess&);
};

#endif
