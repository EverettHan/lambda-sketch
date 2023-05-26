#ifndef CATComponentIdSet_H
#define CATComponentIdSet_H

/**
 * @level Private
 * @usage U1
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATComponentId.h"
#include "CATComponentIdSearch.h"
#include "CATComponentIdFilter.h"
#include "CATLISTV_CATIPLMLogState.h"
#include "CATComponentIdAssociationSet.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATComponentIdSet;
#else
extern "C" const IID IID_CATComponentIdSet;
#endif


class CATIComponentIdSimpleHashTable;
class CATOxLogStates;

class ExportedByCATPLMTos CATComponentIdSet : public CATBaseUnknown
{
  CATDeclareInterface;
public:


  /**
  * Returns the contents of Result as list of CATBaseUnknown_var.
  * Warning, it fails if the InMemory Filter of the <b>CATComponentIdFilter</b>
  *    has not been specified different from CatTosQuery_OnlyActivatedInSession.
  *
  * @param oResult
  *       Result given as List of Objects .
  *
  * @param iClearSet
  *       Clear the contents of this <b>CATComponentIdSet</b>.
  *
  * @return
  *    S_OK:      Success
  *    S_FALSE:   Success but no result (Empty list)
  *    E_FAIL:    Failed
  */
  virtual HRESULT GetList(CATLISTV(CATBaseUnknown_var)&  oResult, const CATBoolean iClearSet = TRUE) = 0;



  /**
  * Returns the contents of Result as list of CATComponentId.
  *
  * @param oResult
  *       Result given as List of Objects .
  *
  * @param iClearSet
  *       Clear the contents of this <b>CATComponentIdSet</b>.
  *
  * @return
  *    S_OK:      Success
  *    S_FALSE:   Success but no result (Empty list)
  *    E_FAIL:    No List returned
  */
  virtual HRESULT GetList(CATLISTV(CATComponentId)& oResult, const CATBoolean iClearSet = TRUE) = 0;

  /**
  * Returns the contents of Result as TodoList for Save Engine
  *
  * @param oLogStates
  *      Resulting LogStates
  *
  * @param includingUnchanged
  *      Append also in result unchanged
  *
  * @param iClearSet
  *       Clear the contents of this <b>CATComponentIdSet</b>.
  *
  * @param iTodoLevel
  *        Select the TOS level
  *
  * @return
  *    S_OK:   Success
  *    E_FAIL: Internal error
  */
  virtual HRESULT GetLogStates(CATOxLogStates     & oLogStates,
    const CATBoolean     includingUnchanged = FALSE,
    const CATBoolean     iClearSet = TRUE,
    CATTosTodoLevel      iTodoLevel = CatTosTodoLevel_Undefined) = 0;

/**
* Returns the contents of Result as TodoList for Save Engine
*
* @param oList
*      Resulting TodoList
*
* @param includingUnchanged
*      Append also in result unchanged
*
* @param iClearSet
*       Clear the contents of this <b>CATComponentIdSet</b>.
*
* @param iTodoLevel
*        Select the TOS level
*
* @return
*    S_OK:   Success
*    E_FAIL: Internal error
*/
  virtual HRESULT GetTodoList(CATLISTV(CATIPLMLogState_var) & oList,
    const CATBoolean                   includingUnchanged = FALSE,
    const CATBoolean                   iClearSet = TRUE,
    CATTosTodoLevel                    iTodoLevel = CatTosTodoLevel_Undefined) = 0;


/**
* Moves the cursor down one item from its current position and Returns the new item.
*
* @param oHandle
*         next record
* @return
*         Error code of function :
*   <dl>
*     <dt>S_OK</dt>
*     <dd>the new current record is valid.</dd>
*     <dt>S_FALSE</dt>
*     <dd>there are no more records.</dd>
*     <dt>E_FAIL </dt>
*     <dd>A problem occurs</dd>
*   </dl>
*/
  virtual HRESULT Next(CATComponentId   & oHandle) = 0;

  /**
  * Moves the cursor down one item from its current position and Returns the new item.
  *
  * @param iIID
  *   The IID associated to the request
  *   (assuming a kind of IUnknown* pointer as returned value)
  *
  * @param oPPV
  *   associated value of representation.
  *   Release() after usage the returned value of oPPV, if it has succeeded.
  *
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>the new current record is valid.</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>there are no more records.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs</dd>
  *   </dl>
  */
  virtual HRESULT Next(const IID &iIID, void **oPPV) = 0;


  /**
  *   Estimated Size of the contents of this <b>CATComponentIdSet<b>.
  *
  * @param oEstimatedSize
  *   Estimated Size.
  *
  * @return
  *    S_OK:      Success
  *    E_FAIL:    No List returned
  */
  virtual HRESULT EstimatedSize(int & oEstimatedSize) = 0;


};




#endif
