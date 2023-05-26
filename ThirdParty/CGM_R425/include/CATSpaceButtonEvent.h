// COPYRIGHT DASSAULT SYSTEMES 2019

#ifndef CATSpaceButtonEvent_H
#define CATSpaceButtonEvent_H

#include "CATDeviceEvent.h"
#include "CATVisFoundation.h"
#include "CATBoolean.h"
#include "CATString.h"

class CATDevice;
class CATSupport;


class ExportedByCATVisFoundation CATSpaceButtonEvent : public CATDeviceEvent
{
	CATDeclareClass;

public:

	CATSpaceButtonEvent();
	virtual ~CATSpaceButtonEvent();
	CATString GetHeaderId();

	CATDevice    *Device;
	CATSupport	 *pSupport;
	CATString	    headerId;
};
#endif
