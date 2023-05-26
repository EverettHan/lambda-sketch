/* -*-c++-*- */
/**
 * @Level Protected
 * @Usage U2
 **/
//=================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=================================================================================

#ifndef CATVVSUrl_H
#define CATVVSUrl_H

#include "CATUnicodeString.h"
#include "CATIAV5Level.h"
#include "CATOmxKeyString.h"
#include "CATOmxUTF8String.h"
#include "CATVVSNetBase.h"
#include "CATVVSUnicodeStringHashtable.h"
#include "CATOmxArray.h"

#ifdef CATIAR421
#define SiteAndProtOnKeyStr
#endif

// Manage unicode NLS chars in URL identifier
#define vvsAllowUnicodeId    0x01

/**
 * Uniform resource locator.
 */
class ExportedByVVSNetBase CATVVSUrl
{
public:

  /**
   * Constructs a new URL which is empty and not set.
   * Used for Objects that have a member which is a <code>CATVVSUrl</code>.
   */
  CATVVSUrl () ;

  /**
   * Constructs a new URL
   * @param iProtocol
   *   The protocol corresponds to the type of the vault access
   * @param iSite
   *   The Identifier of the site access ( = the instance of the vault access)
   * @param iIdentifier
   *   The identifier of the stream required
   */
#ifdef SiteAndProtOnKeyStr
  CATVVSUrl (const CATOmxKeyString& iProtocol, const CATOmxKeyString& iSite,const CATUnicodeString& iIdentifier);
#else
  CATVVSUrl (const CATUnicodeString& iProtocol, const CATUnicodeString& iSite,const CATUnicodeString& iIdentifier);
#endif

  /**
   * Constructs a new URL
   * @param iProtocol
   *   The protocol corresponds to the type of the vault access
   * @param iSite
   *   The Identifier of the site access ( = the instance of the vault access)
   * @param iIdentifier
   *   The identifier of the stream required
   * @param iSearchPart
   *   The search part of the url ( after the ? ) : this piece is optional
   * @param iUsePolicy
   *   0x01: Manage unicode NLS chars in URL identifier  : this piece is optional
   */
#ifdef SiteAndProtOnKeyStr
  CATVVSUrl (const CATOmxKeyString& iProtocol, const CATOmxKeyString& iSite,const CATUnicodeString& iIdentifier,const CATUnicodeString& iSearchPart);
#else
  CATVVSUrl (const CATOmxKeyString& iProtocol, const CATOmxKeyString& iSite,const CATUnicodeString& iIdentifier,const CATUnicodeString& iSearchPart);
  CATVVSUrl (const CATUnicodeString& iProtocol, const CATUnicodeString& iSite,const CATUnicodeString& iIdentifier,const CATUnicodeString& iSearchPart);
#endif
  CATVVSUrl(const CATOmxKeyString& iProtocol, const CATOmxKeyString& iSite, const CATUnicodeString& iIdentifier, const unsigned char iUsePolicy);

  /**
   * Constructs a new URL
   * @param iSpec
   *   The specification of the url which has the form of
   *   protocol://site/identifier?search_part
   */
  CATVVSUrl (const CATUnicodeString& iSpec);

  /**
   * Copy Constructor
   * @param iURL
   *   The url to copy
   */
  CATVVSUrl (const CATVVSUrl& iURL);


  ~CATVVSUrl() ;

  /**
   * Returns if the URL is set or not.
   * @return
   *   <ul>
   *   <li><code>TRUE</code>: the URL is set</li>
   *   <li><code>FALSE</code>: the URL is not set</li>
   *   </ul>
   */
  CATBoolean IsSet() const;

  /**
   * Returns the Protocol
   * @return
   *   The Protocol
   */
  inline const CATOmxKeyString&  GetProtocolKeyString() const {return _Protocol;}
  inline const CATUnicodeString& GetProtocol() const {return _Protocol.asCUS();}
  
  /**
   * Returns the Site
   * @return
   *   The site
   */
  inline const CATOmxKeyString &GetSiteKeyString() const {return _Site;}
  inline const CATUnicodeString &GetSite() const {return _Site.asCUS();}

  /**
   * Returns the Identifier
   * @return
   *   The Identifier
   */
  inline const CATUnicodeString &GetIdentifier()       const {return _Identifier;}

  /**
   * Returns the SearchPart
   * @return
   *   The SearchPart
   */
  const CATUnicodeString &GetSearchPart() const ;

  /**
   * Converts the URL as a string.
   * @param oURLAsString
   *   The returned string.
   * @return
   *   <ul>
   *   <li><code>S_OK</code>: the URL is set so the returned string is valid.</li>
   *   <li><code>S_FALSE</code>: the URL is not set so the the string is not valid ("fail").</li>
   *   </ul>
   */
  HRESULT ConvertToString(CATUnicodeString &oURLAsString) const;

  /**
   * Returns the SearchPart as a Hashtable in order to find
   * directly the key values ( ?key1=value1&key2=value2&key3=value3
   * @return
   *   The SearchPart as a Hashtable
   */
  HRESULT GetSearchPartAsHashtable(CATVVSUnicodeStringHashtable& oHashtable) ;

  /**
   * @deprecated V5R16
   * @nodoc
   * Returns the Complete URL as a String
   * @return
   *   The Complete URL
   */
  CATUnicodeString ToUnicodeString() const  ;

  /** 
  * Equal operator
  * @param iUrl [in]
  *   The URL to test with this object.
  * @return
  *	<UL>
  *   <LI><code>TRUE</code>: The 2 URL are equal</LI>
  *   <LI><code>FALSE</code>: The 2 URL are different</LI>
  * </UL>
  */
  CATBoolean operator == (const CATVVSUrl& iUrl) const;

 /** 
  * Different operator
  * @param iUrl [in]
  *   The URL to test with this object.
  * @return
  *	<UL>
  *   <LI><code>TRUE</code>: The 2 URL are different</LI>
  *   <LI><code>FALSE</code>: The 2 URL are equal</LI>
  * </UL>
  */
  inline CATBoolean operator != (const CATVVSUrl& iUrl) const {return !operator==(iUrl);}

  int Compare (const CATVVSUrl& iUrl) const;

  /**
   * @brief Get the Hash Key object
   *
   * @return CATHashKey
   */
  CATHashKey GetHashKey() const ;

  /**
   * @brief Get the Use Policy object
   * 
   * @return Policy object
   */
  inline const unsigned char GetUsePolicy() const { return _UrlUsePolicy; }

private:
  CATOmxKeyString     _Protocol;
  CATOmxKeyString     _Site;
  CATUnicodeString    _Identifier;
  CATUnicodeString    _SearchPart;
  unsigned char       _UrlUsePolicy;
};

// CATOmxDefaultCollecManager<CATVVSUrl> is now exported by CATVirtualVaultSystem
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATVVSUrl>::manager();
template<> ExportedByVVSNetBase CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxArray<CATVVSUrl> >::manager();

#endif
