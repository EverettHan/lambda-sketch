#ifndef CATUFOLogAccessForClientCore_H
#define CATUFOLogAccessForClientCore_H

#include "IUnknown.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATBoolean.h"
#include "CATProxySpace.h"
/**
 * @level Protected
 * @usage U1
 */

class CATListValCATPLMID;
class CATPLMID;
class CATUnicodeString;
class CATUFOLogComplexEntry;

/**
* Access for client core to write in UFO log.
*/
class ExportedByCATPLMIdentification CATUFOLogAccessForClientCore
{
public:

  /**
  * Begin log entry transaction
  * @param iSpace
  *  The authoring space
  * @param iActionName
  *  The name of the action
  * @return
  *  S_OK if insertion happened
  *  E_FAIL otherwise
  */
  static HRESULT BeginTransaction(CATProxySpace & iSpace, CATUnicodeString & iActionName);

  /**
  * End log entry transaction
  * @param iSpace
  *  The authoring space
  * @param iActionName
  *  The name of the action
  * @return
  *  S_OK if insertion happened
  *  E_FAIL otherwise
  */
  static HRESULT EndTransaction(CATProxySpace & iSpace, CATUnicodeString & iActionName);

  /**
  * Add a move action during a transaction
  * @param iContext
  *  The context of the move
  * @param iOriginalOccurrences
  *  The original occurrences
  * @param iMovedOccurrences
  *   The moved occurrences
  * @return
  *  S_OK if insertion happened
  *  E_FAIL otherwise
  */
  static HRESULT AddMoveSimpleAction(CATPLMID & iContext, CATListValCATPLMID & iOriginalOccurrences,
    CATListValCATPLMID & iMovedOccurrences);

  /**
  * Add an insert action during a transaction
  * @param iContext
  *  The context of the move
  * @param iInsertedOccurrences
  *  The inserted occurrences
  * @return
  *  S_OK if insertion happened
  *  E_FAIL otherwise
  */
  static HRESULT AddInsertSimpleAction(CATPLMID & iContext, CATListValCATPLMID & iInsertedOccurrences);

  /**
  * Add a substitution in usage context
  */
  static HRESULT AddSubstitutionInUsageContext(CATPLMID & iUsageContext,
    CATPLMID & iOriginalProduct,
    CATPLMID & iSubstitutedProduct);

  /**
  * Add a modify delete action during a transaction
  * @param iContext
  *  The context of the delete
  * @param iDeletedOccurrences
  *  The deleted occurrences
  *
  * @return
  *  S_OK if delete happened
  *  E_FAIL otherwise
  */
  static HRESULT AddModifyDeleteSimpleAction(CATPLMID & iContext, CATListValCATPLMID & iDeletedOccurrences);

  /**
* Add a replace action during a transaction.
* A replace action is constituted of master occurrences, and additional (optional) ones.
* @param iContext
*  The context of the move
* @param iOriginalOccurrences
*  The original occurrences
* @param iNewOccurrences
*   The replacing occurrences
* @param iOriginalAdditionalOccurrences
*   Aditional replaced occurrences (optional)
* @param iNewAdditionalOccurrences
*   Additional replacing occurrences (optional)
* @return
*  S_OK if replace happened
*  E_FAIL otherwise
*/
  static HRESULT AddReplaceSimpleAction(CATPLMID & iContext, CATListValCATPLMID & iOriginalOccurrences,
    CATListValCATPLMID & iNewOccurrences,
    CATListValCATPLMID & iOriginalAdditionalOccurences,
    CATListValCATPLMID & iNewAdditionalOccurrences);

  /**
* Add a clone action during a transaction
* @param iContext
*  The context of the move
* @param iOriginalOccurrences
*  The original occurrences
* @param iMovedOccurrences
*   The moved occurrences
* @return
*  S_OK if insertion happened
*  E_FAIL otherwise
*/
  static HRESULT AddCloneSimpleAction(CATPLMID & iContext, CATListValCATPLMID & iOriginalOccurrences,
    CATListValCATPLMID & iMovedOccurrences);

  /**
  * Observes if a component is an alternative for another component
  */
  static HRESULT  IsAlternative(CATPLMID & iComponent, CATPLMID & iAlternative, CATBoolean iMinorSensitivity = TRUE);

  /**
  * Set/unset as under replace operator
  * Block the log so that no replace operation can be logged
  */
  static void SetAsUnderReplaceOperator();
  static void UnsetAsUnderReplaceOperator();
};

#endif
