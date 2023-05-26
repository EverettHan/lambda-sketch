//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMDicPLMCORETYPE_h
#define _VPMDicPLMCORETYPE_h

/**
 * PLMCoreTypes.
 */

enum VPMDicPLMCORETYPE
{
     VPMDicPLMCoreInstance     = 1
    ,VPMDicPLMCoreRepInstance  = 2
    ,VPMDicPLMCoreReference    = 3
    ,VPMDicPLMCoreRepReference = 4
    ,VPMDicPLMPort             = 5
    ,VPMDicPLMConnection       = 6
};

extern const char ExportedByENODicBase * _PLMCoreInstanceTAG;
extern const char ExportedByENODicBase * _PLMCoreRepInstanceTAG;
extern const char ExportedByENODicBase * _PLMCoreReferenceTAG;
extern const char ExportedByENODicBase * _PLMCoreRepReferenceTAG;
extern const char ExportedByENODicBase * _PLMPortTAG;
extern const char ExportedByENODicBase * _PLMConnectionTAG;

#endif

