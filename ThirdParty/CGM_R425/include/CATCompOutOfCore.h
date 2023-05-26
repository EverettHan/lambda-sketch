#ifndef CATCompOutOfCore_H
#define CATCompOutOfCore_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"

#include "CATSGManager.h"
#include "CATCompositeTPtr.h"
// #include "CATCompositePtrList.h"
#include "CATSGComposite.h"

#ifndef _EMSCRIPTEN_TESTS
#include "CATIOManager.h"
#endif//!_EMSCRIPTEN_TESTS

class CATRep;
class CATSGMsgLoopJobs;

typedef std::uint8_t CATLoadCompletionLevel;
typedef float CATLoadPriority;

/**
 * CATCompOutOfCore should be used as base interface for all aspects
 * of the REP that are not necessarily loaded all the time and that
 * might need frequent load/unload or that might have different representation
 * at varying load level.
 */
class ExportedBySGComposites CATCompOutOfCore : public CATSGComposite
{
public:

    virtual HRESULT StreamTo(const CATLoadCompletionLevel iCompletionLevel, const CATLoadPriority iPriority, CATSGMsgLoopJobs* ioJobs = NULL) = 0;
    virtual HRESULT ForceStreamTo(const CATLoadCompletionLevel iCompletionLevel) = 0;

    virtual const CATLoadCompletionLevel GetLoadLevel() = 0;
    virtual const CATLoadPriority        GetCurrentLoadPriority() = 0;

    virtual HRESULT                      BuildRawBuffer(void*& oBuffer, int& oBufferSize) = 0;

    /**
     * If the OutOfCore has a composite representation you can get at it through this method.
     * If the OutOfCore has no composite representation for the current load level it should
     * return E_INVALIDSTATE. If on the other hand this OutOfCore has no composite representation
     * whatever it's load level then it should return E_FAIL.
     *
     * There is something more to say about this method. If the OutOfCOre is meant to have a composite
     * reprensentation that is intended to participate in the same ring this OutOfCore is part of the
     * clearly this composite should be explicitely added to the ring to have exposition at that level.
     * The ring won't ever try to use directly this method to see if it should auto magically handle
     * a potentiel composite as if it was part of the current ring. We leave total control here and
     * if indeed the OutOfCore wants to see it's composite to participate in the ring it should
     * add it explicitely to it. This can be done for example by registering a post render job
     * against the scene manager!
     */
    virtual HRESULT BuildComposite(CATSGCompositePtr& oComposite) = 0;

    virtual void SetVisibleAtFrame(uint8_t frame) = 0;
};

// {44E78CE7-E0DD-4EF4-9D06-DBF9C4A12780}
static const GUID GUID_CATCompOutOfCoreTrait =
{ 0xb01a8a5e, 0x6d52, 0x4c5a, { 0x8b, 0xef, 0xe, 0xad, 0x2a, 0x35, 0x4c, 0x3a } };

template<>
class CATTraitInfo<CATCompOutOfCore>
{
public:
    static const GUID& GetTraitGUID()
    {
        return GUID_CATCompOutOfCoreTrait;
    }
    static const int GetTraitTag() { return CATTraitTag(CATECompositeTagOutOfCore); }
    static const CATECompositionMode GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef ExportedBySGComposites CATCompositeTPtr<CATCompOutOfCore> CATCompOutOfCorePtr;
typedef ExportedBySGComposites std::vector<CATCompOutOfCorePtr> CATCompOutOfCores;
typedef ExportedBySGComposites CATOnStackBorrowPtr<CATCompOutOfCore> CATCompOutOfCoreBorrowPtr;
typedef ExportedBySGComposites CATCompositeTWeakPtr<CATCompOutOfCore> CATCompOutOfCoreWeakPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompOutOfCore_H
