#ifndef _DSYGenericSettingsDumpParser_H
#define _DSYGenericSettingsDumpParser_H


#include "FileReader.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "SettingsCSVImportExport.h"
 #include <stdio.h>

class ExportedBySettingsCSVImportExport DSYGenericSettingsDumpParser
{
    private:
		FileReader * _sr;
		
		CATUnicodeString _controllerName;      
        CATUnicodeString _InternalsettingName;
		CATUnicodeString _line;
        bool _foundNewSetByChance;		
		int nb_fields_found;		
		int findNextV6Attribute();		
		int findNextV5Attribute();
		FILE * _logFile;
		int SyntaxError(char * iMessage);
		int SyntaxError(CATUnicodeString iMessage);
		
    public:		
		
		DSYGenericSettingsDumpParser();
		~DSYGenericSettingsDumpParser();
		
		CATUnicodeString _attName;
		CATUnicodeString _type;
		CATUnicodeString _explicitModification;
		CATUnicodeString _lock;
		CATUnicodeString _modified;
		CATListOfCATUnicodeString _values;
		CATUnicodeString _settingName;
		int versionFlag;
		
		HRESULT OpenFile(CATUnicodeString & iPath);
		HRESULT CloseFile();
		
        int findController();
		
		int findNextSetting();
        
        int findNextAttribute();
		
		void InitLog(FILE * iLog);

        inline CATUnicodeString getCurrentSettingName()   { return _settingName;  };

};

#endif
