#ifndef CATCompSerializationSurrogateHelper_h_
#define CATCompSerializationSurrogateHelper_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGComposite.h"
#include "CATCompSerializationContext.h"
#include "CATCompStream.h"
#include "CATCompSerializationSurrogate.h"

class ExportedBySGComposites CATCompSerializationSurrogateHelper
{
public:
    static HRESULT StreamCompInheritance(const CATTraitRawInfo&                 iCurrentTrait,
                                         CATCompSerializationContextWeakPtr&    iSerializationCtx,
                                         CATCompStreamPtr&                      iStream,
                                         const CATSGCompositePtr&               iComp);
    static HRESULT UnStreamCompInheritance(const CATTraitRawInfo&               iCurrentTrait,
                                           CATCompSerializationContextWeakPtr&  iSerializationCtx,
                                           CATCompStreamPtr&                    iStream,
                                           CATSGCompositePtr&                   ioComp);

    static HRESULT DumpCompositeToFile(CATSGCompositePtr& iCompPtr, const CATUnicodeString &iPath);
    static CATSGCompositePtr RecoverCompositeFromFile(const CATUnicodeString &iPath);
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompSerializationSurrogateHelper_h_
