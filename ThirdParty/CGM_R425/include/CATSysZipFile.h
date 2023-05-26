//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2004                                          *
//*===========================================================================*
//*                                                                           *
//*  Compression		                                              *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation decembre 2004                                  adt              *
//*===========================================================================*
#ifndef CATSysZipFile_H
#define CATSysZipFile_H
#include <time.h>
#include "JS0COMP.h"



/* for general compression manipulation at buffer level*/
#include "CATSysCompress.h"

#include "DSYSysZipFile.h"
#include "CATSysMultiBuffer.h"

class l_CATSysZipFile;
class CATResourceLock;
class CATUnicodeString; 
class CATSysSimpleHashTable;
class CATSysZipLockBytes2;
class DSYSysPath;

/**
* Class for managing compressed archives.
* <br><b>Role</b>: CATSysZipFile manages archives of compressed files 
* following the .ZIP file format specification defined and published
* by PKWARE (R). 
*/
class ExportedByJS0COMP CATSysZipFile : public DSYSysZipFile
{
public:


	/**
*  Default constructor
*/		
	CATSysZipFile(int largeFiles = 0) ;


	/**
*  Cloning constructor. Build an object that shares the same reference counter, locks and Browsing Table 
*     as the object provided in parameter. Those members were allocated on the heap.
* Thread safe
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> E_FAIL</tt> if file or archive is not opened.
*/		
	CATSysZipFile(const CATSysZipFile & pZ);

	
	virtual ~CATSysZipFile();


	/**
* Opens or creates an archive.
* To be used in a multithreaded context. Thread safe.

* When a CATSysZipFile is opened in CATSysZip_ReadWrite mode, the underlying code first opens it in 
* CATSysZip_ExtractShared mode then the Switch method is used to reopen it in CATSysZip_Append/CATSysZip_OpenNew 
* modes and to fall back to read modes  (CATSysZip_Extract/CATSysZip_ExtractShared).
* During the lifecycle of the CATSysZipFile opened in CATSysZip_ReadWrite mode, it cannot be opened anymore 
*  (the OpenZip method will then return a STG_E_SHAREVIOLATION error) except in CATSysZip_ReadCopy mode which allows the 
* calling code to work on a separate copy of the zip archive. 
* 
* The CATSysZip_ReadCopy is used to open a zip archive and work on a separate temporary copy created in the $CATTemp directory. 
* The temporary copy is deleted when the archive is closed.
* When the archive has been opened otherwise in CATSysZip_OpenNew or CATSysZip_Append mode the OpenZip in CATSysZip_ReadCopy mode will fail.
* When it has been opened in CATSysZip_ReadWrite mode, it will succeed only if no switch has been made or if the last switch was made to 
* CATSysZip_Extract or CATSysZip_ExtractShared modes.
* <br><b>Role</b>: 
* @param iPath
*   the path of the archive
* @param iMode
*   Opening mode.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				       incomplete.
*   <br><tt> CATZ_FILENOTFOUND:</tt> if the archive was not found.
*   <br><tt> @hrefCATFRead return code :</tt> if some IO error occured.
*/
    HRESULT OpenZip( const CATUnicodeString & iPath, CATSysZipOpenMode iMode,int iFlags =0);
    HRESULT OpenZip( DSYSysPath & iPath, CATSysZipOpenMode iMode,int iFlags =0 ) override;
    HRESULT OpenZip( CATSysTSUnicodeString & iPath, CATSysZipOpenMode iMode,int iFlags =0);
    HRESULT OpenZip( CATUC2Bytes *iPath, CATSysZipOpenMode iMode,int iFlags =0 );
	HRESULT OpenZip( CATUnicodeString *iPath, CATSysZipOpenMode iMode,int iFlags =0);

	/**
* Opens or creates an archive from memory.
* Thread unsafe
* <br><b>Role</b>: 
* @param ioMLB
*   the CATSysMultiBuffer where the archive is or should be stored
* @param iMode
*   Opening mode.
* @param iFlag
*   DO NOT USE : RESERVED FOR FCS
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				       incomplete.
*   <br><tt> CATZ_FILENOTFOUND:</tt> if the archive was not found.
*   <br><tt> @hrefCATFRead return code :</tt> if some IO error occured.
*/
	HRESULT  OpenZip( CATSysMultiBuffer * ioMLB, CATSysZipOpenMode iMode, int iFlag = 0);
	HRESULT  OpenZip( DSYSysMultiBuffer * ioMLB, CATSysZipOpenMode iMode, int iFlag = 0) override;

	/**
* Adds files into an archive.
*Thread Unsafe.
* <br><b>Role</b>: 
* @param iList
*   the list of path of the files to add.
* @param iNb
*   number of files to add.
* @param iLevel
*    The compression level.
*    It  must be between 0 and 9:
*    1 gives best speed, 9 gives best compression, 0 gives no compression at
*    all (the input data is simply copied a block at a time).
* @param iBaseDir
*    The path of directory. If the added files are in a sub directory of 
*    iBaseDir the stored path will be only relative to iBaseDir and not 
*    absolut.
* @param iFlag
* 
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				    incomplete.
*/
    HRESULT AddFile( CATUnicodeString *iList, unsigned int iNb,
        int iLevel, CATUnicodeString *iBaseDir=NULL, 
	    DWORD iFlag=0);

	HRESULT AddFile( CATSysTSUnicodeString *iList, unsigned int iNb,
        int iLevel, CATSysTSUnicodeString *iBaseDir=NULL, 
        DWORD iFlag=0);
	
	HRESULT AddFile( CATUC2Bytes **iList, unsigned int iNb,
        int iLevel, CATUC2Bytes *iBaseDir=NULL, 
        DWORD iFlag=0);
	
	HRESULT AddFile( DSYSysPath * iList, unsigned int iNb,
        int iLevel, DSYSysPath * iBaseDir=NULL, 
        DWORD iFlag=0) override;

	/**
* Adds a directory into an archive.
*Thread Unsafe.
* <br><b>Role</b>: Adds a whole directories arborescence into the archive. 
* @param iDir
*   the path of the directory
* @param iLevel
*    The compression level.
*    It  must be between 0 and 9:
*    1 gives best speed, 9 gives best compression, 0 gives no compression at
*    all (the input data is simply copied a block at a time).
* @param iFlag
* 
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory.
*   <br><tt> CATZ_E_INVALIDARG :</tt> if arguments are not valid.
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				    incomplete.
*/
	HRESULT AddDirectory( CATUnicodeString *iDirectory, int iLevel,
						CATUnicodeString *iBaseDir=NULL, 
						DWORD iFlag=0);

	HRESULT AddDirectory( CATSysTSUnicodeString *iDirectory, int iLevel,
						CATSysTSUnicodeString *iBaseDir=NULL, 
						DWORD iFlag=0);
	HRESULT AddDirectory( CATUC2Bytes *iDirectory, int iLevel,
						CATUC2Bytes *iBaseDir=NULL, 
						DWORD iFlag=0);
						
	HRESULT AddDirectory( DSYSysPath & iDirectory, int iLevel,
						DSYSysPath * iBaseDir=NULL, 
						DWORD iFlag=0) override;
	
	/**
* <br><b>Role</b>: Change modes on a CATSysZipFile object that was opened in CATSysZip_ReadWrite mode.
* When a CATSysZipFile is opened in CATSysZip_ReadWrite mode, the underlying code first opens it in 
* CATSysZip_ExtractShared mode then the Switch method is used to reopen it in CATSysZip_Append/CATSysZip_OpenNew 
* modes and to fall back to read modes  CATSysZip_Extract/CATSysZip_ExtractShared. 
* @param iMode
*   The desired mode for the switch. Only the following modes can be used here: 
*                       CATSysZip_OpenNew	, CATSysZip_Append	, CATSysZip_Extract	, CATSysZip_ExtractShared.
*     
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_INVALIDARG :</tt> if a wrong mode was required. Or values returned by the OpenZip or Close methods 
*/
	HRESULT SwitchMode(CATSysZipOpenMode iMode) override;


	/**
* Commits the modifications that were written to a zip archive opened in Append modes.
*     
* @return
*   Fails when modifications cannot be written.
*/
	HRESULT Commit() override;
	
	
	/**
* Decompresses an archive
*Thread Unsafe.
* <br><b>Role</b>: 
* @param iExtractDir
*   the path of the directory where files will be extracted to.
* @param iFlag
*   mode of the extraction that is a ORING of the following flags:
*   CATSYSUNZIP_OVERWRITE for overwriting files at the extraction
*   CATSYSUNZIP_WITH_PATH for recreating the arborescence.
* @param oNb
*   Number of files actually extracted.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_INSUFFICIENTBUFFER:</tt> if there was not enough room 
*					      in the output buffer
*   <br><tt> CATZ_E_INVALIDARG :</tt> if iExtractDir is NULL
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				    incomplete.
*/
    HRESULT ExtractAll( const CATUnicodeString & iExtractDir, DWORD iFlag, unsigned int *oNb=NULL);
	HRESULT ExtractAll( CATUnicodeString *iExtractDir, DWORD iFlag, unsigned int *oNb=NULL);
	HRESULT ExtractAll( CATSysTSUnicodeString &iExtractDir, DWORD iFlag, unsigned int *oNb=NULL);
	HRESULT ExtractAll( CATUC2Bytes *iExtractDir, DWORD iFlag, unsigned int *oNb=NULL);
	HRESULT ExtractAll( DSYSysPath & iExtractDir, DWORD iFlag, unsigned int *oNb=NULL) override;

	/**
* Decompresses a specific file.
*Thread Unsafe.
* <br><b>Role</b>: Decompress a specific file from the archive. 
* @param iPath
*   the file path of the zip file 
* @param iExtractDir
*   the path of the directory where files will be extracted to.
* @param iFile
*   the name of the file to be extracted.
* @param iFlag
*   mode of the extraction that is a ORING of the following flags:
*   CATSYSUNZIP_OVERWRITE for overwriting files at the extraction
*   CATSYSUNZIP_WITH_PATH for recreating the arborescence.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_INVALIDARG :</tt> if iExtractDir is NULL.
*   <br><tt> CATZ_E_FILENOTFOUND:</tt> if no file has been found with the 
*                                      given name.
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				    incomplete.
*/
    HRESULT ExtractFile( DSYSysPath &iExtractDir, const CATUnicodeString & iFile, DWORD iFlag ) override;
/**
 * @deprecated R417 ExtractFile.
 * Use the signature with CATUnicodeString &.
 */
    HRESULT ExtractFile( DSYSysPath &iExtractDir, CATSysTSUnicodeString & iFile, DWORD iFlag ) override;
	HRESULT ExtractFile( CATUnicodeString *iExtractDir, CATUnicodeString *iFile, DWORD iFlag);
	HRESULT ExtractFile( CATSysTSUnicodeString &iExtractDir, CATSysTSUnicodeString & iFile, DWORD iFlag );
	HRESULT ExtractFile( CATUC2Bytes *iExtractDir, CATUC2Bytes * iFile, DWORD iFlag );
	
	/**
* Parses the content of an archive.
*Thread Unsafe.
* <br><b>Role</b>: Parses the content of a zip file.
* @param oList
*   the list of files compressed inside the archive.
* @param oNb
*   number of files in the zip file.
* @param oSize
*   the list of original sizes of the files inside the archive. Can be null
*   if the information is not required.
* @param oZipSize
*   the list of original sizes of the files inside the archive. Can be null
*   if the information is not required.
* @param oTime
*   the list of last modification time of the files inside the archive. 
*   Can be null if the information is not required.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_INVALIDFUNCTION:</tt> if the file is not opened for
*					   extraction or not opened at all.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_INVALIDARG :</tt> if oList or oNb is null.
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive is corrupted.
*/
	HRESULT  BrowseZip( CATUnicodeString **oList,
        unsigned int *oNb,
        size_t **oSize=NULL,
        size_t **oZipSize=NULL,
        time_t **oTime=NULL) override;
    
    HRESULT  BrowseZip( CATUC2Bytes ** & oList,
        unsigned int *oNb,
        size_t **oSize=NULL,
        size_t **oZipSize=NULL,
        time_t **oTime=NULL) override;
        
	HRESULT  BrowseZip( CATSysTSUnicodeString ** oList,
        unsigned int *oNb,
        size_t **oSize=NULL,
        size_t **oZipSize=NULL,
        time_t **oTime=NULL) override;

	/**
* Closes an archive.
* <br><b>Role</b>: Closes the archive.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   tbd
*/
	HRESULT Close(DWORD iFlag = 0) override;  

	/**
* Opens a file in the archive.
*Thread unsafe.
* <br><b>Role</b>: Opens a file in the archive for writing or reading.
* depending on the opening mode that has been passed to @href #OpenZip.
* Due to the zip format only one file can be opened inside an archive a given
* time. A subsequent call to this methods on a new file, will first close the
* current one.
* @param iName
*   the name of the entry in the archive.
* @param iLevel
*    The compression level. This argument is ignored if the archive is opened
*    for extraction.
*    It  must be between 0 and 9:
*    1 gives best speed, 9 gives best compression, 0 gives no compression at
*    all (the input data is simply copied).
* @param iFlag
* 
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				    incomplete.
*   <br><tt> CATZ_E_FILENOTFOUND:</tt> if no file has been found with the 
*                                      given name.
*/
    HRESULT OpenFileInZip( const CATUnicodeString &iName, int iLevel, DWORD iFlag=0) override;
/**
 * @deprecated R417 OpenFileInZip.
 * Use the signature with CATUnicodeString &.
 */
	HRESULT OpenFileInZip( CATUnicodeString *iName, int iLevel, DWORD iFlag=0);
	HRESULT OpenFileInZip( CATSysTSUnicodeString & iName, int iLevel, DWORD iFlag = 0 ) override;
	HRESULT OpenFileInZip( CATUC2Bytes *iName, int iLevel, DWORD iFlag=0 ) override;
	/**
* Opens a file in the archive.
*Thread unsafe.
* <br><b>Role</b>: Opens a file in the archive for reading. Returns a pointer 
* on an ILockBytes2 object containing the uncompressed data in memory that 
*can   be read using ILockBytes2 methods.  
* This method CANNOT be used in a multithreaded context to open multiple ILockBytes2 objects in multiple threads. 
*Each object can then be used to read unzipped data in a separate thread. 
* @param iName
*   the name of the entry in the archive.
* @param iLevel
*    The compression level. This argument is ignored if the archive is opened
*    for extraction.
*    It  must be between 0 and 9:
*    1 gives best speed, 9 gives best compression, 0 gives no compression at
*    all (the input data is simply copied).
* @param iFlag
* 
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_BADDATA :</tt> if the archive was corrupted or 
*				    incomplete.
*   <br><tt> CATZ_E_FILENOTFOUND:</tt> if no file has been found with the 
*                                      given name.
*/		
    HRESULT OpenFileInZip (const CATUnicodeString & iName, int iLevel,  DWORD iFlag, CATILockBytes2 *& opZLB) override;
/**
 * @deprecated R417 OpenFileInZip.
 * Use the signature with CATUnicodeString.
 */
	HRESULT OpenFileInZip(CATUnicodeString *iName, int iLevel, DWORD iFlag ,CATILockBytes2 *& opZLB);	
	HRESULT OpenFileInZip(CATSysTSUnicodeString & iName, int iLevel,  DWORD iFlag , CATILockBytes2 *& opZLB) override;
	HRESULT OpenFileInZip(CATUC2Bytes *iName, int iLevel,  DWORD iFlag , CATILockBytes2 *& opZLB) override;
	
	/**
* Writes a buffer in the archive.
*Thread unsafe.
* <br><b>Role</b>: Writes a buffer into the file that have been opened before
* with @href #OpenFileInZip. The archive must have been open in 
* @href #CATSysZip_OpenNew or @href #CATSysZip_Append mode.
* @param iBuff
*    the data to be written
* @param iLen
*     the length of the data to be written.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_INVALIDFUNCTION :</tt> if the archive is not opened for
*					    writing or no file has been yet
*                                          opened with OpenFileInZip.
*/
	HRESULT AddBufferInZip( char *iBuff, size_t iLen ) override;

	/**
* Reads data in the archive.
*Thread unsafe.
* <br><b>Role</b>: Reads data from the file that have been opened before
* with @href #OpenFileInZip. The archive must have been open in 
* @href #CATSysZip_Extract.
* @param ioBuff
*    the buffer where the data will be written
* @param iLen
*     the length of the buffer.
* @param ioRead
*     MUST BE AT 0
*	  output side : the length of the data read.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
*   <br><tt> CATZ_E_INVALIDFUNCTION :</tt> if the archive is not opened for
*					    writing or no file has been yet
*                                          opened with OpenFileInZip.
*/
	HRESULT ReadBufferInZip( char *ioBuff, size_t iLen, size_t *oRead ) override;

	/**
* Close a file in the archive.
* Thread unsafe
* <br><b>Role</b>: Close the current file  that has been open with 
* @href #OpenZip.
* Due to the zip format only one file can be opened inside an archive a given
* time. A subsequent call to this methods on a new file, will first close the
* current one.
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> CATZ_E_FILENOTFOUND:</tt> if no file has been yet opened.
*/
	HRESULT CloseFileInZip( ) override;
	/**
*Returns an fz_info structure about the file that is currently open in the zip archive
* Thread unsafe
* @return
*   <b>Legal values</b>:
*   <br><tt> S_OK :</tt>on Success.
*   <br><tt> E_FAIL</tt> if file or archive is not opened.
*/	
	HRESULT GetCurrentInfo(fz_info * oInfo) override;
    
	
#if defined(_WINDOWS_SOURCE)    // Signatures provided for Native wchar_t support
    HRESULT  BrowseZip (WCHAR ** & oList, unsigned int *oNb, size_t **oSize, size_t **oZipSize, time_t **oTime) override
    {
        return BrowseZip(reinterpret_cast<CATUC2Bytes ** &>(oList), oNb, oSize, oZipSize, oTime);
    }
    HRESULT OpenFileInZip (WCHAR *iName, int iLevel, DWORD iFlag =0 ) override
    {
        return OpenFileInZip(reinterpret_cast<CATUC2Bytes *>(iName), iLevel, iFlag);
    }
    HRESULT OpenFileInZip (WCHAR *iName, int iLevel, DWORD iFlag , CATILockBytes2 *& opZLB) override
    {
        return OpenFileInZip(reinterpret_cast<CATUC2Bytes *>(iName), iLevel, iFlag, opZLB);
    }
#endif


private: 		
	
	l_CATSysZipFile * _l_zipFile;
	
	
	int GetNbrCopies();
};


#endif /* ZLIB_H */
