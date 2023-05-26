#ifndef _DSYSettingsCATVBSWriter_H
#define _DSYSettingsCATVBSWriter_H


#include "SettingsCSVImportExport.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "FileReader.h"
#define str CATUnicodeString



class ExportedBySettingsCSVImportExport DSYSettingsCATVBSWriter
{
	public:
	
	DSYSettingsCATVBSWriter();
	~DSYSettingsCATVBSWriter();
	
	int WriteLine(  int iExpositionModel,
					str iSetting, 
					str iAttr,
					str iType, 
					str iModifiedLevel, 
					str iModified, 
					str iLock, 
					CATListOfCATUnicodeString & iValues );
	
	HRESULT Open(CATUnicodeString & iPath,int iPhase);
	
	HRESULT Close();
	bool _isOpen;
	
	
private:
	CATUnicodeString _settingName;
	CATUnicodeString _settingCtrlName;
	FileReader * _sr;
	CATUnicodeString _codeLevel;
	int nb_array;
	int _phase;
	
	
};


#endif
