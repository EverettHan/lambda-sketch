#ifndef _DSYSettingsCSVWriter_H
#define _DSYSettingsCSVWriter_H


#include "SettingsCSVImportExport.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "FileReader.h"
#define str CATUnicodeString 



class ExportedBySettingsCSVImportExport DSYSettingsCSVWriter
{
	public:
	
	DSYSettingsCSVWriter(char iSeparator= ',');
	~DSYSettingsCSVWriter();
	
	int WriteLine(  int iVersionFlag,
					str iTabPage, 
					str iSetting,
					str iAttr,
					str iType,
					str iModifiedLevel, 
					str iModified, 
					str iLock, 
					CATListOfCATUnicodeString & iValues );
	
	HRESULT Open(CATUnicodeString & iPath);
	
	HRESULT Close();
	
	
	private:
		FileReader * _sr;
		str _separator;
};


#endif
