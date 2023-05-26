#ifndef _CATVPPriorityEnum_H
#define _CATVPPriorityEnum_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2001
#include "CATVisItf.h"

/** @nodoc */
enum CATVPPriority
{
	catVPOverlayPriority,
	catVPGraphPriority,
	catVPP3PlaneHighPriority,
	catVPHighPriority4,
	catVPHighPriority3,
	catVPHighPriority2,
	catVPHighPriority1,
	catVPMediumPriority,
	catVPLowPriority1,
	catVPLowPriority2,
	catVPLowPriority3,
	catVPLowPriority4,
	catVPP3PlaneLowPriority,
	catVPBackGroundPriority,
	catVPCompassPriority
};

/** @nodoc */
int ExportedByCATVisItf ConvertPriority(CATVPPriority);

#endif

