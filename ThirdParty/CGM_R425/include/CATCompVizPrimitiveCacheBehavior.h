#ifndef CATCompVizPrimitiveCacheBehavior_h_
#define CATCompVizPrimitiveCacheBehavior_h_

enum VizPrimitiveCacheBehavior
{
    VizPrimitiveCache_DoNotUse = 0x0,
    VizPrimitiveCache_Use = 0x1,
    VizPrimitiveCache_Clean = 0x2,
    VizPrimitiveCache_Use_Clean = 0x3
};

#endif // !CATCompVizPrimitiveCacheBehavior_h_
