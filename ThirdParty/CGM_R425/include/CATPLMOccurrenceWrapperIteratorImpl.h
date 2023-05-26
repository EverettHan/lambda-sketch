#ifndef CATPLMOccurrenceWrapperIteratorImpl_H
#define CATPLMOccurrenceWrapperIteratorImpl_H

#include "CATBaseUnknown.h"
#include "CATPLMCoreType.h"

class CATPLMOccurrenceWrapper;
class CATListValCATPLMOccurrenceWrapper;

class CATPLMOccurrenceWrapperIteratorImpl : public CATBaseUnknown
{
private:
  virtual HRESULT Next(CATPLMOccurrenceWrapper & oNextWrapper)=0;
  virtual HRESULT ResetCursor()=0;
  virtual int FillList(CATListValCATPLMOccurrenceWrapper & oList)=0;

  friend class CATPLMOccurrenceWrapperIterator;
  friend class PLMOccurrenceWrapperIterator;
  virtual ~CATPLMOccurrenceWrapperIteratorImpl(){;}
};
#endif
