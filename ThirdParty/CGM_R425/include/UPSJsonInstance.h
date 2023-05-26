
#ifndef UPSJsonInstance_H
#define UPSJsonInstance_H

#include "ExportedByCoexUPSJsonMapping.h"
#include "CATStdIO.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmxOHMap.h"
#include "UPSJsonObject.h"


	class ExportedByCoexUPSJsonMapping UPSJsonInstance : public UPSJsonObject
	{
	private:
		UPSJsonInstance& operator=(const UPSJsonInstance&);
		UPSJsonInstance(const UPSJsonInstance&);

	public:
		UPSJsonInstance();
		~UPSJsonInstance();
		
		// used by XPDM for setting XML ID 
		HRESULT SetRefID(const CATUnicodeString& i3dRefID);
		
		HRESULT GetRefID(CATUnicodeString& o3dRefID);
		// For TE to set the 3DExPID for Ref
		HRESULT Set3DRefID(const CATPLMID_Simple & i3dRefPLMID);

	
		
	private :

		CATUnicodeString _RefID;
		

	};
#endif

