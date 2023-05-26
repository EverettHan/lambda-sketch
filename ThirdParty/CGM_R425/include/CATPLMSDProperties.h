
#ifndef CATPLMSDProperties_H
#define CATPLMSDProperties_H

#include "CATOMY.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxKeyString.h"
#include "CATOmxAny.h"
#include "CATUnicodeString.h"
#include "CATVVSUrl.h"
#include "CATOmxArray.h"
#include "CATIAV5Level.h"

class CATWOmxBinaryStream;
struct CATPLMStreamDescriptorKeys
{
  CATPLMStreamDescriptorKeys();
  ~CATPLMStreamDescriptorKeys();

  const CATOmxKeyString Format;
  const CATOmxKeyString Role;
  const CATOmxKeyString LateType;
  const CATOmxKeyString PersistencyType;
  const CATOmxKeyString PersistencyName;
  const CATOmxKeyString MarkStamp;
  const CATOmxKeyString SynchroStamp;
  const CATOmxKeyString IsLargeFile;
  const CATOmxKeyString Url;
  const CATOmxKeyString VvsUrl;
  const CATOmxKeyString Size;
};

ExportedByCATOMY const CATPLMStreamDescriptorKeys& sd_keys();

//#ifndef CATIAR420
ExportedByCATOMY CATBoolean PersNameFix();
//#endif

#define PersistencyNameNULL NULL
#define PersistencyTypeNULL NULL
#define SynchroStampNULL    CATOmxAny()
#define LargeFileNULL       -1

#define OMB_VCS_IR_843104

class ExportedByCATOMY CATPLMSDProperties
{

public:
  CATPLMSDProperties();
  CATPLMSDProperties(const CATOmxKeyValueBlock& iBlock);

  CATOmxAny GetProperty(const CATOmxKeyString& iKey) const;

  HRESULT GetSDKey(CATOmxKeyString& oFormat, CATUnicodeString& oRole, CATUnicodeString& oPersistencyName) const;
  HRESULT GetPropertyAsString(const CATOmxKeyString& iKey, CATBoolean allowEmpty, CATUnicodeString& oValue) const;
  HRESULT GetPropertyAsInt(const CATOmxKeyString& iKey, int& oValue) const;
  HRESULT GetPropertyAsInt64(const CATOmxKeyString& iKey, CATLONG64& oValue) const;

  void SetBlock(const CATOmxKeyValueBlock& iBlock);
  CATOmxKeyValueBlock GetBlock() const;

  HRESULT SetProperty(const CATOmxKeyString& iKey, CATOmxAny iValue);


  CATPLMSDProperties(const CATPLMSDProperties& iCopy);
  CATPLMSDProperties& operator=(const CATPLMSDProperties& iCopy);
  inline CATBoolean operator==(const CATPLMSDProperties& iCompareTo) { return _CompareSd(iCompareTo) == 0; }
  inline CATBoolean operator!=(const CATPLMSDProperties& iCompareTo) { return _CompareSd(iCompareTo) != 0; }


  static CATOmxAny BuildAnyFromUrl(const CATVVSUrl& iUrl);
  static HRESULT GetUrlFromAny(const CATOmxAny& iAny, CATVVSUrl& oUrl);

  static HRESULT BuildSDBlock(const CATOmxKeyString& iFormat, const CATUnicodeString& iRole, const CATUnicodeString& iPersistencyName,
    const CATUnicodeString& iLateType, const CATUnicodeString& iPersistencyType,
    const CATOmxAny& iMarkStamp, const CATOmxAny& iSynchroStamp,
    int iLargeFile, CATOmxKeyValueBlock& oBlock);
  static HRESULT BuildSDBlock(const CATOmxKeyString& iFormat, const CATUnicodeString& iRole, const CATUnicodeString& iPersistencyName,
    const CATUnicodeString& iLateType, const CATUnicodeString& iPersistencyType,
    const CATOmxAny& iMarkStamp, const CATOmxAny& iSynchroStamp,
    int iLargeFile, CATLONG64 iSize, CATOmxKeyValueBlock& oBlock);

  static CATOmxKeyString BuildFormat(int iFormat);

  static CATBoolean ToInt(const CATUnicodeString& iString, int& oInt);
  // return true if stamp is correct.
  static CATBoolean StampStringToInt(const CATUnicodeString& iString, int& oStamp);

  HRESULT Stream(CATWOmxBinaryStream& ioStream) const;
  HRESULT Unstream(CATWOmxBinaryStream& iStream);
#ifdef CATIAR420
  HRESULT MarshalSD(CATUnicodeString& the_SD, CATBoolean iIsImport = FALSE) const;
  HRESULT UnmarshalSD(const CATUnicodeString& iValue);
#else // youpi !
  HRESULT MarshallSD(CATUnicodeString& the_SD, CATBoolean iIsImport = FALSE) const;
  HRESULT UnmarshallSD(const CATUnicodeString& iValue);
#endif
  /**
   Returns the Url
  */
  HRESULT GetUrl(CATUnicodeString& oUrl) const;
  HRESULT GetUrl(CATVVSUrl& oUrl) const;
  HRESULT SetUrl(const CATUnicodeString& iUrl);
  HRESULT SetUrl(const CATVVSUrl& iUrl);

  /**
  *
  */
  HRESULT GetFCSFileName(CATUnicodeString iPhysicalId, CATUnicodeString& oFCSFileName) const;

  /**
  * Activated since R418
  * => Allow streams (Archive role) on entities
  */
  static CATBoolean IsStreamsOnEntityActivated();

  static CATBoolean Md5OnStampActivated();

private:

  static CATBoolean _ToInt(const CATUnicodeString& iString, int& oInt, CATBoolean iSilent);

  /*
  * Searchs the given character, in the given input string, ignoring attribute values.
  * Suppose we search iCharSearched == ')'
  * Attributes are delimited by quote: 'x'
  * When you want to write a ' (simple quote) in a string, you have to write '' (double quote)
  * Suppose we have iValue == ('1_a_)1.cgr')
  * Position returned for iCharSearched == ')' should be: 13 and not 6 !
  * If not found position -1 is returned.
  */
  int _SearchCharacterOutOfAttrValue(const CATUnicodeChar& iCharSearched, const CATUnicodeString& iValue, int iSearchStartIndex);

  /*
  * Checks the input closing quote (at iStartIndex) is valid.
  * Used for legacy V5 SD validation:
  * File name may contain quote ('). In this case, the quote has to be escaped, using double simple quote: ''.
  * A simple quote must be either an opening or closing quote. Closing quote must be followed by:
  *   - spaces
  *   - comma
  *   - closing parenthesis
  *
  * Examples:
  *   SDv1(1,'',NonCATIADocument,1502351331,'cgr','8550_3MSF_85531.cgr’) -> OK
  *   SDv1(1,'',NonCATIADocument,1502351331,'cgr','8550_3MSF_’’85531.cgr’) -> OK
  *   SDv1(1,'',NonCATIADocument,1502351331,'cgr','8550_3MSF_’85531.cgr’) -> NOK
  */
  bool _IsValidClosingQuote(const CATUnicodeString& iValue, int iClosingQuoteIndex);

  int _GetSDVersion() const;

  int _CompareSd(const CATPLMSDProperties&) const;

  CATOmxKeyValueBlock _Block;
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMSDProperties>::manager();
#endif
