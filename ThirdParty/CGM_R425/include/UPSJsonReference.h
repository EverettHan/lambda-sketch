
#ifndef UPSJsonReference_H
#define UPSJsonReference_H

#include "ExportedByCoexUPSJsonMapping.h"
#include "CATStdIO.h"
#include "CATUnicodeString.h"
//#include "CATIDocID.h"
#include "CATOmxArray.h"
#include "CATOmxOHMap.h"
#include "UPSJsonObject.h"
#include "UPSJsonInstance.h"

	class ExportedByCoexUPSJsonMapping UPSJsonReference : public UPSJsonObject
	{
	private:
		//UPSJsonReference(const UPSJsonReference&);// not available
		//UPSJsonReference& operator=(const UPSJsonReference&); // not available

	public:
		UPSJsonReference();
		~UPSJsonReference();
		UPSJsonReference& operator=(const UPSJsonReference&);
		UPSJsonReference(const UPSJsonReference&);		
		
		HRESULT GetChildInstances(CATOmxArray<UPSJsonInstance*>& oUPSJsonInstances);
		HRESULT AddChildInstance(UPSJsonInstance* &ipInstObj);
		HRESULT GetIsRoot(CATBoolean& oIsRoot);
		HRESULT SetIsRoot(const CATBoolean& iIsRoot);
		
	public:
		
		CATBoolean _IsRoot;
		CATOmxArray<UPSJsonInstance*> _ArrUPSJsonInstances;


	};
#endif

