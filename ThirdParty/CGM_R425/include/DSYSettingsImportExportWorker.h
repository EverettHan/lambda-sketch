#include "CATUnicodeString.h"

#include "SettingsCSVImportExport.h"

#ifdef _WINDOWS_SOURCE

//{WXYYZZZZ-6000-11D3-8CFE-0150048383C9}
#define OFFICE_2003_PRD_CODE "6000-11D3-8CFE-0150048383C9}"
#define OFFICE_2007_PRD_CODE "00000FF1CE}"

// Office 2007 {BRMMmmmm-PPPP-LLLL-p000-D000000FF1CE}
// Office 2003 {WXYYZZZZ-6000-11D3-8CFE-0150048383C9}

#define EXCEL_2003_PRD_CODE "16"
#define EXCEL_2007_PRD_CODE	"0016"


 BOOL  fIsOfficeProductCode(char *szProductCode);
 
extern "C"  ExportedBySettingsCSVImportExport BOOL fIsOfficeProductInstalled(char *szProductId);

 
#endif

class ExportedBySettingsCSVImportExport   DSYSettingsImportExportWorker
{

	public:
	
	DSYSettingsImportExportWorker();
	
	HRESULT ImportCSVFiles(CATUnicodeString  *files,int nb_files);
	
	HRESULT ImportXLSFiles(CATUnicodeString *files,int nb_files);

	HRESULT ImportCATVBSFiles(CATUnicodeString *files,int nb_files);
	
	HRESULT ExportSettingAsCSV(CATUnicodeString & iTargetCSV, CATUnicodeString & iSourceCATVBS);
	HRESULT ExportSettingsAsCSV(CATUnicodeString & iTargetFolder, CATUnicodeString & iCATVBSSourceFolder);
	HRESULT ExportSettingsAsXLS(CATUnicodeString & iTargetFolder, CATUnicodeString * iCSVSourceFolder =NULL, CATUnicodeString * iCATVBSSourceFolder=NULL);
	
	HRESULT ExportSettingsToFolder(CATUnicodeString & iFolder,CATUnicodeString & iEnvName,char iMode );
	HRESULT ImportSettings(CATUnicodeString * iFolder,int nb_files,CATUnicodeString & iEnvName,char iMode );
	void CleanTheMess();
	CATUnicodeString getTempMacroDir();
	
	private:
	
	HRESULT XLStoCSV();
	
	HRESULT CSVtoCATVBS(bool iNonExplicit);
	
	HRESULT RunMacros();

	CATUnicodeString _csvWorkDir;
	CATUnicodeString _xlsWorkDir;
	CATUnicodeString _catvbsWorkDir;
	CATUnicodeString _settingsMetadataPath;
	CATUnicodeString _XLSLoadPath;

	bool csv_generated;
};
