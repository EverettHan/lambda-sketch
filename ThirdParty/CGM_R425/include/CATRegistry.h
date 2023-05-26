#ifndef CATREGISTRY_INCLUDE
#define CATREGISTRY_INCLUDE

// Copyright DASSAULT SYSTEMES 1996
//-----------------------------------------------------------------------------
// Abstract:	Registry Services
//-----------------------------------------------------------------------------
#ifdef _WINDOWS_SOURCE
#include <wtypes.h>
#include "JS0LIB.h"

//
// Traverse a registry bottom-first
// NOTE: Only REG_SZ values are considered
//
class ExportedByJS0LIB CATRegistry {
    
  public:
    // Ready for traversal once constructed
    CATRegistry (HKEY key, const char *subkey);
    CATRegistry (HKEY key, const char *subkey, REGSAM mode );
    ~CATRegistry ();

    // Set a new key/subkey for traversal (to reuse the object)
    void SetNewKey (HKEY key, const char *subkey);

    // Enumerate all value names at current key and recurse down.
    // Specify a non-0 dontRecurseFlag to enumerate value names at current key
    // only
    //
    // returns:
    // 0     if registry have been traversed (name and value contain trash)
    // non-0 name and value contain a key path and value
    int Enum (char *name, long nameSize, char *value, long valueSize,
	      int dontRecurseFlag = 0);

    // Get/Set value (default value name is "")
    int GetValue (const char *valueName, char *value, long valueSize);
    int GetValueEx (const char *valueName, char *value, long valueSize);
    int SetValue (const char *valueName, const char *value);

    // For debugging
    static int GetNumCreated () { return numCreated; }
    static int GetNumOpened () { return numOpened; }

  protected:
    void Setup (HKEY key, const char *subkey);
    void Cleanup ();
    int EnumNextKey (char *name, long nameSize,
		     char *value, long valueSize);

    // for debugging
    static int numCreated;
    static int numOpened;
    CATRegistry *currentKey;
    char path[256];		// should be large enough to hold a subkey
    size_t pathLen;		// not the whole path
    HKEY keyHandle;
    DWORD valueIndex;
    DWORD valueCount;
    DWORD keyIndex;
    DWORD keyCount;
    REGSAM Mode;
};

// Access to HKEY_CURRENT_USER (or to HKEY_LOCAL_MACHINE on query)
ExportedByJS0LIB const char *DSGetEnv (const char *variable);
ExportedByJS0LIB int         DSDelEnv (const char *variable);
ExportedByJS0LIB const char *DSPutEnv (const char *variable,
				       const char *value);
// Update HKEY_CURRENT_USER and HKEY_LOCAL_MACHINE only if key exists
ExportedByJS0LIB const char *DSPutEnv1 (const char *variable,
					const char *value);
// Remove all variables at this path
ExportedByJS0LIB int         DSClrEnv (const char *path);

// Access to HKEY_LOCAL_MACHINE (on local or remote machine)
ExportedByJS0LIB const char *DSADMGetEnv (const char *variable,
					  const char *machine = NULL);
ExportedByJS0LIB int         DSADMDelEnv (const char *variable,
					  const char *machine = NULL);
ExportedByJS0LIB const char *DSADMPutEnv (const char *variable,
					  const char *value,
					  const char *machine = NULL);
ExportedByJS0LIB int         DSADMClrEnv (const char *path,
					  const char *machine = NULL);

// Expand CSIDL Key in a String
ExportedByJS0LIB DWORD ExpandCSIDLStringsA ( const char * c_in, char * c_out, DWORD c_out_size );

#endif // _WINDOWS_SOURCE

#endif
