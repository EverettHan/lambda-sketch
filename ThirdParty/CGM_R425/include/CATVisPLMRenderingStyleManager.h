#ifndef CATVisPLMRenderingStyleManager_H
#define CATVisPLMRenderingStyleManager_H

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "SGInfra.h"

#include "list.h"
#include "CATMutex.h"

#define CATVISPLMMAXVIEWMODE    5
#define CATVISPLMCUSTOMVIEWMODE 4

class CATVisPLMRenderingStyleData;
class ExportedBySGInfra CATVisPLMRenderingStyleManager 
{
public :
    static CATVisPLMRenderingStyleManager* GetManager();
    static void Destroy();

    void SetRenderingStyles(unsigned int iPLMViewMode, 
        CATVisPLMRenderingStyleData*  iDatas,
        unsigned int iSize); 
    void ResetRenderingStyles(unsigned int iPLMViewMode); 
    void ModifyRenderingStyle(unsigned int iPLMViewMode,  
        unsigned int iDataID, 
        const CATVisPLMRenderingStyleData & iData); 
    CATVisPLMRenderingStyleData* GetRenderingStyle(unsigned int iPLMViewMode,  
                          unsigned int iDataID);
    
protected :
    CATVisPLMRenderingStyleManager();
    ~CATVisPLMRenderingStyleManager();

private :
    CATVisPLMRenderingStyleData* _renderingStyles[CATVISPLMMAXVIEWMODE];
    unsigned int _renderingStylesSize[CATVISPLMMAXVIEWMODE];

    static CATVisPLMRenderingStyleManager* _manager;
    static unsigned int                    _nRef;
    static CATMutex                        _mutex;
};


#endif
