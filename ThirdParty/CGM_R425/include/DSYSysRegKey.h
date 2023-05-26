#ifndef DSYSysRegKey_H
#define DSYSysRegKey_H


/******************************************************************/
/* includes                                                       */
/******************************************************************/
#include <string>
#include <vector>
#include "CATSysTS.h"
#include "CATILockBytes2.h"
#include "CATDataType.h"
#include "DSYString.h"
#include "DSYSysPath.h"
#include "DSYSysJSON.h"

#ifdef _WINDOWS_SOURCE
  // #include <atlbase.h>
#endif


/******************************************************************/
/* define                                                         */
/******************************************************************/
#ifdef _WINDOWS_SOURCE
  typedef HKEY DSYSysRegHKey;
#else
  typedef int DSYSysRegHKey;
#endif

#ifndef _WINDOWS_SOURCE
  enum
  {
    /* Misc*/
    REG_NONE,
    
    /* Key Data Types*/
    REG_DWORD,
    REG_QWORD,
    REG_SZ,
    REG_MULTI_SZ,
    // REG_EXPAND_SZ

    /* DSYSysRegHKey */
    HKEY_CLASSES_ROOT,
    HKEY_CURRENT_USER,
    HKEY_LOCAL_MACHINE,
    // HKEY_CURRENT_CONFIG,
    // HKEY_USERS,

    /* Security access options */
    KEY_READ,
    KEY_WRITE
  };

  class CATFileLockBytes;
#endif


class ExportedByCATSysTS DSYSysRegKey final
{
  
#ifndef _WINDOWS_SOURCE
  friend CATUnicodeString DSYSysRegKeyGetPath(DSYSysRegKey& iRegKey);
#endif
  
public:
  DSYSysRegKey();
  DSYSysRegKey(const DSYSysRegKey& iKey) = delete;
  ~DSYSysRegKey();  // Call CloseKey();

  HRESULT CreateKey(DSYSysRegHKey iKeyParent, const CATUnicodeString& iKeyName, CATULONG32 iSamDesired = KEY_READ | KEY_WRITE);   // Create&Open the key
  HRESULT CreateKey(DSYSysRegKey& iKeyParent, const CATUnicodeString& iKeyName, CATULONG32 iSamDesired = KEY_READ | KEY_WRITE);   // Create&Open the key
  HRESULT OpenKey(DSYSysRegHKey iKeyParent, const CATUnicodeString& iKeyName, CATULONG32 iSamDesired = KEY_READ | KEY_WRITE);      // Only open the key
  HRESULT OpenKey(DSYSysRegKey& iKeyParent, const CATUnicodeString& iKeyName, CATULONG32 iSamDesired = KEY_READ | KEY_WRITE);      // Only open the key
  HRESULT CloseKey();

  // Install equivalent: DeleteKey
  HRESULT DeleteSubKey(const CATUnicodeString& iKeyName);

  // Install equivalent DeleteKeyTree
  HRESULT RecurseDeleteKey(const CATUnicodeString& iKeyName);

  // Install equivalent: GetSubkeys
  HRESULT GetSubkeys(std::vector<CATUnicodeString>& oKeyNames) const;

  // Install equivalent: GetValues
  HRESULT GetValueNames(std::vector<CATUnicodeString>& oValueNames) const;

  // Install equivalent: "GetValue(s)"
  HRESULT QueryDWORDValue(const CATUnicodeString& iValueName, CATUINT32& oValueData) const;
  HRESULT QueryQWORDValue(const CATUnicodeString& iValueName, CATULONG64& oValueData) const;
  HRESULT QueryStringValue(const CATUnicodeString& iValueName, CATUnicodeString& oValueData) const;
  HRESULT QueryMultiStringValue(const CATUnicodeString& iValueName, std::vector<CATUnicodeString>& oValueData) const;

  // Install equivalent: "SetValue(s)"
  HRESULT SetDWORDValue(const CATUnicodeString& iValueName, CATUINT32 iValueData);
  HRESULT SetQWORDValue(const CATUnicodeString& iValueName, CATULONG64 iValueData);
  HRESULT SetStringValue(const CATUnicodeString& iValueName, const CATUnicodeString& iValueData);
  HRESULT SetMultiStringValue(const CATUnicodeString& iValueName, const std::vector<CATUnicodeString>& iValueData);

  HRESULT DeleteValue(const CATUnicodeString& iValueName);

private:

#ifdef _WINDOWS_SOURCE
  
#else
  CATUnicodeString  ComputeEnum(DSYSysRegHKey iKeyParent) const;
  DSYSysPath        ConcatWithParentPath(const CATUnicodeString& iKeyPath, CATUnicodeString iKeyName);
  HRESULT           QueryValue(const CATUnicodeString& iValueName, int iValueType, DSYSysJSONValue& oJSONValue) const;

  HRESULT         CreateKeyInt(const CATUnicodeString& iKeyPath, const CATUnicodeString& iKeyName, CATULONG32 iSamDesired = KEY_READ | KEY_WRITE);
  HRESULT         OpenKeyInt(const CATUnicodeString& iKeyPath, const CATUnicodeString& iKeyName, CATULONG32 iSamDesired = KEY_READ | KEY_WRITE);
  HRESULT         OpenKeyReal(const CATUnicodeString& iKeyPath, CATULONG32 iSamDesired = KEY_READ | KEY_WRITE);
  HRESULT         GetSubkeysInt(const CATUnicodeString& iKeyPath, std::vector<CATUnicodeString>& oKeyNames) const;
  bool            CheckWriteAccess();
  HRESULT         EnsureParentAreKeys(const DSYSysPath& iKeyPath);
  DSYSysJSONValue AddJSONValue(int iDataType, DSYSysJSONValue iValueData);
#endif

#ifdef _WINDOWS_SOURCE
  DSYSysRegHKey     m_Key;
#else
  CATFileLockBytes* m_pFileLockBytes;
  DSYSysJSONObject* m_pContent;
#endif

  CATUnicodeString  m_Path;
  void* m_pTracer;

};

#endif  // DSYSysRegKey_H
