// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef CATCVMStreamVersion_H
#define CATCVMStreamVersion_H

//#include "CATCVMGeoObjects.h"
#include "CATCVMSysObjects.h"
#include "CATCVMVersionDefinition.h"
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif
#include "CATCVMVersionDefinition.h"
#define CATMaxIdentifierNAME  32

class ExportedByCATCVMSysObjects CATCVMStreamVersion
{
public :
     CATCVMStreamVersion (CATCVMStreamVersionId Id, char *iVersionName);
     ~CATCVMStreamVersion();

	const char * GetVersionName() const; 
    CATCVMStreamVersionId GetVersionNumber() const;


private:
	char _VersionName [CATMaxIdentifierNAME];
    CATCVMStreamVersionId _Id;

	void SetVersionName ( char *iVersionName);


};

#endif
