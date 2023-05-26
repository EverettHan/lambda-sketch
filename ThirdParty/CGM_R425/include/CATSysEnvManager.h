#ifndef __CATSysEnvManager_h
#define __CATSysEnvManager_h                           


//-----------------------------------------------------------------------
// DEPARTEMENT SAD
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------
#include "JS0LIB.h"  // exported by..
#include "CATSysEnv.h"
#include "CATSysEnvList.h"
#include "CATBoolean.h"
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14

class CATTrace;
class CATSysEnvFileManager;
class CATListValCATUnicodeString;
class CATSysEnvTool;

#define  USER_ENV_DIR     1
#define  GLOBAL_ENV_DIR   2
#define  UID_DIR          3

#define _SET_NEW_ENVIRONMENT_IN_UNIX
#define CATENV_TRACE_NAME "CATSYSENV"
struct ProductLineDescription 
{
  CATUnicodeString ProductLine;
  CATUnicodeString WindowsExeName;
  CATUnicodeString UnixExeName;
  CATUnicodeString StartMenuName;
  CATUnicodeString RegistredName;
  CATUnicodeString ExeToRegister;
  CATUnicodeString MaskToRegister;
  CATUnicodeString Is3264Authorized;
  CATUnicodeString IsLicensing;
  CATUnicodeString IsExeToBeLaunched;
  CATUnicodeString IsCustomShortcut;
  CATUnicodeString IsSetcatenv;
  CATUnicodeString IsNeedBBdemon;
  CATUnicodeString DocHomepage;
  CATUnicodeString Doc;
  CATUnicodeString ProductLineGroup;

};
//=================================================================================
class ExportedByJS0LIB CATSysEnvManager
  //=================================================================================
{
public:
  /****************************************************************************/
  /*                         PUBLIC VARIABLES                                 */
  /****************************************************************************/
  typedef enum
  {
    //CATSysEnv errors
    CSEM_OK=0,
    CSEM_KO,
    CSEM_UnableToExpandAVariable,
    CSEM_EnvNotFoundInList,
    CSEM_VariableNotFound,
    CSEM_VariableAlreadyExists,
    CSEM_UnknownVariableType,
    CSEM_UnableToComputeVariable,
    CSEM_BadOptions,
    CSEM_BadOptions_InvalidType,
    CSEM_MustBeSystemAdmin,
    CSEM_NonValidType,
    CSEM_DisplayHelp,
    CSEM_MandIncError,

    //CATSysEnvManager errors
    CSEM_DefEnvSet,
    CSEM_RefFileNotFound,
    CSEM_RefFileCannotBeOpened,
    CSEM_EnvNameNotSpecified,
    CSEM_InvalidEnvNameOption,
    CSEM_InvalidEnvDirOption,
    CSEM_InvalidEnvModeOption,
    CSEM_InvalidEnvVarOption,
    CSEM_UnspecifiedStorageDirectory,
    CSEM_EnvVarOptionNotFound,
    CSEM_EnvModeNotSpecified,
    CSEM_CannotDelOfficalVar,
    CSEM_DefaultFolderNotFound,
    CSEM_EnvFileNotFound,
    CSEM_SpecifiedFolderNotFound,
    CSEM_CannotWriteDefFolder,
    CSEM_UnableToWriteEnvFile,
    CSEM_FileAlreadyExist,
    CSEM_UnableToOpenEnvFile,
    CSEM_UnableToCreateVarPath,
    CSEM_NoVariableFound,
    CSEM_UnknownVariable,
    CSEM_CurrentEnvCannotBeModified,
    CSEM_NoConcatenationSpecified,
    CSEM_EnvIsNull,
    CSEM_CannotCreateDefaultFolder,

    CSEM_EnvDoesNotExist,
    CSEM_DiskFull,
    CSEM_CannotWriteHeader,
    CSEM_InvalidHeader,
    CSEM_VariableModificationFailed
  }ReturnCode;

  typedef enum
  {
    //Access Errors
    CSEM_Unknown                       = 0,
    CSEM_DIR_RW                        = 1 << 1,
    CSEM_DIR_RO                        = 1 << 2,
    CSEM_DIR_KO                        = 1 << 3,
    CSEM_HOME_Unaccessible             = 1 << 4,
    CSEM_NoRAccess                     = 1 << 5,
    CSEM_NoRWAccess                    = 1 << 6,
    CSEM_CSIDL_Unaccessible            = 1 << 7,
    CSEM_DSIsNotADirectory             = 1 << 8,
    CSEM_CATEnvIsNotADirectory         = 1 << 9,
    CSEM_UIDIsNotADirectory            = 1 <<10,
    CSEM_CannotAccessUIDSubdirectory   = 1 <<11,
    CSEM_USERPROFILE_Set               = 1 <<12,
    CSEM_TEMPDirectory_Set             = 1 <<13,
    CSEM_CannotCreateDSSubdirectory    = 1 <<14,
    CSEM_CannotCreateCATEnvSubdirectory= 1 <<15,
    CSEM_CannotCreateUIDSubdirectory   = 1 <<16,
    CSEM_CATEnv_Not_Created            = 1 <<17
  }AccessError;        



  /****************************************************************************/
  /*                         PUBLIC METHODS                                   */
  /****************************************************************************/
  CATSysEnvManager ( );
  ~CATSysEnvManager ( );

  void Make();
  void Unmake();

  CATSysEnvManager::ReturnCode Create ( CATUnicodeString EnvName, CATUnicodeString &Dir, CATUnicodeString ConcatPath, 
    CATSysEnv::Type Type,     CATSysEnv::Mode Mode,  CATSysEnv::Value Erase, CATSysEnv * &Env, CATUnicodeString &ArgList, CATUnicodeString &ProductLine, CATUnicodeString &iMarketingVersion);
  CATSysEnvManager::ReturnCode CopyFrom ( CATUnicodeString FromPath, CATUnicodeString Name, CATUnicodeString &StorageDir, CATUnicodeString ConcatPath,  
    CATSysEnv::Type Type, CATSysEnv::Mode Mode, CATSysEnv::Value Erase, CATSysEnv * &Env1, CATUnicodeString &ArgList, CATUnicodeString &ProductLine, CATUnicodeString &iMarketingVersion, int AppendValues=0); 
  CATSysEnvManager::ReturnCode Delete ( CATUnicodeString EnvName, CATSysEnv::Mode Mode);
  CATSysEnvManager::ReturnCode Delete ( CATSysEnv  iEnv  );
  CATSysEnvManager::ReturnCode Read   ( CATUnicodeString EnvName, CATSysEnv::Mode Mode, CATSysEnv * (&Env) , CATSysEnv::Value AvoidMandatoryInclude=CATSysEnv::CSE_No);
  CATSysEnvManager::ReturnCode Write  ( CATSysEnv *Env, int UpdateTms=1);
  CATSysEnvManager::ReturnCode Unload ( CATUnicodeString Name, CATSysEnv::Mode Mode);
  CATSysEnvManager::ReturnCode IsAnOfficialVariable   ( const char * varname);   
  CATSysEnvManager::ReturnCode SetCATEnvDirectory     ( CATSysEnv::Mode iMode, const CATUnicodeString iPath );
  CATSysEnvManager::ReturnCode GetCATEnvDirectory     ( CATSysEnv::Mode iMode, CATUnicodeString &oPath );
  CATSysEnvManager::AccessError GetDirectoryStatus    ( int iDir,CATUnicodeString &iPath);
  CATSysEnvManager::ReturnCode CheckIfFileExists      ( CATUnicodeString iEnvName, CATUnicodeString iStorageDir,
    CATSysEnv::Mode iMode);
  CATSysEnvManager::ReturnCode List                   ( CATSysEnv::Mode iMode, CATListValCATUnicodeString & oFileList  );
  CATSysEnvManager::ReturnCode AddExtension           ( CATUnicodeString *iEnvName);
  CATSysEnvManager::ReturnCode DeleteExtension        ( CATUnicodeString *iEnvName);
  void                         ListCurrentVariables   ( CATUnicodeString &texte   );
  bool                         CATGetEnvU             (const char *varname, CATUnicodeString *opszValue = NULL);
  const char   *               CATGetEnv              ( const char * varname      );    // ++IK8 17:08:29 @deprecated R420 Risk of data-loss!
  // CATUnicodeString             CATGetOfficialVariableU(const CATUnicodeString & varname);
  const char   *               CATGetOfficialVariable ( const char * varname      );    // ++IK8 17:08:29 @deprecated R420 Risk of data loss! Call IsAnOfficialVariable + CATGetEnvU instead
  void                         DumpEnv                ( CATUnicodeString & texte  );
  void                         DumpEnv                ( CATUnicodeString & texte, CATSysEnv * Env01);
  int                          GetNbOfEnvRead         ( );
  void                         ResetNbOfEnvRead       ( );
  CATSysEnv *                  GetMainEnv             (); 
  CATLibStatus                 ReloadMainEnv          ( const char * user_name );
  CATLibStatus                 SetCompanyName         (CATUnicodeString ComapnyName);                       
  CATSysEnvManager::ReturnCode GetListOfTools(CATUnicodeString iProductLine, CATSysEnvTool  * &oToolsList, int & oNumberOfTools);  
  CATSysEnvManager::ReturnCode GetListOfProductLines (CATListValCATUnicodeString & oProdList, int GetLabel=0);
  CATUnicodeString             GetModuleForProductLine (CATUnicodeString &ProductLine);
  CATUnicodeString             GetCopyRigthForProductLine (CATUnicodeString &ProductLine);
  CATUnicodeString             GetLabelForProductLine (CATUnicodeString &ProductLine);
  int                          CreateProductLinesArray (CATUnicodeString iCATReffilesPath = "");
  CATUnicodeString             GetProductLinesForOrder (int Order);
  int                          GetOrderForProductLine (CATUnicodeString & ProductLine);
  CATUnicodeString             GetExeToRegisterForProductLine (CATUnicodeString &ProductLine);
  CATULONG64                   GetMaskForExeToRegister (CATUnicodeString &ExeToRegister);
  CATULONG64                   GetMaskForProductLine (CATUnicodeString &ProductLine);
  CATBoolean                   Is3264AuthorizedForProductLine( CATUnicodeString & ProductLine);
  CATBoolean                   IsLicensingForProductLine( CATUnicodeString & ProductLine);
  CATBoolean                   IsExeToBeLaunchedForProductLine( CATUnicodeString & ProductLine);
  CATBoolean                   IsCustomShortcutForProductLine( CATUnicodeString & ProductLine);
  CATBoolean                   IsSetcatenvForProductLine( CATUnicodeString & ProductLine);
  CATUnicodeString             GetSetcatenvForProductLine (CATUnicodeString &ProductLine);
  CATBoolean                   IsNeedBBdemonForProductLine( CATUnicodeString & ProductLine);
  CATUnicodeString             GetDocHomepageForProductLine (CATUnicodeString &ProductLine);
  CATUnicodeString             GetDocForProductLine (CATUnicodeString &ProductLine);
  CATUnicodeString             GetProductLineGroupForProductLine (CATUnicodeString &ProductLine,
    CATUnicodeString iCATReffilesPath = "");
  CATUnicodeString             GetEnvFileProductLine ();

private:      

  /****************************************************************************/
  /*                        PRIVATE VARIABLES                                 */
  /****************************************************************************/
  static CATUnicodeString  * CurrentEnvName; 
  static CATUnicodeString  * CurrentEnvDir;
  static CATUnicodeString  * OSType;
  static CATSysEnvTool     * ToolsList;
  static int                 _NbOfEm;
  static int                 _NbOfOfficialVariables;
  static int                 _NbOfTools;
  static int                 _NbOfProductLines;
  static int                 _NbOfEnvListed;
  static int                 PrintDebugTraces;
  static int                 USE_FILE_VALUE;
  static char              ** OfficialVariables;

  //This array is used to store all the environments created.
  static CATSysEnvList *  ListOfEnv; 
  static CATSysEnv     *  MainEnv;

  static CATSysEnvFileManager * EFM;

  //This array is used to store all the environments created.
  static CATTrace * Trace1;
  static CATTrace * Trace2;
  //      static char message_trace[4096];
  static int cpt;

  static CATUnicodeString * UserCATEnvPath;
  static CATUnicodeString * GlobalCATEnvPath;
  static CATUnicodeString * UIDPath;

  static ProductLineDescription * _ProductLinesArray;

  static CATSysEnvManager::AccessError UserCATEnvError;
  static CATSysEnvManager::AccessError GlobalCATEnvError;
  static CATSysEnvManager::AccessError UIDError;

  /****************************************************************************/
  /*                         PRIVATE METHODS                                  */
  /****************************************************************************/

  void                                 WriteTraceHeader();
  void                                 WriteTraceDumpEnv();

  CATSysEnvManager::ReturnCode         AddEnvInList(CATSysEnv * Env1);
  CATSysEnvManager::ReturnCode         GetError( int CSEFM_Error );
  
  /**
   * _GetEnv.
   * @param oppUnicodeValue (Used on Windows to handle values containing Unicode data properly!)
   * @returns pointer to a value string
   */
  const char *_GetEnv(const char * varname, CATUnicodeString *opszValue = NULL);

 /* CATLibStatus                         GetDirFromEnvDirFile(CATUnicodeString &EnvDir);
  CATLibStatus                         GetNameFromEnvNameFile(CATUnicodeString &EnvName);*/
  CATBoolean                           CheckFullPathEnv (CATUnicodeString & iDir, CATUnicodeString & iEnv);

};
#endif





