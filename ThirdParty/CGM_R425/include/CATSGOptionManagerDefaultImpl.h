#ifndef CATSGOptionManagerDefaultImpl_h_
#define CATSGOptionManagerDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATSGOptionManager.h"
#include "CATSGCompositeHost.h"
#include "CATUnicodeString.h"
#include "CATIOAtomics.h"

#include <unordered_map>
#include <vector>
#include <string>
#include <functional>

struct CATUnicodeStringHash
{
    std::size_t operator()(const CATUnicodeString& iStr) const { return iStr.ComputeHashKey(); }
};

/**
* Contains the name of the option and also stores the result from hash computation on the name string.
* Note: This struct is used as Key type in the hashtable on CATSGOptionManagerDefaultImpl.
*/
struct CATSGStaticOption
{
public:
    CATSGStaticOption() : CATSGStaticOption(CATUnicodeString()) {}
    explicit CATSGStaticOption(const CATUnicodeString& iName) : CATSGStaticOption(iName, CATUnicodeStringHash()(iName)) {}
    /** WARNING: make sure iHashValue originated from CATUnicodeStringHash() */
    CATSGStaticOption(const CATUnicodeString& iName, std::size_t iHashValue) : name(iName), hashValue(iHashValue) {}

    bool operator==(const CATSGStaticOption& other) const
    {
        return (hashValue == other.hashValue && name == other.name);
    }

public:
    CATUnicodeString    name;
    std::size_t         hashValue;
};

struct CATSGStaticOptionHash
{
public:
    std::size_t operator()(const CATSGStaticOption& k) const { return k.hashValue; }
};

/**
* Default implementation of CATSGOptionManager composite.
*/
class ExportedBySGComposites CATSGOptionManagerDefaultImpl : public CATSGCompositeHost1<CATSGOptionManager, CATSGComposite>
{
public:
    typedef std::unordered_map<CATSGStaticOption, float, CATSGStaticOptionHash> OptionMap;
    typedef std::pair<CATSGStaticOption, float> OptionPair;

public:
    CATSGOptionManagerDefaultImpl();
    virtual ~CATSGOptionManagerDefaultImpl();

    virtual void InitWithDefaultLDHOptions();
    virtual void InitWithEnvLDHOptions();

    virtual bool    DoesOptionExist(CATSGStaticOptionEnum iOptionEnum) const;
    virtual HRESULT GetOptionValue(CATSGStaticOptionEnum iOptionEnum, float& oOptionValue) const;
    virtual HRESULT SetOptionValue(CATSGStaticOptionEnum iOptionEnum, float iOptionValue);

    virtual bool    DoesOptionExist(const CATUnicodeString& iOptionName) const;
    virtual HRESULT GetOptionValue(const CATUnicodeString& iOptionName, float& oOptionValue) const;
    virtual HRESULT SetOptionValue(const CATUnicodeString& iOptionName, float iOptionValue);

    virtual HRESULT GetAllOptions(std::vector<std::pair<CATUnicodeString, float> >& oOptions) const;

//protected:
    virtual HRESULT _GetOptionValue(const CATUnicodeString& iOptionName, int iHashValue /* NOT ENUM */, float& oOptionValue) const;

private:
    OptionMap _map;
};

#endif	// SG_COMPOSITES_MULTIOS
#endif	// !CATSGOptionManagerDefaultImpl_h_
