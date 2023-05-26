#ifndef CATCompSerializationSurrogateTemplate_h_
#define CATCompSerializationSurrogateTemplate_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompSerializationContext.h"
#include "CATCompStream.h"
#include <map>

template<typename T>
class ExportedBySGComposites CATSGSerializationSurrogateTemplate
{
public:
    static HRESULT Stream(CATCompSerializationContextPtr& iSerializationCtx,
                          CATCompStreamPtr&               iStream,
                          T&                              iElement);
    static HRESULT UnStream(CATCompSerializationContextPtr& iSerializationCtx,
                            CATCompStreamPtr&               iStream,
                            T&                              oElement);
};

/**
 * Partial template specialization for CATSGCompositeTPtr
 */
template<class T>
class ExportedBySGComposites CATSGSerializationSurrogateTemplate<CATCompositeTPtr<T> >
{
public:
    static HRESULT Stream(CATCompSerializationContextPtr& iSerializationCtx,
                          CATCompStreamPtr&               iStream,
                          CATCompositeTPtr<T>&            iElement);
    static HRESULT UnStream(CATCompSerializationContextPtr& iSerializationCtx,
                            CATCompStreamPtr&               iStream,
                            CATCompositeTPtr<T>&            oElement);
};

/**
 * Partial template specialization for std::vector
 */
template<class T>
class ExportedBySGComposites CATSGSerializationSurrogateTemplate<std::vector<T> >
{
public:
    static HRESULT Stream(CATCompSerializationContextPtr& iSerializationCtx,
                          CATCompStreamPtr&               iStream,
                          std::vector<T>&                  iElement);
    static HRESULT UnStream(CATCompSerializationContextPtr& iSerializationCtx,
                            CATCompStreamPtr&               iStream,
                            std::vector<T>&                  oElement);
};

/**
 * Partial template specialization for std::map
 */
template<class KeyType, class ValueType>
class ExportedBySGComposites CATSGSerializationSurrogateTemplate<std::map<KeyType, ValueType> >
{
public:
    static HRESULT Stream(CATCompSerializationContextPtr& iSerializationCtx,
                          CATCompStreamPtr&               iStream,
                          std::map<KeyType, ValueType>&  iElement);
    static HRESULT UnStream(CATCompSerializationContextPtr& iSerializationCtx,
                            CATCompStreamPtr&               iStream,
                            std::map<KeyType, ValueType>&  oElement);
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompSerializationSurrogateTemplate_h_
