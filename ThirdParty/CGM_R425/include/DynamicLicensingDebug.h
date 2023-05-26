#ifndef DynamicLicensingDebug_h
#define DynamicLicensingDebug_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "JS0CORBA.h"

struct DynamicLicensingDebugResult
{
	IUnknown *InterfaceObject;
	const char*info;
	CATMetaClass const *MetaOfInterfaceObject;
	CATMetaClass const *MetaOfDirectImplementation;
};

struct ChainedLicencedObject;

class ExportedByJS0CORBA DynamicLicensingDebug
{
private:
	static ChainedLicencedObject *Current;
public:
	static void Reset();
	static DynamicLicensingDebugResult Next();
};

#endif
