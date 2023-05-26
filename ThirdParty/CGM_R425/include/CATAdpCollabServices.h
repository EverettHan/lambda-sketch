#ifndef CATAdpCollabServices_H
#define CATAdpCollabServices_H

// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATPLMIntegrationAccessRestrictedCollabUse.h"
#include "CATCollec.h"

class CATLISTP(CATIAdpPLMIdentificator);
class CATIAdpErrorMonitor;
class CATIPLMSpace;
class CATIBBStreamer;
class CATLISTP(CATIPLMComponent);
class CATIPLMCollabImporter;

class ExportedByCATPLMIntegrationAccessRestrictedCollabUse CATAdpCollabServices
{
public:
  /**
   * Constructor
   * @param *iUnknown
   *   For further use
   */
  CATAdpCollabServices() ;
  virtual ~CATAdpCollabServices() ;
   
/**
 * Exports a set of components available in a dataspace into a stream of bytes.
 * <br><b>Role:</b>Retrieve the definition of components represented in a memory dataspace and write it into a stream of bytes.
 * @param iSourceResolutionDataspace [in]
 *   The memory dataspace the components are represented in. The data defining the content of the components will therefore be introspected from this dataspace.
 * The dataspace can be obtained through the @href CATPLMSpaceServices#GetResolutionSpace entry point.
 * @param iComponents
 *   The components the user want to intropect in the dataspace and export into a stream of bytes.
 *   <ul>
 *   <li>If no component is provided, <tt>ERR_01</tt> is raised through the @href CATIAdpErrorMonitor and <tt>E_INVALIDARG</tt> is returned.</li> 
 *   </ul>
 * @param iStreamer
 *   The protocol enabling to stream data to a flow.
 * @param iErrorMonitor
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service. it can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.
* @return
 *   <ul>
 *   <li><tt>S_OK</tt>: The components were successfully exported into the stream.</li> 
 *   <li><tt>E_FAIL</tt>: A fatal error happened during the transaction. Nothing was done during the operation. The errors can be read through the provided @href CATIAdpErrorMonitor.</li>
 *   <li><tt>E_INVALIDARG</tt>: The provided @href CATIPLMSpace was invalid or the set of components provided for export is empty or invalid (the components are not found in the provided dataspace).</li>
 *   </ul>
 */
  HRESULT ExportComponents( CATIPLMSpace * iSourceResolutionSpace, const CATLISTP(CATIAdpPLMIdentificator) & iComponents, CATIBBStreamer * iStreamer, CATIAdpErrorMonitor * iErrorMonitor );

/**
 * Imports a set of components available in a stream of bytes into a memory dataspace.
 * <br><b>Role:</b>Retrieve the definition of components from a stream of bytes and imports it into a memory dataspace.
 * @param iUnstreamer
 *   The protocol enabling to extract data vehicled through the flow.
 * @param iTargetResolutionDataspace [in]
 *   The memory dataspace the components will be imported in. If NULL is given, the authoring dataspace will be automatically chosen as target resolution space.
 * The dataspace can be obtained through the @href CATPLMSpaceServices#GetResolutionSpace entry point.
 * @param iErrorMonitor
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service. it can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.
 * @param oComponents [out, CATCATBaseUnknown#Release]
 *   The components imported in the dataspace.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: The components were successfully imported into the provided dataspace.</li> 
 *   <li><tt>E_FAIL</tt>: A fatal error happened during the transaction. Nothing was done during the operation. The errors can be read through the provided @href CATIAdpErrorMonitor.</li>
 *   <li><tt>E_INVALIDARG</tt>: The provided @href CATIPLMSpace was invalid or the stream is invalid.</li>
 *   </ul>
 */
  HRESULT ImportComponents( CATIBBStreamer * iUnstreamer, CATIPLMSpace * iTargetResolutionSpace, CATLISTP(CATIPLMComponent) & oComponents, CATIAdpErrorMonitor * iErrorMonitor );

private:
  CATIPLMCollabImporter * _pImporter;
};

#endif
