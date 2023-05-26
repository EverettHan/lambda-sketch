#ifndef CATPLMIDSet_H
#define CATPLMIDSet_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxOrderedOSet.h"

class CATPLMID;
class CATOmXStream;
class CATPLMIDVisitor;
class CATPLMIDSet;

/**
* Legacy, use instead CATOmxOrderedOSet<CATPLMID>
*/
class ExportedByCATPLMIdentificationAccess CATPLMIDSet
{
protected:
  CATOmxOrderedOSet<CATPLMID> m_set;
public:
  /**@nodoc, Legacy, use instead CATOmxOrderedOSet<CATPLMID>*/
  HRESULT Insert(const CATPLMID & iPLMID);
  HRESULT InsertList(const CATListValCATPLMID & iListPLMID);
  HRESULT InsertSet(const CATPLMIDSet & iSetPLMID);
  HRESULT Locate(const CATPLMID & iPLMID, CATPLMID * oInsertedPLMID = NULL) const;
  HRESULT Remove(const CATPLMID & iPLMID) {return m_set.Remove(iPLMID) ? S_OK : S_FALSE;}
  HRESULT Visit(CATPLMIDVisitor & iVisitor) const;
  HRESULT Compare (const CATPLMIDSet& iComparedSet,CATBoolean& oIsEqual,CATPLMIDVisitor* iComparedSetExtraPLMID = 0,CATPLMIDVisitor* iComparedSetMissingPLMID = 0) const;
  HRESULT Flush() {m_set.RemoveAll();return S_FALSE;}
  unsigned int Size() const {return m_set.Size();}
  CATBoolean operator!() const {return !Size();}
  inline CATOmxIter<CATPLMID> Iterator() const {return m_set.Iterator();}
};
#endif
