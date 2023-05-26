#ifndef __CATSysEnvFileManager_h
#define __CATSysEnvFileManager_h       
//-----------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2001
//-----------------------------------------------------------------------

#include "CATSysEnv.h"
#include "JS0LIB.h"  // exported by.
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14

class  CATUnicodeString;
class  CATTrace;
class  CATListValCATUnicodeString;

#define  USER_ENV_DIR     1
#define  GLOBAL_ENV_DIR   2
#define  UID_DIR          3
 
//=========================================================================
class ExportedByJS0LIB CATSysEnvFileManager
//=========================================================================
{
  
public:

  /****************************************************************************/
  /*                         PUBLIC VARIABLES                                 */
  /****************************************************************************/
  typedef enum
  {
      CSEFM_OK=0,
      CSEFM_UserReadFailed_GlobalInstead,
      CSEFM_UserReadFailed_DefaultInstead,
      CSEFM_GlobalReadFailed_DefaultInstead,
      CSEFM_NameNotDefined,
      CSEFM_ModeNotDefined,
      CSEFM_WriteFailed,
      CSEFM_WriteFailed_FileSystemFull,
      CSEFM_NoWriteAccessToPath,
      CSEFM_NoReadAccessToPath,
      CSEFM_PathDoesNotExist,
      CSEFM_DeleteFailed_NoSuchFile,
      CSEFM_DefaultFolderNotFound,
      CSEFM_SpecifiedFolderNotFound,
      CSEFM_RefFileCannotBeOpened,
      CSEFM_RefFileNotFound,
      CSEFM_UnknownVariableType,
      CSEFM_UnableToComputeVariable,
      CSEFM_CannotWriteHeader,
      CSEFM_InvalidHeader,
      CSEFM_EnvNameNotSpecified,
      CSEFM_EnvFileNotFound,
      CSEFM_EnvDoesNotExist,
      CSEFM_UnableToWriteEnvFile,
      CSEFM_DiskFull,
      CSEFM_FileAlreadyExist,
      CSEFM_KO
   }Answer;

   typedef enum
   {
      //Access Errors
      CSEFM_Unknown                       = 0,
      CSEFM_DIR_RW                        = 1 << 1,
      CSEFM_DIR_RO                        = 1 << 2,
      CSEFM_DIR_KO                        = 1 << 3,
      CSEFM_HOME_Unaccessible             = 1 << 4,
      CSEFM_NoRAccess                     = 1 << 5,
      CSEFM_NoRWAccess                    = 1 << 6,
      CSEFM_CSIDL_Unaccessible            = 1 << 7,
      CSEFM_DSIsNotADirectory             = 1 << 8,
      CSEFM_CATEnvIsNotADirectory         = 1 << 9,
      CSEFM_UIDIsNotADirectory            = 1 <<10,
      CSEFM_CannotAccessUIDSubdirectory   = 1 <<11,
      CSEFM_USERPROFILE_Set               = 1 <<12,
      CSEFM_TEMPDirectory_Set             = 1 <<13,
      CSEFM_CannotCreateDSSubdirectory    = 1 <<14,
      CSEFM_CannotCreateCATEnvSubdirectory= 1 <<15,
      CSEFM_CannotCreateUIDSubdirectory   = 1 <<16,
      CSEFM_CATEnv_Not_Created            = 1 <<17
   }AccessError;  


   /****************************************************************************/
   /*                         PUBLIC METHODS                                   */
   /****************************************************************************/
  CATSysEnvFileManager();
  CATSysEnvFileManager( CATUnicodeString CName);
  CATSysEnvFileManager ( const CATUnicodeString iUserPath, const CATUnicodeString iGlobalPath); 
  ~CATSysEnvFileManager();    

  CATSysEnvFileManager::Answer Read               ( CATSysEnv * ioEnv , CATSysEnv::Value AvoidMandatoryInclude=CATSysEnv::CSE_No );
  CATSysEnvFileManager::Answer Write              ( CATSysEnv   iEnv                                   );
  CATSysEnvFileManager::Answer SetCATEnvDirectory ( CATSysEnv::Mode iMode, const CATUnicodeString iPath );
  CATSysEnvFileManager::Answer GetCATEnvDirectory ( CATSysEnv::Mode iMode, CATUnicodeString &oPath       );
  CATSysEnvFileManager::AccessError GetDirectoryStatus( int iDir,CATUnicodeString &iPath);
  CATSysEnvFileManager::Answer List               ( CATSysEnv::Mode iMode, CATListValCATUnicodeString & oFileList , int & oNbEnvFound ); 
  CATSysEnvFileManager::Answer Delete             ( CATSysEnv  iEnv                                   );
  CATSysEnvFileManager::Answer Delete             ( CATUnicodeString iEnvName, CATSysEnv::Mode iMode   );
  CATSysEnvFileManager::Answer CheckIfFileExists  ( CATUnicodeString iEnvName,  CATUnicodeString iStorageDir, CATSysEnv::Mode iMode);
  CATSysEnvFileManager::Answer GenerateEnvFromPattern( CATUnicodeString iConcatPath, CATSysEnv & oEnv); 
  CATSysEnvFileManager::Answer AddExtension (CATUnicodeString *iEnvName);
  CATSysEnvFileManager::Answer DeleteExtension (CATUnicodeString *iEnvName);
  void                         CheckUserHomeDirectory(CATUnicodeString user_home );
  CATSysEnv::Type              ConvertStrToEnvType(const char * val_type);
  const char *                 ConvertEnvTypeToStr (CATSysEnv::Type type);
  CATLibStatus                 SetCompanyName      (CATUnicodeString CompanyName );  

  CATSysEnvFileManager::Answer   ReadIncludeEnv (CATUnicodeString Path, CATSysEnv* ioEnv);
protected:
  CATSysEnvFileManager::Answer ListOldEnv ( CATSysEnv::Mode iMode, CATUnicodeString ** oEnvListe, int & oNbEnvFound, int iDate=2 ); 
  CATSysEnv::Mode              GetEnvModeFromFileHeader (unsigned int iEnvFileHandle);
  

private:

   /****************************************************************************/
   /*                        PRIVATE VARIABLES                                 */
   /****************************************************************************/
  
      static int   _NbOfFEM;
 
      static CATTrace * _Trace_EFM;
      static CATTrace * _Trace_EFM_Verbose;

      static CATUnicodeString * _UserCATEnvPath;
      static CATUnicodeString * _GlobalCATEnvPath;
      static CATUnicodeString * _UIDPath;
	  static CATUnicodeString _TmpType;

      static CATSysEnvFileManager::AccessError _UserCATEnvError;
      static CATSysEnvFileManager::AccessError _GlobalCATEnvError;
      static CATSysEnvFileManager::AccessError _UIDError;
		static char             ** _VariablesInRefFile;
		static CATUnicodeString  * _DefaultUserStorageDirectory;
		static char              * _CompanyName;
		static int                 _NbOfVariablesInRefFile;

      enum RefFileType
      {
         RefFile_Interactif   = 1 << 0,   
         RefFile_Server       = 1 << 1,
	 RefFile_BackwardComp = 1 << 2 
      };   
   /****************************************************************************/
   /*                        PRIVATE METHODS                                   */
   /****************************************************************************/

  int InitAdmin();
 
  CATSysEnvFileManager::Answer ReadReferenceFile     (CATSysEnvFileManager::RefFileType iType, CATUnicodeString iConcatPath, CATUnicodeString &oFileContent);


  CATSysEnvFileManager::Answer GenerateBackwardCompatibiltyShell(CATSysEnv * ioEnv);
  CATSysEnvFileManager::Answer AddEnvFileHeader  (unsigned int iFileHandle);
  CATSysEnvFileManager::Answer CheckEnvFileHeader(unsigned int iFileHandle );
  CATSysEnvFileManager::Answer MakeConcat ( CATUnicodeString iConcatPath, CATUnicodeString iSubPath, CATUnicodeString &oResult );

  
  


};

#endif








