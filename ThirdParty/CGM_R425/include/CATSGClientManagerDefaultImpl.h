#ifndef CATSGClientManagerDefaultImpl_h_
#define CATSGClientManagerDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGCompositeHost.h"
#include "CATSGClientManager.h"

class ExportedBySGComposites CATSGClientManagerDefaultImpl : public CATSGCompositeHost1<CATSGClientManager, CATSGComposite>
{
public:
    CATSGClientManagerDefaultImpl(const CATUnicodeString& iBinderDirectory, const CATUnicodeString& iBinderOutputDirectory);
    virtual ~CATSGClientManagerDefaultImpl();

    virtual HRESULT ProcessClientJobs();

private:
    CATSGClientManagerDefaultImpl(const CATSGClientManagerDefaultImpl&);
    CATSGClientManagerDefaultImpl& operator=(const CATSGClientManagerDefaultImpl&);

private:
    HRESULT RetrieveMethodID(CATCompSerializationContextPtr& iSerializationCtx, const CATUnicodeString& iBinderPath, CATUnicodeString& oMethodID);

private:
    CATUnicodeString    _binderDir;
    CATUnicodeString    _binderOutputDir;
};

#endif // end of #ifdef SG_COMPOSITES_MULTIOS
#endif // !CATSGClientManagerDefaultImpl_h_
