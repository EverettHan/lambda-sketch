#ifndef PLMSidlComAbendInfoClt_H
#define PLMSidlComAbendInfoClt_H

#include "CATAbendInfo.h"
#include "CATComSidl.h"
//#include "CATBaseUnknown.h"
//#include "CATComSidlInputStream.h"
//#include "CATComSidlTabPacket.h"
//#include "CATSysSHRequest.h"

class ExportedByCATComSidl PLMSidlCltAbendInfo : public CATAbendInfo 
{
	PLMSidlCltAbendInfo();
	PLMSidlCltAbendInfo(char *iDangerDetected);
	~PLMSidlCltAbendInfo();
	virtual char *Dump();

private:
	char	*m_DumpString;
} ;

#endif
