#ifndef CATCompPolyhedralFlags_h_
#define CATCompPolyhedralFlags_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"

class CATRep;

typedef enum {
    CATERepOriginFlag_Undefined                 = 0,
    CATERepOriginFlag_CATBodyBuildRep           = 1,
    //CATERepOriginFlag_Other                   = 2, // <- DO NOT USE
    CATERepOriginFlag_CATBodyPHBuildRep         = 3,
    CATERepOriginFlag_CATGeoPolyBodyBuildRep    = 4
} CATERepOriginFlag;

typedef enum {
    CATETopologyFlag_Undefined      = 0,
    CATETopologyFlag_Vertex         = 1,
    CATETopologyFlag_Edge           = 2,
    CATETopologyFlag_Face           = 4,
    CATETopologyFlag_Volume         = 8
} CATETopologyFlag;

class ExportedBySGComposites CATCompPolyhedralFlags : public CATSGComposite
{
public:
    virtual HRESULT GetRepOriginFlag(unsigned char& oRepOriginFlag) const = 0;
    virtual HRESULT SetRepOriginFlag(unsigned char iRepOriginFlag) = 0;

    virtual HRESULT GetTopologyFlag(unsigned char& oTopologyFlag) const = 0;
    virtual HRESULT SetTopologyFlag(unsigned char iTopologyFlag) = 0;
};

// {54F0B133-4C36-4A44-910C-99AF828751D7}
static const GUID GUID_CATCompPolyhedralFlagsTrait =
{ 0x54f0b133, 0x4c36, 0x4a44, { 0x91, 0xc, 0x99, 0xaf, 0x82, 0x87, 0x51, 0xd7 } };

template<>
class CATTraitInfo<CATCompPolyhedralFlags>
{
public:
    static const GUID&                  GetTraitGUID()
    {
        return GUID_CATCompPolyhedralFlagsTrait;
    }
    static const int                    GetTraitTag()
    {
        return CATECompositeTagPolyhedralFlags;
    }
    static const CATECompositionMode    GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo        GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTWeakPtr<CATCompPolyhedralFlags>    CATCompPolyhedralFlagsWeakPtr;
typedef CATCompositeTPtr<CATCompPolyhedralFlags>        CATCompPolyhedralFlagsPtr;
typedef CATOnStackBorrowPtr<CATCompPolyhedralFlags>     CATCompPolyhedralFlagsBorrowPtr;

/**
* Get the PolyhedralFlags composite from the ring attached to the CATRep.
*     iCreateCompAndRing==false: oPolyFlags will be null if either the ring or the composite do not exist.
*     iCreateCompAndRing==true: oPolyFlags will never be null, because the ring and/or the composite will be created if they do not exist.
*/
HRESULT ExportedBySGComposites GetPolyhedralFlagsFromRep(CATRep* iRep, CATCompPolyhedralFlagsPtr& oPolyFlags, bool iCreateCompAndRing = false);

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompPolyhedralFlags_h_
