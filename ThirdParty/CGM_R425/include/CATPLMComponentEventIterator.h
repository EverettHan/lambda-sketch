#ifndef _CATPLMComponentEventIterator_H
#define _CATPLMComponentEventIterator_H
/**
 * @level Protected
 * @usage U1       
 */
#include "CATPLMIdentificationAccess.h"

class CATPLMComponentEvent;

class ExportedByCATPLMIdentificationAccess CATPLMComponentEventIterator
{
  friend class CATOxRedrawListener;
public:
  /**
  * Allows to get next Event
  */
  virtual const CATPLMComponentEvent * operator++ (int) = 0;

protected:
  CATPLMComponentEventIterator(){}
  virtual ~CATPLMComponentEventIterator(){}

private:
  // forbidden operations
  CATPLMComponentEventIterator (CATPLMComponentEventIterator &);
  CATPLMComponentEventIterator& operator=(CATPLMComponentEventIterator&);
};
#endif

