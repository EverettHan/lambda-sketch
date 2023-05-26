#ifndef CATISGCompositeHost_H
#define CATISGCompositeHost_H

#include "CATCmpGuid.h"
#include "IUnknown.h"

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"
#include "CATIOAtomics.h"
#include "CATSGComposite.h"

#include <atomic>
#include <vector>
#include <algorithm>

//*
#define ALLOCATE_COMP_IN_POOL
/*/
#define ALLOCATE_COMP_IN_SGPOOL
//*/
#if defined(ALLOCATE_COMP_IN_POOL)
#include "CATVizAllocator.h"
#elif defined(ALLOCATE_COMP_IN_SGPOOL)
#include "SGComposites.h"
// System (PublicInterfaces)
#include "CATSysAllocator.h"
class ExportedBySGComposites CATSGCompositesPool
{
public:
    static inline void* GetSGCompositesPool(void)
    {
        return _sgcompositesPool;
    }

    static void* PermanentAllocate(size_t iSize);
    static void PermanentDeallocate(void* iPtr, size_t iSize = NULL);

    static void* _sgcompositesPool;
};
#endif // !ALLOCATE_COMP_IN_POOL

class CATIOBuffer;
typedef CATCompositeTPtr<CATIOBuffer> CATIOBufferPtr;

/**
 * CATSGCompositeHost classes are convenience classes to build composite
 * implementations by specifying the list of trait abstract classes that you want
 * to expose yourself as. These conveniences classes implement some of the recurring
 * methods that need to be implemented for all composites so that you don't have
 * to rewrite these each time.
 *
 * See CATSGComposite documentation for more information on how these host classes
 * can be used.
 */
template<typename T>
class CATSGCompositeHost : public T
{
public:
    CATSGCompositeHost() : _refCount(0)
    {
        _sgContext = NULL;
    }

    CATSGCompositeHost(CATSGContext& iCtx) : _refCount(0)
    {
        _sgContext = &iCtx;
    }

    virtual ~CATSGCompositeHost()
    {
    }

#if defined(ALLOCATE_COMP_IN_POOL)
    void* operator new(size_t iSize) { return CATVizAllocator::PermanentAllocate(iSize); }
    void operator delete(void* iObject) { CATVizAllocator::PermanentDeallocate(iObject); }
#elif defined(ALLOCATE_COMP_IN_SGPOOL)
    void* operator new(size_t iSize) { return CATSGCompositesPool::PermanentAllocate(iSize); }
    void operator delete(void* iObject) { CATSGCompositesPool::PermanentDeallocate(iObject); }
#endif // !ALLOCATE_COMP_IN_POOL

    virtual CATINT32 __stdcall AddRef()
    {
        return _refCount.fetch_add(1) + 1;
    }

    virtual CATINT32 __stdcall Release()
    {
        CATINT32 rc = _refCount.fetch_sub(1) - 1;
        if (rc <= 0)
        {
            delete this;
        }
        return rc;
    }

    virtual HRESULT				    SetOwner(CATSGCompositeWeakPtr iOwner)
    {
        _owner = iOwner;
        return S_OK;
    }

    virtual CATSGCompositeWeakPtr	GetOwner() const
    {
        return _owner;
    }

    virtual HRESULT		OnRingEvt(const CATRingEvt& iRingEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT		OnCompositeEvt(CATCompositeEvt& iCompositeEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT OnRepEvt(const CATRepEvt& iRepEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT DispatchCompositeEvt(CATCompositeEvt& iCompositeEvt)
    {
        for (CATSGCompositePtr& it : _listeners) {
            it->OnCompositeEvt(iCompositeEvt);
        }
        return S_OK;
    }

    virtual HRESULT	RegisterEvtListener(CATSGCompositePtr& iCompositeEvtListener)
    {
        auto it = std::find(_listeners.begin(), _listeners.end(), iCompositeEvtListener);
        if (it == _listeners.end()) {
            _listeners.push_back(iCompositeEvtListener);
        }
        return S_OK;
    }

    virtual HRESULT UnRegisterEvtListener(CATSGCompositePtr& iCompositeEvtListener)
    {
        auto it = std::find(_listeners.begin(), _listeners.end(), iCompositeEvtListener);
        if (it != _listeners.end()) {
            _listeners.erase(it);
        }
        return S_OK;
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.push_back(CATTraitInfo<T>::GetRaw());
        return traitsRawInfo;
    }

    virtual CATTraitRawInfo	GetTrait() const
    {
        return CATTraitInfo<T>::GetRaw();
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return CATCmpGuid(&CATTraitInfo<T>::GetTraitGUID(), &iTraitGUID) > 0;
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T>::GetTraitTag() == iTraitTag);
    }

    virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1)
    {
        if (iIncludeStructuralSize != 0) {
            unsigned int comp = sizeof(CATSGCompositeHost<T>);
            unsigned int t = sizeof(T);
            //#define WZC_COMPRING_MEMSTAT
#ifdef WZC_COMPRING_MEMSTAT
            CATSGContext& sgCtx = CATSGContext::Get(0);
            CATSGProfilerPtr& profiler = sgCtx.GetSGProfiler();
            float current = 0;
            profiler->GetStatValue("Comp", current);
            current += comp / 1000;
            profiler->SetStatValue("Comp", current);
            profiler->GetStatValue("Host", current);
            current += (comp - t) / 1000;
            profiler->SetStatValue("Host", current);
#endif // WZC_COMPRING_MEMSTAT
            return comp;
        }
        else {
            return 0;
        }
    }

    virtual CATSGExecutionGroup*  GetExecutionGroup()
    {
        return NULL;
    }
    virtual const CATSGExecutionGroup* GetExecutionGroup() const
    {
        return NULL;
    }

    virtual CATSGContext* GetContext()
    {
        return _sgContext;
    }
    virtual const CATSGContext* GetContext() const
    {
        return _sgContext;
    }

    virtual HRESULT BorrowOutOfCoreView(CATCompOutOfCoreBorrowPtr& oOutOfCore)
    {
        return E_NOTIMPL;
    }

    HRESULT TryGetUserDataBuffer(const GUID iGUID, CATIOBufferPtr& oBuffer)
    {
        return E_NOTIMPL;
    }

    HRESULT AllocateUserDataBuffer(const GUID iGUID)
    {
        return E_NOTIMPL;
    }

    HRESULT DiscardUserDataBuffer(const GUID iGUID)
    {
        return E_NOTIMPL;
    }

protected:
    virtual void SetContext(CATSGContext* iNewContext)
    {
        _sgContext = iNewContext;
    }

private:
    std::atomic<CATINT32>               _refCount;
    CATSGCompositeWeakPtr               _owner;
    CATSGContext*                       _sgContext;
    std::vector<CATSGCompositePtr>      _listeners;
};

template<typename T>
class CATSGCompositeHostNoListeners : public T
{
public:
    CATSGCompositeHostNoListeners() : _refCount(0)
    {
        _sgContext = NULL;
    }

    CATSGCompositeHostNoListeners(CATSGContext& iCtx) : _refCount(0)
    {
        _sgContext = &iCtx;
    }

    virtual ~CATSGCompositeHostNoListeners()
    {
    }

#if defined(ALLOCATE_COMP_IN_POOL)
    void* operator new(size_t iSize) { return CATVizAllocator::PermanentAllocate(iSize); }
    void operator delete(void* iObject) { CATVizAllocator::PermanentDeallocate(iObject); }
#elif defined(ALLOCATE_COMP_IN_SGPOOL)
    void* operator new(size_t iSize) { return CATSGCompositesPool::PermanentAllocate(iSize); }
    void operator delete(void* iObject) { CATSGCompositesPool::PermanentDeallocate(iObject); }
#endif // !ALLOCATE_COMP_IN_POOL

    virtual CATINT32 __stdcall AddRef()
    {
        return _refCount.fetch_add(1) + 1;
    }

    virtual CATINT32 __stdcall Release()
    {
        CATINT32 rc = _refCount.fetch_sub(1) - 1;
        if (rc <= 0)
        {
            delete this;
        }
        return rc;
    }

    virtual HRESULT SetOwner(CATSGCompositeWeakPtr iOwner)
    {
        _owner = iOwner;
        return S_OK;
    }

    virtual CATSGCompositeWeakPtr GetOwner() const
    {
        return _owner;
    }

    virtual HRESULT OnRingEvt(const CATRingEvt& iRingEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT OnCompositeEvt(CATCompositeEvt& iCompositeEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT OnRepEvt(const CATRepEvt& iRepEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT DispatchCompositeEvt(CATCompositeEvt& iCompositeEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT RegisterEvtListener(CATSGCompositePtr &iCompositeEvtListener)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT UnRegisterEvtListener(CATSGCompositePtr &iCompositeEvtListener)
    {
        return E_NOTIMPL;
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.push_back(CATTraitInfo<T>::GetRaw());
        return traitsRawInfo;
    }

    virtual CATTraitRawInfo GetTrait() const
    {
        return CATTraitInfo<T>::GetRaw();
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return CATCmpGuid(&CATTraitInfo<T>::GetTraitGUID(), &iTraitGUID) > 0;
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T>::GetTraitTag() == iTraitTag);
    }

    virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1)
    {
        if (iIncludeStructuralSize != 0) {
            unsigned int comp = sizeof(CATSGCompositeHostNoListeners<T>);
            unsigned int t = sizeof(T);
            //#define WZC_COMPRING_MEMSTAT
#ifdef WZC_COMPRING_MEMSTAT
            CATSGContext& sgCtx = CATSGContext::Get(0);
            CATSGProfilerPtr& profiler = sgCtx.GetSGProfiler();
            float current = 0;
            profiler->GetStatValue("Comp", current);
            current += comp / 1000;
            profiler->SetStatValue("Comp", current);
            profiler->GetStatValue("Host", current);
            current += (comp - t) / 1000;
            profiler->SetStatValue("Host", current);
#endif // WZC_COMPRING_MEMSTAT
            return comp;
        }
        else {
            return 0;
        }
    }

    virtual CATSGExecutionGroup* GetExecutionGroup()
    {
        return NULL;
    }
    virtual const CATSGExecutionGroup* GetExecutionGroup() const
    {
        return NULL;
    }

    virtual CATSGContext* GetContext()
    {
        return _sgContext;
    }
    virtual const CATSGContext* GetContext() const
    {
        return _sgContext;
    }

    virtual HRESULT BorrowOutOfCoreView(CATCompOutOfCoreBorrowPtr& oOutOfCore)
    {
        return E_NOTIMPL;
    }

    HRESULT TryGetUserDataBuffer(const GUID iGUID, CATIOBufferPtr& oBuffer)
    {
        return E_NOTIMPL;
    }

    HRESULT AllocateUserDataBuffer(const GUID iGUID)
    {
        return E_NOTIMPL;
    }

    HRESULT DiscardUserDataBuffer(const GUID iGUID)
    {
        return E_NOTIMPL;
    }

protected:
    virtual void SetContext(CATSGContext* iNewContext)
    {
        _sgContext = iNewContext;
    }

private:
    std::atomic<CATINT32>               _refCount;
    CATSGCompositeWeakPtr               _owner;
    CATSGContext*                       _sgContext;
};

template<typename T>
class CATSGCompositeHostDedicated : public T
{
public:
    CATSGCompositeHostDedicated() : _refCount(0)
    {
    }

    CATSGCompositeHostDedicated(CATSGContext& iCtx) : _refCount(0)
    {
    }

    virtual ~CATSGCompositeHostDedicated()
    {
    }

#if defined(ALLOCATE_COMP_IN_POOL)
    void* operator new(size_t iSize) { return CATVizAllocator::PermanentAllocate(iSize); }
    void operator delete(void* iObject) { CATVizAllocator::PermanentDeallocate(iObject); }
#elif defined(ALLOCATE_COMP_IN_SGPOOL)
    void* operator new(size_t iSize) { return CATSGCompositesPool::PermanentAllocate(iSize); }
    void operator delete(void* iObject) { CATSGCompositesPool::PermanentDeallocate(iObject); }
#endif // !ALLOCATE_COMP_IN_POOL

    virtual CATINT32 __stdcall AddRef()
    {
        return _refCount.fetch_add(1) + 1;
    }

    virtual CATINT32 __stdcall Release()
    {
        CATINT32 rc = _refCount.fetch_sub(1) - 1;
        if (rc <= 0)
        {
            delete this;
        }
        return rc;
    }

    virtual HRESULT SetOwner(CATSGCompositeWeakPtr iOwner)
    {
        return E_NOTIMPL;
    }

    virtual CATSGCompositeWeakPtr GetOwner() const
    {
        return CATSGCompositeWeakPtr();
    }

    virtual HRESULT OnRingEvt(const CATRingEvt& iRingEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT OnCompositeEvt(CATCompositeEvt& iCompositeEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT OnRepEvt(const CATRepEvt& iRepEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT DispatchCompositeEvt(CATCompositeEvt& iCompositeEvt)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT RegisterEvtListener(CATSGCompositePtr &iCompositeEvtListener)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT UnRegisterEvtListener(CATSGCompositePtr &iCompositeEvtListener)
    {
        return E_NOTIMPL;
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.push_back(CATTraitInfo<T>::GetRaw());
        return traitsRawInfo;
    }

    virtual CATTraitRawInfo GetTrait() const
    {
        return CATTraitInfo<T>::GetRaw();
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return CATCmpGuid(&CATTraitInfo<T>::GetTraitGUID(), &iTraitGUID) > 0;
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T>::GetTraitTag() == iTraitTag);
    }

    virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1)
    {
        if (iIncludeStructuralSize != 0) {
            unsigned int comp = sizeof(CATSGCompositeHostNoListeners<T>);
            unsigned int t = sizeof(T);
            //#define WZC_COMPRING_MEMSTAT
#ifdef WZC_COMPRING_MEMSTAT
            CATSGContext& sgCtx = CATSGContext::Get(0);
            CATSGProfilerPtr& profiler = sgCtx.GetSGProfiler();
            float current = 0;
            profiler->GetStatValue("Comp", current);
            current += comp / 1000;
            profiler->SetStatValue("Comp", current);
            profiler->GetStatValue("Host", current);
            current += (comp - t) / 1000;
            profiler->SetStatValue("Host", current);
#endif // WZC_COMPRING_MEMSTAT
            return comp;
        }
        else {
            return 0;
        }
    }

    virtual CATSGExecutionGroup* GetExecutionGroup()
    {
        return NULL;
    }
    virtual const CATSGExecutionGroup* GetExecutionGroup() const
    {
        return NULL;
    }

    virtual CATSGContext* GetContext() = 0;
    virtual const CATSGContext* GetContext() const = 0;

    virtual HRESULT BorrowOutOfCoreView(CATCompOutOfCoreBorrowPtr& oOutOfCore)
    {
        return E_NOTIMPL;
    }

    HRESULT TryGetUserDataBuffer(const GUID iGUID, CATIOBufferPtr& oBuffer)
    {
        return E_NOTIMPL;
    }

    HRESULT AllocateUserDataBuffer(const GUID iGUID)
    {
        return E_NOTIMPL;
    }

    HRESULT DiscardUserDataBuffer(const GUID iGUID)
    {
        return E_NOTIMPL;
    }

protected:
    virtual void SetContext(CATSGContext* iNewContext)
    {
        // cannot do anything since CATSGContext pointer is not store in the composite
    }

private:
    std::atomic<CATINT32> _refCount;
};

/**
 * Check CATSGCompositeHost documentation for more details.
 */
template<typename T1, typename T0>
class CATSGCompositeHost1 : public CATSGCompositeHost<T1>
{
public:
    CATSGCompositeHost1()
    {

    }
    CATSGCompositeHost1(CATSGContext& iCtx) : CATSGCompositeHost<T1>(iCtx)
    {

    }
    virtual ~CATSGCompositeHost1()
    {
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.reserve(2);
        traitsRawInfo.push_back(CATTraitInfo<T1>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T0>::GetRaw());
        return traitsRawInfo;
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return (CATCmpGuid(&CATTraitInfo<T1>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T0>::GetTraitGUID(), &iTraitGUID) > 0);
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T1>::GetTraitTag() == iTraitTag || CATTraitInfo<T0>::GetTraitTag() == iTraitTag);
    }
};

template<typename T1, typename T0>
class CATSGCompositeHost1NoListeners : public CATSGCompositeHostNoListeners<T1>
{
public:
    CATSGCompositeHost1NoListeners()
    {

    }
    CATSGCompositeHost1NoListeners(CATSGContext& iCtx) : CATSGCompositeHostNoListeners<T1>(iCtx)
    {

    }
    virtual ~CATSGCompositeHost1NoListeners()
    {
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.reserve(2);
        traitsRawInfo.push_back(CATTraitInfo<T1>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T0>::GetRaw());
        return traitsRawInfo;
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return (CATCmpGuid(&CATTraitInfo<T1>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T0>::GetTraitGUID(), &iTraitGUID) > 0);
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T1>::GetTraitTag() == iTraitTag || CATTraitInfo<T0>::GetTraitTag() == iTraitTag);
    }
};

template<typename T1, typename T0>
class CATSGCompositeHost1Dedicated : public CATSGCompositeHostDedicated<T1>
{
public:
    CATSGCompositeHost1Dedicated()
    {

    }
    CATSGCompositeHost1Dedicated(CATSGContext& iCtx) : CATSGCompositeHostDedicated<T1>(iCtx)
    {

    }
    virtual ~CATSGCompositeHost1Dedicated()
    {
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.reserve(2);
        traitsRawInfo.push_back(CATTraitInfo<T1>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T0>::GetRaw());
        return traitsRawInfo;
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return (CATCmpGuid(&CATTraitInfo<T1>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T0>::GetTraitGUID(), &iTraitGUID) > 0);
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T1>::GetTraitTag() == iTraitTag || CATTraitInfo<T0>::GetTraitTag() == iTraitTag);
    }
};

/**
 * Check CATSGCompositeHost documentation for more details.
 */
template<typename T2, typename T1, typename T0>
class CATSGCompositeHost2 : public CATSGCompositeHost1<T2, T1>
{
public:
    CATSGCompositeHost2()
    {

    }
    CATSGCompositeHost2(CATSGContext& iCtx) : CATSGCompositeHost1<T2, T1>(iCtx)
    {

    }
    virtual ~CATSGCompositeHost2()
    {
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.reserve(3);
        traitsRawInfo.push_back(CATTraitInfo<T2>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T1>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T0>::GetRaw());
        return traitsRawInfo;
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return (CATCmpGuid(&CATTraitInfo<T2>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T1>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T0>::GetTraitGUID(), &iTraitGUID) > 0);
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T2>::GetTraitTag() == iTraitTag || CATTraitInfo<T1>::GetTraitTag() == iTraitTag || CATTraitInfo<T0>::GetTraitTag() == iTraitTag);
    }
};

template<typename T2, typename T1, typename T0>
class CATSGCompositeHost2NoListeners : public CATSGCompositeHost1NoListeners<T2, T1>
{
public:
    CATSGCompositeHost2NoListeners()
    {

    }
    CATSGCompositeHost2NoListeners(CATSGContext& iCtx) : CATSGCompositeHost1NoListeners<T2, T1>(iCtx)
    {

    }
    virtual ~CATSGCompositeHost2NoListeners()
    {
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.reserve(3);
        traitsRawInfo.push_back(CATTraitInfo<T2>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T1>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T0>::GetRaw());
        return traitsRawInfo;
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return (CATCmpGuid(&CATTraitInfo<T2>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T1>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T0>::GetTraitGUID(), &iTraitGUID) > 0);
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T2>::GetTraitTag() == iTraitTag || CATTraitInfo<T1>::GetTraitTag() == iTraitTag || CATTraitInfo<T0>::GetTraitTag() == iTraitTag);
    }
};

template<typename T2, typename T1, typename T0>
class CATSGCompositeHost2Dedicated : public CATSGCompositeHost1Dedicated<T2, T1>
{
public:
    CATSGCompositeHost2Dedicated()
    {

    }
    CATSGCompositeHost2Dedicated(CATSGContext& iCtx) : CATSGCompositeHost1Dedicated<T2, T1>(iCtx)
    {

    }
    virtual ~CATSGCompositeHost2Dedicated()
    {
    }

    virtual CATTraitsRawInfo GetTraits() const
    {
        CATTraitsRawInfo traitsRawInfo;
        traitsRawInfo.reserve(3);
        traitsRawInfo.push_back(CATTraitInfo<T2>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T1>::GetRaw());
        traitsRawInfo.push_back(CATTraitInfo<T0>::GetRaw());
        return traitsRawInfo;
    }

    virtual const bool IsTraitSupported(const GUID& iTraitGUID) const
    {
        return (CATCmpGuid(&CATTraitInfo<T2>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T1>::GetTraitGUID(), &iTraitGUID) > 0) || (CATCmpGuid(&CATTraitInfo<T0>::GetTraitGUID(), &iTraitGUID) > 0);
    }

    virtual const bool IsTraitSupported(const CATTraitTag& iTraitTag) const
    {
        return iTraitTag >= 0 && (CATTraitInfo<T2>::GetTraitTag() == iTraitTag || CATTraitInfo<T1>::GetTraitTag() == iTraitTag || CATTraitInfo<T0>::GetTraitTag() == iTraitTag);
    }
};
#endif // SG_COMPOSITES_MULTIOS
#endif // CATISGComposite_H


