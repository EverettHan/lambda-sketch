#ifndef CATPLMPathId_H
#define CATPLMPathId_H

#include "CATUnicodeString.h"

/**
 * encapsulation of the pathid attribute value of SemanticRelation
 * it is actually a string with format num.num.num.num (probably an uuid)
 * use this class whenever you manipulate this pathid:
 *   - it will increase type safety (string is quite generic...)
 *   - could allow future optimisations (storing an uuid as a CATUnicodeString is VERY expensive)
 * this class does not implement any behavior or check, it is just a simple vehicle
 */
class CATPLMPathId
{
  CATUnicodeString m_pathid;
public:
  inline CATPLMPathId() {}
  inline CATPLMPathId(const CATUnicodeString& id) :m_pathid(id) {}
  inline bool IsNull() const { return 0 != m_pathid.IsNull(); }
  inline CATUnicodeString ToString() const { return m_pathid; }

  inline bool operator==(const CATPLMPathId& other) const { return 0 != (m_pathid == other.m_pathid); }
  inline bool operator!=(const CATPLMPathId& other) const { return !operator==(other); }
};

#endif
