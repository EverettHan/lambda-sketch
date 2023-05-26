#ifndef CATSGOptionManager_H
#define CATSGOptionManager_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGComposite.h"
#include "CATUnicodeString.h"

#include <vector>
#include <utility>

enum CATSGStaticOptionEnum
{
    #define DeclareCATSGStaticOption(name, defaultValue) name,
    #include "CATSGStaticOptions.h"
    #undef DeclareCATSGStaticOption
    CATSGStaticOptionsCount
};

class ExportedBySGComposites CATSGOptionManager : public CATSGComposite
{
public:
    virtual bool    DoesOptionExist(CATSGStaticOptionEnum iOptionEnum) const = 0;
    virtual HRESULT GetOptionValue(CATSGStaticOptionEnum iOptionEnum, float& oOptionValue) const = 0;
    virtual HRESULT SetOptionValue(CATSGStaticOptionEnum iOptionEnum, float iOptionValue) = 0;

    virtual bool    DoesOptionExist(const CATUnicodeString& iOptionName) const = 0;
    virtual HRESULT GetOptionValue(const CATUnicodeString& iOptionName, float& oOptionValue) const = 0;
    virtual HRESULT SetOptionValue(const CATUnicodeString& iOptionName, float iOptionValue) = 0;

    virtual HRESULT GetAllOptions(std::vector<std::pair<CATUnicodeString, float> >& oOptions) const = 0;

//protected:
    virtual HRESULT _GetOptionValue(const CATUnicodeString& iOptionName, int iHashValue /* NOT ENUM */, float& oOptionValue) const = 0;
};

// {34BD68C3-3661-4C7F-A12B-3C9ACDAE378B}
static const GUID GUID_CATSGOptionManagerTrait =
{ 0x34bd68c3, 0x3661, 0x4c7f, { 0xa1, 0x2b, 0x3c, 0x9a, 0xcd, 0xae, 0x37, 0x8b } };

HRESULT ExportedBySGComposites GetSGOptionValueFromContext(CATSGContext* ctx, CATSGStaticOptionEnum iOptionEnum, float& oOptionValue);
HRESULT ExportedBySGComposites GetSGOptionValueFromDefaultContext(CATSGStaticOptionEnum iOptionEnum, float& oOptionValue);

template<>
class CATTraitInfo<CATSGOptionManager>
{
public:
    static const GUID&                  GetTraitGUID()
    {
        return GUID_CATSGOptionManagerTrait;
    }
    static const int                    GetTraitTag() { return CATTraitTag(-1); }
    static const CATECompositionMode    GetCompositeMode()
    {
        return CATECompositionModeParticular;
    }
    static const CATTraitRawInfo        GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTPtr<CATSGOptionManager> CATSGOptionManagerPtr;

#endif    // SG_COMPOSITES_MULTIOS
#endif    // CATSGOptionManagery_H
