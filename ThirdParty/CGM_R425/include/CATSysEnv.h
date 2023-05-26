#ifndef CATSysEnv_h
#define CATSysEnv_h
/* */                           
//-----------------------------------------------------------------------
// DEPARTEMENT SAD               
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------


#include "CATUnicodeString.h"
#include "CATVarCouple.h"
#include <stdlib.h>  // putenv

#include "CATLib.h"
#include "JS0LIB.h"  // exported by...

class CATTrace;
class CATSysEnvList;


//======================================================================
class ExportedByJS0LIB CATSysEnv
//======================================================================
{
   public:
   
      //-- Some typedefs
      typedef enum 
      {
         CSE_DefaultEnvironment,
         CSE_NotDefaultEnvironment,
         CSE_Yes,
         CSE_No,
         CSE_NoInclude,
         CSE_OptIncError,
         CSE_MandIncError,
         CSE_MainEnv
      } Value;
      
      typedef enum
      {
         CSE_Undefined,
         CSE_User,
         CSE_Global
      } Mode;

      typedef enum
      {
         CSE_Server,
         CSE_Interactif
      }Type;
      typedef enum
      {
         CSE_Update,
         CSE_ResetVariable
      }Options;

      typedef enum
      {
         CSE_OK,
         CSE_KO,
         CSE_UnableToExpandAVariable,
         CSE_EnvNotFoundInList,
         CSE_VariableNotFound
      } ReturnCode;
      //---
 
      //--- The public methods
       
      CATSysEnv  ();
      CATSysEnv  (CATSysEnv *Env1);
      ~CATSysEnv ();

      
      /*
      *   Return the value of VarName , or NULL if VarName is not found
      */
      bool GetEnvU(const CATUnicodeString & VarName, CATUnicodeString *opszValue = nullptr);
      const char * GetEnv ( const char* VarName );  // ++IK8 17:08:29 @deprecated R420 Risk of data-loss!
   
      /* Insert in EnvArray, a CATVarCouple initialized to
      *  varname and varcouple
      */
      void PutEnv ( CATUnicodeString      varname , 
                    CATUnicodeString      varavlue, 
                    CATSysEnv::Options    Opts=CATSysEnv::CSE_Update, 
                    CATVarCouple::CVCType VarType=CATVarCouple::CVC_Undefined,
                    CATUnicodeString      Comment="" );

      /* 
      *  Delete a variable in EnvArray
      */
      CATSysEnv::ReturnCode  DelEnv( CATUnicodeString varname );

      /* Put in the CATUnicodeString texte all the variable and their value
      *   ex: Var1 = Val1
      *       Var2 = Val2
      */
      void List (CATUnicodeString &texte , CATSysEnv::Value DumpCustomised=CATSysEnv::CSE_Yes);
    
      /*
      *   Expand all the variables values in EnvArray
      */
      CATSysEnv::ReturnCode   ExpandEnv    ( const char * user_name, int EmptyValue=0 );
      CATSysEnv::ReturnCode   ExpandEnv    ( int EmptyValue=0);
      CATSysEnv::Mode         GetEnvMode   ( );
      CATSysEnv::Value        GetEnvStatus ( );
      CATSysEnv::Value        GetIncludeEnvStatus(); 
      CATSysEnv::Type         GetEnvType   ( );
      CATSysEnv::Value        GetEnvDeleteOld ( );
      CATSysEnv::Value        IsMainEnv ( );
      CATUnicodeString        GetEnvName   ( );
      CATUnicodeString        GetEnvPath   ( );
	  CATUnicodeString        GetArgList   ( );
	  CATUnicodeString        GetEnvProductLine ( );
	  CATUnicodeString        GetMarketingVersion ( );
      CATVarCouple *          GetNext      ( );
      CATVarCouple *          GetEnvVar    (const char* varname );
      time_t                  GetTimeStamp ();  
      int GetNb_Max_Variables();
      int GetNbVariables();
      int GetCurrentVar();
      
      void  SetCurrentVar( int i);  
      void  SetTimeStamp ( time_t s);  
      void  SetEnvMode   ( CATSysEnv::Mode  val_mode   );
      void  SetEnvStatus ( CATSysEnv::Value val_status ); 
      void  SetIncludeEnvStatus ( CATSysEnv::Value status ); 
      void  SetEnvType   ( CATSysEnv::Type val_type   );
      void  SetEnvName   ( CATUnicodeString Name      );
	  void  SetArgList   ( CATUnicodeString &iArgList );
	  void  SetEnvProductLine ( CATUnicodeString &iProductLine );
	  void  SetMarketingVersion ( CATUnicodeString &iMarketingVersion );
      void  SetEnvPath   ( CATUnicodeString Path      );
      void  SetEnvDeleteOld   ( CATSysEnv::Value val_del);
      void  SetMainEnvFlag ( );

      CATSysEnv::Value        IsEnvFilled ( );     
      CATSysEnv::ReturnCode   ChangeVariable ( const char * name, const char * value , const char * comment=NULL);   
      void  ClearEnv       ( );
      CATSysEnv::ReturnCode RemoveAllIncludes();
      CATSysEnv::ReturnCode RemoveInclude(CATUnicodeString type, CATUnicodeString value);

   private:
      int         Nb_Max_Variables;
      int         NbVariables ;
      int         CurrentVar;
      int         FirstRead;

      CATSysEnv::Type   EnvType;   
      CATSysEnv::Mode   EnvMode;   
      CATSysEnv::Value  EnvStatus;
      CATSysEnv::Value  EnvDeleteOld;
      CATSysEnv::Value  EnvFilled;  
      CATSysEnv::Value  IncludeEnvStatus; /** @win64 fbq : 64-bit structure padding **/
      CATSysEnv::Value  MainEnvStatus;
      CATUnicodeString  EnvName;
      CATUnicodeString  EnvPath;
	  CATUnicodeString  _ArgList;
	  CATUnicodeString  _ProductLine;
	  CATUnicodeString  _MarketingVersion;
      CATVarCouple      *EnvArray;
      time_t            TimeStamp;
      
      void  AddVariable    ( CATVarCouple &Var );
};


#endif
