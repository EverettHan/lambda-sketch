// WARNING: Please do NOT include this file! Use "ViscaURLServices.h" ONLY.

#include "ViscaURLServices.h"

#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>


namespace
{
	// Classes

	class CheckChar
	{
	private:
		CheckChar()
		{
      m_NumericChars['-' / 8] |= (1 << ('-' % 8));
      for (char i = '0'; i <= '9'; i++)
        m_NumericChars[i / 8] |= (1 << (i % 8));
      
			m_BlankChars[' ' / 8] |= (1 << (' ' % 8));
			m_BlankChars['\t' / 8] |= (1 << ('\t' % 8));
			m_BlankChars['\r' / 8] |= (1 << ('\r' % 8));
			m_BlankChars['\n' / 8] |= (1 << ('\n' % 8));
      
			m_ScopeBeginChars['{' / 8] |= (1 << ('{' % 8));
			m_ScopeBeginChars['[' / 8] |= (1 << ('[' % 8));

			m_ScopeEndChars['}' / 8] |= (1 << ('}' % 8));
			m_ScopeEndChars[']' / 8] |= (1 << (']' % 8));
		}

		char m_NumericChars[32] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                                0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
		char m_BlankChars[32] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                              0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
		char m_ScopeBeginChars[32] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                                   0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
		char m_ScopeEndChars[32] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                                 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
		static CheckChar s_Instance;

	public:
		static bool IsNumeric(const char iChar)
		{
			return 0 != (s_Instance.m_NumericChars[iChar / 8] & (1 << (iChar % 8)));
		}

		static bool IsBlank(const char iChar)
		{
			return 0 != (s_Instance.m_BlankChars[iChar / 8] & (1 << (iChar % 8)));
		}
    
    static bool IsScopeBegin(const char iChar)
		{
			return 0 != (s_Instance.m_ScopeBeginChars[iChar / 8] & (1 << (iChar % 8)));
		}
    
    static bool IsScopeEnd(const char iChar)
		{
			return 0 != (s_Instance.m_ScopeEndChars[iChar / 8] & (1 << (iChar % 8)));
		}
	};
	CheckChar CheckChar::s_Instance;

	// Prototypes

	template <class StringType>
	int Find_(const StringType& iInput, const StringType& iSearched, int iStart);

	template <class StringType>
	StringType SubStr_(const StringType& iInput, int iStart, int iLength);

	template <class StringType>
	StringType ToUpper_(const StringType& iInput);

	template <class StringType>
	StringType ToLower_(const StringType& iInput);

	template <class StringType>
	unsigned int Length_(const StringType& iInput);

	template <class StringType>
	const char CharAt_(const StringType& iInput, int iPos);
  
	template <class StringType>
	StringType ToString_(size_t iValue);

  template <class StringType>
  size_t ToNumber_(const StringType& iInput);

	// Generic implementations

	template <class StringType>
	int Find_(const StringType& iInput, const char* iSearched, int iStart)
	{
		return Find_(iInput, StringType(iSearched), iStart);
	}

	template <class StringType>
	bool IsNumeric_(const StringType& iInput)
  {
    unsigned int pos = 0;
    const unsigned int posEnd = Length_(iInput);
    while (pos < posEnd)
    {
      if (!CheckChar::IsNumeric(CharAt_<StringType>(iInput, pos)))
        return false;
			pos++;
    }
    return true;
  }

	template <class StringType, bool Revert>
	int AvoidBlank_(StringType iStr, int iPos, int iEndPos)
	{
		if (Revert)
		{
			while (iPos > iEndPos && CheckChar::IsBlank(CharAt_<StringType>(iStr, iPos)))
				iPos--;
		}
		else
		{
			while (iPos < iEndPos && CheckChar::IsBlank(CharAt_<StringType>(iStr, iPos)))
				iPos++;
		}

		return iPos;
	}

	template <class StringType>
	int FindScopeEnd_(StringType iStr, int iPos, int iEndPos)
	{
    int scopeCount = 0;
    do
    {
      const char charAt = CharAt_<StringType>(iStr, iPos);
      if (CheckChar::IsScopeBegin(charAt))
        scopeCount++;
      else if (CheckChar::IsScopeEnd(charAt))
        scopeCount--;
      iPos++;
    }
    while (iPos < iEndPos && scopeCount > 0);
    return (0 == scopeCount) ? (iPos-1) : -1;
  }

	template <class StringType>
	int CountScopes_(StringType iStr, int iPos, int iEndPos)
	{
    int scopeCount = 0;
    while (iPos < iEndPos)
    {
      const char charAt = CharAt_<StringType>(iStr, iPos);
      if (CheckChar::IsScopeBegin(charAt))
        scopeCount++;
      else if (CheckChar::IsScopeEnd(charAt))
        scopeCount--;
      iPos++;
    }
    return scopeCount;
  }

  enum EPropType
  {
    ePrimary,
    eString,
    eObject,
    eArray
  };

  template <class StringType>
  EPropType GetPropertyValueType_(const StringType& iJSON, unsigned int iPropValuePos)
  {
    const char propValChar = CharAt_(iJSON, iPropValuePos);
    switch (propValChar)
    {
    case '"':
      return eString;
    case '{':
      return eObject;
    case '[':
      return eArray;
    }
    return ePrimary;
  }

	// std::string

	template <>
	int Find_<std::string>(const std::string& iInput, const std::string& iSearched, int iStart)
	{
		return (int)iInput.find(iSearched, iStart);
	}

	template <>
	std::string SubStr_<std::string>(const std::string& iInput, int iStart, int iLength)
	{
		return iInput.substr(iStart, iLength);
	}

	template <>
	std::string ToUpper_<std::string>(const std::string& iInput)
	{
    std::string output;
    std::transform(iInput.begin(), iInput.end(), std::back_inserter(output), ::toupper);
		return output;
	}

	template <>
	std::string ToLower_<std::string>(const std::string& iInput)
	{
    std::string output;
    std::transform(iInput.begin(), iInput.end(), std::back_inserter(output), ::tolower);
		return output;
	}

	template <>
	unsigned int Length_<std::string>(const std::string& iInput)
	{
		return (unsigned int)iInput.size();
	}

	template <>
	const char CharAt_<std::string>(const std::string& iInput, int iPos)
	{
		return iInput.at(iPos);
	}

	template <>
	std::string ToString_<std::string>(size_t iValue)
	{
		return std::to_string(iValue);
	}

  template <>
  size_t ToNumber_<std::string>(const std::string& iInput)
  {
    return (size_t)std::stoull(iInput);
  }

	// CATUnicodeString

	template <>
	int Find_<CATUnicodeString>(const CATUnicodeString& iInput, const CATUnicodeString& iSearched, int iStart)
	{
		return iInput.FindPosition(iSearched, iStart);
	}

	template <>
	CATUnicodeString SubStr_<CATUnicodeString>(const CATUnicodeString& iInput, int iStart, int iLength)
	{
		return iInput.SubString(iStart, iLength);
	}

	template <>
	CATUnicodeString ToUpper_<CATUnicodeString>(const CATUnicodeString& iInput)
	{
    CATUnicodeString output = iInput;
    output.ToUpper();
		return output;
	}

	template <>
	CATUnicodeString ToLower_<CATUnicodeString>(const CATUnicodeString& iInput)
	{
    CATUnicodeString output = iInput;
    output.ToLower();
		return output;
	}

	template <>
	unsigned int Length_<CATUnicodeString>(const CATUnicodeString& iInput)
	{
		return (unsigned int)iInput.GetLengthInChar();
	}

	template <>
	const char CharAt_<CATUnicodeString>(const CATUnicodeString& iInput, int iPos)
	{
		return (const char)iInput[(size_t)iPos];
	}
  
  template <>
	CATUnicodeString ToString_<CATUnicodeString>(size_t iValue)
	{
    CATUnicodeString output;
    output.BuildFromNum(iValue);
		return output;
	}

  template <>
  size_t ToNumber_<CATUnicodeString>(const CATUnicodeString& iInput)
  {
    std::uint64_t res = 0;
    int convRes = iInput.ConvertToNum(&res, "%ull");
    return (size_t)res;
  }
}

template <class StringType>
const typename ViscaURLServices<StringType>::URLsRequestOptions ViscaURLServices<StringType>::kDefaultRequestOptions;

template <class StringType>
const typename ViscaURLServices<StringType>::BatchOptions ViscaURLServices<StringType>::kDefaultBatchOptions;

template <class StringType>
const typename ViscaURLServices<StringType>::FetchOptions ViscaURLServices<StringType>::kDefaultFetchOptions;

template <class StringType>
StringType ViscaURLServices<StringType>::s_JSONField[eField_Count] = {
  "tenant",
  "source",
  "boid",
  "filename",
  "format",
  "element",
  "version",
  "type",
  "timestamp",
  "signature",
  "correlationID",
  "emptyReason",
  "derivedVersion",
  "updatedAccessURL",
  "ticketWrappers",
  "ticket",
  "url",
  "headers",
  "name",
  "value",
  "urls",
  "files",
  "filesNotFound",
  "inaccurateFiles"
};

template <class StringType>
unsigned int ViscaURLServices<StringType>::s_JSONFieldLen[eField_Count] = {
  (unsigned int)strlen("tenant"),
  (unsigned int)strlen("source"),
  (unsigned int)strlen("boid"),
  (unsigned int)strlen("filename"),
  (unsigned int)strlen("format"),
  (unsigned int)strlen("element"),
  (unsigned int)strlen("version"),
  (unsigned int)strlen("type"),
  (unsigned int)strlen("timestamp"),
  (unsigned int)strlen("signature"),
  (unsigned int)strlen("correlationID"),
  (unsigned int)strlen("emptyReason"),
  (unsigned int)strlen("derivedVersion"),
  (unsigned int)strlen("updatedAccessURL"),
  (unsigned int)strlen("ticketWrappers"),
  (unsigned int)strlen("ticket"),
  (unsigned int)strlen("url"),
  (unsigned int)strlen("headers"),
  (unsigned int)strlen("name"),
  (unsigned int)strlen("value"),
  (unsigned int)strlen("urls"),
  (unsigned int)strlen("files"),
  (unsigned int)strlen("filesNotFound"),
  (unsigned int)strlen("inaccurateFiles")
};

template <class StringType>
StringType ViscaURLServices<StringType>::s_URLField[eField_Count] = {
  "t",
  "s",
  "id",
  "f",
  "fmt",
  "e",
  "v",
  "type",
  "ts",
  "sgn",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""
};

template <class StringType>
bool ViscaURLServices<StringType>::s_NumericField[eField_Count] = {
  false, // "tenant",
  false, // "source",
  false, // "boid",
  false, // "filename",
  false, // "format",
  true,  // "element",
  false, // "version",
  false, // "type",
  false, // "timestamp",
  false, // "signature",
  false, // "correlationID",
  false, // "emptyReason",
  false, // "derivedVersion",
  false, // "updatedAccessURL",
  false, // "ticketWrappers",
  false, // "ticket",
  false, // "url",
  false, // "headers",
  false, // "name",
  false, // "value",
  false, // "urls",
  false, // "files",
  false, // "filesNotFound",
  false  // "inaccurateFiles"
};

template <class StringType>
bool ViscaURLServices<StringType>::s_ArrayField[eField_Count] = {
  false, // "tenant",
  false, // "source",
  false, // "boid",
  false, // "filename",
  false, // "format",
  false, // "element",
  false, // "version",
  false, // "type",
  false, // "timestamp",
  false, // "signature",
  false, // "correlationID",
  false, // "emptyReason",
  false, // "derivedVersion",
  false, // "updatedAccessURL",
  false, // "ticketWrappers",
  false, // "ticket",
  false, // "url",
  true,  // "headers",
  false, // "name",
  false, // "value",
  true,  // "urls",
  true,  // "files",
  true,  // "filesNotFound",
  true   // "inaccurateFiles"
};

template <class StringType>
StringType ViscaURLServices<StringType>::GetJSONField(const StringType& iParam, unsigned int iFields)
{
	StringType res = "";
	int idEqual = Find_(iParam, "=", 0);
	if (idEqual < 1)
		return "";

	const unsigned int length = Length_(iParam);
	StringType key = SubStr_(iParam, AvoidBlank_<StringType, false>(iParam, 0, idEqual), AvoidBlank_<StringType, true>(iParam, idEqual - 1, 0) + 1);
	StringType value = SubStr_(iParam, AvoidBlank_<StringType, false>(iParam, idEqual + 1, length), AvoidBlank_<StringType, true>(iParam, length - 1, idEqual + 1) - idEqual);

  for (unsigned int i = 0; i < eField_Count; i++)
  {
    if (0 == (iFields & (1 << i)))
      continue;
    
    if (key == s_URLField[i])
    {
      res = "\"" + s_JSONField[i];
      if (s_NumericField[i])
        res += +"\":" + value;
      else
        res += +"\":\"" + value + "\"";
      break;
    }
  }

	return res;
}

template <class StringType>
bool ViscaURLServices<StringType>::GetURLField(const StringType& iParam, unsigned int iFields, EField& oField, StringType& oValue)
{
  StringType res = "";
	int idEqual = Find_(iParam, "=", 0);
	if (idEqual < 1)
		return false;
  
  const unsigned int length = Length_(iParam);
	StringType key = SubStr_(iParam, AvoidBlank_<StringType, false>(iParam, 0, idEqual), AvoidBlank_<StringType, true>(iParam, idEqual - 1, 0) + 1);
	StringType value = SubStr_(iParam, AvoidBlank_<StringType, false>(iParam, idEqual + 1, length), AvoidBlank_<StringType, true>(iParam, length - 1, idEqual + 1) - idEqual);

  for (unsigned int i = 0; i < eField_Count; i++)
  {
    if (0 == (iFields & (1 << i)))
      continue;
    
    if (key == s_URLField[i])
    {
      oField = (EField)i;
      oValue = value;
      return true;
    }
  }

	return false;
}

template <class StringType>
int ViscaURLServices<StringType>::GetJSONPropertyValue(const StringType& iJSON, unsigned int iJSONLen, unsigned int iPropPos, unsigned int iPropLen)
{
  const char prevChar = CharAt_(iJSON, AvoidBlank_<StringType, true>(iJSON, iPropPos - 1, 0));
  if (!CheckChar::IsScopeBegin(prevChar) && prevChar != ',')
    return -1;

  int nextCharPos = AvoidBlank_<StringType, false>(iJSON, iPropPos + iPropLen, iJSONLen);
  const char nextChar = CharAt_(iJSON, nextCharPos);
  if (nextChar != ':')
    return -1;
  
  return AvoidBlank_<StringType, false>(iJSON, nextCharPos + 1, iJSONLen);
}

template <class StringType>
int ViscaURLServices<StringType>::SearchJSONPropertyInScope(const StringType& iJSON, unsigned int iScopePos, int& ioScopeEnd, EField iName)
{
  if (ioScopeEnd <= (int)iScopePos)
    ioScopeEnd = FindScopeEnd_(iJSON, iScopePos, Length_(iJSON));
  
  StringType searchedProp = "\"";
  searchedProp += s_JSONField[iName];
  searchedProp += "\"";
  unsigned int searchedPropLen = s_JSONFieldLen[iName] + 2;
  int pos = (int)iScopePos;
  
  while (pos < ioScopeEnd)
  {
    pos = Find_(iJSON, searchedProp, pos);
    
    if (pos < 0)
      break;
    
    if (0 != CountScopes_(iJSON, iScopePos+1, pos))
    {
      pos += searchedPropLen;
      continue;
    }

    int res = GetJSONPropertyValue(iJSON, ioScopeEnd, pos, searchedPropLen);
    if (res > 0)
      return res;

    pos += searchedPropLen;
  }
  
  return -1;
}

template <class StringType>
int ViscaURLServices<StringType>::GetJSONNextArrayObject(const StringType& iJSON, unsigned int iArrayPos, int& ioArrayEnd, unsigned int iCurObjectPos)
{
  if (eArray != GetPropertyValueType_(iJSON, iArrayPos))
    return -1;
  
  if (ioArrayEnd <= (int)iArrayPos)
    ioArrayEnd = FindScopeEnd_(iJSON, iArrayPos, Length_(iJSON));

  int nextObjPos = iCurObjectPos + 1;
  if (iCurObjectPos > iArrayPos && eObject == GetPropertyValueType_(iJSON, iCurObjectPos))
  {
    nextObjPos = FindScopeEnd_(iJSON, iCurObjectPos, ioArrayEnd);
    if (nextObjPos < (int)iCurObjectPos || CharAt_(iJSON, nextObjPos) != '}')
      return -1;
    
    nextObjPos = AvoidBlank_<StringType, false>(iJSON, nextObjPos + 1, ioArrayEnd);
    if (nextObjPos >= ioArrayEnd || CharAt_(iJSON, nextObjPos) != ',')
      return -1;

    nextObjPos++;
  }

  nextObjPos = AvoidBlank_<StringType, false>(iJSON, nextObjPos, ioArrayEnd);
  return (eObject == GetPropertyValueType_(iJSON, nextObjPos)) ? nextObjPos : -1;
}

template <class StringType>
unsigned int ViscaURLServices<StringType>::CopyJSONPropertyStringValuesInScope(const StringType& iJSON, unsigned int iScopePos, int& ioScopeEnd, StringType* const oValues[eField_Count])
{
  unsigned int foundProp = 0;
  for (unsigned int i = 0; i < eField_Count; i++)
  {
    if (nullptr == oValues[i])
      continue;
    
    int propValuePos = SearchJSONPropertyInScope(iJSON, iScopePos, ioScopeEnd, (EField)i);
    if (propValuePos < 0 || propValuePos > ioScopeEnd)
      continue;

    int propValueEndPos = propValuePos;
    EPropType propType = GetPropertyValueType_(iJSON, propValuePos);

    if (s_NumericField[(EField)i])
    {
      if (propType != ePrimary)
        continue;
      while (CheckChar::IsNumeric(CharAt_(iJSON, propValueEndPos)))
        propValueEndPos++;
      *(oValues[i]) = SubStr_(iJSON, propValuePos, propValueEndPos - propValuePos);
    }
    else if (propType == eString)
    {
      propValueEndPos = Find_(iJSON, "\"", propValuePos + 1);
      if (propValueEndPos < 0 || propValueEndPos > ioScopeEnd)
        continue;
      *(oValues[i]) = SubStr_(iJSON, propValuePos + 1, propValueEndPos - propValuePos - 1);
    }
    else
      continue;
    
    foundProp |= (1 << i);
  }
  
  return foundProp;
}

template <class StringType>
unsigned int ViscaURLServices<StringType>::CopyJSONPropertyNumberValuesInScope(const StringType& iJSON, unsigned int iScopePos, int& ioScopeEnd, std::optional<std::size_t>* const oValues[eField_Count])
{
  unsigned int foundProp = 0;
  for (unsigned int i = 0; i < eField_Count; i++)
  {
    if (!s_NumericField[(EField)i] || nullptr == oValues[i])
      continue;

    int propValuePos = SearchJSONPropertyInScope(iJSON, iScopePos, ioScopeEnd, (EField)i);
    if (propValuePos < 0 || propValuePos > ioScopeEnd)
      continue;

    int propValueEndPos = propValuePos;
    if (GetPropertyValueType_(iJSON, propValuePos) != ePrimary)
      continue;

    while (CheckChar::IsNumeric(CharAt_(iJSON, propValueEndPos)))
      propValueEndPos++;
    StringType numberStr = SubStr_(iJSON, propValuePos, propValueEndPos - propValuePos);
    *(oValues[i]) = ToNumber_(numberStr);

    foundProp |= (1 << i);
  }

  return foundProp;
}

template<class StringType>
template<class ElementType>
bool ViscaURLServices<StringType>::CopyJSONArrayElements(const StringType& iJSON, int iScopePos, int& ioScopeEndPos, EField iName, unsigned int iFieldsCheck, std::vector<ElementType>& oElements,
                                                         const std::vector<std::function<unsigned int(const StringType& iJSON, int iScopePos, int& ioScopeEndPos, ElementType& oElement)>>& iSubMngt)
{
  int elementsValPos = SearchJSONPropertyInScope(iJSON, iScopePos, ioScopeEndPos, iName);
  if (elementsValPos > iScopePos && elementsValPos < ioScopeEndPos && eArray == GetPropertyValueType_(iJSON, elementsValPos))
  {
    StringType* elementStrValues[eField_Count];
    for (int i = 0; i < eField_Count; i++)
      elementStrValues[i] = nullptr;

    std::optional<std::size_t>* elementNumValues[eField_Count];
    for (int i = 0; i < eField_Count; i++)
      elementNumValues[i] = nullptr;

    int arrayObj = elementsValPos;
    int elementsValEndPos = -1;
    while ((arrayObj = GetJSONNextArrayObject(iJSON, elementsValPos, elementsValEndPos, arrayObj)) > elementsValPos)
    {
      int arrayObjEnd = -1;
      ElementType element;

      ReferElementStrings(element, elementStrValues);
      unsigned int fieldsCheck = CopyJSONPropertyStringValuesInScope(iJSON, arrayObj, arrayObjEnd, elementStrValues);

      ReferElementNumbers(element, elementNumValues);
      fieldsCheck |= CopyJSONPropertyNumberValuesInScope(iJSON, arrayObj, arrayObjEnd, elementNumValues);

      for (auto mngtFunc : iSubMngt)
      {
        int arraySubObjEnd = arrayObjEnd;
        fieldsCheck |= mngtFunc(iJSON, arrayObj, arraySubObjEnd, element);
      }

      if (0 != (fieldsCheck & iFieldsCheck))
        oElements.push_back(element);
    }

    return true;
  }
  return false;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::CreateURLsRequestBody(const std::vector<RequestedDerivedObject>& iRequestedObjects, StringType& oBody, const URLsRequestOptions& iOptions)
{
  if (iRequestedObjects.size() == 0)
		return E_INVALIDARG;

  oBody = "{\"files\":[";
  for (int i = 0; i < (int)iRequestedObjects.size(); ++i)
	{
		if (i == 0)
			oBody += "{";
		else
			oBody += ", {";
    
    const RequestedDerivedObject& obj = iRequestedObjects[i];
		oBody += "\"source\":\"" + obj.source + "\", ";
		oBody += "\"boid\":\"" + obj.boid + "\", ";
		oBody += "\"type\":\"" + obj.type + "\"}";
  }

  oBody += "]";
  if (iOptions.fallback)
    oBody += ", \"fallback\": true";
	oBody += "}";
	return S_OK;
}

template <class StringType>
bool ViscaURLServices<StringType>::IsURLFetchCompatible(const StringType& iUrl)
{
  return (Find_(ToLower_(iUrl), "&type=av", 0) < 0);
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::CreateBatchURLAndBody(const std::vector<StringType>& iUrls, StringType& oUrl, StringType& oBody, const BatchOptions& iOptions)
{
	//Exctract the base url
	if (iUrls.size() == 0)
		return E_INVALIDARG;

	static const StringType urlToFind = "api/v1/rep?";
  static const unsigned int urlToFindLen = Length_(urlToFind);

	oBody = "{\"files\":[";
	for (int i = 0; i < (int)iUrls.size(); ++i)
	{
		if (i == 0)
			oBody += "{";
		else
			oBody += ", {";

		StringType str = iUrls[i];
		if (str != "")
		{

			int id = Find_(str, urlToFind, 0);
			if (id == -1)
			{
				return E_FAIL;
			}

			if (i == 0)
			{
				oUrl = SubStr_(str, 0, id);
				oUrl += "api/v1/reps";
			}

			StringType params = SubStr_(str, id + urlToFindLen, Length_(str) - (id + urlToFindLen));
			params += "&"; // to avoid corner case

			int idx = 0;
			int curIdx = 0;
			int test = 0;
			while (idx != -1)
			{
				curIdx = Find_(params, "&", idx);
				if (curIdx != -1)
				{
					StringType param = SubStr_(params, idx, (curIdx - idx));
					StringType jsonValue = GetJSONField(param, fSecuredAccessKey);

					if (test == 0)
						oBody += jsonValue;
					else if (Length_(jsonValue) > 0)
						oBody += ", " + jsonValue;
				}

				if (curIdx == -1)
					idx = -1;
				else
					idx = curIdx + 1;

				test++;
			}

		}
		oBody += "}";
	}
  
  oBody += "]";
  if (iOptions.allowPartial)
    oBody += ", \"allowPartial\": true";
  if (iOptions.fallback)
    oBody += ", \"fallback\": true";
  if (iOptions.checkVersion)
    oBody += ", \"checkVersion\": true";
	oBody += "}";
	return S_OK;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::CreateFetchURLAndBody(const std::vector<StringType>& iUrls, const std::vector<StringType>& iCorrelationIDs, StringType& oUrl, StringType& oBody, const FetchOptions& iOptions)
{
	//Exctract the base url
	if (iUrls.size() == 0)
		return E_INVALIDARG;

	if (iUrls.size() != iCorrelationIDs.size())
		return E_INVALIDARG;

	static const StringType urlToFind = "api/v1/rep?";
  static const unsigned int urlToFindLen = Length_(urlToFind);

	oBody = "{\"files\":[";
	for (int i = 0; i < (int)iUrls.size(); ++i)
	{
		if (i == 0)
			oBody += "{";
		else
			oBody += ", {";

		StringType str = iUrls[i];
		if (str != "")
		{
			int id = Find_(str, urlToFind, 0);
			if (id == -1)
			{
				return E_FAIL;
			}

			if (i == 0)
			{
				oUrl = SubStr_(str, 0, id);
				oUrl += "api/v1/fetch";
			}

			StringType params = SubStr_(str, id + urlToFindLen, Length_(str) - (id + urlToFindLen));
			params += "&"; // to avoid corner case

			int idx = 0;
			int curIdx = 0;
			int test = 0;
			while (idx != -1)
			{
				curIdx = Find_(params, "&", idx);
				if (curIdx != -1)
				{
					StringType param = SubStr_(params, idx, (curIdx - idx));
					StringType jsonValue = GetJSONField(param, fSecuredAccessKey);

					if (Length_(jsonValue) > 0)
						oBody += jsonValue + ", ";
				}

				if (curIdx == -1)
					idx = -1;
				else
					idx = curIdx + 1;

				test++;
			}

			oBody += "\"correlationID\":\"" + iCorrelationIDs[i] + "\"";

		}
		oBody += "}";
	}

  oBody += "]";
  if (iOptions.splitTargetedSize > 0)
  {
    oBody += ", \"splitTargetedSize\": ";
    oBody += ToString_<StringType>(iOptions.splitTargetedSize);
  }
  if (iOptions.allowPartial)
    oBody += ", \"allowPartial\": true";
  if (iOptions.checkVersion)
    oBody += ", \"checkVersion\": true";
	oBody += "}";
	return S_OK;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::GetRequestedObjectFromURL(const StringType& iUrl, StringType& oTenant, RequestedObject& oDerivObj)
{
  static const StringType protoToFind = "://";
  static const unsigned int protoToFindLen = Length_(protoToFind);

  int proId = Find_(iUrl, protoToFind, 0);
  if (proId == -1)
    return E_FAIL;

  unsigned int tenBegin = proId + protoToFindLen;
  int tenId = Find_(iUrl, "-", tenBegin);
  if (tenId == -1)
    return E_FAIL;
  
  oTenant = ToUpper_(SubStr_(iUrl, tenBegin, tenId - tenBegin));

  static const StringType urlToFind = "api/v1/rep?";
  static const unsigned int urlToFindLen = Length_(urlToFind);
  
  int id = Find_(iUrl, urlToFind, 0);
  if (id == -1 || id < tenId)
    return E_FAIL;

  StringType params = SubStr_(iUrl, id + urlToFindLen, Length_(iUrl) - (id + urlToFindLen));
  params += "&"; // to avoid corner case
  
  int idx = 0;
  int curIdx = 0;
  unsigned int fields = 0;
  
  while (idx != -1)
  {
    curIdx = Find_(params, "&", idx);
    if (curIdx != -1)
    {
      StringType param = SubStr_(params, idx, (curIdx - idx));
      EField field = eField_Count;
      StringType value = "";
      if (GetURLField(param, fAccessKey, field, value) && field < eField_Count)
      {
        if (s_NumericField[field] && !IsNumeric_(value))
          return E_INVALIDARG;

        switch (field)
        {
        case eSource:
          oDerivObj.source = ToLower_(value);
          break;
        case eBOID:
          oDerivObj.boid = value;
          break;
        case eFilename:
          oDerivObj.filename = value;
          break;
        case eFormat:
          oDerivObj.format = value;
          break;
        case eElement:
          oDerivObj.element = ToNumber_(value);
          break;
        case eVersion:
          oDerivObj.version = value;
          break;
        case eType:
          oDerivObj.type = ToUpper_(value);
          break;
        default:
          return E_UNEXPECTED;
        }
        fields |= (1 << field);
      }
    }

    if (curIdx == -1)
      idx = -1;
    else
      idx = curIdx + 1;
  }

  return ((fields & fMandatoryAccessKey) == fMandatoryAccessKey) ? S_OK : E_INVALIDARG;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::GetAccessKeyFromRequestedObject(const RequestedObject& iDerivObj, StringType& oAccessKey)
{
  if (Length_(iDerivObj.source) == 0 || Length_(iDerivObj.boid) == 0 || Length_(iDerivObj.version) == 0 || Length_(iDerivObj.type) == 0)
    return E_INVALIDARG;

  const bool hasElement = iDerivObj.element.has_value();
  const bool hasFilename = (Length_(iDerivObj.filename) > 0);
  const bool hasFormat = (Length_(iDerivObj.format) > 0);
  if (!hasElement && (!hasFilename || !hasFormat))
    return E_INVALIDARG;
  
  oAccessKey = "/api/v1/rep?";
  oAccessKey += s_URLField[eSource] + "=" + ToLower_(iDerivObj.source);
  oAccessKey += "&" + s_URLField[eBOID] + "=" + iDerivObj.boid;
  if (hasFilename)
    oAccessKey += "&" + s_URLField[eFilename] + "=" + iDerivObj.filename;
  if (hasFormat)
    oAccessKey += "&" + s_URLField[eFormat] + "=" + iDerivObj.format;
  if (hasElement)
    oAccessKey += "&" + s_URLField[eElement] + "=" + ToString_<StringType>(iDerivObj.element.value());
  oAccessKey += "&" + s_URLField[eVersion] + "=" + iDerivObj.version;
  oAccessKey += "&" + s_URLField[eType] + "=" + ToUpper_(iDerivObj.type);

  return S_OK;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::GetAccessKeyFromURL(const StringType& iUrl, StringType& oAccessKey)
{
  RequestedObject reqObj;
  StringType tenant;
  HRESULT res = GetRequestedObjectFromURL(iUrl, tenant, reqObj);
  return SUCCEEDED(res) ? GetAccessKeyFromRequestedObject(reqObj, oAccessKey) : res;
}



template <>
template <>
void ViscaURLServices<std::string>::ReferElementStrings<ViscaURLServices<std::string>::URLOnObject>(URLOnObject& iElement, std::string* oValues[eField_Count])
{
  oValues[eSource] = &iElement.source;
  oValues[eBOID] = &iElement.boid;
  oValues[eFilename] = &iElement.filename;
  oValues[eFormat] = &iElement.format;
  oValues[eVersion] = &iElement.version;
  oValues[eType] = &iElement.type;
  oValues[eURL] = &iElement.url;
  oValues[eDerivedVersion] = &iElement.derivedVersion;
}

template <>
template <>
void ViscaURLServices<CATUnicodeString>::ReferElementStrings<ViscaURLServices<CATUnicodeString>::URLOnObject>(URLOnObject& iElement, CATUnicodeString* oValues[eField_Count])
{
  oValues[eSource] = &iElement.source;
  oValues[eBOID] = &iElement.boid;
  oValues[eFilename] = &iElement.filename;
  oValues[eFormat] = &iElement.format;
  oValues[eVersion] = &iElement.version;
  oValues[eType] = &iElement.type;
  oValues[eURL] = &iElement.url;
  oValues[eDerivedVersion] = &iElement.derivedVersion;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::DecodeURLsRequestAnswer(const StringType& iAnswer, std::vector<URLOnObject>& oStaticURLs)
{
  int answerLen = (int)Length_(iAnswer);
  int answerScopePos = AvoidBlank_<StringType, false>(iAnswer, 0, answerLen);
  if (eObject != GetPropertyValueType_(iAnswer, answerScopePos))
    return E_INVALIDARG;

  return CopyJSONArrayElements<URLOnObject>(iAnswer, answerScopePos, answerLen, eURLs, fURLKey, oStaticURLs, {}) ? S_OK : E_FAIL;
}


template <>
template <>
void ViscaURLServices<std::string>::ReferElementStrings<ViscaURLServices<std::string>::DynamicURLOnObject>(DynamicURLOnObject& iElement, std::string* oValues[eField_Count])
{
  ReferElementStrings<ViscaURLServices<std::string>::URLOnObject>(iElement, oValues);
}

template <>
template <>
void ViscaURLServices<CATUnicodeString>::ReferElementStrings<ViscaURLServices<CATUnicodeString>::DynamicURLOnObject>(DynamicURLOnObject& iElement, CATUnicodeString* oValues[eField_Count])
{
  ReferElementStrings<ViscaURLServices<CATUnicodeString>::URLOnObject>(iElement, oValues);
}

template <>
template <>
void ViscaURLServices<std::string>::ReferElementStrings<ViscaURLServices<std::string>::Header>(Header& iElement, std::string* oValues[eField_Count])
{
  oValues[eName] = &iElement.name;
  oValues[eValue] = &iElement.value;
}

template <>
template <>
void ViscaURLServices<CATUnicodeString>::ReferElementStrings<ViscaURLServices<CATUnicodeString>::Header>(Header& iElement, CATUnicodeString* oValues[eField_Count])
{
  oValues[eName] = &iElement.name;
  oValues[eValue] = &iElement.value;
}

template<class StringType>
template<class ElementType>
void ViscaURLServices<StringType>::ReferElementNumbers(ElementType& iElement, std::optional<std::size_t>* oValues[eField_Count])
{
  if constexpr (std::is_same_v<ElementType, DynamicURLOnObject>)
    oValues[eElement] = &iElement.element;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::DecodeBatchAnswer(const StringType& iAnswer, std::vector<DynamicURLOnObject>& oDynamicURLs)
{
  int answerLen = (int)Length_(iAnswer);
  int answerScopePos = AvoidBlank_<StringType, false>(iAnswer, 0, answerLen);
  if (eObject != GetPropertyValueType_(iAnswer, answerScopePos))
    return E_INVALIDARG;

  std::function<unsigned int(const StringType& iJSON, int iScopePos, int& ioScopeEndPos, DynamicURLOnObject& oElement)> headersMngt =
    [](const StringType& iJSON, int iScopePos, int& ioScopeEndPos, DynamicURLOnObject& oElement)
  {
    return CopyJSONArrayElements<Header>(iJSON, iScopePos, ioScopeEndPos, eHeaders, fHeader, oElement.headers, {}) ? fHeader : 0;
  };
  return CopyJSONArrayElements<DynamicURLOnObject>(iAnswer, answerScopePos, answerLen, eFiles, fFileKey, oDynamicURLs, { headersMngt }) ? S_OK : E_FAIL;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::MergeBatchAnswer(const std::vector<DynamicURLOnObject>& iDynamicURLs, std::vector<MergedURLOnObjects>& oMergedURLs, const std::size_t iSplitTargetedSize)
{
  struct DynURLWithIdx
  {
    const DynamicURLOnObject* dynUrl;
    std::size_t index = 0;
  };

  std::map<StringType, std::vector<DynURLWithIdx>> toMergeMap;
  std::size_t index = 0;
  for (const DynamicURLOnObject& iDynURL : iDynamicURLs)
  {
    typename std::map<StringType, std::vector<DynURLWithIdx>>::iterator found = toMergeMap.find(iDynURL.url);
    if (found == toMergeMap.end())
      toMergeMap[iDynURL.url] = { {&iDynURL, index} };
    else
    {
      const DynURLWithIdx& refObj = (*found).second[0];
      if (nullptr == refObj.dynUrl || refObj.dynUrl->source != iDynURL.source || refObj.dynUrl->boid != iDynURL.boid)
        return E_INVALIDARG;
      (*found).second.push_back({ &iDynURL, index });
    }
    index++;
  }

  static const StringType kBytesStr = "bytes=";
  static const int kBytesStrLen = Length_<StringType>(kBytesStr);

  const std::function<std::int64_t(const Header& iHeader)> computeRangeSize = [bytesStr = kBytesStr, bytesStrLen = kBytesStrLen](const Header& iHeader)
  {
    static const StringType rangeStr = "Range";

    if (iHeader.name != rangeStr || 0 != Find_<StringType>(iHeader.value, bytesStr, 0))
      return (std::int64_t)-1;

    int rangeSepIdx = Find_<StringType>(iHeader.value, "-", bytesStrLen);
    if (rangeSepIdx < 0)
      return (std::int64_t)-1;

    const StringType startRangeStr = SubStr_(iHeader.value, bytesStrLen, rangeSepIdx - bytesStrLen);
    const StringType endRangeStr = SubStr_(iHeader.value, rangeSepIdx+1, Length_(iHeader.value) - rangeSepIdx - 1);
    if (!IsNumeric_(startRangeStr) || !IsNumeric_(endRangeStr))
      return (std::int64_t)-1;

    return (std::int64_t)ToNumber_(endRangeStr) - (std::int64_t)ToNumber_(startRangeStr);
  };

  const std::function<MergedURLOnObjects(const DynURLWithIdx& iFile)> initMergedFile = [computeRangeSize](const DynURLWithIdx& iFile)
  {
    MergedURLOnObjects mergedFile;
    if (nullptr == iFile.dynUrl)
      return mergedFile;

    mergedFile = { { *iFile.dynUrl } };
    mergedFile.elements = { {mergedFile.element, iFile.index} };
    mergedFile.element.reset();

    if (mergedFile.headers.size() == 1)
    {
      std::int64_t rangeSize = computeRangeSize(mergedFile.headers[0]);
      if (rangeSize >= 0)
        mergedFile.contentSize = (std::size_t)rangeSize;
    }

    return mergedFile;
  };

  oMergedURLs.clear();
  oMergedURLs.reserve(toMergeMap.size());

  for (const std::pair<StringType, std::vector<DynURLWithIdx>>& toMerge : toMergeMap)
  {
    const std::vector<DynURLWithIdx>& filesToMerge = toMerge.second;
    if (filesToMerge.empty())
      continue;

    MergedURLOnObjects mergedFile = initMergedFile(filesToMerge[0]);
    for (std::size_t i = 1; i < filesToMerge.size(); i++)
    {
      const DynURLWithIdx& fileToMerge = filesToMerge[i];
      if (nullptr == fileToMerge.dynUrl)
        continue;

      if (!mergedFile.contentSize.has_value() || (iSplitTargetedSize != 0 && mergedFile.contentSize.value() >= iSplitTargetedSize))
      {
        oMergedURLs.push_back(mergedFile);
        mergedFile = initMergedFile(fileToMerge);
        continue;
      }

      std::int64_t rangeSize = -1;
      if (fileToMerge.dynUrl->headers.size() != 1 || (rangeSize = computeRangeSize(fileToMerge.dynUrl->headers[0])) < 0)
      {
        oMergedURLs.push_back(MergedURLOnObjects{ {*fileToMerge.dynUrl} });
        continue;
      }
      else if (iSplitTargetedSize != 0 && mergedFile.contentSize.value() + rangeSize > iSplitTargetedSize)
      {
        oMergedURLs.push_back(mergedFile);
        mergedFile = initMergedFile(fileToMerge);
        continue;
      }
      
      mergedFile.contentSize = mergedFile.contentSize.value() + (std::size_t)rangeSize;
      mergedFile.elements.push_back({ fileToMerge.dynUrl->element, fileToMerge.index });

      Header& mergedFileHeader = mergedFile.headers[0];
      const StringType& rangeToMergeStr = fileToMerge.dynUrl->headers[0].value;
      mergedFileHeader.value += ",";
      mergedFileHeader.value += SubStr_(rangeToMergeStr, kBytesStrLen, Length_(rangeToMergeStr) - kBytesStrLen);
    }

    oMergedURLs.push_back(mergedFile);
  }

  return (oMergedURLs.size() < iDynamicURLs.size()) ? S_OK : S_FALSE;
}


template <>
template <>
void ViscaURLServices<std::string>::ReferElementStrings<ViscaURLServices<std::string>::FCSMedia>(FCSMedia& iElement, std::string* oValues[eField_Count])
{
  oValues[eTicket] = &iElement.ticket;
  oValues[eURL] = &iElement.url;
}

template <>
template <>
void ViscaURLServices<CATUnicodeString>::ReferElementStrings<ViscaURLServices<CATUnicodeString>::FCSMedia>(FCSMedia& iElement, CATUnicodeString* oValues[eField_Count])
{
  oValues[eTicket] = &iElement.ticket;
  oValues[eURL] = &iElement.url;
}

template <>
template <>
void ViscaURLServices<std::string>::ReferElementStrings<ViscaURLServices<std::string>::FetchObject>(FetchObject& iElement, std::string* oValues[eField_Count])
{
  oValues[eSource] = &iElement.source;
  oValues[eBOID] = &iElement.boid;
  oValues[eFilename] = &iElement.filename;
  oValues[eFormat] = &iElement.format;
  oValues[eVersion] = &iElement.version;
  oValues[eType] = &iElement.type;
  oValues[eCorrelationID] = &iElement.correlationID;
  oValues[eEmptyReason] = &iElement.emptyReason;
}

template <>
template <>
void ViscaURLServices<CATUnicodeString>::ReferElementStrings<ViscaURLServices<CATUnicodeString>::FetchObject>(FetchObject& iElement, CATUnicodeString* oValues[eField_Count])
{
  oValues[eSource] = &iElement.source;
  oValues[eBOID] = &iElement.boid;
  oValues[eFilename] = &iElement.filename;
  oValues[eFormat] = &iElement.format;
  oValues[eVersion] = &iElement.version;
  oValues[eType] = &iElement.type;
  oValues[eCorrelationID] = &iElement.correlationID;
  oValues[eEmptyReason] = &iElement.emptyReason;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::DecodeFetchAnswer(const StringType& iAnswer, std::vector<FCSMedia>& oMedias, std::vector<FetchObject>& oMissingFiles)
{
  int answerLen = (int)Length_(iAnswer);
  int answerScopePos = AvoidBlank_<StringType, false>(iAnswer, 0, answerLen);
  if (eObject != GetPropertyValueType_(iAnswer, answerScopePos))
    return E_INVALIDARG;
  
  bool res = CopyJSONArrayElements<FCSMedia>(iAnswer, answerScopePos, answerLen, eTicketWrappers, fMedia, oMedias, {});
  res |= CopyJSONArrayElements<FetchObject>(iAnswer, answerScopePos, answerLen, eFilesNotFound, fAccessKey, oMissingFiles, {});
  return (res ? S_OK :E_FAIL);
}

template <>
template <>
void ViscaURLServices<std::string>::ReferElementStrings<ViscaURLServices<std::string>::InaccurateObject>(InaccurateObject& iElement, std::string* oValues[eField_Count])
{
  ReferElementStrings<FetchObject>(iElement, oValues);
  oValues[eDerivedVersion] = &iElement.derivedVersion;
  oValues[eUpdatedAccessURL] = &iElement.updatedAccessURL;
}

template <>
template <>
void ViscaURLServices<CATUnicodeString>::ReferElementStrings<ViscaURLServices<CATUnicodeString>::InaccurateObject>(InaccurateObject& iElement, CATUnicodeString* oValues[eField_Count])
{
  ReferElementStrings<FetchObject>(iElement, oValues);
  oValues[eDerivedVersion] = &iElement.derivedVersion;
  oValues[eUpdatedAccessURL] = &iElement.updatedAccessURL;
}

template <class StringType>
HRESULT ViscaURLServices<StringType>::DecodeFetchAnswer(const StringType& iAnswer, std::vector<FCSMedia>& oMedias, std::vector<FetchObject>& oMissingFiles, std::vector<InaccurateObject>& oInaccurateFiles)
{
  int answerLen = (int)Length_(iAnswer);
  int answerScopePos = AvoidBlank_<StringType, false>(iAnswer, 0, answerLen);
  if (eObject != GetPropertyValueType_(iAnswer, answerScopePos))
    return E_INVALIDARG;
  
  bool res = CopyJSONArrayElements<FCSMedia>(iAnswer, answerScopePos, answerLen, eTicketWrappers, fMedia, oMedias, {});
  res |= CopyJSONArrayElements<FetchObject>(iAnswer, answerScopePos, answerLen, eFilesNotFound, fAccessKey, oMissingFiles, {});
  res |= CopyJSONArrayElements<InaccurateObject>(iAnswer, answerScopePos, answerLen, eInaccurateFiles, fAccessKey, oInaccurateFiles, {});
  return (res ? S_OK : E_FAIL);
}
