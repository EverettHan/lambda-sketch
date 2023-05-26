//===================================================================
// COPYRIGHT Dassault Systemes 2015/08/21
//===================================================================
// CATSGSerializationSurrogateTemplateBinder.cpp
// Header definition of class CATSGSerializationSurrogateTemplateBinder
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/08/21 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATSGSerializationSurrogateTemplateBinder_h_
#define CATSGSerializationSurrogateTemplateBinder_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGContext.h"
#include "CATCompOutOfCore.h"
#include "CATCompMesh.h"
#include "CATSGSerializationSurrogateTemplate.h"
#include "CATCompStream.h"
#include "CATIOBinders.h"
#include "CATCompSerializationContext.h"


/**
 * Base Class of all CATSGSerializationSurrogateTemplateBinderXArg, it just holds
 * a few methods to stream/unstream method ID and the composite calling the binded method.
 * There is one subclass for each binder type.
 * Be careful that for certain arguments with const qualifiers or references, partial
 * template specialization of CATSGSerializationSurrogateTemplateBinderXArg might be needed, due
 * to limitations of other templated class such as CATSGSerializationSurrogateTemplate and
 * CATIOBinder.
 */
template<typename T>
class CATSGSerializationSurrogateTemplateBinder
{
protected:
    static inline HRESULT StreamMethodAndCaller(CATCompSerializationContextPtr& iSerializationCtx,
                                                CATCompStreamPtr&               iStream,
                                                T*                              ipComp,
                                                CATUnicodeString&               iMethodID)
    {
        HRESULT hr = S_OK;
        hr = CATSGSerializationSurrogateTemplate<CATUnicodeString>::Stream(iSerializationCtx, iStream, iMethodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::StreamMethodAndCaller, failed to stream method ID");
            return hr;
        }
        if(CATTraitInfo<T>::GetCompositeMode() != CATECompositionModeParticular) {
            CATSGCompositePtr compPtr (ipComp);
            CATSGRef compRef;
            hr = iSerializationCtx->Stream(compPtr, compRef);
            if(FAILED(hr)) {
                CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::StreamMethodAndCaller, failed to stream composite");
                return hr;
            }
            hr = iStream->WriteRef(compRef);
            if(FAILED(hr)) {
                CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::StreamMethodAndCaller, failed to write reference");
                return hr;
            }
        }
        return S_OK;
    }

    static inline HRESULT UnStreamMethodAndCaller(CATCompSerializationContextPtr& iSerializationCtx,
                                                  CATCompStreamPtr&               iStream,
                                                  T*&                             opComp,
                                                  CATUnicodeString&               oMethodID)
    {
        HRESULT hr = S_OK;
        hr = CATSGSerializationSurrogateTemplate<CATUnicodeString>::UnStream(iSerializationCtx, iStream, oMethodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::UnStreamMethodAndCaller, failed to unstream method ID");
            return hr;
        }
        if(CATTraitInfo<T>::GetCompositeMode() == CATECompositionModeParticular) {
            CATOnStackBorrowBasePtr brwPtr;
            hr = CATSGContext::Get(0).GetExtraManager(CATTraitInfo<T>::GetRaw(), brwPtr);
            if(SUCCEEDED(hr)) {
                opComp = (T*) brwPtr.PtrAsVoid();
                if(!opComp) {
                    CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::UnStreamMethodAndCaller, unstreamed composite is of unexpected type");
                    return E_FAIL;
                }
            } else {
                CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::UnStreamMethodAndCaller, failed to get manager");
                return hr;
            }
        } else {
            CATSGCompositePtr compPtr;
            CATSGRef compRef;
            hr = iStream->ReadRef(compRef);
            if(FAILED(hr)) {
                CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::UnStreamMethodAndCaller, failed to read reference");
                return hr;
            }
            hr = iSerializationCtx->UnStream(compRef, compPtr);
            if(FAILED(hr)) {
                CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::UnStreamMethodAndCaller, failed to unstream composite");
                return hr;
            }
            opComp = (T*) compPtr.Ptr();
            if(!opComp) {
                CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder::UnStreamMethodAndCaller, unstreamed composite is of unexpected type");
                return E_FAIL;
            }
            opComp->AddRef();
        }
        return S_OK;
    }
};

template<typename T, typename R, template <class> class LifeCyclePolicy>
class CATSGSerializationSurrogateTemplateBinderNoArg : public CATSGSerializationSurrogateTemplateBinder<T>
{
public:

    static HRESULT StreamBinderNoArg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                     CATIOBinderNoArg<T, R, LifeCyclePolicy>* ipBinder)
    {
        HRESULT hr = S_OK;
        CATUnicodeString methodID;

        hr = CATTraitInfo<T>::GetBindableMethodID(ipBinder->GetMethod(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderNoArg::StreamBinderNoArg, failed to get method ID");
            return hr;
        }
        hr = CATSGSerializationSurrogateTemplateBinder<T>::StreamMethodAndCaller(iSerializationCtx, iStream, ipBinder->GetThis(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderNoArg::StreamBinderNoArg, failed to stream method and caller");
            return hr;
        }
        return S_OK;
    }

    static HRESULT UnStreamBinderNoArg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                       CATIOBinderNoArg<T, R, LifeCyclePolicy>*& opBinder)
    {
        HRESULT hr = S_OK;
        T* pComp = NULL;
        CATUnicodeString methodID;

        hr = CATSGSerializationSurrogateTemplateBinder<T>::UnStreamMethodAndCaller(iSerializationCtx, iStream, pComp, methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderNoArg::UnStreamBinderNoArg, failed to unstream method ID and caller");
            return hr;
        }
        R (T::*pMethod)() = NULL;
        hr = CATTraitInfo<T>::GetBindableMethod(methodID,pMethod);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderNoArg::UnStreamBinderNoArg, failed to get method to stream");
            return hr;
        }
        opBinder = new CATIOBinderNoArg<T, R, LifeCyclePolicy>(pMethod,pComp);
        return S_OK;
    }

};

template<typename T, typename A0, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATSGSerializationSurrogateTemplateBinder1Arg : public CATSGSerializationSurrogateTemplateBinder<T>
{
public:

    static HRESULT StreamBinder1Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                    CATIOBinder1Arg<T, A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>* ipBinder)
    {
        HRESULT hr = S_OK;
        CATUnicodeString methodID;

        hr = CATTraitInfo<T>::GetBindableMethodID(ipBinder->GetMethod(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::StreamBinder1Arg, failed to get method ID");
            return hr;
        }
        hr = CATSGSerializationSurrogateTemplateBinder<T>::StreamMethodAndCaller(iSerializationCtx, iStream, ipBinder->GetThis(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::StreamBinder1Arg, failed to stream method ID and caller");
            return hr;
        }
        A0 arg0 = ipBinder->GetArg0();
        hr = CATSGSerializationSurrogateTemplate<A0>::Stream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::StreamBinder1Arg, failed to stream first argument");
            return hr;
        }
        return S_OK;
    }

    static HRESULT UnStreamBinder1Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                      CATIOBinder1Arg<T, A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>*& opBinder)
    {
        HRESULT hr = S_OK;
        T* pComp = NULL;
        CATUnicodeString methodID;

        hr = CATSGSerializationSurrogateTemplateBinder<T>::UnStreamMethodAndCaller(iSerializationCtx, iStream, pComp, methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::UnStreamBinder1Arg, failed to unstream method ID and caller");
            return hr;
        }
        R (T::*pMethod)(A0) = NULL;
        hr = CATTraitInfo<T>::GetBindableMethod(methodID,pMethod);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::UnStreamBinder1Arg, failed to get method to stream");
            return hr;
        }
        A0 arg0;
        hr = CATSGSerializationSurrogateTemplate<A0>::UnStream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::UnStreamBinder1Arg, failed to unstream first argument");
            return hr;
        }
        opBinder = new CATIOBinder1Arg<T, A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>(pMethod,pComp,arg0);
        return S_OK;
    }
};

template<typename T, typename A0, typename R, template <class> class LifeCyclePolicy,
         template <class> class Arg0LifeCyclePolicy, CATECleanArguments CleanArgs>
class CATSGSerializationSurrogateTemplateBinder1Arg<T, const A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs> : public CATSGSerializationSurrogateTemplateBinder<T>
{
public:

    static HRESULT StreamBinder1Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                    CATIOBinder1Arg<T, const A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>* ipBinder)
    {
        HRESULT hr = S_OK;
        CATUnicodeString methodID;

        hr = CATTraitInfo<T>::GetBindableMethodID(ipBinder->GetMethod(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::StreamBinder1Arg, failed to get method ID");
            return hr;
        }
        hr = CATSGSerializationSurrogateTemplateBinder<T>::StreamMethodAndCaller(iSerializationCtx, iStream, ipBinder->GetThis(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::StreamBinder1Arg, failed to stream method ID and caller");
            return hr;
        }
        A0 arg0 = ipBinder->GetArg0();
        hr = CATSGSerializationSurrogateTemplate<A0>::Stream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::StreamBinder1Arg, failed to stream first argument");
            return hr;
        }
        return S_OK;
    }

    static HRESULT UnStreamBinder1Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                      CATIOBinder1Arg<T, const A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>*& opBinder)
    {
        HRESULT hr = S_OK;
        T* pComp = NULL;
        CATUnicodeString methodID;

        hr = CATSGSerializationSurrogateTemplateBinder<T>::UnStreamMethodAndCaller(iSerializationCtx, iStream, pComp, methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::UnStreamBinder1Arg, failed to unstream method and caller");
            return hr;
        }
        R (T::*pMethod)(const A0) = NULL;
        hr = CATTraitInfo<T>::GetBindableMethod(methodID,pMethod);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::UnStreamBinder1Arg, failed to get method to stream");
            return hr;
        }
        A0 arg0;
        hr = CATSGSerializationSurrogateTemplate<A0>::UnStream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder1Arg::UnStreamBinder1Arg, failed to unstream first argument");
            return hr;
        }
        opBinder = new CATIOBinder1Arg<T, const A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>(pMethod, pComp, arg0);
        return S_OK;
    }
};

template<typename T, typename A0, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy, CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATSGSerializationSurrogateTemplateBinderF1Arg : public CATSGSerializationSurrogateTemplateBinder<T>
{
public:

    static HRESULT StreamBinderF1Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                    CATIOBinderF1Arg<T, A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>* ipBinder)
    {
        HRESULT hr = S_OK;
        CATUnicodeString methodID;

        hr = CATTraitInfo<T>::GetBindableMethodID(ipBinder->GetMethod(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderF1Arg::StreamBinderF1Arg, failed to get method ID");
            return hr;
        }
        hr = CATSGSerializationSurrogateTemplateBinder<T>::StreamMethodAndCaller(iSerializationCtx, iStream, ipBinder->GetThis(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderF1Arg::StreamBinderF1Arg, failed to stream method ID and caller");
            return hr;
        }
        A0 arg0 = ipBinder->GetArg0();
        hr = CATSGSerializationSurrogateTemplate<A0>::Stream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderF1Arg::StreamBinderF1Arg, failed to stream first argument");
            return hr;
        }
        return S_OK;
    }


    static HRESULT UnStreamBinderF1Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                      CATIOBinderF1Arg<T, A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>*& opBinder)
    {
        HRESULT hr = S_OK;
        T* pComp = NULL;
        CATUnicodeString methodID;

        hr = CATSGSerializationSurrogateTemplateBinder<T>::UnStreamMethodAndCaller(iSerializationCtx, iStream, pComp, methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderF1Arg::UnStreamBinderF1Arg, failed to unstream method ID and caller");
            return hr;
        }
        R (T::*pMethod)(CATIOFuture<A0>) = NULL;
        hr = CATTraitInfo<T>::GetBindableMethod(methodID,pMethod);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderF1Arg::UnStreamBinderF1Arg, failed to get method");
            return hr;
        }
        A0 arg0;
        hr = CATSGSerializationSurrogateTemplate<A0>::UnStream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinderF1Arg::UnStreamBinderF1Arg, failed to unstream first argument");
            return hr;
        }
        opBinder = new CATIOBinderF1Arg<T, A0, R, LifeCyclePolicy, Arg0LifeCyclePolicy, CleanArgs>(pMethod,pComp,arg0);
        return S_OK;
    }

};

template<typename T, typename A0, typename A1, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg1LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATSGSerializationSurrogateTemplateBinder2Arg : public CATSGSerializationSurrogateTemplateBinder<T>
{
public:

    static HRESULT StreamBinder2Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                    CATIOBinder2Arg<T, A0, A1, R, LifeCyclePolicy, Arg0LifeCyclePolicy, Arg1LifeCyclePolicy, CleanArgs>* ipBinder)
    {
        HRESULT hr = S_OK;
        CATUnicodeString methodID;

        hr = CATTraitInfo<T>::GetBindableMethodID(ipBinder->GetMethod(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::StreamBinder2Arg, failed to get method ID");
            return hr;
        }
        hr = CATSGSerializationSurrogateTemplateBinder<T>::StreamMethodAndCaller(iSerializationCtx, iStream, ipBinder->GetThis(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::StreamBinder2Arg, failed to stream method ID and caller");
            return hr;
        }
        A0 arg0 = ipBinder->GetArg0();
        hr = CATSGSerializationSurrogateTemplate<A0>::Stream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::StreamBinder2Arg, failed to stream first argument");
            return hr;
        }
        A1 arg1 = ipBinder->GetArg1();
        hr = CATSGSerializationSurrogateTemplate<A1>::Stream(iSerializationCtx, iStream, arg1);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::StreamBinder2Arg, failed to stream second argument");
            return hr;
        }
        return S_OK;
    }

    static HRESULT UnStreamBinder2Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                      CATIOBinder2Arg<T, A0, A1, R, LifeCyclePolicy, Arg0LifeCyclePolicy, Arg1LifeCyclePolicy, CleanArgs>*& opBinder)
    {
        HRESULT hr = S_OK;
        T* pComp = NULL;
        CATUnicodeString methodID;

        hr = CATSGSerializationSurrogateTemplateBinder<T>::UnStreamMethodAndCaller(iSerializationCtx, iStream, pComp, methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::UnStreamBinder2Arg, failed to unstream method ID and caller");
            return hr;
        }
        R (T::*pMethod)(A0, A1) = NULL;
        hr = CATTraitInfo<T>::GetBindableMethod(methodID,pMethod);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::UnStreamBinder2Arg, failed to get method");
            return hr;
        }
        A0 arg0;
        hr = CATSGSerializationSurrogateTemplate<A0>::UnStream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::UnStreamBinder2Arg, failed to unstream first argument");
            return hr;
        }
        A1 arg1;
        hr = CATSGSerializationSurrogateTemplate<A1>::UnStream(iSerializationCtx, iStream, arg1);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder2Arg::UnStreamBinder2Arg, failed to unstream second argument");
            return hr;
        }
        opBinder = new CATIOBinder2Arg<T, A0, A1, R, LifeCyclePolicy, Arg0LifeCyclePolicy, Arg1LifeCyclePolicy, CleanArgs>(pMethod, pComp, arg0, arg1);
        return S_OK;
    }
};

template<typename T, typename A0, typename A1, typename A2, typename R, template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg0LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg1LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         template <class> class Arg2LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy,
         CATECleanArguments CleanArgs = CATENoCleanAfterCall>
class CATSGSerializationSurrogateTemplateBinder3Arg : public CATSGSerializationSurrogateTemplateBinder<T>
{
public:

    static HRESULT StreamBinder3Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                    CATIOBinder3Arg<T, A0, A1, A2, R, LifeCyclePolicy, Arg0LifeCyclePolicy, Arg1LifeCyclePolicy, Arg2LifeCyclePolicy, CleanArgs>* ipBinder)
    {
        HRESULT hr = S_OK;
        CATUnicodeString methodID;

        hr = CATTraitInfo<T>::GetBindableMethodID(ipBinder->GetMethod(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::StreamBinder3Arg, failed to get method ID");
            return hr;
        }
        hr = CATSGSerializationSurrogateTemplateBinder<T>::StreamMethodAndCaller(iSerializationCtx, iStream, ipBinder->GetThis(), methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::StreamBinder3Arg, failed to stream method ID and caller");
            return hr;
        }
        A0 arg0 = ipBinder->GetArg0();
        hr = CATSGSerializationSurrogateTemplate<A0>::Stream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::StreamBinder3Arg, failed to stream first argument");
            return hr;
        }
        A1 arg1 = ipBinder->GetArg1();
        hr = CATSGSerializationSurrogateTemplate<A1>::Stream(iSerializationCtx, iStream, arg1);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::StreamBinder3Arg, failed to stream second argument");
            return hr;
        }
        A2 arg2 = ipBinder->GetArg2();
        hr = CATSGSerializationSurrogateTemplate<A2>::Stream(iSerializationCtx, iStream, arg2);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::StreamBinder3Arg, failed to stream third argument");
            return hr;
        }
        return S_OK;
    }

    static HRESULT UnStreamBinder3Arg(CATCompSerializationContextPtr& iSerializationCtx, CATCompStreamPtr& iStream,
                                      CATIOBinder3Arg<T, A0, A1, A2, R, LifeCyclePolicy, Arg0LifeCyclePolicy, Arg1LifeCyclePolicy, Arg2LifeCyclePolicy, CleanArgs>*& opBinder)
    {
        HRESULT hr = S_OK;
        T* pComp = NULL;
        CATUnicodeString methodID;

        hr = CATSGSerializationSurrogateTemplateBinder<T>::UnStreamMethodAndCaller(iSerializationCtx, iStream, pComp, methodID);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::UnStreamBinder3Arg, failed to unstream method ID and caller");
            return hr;
        }
        R (T::*pMethod)(A0, A1, A2) = NULL;
        hr = CATTraitInfo<T>::GetBindableMethod(methodID,pMethod);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::UnStreamBinder3Arg, failed to get method");
            return hr;
        }
        A0 arg0;
        hr = CATSGSerializationSurrogateTemplate<A0>::UnStream(iSerializationCtx, iStream, arg0);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::UnStreamBinder3Arg, failed to unstream first argument");
            return hr;
        }
        A1 arg1;
        hr = CATSGSerializationSurrogateTemplate<A1>::UnStream(iSerializationCtx, iStream, arg1);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::UnStreamBinder3Arg, failed to unstream second argument");
            return hr;
        }
        A2 arg2;
        hr = CATSGSerializationSurrogateTemplate<A2>::UnStream(iSerializationCtx, iStream, arg2);
        if(FAILED(hr)) {
            CATSGContext::Get(0).LogError("Error in CATSGSerializationSurrogateTemplateBinder3Arg::UnStreamBinder3Arg, failed to unstream third argument");
            return hr;
        }
        opBinder = new CATIOBinder3Arg<T, A0, A1, A2, R, LifeCyclePolicy, Arg0LifeCyclePolicy, Arg1LifeCyclePolicy, Arg2LifeCyclePolicy, CleanArgs>(pMethod, pComp, arg0, arg1, arg2);
        return S_OK;
    }

};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGSerializationSurrogateTemplateBinder_h_
