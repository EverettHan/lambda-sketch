#ifndef CATSGSerializationSurrogateTemplateArray_h_
#define CATSGSerializationSurrogateTemplateArray_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompSerializationContext.h"
#include "CATCompStream.h"

template<typename T>
class ExportedBySGComposites CATSGSerializationSurrogateTemplateArray
{
public:
    static HRESULT Stream(CATCompSerializationContextPtr& iSerializationCtx,
                          CATCompStreamPtr&               iStream,
                          std::vector<T>&                 iArray);
    static HRESULT UnStream(CATCompSerializationContextPtr& iSerializationCtx,
                            CATCompStreamPtr&               iStream,
                            std::vector<T>&                 oArray);
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGSerializationSurrogateTemplateArray_h_
