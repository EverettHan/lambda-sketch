/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef	xxPLMBatchInfraServices_h
#define	xxPLMBatchInfraServices_h

/** @level Private 
* @usage U1
*/

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByPLMBatchInfraServices.h"

class CATIPLMCompProviderRestrictedAccess;

class ExportedByPLMBatchInfraServices PLMBatchInfraServices {
  public:

/*x
Section PLMBatchInfraServices  
Abstract This class contains basic methods used to handle file resources (path, extension, directory, ...) without any prereq on standard PLMBatch objects: PLMBatchEngine , CATBatchContext ...
x*/


/**
 * Verify a directory existence and accessibility
 * <BR>Verify the existence and accessibility of a directory.
 * @param iDirName
 *   Full directory path
 * @return
 *   <dl>
 *   <dt><tt>0</tt>        the entered directory path is not valid (null).
 *   <dt><tt>1</tt>        the directory does not exist.
 *   <dt><tt>2</tt>        the directory exists but is not authorizes in writing.
 *   <dt><tt>3</tt>        if problem of access.
 *   </dl>
 */
static int CheckIfDirectory ( const CATUnicodeString &iDirName );

/**
 * Verify a file existence and accessibility
 * <BR>Verify the existence and accessibility of a file.
 * @param iFileName
 *   Full directory path
 * @param oExist
 *   Existance flag <ul>
 * <li>=0:   if the file does not exist
 * <li>=1: if the file exists
 * <li>=-1: if the file exists but does not observe the condition of access
 * </ul>
 * @param iAccess
 *   Access flag
 * <ul>
 * <li>=0: test the existence only
 * <li>=1: test the existence AND read access
 * <li>=2: test the existence AND write access
 * </ul>
 * @param iflag
 *   Access flag
 * <ul>
 * <li>=0: no flush of CATFileStat64 HashTable
 * <li>=1: INODE_UPDATE value for CATFileStat64 API
 * </ul>
 * @return
 *   <ul>
 *   E_FAIL: FileName corresponds a directory.
 *   </ul>
 */
static HRESULT CheckIfFile( const CATUnicodeString &iFileName, int &oExist, int iAccess = 0, int iflag=0 /*INODE_UPDATE*/); 

 /**
* Copy a Resource 
* <BR>Copy a resource (a file or the full content of a directory) under a directory.
* @param iResourcePath the relative local path (regarding CATInstallPath) of the resource to copy
* <UL>
* <LI>In case of iResourceToCopy is a File, the file is copied under the iReceivingDir
* <LI>In case of iResourceToCopy is a directory, the entire files under iResourceToCopy are copied under the iReceivingDir
* </UL>
* @param iResourceType the type of resource to copy
* <UL>
* <LI>1: iResourceToCopy is a directory
* <LI>0: iResourceToCopy is a file (default)
* </UL>
* @param iReceivingDir the directory under which resources have to be copied
* <BR><FONT COLOR=RED>Depending on the OS, iReceivingDir ends with '\' or '/' character</FONT>
* <BR>If iReceivingDir doesn't exist, it is created.
* @return <UL>
* <LI>OK: resource successfully copied
* <LI>
* <LI>E_FAIL: iReceivingDir is not a valid directory (not a directory, no write access)
* <LI>E_FAIL: iResourceToCopy can't be copied (does not exist, no read access)
* </UL>
*/
static HRESULT CopyResource (CATUnicodeString & iResourceToCopy , int iResourceType , CATUnicodeString & iReceivingDir);   

/**
     * Directory Scan
     * <BR>Scan a Directory to get the list of files, taken into account a filter criteria
     * <BR>Warning: non recursive: Search is not applied to sub-directories.
     * @param iDirectory the directory to scan
     * @param iFilterKeys the list of  key to filter files according to File name   
     * <BR>iFilterKeys is applied to the fileName, not on filePath ...
     * @param iFilterTyp the type of filtering to be applied when almost one iFilterKey is defined: <UL>
     * <LI>=0 AllBut: Return all files except the one containing the string 'iFilterKey' 
     * <LI>=1 NonePlus: Return only files containing the string 'iFilterKey' 
     * </UL>
     * @return The list of files found under iDirectoryName satisfying the iFilterKey/iFilterTyp criteria
      */

static CATListOfCATUnicodeString * GetListOfFiles(CATUnicodeString & iDirectory, CATListOfCATUnicodeString iFilterKeys, int iFilterTyp ) ;

/**
* Validates input FileName/FilePath 
* <BR> Validates input FileName/FilePath and removes * : ? < > | , \\ / " ... (plus blank on Unix) 
* also it replace the characters with '_' whose ascii value is not between of 32 and 127
* @param ioFullFileName
* The FileName/FilePath to validate. The validation is OS based and if it is a Filename/FilePath   
* @return the validated FileName/FilePath.
* <DD>output= CATTrue : the string has special character
* <DD>output= CATFalse : the string hasn't special character
*/

 
static CATBoolean ReplaceSpecialCharacters(CATUnicodeString & ioFullFileName); // OZQ for IR-103216


/**
 * PowerCopy of a file under a directory
 * <br>
 * @param iLocation
 *   Source directory path
 * @param iName
 *   Source Filename
 * @param iTargetLocation
 *   Target directory path
 * @param iTargetName
 *   Target Filename 
 * @return
 *   
 *   <br>S_OK: the copy could be done.
 *   <br>E_FAIL: the copy aborts<ul> 
 *	<li>  not readable source
 *	<li>  source file non-existent
 *	<li>  destination directory non-existent
 *	<li>  Problem of writing in the Target directory.
 *   </ul>
 * If Target File already exists, it will be overwritten (replace mode). In ordre to protect documents in the target directory, change the write access permission.
 */
static HRESULT CopyOneFileToDir(const CATUnicodeString &iLocation, const CATUnicodeString &iName, const CATUnicodeString &iTargetLocation, const CATUnicodeString &iTargetName);


/**
 * Validates the path of an xml file
 * <br>Main tests are whether file exist, good extension or is selectable.
 * @param iPath
 * The path of the xml file.
 * @param iaccess
 * The access mode of the xml file
 * <UL>
 *		<LI> = 0  Test the existence of the file </LI>
 *		<LI> = 1  Test the read access of the file </LI>
 *		<LI> = 2  Test the write access of the file </LI>
 *		<LI> = 3  Test the existence of the directory, file can not exist </LI>
 *		<LI> = 4  Test the write access of the directory </LI> 
 * </UL>
 * @param oErrMsg
 * This parameter is used for getting the error messages in case of any error.
 * @return
 * <UL>
 * <LI>= 0 :   The xml file path is valid.</LI>
 * <LI>= 170 : The xml file is a directory.</LI>
 * <LI>= 171 : The xml file doesnot exist.</LI>
 * <LI>= 173 : The xml file doesnot have read access.</LI>
 * <LI>= 175 : The xml file has bad extension.</LI>
 * </UL>
*/
   static int ValidXmlFile ( CATUnicodeString iPath, int iaccess, CATUnicodeString *oMsg = NULL) ;

/**
 * Test a directory validity.
 * <BR>Test if a directory is a valid directory or not.
 * @param iDir
 * The path of the directory.
 * @param iAccess
 * The access permission of the directory.
 * @param oMsg
 * This parameter is used for getting the error messages in case of any error. Default Value is NULL.
 * <br>Default Value is NULL.
 * @return
 *  <UL>
 *	<LI>= 200 : directory is a file.</LI>
 *  <LI>= 201 : directory doesnot exist.</LI>
 *  <LI>= 204 : directory doesnot have write access.</LI>
 *  <LI>= 205 : directory is un defined.</LI>
 * </UL>
*/

static int ValidDir(CATUnicodeString iDir ,  int iAccess , CATUnicodeString * oMsg = NULL ) ;


/**
 * Return the list of standard supported extension.
 * @param PLMBatchProvider 
 * Current PLMBatch Provider
 * @return the list of extension
 *  <p>This list has a specific format as follow:<ul>
 *  <li>list [2j-1] = extension (with or without *) - list [2j-1] = NLS tag<br>
 * </ul>for instance, in File mode: <ul>
 *     <li>list [2j-1] = "*.CATPart" - list [2j-1] = "CATPart (*.CATPart)"
 * </ul>
*/
static CATListOfCATUnicodeString GetQueriableObjectsList(CATUnicodeString PLMBatchProvider);	


/**
 * Convert a string with ${VARIABLE} syntaxe.
 * @param ioString
 * The string to interprete containing several ${VARIABLE} sub-string.
 * @return the string with interpreted ${VARIABLE} values. 
 * @return 1 if ioString is parsed/modified, 0 if not modified.
*/
static int ConvertVariablefromString(CATUnicodeString& ioString) ;

/**
 * Convert a path contains invalid characters.
 * @param ioPathVariable
 * The path to interprete containing no ${VARIABLE} sub-string.
 * @return the path with invalid characters replaced. 
 * @return the type of modification done on ioPathVariable
 * output=0: the path hasn't been modified (no invalid character)
  * output=2: path has been modified: it contained invalid characters
*/
static int CheckInvalidCharinPath(CATUnicodeString& ioPathVariable) ;


/**
 * Check a file name contains invalid characters.
 * @param ioNameVariable
 * The FileName to interprete containing no ${VARIABLE} sub-string.
 * @return the FileName with invalid characters replaced.
 * @return the type of modification done on ioNameVariable 
 * output=0: the FileName hasn't been modified (no invalid character)
  * output=2: FileName has been modified: it contained invalid characters
*/
static int CheckInvalidCharinName(CATUnicodeString& ioNameVariable) ;



/**
 * Validate input FileName/FilePath 
 * <BR>Validates input FileName/FilePath and removes * : ? < > | , \\ / " ... (plus blank on Unix)
 * @param ioFile
 * The FileName/FilePath to validate. The validation is OS based.   
 * @param iPath <UL>
 * <LI>= 0 : ioFile is a File name (default)
 * <LI>= 1 : ioFile is a Path 
 * </UL>
 * @param iSubstitution (optional) the substitution string in case of invalid character 
 * @return the validated FileName/FilePath. <UL>
 * <LI>output=0: the string hasn't invalid character
 * <LI>output=1: string has been modified: it contained invalid characters
 * </UL>
*/
static int ValidateFileName(CATUnicodeString& ioFile, int iPath=0,CATUnicodeString * iSubstitution=NULL);

/**
 * Get the full document path.
 * <BR>This method is used to get the full document path.
 * @param iDocAttach
 * The document for which the path is to be obtained (scan the CATDocView resource).
 * @return
 * The full document path.
*/
    static CATUnicodeString GetOfficialDocPath ( CATUnicodeString iDocAttach ) ;

/*x
Section Extension  
Abstract List of methods dealing with file extension managment, conversion and validation
x*/
/**
 * <FONT COLOR=RED>convert V5 extension to V6 PLMCoreTyp</FONT>
 * <BR>Temporarily added to convert V5 extension to V6 PLMCoreTyp
 * <BR>Will be removed once all Applications modify their CATIBatchAppl ::DocumentExtensionManaged
 */
static void ConvertP1TypeToP2Type(CATUnicodeString& ioType);

/**
 * Return the extension for the file.
 * <BR>This method returns the extension contained in a path.extension file
 * @param iPath
 * The file path or the file name with extention.
 * @return 
 * The extension of the file<ul>
 * <li>if the file is file.ext, the extension returned will be '<i>ext</i>'
 * <li>if the file is a CATIA file, the extension returned is the extension of the file and not the type of the document. 
 * For instance, a CATDrawing saved in file.CATPart will return CATPart and not CATDrawing.
 * </ul>As a result, this services is useless for CATIA documents. To be used only for 'non CATIA' files.
*/

static CATUnicodeString GetPathFileExtn(const CATUnicodeString iPath);

/**
 * Method to get the extension of the document.
 * <BR>This method returns the extension using the CATFileDescriptor of the specified path (exact extension)
 * @param iName
 * <UL>
 *		<LI> Path of the document in case of CATIA Document.</LI>
 *		<LI> URL of the document in case of ENOVIA Document.</LI>
 * </UI>
 * @return
 * <UL>
 *		<LI> extension of the document in case of a file </LI>
 *		<LI> NULL if no extension can be found</LI>
 *</UL>
*/
static CATUnicodeString GetRealExtension(CATUnicodeString iName) ;  



/**
 * Return the Extension of a document
  * @param iFileDocumentPathname
  *   The file path name.
  * @param oFileDocumentExtension 
  *   The returned file extension name.
  *   Returns an empty string if no file extension is found
  * @return
  *   S_OK
*/
static HRESULT GetFileExtension( const CATUnicodeString& iFileDocumentPathname, CATUnicodeString& oFileDocumentExtension ) ;

/**
 * Return the W Extension of a document
  * @param iFileDocumentPathname
  *   The file path name.
  * @param oFileDocumentExtension 
  *   The returned Windows type file extension name.
  *   Returns an empty string if no file extension is found
  * @return
  *   S_OK
*/
static HRESULT GetWFileExtension( const CATUnicodeString& iFileDocumentPathname, CATUnicodeString& oFileDocumentExtension ) ;

	/**
	* Set the batch type
	* @param  iBatchType The batch type
	* <UL>
	* <LI>type=0: Batch Std
	* <LI>type=1: Batch Server
	* <LI>type=2: Batch Task
	* <LI>type=3: ReleaseBatchServer
	* </UL>
	*/
static void SetBatchType(int iBatchType=0) ;

	/**
	* Get the batch type
	* @return the batch type 
	* <UL>
	* <LI>type=0: Batch Std
	* <LI>type=1: Batch Server
	* <LI>type=2: Batch Task
	* <LI>type=3: ReleaseBatchServer
	* </UL>
	*/
static int GetBatchType();

	/**
	* Method to get Set & Unset Batch server transaction
	* <BR>Set & Reset of non M1 cache before Batch server's each task launch
	* @param iMode (IN)
	*  Flag to decide to set or reset
	* @param iProviderName
    *   The provider name.
	* @return 
	* <ul>
	* <li>S_OK: Server mode transaction succeeded to clean cache data
	* <li>S_FALSE: Server mode transaction not implemented by connector
	* <li>E_FAIL: Server mode transaction failed
	* </ul> 
	*/
	static HRESULT ManageBatchSrvModeTransaction(CATUnicodeString & iBatchName, int iMode,CATUnicodeString & iProviderName); 

/**
 * Convert a Special character in XML Format.
 * @param oVal
 * The string to be converted to XML format if any.
 * @return S_OK if special character is converted to XML tag. 
 * @return S_FALSE if there is no special character to convert.
*/
static HRESULT EncodeValueforXML(CATUnicodeString& oVal);  

/**
* Convert a XML tags with special character
 * @param ocVal
 * The string to be converted from XML if any.
 * @return S_OK if XML tag  for special character is converted to special character. 
 * @return S_FALSE if there is no special character to convert.
*/
static HRESULT DecodeValueFromXML(CATUnicodeString& ocVal);   

/**
 * Convert a XML tags with special character
 * @param ocVal
 * The List of string to be converted from XML if any.
 * @return S_OK if XML tag  for special character is converted to special character. 
 * @return S_FALSE if there is no special character to convert.
*/
static HRESULT DecodeValueFromXML(CATListOfCATUnicodeString& ocVal);  

private:  
/**
* Gets the position of the extension a file name.
* <br>Gets the position of a windows extension a file name.
* Sample:<pre>
*          123456789012345678901234567
* Position 012345678901234567890123456  Length  oExtPos  oExtSize 
*         "xxx/yyy/Part1"                 13      -1         0
*         "xxx/yyy/Part1.CATPart"         21      14         7
*         "xxx/yyy/Part1.CATPart.45547"   27      22         5
* </pre>
* @param iDocStorageName
*   The document storage name.
* @param oExtPos
*   The position of the extension (0 to length - 1). If it's negative, no extension has been found.
* @param oExtSize
*   The size of the extension
*/
static void GetWFileNamePosExt(const CATUnicodeString &iDocStorageName, int &oExtPos, int &oExtSize);

/**
* Method to get CATIPLMCompProviderRestrictedAccess handle
*/
/**
 * @return IUnknown#Release 
 */
static CATIPLMCompProviderRestrictedAccess * GetPLMCompProviderRestrictedAccess_X();
  
/**
* Gets the position of the extension a file name.<br>
* Sample:<pre>
*  123456789012345678901234567
*  012345678901234567890123456  Dot1Pos  Dot2Pos  Length oExtPos  oExtSize
* "xxx/yyy/Part1"                 -1       -1       13      -1       -1
* "xxx/yyy/Part1.CATPart"         13       -1       21      13        7
* "xxx/yyy/Part1.CATPart.45547"   13       21       26      22        5
* </pre>
* @param iDocStorageName
*   The document storage name.
* @param oExtPos
*   The position of the extension (0 to length - 1). If it's negative, no extension has been found.
* @param oExtSize
*   The size of the extension
*/
static void GetFileNamePosExt(const CATUnicodeString &iDocStorageName, int &oExtPos, int &oExtSize);

static int _BatchType; //R217: BBX PLMBatchServer 
} ;

#endif
