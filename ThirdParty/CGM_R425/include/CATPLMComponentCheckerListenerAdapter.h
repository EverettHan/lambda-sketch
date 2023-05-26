#ifndef CATPLMComponentCheckerListenerAdapter_H
#define CATPLMComponentCheckerListenerAdapter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U3
 */
#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"
#include "CATPLMComponentCheckerListener.h"

class CATPLMRelationalCheckSumComparator;

/**
* Adapter to be used for implementing CATPLMComponentCheckerListener
*/
class ExportedByCATPLMIdentification CATPLMComponentCheckerListenerAdapter : public CATPLMComponentCheckerListener
{
public:
  CATPLMComponentCheckerListenerAdapter();
  virtual ~CATPLMComponentCheckerListenerAdapter();

  /**
  * Default behaviour : S_OK
  */   
  virtual HRESULT NumberOfPossibleRelationalChecks(unsigned int iPossibleRelationalChecks);

  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT IsCandidateForRelationalCheck(const CATPLMID & iPLMID);

  /**
  * Default behaviour : S_OK
  */  
  virtual HRESULT NumberOfEffectiveRelationalChecks(unsigned int iEffectiveRelationalChecks);

  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT OnRelationalCheckBlockStarting(unsigned int iBlockNumber, unsigned int iBlockSize, unsigned int iMaxBlockNumber);

  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT OnRelationalCorruption(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator);

  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT OnMetadatasCorruption(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator);

  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT OnRelationalValidate(const CATPLMID & iPLMID, const CATUnicodeString & iComments);

  /**
  * Default behaviour : E_FAIL
  */ 
  virtual HRESULT OnRelationalCheckFailure(const CATPLMID & iPLMID, const CATUnicodeString & iComments);

  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT OnStreamIterationCorruption(const CATPLMID & iPLMID, const CATUnicodeString & iComments);
 
  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT OnStreamSizeWarning(const CATPLMID & iPLMID, const CATUnicodeString & iComments);

  /**
  * Default behaviour : S_OK
  */ 
  virtual HRESULT OnRelationalCheckBlockEnding(unsigned int iBlockIdentifier);
};

#endif
