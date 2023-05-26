//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2001                                          *
//*===========================================================================*
//*                                                                           *
//*  Advanced Function for JS0LIB0                                            *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation august 2001                                    adt              *
//*===========================================================================*
#ifndef CATLIBEX_H 
#define CATLIBEX_H  42400
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef _WINDOWS_SOURCE
#include <io.h>
#include <stdlib.h>
#else
#include <dirent.h>
#include <limits.h>
#endif

#include "CATUniStd.h"
#include "JS0LIB.h"
#include "JS0STDLIB.h"
#include "JS0TSLIB.h"
#include "JS0COMP.h"
#include "CATWTypes.h"
#include "CATLib.h"
#include "CATTSLib.h"           // CATConvertError, CATLibProcessArgEscape
#include "DSYSysZipErrorDef.h"  // INVALIDFD
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"


#ifdef _WINDOWS_SOURCE
void ExportedByJS0STDLIB FlushInvalidUNC ();
void ExportedByJS0STDLIB FlushInvalidNLSUNC ();

#define CATFLUSHINVALIDUNC	FlushInvalidUNC ();
#else
#define CATFLUSHINVALIDUNC	
#endif

class CATDirList;

class ExportedByJS0STDLIB CATDIR
{
public:
	CATDIR();
	~CATDIR();
	CATDirList	*_Enum;
};

  
class CATDirEnt
{
public :
  CATUnicodeString _Name;
  CATUnicodeString _AbsPath;
};

/**
 * CATGetEnvU.
 * It is strongly recommended to use this function instead of CATGetEnvValue/CATGetEnv, which are not Unicode compliant.
 * @param varname is the name of the environment variable.
 * @param opszValue [out] if provided, the input string will be set to the variable's value.
 * @return true if the variable is set, false otherwise.
 */
bool ExportedByJS0LIB CATGetEnvU(const char *varname, CATUnicodeString *opszValue = NULL);

bool ExportedByJS0LIB CATGetOfficialVariableU(const char *varname, CATUnicodeString *opszValue = NULL);

HRESULT ExportedByJS0STDLIB CATFlushInodeCache();

// @deprecated R423 Inefficient - output strings are allocated with new and must be deallocated by caller
HRESULT ExportedByJS0STDLIB  CATSplitPath (CATUnicodeString *iPath,	CATUnicodeString **oDir, CATUnicodeString **oFileName);

// if the caller prefers to preallocate the strings
HRESULT ExportedByJS0STDLIB  CATSplitPath  (const CATUnicodeString *iPath, CATUnicodeString *oDir, CATUnicodeString *oFileName);
// To be use preferably
HRESULT ExportedByJS0STDLIB  CATSplitPathEx(const CATUnicodeString *iPath, CATUnicodeString *oDir, CATUnicodeString *oFileName);

HRESULT ExportedByJS0STDLIB CATMakePath (CATUnicodeString *iDirPath, CATUnicodeString *iFileName, CATUnicodeString **oPath);

/* No Allocation but ioDirPath is modified !*/
HRESULT ExportedByJS0STDLIB CATMakePath (CATUnicodeString *ioDirPath, CATUnicodeString *iFileName);

// cf. similar to CATGetFileInfo (adds flags + HRESULT)
HRESULT ExportedByJS0STDLIB CATFileStat (CATUnicodeString *iPath, CATFileInfo *oStat, int iFlag=0);

HRESULT ExportedByJS0STDLIB CATCreateDirectoryR (CATUnicodeString *iPath); 

HRESULT ExportedByJS0STDLIB CATOpenDirectory (CATUnicodeString *iPath, CATDIR *ioDir);
HRESULT ExportedByJS0STDLIB CATReadDirectory (CATDIR *iDir, CATDirEnt *oEnt, int *endOfDir, int iNoAbs=0);
HRESULT ExportedByJS0STDLIB CATCloseDirectory(CATDIR *iDir);

HRESULT ExportedByJS0STDLIB CATListDirectory(CATUnicodeString & iDirPath, CATListOfCATUnicodeString & oFileList);

HRESULT ExportedByJS0STDLIB CATGetTempDirectory (CATUnicodeString **Path);

HRESULT ExportedByJS0STDLIB CATIsAbsolutePath (const char *iPath,int iType=0);

HRESULT ExportedByJS0TSLIB CATPathType (const CATUnicodeString & iPath, int *oType, size_t iLen=0);
HRESULT ExportedByJS0TSLIB CATPathType (const CATUC2Bytes *iPath, int *oType, size_t iLen=0);
// CATSysPathType: @deprecated R423, use CATPathType
HRESULT ExportedByJS0STDLIB CATSysPathType (CATUnicodeString *iPath, int *oType);

HRESULT ExportedByJS0STDLIB CATSysNameFilter( CATUnicodeString *iPath, char **oAsciiPath);

HRESULT ExportedByJS0STDLIB CATIdenticaleFile( CATUnicodeString *iPath1, CATUnicodeString *iPath2);


//Retrieves the full absolute path from a relative path. For NT, the absolute path is canonical.	
HRESULT ExportedByJS0STDLIB CATGetAbsolutePath (const CATUnicodeString * iRelativePath, CATUnicodeString & oAbsolutePath);			   

HRESULT ExportedByJS0STDLIB CATSetReadOnlyMode(CATUnicodeString fullPath);

HRESULT ExportedByJS0STDLIB CATSetWriteMode(CATUnicodeString fullPath);

HRESULT ExportedByJS0STDLIB CATRemoveDirectoryR(CATUnicodeString * iDirToRemove);


#define _CATSysListDirectory_H

#include "IUnknown.h" // pulls in the definition of HRESULT.

class ExportedByJS0STDLIB CATSysLSDirectoryEntry : public CATDirectoryEntry
// directory entry with locally cached modification timestamp.
{
  CATSysLSDirectoryEntry& operator=(const CATSysLSDirectoryEntry&);
  CATSysLSDirectoryEntry(const CATDirectoryEntry& entry, const CATFileInfo& fi);
public:
  /**
   * @nodoc
   * Copy constructor, needed for duplication of instances of this class.
   */
  CATSysLSDirectoryEntry(const CATSysLSDirectoryEntry&);
  
  /**
   * @nodoc
   * Returns 0 if the specified directory entry passed as 'entry' can not be stat().
   */
  static CATSysLSDirectoryEntry *make(char *dir, const CATDirectoryEntry& entry);
  ~CATSysLSDirectoryEntry() {}

  int operator==(const CATSysLSDirectoryEntry& other);

  // the following is a subset of what is in the CATFileInfo struct
	off_t	st_size;
	time_t	m_Atime;
	time_t	m_Mtime;
	time_t	m_Ctime;
};


#include <CATLISTP_Clean.h>
#define CATLISTP_Append
#define CATLISTP_QuickSort
#define CATLISTP_RemoveAll
#include <CATLISTP_Declare.h>
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByJS0STDLIB
CATLISTP_DECLARE( CATSysLSDirectoryEntry );
class ExportedByJS0STDLIB CATSysListOfDirectoryEntries : public CATLISTP(CATSysLSDirectoryEntry)
{
 public:
  CATSysListOfDirectoryEntries(const CATSysListOfDirectoryEntries&);
  CATSysListOfDirectoryEntries& operator=(const CATSysListOfDirectoryEntries&);
  
  CATSysListOfDirectoryEntries(int alloc=0) : CATLISTP(CATSysLSDirectoryEntry)(alloc) {}
  ~CATSysListOfDirectoryEntries();

  enum SortOrder {
    SORT_NONE                 = 0,
    SORT_BY_LAST_MODIFICATION = 1,
    SORT_BY_LAST_ACCESS       = 2,
    SORT_BY_SIZE              = 3,
    SORT_BY_NAME              = 4,
    SORT_BY_CREATION_TIME     = 5,

    // to be kept synchronized with the above.
    REVERSE_SORT_BY_LAST_MODIFICATION = 6,
    REVERSE_SORT_BY_LAST_ACCESS       = 7,
    REVERSE_SORT_BY_SIZE              = 8,
    REVERSE_SORT_BY_NAME              = 9,
    REVERSE_SORT_BY_CREATION_TIME     = 10
  };

  /**
   * @nodoc
   * List the contents of a directory, with the specified sorting order.
   */
  static CATSysListOfDirectoryEntries ListDirectory(const char *iPath, SortOrder iOrder);

  /**
   * @nodoc
   * Same as above, except you pass the output parameter explicitly, to avoid a CATSysListOfDirectoryEntries duplication.
   */
  static HRESULT ListDirectory(CATSysListOfDirectoryEntries& oListOfEntries, const char *iPath, SortOrder iOrder);
};	// class CATSysListOfDirectoryEntries


/** 
 * CATFileAccess.
 * @deprecated Use CATFileAccess(const CATUnicodeString &, int, int) instead (CATLib.h),
 * which was added to avoid any risk of data loss under specific locale settings.
 * Indeed, CATUnicodeString is implicitly convertible to "const char *", so the following code would have called 
 * CATFileAccess(const char *, int):
 * CATFileAccess(CATUnicodeString(...), 0);
 * => risk of data loss
 */
inline HRESULT CATFileAccess ( CATUnicodeString *iPath, int iMode, int iFlag = 0)
{
    if (iPath == NULL)
        return CATConvertError (INVALIDFD, FACILITY_WIN32);
    return _CATFileAccess(*iPath, iMode, iFlag);
}

/** 
 * CATDeleteFile.
 * @deprecated Use CATDeleteFile(const CATUnicodeString &) instead (CATLib.h),
 * which was added to avoid any risk of data loss under specific locale settings.
 */
inline HRESULT CATDeleteFile (CATUnicodeString *iPath)
{
    if (iPath == NULL)
        return CATConvertError (INVALIDFD, FACILITY_WIN32);
    return _CATDeleteFile(*iPath);
}

/** 
 * CATCreateDirectory.
 * @deprecated Use CATCreateDirectory(const CATUnicodeString &) instead (CATLib.h),
 * which was added to avoid any risk of data loss under specific locale settings.
 */
inline HRESULT CATCreateDirectory (CATUnicodeString *iPath)
{
    if (iPath == NULL)
        return CATConvertError (INVALIDFD, FACILITY_WIN32);
    return _CATCreateDirectory(*iPath);
}

/** 
 * CATRenameFile.
 * @deprecated Use CATRenameFile(const CATUnicodeString &, const CATUnicodeString &) instead (CATLib.h),
 * which was added to avoid any risk of data loss under specific locale settings.
 */
inline HRESULT CATRenameFile (CATUnicodeString *iPath, CATUnicodeString *iNewPath)
{
    if (!iPath || !iNewPath)
        return CATConvertError (INVALIDFD, FACILITY_WIN32);
    return _CATRenameFile(*iPath, *iNewPath);
}



/** 
 * @nodoc 
 * CATStartProcess / CATStartProcessEx  C++-compliant signatures (cf. CXX_NOPERMISSIVE mode in Imakefile).
 * @see CATTSLib.h for full documentation. However, please note the following behavior differences 
 * compared to the CATUnicodeString-based signatures:
 *   1) argv[0] must point to the program name, so the first applicative argument is argv[1]
 *   2) By default, for legacy compatibility reasons, the caller has to handle OS-specific escaping of arguments (cf. quotes on Windows). 
 *      However, one can enable automatic escaping by passing the flag: CATLibProcessArgEscape
 *      This flag is recommended to ensure proper code portability.
 */
#ifdef __cplusplus  // Useful mainly if moved to CATLib.h
/**
 * Regarding the const_cast below on Unix OS:
 * CATStartProcess signature was originally based on the signature of the "execv" system call.
 * This explains why C++ constness hasn't been taken into account in the first place for "argv".
 * Neither the pointers nor the string contents themselves are intended to be changed, though.
 * Thus, in this case, we get away with const_cast-ing in C++ code.
 * The following inline functions wrap this cast to avoid propagating it in client code.
 * 
 * cf. https://stackoverflow.com/questions/190184/execv-and-const-ness
 * "Specifying two levels of const- qualification for the argv[] and envp[] parameters for 
 *  the exec functions may seem to be the natural choice, given that these functions do not modify 
 *  either the array of pointers or the characters to which the function points, 
 *  but this would disallow existing correct code. 
 *  Instead, only the array of pointers is noted as constant."
 */
inline CATLibStatus CATStartProcess (const char *comPath, char const *const argv[],
                                        int wait, int *pid, int *exitStatus) {
    return CATStartProcess(comPath, const_cast<char *const*>(argv), wait, pid, exitStatus);
}
inline CATLibStatus CATStartProcessEx (const char *comPath, char const *const argv[], int iFlags, 
                                        int *pid, int *exitStatus, void **oReserved) {
    return CATStartProcessEx(comPath, const_cast<char *const*>(argv), iFlags, pid, exitStatus, oReserved);
}
#endif  // __cplusplus



#endif
