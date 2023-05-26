#ifndef CATPLMSRIds_H
#define CATPLMSRIds_H

#include "CATPLMPathId.h"

/**
 * a simple vehicle for the 2 identifiers of a SemanticRelation:
 *   - IDRel:  unsigned int, session strong identifier, always set
 *   - pathid: string (probably an uuid): M1 strong identifier, set only by M1 when creating an SR in DB
 */
class CATPLMSRIds
{
public:
  inline CATPLMSRIds() : IDRel(0) {}
  inline CATPLMSRIds(unsigned int iIDRel, const CATPLMPathId& ipathid) : IDRel(iIDRel), pathid(ipathid) {}
  static inline CATPLMSRIds FromIDRel(unsigned int iIDRel)
  {
    return CATPLMSRIds(iIDRel, CATPLMPathId());
  }

  unsigned int IDRel;
  CATPLMPathId pathid;
};


#endif
