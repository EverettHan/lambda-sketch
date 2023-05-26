
#ifndef CATOmyTimeDump_H
#define CATOmyTimeDump_H

#include "CATUnicodeString.h"
#include "CATOMYCuteIOAccess.h"
#include "CATLib.h"

/**
 * @level Private 
 * @usage U1
 */

class ExportedByCATOMYCuteIOAccess CATOmyTimeDump
{
public:
	CATOmyTimeDump(CATUnicodeString iTag);
	virtual ~CATOmyTimeDump();
  CATULONG32 GetElapsedTime();

private:
	CATUnicodeString _Tag;
	CATTimerId _Timer;
};

#endif
