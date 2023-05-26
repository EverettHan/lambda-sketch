#ifndef _DSYSettingsCSVReader_H
#define _DSYSettingsCSVReader_H


#include "SettingsCSVImportExport.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "FileReader.h"
#define strRef CATUnicodeString & 



class ExportedBySettingsCSVImportExport DSYSettingsCSVReader
{
	public:
	
	DSYSettingsCSVReader(char iSeparator = ',');
	~DSYSettingsCSVReader();
	
	int ReadLine(int &  oExpositionType ,strRef oSetting, strRef oAttr,strRef oType, strRef oModifiedLevel, strRef oModified, strRef oLock, CATListOfCATUnicodeString & oValues);
	
	HRESULT Open(CATUnicodeString & iPath);
	
	HRESULT Close();
	
	
	private:
		FileReader * _sr;
		CATUnicodeString _separator;
};


#endif
