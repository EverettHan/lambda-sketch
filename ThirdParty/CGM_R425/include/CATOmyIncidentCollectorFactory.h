/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2009
//-----------------------------------------------------------------------------
//
// class CATOmyIncidentCollectorFactory :
// 
// Services to manage Life Cycle of Error Monitor(s) to be used by applications
//
//-----------------------------------------------------------------------------
// 25/03/09 Creation                                                        VCS
//-----------------------------------------------------------------------------

#ifndef CATOmyIncidentCollectorFactory_H
#define CATOmyIncidentCollectorFactory_H

// System
/**
 * @level Private
 * @usage U1
 */

#include "CATBaseUnknown.h"
#include "CATOmyIncidentCollect.h"
#include "CATIOmyIncidentCollector.h"

class CATUuid;

/**
* Services to manage Life Cycle of the IncidentCollector
* <br><b>Role:</b> manages the <b>Creation and Retrieval and Release of an IncidentCollector </b> 
*  to be used by low level PLMServices in the current session.
* <br> The incidentCollector is used to stack low level PLM services (stream, export,...) errors
* <br> into the specific CATIOmyIncidentCell format. 
* <br> IncidentCollector Life cycle is to be managed the following way:
* <ul>
* <li>Get or Create IncidentCollector in session: GetIncidentCollector</li>
* <li>Find the IncidentCollector previously created : GetIncidentCollector</li>
* <li>Fill the IncidentCollector: cf CATIOmyIncidentCollector / CATIOmyIncidentCell behaviors</li>
* <li>Empty the IncidentCollector after error stack display or transfer: CATOmyIncidentCollector->EmptyCollector()</li>
* </ul>
*/
class ExportedByCATOmyIncidentCollect CATOmyIncidentCollectorFactory
{
public:

  /**
  * @nodoc deprecated V6R2014 Use GetIncidentCollector instead
  */
  static HRESULT CreateIncidentCollector(CATIOmyIncidentCollector_var& ohIncidentCollector);

	/**
  * @nodoc deprecated V6R2014 Use GetIncidentCollector instead
	*/
	static HRESULT FindIncidentCollector(CATIOmyIncidentCollector_var& ohIncidentCollector);

  /**
  * Gets an Incident Collector from the current session.
  * <br><b>Role:</b> Finds or Creates, if not found, an Incident Collector
  * and references it in the current session.
  * @return
  *   ohIncidentCollector: the handler on the Incident Collector found or created by the factory.  
  * <br>                   (NULL_var if operation failed)
  */
	static CATIOmyIncidentCollector_var GetIncidentCollector();

};
#endif
