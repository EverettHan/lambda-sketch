#ifndef CATPLMTYPEHCOLLECTIONBASE_H_
#define CATPLMTYPEHCOLLECTIONBASE_H_

#include "CATPLMIdentificationAccess.h"
#include "CATOmxOHMap.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeHArray.h"

class CATPLMTypeHVisitor;
/**
* Base class for collections that needs to provide a generic and efficient acces
* to the types they contain from their derived types. Used for CATPLMTypeHMap, but
* may be reused to provide the same functionality on other collections (Arrays, Sets...)
* If you ever need those, please contact the Integration or TOS teams.
*/
class ExportedByCATPLMIdentificationAccess CATPLMTypeHCollectionBase
{
  CATOmxOHMap<CATPLMTypeH, CATPLMTypeHArray> _cachedMap;
public:
  CATPLMTypeHCollectionBase();
  virtual ~CATPLMTypeHCollectionBase();
  
  /**
   * Retrieves the best matching type available in the map based on the type hierarchy.
   * If the given type is in the collection, the result of this method will be itself.
   */
  CATPLMTypeH GetBestMatchingType(const CATPLMTypeH & iType);

  /**
   * Retrieves all the matching types available in the map based on the type hierarchy.
   * The array is ordered from best matching to least matching type. If the given type
   * is available in the collection, it will be the first in that aray.
   */
  CATPLMTypeHArray GetMatchingTypes(const CATPLMTypeH & iType);

  /**
   * Tell if a matching type can be found in the map.
   */
  CATBoolean HasMatchingType(const CATPLMTypeH & iType);

protected:
  /**
  * To be implemented by the derived collection.
  * It will be called during the initialisation of the cache for a given derived type.
  * It should call iVisitor.Visit on all the types contained in the collection.
  * See CATPLMTypeHMap::VisitAllTypes for an example.
  */
  virtual void VisitAllTypes(CATPLMTypeHVisitor & iVisitor)=0;

  /**
  * Update the cache to take into account a new type in the collection.
  * To be called each time a type is inserted in the derived collection
  */
  void UpdateTypeCacheAdd(const CATPLMTypeH & iType);

  /**
  * Update the cache to take in account the remove of a type from the collection.
  * To be called each time a type is removed from the derived collection
  */
  void UpdateTypeCacheRem(const CATPLMTypeH & iType);
  
  /**
  * Flush the cache.
  * Should be called at least when the derived collection is flushed.
  */
  void FlushTypeCache();
private:
  static void InsertTypeInArray(const CATPLMTypeH & iType, CATPLMTypeHArray & iArray);
};

#endif /* CATPLMTYPEHCOLLECTIONBASE_H_ */
