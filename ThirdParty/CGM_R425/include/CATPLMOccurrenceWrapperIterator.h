#ifndef CATPLMOccurrenceWrapperIterator_H
#define CATPLMOccurrenceWrapperIterator_H

#include "CATPLMIdentificationAccessOccWrapper.h"

#include "CATOmxSR.h"

class CATPLMOccurrenceWrapper;
class CATListValCATPLMOccurrenceWrapper;
class CATPLMOccurrenceWrapperIteratorImpl;

class ExportedByCATPLMIdentificationAccessOccWrapper CATPLMOccurrenceWrapperIterator
{
public:
  HRESULT Next(CATPLMOccurrenceWrapper & oNextWrapper);
  HRESULT ResetCursor();
  int FillList(CATListValCATPLMOccurrenceWrapper & oList);

  CATPLMOccurrenceWrapperIterator();
  virtual ~CATPLMOccurrenceWrapperIterator();

private:
  CATPLMOccurrenceWrapperIterator(CATPLMOccurrenceWrapperIterator & iWrapper); // Not implemented
  CATPLMOccurrenceWrapperIterator& operator=(CATPLMOccurrenceWrapperIterator& iWrapper); // Not implemented

  friend class PLMOccurrenceWrapperWithContextFromNavOcc;
  friend class PLMOccurrenceWrapperWithContextFromPofi;
  friend class PLMOccurrenceWrapperWithContextFromNavRepInst;
  friend class PLMOccurrenceWrapperWithoutContextFromRef;
  friend class PLMOccurrenceWrapperWithoutContextFromPofi;
  friend class PLMOccurrenceWrapper;
  HRESULT SetImpl(CATOmxSR<CATPLMOccurrenceWrapperIteratorImpl> iImpl);
  CATOmxSR<CATPLMOccurrenceWrapperIteratorImpl> _impl;
};
#endif
