/**
* @level Private
* @usage U3
*/

#ifndef VVSDummyPowerIOVSCpt_H
#define VVSDummyPowerIOVSCpt_H

#include "VVSDummyVaultSite.h"
#include "VVSDummyVSCpt.h"
#include "CATUnicodeString.h"
#include "CATVVSUrl.h"

class CATILockBytes2;
class CATVVSUnicodeStringHashtable;

class ExportedByVVSDummyVaultSite VVSDummyPowerIOVSCpt: public VVSDummyVSCpt
{
public:

	VVSDummyPowerIOVSCpt(const CATUnicodeString & iLockFileName, const CATUnicodeString & iDeleteCacheFile);
	virtual ~VVSDummyPowerIOVSCpt ();

	virtual HRESULT Get_Property(const CATUnicodeString& iKey, CATUnicodeString& iValue) const ;
	virtual HRESULT Set_Property(const CATUnicodeString& iKey, const CATUnicodeString& iValue) const 
    { return _Set_Property(iKey,iValue,FALSE);}

	//CATIVVSSoftComponentLifeCycle
	virtual HRESULT Init (const CATVVSUnicodeStringHashtable&  iInitParameters ) ;
  virtual HRESULT Shutdown (const CATVVSUnicodeStringHashtable&  iShutdownParameters ) ;
	
protected:

  HRESULT _Set_Property(const CATUnicodeString& iKey, const CATUnicodeString& iValue, CATBoolean iForce) const ;

  VVSDummyPowerIOVSCpt (const VVSDummyPowerIOVSCpt &) = delete ;
	VVSDummyPowerIOVSCpt& operator=(const VVSDummyPowerIOVSCpt&) = delete ;

  CATUnicodeString              _CachePrefix;    
  CATUnicodeString              _LifeCycleBehaviour;
  CATUnicodeString              _LockFileName;
  CATUnicodeString              _DeleteCacheFile;
  CATVVSUrl                     _PowerIOCacheUrl;
  CATILockBytes2*               _pLockBytes;
  CATVVSUnicodeStringHashtable* _Properties;
  CATBoolean                    _IsToBeLocked;  
  CATBoolean _IsTransient;

private:

#ifdef _WINDOWS_SOURCE
  static HRESULT CATRemoveDirectoryContent(CATUnicodeString * iDirToRemove , CATUnicodeString & oErrorString);
#endif
	
};

#endif

