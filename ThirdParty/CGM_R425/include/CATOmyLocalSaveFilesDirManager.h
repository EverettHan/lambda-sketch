
#ifndef CATOmyLocalSaveFilesDirManager_h
#define CATOmyLocalSaveFilesDirManager_h

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATOMYBaseSessionRestrictedUseForIntegration.h"
#include "CATOmyFileServices.h"

class CATOmxUTF8String;
class CATOmyLocalSaveIsLogData;


class ExportedByCATOMYBaseSessionRestrictedUseForIntegration CATOmyLocalSaveFilesDirManager
{
  friend class CATOmyLocalSaveDebugData;
  // TODO: move to a central location
  const CATUnicodeString& EditorsFileName();
  const CATUnicodeString& InfraEditorsFileName();
  const CATUnicodeString& TOSFileName();
  const CATUnicodeString& SnapFileName();
  const CATUnicodeString& ImageSessionFileName();


  //This is to manage issues with localsave which could be missing transactions.
  //We ensure that each directory contains its file which files every transaction creation/deletion/copy/delete
  class DebugLogWriter
  {
    unsigned int _fileDesc;
    const CATUnicodeString &_path;
    CATBoolean _opened;
    HRESULT OpenFile();
  public:
    static const CATUnicodeString& TransacDataDebugFileName();
    DebugLogWriter(const CATUnicodeString &iPath);
    ~DebugLogWriter();
    void Write(const CATOmxUTF8String &iString);
  };

  DebugLogWriter _log;
  const OmyDirectoryEntry _srcPath;

  HRESULT DeleteFile(const CATUnicodeString & iFileName);
  HRESULT CopyFile(const CATUnicodeString & iTgtDirPath, const CATUnicodeString & iFileName);
public:
  //Creates the manager specifying where to write the transaction log. The path is also used to create new image or copy image
  CATOmyLocalSaveFilesDirManager(const CATUnicodeString & iLogDirPath) :_log(iLogDirPath), _srcPath(iLogDirPath) {}
  CATOmyLocalSaveFilesDirManager(const OmyDirectoryEntry & iLogDirPath) :_log(iLogDirPath._Path), _srcPath(iLogDirPath) {}
  HRESULT DeleteLocalSaveFiles();
  //Every pathes below are full pathes
  HRESULT CopyLocalSaveFiles(const CATUnicodeString & iTgtDirPath);
  HRESULT CopyIsLogFile(CATOmyLocalSaveIsLogData &iIsLogFile, const CATUnicodeString & iTgtDirPath);
  HRESULT CreateTransaction(const CATUnicodeString &iTgt); //path ending with the transaction name
  HRESULT CreateNewImage();
  HRESULT DeleteTransaction(const OmyDirectoryEntry & iTgtDirPath);

};

#endif
