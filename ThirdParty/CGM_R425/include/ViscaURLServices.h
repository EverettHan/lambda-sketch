#ifndef __VISCAURLSERVICE_H__
#define __VISCAURLSERVICE_H__

#if defined(__ViscaURLServices)
#define ExportedByViscaURLServices DSYExport
#else
#define ExportedByViscaURLServices DSYImport
#endif
#include "DSYExport.h"

#include "CATSysErrorDef.h"
#include "CATUnicodeString.h"

#include <functional>
#include <optional>
#include <string>
#include <vector>


template <class StringType>
class ViscaURLServices
{
public:
  struct URLsRequestOptions
  {
    bool fallback = false;
  };
  static const URLsRequestOptions kDefaultRequestOptions;

  struct RequestedDerivedObject
  {
    StringType source;
    StringType boid;
    StringType type;
  };
  static HRESULT CreateURLsRequestBody(const std::vector<RequestedDerivedObject>& iRequestedObjects, StringType& oBody, const URLsRequestOptions& iOptions = kDefaultRequestOptions);

  static bool IsURLFetchCompatible(const StringType& iUrl);

  struct BatchOptions
  {
    bool allowPartial = false;
    bool fallback = false;
    StringType emptyFallback;
    bool checkVersion = false;
  };
  static const BatchOptions kDefaultBatchOptions;
  
  static HRESULT CreateBatchURLAndBody(const std::vector<StringType>& iUrls, StringType& oUrl, StringType& oBody, const BatchOptions& iOptions = kDefaultBatchOptions);

  struct FetchOptions
  {
    size_t splitTargetedSize = 0;
    bool allowPartial = false;
    bool checkVersion = false;
  };
  static const FetchOptions kDefaultFetchOptions;

  static HRESULT CreateFetchURLAndBody(const std::vector<StringType>& iUrls, const std::vector<StringType>& iCorrelationIDs, StringType& oUrl, StringType& oBody, const FetchOptions& iOptions = kDefaultFetchOptions);

  struct RequestedObject
  {
    StringType source;
    StringType boid;
    StringType filename;
    StringType format;
    StringType version;
    StringType type;
    std::optional<std::size_t> element;
  };
  static HRESULT GetRequestedObjectFromURL(const StringType& iUrl, StringType& oTenant, RequestedObject& oDerivObj);
  static HRESULT GetAccessKeyFromRequestedObject(const RequestedObject& iDerivObj, StringType& oAccessKey);
  static HRESULT GetAccessKeyFromURL(const StringType& iUrl, StringType& oAccessKey);

  struct Header
  {
    StringType name;
    StringType value;
  };

  struct URLOnObject : public RequestedObject
  {
    StringType derivedVersion;
    StringType url;
  };
  static HRESULT DecodeURLsRequestAnswer(const StringType& iAnswer, std::vector<URLOnObject>& oStaticURLs);

  struct DynamicURLOnObject : public URLOnObject
  {
    std::vector<Header> headers;
  };
  static HRESULT DecodeBatchAnswer(const StringType& iAnswer, std::vector<DynamicURLOnObject>& oDynamicURLs);

  struct MergedElement
  {
    std::optional<std::size_t> element;
    std::size_t index;
  };
  struct MergedURLOnObjects : public DynamicURLOnObject
  {
    std::vector<MergedElement> elements;
    std::optional<std::size_t> contentSize = 0;
  };
  static HRESULT MergeBatchAnswer(const std::vector<DynamicURLOnObject>& iDynamicURLs, std::vector<MergedURLOnObjects>& oMergedURLs, const std::size_t iSplitTargetedSize = 0);

  struct FCSMedia
  {
    StringType url;
    StringType ticket;
  };
  struct FetchObject : public RequestedObject
  {
    StringType correlationID;
    StringType emptyReason;
  };
  static HRESULT DecodeFetchAnswer(const StringType& iAnswer, std::vector<FCSMedia>& oMedias, std::vector<FetchObject>& oMissingFiles);

  struct InaccurateObject : public FetchObject
  {
    StringType derivedVersion;
    StringType updatedAccessURL;
  };
  static HRESULT DecodeFetchAnswer(const StringType& iAnswer, std::vector<FCSMedia>& oMedias, std::vector<FetchObject>& oMissingFiles, std::vector<InaccurateObject>& oInaccurateFiles);

private:
  enum EField
  {
    eTenant = 0,
    eSource,
    eBOID,
    eFilename,
    eFormat,
    eElement,
    eVersion,
    eType,
    eTimestamp,
    eSignature,
    eCorrelationID,
    eEmptyReason,
    eDerivedVersion,
    eUpdatedAccessURL,
    eTicketWrappers,
    eTicket,
    eURL,
    eHeaders,
    eName,
    eValue,
    eURLs,
    eFiles,
    eFilesNotFound,
    eInaccurateFiles,
    eField_Count
  };
  static StringType s_JSONField[eField_Count];
  static unsigned int s_JSONFieldLen[eField_Count];
  static StringType s_URLField[eField_Count];
  static bool s_NumericField[eField_Count];
  static bool s_ArrayField[eField_Count];

  enum FField
  {
    fTenant = (1 << eTenant),
    fSource = (1 << eSource),
    fBOID = (1 << eBOID),
    fFilename = (1 << eFilename),
    fFormat = (1 << eFormat),
    fElement = (1 << eElement),
    fVersion = (1 << eVersion),
    fType = (1 << eType),
    fTimestamp = (1 << eTimestamp),
    fSignature = (1 << eSignature),
    fCorrelationID = (1 << eCorrelationID),
    fEmptyReason = (1 << eEmptyReason),
    fDerivedVersion = (1 << eDerivedVersion),
    fUpdatedAccessURL = (1 << eUpdatedAccessURL),
    fTicket = (1 << eTicket),
    fURL = (1 << eURL),
    fHeaders = (1 << eHeaders),
    fName = (1 << eName),
    fValue = (1 << eValue),

    fMandatoryAccessKey = (fSource|fBOID|fVersion|fType),
    fAccessKey = (fMandatoryAccessKey|fFilename|fFormat|fElement),
    fSecuredAccessKey = (fAccessKey|fTimestamp|fSignature),
    fURLKey = (fAccessKey|fURL),
    fFileKey = (fURLKey | fHeaders),
    fHeader = (fName | fValue),
    fMedia = (fTicket|fURL)
  };
  
  static StringType GetJSONField(const StringType& iParam, unsigned int iFields);
  static bool GetURLField(const StringType& iParam, unsigned int iFields, EField& oField, StringType& oValue);

  static int GetJSONPropertyValue(const StringType& iJSON, unsigned int iJSONLen, unsigned int iPropPos, unsigned int iPropLen);
  static int SearchJSONPropertyInScope(const StringType& iJSON, unsigned int iScopePos, int& ioScopeEnd, EField iName);
  static int GetJSONNextArrayObject(const StringType& iJSON, unsigned int iArrayPos, int& ioArrayEnd, unsigned int iCurObjectPos);
  static unsigned int CopyJSONPropertyStringValuesInScope(const StringType& iJSON, unsigned int iScopePos, int& ioScopeEnd, StringType* const oValues[eField_Count]);
  static unsigned int CopyJSONPropertyNumberValuesInScope(const StringType& iJSON, unsigned int iScopePos, int& ioScopeEnd, std::optional<std::size_t>* const oValues[eField_Count]);

  template<class ElementType>
  static void ReferElementStrings(ElementType& iElement, StringType* oValues[eField_Count]);

  template<class ElementType>
  static void ReferElementNumbers(ElementType& iElement, std::optional<std::size_t>* oValues[eField_Count]);

  template<class ElementType>
  static bool CopyJSONArrayElements(const StringType& iJSON, int iScopePos, int& ioScopeEndPos, EField iName, unsigned int iFieldsCheck, std::vector<ElementType>& oElements,
                                    const std::vector<std::function<unsigned int(const StringType& iJSON, int iScopePos, int& ioScopeEndPos, ElementType& oElement)>>& iSubMngt);
};

#if defined(_ANDROID_SOURCE) || defined(_DARWIN_SOURCE)
// Ugly by-pass for link issues on Clang platforms which implies that we do not export the template specialization in a library.
#include "ViscaURLServices.hpp"
#else
template class ExportedByViscaURLServices ViscaURLServices<std::string>;
template class ExportedByViscaURLServices ViscaURLServices<CATUnicodeString>;
#endif

#endif
