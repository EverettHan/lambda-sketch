#ifndef CATNTScriptSite_H
#define CATNTScriptSite_H
// COPYRIGHT DASSAULT SYSTEMES 1997
//-----------------------------------------------------------------------------
// Class  :     CATNTScriptSite 
// Date   :     October 97
// Resp   :     EHT
//-----------------------------------------------------------------------------
// Abstract: class which runs macro scripts. These scripts could be in VBScript
//           or JScript. The CATNTScriptSite class is compliant with the CNext 
//           Object Model (id it derives from CATBaseUnknown) and contains a 
//           pointer to CATInternalNTScriptSite.
//
//           CATInternalNTScriptSite is an implementation of the NT interface 
//           IActiveScriptSite which is a script engine container
//           CATNTScriptSite is just an envelop of CATInternalNTScriptSite.
//
//           CNext developpers have to use the class CATNTScriptSite
//           and not CATInternalNTScriptSite.
//                            
//-----------------------------------------------------------------------------
#include "CATScriptEngine.h"
#include "CATBaseUnknown.h"
#include "CATVariant.h"
//#include "CATActiveX.h"
#include "CATI18NTypes.h"

#ifndef _WINDOWS_SOURCE

#include "Excepinfo.h"

#endif

class CATUnicodeString;
class CATInternalNTScriptSite;
interface IActiveScriptSite;


enum ScriptEngineVersionControl {IsActive, NoActive, NoChange};

class ExportedByCATScriptEngine CATNTScriptSite : public CATBaseUnknown   
{
  CATDeclareClass;	
  
  public :
    
//-------------------------------------------------------------------
// Constructor, copy constructor, destructor
//-------------------------------------------------------------------
  CATNTScriptSite         ();
  CATNTScriptSite         (const CATNTScriptSite & iSrc);
  virtual ~CATNTScriptSite();
  
//-------------------------------------------------------------------
// Synchronize the execution of the script and the Host messages loop
//-------------------------------------------------------------------
  HRESULT __stdcall SetMode(HRESULT (*iFctCallback)(LONG reserved1, 
						    void *reserved2)); 
  
//-------------------------------------------------------------------
// On UNIX, force the initialisation of the Script Engine
//-------------------------------------------------------------------
  static HRESULT __stdcall ReInit(); 

//-------------------------------------------------------------------
// AddNamedItem
// Adds a root-level object to the scripting engine's space
//
// PARAMETERS :
//   IUnknown          * iActiveObject  The root-level object
//   CATUnicodeString  * iObjectName    Name of iActiveObject
//   const IID         * iIIDOfObject   IID of iActiveObject
//  
//-------------------------------------------------------------------
  HRESULT __stdcall AddNamedItem(IUnknown               * iActiveObject,
                                 const CATUnicodeString * iObjectName,
                                 const IID              * iIIDOfObject);

//-------------------------------------------------------------------
// LoadScript
// Load a Macro which is contained by a buffer
//
// PARAMETERS :
//   IUnknown          * iActiveObject  Base Object of the execution
//   CATUnicodeString  * iObjectName    Name of iActiveObject
//   const IID         * iIIDOfObject   IID of iActiveObject
//   CATUC2Bytes       * iScriptBuffer  Buffer which contains the macro
//   CATUnicodeString  * iProgId        ProgId of the ScriptEngine,
//                                      if NULL the ProgId VBScript is
//                                      assumed. The default value is NULL
//   IActiveScriptSite * ipScriptSite   Pointer to an IActiveScriptSite.
//                                      The default value is NULL.
//   CATVariant        * Reserved       Reserved
//   EXCEPINFO         * oErrorInfo     Structure which contains the 
//                                      informations on failure.
//
//-------------------------------------------------------------------
  HRESULT __stdcall LoadScript(IUnknown          * iActiveObject, 
			       CATUnicodeString  * iObjectName, 
			       const IID         * iIIDOfObject, 
			       const CATUC2Bytes * iScriptBuffer, 
			       CATUnicodeString  * iProgId            = NULL, 
			       IActiveScriptSite * ipScriptSite       = NULL,
			       CATVariant        * Reserved           = NULL, 
			       EXCEPINFO         * oErrorInformations = NULL);

//-------------------------------------------------------------------
// CallSub
// Call a Sub with Arguments in the Loaded Macro
//
// PARAMETERS :
//   CATUnicodeString * SubName            Name of the Sub or Function
//   CATVariant       * iParams            Parameters array
//   int                NbParams           Number of Parameters
//   CATVariant       * oVarResult         Retturn Value of the Sub
//   EXCEPINFO        * oErrorInformations Structure which contains the 
//                                         informations on failure.
//
//-------------------------------------------------------------------
  HRESULT __stdcall CallSub(CATUnicodeString * SubName            = NULL,
                            CATVariant       * iParams            = NULL,
			    int                NbParams           = 0,
                            CATVariant       * oVarResult         = NULL,
                            EXCEPINFO        * oErrorInformations = NULL);

//-------------------------------------------------------------------
// UnloadScript
// Unload a Macro
//
//-------------------------------------------------------------------
  HRESULT __stdcall UnloadScript(); 

  private :
  CATInternalNTScriptSite * _InternalNTScriptSite;  
};


//-------------------------------------------------------------------
// execute a script which is in a text file
//
// PARAMETERS :
//   const CATUnicodeString & ifileName      Name of the file which 
//                                           contains the script
//   CATNTScriptSite       *& ioScriptParser if NULL a new instance of a 
//                                           script parser will be returned, 
//                                           else ioScriptParser is used.
//   CATVariant            * Reserved        Reserved. Must be = NULL
//   EXCEPINFO             * oErrorInfo      Structure which contains the 
//                                           informations on Error
//   CATUnicodeString      * iEntry          Name of an entry point. Default 
//                                           value is NULL.
//-------------------------------------------------------------------
ExportedByCATScriptEngine HRESULT __stdcall CATExecuteScriptFromTXTFile
                           (const CATUnicodeString & ifileName, 
			   CATNTScriptSite       *& ioScriptParser,
			   CATVariant             * oReturnValue = NULL, 
			   EXCEPINFO              * oErrorInformations = NULL,
			   CATUnicodeString       * iEntry = NULL);

//-------------------------------------------------------------------
// For test only
//-------------------------------------------------------------------
extern ExportedByCATScriptEngine ULONG compteurScript; 
extern ExportedByCATScriptEngine ULONG flagTestScript;

#endif // CATNTScriptSite_H










