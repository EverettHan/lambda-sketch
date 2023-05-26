// COPYRIGHT DASSAULT SYSTEMES 200
//-----------------------------------------------------------------------------
// Abstract:Registration services - un/register an OLE server
//              see CATIARegistration.cpp for an example
//-----------------------------------------------------------------------------
#if !defined(CATREGISTRATION_INCLUDE) && defined(_WINDOWS_SOURCE)
#define CATREGISTRATION_INCLUDE

#include <wtypes.h>
#include "JS0CATREG.h"
#include "CATMsgCatalog.h"
#include "CATSysEnvManager.h"
// ++vxg - 11:11:14
#include "CATRegistrationDebug.h"
// --vxg - 11:11:14

class CATTrace;

#pragma warning (disable : 4200)

class ExportedByJS0CATREG CATRegistration {

public:
  // Registration key and value
  struct KeyDef {
    long Application;    // Application mask to register
    HKEY rootkey;
    const char *keypath;// Registry path
    const char *value;// value (encoded a la printf)
  };// see CATIAKeys.h for explanation and examples
  struct RegDef {
    const char *catalog;
    KeyDef keydefs[];
  };

  CATRegistration (CATTrace *tracer = NULL);
  ~CATRegistration ();

  // Register:
  // - env: Envirnonnement Name
  // - direnv: Envirnonnement directory path
  // - defs : keys and values to be registered.
  // - dontCheckFlag is 0 : only register if what's in the registry is out
  //                        of date.
  //             is not 0 : always register.
  // - iserverPath : the path that will replace serverPath in defs.
  //                 if NULL then the path of the running program is used.
  // - _ProductLine: Product Line name 
  int Register (const RegDef *defs, int dontCheckFlag, const char *iserverPath = NULL);
  int Register (const char * env, const char * direnv, const RegDef *defs, int dontCheckFlag, const char *iserverPath = NULL);
  int RegisterEx (const RegDef *defs, int dontCheckFlag, const char *iserverPath = NULL, const char *iProductLine="CATIA");
  int RegisterEx (const char * env, const char * direnv, const RegDef *defs, int dontCheckFlag, const char *iserverPath = NULL, const char *iProductLine="CATIA");
  // Unregister:
  // - defs the keys to be removed
  int Unregister (const RegDef *defs); 
  // Verify:
  // - defs the keys to be compared against
  int Verify (const RegDef *defs, int *missingCount, int *differentCount,
    const char *iserverPath = NULL);

private:
  struct ExportedByJS0CATREG Buffer {
    char *ptr;
    unsigned int size;
    Buffer ();
    ~Buffer ();
    BOOL Alloc (unsigned int);
    BOOL Realloc (unsigned int);
  };

  BOOL ParseKey (const char *key, char **osubkey, char **ovalname);
  HKEY CreateKey (HKEY key, const char *subkey);
  HKEY OpenKey (HKEY key, const char *subkey);
  BOOL GetValue (HKEY key, const char *valueName, DWORD *valueType, void **value, DWORD *valueLength);
 
  BOOL VerifyKey  (const KeyDef *kd, int *missing, int *different);
  BOOL RegisterKey (const KeyDef *kd, REGSAM isam);
  BOOL UnregisterKey (const KeyDef *kd, REGSAM isam);
  void PrintError (const char *imsg );
  void DisplayError (DWORD errCode, HKEY key, const char * subkey, const char *ifunc, const char *imsgkey);
  BOOL SetServerPath (const char *ipath);
  BOOL DetermineValue (const char *ivalue, const char **ovalue, unsigned long *olen);

  CATTrace  *_Tracer;
  const char *_Catalog;
  Buffer _Bufvalue;
  Buffer _Bufsubkey;
  Buffer _Bufvalname;
  CATUnicodeString _PathExe;
  CATUnicodeString _NameExe;
  CATUnicodeString _DirExe;
  CATUnicodeString _EnvName;
  CATUnicodeString _EnvDir;
  CATUnicodeString _EnvOption;
  CATULONG64   _MaskToRegister;
  unsigned int _EnvOptionLength;
  unsigned int _PathLengthExe;
  unsigned int _DirLengthExe;
  unsigned int _NameExeLength;
  CATUnicodeString  _ProductLine;
  CATSysEnvManager _EM;
};

#endif
