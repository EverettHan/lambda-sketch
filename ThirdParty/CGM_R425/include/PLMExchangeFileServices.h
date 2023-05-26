// *****************************************************************
// COPYRIGHT DASSAULT SYSTEMES 2013-2016
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : SANDEEP SWAMI
//      FUNCTION    : 3DXML FILE UTILITY SERVICES  
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class providing utility services for 3DXML FILE, like :
//             - Checking the format of file.
//             - Checking if file already exits.
//             - Getting the extension of the file, etc... 
// *****************************************************************
//
//   Story :
//   -------
//   Revision 1.0  July    2013  (ZUK) Initial Revision for V6R2014x
//   Revision 2.0  March   2013  (HIL) UEE service design for V6R2015x
//   Revision 2.1  June    2015  (JLM) Complete coverage and fix comments
//
// ****************************************************************

#ifndef PLMExchangeFileServices_H
#define PLMExchangeFileServices_H

#include "ExportedByPLMExchangeFileServices.h"
#include "CATIPLMComponent.h"
#include "CATListOfInt.h"

// -- Forward declaration

class CATUnicodeString ;


class ExportedByPLMExchangeFileServices PLMExchangeFileServices
{
   public:

    /**
      * Method to check the Path is available or not.
      * @param iusPath[in]
      * Selected Path
      * @param obAvaiable[ out]
      * status of path availability
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>in case of success.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      static HRESULT IsPathAvailable( CATUnicodeString & iusPath , CATBoolean & obAvailable ) ;

        /**
      * Method to check if the full file Path is available or not.
      * @param iusPath[in]
      * Selected full file Path
      * @param obAvaiable[ out]
      * status of path availability
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>in case of success.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      static HRESULT IsFullFilePathAvailable( CATUnicodeString & iusFullFilePath , CATBoolean & obAvailable );

    /**
      * Method to validating the format.
      * @param iusFileName [in]
      *   Selected File Name.
      * @param iusError [out]
      *   Error if any
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>in case of success.</dd>
      *   <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      *   </dl>
      */
      static HRESULT ValidateFormat( CATUnicodeString & iusFileName, CATUnicodeString &iusFormat, CATUnicodeString &ousError);

    /**
      * Method to validating file is accessible or not.
      * @param iusPath[in]
      *   Selected Path
      * @param iusFileName [in]
      *   Selected File Name
      * @param iusError [out]
      * @return
      *   Error if any
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>in case of success.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      static HRESULT ValidateFileAccess( CATUnicodeString &iusPath,CATUnicodeString &iusFileName, CATUnicodeString &ousError);

    /**
      * Method to check if the path conatains any special character.
      * @param iusFileName[ in]
      *   File Name in which special characters to be checked.
      * @return
      *   Error if any
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>in case of success.</dd>
      *   <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      *   </dl>
      */
      static HRESULT CATCheckSpecialChar(const CATUnicodeString& iusFileName);

    /**
      * Method to check and remove any special character in the given input string
      * @param iusFileName[ in]
      *   File Name in which special characters to be checked.
      * @param ousFileNameNoSpecChar[ in]
      *   Ouput File Name in which special characters have been removed.
      * @return
      *   Error if any
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>in case of success and at least one special character has been detected and removed.</dd>
      *   <dt>S_FALSE</dt> <dd>in case of success and not special character has been detected in the input string</dd>
      *   <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      *   </dl>
      */
      static HRESULT CATRemoveSpecialChar(const CATUnicodeString& iusFileName, CATUnicodeString & ousFileNameNoSpecChar);

    /**
      * Method to check if file is read only.
      * @param iusPath[ in]
      *   File Path
      * @param iusFileName[ in]
      *   File Name
      * @return
      *   Error if any
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>TRUE</dt>   <dd>file is read only.</dd>
      *   <dt>FALSE</dt>  <dd>otherwise.</dd>
      *   </dl>
      */
      static CATBoolean IsFileReadOnly(CATUnicodeString& iusPath,CATUnicodeString& iusFileName);

    /**
      * Method to check if file is alraedy exists.
      * @param iusPath[ in]
      *   File Path
      * @param iusFileName[ in]
      *   File Name
      * @return
      *   Error if any
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>TRUE</dt>    <dd>file is exists.</dd>
      *   <dt>FALSE</dt>  <dd>otherwise.</dd>
      *   </dl>
      */
      static CATBoolean IsFileAlreadyExist(CATUnicodeString& iusPath,CATUnicodeString& iusFileName);

    /**
      * Method to check if file is alraedy exists.
      * @param iusFullFilePath[ in]
      *   Full file path which includes the file name.
      * @return
      *   Error if any
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>TRUE</dt>    <dd>file is exists.</dd>
      *   <dt>FALSE</dt>  <dd>otherwise.</dd>
      *   </dl>
      */
      static CATBoolean IsFileAlreadyExist(CATUnicodeString& iusFullFilePath);

    /**
      * Method to check if the extension of a selected file corresponds with a selected format.
      *
      * @param iusFormat [in]
      *   Selected format (form : USAGE (*.extension))
      *
      * @param iusFilePath [in]
      *   file path or file name with extension.
      *
      * @return
      *   Error if any
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>TRUE</dt>    <dd>file is exists.</dd>
      *   <dt>FALSE</dt>  <dd>otherwise.</dd>
      *   </dl>
      */
      static CATBoolean FormatCorrespondingWithFileExtension(CATUnicodeString & iusFormat, CATUnicodeString & iusFilePath) ;

    /**
      * Method to Get all files having a particular the extension.
      *
      * @param iusDirectoryPath [in]
      *   File path directory.
      *
      * @param iListOfExtensions [in]
      *   Selected file extensions. (if enmpty string it provides all files in the directory)
      *
      * @param olstFileNames [out]
      *   File names with the right extension.
      *
      * @return
      *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>E_FAIL</dt>       <dd>Input argument not valid or no access to file directory.</dd>
      *   <dt>S_FALSE</dt>      <dd>No file found.</dd>
      *   <dt>S_OK</dt>         <dd>Some files answer to the criteria.</dd>
      *   </dl>
      */
      static HRESULT GetFileNames( const CATUnicodeString    & iusDirectoryPath 
                                 , CATListOfCATUnicodeString & iListOfExtensions
                                 , CATListOfCATUnicodeString & olstFileNames ) ;

    /**
      * Method to create full file path.
      * @param iusPath[ in]
      *   File Path
      * @param iusFileName[ in]
      *   File Name
      * @param ousFullPath[ out]
      *   Full File Path
      * @return
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>in case of success.</dd>
      *   <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      *   </dl
      */
      static HRESULT CreateFullPath(CATUnicodeString& iusPath, CATUnicodeString &iusFileName,CATUnicodeString &ousFullPath);

    /**
      * Method to get the file extension.
      *
      * @param iusFileName
      * File Name
      *
      * @param ibIfFullExtensionNeeded
      * This is boolean parameter which decides if user is expecting full extension
      * This variable is needed to set to TRUE when there are files which are having extensions such as ABC.Prt.123
      * Here, though actual extension is "Prt", but if user wants this extension as "Prt.123", then he needs to set this 
      * parameter to TRUE 
      *
      * @ return
      *   Error code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>File Extension String</dt> <dd>If method is successful</dd>
      *   <dt>Empty String</dt>          <dd>Default Value</dd>
      *   </dl>
      */
      static CATUnicodeString GetFileExtension(CATUnicodeString &iusFileName, CATBoolean ibIfFullExtensionNeeded = FALSE);

      /**
      * Method to get the file extension.
      *
      * @param iusFileName
      * File Name or file path
      *
      * @ return
      *   Error code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>File Extension String</dt> <dd>If method is successful</dd>
      *   <dt>Empty String</dt>          <dd>Default Value</dd>
      *   </dl>
      */
      static CATUnicodeString GetFileGenericExtension(CATUnicodeString &iusFileName);

    /**
      * Method to encode input string.
      *
      * @param iusUseBuffer [in]
      * buffer to encode.
      *
      * @param iListOfOptionValues [in]
      * List of input options like import option, Import under folder etc...
      *
      * @param oBufferedObjLength [out]
      * length of the encoded stream buffered Object.
      *
      * @param oStreamBuffer [out]
      * encoded stream.
      *
      * @return
      *   Error code.
      *   <br><b>Legal values</b>:  
      *   <dl>
      *   <dt>S_OK</dt>           <dd>all is done.</dd>
      *   <dt>E_INVALIDARG</dt>   <dd>Invalid input.</dd>
      *   <dt>E_OUTOFMEMORY</dt>  <dd>Out of Memory.</dd>
      *   </dl>
      */
      static HRESULT StreamString( CATUnicodeString & iusInputBuffer , CATListOfInt & iListOfOptionValues, int & oBufferedObjLength, char *& opStreamBuffer);

    /**
      * Method to get the file size.
      *
      * @param iusFileFullPath [in]
      * Full File Path.
      *
      * @param oFileSize [out]
      * File Size in KB.
      *
      * @return
      *   Error code.
      *   <br><b>Legal values</b>:  
      *   <dl>
      *   <dt>S_OK</dt>           <dd>all is done.</dd>
      *   <dt>E_INVALIDARG</dt>   <dd>Invalid input.</dd>
      *   <dt>E_FAIL</dt>         <dd>Size computation failed.</dd>
      *   </dl>
      */
      static HRESULT GetFileSize( CATUnicodeString& iusFileFullPath, double &oFileSize);

    /**
      * Method to get the date of creation for the file.
      *
      * @param iusFileFullPath [in]
      * Full File Path.
      *
      * @param ousCreationDate [out]
      * Creation date of the file.
      * e.g., "12/20/2014 12:59"
      *
      * @return
      *   Error code.
      *   <br><b>Legal values</b>:  
      *   <dl>
      *   <dt>S_OK</dt>           <dd>all is done.</dd>
      *   <dt>E_INVALIDARG</dt>   <dd>Invalid input.</dd>
      *   <dt>E_FAIL</dt>         <dd> creation date computation failed.</dd>
      *   </dl>
      */
      static HRESULT GetFileDateOfCreation ( CATUnicodeString& iusFileFullPath, CATUnicodeString &ousCreationDate);

    /**
      * Method to create a unique forlder at the temp path.
      *
      * @param iusFolderIdentString [in]
      * Folder Identification String. The identification string will be used to generate the created folder name.
      *
      * @param ousFullFolderPath [out]
      * Full path of the newly created folder.
      *
      * @param ousFolderName [out]
      * Name of the newly created folder.
      * the folder name will be created from the input (indent string) + (underscore) + (unique name created on fly).
      * e.g., if the input string is "folder", then the folder name would be "folder_<Unique_Name>".
      * @return
      *   Error code.
      *   <br><b>Legal values</b>:  
      *   <dl>
      *   <dt>S_OK</dt>           <dd>all is done.</dd>
      *   <dt>E_INVALIDARG</dt>   <dd>Invalid input.</dd>
      *   <dt>E_FAIL</dt>         <dd> Folder creation failed.</dd>
      *   </dl>
      */
      static HRESULT CreateUniqueTemporaryFolder( const CATUnicodeString & iusFolderIdentString
                                                , CATUnicodeString       & ousFullFolderPath
                                                , CATUnicodeString       & ousFolderName    ) ;

      static HRESULT CreateTemporaryFolder (const CATUnicodeString& iusFolderIdentString,
                                            CATUnicodeString& ousFullFolderPath, 
                                            CATUnicodeString& ousFolderName, 
                                            CATBoolean bIsUnique=FALSE);

    /**
      * Method to delete a folder at the temp path.
      *
      * @param iStrFullFolderPath [in]
      * Full path of the folder which is supposed to be deleted.
      *
      * @return
      *   Error code.
      *   <br><b>Legal values</b>:  
      *   <dl>
      *   <dt>S_OK</dt>           <dd> all is done.</dd>
      *   <dt>E_INVALIDARG</dt>   <dd>Invalid input.</dd>
      *   <dt>E_FAIL</dt>         <dd> Folder deletion failed.</dd>
      *   </dl>
      */
      static HRESULT DeleteTemporaryFolder(const CATUnicodeString & iStrFullFolderPath ) ;

    /**
      * Method to get the name of the file with or without extension.
      *
      * @param iStrPath [in]
      * Full path of the folders to be tested.
      *
      * @param ibWithExtension
      * This is boolean parameter which decides if user is expecting an extension or not
      *
      * @ return
      *   Error code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>File name String</dt> <dd>If method is successful</dd>
      *   <dt>Empty String</dt>         <dd>Default Value</dd>
      *   </dl>
      */
      static CATUnicodeString GetFileName(CATUnicodeString &iStrPath, CATBoolean ibWithExtension = FALSE);

    /**
      * Method to test if one folder exists, if not the function will create it.
      *
      * @param iusPath [in]
      * Full path of the folders to be tested.
      *
      * @return
      *   Error code.
      *   <br><b>Legal values</b>:  
      *   <dl>
      *   <dt>S_OK</dt>           <dd> All is done.</dd>
      *   <dt>E_FAIL</dt>         <dd> Method failed.</dd>
      *   </dl>
      */
      static HRESULT TestFolders(CATUnicodeString & iusPath ) ;

      /**
      * Method to test if the selected path and filename can be used to create a path that won't exceed the max length
      *
      * @param iFilePath [in]
      * string with the file path (can be terminated with a backslash or not).

      * @param iFileName [in]
      * name of the file to create (without extension)

      * @param iExtension [in]
      * extension of the created file (can start with the point or not).

      * @param oNewFileName [out]
      * final file name if the length exceed the MAX_PATH.
      *
      * @return
      *   Error code.
      *   <br><b>Legal values</b>:  
      *   <dl>
      *   <dt>S_OK</dt>           <dd> The compilated path doesn't exceed the MAX_PATH.</dd>
      *   <dt>S_FALSE</dt>        <dd> The compilated path exceed the MAX_PATH but the file name can be resized to fit</dd>
      *   <dt>E_FAIL</dt>         <dd> The compilated path exceed the MAX_PATH and the name of the file can't be created</dd>
      *   </dl>
      */
      static HRESULT CheckFilePathLength(CATUnicodeString & iFilePath, CATUnicodeString & iFileName, CATUnicodeString & iExtension, CATUnicodeString & oNewFileName);
      
      static HRESULT SplitFolderAndFileName(CATUnicodeString & iusPath, CATUnicodeString & oDirPath, CATUnicodeString & oFilePath) ;
   private:

      // Create Folders if they don't exist
      static HRESULT _createFolders( CATUnicodeString & iStrPath ) ;
} ;
#endif
