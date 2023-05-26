#ifndef CATCompStreamOptionsForRep_h_
#define CATCompStreamOptionsForRep_h_

#include "SGComposites.h"

// SGInfra (ProtectedInterfaces)
#include "CATSGUtil.h"
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"

/**
* This composite is for specifying options or customization to be used during CGR streaming.
*/
class ExportedBySGComposites CATCompStreamOptionsForRep : public CATSGComposite
{
public:
    /**
    * This is to check global activation or deactivation of this type of composite.
    * For now, this method returns the value of the "UseStreamOptionsForRep" env variable.
    *     UseStreamOptionsForRep=1 (default) -> composite can be used.
    *     UseStreamOptionsForRep=0 -> composite cannot be used.
    */
    static const bool GetUseStreamOptionsForRep();

    /**
    * Use this method to disable CGR streaming for a given rep.
    *     iAllowStreamingInCGR=true -> Rep can be written into CGR.
    *     iAllowStreamingInCGR=false -> Rep cannot be written into CGR.
    */
    virtual HRESULT SetAllowStreamingInCGR(const bool iAllowStreamingInCGR) = 0;

    /**
    * Use this method to check is CGR streaming for a given rep is disabled or not.
    *     return true -> Rep can be written into CGR.
    *     return false -> Rep cannot be written into CGR.
    */
    virtual const bool GetAllowStreamingInCGR() const = 0;
};

// {4A6E048F-BC09-4b93-8FE2-1860C07EBC13}
static const GUID GUID_CATCompStreamOptionsForRep =
{ 0x4a6e048f, 0xbc09, 0x4b93, { 0x8f, 0xe2, 0x18, 0x60, 0xc0, 0x7e, 0xbc, 0x13 } };

template<>
class CATTraitInfo<CATCompStreamOptionsForRep>
{
public:
    static const GUID& GetTraitGUID()
    {
        return GUID_CATCompStreamOptionsForRep;
    }
    static const int GetTraitTag()
    {
        return CATECompositeTagStreamOptionsForRep;
    }
    static const CATECompositionMode GetCompositeMode()
    {
        if (CATCompStreamOptionsForRep::GetUseStreamOptionsForRep())
            return CATECompositionModeExclusive;
        else
            return CATECompositionModeNOWAY;
    }
    static const CATTraitRawInfo GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTPtr<CATCompStreamOptionsForRep>        CATCompStreamOptionsForRepPtr;
typedef CATCompositeTWeakPtr<CATCompStreamOptionsForRep>    CATCompStreamOptionsForRepWeakPtr;
typedef CATOnStackBorrowPtr<CATCompStreamOptionsForRep>     CATCompStreamOptionsForRepBorrowPtr;

/**
* Get the StreamOptionsForRep composite from the ring attached to the CATRep.
*     iCreateCompAndRing==false: oStreamOptionsForRep will be null if either the ring or the composite do not exist.
*     iCreateCompAndRing==true: oStreamOptionsForRep will never be null, because the ring and/or the composite will be created if they do not exist.
*/
HRESULT ExportedBySGComposites GetStreamOptionsForRepFromRep(CATRep* iRep, CATCompStreamOptionsForRepPtr& oStreamOptionsForRep, bool iCreateCompAndRing = false);

#endif // !CATCompStreamOptionsForRep_h_
