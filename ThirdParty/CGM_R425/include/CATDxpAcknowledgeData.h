
#ifndef CATDxpAcknowledgeData_H
#define CATDxpAcknowledgeData_H

#include "CATIAV5Level.h"
#ifdef CATIAR420 //FUN070403

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmxOHMap.h"
#include "ExportedByXPDMServices.h"





class ExportedByXPDMServices CATDxpAcknowledgeData
{


public:

	static CATDxpAcknowledgeData * getInstance();

	static void kill();

	CATListOfCATUnicodeString GetExternalIDList();

	void GetInfoHeaderInfoForAck(CATOmxOHMap<CATUnicodeString, CATUnicodeString> &oHmapInfoHeader);

	void AddToExternalIDList(const CATUnicodeString & iExternalID);

	void AddInfoHeaderData(const CATUnicodeString name, const CATUnicodeString value);

private:

	static CATDxpAcknowledgeData * _AckDataSingleton;
	CATDxpAcknowledgeData();
	~CATDxpAcknowledgeData();
	CATListOfCATUnicodeString _ExternalIDlist;
	CATOmxOHMap<CATUnicodeString, CATUnicodeString>  _MapOfInfoHeader;
	

};
#endif
#endif
