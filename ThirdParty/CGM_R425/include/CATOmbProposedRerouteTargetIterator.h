#ifndef CATOmbProposedRerouteTargetIterator_H
#define CATOmbProposedRerouteTargetIterator_H

// COPYRIGHT Dassault Systemes 2007

/**
 * @level Private
 * @usage U3
 */

#include "CATObjectModelerBase.h"

class CATOmbProposedRerouteTarget;

/**
 * Iterator on @href CATOmbProposedRerouteTarget.
 * <br><b>Role:</b>Used to have access to the possible target components, along with their status.
 * @see CATOmbReroutingError#GetTargetComponents 
 */
class ExportedByCATObjectModelerBase CATOmbProposedRerouteTargetIterator
{
public:

	/**
	 * Retrieves the next element.
	 * @return
	 *  NULL if there is no more element, the next element else.
	 *  <br><b>Note:</b>The returned element must not be deleted. 
	 */ 
	virtual CATOmbProposedRerouteTarget *operator++() = 0;

	/** @nodoc */
	virtual ~CATOmbProposedRerouteTargetIterator() {};
};

#endif
