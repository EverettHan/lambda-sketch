#include "CATOmxOHMap.h"
// COPYRIGHT Dassault Systemes 2019
//===================================================================
//
// CATPLMVersionInput.h
// Provide implementation to interface
//    CATIPLMVersionInput
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2019  
//===================================================================
#ifndef CATPLMVersionInput_H
#define CATPLMVersionInput_H

class CATIPLMVersionGraph;
class CATOmxKeyValueBlock;
class CATOmxKeyValueBlock;
class CATIPLMAttributeSet;
class CATPLMID;
class CATUnicodeString;

#include "CATIPLMVersionInput.h"
#include "CATOmxList.h"
#include "CATOmxPair.h"
#include "CATPLMID.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxCollecManager.h"
#include "CATPLMTypeH.h"
#include "CATPLMVersionOptions.h"

class CATPLMVersionInput : public CATIPLMVersionInput
{
public:
  CATPLMVersionInput(const CATPLMID & iId, const CATUnicodeString & iIntent)
    :m_pid(iId)
    , m_copy_id(iId)
    , m_intent(iIntent)
    , m_keep_mask(CATPLMVersionOptions::DEFAULT)
    , m_reset_mask(CATPLMVersionOptions::DEFAULT)
  {
  }
  ~CATPLMVersionInput() {}

  virtual HRESULT AddAttributes(const CATOmxKeyValueBlock & iAttributes);

  virtual HRESULT AddExtensionAttributes(const CATPLMTypeH & iExtensionType, const CATOmxKeyValueBlock & iExtensionAttributes);

  virtual HRESULT AddAttributes(const CATIPLMAttributeSet & iAttributes);

  virtual void NewVersionFromContent(const CATPLMID &iContentFrom);

  virtual void NewIntentFrom(const CATUnicodeString & iIntent, const CATPLMID &iFrom);

  virtual HRESULT KeepOrReset(const CATPLMVersionOptions::KeepOrReset &iAttrsToKeepMask, const CATPLMVersionOptions::KeepOrReset &iAttrsToResetMask);

  const CATUnicodeString & GetIntent() const
  {
    return m_intent;
  }
  const CATPLMID & GetPLMID() const
  {
    return m_pid;
  }

  const CATPLMID & GetCopyId() const
  {
    return m_copy_id;
  }

  const CATOmxArray<CATOmxPair<CATUnicodeString, CATPLMID> >& GetOtherIntents() const
  {
    return m_otherintents;
  }

  const CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock> &GetAttributes() const
  {
    return m_attributes;
  }

  const CATPLMVersionOptions::KeepOrReset& GetKeepMask() const
  {
    return m_keep_mask;
  }

  const CATPLMVersionOptions::KeepOrReset& GetResetMask() const
  {
    return m_reset_mask;
  }

private:
  CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock> m_attributes;
  CATOmxArray<CATOmxPair<CATUnicodeString, CATPLMID> > m_otherintents;
  CATPLMID m_pid;
  CATPLMID m_copy_id;
  CATUnicodeString m_intent;

  CATPLMVersionOptions::KeepOrReset m_keep_mask;
  CATPLMVersionOptions::KeepOrReset m_reset_mask;
};

#endif
