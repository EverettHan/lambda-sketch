#ifndef CATSGClientManager_h_
#define CATSGClientManager_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"
#include "CATCompSerializationContext.h"

class ExportedBySGComposites CATSGClientManager : public CATSGComposite
{
public:
    virtual HRESULT ProcessClientJobs() = 0;
};

// {24E85A81-970C-4E8D-9C72-1AB2F0AA510E}
static const GUID GUID_CATSGClientManagerTrait =
{ 0x24e85a81, 0x970c, 0x4e8d, { 0x9c, 0x72, 0x1a, 0xb2, 0xf0, 0xaa, 0x51, 0xe } };

template<>
class CATTraitInfo<CATSGClientManager>
{
public:
    static const GUID&                  GetTraitGUID()
    {
        return GUID_CATSGClientManagerTrait;
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

typedef CATCompositeTWeakPtr<CATSGClientManager>    CATSGClientManagerWeakPtr;
typedef CATCompositeTPtr<CATSGClientManager>        CATSGClientManagerPtr;
typedef CATOnStackBorrowPtr<CATSGClientManager>     CATSGClientManagerBorrowPtr;

#endif // end of #ifdef SG_COMPOSITES_MULTIOS
#endif // !CATSGClientManager_h_
