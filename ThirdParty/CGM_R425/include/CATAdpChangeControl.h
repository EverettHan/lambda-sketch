#ifndef CATAdpChangeControl_H
#define CATAdpChangeControl_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATPLMIntegrationAccess.h"
#include "CATCollec.h"

//#include "CATPLMID.h"
class CATLISTV(CATPLMID);
class CATIAdpErrorMonitor;

static const char * g_ErrorCatalog = "CATAdpSessionErrors";
static const char * g_RefError = "NotARefNorRepRef";
static const char * g_SessionError = "InSession";

/**
* @deprecated V6R419, see with configuration teams
*/
class ExportedByCATPLMIntegrationAccess CATAdpChangeControl
{
public:
  /**
   * Constructor
   * @param *iUnknown
   *   For further use
   */
  CATAdpChangeControl(CATBaseUnknown *iUnknown = NULL) {;}
  virtual ~CATAdpChangeControl() {;}
   
   /**
   * @deprecated V6R419, see with configuration teams
   */
  HRESULT ActivateModificationUnderAction (const CATLISTV(CATPLMID) & iIds, 
                                     CATIAdpErrorMonitor * iopErrorMonitor
                                        );
  
  /**
  * @deprecated V6R419, see with configuration teams
  * DOES NOT WORK STARTING V6R419FD05, server failure since service is deprecated, see change/config teams.
  *
  */
  HRESULT DeactivateModificationUnderAction (const CATLISTV(CATPLMID) & iIds, 
                                         CATIAdpErrorMonitor * iopErrorMonitor
                                            );
};

#endif
