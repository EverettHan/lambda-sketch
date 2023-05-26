// COPYRIGHT Dassault Systemes 2011
//=============================================================================
//
// CATVidURL.h
// Header definition of CATVidURL
//
//=============================================================================
//  Aug 2011  Creation: LD5
//=============================================================================
#ifndef CATVidURL_H
#define CATVidURL_H

#include <VisuDialog.h>
#include <CATBoolean.h>
#include <CATUnicodeString.h>
#include <CATUnicodeChar.h>
#include <CATSYPHashMap.h>
#include <CATVid.h>
//-----------------------------------------------------------------------------
/** @ingroup VIDCore
 *
 * A class to build, parse, decompose and validate URLs. It supports RFC 3986.  
 *
 *
 * @par Notations
 *
 * @par
 * In a production rule, <tt> X </tt> is a variable and <tt> "x" </tt> is a literal.
 *
 * @par
 * @li <tt> A B </tt> means "A then B"
 * @li <tt> *(...) </tt> means "any number of ..."
 * @li <tt> n(...) </tt> means "exactly n ...", with n a natural number
 * @li <tt> [...] </tt> means "0 or 1 ..."
 * @li <tt> ( A | B ) </tt> means "A or B"
 * @li <tt> DIGIT </tt> is a digital character
 * @li <tt> ALPHA </tt> is an alphabetic character
 * @li <tt> ALPHANUM = ( ALPHA | DIGIT ) </tt>
 * @li <tt> HEXDIG </tt> is an hexadecimal number (case-insensitive)
 * @li <tt> H16 = HEXDIG [ HEXDIG ] [ HEXDIG ] [ HEXDIG ] </tt>
 * @li <tt> subdelim = ( "!" | "$" | "&" | "'" | "(" | ")" | "*" | "+" | "," | ";" | "=" ) </tt>
 * @li <tt> unreserved = ( ALPHA | DIGIT | "-" | "." | "_" | "~" ) </tt>
 *
 *
 * @par Global structure
 *
 * @par
 * The structure of a valid URL is:
 *
 * @par
 * <tt> Scheme ":" ["//" [UserInfo "@"] Host [":" Port]] Path ["?" Query ] ["#" Fragment] </tt>
 *
 * @par
 * With:
 * @li @c Scheme : mandatory. Must be terminated by scheme delimiter ":".
 * @li @c UserInfo : Optional. If not empty, is terminated by user 
 * information postfix "@".
 * @li @c Host : Optional.
 * @li @c Port : Optional. If not empty, begins with port prefix ":".
 * @li @c Path : Optional.
 * @li @c Query : Optional. If not empty, begins with query prefix "?" (ie. 
 * CATUnicodeString("\?")).
 * @li @c Fragment : Optional. If not empty, begins with fragment prefix "#".
 *
 *
 * @par Decomposing a URL
 *
 * @par
 * For instance: 
 *
 * @par
 * <tt> "http://sisyphus:eTernItY99:-D@ftp.localhost.com:2021/TODO/2011/11/24?type=map&title=hill#top" </tt>
 *
 * @par
 * is composed of:
 * @li @c Scheme : "http"
 * @li @c UserInfo : "sisyphus:eTernItY99:-D"
 * @li @c Host : "ftp.localhost.com"
 * @li @c Port : "2012"
 * @li @c Path : "/TODO/2011/11/24"
 * @li @c Query : "type=map&title=hill"
 * @li @c Fragment : "top"
 *
 *
 * @par Authority
 *
 * @par
 * Authority covers @c UserInfo, @c Host and @c Port . 
 *
 *
 * @par Scheme
 *
 * @par
 * The scheme of a URL is the part at the beginning of the 
 * URL, before the ":" character -- for instance, "file", "http", "mailto"...
 *
 * @par
 * A scheme complies to the case-insensitive expression: 
 *
 * @par
 * <tt> scheme = ALPHA *( ALPHANUM | "+" | "-" | "." ) </tt>
 * 
 *
 * @par UserInfo
 *
 * @par
 * The user information in a URL consists in a username and eventual 
 * information about how to access the resource, for instance, "user:password".
 *
 * @par
 * A user information complies to the expression:
 *
 * @par
 * <tt> *( unreserved | subdelim | ":" | ( "%" HEXDIG HEXDIG )) </tt>
 *
 *
 * @par Host
 *
 * @par
 * The host part of an URL is either a litteral hostname or an IP address.
 *
 * @par
 * @li <strong> Hostname: </strong><br/>
 * <tt> *( unreserved | ":" | ( "%" HEXDIG HEXDIG )) </tt>
 * @li <strong> IPV4 address: </strong><br/>
 * To provide an IPV4 address, set the host as: <br/> 
 * <tt> IPV4 = N "." N "." N "." N </tt><br/>
 * with <tt> N </tt> a natural number between 0 and 255 containing no trailing 
 * 0. <br/>
 * For instance, "255.15.148.0" is valid, "255.015.148.000" is not.
 * @li <strong> IPV6 address: </strong><br/>
 * To provide an IPV6 address, set the host as "[" + IPV6Address + "]". This 
 * class supports omission. For instance, "fe80:0:0:0:200:f8ff:fe21:67cf" is 
 * equivalent to "fe80::200:f8ff:fe21:67cf". <br/>
 * An IPV6 address complies to any of the following expressions: <br/>
 * <tt> 7(H16 ":") H16 </tt><br/>
 * <tt> 6(H16 ":") IPV4 </tt><br/>
 * <tt> n(H16 ":") ":" m(H16 ":") H16  </tt>  with <tt> m + n < 7 </tt><br/>
 * <tt> n(H16 ":") ":" m(H16 ":") IPV4  </tt>  with <tt> m + n < 6 </tt><br/>
 * with <tt> n </tt> and <tt> m </tt> two natural numbers. <br/>
 * @li <strong> IPVFuture address: </strong><br/>
 * To provide an IPVFuture address, set the host as <br/>
 * <tt> "[v" HEXDIG "." IPAddressBody "]" </tt><br/>
 * with <tt> HEXDIG </tt> being the version number and: <br/>
 * <tt> IPAddressBody = [ unreserved | subdelim | ":" ] *( unreserved | subdelim | ":" ) </tt>
 * 
 *
 * @par Port
 *
 * @par
 * The port number is a digital number:
 * 
 * @par
 * <tt> *DIGIT </tt>
 * 
 *
 * @par Path
 *
 * @par
 * The path contain hierarchical information to access the resource.
 * The path to the resource complies to the expression:
 *
 * @par
 * <tt> *("/" | unreserved | subdelim | ":" | "@" | ( "%" HEXDIG HEXDIG )) </tt>
 *
 * @par
 * like "//path/to/resource/filename.ext", "Three-Lettered-Trigram@3ds.com", 
 * "./relative/path/to/success", "../tortuous/./path/towards/enlightenment". 
 * If the authority is not empty, the path must either be empty or begin with 
 * "/". If the authority is empty, the path cannot begins with "//".
 *
 *
 * @par Query
 *
 * @par
 * The query contains additional non-hierarchical information, such as
 * "type=book&category=magic&language=elvish-gaelic" or 
 * "animal=phoenix;recipe=honey_soy_grilled_phoenix". It complies to the 
 * expression:
 *
 * @par
 * <tt> *( subdelim | unreserved | "/" | "?" | ( % HEXDIG HEXDIG )) </tt>
 * 
 *
 * @par Fragment
 *
 * @par
 * The fragment identifier component is used for indirect identification of a 
 * secondary resource by reference to a primary resource.
 * It complies to the same expression than the query:
 *
 * @par
 * <tt> *( subdelim | unreserved | "/" | "?" | ( % HEXDIG HEXDIG )) </tt>
 *
 * @par
 * For instance, "chapter-1" and "ingredients" are valid fragments.
 *
 *
 * Source: RFC 3986 (Uniform Resource Identifier: Generic Syntax) <br/>
 * <a href="http://www.ietf.org/rfc/rfc3986.txt"/>
 */
class ExportedByVisuDialog CATVidURL
{
public:

  /**
   * @param i_s string to parse.
   * @param o_sError eventual parsing errors.
   *
   * @return @c TRUE if the input string is valid as a query and a fragment, 
   * @c FALSE else. 
   */
  static CATBoolean IsQueryAndFragment(const CATUnicodeString& i_s, CATUnicodeString& o_sError);
  /**
   * @param i_s string to parse.
   * @param o_sError eventual parsing errors.
   *
   * @return @c TRUE if the input string is a valid hostname, @c FALSE else. 
   */
  static CATBoolean IsHostname(const CATUnicodeString& i_s, CATUnicodeString& o_sError);
  /**
   * @param i_s string to parse.
   * @param o_sError eventual parsing errors.
   *
   * @return @c TRUE if the input string is a valid IPV4 address, @c FALSE 
   * else. 
   */
  static CATBoolean IsIPV4Address(const CATUnicodeString& i_s, CATUnicodeString& o_sError);
  /**
   * @param i_s string to parse.
   * @param o_sError eventual parsing errors.
   *
   * @return @c TRUE if the input string is a valid IPV6 address, @c FALSE
   * else. 
   */
  static CATBoolean IsIPV6Address(const CATUnicodeString& i_s, CATUnicodeString& o_sError);
  /**
   * @param i_s string to parse.
   * @param o_sError eventual parsing errors.
   *
   * @return @c TRUE if the input string is a valid future IP address, @c FALSE 
   * else. 
   */
  static CATBoolean IsIPVFutureAddress(const CATUnicodeString& i_s, CATUnicodeString& o_sError);
  /**
   * @param i_s string to parse.
   * @param o_sError eventual parsing errors.
   *
   * @return @c TRUE if the input string is a valid decimal octet, @c FALSE 
   * else. 
   */
  static CATBoolean IsDecOctet(const CATUnicodeString& i_s);
  /**
   * @param i_c character to consider.
   *
   * @return @c TRUE if the input character is an hexadecimal, @c FALSE else. 
   */
  static CATBoolean IsHexadecimal(const CATUnicodeChar& i_c);
  /**
   * @param i_c character to consider.
   *
   * @return @c TRUE if the input character is an unreserved character, 
   * @c FALSE else. 
   */
  static CATBoolean IsUnreserved(const CATUnicodeChar& i_c);
  /**
   * @param i_c character to consider.
   *
   * @return @c TRUE if the input character is a subdelimiter, @c FALSE else. 
   */
  static CATBoolean IsSubDelim(const CATUnicodeChar& i_c);
  /**
   * @param i_s string to parse.
   * @param i_bOmissionAuthorized @c TRUE if zero omission is authorized, 
   * @c FALSE else.
   *
   * @return @c TRUE if the input string is a set of four hexadecimals, or of
   * four or less hexadecimals in case @c i_bOmissionAuthorized is activated, 
   * @c FALSE else. 
   */
  static CATBoolean IsH16(const CATUnicodeString& i_s, CATBoolean i_bOmissionAuthorized = FALSE);
  /**
   * @param i_s string to parse.
   *
   * @return @c TRUE if the input string is an LS32 as described in RFC 3986.
   */
  static CATBoolean IsLS32(const CATUnicodeString& i_s);

  /**
   * Default constructor. Builds an empty URL.
   */
  CATVidURL();
  /**
   * Constructor. If the input URL is not valid, the URL returned by #GetURL
   * will contain only the valid components that have been recognized in the
   * input URL, if any (see the class description of @ref CATVidURL).
   * 
   * @param i_sURL an input URL.
   *
   * @see CATVidURL
   */
  CATVidURL(const CATUnicodeString& i_sURL);
  /**
   * Constructor. Builds an URL from all its different parts. The URL returned
   * by #GetURL will be computed only from the valid input parts (see the class
   * description of @ref CATVidURL).
   *
   * @param i_sScheme string representation of the CATVid#Scheme of the URL.
   * @param i_sUserInfo string representation of the CATVid#UserInfo of the 
   * URL.
   * @param i_sHost string representation of the CATVid#Host of the URL.
   * @param i_sPort string representation of the CATVid#Port of the URL.
   * @param i_sPath string representation of the CATVid#Path of the URL.
   * @param i_sQuery string representation of the CATVid#Query of the URL.
   * @param i_sFragment string representation of the CATVid#Fragment of the 
   * URL.
   *
   * @see CATVidURL
   * @see CATVid#URLParts
   */
  CATVidURL(const CATUnicodeString& i_sScheme,
            const CATUnicodeString& i_sUserInfo,
            const CATUnicodeString& i_sHost,
            const CATUnicodeString& i_sPort,
            const CATUnicodeString& i_sPath,
            const CATUnicodeString& i_sQuery,
            const CATUnicodeString& i_sFragment);
  /**
   * Destructor.
   */
  virtual ~CATVidURL();
  /**
   * Copy constructor. The @c CATUnicodeString representing the URL of the 
   * @c CATVidURL to copy is copied into our new @c CATVidURL instance.
   *
   * @param i_original The @c CATVidURL to copy.
   */
  CATVidURL(const CATVidURL &i_original);
  /**
   * Assignment operator. The @c CATUnicodeString representing the URL of the 
   * @c CATVidURL to copy is copied into our @c CATVidURL instance.
   *
   * @param i_original The @c CATVidURL to be assigned to ours.
   *
   * @return The assigned @c CATVidURL.
   */
  CATVidURL& operator=(const CATVidURL& i_original);
  /**
   * Equal operator. Two @c CATVidURL are equal if the @c CATUnicodeString that
   * represents their URL are equal.
   *
   * @param i_original The @c CATVidURL to be compared with ours.
   *
   * @return @c TRUE if the two URLs are equal, @c FALSE else.
   */
  CATBoolean operator==(const CATVidURL& i_right) const;
  /**
   * Not-equal operator.
   *
   * @param i_original The @c CATVidURL to be compared with ours.
   *
   * @return @c FALSE if the two URLs are equal, @c TRUE else.
   *
   * @see #operator==
   */
  CATBoolean operator!=(const CATVidURL& i_right) const;
  /**
   * @return The URL string.
   */
  const CATUnicodeString GetURL() const;
  /**
   * @return The relative URL, ie. the URL without its scheme.
   */
  const CATUnicodeString GetRelativeURL() const;
  /**
   * @return The authority of the URL, ie. [ UserInfo "@" ] Host [":" Port].
   */
  const CATUnicodeString GetAuthority() const;
  /**
   * @param i_ePart the URL part that you are interrested in.
   * 
   * @return a string representation of the URL part asked for.
   */
  const CATUnicodeString GetPart(CATVid::URLPart i_ePart) const;
  /**
   * @param i_ePart Identifier for a part of the URL (@ref CATVid#URLPart).
   *
   * @return @c TRUE if the URL possesses such a (non-empty) part, @c FALSE 
   * else. Note that if the part was not valid at URL instanciation, it is
   * empty and @ref #HasPart will return @c FALSE.
   */
  CATBoolean HasPart(CATVid::URLPart i_ePart) const;
  /**
   * @return @c TRUE if the URL is valid, @c FALSE else.
   */
  CATBoolean IsValid() const;
  /**
   * @param i_ePart Identifier for a part of the URL (@ref CATVid#URLPart).
   *
   * @return @c TRUE if the specified URL part of the URL is valid, @c FALSE 
   * else.
   */
  CATBoolean IsPartValid(CATVid::URLPart _eURLPart) const;
  /**
   * If the URL is not valid, it has an error message. If it is valid, this 
   * error message is empty.
   *
   * @return a global error message for the entire URL, including error
   * messages for each individual parts.
   */
  const CATUnicodeString GetErrorMsg() const;
  /**
   * If a URL part is not valid, it has an error message. If it is valid, this 
   * error message is empty. 
   *
   * @param i_ePart the URL part that you are interested in.
   *
   * @return the error message for the specified URL part.
   */
  const CATUnicodeString GetPartErrorMsg(CATVid::URLPart i_ePart) const;

private:
  /**
   * Initialize the URL table and associated error messages table as soon as
   * the URL is not empty.
   *
   * @see #InitMapWithPartsKeys
   */
  void Init();
  /**
   * Initialize an internal hash map with all URL parts identifiers and empty 
   * strings.
   *
   * @param identifier for which internal map to initialize (0 for the map of
   * URL parts, 1 for the map of URL parts errors).
   *
   * @see CATVid#URLPart
   */
  void InitMapWithPartsKeys(int i_iMapType);
  /**
   * Break the internal URL into several URL parts and parse each of them with 
   * #ParsePart.
   *
   * @see #ParsePart
   */
  void URLToParts();
  /**
   * Build the internal URL from all parts saved in the URL parts map.
   */
  void PartsToURL();
  /**
   * Parse a specific URL part and save it into the URL parts map if it is 
   * valid. Else, fill in errors in the URL parts errors map.
   *
   * @param i_ePart identifier for an URL part.
   * @param i_sPart string reprensentation to interpret as an URL part of type 
   * @c i_ePart.
   */
  void ParsePart(int i_ePart, const CATUnicodeString& i_sPart);
  /**
   * Add a parsing error for a specific URL part.
   *
   * @param i_ePart identifier for an URL part.
   * @param i_sPart error of parsing corresponding to the URL part of type 
   * @c i_ePart.
   */
  void AddPartError(CATVid::URLPart i_ePart, const CATUnicodeString i_sPart, const CATUnicodeString& i_sPartErrorMsg);
  /**
   * Appends a new global parsing error to the global error message of the URL.
   *
   * @param i_sGlobalErrorMsg the error to append.
   */
  void AddGlobalError(const CATUnicodeString& i_sGlobalErrorMsg);
  /**
   * @return @c TRUE if the URL is an empty string.
   */
  CATBoolean IsEmpty() const;

private:
  /**
   * The URL.
   */
  CATUnicodeString _sURL;
  /**
   * The global error message associated to the input URL at instanciation, 
   * including all URL-part-specific error messages contained in 
   * @ref #_PartsErrorMsg.
   */
  CATUnicodeString _sErrorMsg;
  /**
   * Map of all the valid parts that compose #_sURL.
   */
  CATSYPHashMap<int, CATUnicodeString> _Parts;
  /**
   * Map of all errors for specific parts contained in #_Parts. 
   */
  CATSYPHashMap<int, CATUnicodeString> _PartsErrorMsg; 
};
//-----------------------------------------------------------------------------

/* TODO LD5
[URL] URL builder. Host = "", supporter file:///e:/monpath. % et escaping. 
Cas particuliers https://fr.wikipedia.org/wiki/Uniform_Resource_Locator. */

#include <CATSYPFactoryResult.h>
extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidURLFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidURLSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif
