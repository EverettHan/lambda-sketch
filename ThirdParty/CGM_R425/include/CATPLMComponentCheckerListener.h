#ifndef CATPLMComponentCheckerListener_H
#define CATPLMComponentCheckerListener_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U3
 */
#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"

class CATPLMID;
class CATPLMRelationalCheckSumComparator;
class CATOmbRelationalCheckSum;
class CATUnicodeString;

/**
* PLM Integration Checker
* Checking Database consistency after remote operation
* The following adapter must be used CATPLMComponentCheckerListenerAdapter
*/
class ExportedByCATPLMIdentification CATPLMComponentCheckerListener
{
public:
  CATPLMComponentCheckerListener(){}
  virtual ~CATPLMComponentCheckerListener(){}
  
  /**
  * Number of possible relational checks
  */
  virtual HRESULT NumberOfPossibleRelationalChecks(unsigned int iPossibleRelationalChecks) = 0;

  /**
  * Method invoked on all candidates before starting relational checks
  * @return
  *    S_OK    : Check has to be done
  *    S_FALSE : Check is not necessary for this component
  *    E_FAIL  : Check is globally aborted 
  */
  virtual HRESULT IsCandidateForRelationalCheck(const CATPLMID & iPLMID) = 0;

  /**
  * Number of effective relational checks according to IsCandidateForRelationalCheck
  */
  virtual HRESULT NumberOfEffectiveRelationalChecks(unsigned int iEffectiveRelationalChecks) = 0;
  
  /**
  * Method invoked before a set of checks
  * @param iBlockNumber
  *        Identifier of the current block
  * @param iBlockSize
  *        Size of the block
  * @param iMaxBlockNumber
  *        Max block number
  * @return 
  *        S_OK
  *        E_FAIL
  */
  virtual HRESULT OnRelationalCheckBlockStarting(unsigned int iBlockIdentifier, unsigned int iBlockSize, unsigned int iMaxBlockNumber) = 0;
  
  /**
  * Event when corruption (Check is based on a comparison with safe copy)
  */
  virtual HRESULT OnRelationalCorruption(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator) = 0;

  /**
  * Event when corruption of the metadatas (Check is based on a comparison with safe copy)
  */
  virtual HRESULT OnMetadatasCorruption(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator) = 0;

  /**
  * Event when corruption (Check is based on basic integrity checks)
  */
  virtual HRESULT OnRelationalCorruption(const CATPLMID & iPLMID, const CATOmbRelationalCheckSum & iCheckSum) = 0;

  /**
  * Event when corruption of the metadatas (Check is based on a comparison with safe copy)
  */
  virtual HRESULT OnMetadatasCorruption(const CATPLMID & iPLMID, const CATOmbRelationalCheckSum & iCheckSum) = 0;

  /**
  * Event when all is OK
  */
  virtual HRESULT OnRelationalValidate(const CATPLMID & iPLMID, const CATUnicodeString & iComments) = 0;

  /**
  * Event when unknown external failure
  */
  virtual HRESULT OnRelationalCheckFailure(const CATPLMID & iPLMID, const CATUnicodeString & iComments) = 0;

  /**
  * Event when stream iteration problem
  */
  virtual HRESULT OnStreamIterationCorruption(const CATPLMID & iPLMID, const CATUnicodeString & iComments) = 0;

  /**
  * Event when stream size is suspect
  */
  virtual HRESULT OnStreamSizeWarning (const CATPLMID & iPLMID, const CATUnicodeString & iComments) = 0;

  /**
  * Method invoked after a set of checks
  * @param iBlockIdentifier
  *        Identifier of the current set
  * @return 
  *        S_OK
  *        E_FAIL
  */
  virtual HRESULT OnRelationalCheckBlockEnding(unsigned int iBlockIdentifier) = 0;

private:

  /* forbidden operations */
  CATPLMComponentCheckerListener (CATPLMComponentCheckerListener &);
  CATPLMComponentCheckerListener& operator=(CATPLMComponentCheckerListener&);
};

#endif
