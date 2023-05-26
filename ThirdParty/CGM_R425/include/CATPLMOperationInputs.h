/*
 * CATPLMOperationInputs.h
 *
 *  Created on: Sep 26, 2013
 *      Author: pjq
 */

#ifndef CATPLMOPERATIONINPUTLIST_H_
#define CATPLMOPERATIONINPUTLIST_H_

#include "CATPLMModelBuilder.h"
#include "CATPLMOperationInput.h"
#include "CATOmxArray.h"
#include "CATOmxOSet.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxIter.h"

 /**
  * List of CATPLMOperationInput. Duplicates are not appended.
  */
class ExportedByCATPLMModelBuilder CATPLMOperationInputs
{
public:
  CATPLMOperationInputs() = default;
  CATPLMOperationInputs(const CATPLMID& iInput);
  CATPLMOperationInputs(const CATPLMOperationInput& iInput);
  CATPLMOperationInputs(const CATPLMIDs& iInputs);
  CATPLMOperationInputs(const CATPLMOperationInputs& iOther) = default;

  CATPLMOperationInputs& operator = (const CATPLMOperationInputs& iOther) = default;

  inline int Size() const { return m_inputs.Size(); }

  void Insert(const CATPLMID& iInput);
  void Insert(const CATPLMOperationInput& iInput);
  void Insert(const CATPLMIDs& iInputs);
  void Insert(const CATPLMOperationInputs& iInputs);

  inline CATOmxSTLIter<const CATPLMOperationInput> begin() const { return m_inputs.begin(); }
  inline CATOmxSTLIter<const CATPLMOperationInput> end()   const { return m_inputs.end(); }

  inline CATBoolean Locate(const CATPLMOperationInput& iInput) const { return (m_inputs.Locate(iInput)) ? TRUE : FALSE; }

  CATPLMIDs AsPLMIDs() const;

  inline void RemoveAll() { m_inputs.RemoveAll(); }

  inline void RemoveValue(const CATPLMOperationInput& iInput) { m_inputs.Remove(iInput); }

  inline CATOmxOSet<CATPLMOperationInput>::IteratorType GetIterator() const { return m_inputs.Iterator(); }

#ifdef CATIAR424
  OMX_DEPRECATED("This method is deprecated.")
    HRESULT CompleteDisciplines() { return S_OK; }
#else
  HRESULT CompleteDisciplines() { return S_OK; }
#endif

private:
  CATOmxOSet<CATPLMOperationInput> m_inputs;
};

/* Collection manager for CATOmxCollection apis. */
template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMOperationInputs>::manager();

#endif /* CATPLMOPERATIONINPUTLIST_H_ */
