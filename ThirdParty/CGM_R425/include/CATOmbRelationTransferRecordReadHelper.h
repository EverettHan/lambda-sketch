#ifndef CATOmbRelationTransferRecordReadHelper_H
#define CATOmbRelationTransferRecordReadHelper_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U3
 */
#include "CATOmbRelationTransfer.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATOmbRelationTransferAssistant.h"

class CATPLMSemanticRelationData;
class CATPLMID;

/**
 * Class that defines a listener to raise PLMIntegrity violation.
 */
class  ExportedByCATOmbRelationTransfer CATOmbRelationTransferRecordReadHelper
{
public:

  /**
  * constructor
  */
  CATOmbRelationTransferRecordReadHelper(CATOmbRelationTransferAssistant & iAssistant);
  virtual ~CATOmbRelationTransferRecordReadHelper();

  enum State {Valid, Invalid};

  /**
  * Returns Helper validity
  */
  State GetState(){return _State;}

  /**
  * Gets nomber of semantical relations
  * @param oCount
  *        The number of SR
  * @return
  *     S_OK           : if succeeded
  *     E_ACCESSDENIED : if relational view cannot be exported cause to violations
  *     E_FAIL         : if failure
  */
  HRESULT SemanticRelationCount(unsigned int & oCount);

  /**
  * Access to semantic relation persistency description from index
  * @param iIndex
  *        Index starting to 1
  * @param oTargetId
  *        Simple or complex component identifier
  * @param oSemanticData
  *        Extra persistency information
  * @return 
  *     S_OK           : if succeeded
  *     E_ACCESSDENIED : if relational view cannot be exported cause to violations
  *     E_FAIL         : if failure
  */
  HRESULT GetSemanticRelation(int iIndex, CATPLMID & oTargetId,  CATPLMSemanticRelationData & oSemanticData);

private:

  /* forbidden operations */
  CATOmbRelationTransferRecordReadHelper (CATOmbRelationTransferRecordReadHelper &);
  CATOmbRelationTransferRecordReadHelper& operator=(CATOmbRelationTransferRecordReadHelper&);

  CATOmbRelationTransferAssistant _Assistant;
  State                           _State;
} ;

#endif

