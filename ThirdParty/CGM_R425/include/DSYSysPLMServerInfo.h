//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013                                          
//===========================================================================                                 
//===========================================================================
//  Creation January 2013                                sip              
//===========================================================================
#ifndef DSYSysPLMServerInfo_h
#define DSYSysPLMServerInfo_h

#include "CATSysPreferenceRepository.h"
#include "CATSettingRepository.h"

class CATUnicodeString;
class CATSysTSUnicodeString;

HRESULT ExportedByJS0SETT DSYSysSetSecurityContext(const CATUnicodeString &iArgValueCTX);
// @deprecated R418
HRESULT ExportedByJS0SETT DSYSysSetSecurityContext(CATSysTSUnicodeString &iArgValueCTX);

class ExportedByJS0SETT DSYSysPLMServerInfo
{
private:
  DSYSysPLMServerInfo();
  ~DSYSysPLMServerInfo();

  CATUnicodeString				         _Alias;
  CATUnicodeString				         _Provider;

public:
  HRESULT		GetURLForKey(const CATUnicodeString& iKey, CATUnicodeString& oURL);
  HRESULT		GetKeyForAlias(const CATUnicodeString& iAlias, CATUnicodeString& oKey);
  HRESULT		GetURLForAlias(const CATUnicodeString& iAlias, CATUnicodeString& oURL);
  HRESULT		GetProviderNameForAlias(const CATUnicodeString& iAlias, CATUnicodeString& oProviderName);
  HRESULT  GetCurURL(CATUnicodeString& oURL);
  HRESULT		GetCurAlias(CATUnicodeString& oAlias);
  HRESULT  GetCurProviderName(CATUnicodeString& oProvider);
  static DSYSysPLMServerInfo*		getInstance();

  //Can only be set by login
  HRESULT		SetCurAlias(const CATUnicodeString& iAlias);

  //Can only be set by login
  HRESULT	 SetCurProviderName(CATUnicodeString& iProvider);

  //Do not use: only used at exit
  static void						releaseInstance();

  //bypass pourri car tharama n'a pas fiat la modification...
  HRESULT		GetProviderNameForAliasForRealMen(const CATUnicodeString& iAlias, CATUnicodeString& oProviderName);

};

#endif

