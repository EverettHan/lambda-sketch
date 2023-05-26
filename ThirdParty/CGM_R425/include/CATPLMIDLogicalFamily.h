#ifndef _CATPLMIDLogicalFamily_H
#define _CATPLMIDLogicalFamily_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U1
 */
#include "CATLib.h"
#include "IUnknown.h"
#include "CATOmxArray.h"
#include "CATPLMID.h"
#include "CATPLMIDLogicalFamilyVisitor.h"
#include "CATPLMID_Simple.h"

class CATPLMIDLogicalFamily
{
public:
  CATPLMIDLogicalFamily() = default;
  CATPLMIDLogicalFamily(const CATOmxArray<CATPLMID>& members) :m_members(members) {}
  /**
  * Returns the number of identifiers belonging to family
  */
  unsigned int Size() const { return m_members.Size(); }

  /**
  * Visit family content
  *
  * @param iVisitor
  *   Visitor allowing to visit family content
  */
  HRESULT Visit(CATPLMIDLogicalFamilyVisitor & iVisitor) const
  {
    for (CATPLMID id : m_members)
      iVisitor.Visit(id);
    return S_OK;
  }
public:
  CATOmxArray<CATPLMID> m_members;
};

#endif
