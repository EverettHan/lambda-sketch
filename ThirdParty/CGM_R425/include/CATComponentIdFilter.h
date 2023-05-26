#ifndef CATComponentIdFilter_H
#define CATComponentIdFilter_H

/**
 * @level Private
 * @usage U1
 */

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATTosMacros.h"
#include "CATPLMTypeId.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATLISTV_CATComponentId.h"
#include "CATPLMRepositoryName.h"
#include "CATComponentIdSearch.h"
#include "CATProxySpace.h"
#include "CATTosTodoLevel.h"
#include "CATPLMBagType.h"
#include "CATComponentIdStatus.h"
#include "CATOmxAny.h"
#include "CATOmxKeyValueBlock.h"
#include "CATPLMTypeHArray.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeDefinitionStrings.h"
#include "CATPLMCompletionLevel.h"

class CATOxSearchResult;


/**
 * Search criteria for CATComponentIdSearch
 * Hint: unlesss you are in a very basic case, prefer writing exactly whay you want to do instead
 * of trying to guess what you could do with the following
 */
class ExportedByCATPLMTos CATComponentIdFilter
{
public:

  /**
  * Empty Constructor
  * */
  CATComponentIdFilter();

 /**
 * Destructor
  */
  ~CATComponentIdFilter();

 /**
  * Constructor by Copy
  */
  CATComponentIdFilter(const CATComponentIdFilter &iCopy) = delete;
  CATComponentIdFilter& operator=(const CATComponentIdFilter &iCopy) = delete;


 /**
  * if TRUE (which is the default) only the cells with a state
  *   activated (kind of opened)
  * or
  *   deleted   (that must be deleted in DB)
  * will be returned.
  * In other words that's (probably) a way to exclude cells in "waiting" state (reserved in TOS but not opened)
  * redundant with "SetInMemory"
  */
  HRESULT SetPersistencyFilter(CATBoolean iPersistencyCompletion);


  /**
   * Same as SetStartingWithScope BUT if input objects are aggregated then their aggregating object is used instead.
   */
  HRESULT SetStartingWithRoot(CATBoolean iStartingWithRoot, const CATLISTV(CATComponentId)  & iRoots);

  /**
  * SetStartingWithBagRoots
  *
  * The analysis is starting with le components registered in specific bags.
  * Using a filter based on Public bags allows to exclude components used only for infrastructure usages like undoredo and settings.
  *
  * @param iStartingWithBagRoots
  *        Specified Bag roots filter
  * @param iBagTypeMask
  *        Specify the allowed bags
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT SetStartingWithBagRoots(CATBoolean iStartingWithBagRoots, CATPLMBagType iBagTypeMask);

  /**
   * if TRUE a kind of unspecifiable completion is made using aggregated/pointed object...
   */
  HRESULT SetWithExpandPointedScope(CATBoolean iWithExpandPointedScope);

  /**
  * Specify TOS to use (by default it is TOS without uuid...default "Authoring" TOS)
  */
  HRESULT SetFilterByTOS(CATBoolean iFilterByTOS, const CATProxySpace  & iTos);

  /**
  * Add a filter on the state of the TOS cells (see CATTosQuery_Filter)
  */
  HRESULT SetInMemory(const CATTosQuery_Filter & iInMemoryFilter);


  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //
  //    Type Status
  //
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  /**
  * SetCoreTypeFilter
  *
  * @param iCorePLMType
  *    Specified one Type filter
  *       PLMType_CoreReference
  *       PLMType_CoreRepReference
  *       PLMType_CoreInstance
  *       PLMType_CoreRepInstance
  *       PLMType_Connection
  *       PLMType_Port
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT SetCoreTypeFilter(const CATUnicodeString & iCorePLMType);

  /**
  * SetCoreTypeFilter
  *
  * @param iTypes
  *    Specified Core Type filter
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT  SetCoreTypesFilter(const CATPLMTypeHArray & iTypes);


  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //
  //    TodoStatus
  //
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  /**
  * SetFilterByTodoStatus
  *
  * @param iWithFilterByTodoStatus
  *
  * @param iTodoLevel
  *        Select the TOS level
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT SetFilterByTodoStatus(CATBoolean iWithFilterByTodoStatus, CATTosTodoLevel iTodoLevel = CatTosTodoLevel_Undefined);


  /**
  * SetFilterByCIDStatus
  *
  * @param iWithFilterByCIDStatus
  *
  * @param iCIDStatusMask
  *        The requested CID status
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT SetFilterByCIDStatus(CATBoolean iWithFilterByCIDStatus, CATComponentIdStatus iCIDStatusMask);


  /**
  * SetFilterByUIDisplayable
  *     Only components not belonging to system models like configuration are taken into account
  *
  * @param iWithFilterByUIDisplayable
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT SetFilterByUIDisplayable(CATBoolean iWithFilterByUIDisplayable);


  HRESULT SetFilterByProvider(CATBoolean iFilterByProvider, CATPLMRepositoryName      iTargetRepository);


  /**
   * DO NOT USE, CATASTROPHIC PERFORMANCES
   */
  HRESULT SetFilterByAttribute(CATOmxKeyValueBlock& iAttrBlock);

  /**
  * @deprecated V6R214
  * @use SetCoreTypeFilter( const CATUnicodeString & iCorePLMType )
  */
  HRESULT SetCoreTypeFilter(const char iCorePLMType[]);

  /**
  * @deprecated V6R214
  * @use SetCoreTypesFilter( CATPLMTypeHArray )
  */
  HRESULT  SetCoreTypesFilter(const CATLISTV(CATPLMTypeId) & iTypes);

private:

  CATTosQuery_Filter         _InMemory;

  CATPLMTypeId               _PLMTypeId;

  CATPLMTypeH                 _PLMTypeH;
  CATPLMTypeHArray            _TypesH;

  CATBoolean                  _IsFilteredByTos;
  CATProxySpace               _TosFiltering;


  CATPLMRepositoryName        _Repository;

  CATBoolean                  _PersistencyFilter;
  CATBoolean                  _WithExpandPointedScope;
  CATBoolean                  _IsFilteredByTodoStatus;
  CATTosTodoLevel             _TodoLevel;
  CATBoolean                  _IsFilteredByCIDStatus;
  CATComponentIdStatus        _CIDStatusMask;
  CATBoolean                  _IsFilteredByRepository;
  CATBoolean                  _IsFilteredByUIDisplayable;

  // Filtered by roots
  CATBoolean                  _IsFilteredByRoots;
  CATLISTV(CATComponentId)  _Roots;

  // Filtered by bag roots
  CATBoolean                  _IsFilteredByBagRoots;
  CATPLMBagType               _BagTypeMask;

  // Filtered by attribute value
  CATOmxKeyValueBlock         _AttrBlock;

  friend class CATOxSearchResult;
  friend class CATOxSearchBagRootsVisitor;
};



#endif
