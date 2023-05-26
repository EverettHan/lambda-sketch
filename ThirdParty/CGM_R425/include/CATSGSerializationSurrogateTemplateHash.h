#ifndef CATSGSerializationSurrogateTemplateHash_h_
#define CATSGSerializationSurrogateTemplateHash_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompSerializationContext.h"
#include "CATCompStream.h"
#include <map>

template<typename KeyType, typename ValueType>
class ExportedBySGComposites CATSGSerializationSurrogateTemplateHash
{
public:
    static HRESULT Stream(CATCompSerializationContextPtr& iSerializationCtx,
                          CATCompStreamPtr&               iStream,
                          std::map<KeyType, ValueType>&   iHash);
    static HRESULT UnStream(CATCompSerializationContextPtr& iSerializationCtx,
                            CATCompStreamPtr&               iStream,
                            std::map<KeyType, ValueType>&   oHash);
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGSerializationSurrogateTemplateHash_h_
