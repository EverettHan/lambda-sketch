#ifndef CATMMCFILE_H
#define CATMMCFILE_H

#include "CATMMediaCore2.h"

#include "CATUnicodeChar.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#include <functional>

class CATMMCSplitedString
{
public:
  CATMMCSplitedString(const CATUnicodeString& inputString, const CATUnicodeChar iSplitter);

  /**
  * Returns the number of fields separated by the splitter string. If a pointer to a list of strings is given, the list is filled with the separated fields.
  * @param iSplitter: eg:";", ":", "\", "/"
  */
  static int                SeperateStrings(const CATUnicodeString& inputString, const CATUnicodeChar iSplitter, CATListOfCATUnicodeString* oLst = NULL);
  /**
  * Returns the number of fields countaining seeked string.
  * @param iSplitter: eg:";", ":", "\", "/"
  * @param iSeekedString: eg:"Function"
  */
  static int                CountPositions(const CATUnicodeString& inputString, const CATUnicodeChar iSplitter, const CATUnicodeString iSeekedString);
  /**
  * Returns the position of first field countaining the specified seeked string.
  * @param iSplitter: eg:";", ":", "\", "/"
  * @param iSeekedString: eg:"Function"
  */
  static int                FindPosition(const CATUnicodeString& inputString, const CATUnicodeChar iSplitter, const CATUnicodeString iSeekedString);
  /**
  * Returns a sublist of the string devided by a specified splitter character.
  * @param iSplitter: eg:";", ":", "\", "/"
  * @param iFields  : eg:"1-3;5-", "4<","4<=". First element is index to 1. Order must be kept.
  */
//static CATUnicodeString   ExtractSplittedStrings(const CATUnicodeString& inputString, const CATUnicodeChar iSplitter, CATUnicodeString iFields);
private:
  const CATUnicodeString&   _inputString;
  const CATUnicodeChar      _splitter;
  CATListOfCATUnicodeString _lst;
};

/**
 * @ingroup groupPotentialSysFileSrv
 * @brief Services for manipulating file path.
 */
class ExportedByCATMMediaCore2 CATMMCFile
{
public:
  CATMMCFile();
  CATMMCFile(const CATUnicodeString file);
  CATMMCFile(const CATUnicodeString path, const CATUnicodeString file);
  virtual ~CATMMCFile();

  CATMMCFile&               operator=(const CATMMCFile&);

  //1. Working on strings
  static bool               HasWrongSeparator(const CATUnicodeString file);//Regarding OS (Win vs Unix).
  static bool               CorrectSeparator(CATUnicodeString& ioFile);
  void                      Reset(const CATUnicodeString file);
  enum CATMMCFileDesc { fDir = 1, fFile = 2, fExt = 4 };
  bool                      Has(int iRequest) const;
  CATUnicodeString&         Get(int iRequest = fDir | fFile | fExt) const;
  bool                      IsEqualTo(const CATMMCFile &iFile) const;
  bool                      HasSpaces(int iRequest = fDir | fFile) const;
//bool                      HasUnicode(int iRequest = fDir | fFile) const;
  void                      MakeTmp(int iRequest);
  void                      Set(int iRequest, const CATMMCFile& iSrc);
  void                      Set(CATMMCFileDesc ifd, CATUnicodeString iNew);

  //2. Working on directory or/and files
  int                       Exist (CATMMCFileDesc iRequest=fFile) const;//Implmented/fFile and fDir
  CATMMCFileDesc            Is    ();//Not const. If _name contains directory path, value is tranfered to _path;
  int                       Delete(CATMMCFileDesc iRequest=fFile);//Not implmented/directory
  int                       Open(const char *iMode);
  CATMMCFile&               Append(CATMMCFileDesc ifd, CATUnicodeString iExtend);
  CATMMCFile&               AddDirectoryToPath(const CATUnicodeString& iDir);
  unsigned int              GetFDesc() { return _fileDesc; };
  unsigned int              Write(const char *iBuff, unsigned int iSize);
  int                       Close();
  int                       CopyTo(CATMMCFile &iDest, bool iDeletePrevious=0);//File has to be closed. -1: something to do, but failed.
  int                       MoveTo(CATMMCFile &iDest, bool iDeletePrevious=0);//File has to be closed. -1: something to do, but failed.

  //3. static services.
  static const char*        GetPathsSeparator();
  static const char*        GetDirectorySeparator();
  static bool               CorrectSeparators(CATUnicodeString& ioPaths);
  static const char*        GetSettingPath();
  static const char*        GetInstallPath();
  static const char*        GetTmpDirectory();
  static bool               SplitAfterLast(const CATUnicodeString inputString, const CATUnicodeString iSplitter, CATUnicodeString *opBefore, CATUnicodeString *opAfter);
  static CATUnicodeString   CreateNewUUID();
  static CATUnicodeString  _WinSlash;
  static CATUnicodeString  _UnxSlash;
  static CATUnicodeString  _WinPathSep;
  static CATUnicodeString  _UnxPathSep;
  static CATListOfCATUnicodeString LookIntoDirectoryWithNameOrExtensions(const CATUnicodeString& iDirectory, CATMMCFileDesc iDirAndOrFile, CATUnicodeString nameDescription, int iRecursiveMode = 0);
  static CATListOfCATUnicodeString LookIntoDirectoryWithNameOrExtensions(const CATUnicodeString& iDirectory, std::function<bool(CATUnicodeString, bool)> const& filterFunc, int iRecursiveMode = 0);

private:
//CATMMCFile(const CATMMCFile&);
  bool                      RefuseRequest(int Request) const;

  CATUnicodeString         _path, _name, _ext;
  mutable CATUnicodeString _tmp;//_tmp will be used with System services that generally requires CATUnicodeString*. Devrait etre declaré mutable ?!
  unsigned int             _fileDesc;
  static CATUnicodeString  _empty;
};

/**
 * @ingroup groupPotentialSysFileSrv
 * @brief Services for indexing file names.
 */
class ExportedByCATMMediaCore2 CATMMCIndexedName
{
public:
  /**
  * Constructor: Index initialized to 0.
  */
  CATMMCIndexedName(CATUnicodeString iPrefixe, CATUnicodeString iSuffix, unsigned int iMaxDigit = 2);
  CATMMCIndexedName(CATUnicodeString iPrefixeAndIndexed, unsigned int iDigits);
  virtual ~CATMMCIndexedName();

  void              Increment();
  CATUnicodeString  GetIndexedName() const;
  CATUnicodeString  GetIndexedName(int iIndex) const;

  unsigned int        _index;

  static int IsIndexed(const CATUnicodeString& iString);

private:
  CATUnicodeString    _prefix;
  CATUnicodeString    _suffix;
  unsigned int        _maxDigit;
};

#endif
