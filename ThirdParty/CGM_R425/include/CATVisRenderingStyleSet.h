#ifndef CATVisRenderingStyleSet_H
#define CATVisRenderingStyleSet_H

// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATVizBaseIUnknown.h"
#include "SGInfra.h"
#include "list.h"

class CATVisPLMRenderingStyleData;
class ExportedBySGInfra CATVisRenderingStyleSet : public CATVizBaseIUnknown
{
public :
    static CATVisRenderingStyleSet* Create();
    CATVisRenderingStyleSet* Clone();

    void SetRenderingStyle(unsigned int iID, const CATVisPLMRenderingStyleData&  iData);
    void ResetRenderingStyles(); 
    const CATVisPLMRenderingStyleData* GetRenderingStyle(unsigned int iID) const;
    
    void SetVersionNumber(unsigned int iVersionNumber);
    bool HasSameVersionNumber(const CATVisRenderingStyleSet& iOtherStyleSet) const;

protected :
    CATVisRenderingStyleSet();
    ~CATVisRenderingStyleSet();

private :
    list<CATVisPLMRenderingStyleData> _data;
    unsigned int _versionNumber = 0u;
};


#endif
