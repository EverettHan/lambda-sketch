#ifndef CATPLMAppIdDefine_H
#define CATPLMAppIdDefine_H

/**
 * @level Private
 * @usage U3
 */
 
// List of special attribute for *.appid file
#define SpAttr_StrongRelations       0x0001
#define SpAttr_Owner                 0x0002
#define SpAttr_Reserved              0x0004
#define SpAttr_CreationDate          0x0008
#define SpAttr_ListIdentifiers       0x0010
#define SpAttr_SortingOrder          0x0020
#define SpAttr_SR                    0x0040
#define SpAttr_SD                    0x0080
#define SpAttr_ExtensionNames        0x0100
#define SpAttr_AllExtensionsAtt      0x0200
#define SpAttr_IsReserved            0x0400
#define SpAttr_Maturity              0x0800
#define SpAttr_Project               0x1000
#define SpAttr_PathType              0x2000
#define SpAttr_SlimSR                0x4000


// Specific for debug : List of creation mode for AppId operator.
#define dbg_DadDod_NoCache              0x0001
#define dbg_DadDod_ForceManagerCreation 0x0002
#define dbg_DadDod_PersistentCacheDir   0x0004
#define dbg_DadDod_BasicDump            0x0008
#define dbg_DadDod_Dump                 0x0010
#define dbg_DadDod_ForceCacheCreation   0x0020
#define dbg_DadDod_DumpAll              0x0040

#endif
