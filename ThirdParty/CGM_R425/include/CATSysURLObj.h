
#ifndef CATSysURLObj_H
#define CATSysURLObj_H

#include "JS0HTTP.h"
#include "CATSysErrorDef.h"
#include "DSYString.h"
#include "CATHttpTools.h" // CATSysURL

#include <string>
#include <string_view>


/** 
 * CATSysURLObj.
 * Efficient wrapper for CATSysURL.
 */
class ExportedByJS0HTTP CATSysURLObj final
{
    // Rely on std::string_view in order to avoid unnecessary memory allocations
public:
    CATSysURLObj(std::string_view const & iUrl);    // no need for a constructor taking an "std::string" argument
    CATSysURLObj(const CATUnicodeString &iszUrl);
    CATSysURLObj(const char *iszUrl) : CATSysURLObj( std::string_view{iszUrl} ) {}
    CATSysURLObj(const wchar_t *iszUrl);
    CATSysURLObj(const CATSysURLObj & iOther);
    CATSysURLObj(CATSysURLObj && iRValue);          // Move constructor
    CATSysURLObj& operator=(CATSysURLObj iOther);
    ~CATSysURLObj();    // Non-virtual, cf. final class
    
    // DO NOT expose "m_UrlStruct" directly! Indeed, it holds pointers to non-const data!
    std::string_view  GetScheme() const { return { m_UrlStruct.lpszScheme, m_UrlStruct.dwSchemeLength }; }
    std::string_view  GetHost() const { return { m_UrlStruct.lpszHostName, m_UrlStruct.dwHostNameLength }; }
    std::string_view  GetPort() const { return { this->m_Port }; }
    std::string_view  GetPath() const { return { m_UrlStruct.lpszUrlPath, m_UrlStruct.dwUrlPathLength }; }
    std::string_view  GetUserName() const { return { m_UrlStruct.lpszUserName, m_UrlStruct.dwUserNameLength }; }
    std::string_view  GetPassword() const { return { m_UrlStruct.lpszPassword, m_UrlStruct.dwPasswordLength }; }
    std::string_view  GetExtraInfo() const { return { m_UrlStruct.lpszExtraInfo, m_UrlStruct.dwExtraInfoLength }; }

    bool IsValid() const { return SUCCEEDED(m_hrInit); }
    
    [[deprecated("Use IsValid() which is const instead.")]]
    HRESULT Init() { return m_hrInit; }
    
    // Returns the native-format representation of the URL:
    // normalized, lower-case URL string, that is suitable for comparison (as an alternative to operator==)
    operator std::string_view() const { return _getUrl(); } // cf. inspired by "std::filesystem::path"
    
    [[deprecated("Use 'operator std::string_view()' instead.")]]
    CATUnicodeString ToString() const { return _getUrl().data(); }
    
    bool operator ==(const CATSysURLObj & iComparand) const;
    bool operator !=(const CATSysURLObj & iComparand) const { return !(*this == iComparand); }
    
private:

    std::string_view _getUrl() const;

    // Members
    CATSysURL m_UrlStruct;
    mutable std::string m_szUrl;
    std::string m_Port;
    HRESULT m_hrInit;
};



inline CATSysURLObj::CATSysURLObj(CATSysURLObj && iRValue)
 : m_UrlStruct(iRValue.m_UrlStruct), m_szUrl(iRValue.m_szUrl)
 , m_Port(iRValue.m_Port), m_hrInit(iRValue.m_hrInit)
{
    memset(&iRValue.m_UrlStruct, 0, sizeof(CATSysURL));
}


#endif  // CATSysURLObj_H
