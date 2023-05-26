#ifndef __CATOmxAnyMapConvert_h__
#define __CATOmxAnyMapConvert_h__

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"

class CATOmxKeyValueBlock;
class CATOmxAny;
class CATOmxKeyString;

/** set kv_blk (and wrap) into target. */
ExportedByCATOmxKernel HRESULT operator <<(CATOmxAny &oAny,const CATOmxKeyValueBlock &iMap);
/** get a copy kv_blk from target. */
ExportedByCATOmxKernel HRESULT operator >>(const CATOmxAny &iAny, CATOmxKeyValueBlock &oMap);

#endif

