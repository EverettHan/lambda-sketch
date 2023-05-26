// COPYRIGHT DASSAULT SYSTEMES 2014
#ifndef DSYSysRscTools_h
#define DSYSysRscTools_h
/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined(__JS0RSCTools)
# define ExportedByJS0RSCTools  DSYExport
#else // __JS0RSCTools
# define ExportedByJS0RSCTools  DSYImport
#endif  // __JS0RSCTools

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/
#include <stdlib.h>
#include <stdio.h>

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"
#include "CATSysErrorDef.h"
#include "DSYSysRscError.h"

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

//=======================================================================
typedef void* DSYSysRscFactoryHandle;
//=======================================================================
class DSYSysPath;
class CATUnicodeString;
//=======================================================================



//--------------------------------------------------------------------//
//------------------- DSYSysRscBundleEntryInfo -----------------------//
//--------------------------------------------------------------------//
#ifdef __cplusplus
extern "C"
{
#endif  // __cplusplus
    struct DSYSysRscBundleEntryInfo
    {
        unsigned char*  _Checksum;
        unsigned int    _ChecksumSize;
        long long       _RawSize;
        long long       _CompSize;
        char            _IsSecable;
        char            _IsLibrary;
    };
#ifdef __cplusplus
}
#endif  // __cplusplus

//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

//--------------------------------------------------------------------//
//------------------------ DSYSysRscResult ---------------------------//
//--------------------------------------------------------------------//
class ExportedByJS0RSCTools DSYSysRscResult
{
public:
    DSYSysRscResult(HRESULT iRc, const char* ipFullPath);
    DSYSysRscResult(HRESULT iRc, const char* ipRelativePath, const char* ipName);
    ~DSYSysRscResult();
    
    HRESULT GetResult()
    { return m_Rc; }
    const char* GetFilePath()
    { return m_pFile; }
    
private:
    HRESULT m_Rc;
    char*   m_pFile;
};
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

//=======================================================================

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

/**
* DSYSysRscObbCreate  : Used to create a bundle in "Obb mode".
*                       This mode means : 
*                         - All files in with secable flag will be stored in the bundle with that flag.
*                         - All files under a "bin" directory will be marked as library.
*
*  NOTA : Unlike desktop set of functions "DSYSysRscBundleXXX", This function put the part holding secables files it the end of the bundle.
*         The secable part will be dispatchable
*
*
* @param iFileMarkerPath  : The path to the file marker containing information on which relative path have to be include in the bundle, which extensions in secable part or excluded, ...
*                           There are severable differents behaviour due to its presence :
*                          - No FileMarker    : Every files will be eligible for the bundle.
*                                                 All files under a "bin" directory will be marked as library.
*                                                 All files are stored in the secable part. (// TODO To be modified)
*                          - With Filemarker  : Only files with their directory given in the file marker will be eligible for the bundle
*                                                 Secable flag is extraced from the FileMarker, as the excluded flag (the last one will excluded an extension from the bundle for this relative path)
*
* @param iFileMarkerConcatenation : A concatenation of pathes where the file marker will be sought. Waiting for a concatenation as "{Concat1}\win_b64;{Concat2}\win_b64;{Concat3}\win_b64"
*
*/

//=======================================================================
ExportedByJS0RSCTools HRESULT DSYSysRscObbCreate(DSYSysPath& iSrcDir, DSYSysPath& iDstFile, DSYSysPath* ipFileMarkerPath = NULL);
ExportedByJS0RSCTools HRESULT DSYSysRscObbCreate(DSYSysPath& iSrcDir, DSYSysPath& iDstFile, const char* iFileMarkerConcatenation);
//=======================================================================

/************************************************************************/
/************************************************************************/

/**
* This set of functions is used to extract the flag to store in the METAToc for the installation tools.
* A FileMarker need to be open with the DSYSysRscMarkerOpen function, as many call as needed (in a loop for instance) on DSYSysRscMarkerRead, and DSYSysRscMarkerClose to end this process.
*/

/**
* DSYSysRscMarkerOpen : Open the given FileMarker
*
* @param oppHandle        : An handler on the FileMarker
* @param iMarkerFilePath  : The path to the FileMarker
* @param iInstallPath     : The path where the installation is done.
*                           IMPORTANT : it is used to recreate the relative path used in the filemarker if the path given in DSYSysRscMarkerRead is absolute (iFilePath) by cutting off  the install path.
*                           Example : iInstallPath           : C:/programs/DassaultSystemes/win_b64
*                                     iFilePath              : C:/programs/DassaultSystemes/win_b64/resources/msgcatalogs/toto.CATNls
*                                     searched in filemarker : "resources/msgcatalogs/toto.CATNls"
*/

/**
* DSYSysRscMarkerRead
*
* @param opType (int)   : The flag extracted from the FileMarker for the given iFilePath.
* @param iFilePath      : The path (absolute) to the file whose flag is needed.
* @param ipHandle       : The handle on the FileMarker
*
*   Infos for bundles built for mobile :
*     DSYSysRscMarkerRead_IsFileInMobileBundle    : To check if the file is included in the mobile version of the bundle (e.g : all files in file marker, secable and lib will be dispatched later at runtime)
*   Infos for bundles built for desktop :
*     DSYSysRscMarkerRead_IsFileInDesktopBundle   : To check if the file is included in the desktop version of the bundle (e.g : all files in file marker that are not secable or lib)
*/

/**
* DSYSysRscMarkerClose : Close the FileMarker
* @param ipHandle   : The handle on the FileMarker
*/

//=======================================================================
ExportedByJS0RSCTools HRESULT DSYSysRscMarkerOpen(void** oppHandle, DSYSysPath& iMarkerFilePath, DSYSysPath* iInstallPath = NULL);
ExportedByJS0RSCTools HRESULT DSYSysRscMarkerOpen(void** oppHandle, const char* iFileMarkerConcatenation, DSYSysPath* iInstallPath = NULL);
//=======================================================================

//=======================================================================
ExportedByJS0RSCTools HRESULT DSYSysRscMarkerRead(int* opType, DSYSysPath& iFilePath, void* ipHandle);
  ExportedByJS0RSCTools bool  DSYSysRscMarkerRead_IsFileInMobileBundle    (int opType);
  ExportedByJS0RSCTools bool  DSYSysRscMarkerRead_IsFileInDesktopBundle   (int opType);
//=======================================================================

//=======================================================================
ExportedByJS0RSCTools HRESULT DSYSysRscMarkerClose(void** oppHandle);
//=======================================================================


/************************************************************************/
/************************************************************************/

/**
* A set of 3 functions works with a call of DSYSysRscBundleInitialize at the begining of the use and of DSYSysRscBundleFinalize at the end.
* Between them, an entry in the bundle can be openned, wrote, and close with the 3 functions DSYSysRscBundleEntryOpen, DSYSysRscBundleEntryWrite and DSYSysRscBundleEntryWrite.
*
*            DSYSysRscBundleInitialize
*
*       |----DSYSysRscBundleEntryOpen  --^
*       |----DSYSysRscBundleEntryWrite --|
*       v----DSYSysRscBundleEntryClose --|
*
*            DSYSysRscBundleFinalize
*
* /!\ As each entries are independants. If in a loop, the HRESULT returned by DSYSysRscBundleEntryClose DOES NOT provide any information on the possibility to run the next DSYSysRscBundleEntryOpen /!\
*
* As Secable files are write at the end of the bundle, they are queued for latter writting.
* If the user is building a bundle with such files, a call to DSYSysRscBundleGetResults is mandatory to obtain result of secables files processing.
*
*/


/**
* DSYSysRscBundleInitialize: Initialize the factory under this API.
*
* For the file marker path, if the user set the environment variable "CATBundleFMPath" to a specific path, it will have the absolute priority on what have been given as parameter.
*
*
* @param iopRscFactory              : A handler to the created factory
* @param iBundlePath                : The path where the bundle will be created
* @param iRootPath                  : The path used to cut the absolute path of added files.
*                                     IMPORTANT : it is used to create the relative path stored in the bundle from the absolute path given in DSYSysRscBundleEntryOpen (iDestPath).
*                                     Example   : iInstallPath  : C:/programs/DassaultSystemes/win_b64
*                                                 iDestPath     : C:/programs/DassaultSystemes/win_b64/resources/msgcatalogs/toto.CATNls
*                                                 In bundle     : "resources/msgcatalogs/toto.CATNls"
* @param iFileMarkerConcatenation  : A concatenation of pathes where the file marker will be sought. Waiting for a concatenation as "{Concat1}\win_b64;{Concat2}\win_b64;{Concat3}\win_b64"
*                                    There are severable differents behaviour due to its presence :
*                                    - No FileMarker    : Every files will be eligible for the bundle.
*                                    - With Filemarker  : Only files with their directory given in the file marker will be eligible for the bundle if they match the filters.
*
* @param iNewBundle                : If set to 1, create a whole new bundle even if iBundlePath points to an existing one.
*                                    If set to 0, if there is and existing bundle at iBundlePath, it will be updated instead of erased.
*                                    if no bundle at iBundlePath, it will create it
*
* @return                          : S_OK 
*                                  : E_FAIL
*/
//=======================================================================
extern "C" ExportedByJS0RSCTools HRESULT DSYSysRscBundleInitialize(DSYSysRscFactoryHandle* iopRscFactory, DSYSysPath& iBundlePath, DSYSysPath* iRootPath, const char* iFileMarkerConcatenation, char iNewBundle);
//=======================================================================


    /**
    * DSYSysRscBundleEntryOpen : Open an entry in the bundle
    *
    * @param ipRscFactory  : The handler to the factory
    * @param oppHandle     : The poitner that will contain an handler on this entry.
    * @param iDestPath     : Is the absolute path of the file to include in the bundle.
    *                        Can be a relative path from iInstallPath given in DSYSysRscBundleInitialize.
    *                        Return E_EXCLUDEDFILE if not under the iInstallPath given in DSYSysRscBundleInitialize or under a relative path registered in the file marker, if this one is present.
    * @param iDataInBundle : Flag extracted from the METAToc.xml. Because only runtime data have to be included in the bundle, this int flag act as a bool, need to be setted to 
    *                        TRUE    : 1  ; if the file is part of a runtime data module.
    *                        FALSE   : 0  ; if not, and file will be ignored.
    *                        DEFAULT : -1 ; behave as it is a runtime data (from Android bundle creation)
    * @param iEntrySize    : In case of a use of the next function, DSYSysRscBundleEntryWrite, in a loop with a sliding buffer.
    *                        know the size of the file in advance avoid some calculation/re-allocation in order to optimize processing time.
    * @param iUpdateEntry  : Delete any existing entry and recreate one with these parameters.
    * @param iUseLZ4       : Use the LZ4 compression
    *
    * @return              : S_OK 
    *                      : E_FAIL
    *                      : E_EXCLUDEDFILE if file doesn't match iInstallPath of DSYSysRscBundleInitialize || is not included via iRunTimeData || is not included via the FileMarker
    *                      : E_FILEALREADYEXISTS if a file that match relpath/filename is allready present in the bundle (only if iUpdateEntry is set to false)
    */
    //=======================================================================
    extern "C" ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryOpen(DSYSysRscFactoryHandle ipRscFactory, void** oppHandle, DSYSysPath& iDestPath, const int iDataInBundle, unsigned int iEntrySize, bool iUpdateEntry, bool iUseLZ4);
    //=======================================================================


    /**
    * DSYSysRscBundleEntryWrite : Write in a buffer the given content - no async
    *
    * @param ipHandle     : The handler on the entry
    * @param ipBuffer     : The input buffer to store
    * @param ipBufferSize : The size of the input buffer to store
    * @param opWritten    : The total size writtentin the buffer
    *
    * OR
    *
    * Allow the user to delegate to the factory the reading of the file to add to the bundle in worker threads.
    * Because of this asynchronism, the user WILL NOT have the result of this reading immedialtly.
    * To obtain these results, a call to DSYSysRscBundleGetResults is necessary.
    *
    * @param ipHandle     : The handler on the entry
    * @param iFileToAdd   : The absolute path to the file to add to the bundle
    *
    * @return             : S_OK 
    *                     : E_FAIL
    *                     : DSYSysFOpen errors.
    */
    //=======================================================================
    extern "C" ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryWrite(void* ipHandle, const char* ipBuffer, const unsigned int iBufferSize, unsigned int* opWritten = NULL);
    ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryWrite(void* ipHandle, DSYSysPath& iFileToAdd);
    //=======================================================================


    /**
    * DSYSysRscBundleEntryClose : Add the buffer in the bundle related to the parameters of the entry - async
    *
    * @param oppHandle          : The handler on the entry.
    *
    * @return                   : S_OK 
    *                           : E_FAIL (in this case, bundle is cleaned from this entry)
    */
    //=======================================================================
    extern "C" ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryClose(void** oppHandle);
    //=======================================================================


    /**
    * DSYSysRscBundleEntryGetInfo : Return a DSYSysRscBundleEntryInfo structure (definition in this header) of an entry in the bundle
    *
    * @param ipRscFactory   : The handler to the factory.
    * @param iPath          : The path of the entry to remove from the bundle.
    *                         Can be relative (example : "toto/tata/bil.CATNls") or absolute (in the case, the root path used in DSYSysRscBundleInitialize is used to parse the path)

    * @param oEntryInfo     : The information structure
    *
    * @return               : S_OK 
    *                       : E_FAIL
    */
    //=======================================================================
    extern "C" ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryGetInfo(DSYSysRscFactoryHandle ipRscFactory, const char* ipPath, DSYSysRscBundleEntryInfo& oEntryInfo);
    //=======================================================================


    /**
    * DSYSysRscBundleEntryDelete    : remove an entry from the bundle.
    *
    * @param ipRscFactory   : The handler to the factory.
    * @param iPath          : The path of the entry to remove from the bundle.
    *                         Can be relative (example : "toto/tata/bil.CATNls") or absolute (in the case, the root path used in DSYSysRscBundleInitialize is used to parse the path)
    *
    * @return               : S_OK 
    *                       : E_FAIL
    */
    //=======================================================================
    extern "C" ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryDelete(DSYSysRscFactoryHandle ipRscFactory, const char* ipPath);
    //=======================================================================
    
    /*
    * Return the error list of the async writes done in DSYSysRscBundleEntryWrite() and DSYSysRscBundleEntryClose().
    * Because this function call WaitOnAllJobsTermination, it will negate async beneficts if called in the Open/Write/Close loop.
    * Function is meant to be call before DSYSysRscBundleFinalize().
    *
    * Result is allocated by the factory and is deleted in DSYSysRscBundleFinalize. User doesn't have to delete it.
    *
    * @param ipRscFactory : The handler to the factory.
    * @param oNbError     : number of error ( FAILED (l_Rc)) )
    *
    * @return   : array of DSYSysRscResult*
    */
    //=======================================================================
    extern "C" ExportedByJS0RSCTools DSYSysRscResult** DSYSysRscBundleGetResults(DSYSysRscFactoryHandle ipRscFactory, unsigned int* oNbError);
    //=======================================================================


/**
* DSYSysRscBundleFinalize : Finalize the creation of the bundle (write down the index table and some other stuff)
*
* @param ippBundleFactory : The handler to the factory to finalize.
*
* @return                 : S_OK 
*                         : E_FAIL
*/
//=======================================================================
extern "C" ExportedByJS0RSCTools HRESULT DSYSysRscBundleFinalize(DSYSysRscFactoryHandle* ippBundleFactory);
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
extern "C" ExportedByJS0RSCTools int DSYSysRscCmd(int iArgc, char** ippArgv, void* ipTracer);
//=======================================================================





/* deprecated version */
ExportedByJS0RSCTools HRESULT DSYSysRscBundleInitialize(DSYSysPath& iBundlePath, DSYSysPath* iRootPath, const char* iFileMarkerConcatenation, char iNewBundle);
    ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryOpen(void** oppHandle, DSYSysPath& iDestPath, const int iDataInBundle = -1, unsigned int iEntrySize = 0, bool iUpdateEntry = false, bool iUseLZ4 = false);
    ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryGetInfo(const char* iPath, DSYSysRscBundleEntryInfo& oEntryInfo);
    ExportedByJS0RSCTools HRESULT DSYSysRscBundleEntryDelete(const char* ipPath);
    ExportedByJS0RSCTools DSYSysRscResult** DSYSysRscBundleGetResults(unsigned int* oNbError);
ExportedByJS0RSCTools HRESULT DSYSysRscBundleFinalize();

ExportedByJS0RSCTools HRESULT DSYSysRscMarkerRead(bool* opType, DSYSysPath& iFilePath, void* ipHandle);


#endif  // DSYSysRscTools_h
