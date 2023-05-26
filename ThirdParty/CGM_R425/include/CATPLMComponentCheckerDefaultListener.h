#ifndef CATPLMComponentCheckerDefaultListener_H
#define CATPLMComponentCheckerDefaultListener_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U3
 */
#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"
#include "CATPLMComponentCheckerListenerAdapter.h"

class CATPLMRelationalCheckSumComparator;
class CATOmbRelationalCheckSum;

/**
* PLM Integration Checker
* Checking Database consistency after remote operation
*/
class ExportedByCATPLMIdentification CATPLMComponentCheckerDefaultListener : public CATPLMComponentCheckerListenerAdapter
{
public:
  CATPLMComponentCheckerDefaultListener();
  virtual ~CATPLMComponentCheckerDefaultListener();

  HRESULT OnRelationalValidate(const CATPLMID & iPLMID, const CATUnicodeString & iComments);

  HRESULT OnRelationalCorruption(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator);

  HRESULT OnMetadatasCorruption(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator);

  HRESULT OnRelationalCorruption(const CATPLMID & iPLMID, const CATOmbRelationalCheckSum & iCheckSum);

  HRESULT OnMetadatasCorruption(const CATPLMID & iPLMID, const CATOmbRelationalCheckSum & iCheckSum);

  HRESULT OnRelationalCheckFailure(const CATPLMID & iPLMID, const CATUnicodeString & iComments);

  HRESULT OnStreamIterationCorruption(const CATPLMID & iPLMID, const CATUnicodeString & iComments);
  
  HRESULT OnStreamSizeWarning(const CATPLMID & iPLMID, const CATUnicodeString & iComments);
  
  unsigned int GetRelationalValidateCount(){return _NbRelationalValidate;}

  unsigned int GetRelationalCorruptionCount(){return _NbRelationalCorruption;}

  unsigned int GetStreamIterationCorruptionCount(){return _NbStreamIterationCorruption;}

  unsigned int GetStreamSizeWarningCount(){return _NbStreamSizeWarning;}

  unsigned int GetCheckFailureCount(){return _NbCheckFailure;}

  unsigned int GetMetadatasCorruption(){return _NbMetadatasCorruption;}

  /**
  * @return
  *   S_OK   : all is OK
  *   E_FAIL : data corruption
  */
  HRESULT Commit();

private:

  /* forbidden operations */
  CATPLMComponentCheckerDefaultListener (CATPLMComponentCheckerDefaultListener &);
  CATPLMComponentCheckerDefaultListener& operator=(CATPLMComponentCheckerDefaultListener&);

  unsigned int _NbRelationalValidate;
  unsigned int _NbRelationalCorruption;
  unsigned int _NbStreamIterationCorruption;
  unsigned int _NbStreamSizeWarning;
  unsigned int _NbCheckFailure;
  unsigned int _NbMetadatasCorruption;
};

#endif
