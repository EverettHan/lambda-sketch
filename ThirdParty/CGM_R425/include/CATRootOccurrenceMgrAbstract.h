#ifndef CATRootOccurrenceMgrAbstract_H
#define CATRootOccurrenceMgrAbstract_H

#include "CATPLMModelerOccInterfaces.h"
#include "CATRootOccurrenceMgr.h"
#include "CATOmxSR.h"
#include "CATOmxList.h"
#include "CATBaseUnknown.h"

class CATRootOccurrenceMgrAbstract
{
public:
  virtual HRESULT GetRootOccList(const CATBaseUnknown * iRoot, CATRootOccModeMask iMask, CATOmxList<CATBaseUnknown> & oRootOccList) = 0;
  virtual HRESULT CreateAndUnfold(const CATBaseUnknown * iRoot, CATOmxSR<CATBaseUnknown> & oRootOcc, const CATBaseUnknown * iFilter = NULL) = 0;
  virtual void ReleaseOccurrenceTree(CATBaseUnknown * iRootOcc) = 0;
  virtual void LockOccurrenceTree(CATBaseUnknown * iRootOcc) = 0;
  virtual HRESULT GetRootOccurrenceMode(CATBaseUnknown * iRootOcc, CATRootOccModeMask & oMode) = 0;
  virtual CATOmxSR<CATBaseUnknown> RetrieveRootOccurrence(const CATBaseUnknown* iReference, const CATBaseUnknown* iFilter, CATRootOccModeMask iMask) = 0;
};


#endif
