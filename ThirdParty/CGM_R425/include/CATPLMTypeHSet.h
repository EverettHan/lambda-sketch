/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeHSet_H
#define CATPLMTypeHSet_H

#include "CATPLMIdentificationAccess.h"
#include "CATOmxOHMap.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeHArray.h"
#include "CATBoolean.h"
#include "CATPLMTypeHIter.h"
#include "CATPLMTypeHCollectionBase.h"

/**
 * Class implementing a set of unique @href CATPLMTypeH objects.
 * <br><b>Role</b>: This class allows to handle a set of @href CATPLMTypeH objects.
 * There cannot be duplicates. The set is unsorted, ie the order in which the typeH are inserted is not kept.
 *
 * If you want to allow duplicates or manage the order of the typeH objects in the collection, use @href CATPLMTypeHArray instead.
 */
class ExportedByCATPLMIdentificationAccess CATPLMTypeHSet: public CATPLMTypeHCollectionBase
{
public:
  CATPLMTypeHSet();
  CATPLMTypeHSet(const CATPLMTypeHArray & iArray);
  CATPLMTypeHSet(const CATPLMTypeHSet & iOther);
  CATPLMTypeHSet & operator=(const CATPLMTypeHSet & iOther);
  ~CATPLMTypeHSet();

  unsigned Size() const;
  CATBoolean Exists(const CATPLMTypeH & iTypeH) const;

  /**
   * Those directives are not useful. They are just here to remember you of those key available methods.
   */
  using CATPLMTypeHCollectionBase::GetBestMatchingType;
  using CATPLMTypeHCollectionBase::GetMatchingTypes;
  using CATPLMTypeHCollectionBase::HasMatchingType;

  /**
   * Inserts a @href CATPLMTypeH into the set.
   * @param iTypeH [in]
   *        The @href CATPLMTypeH to insert into the set.
   * @return
   *        TRUE if iTypeH was not already present
   *        FALSE if iTypeH was already in the set
   */
  CATBoolean Insert(const CATPLMTypeH & iTypeH);
  void Insert(const CATPLMTypeHArray & iTypeHArray);
  void Insert(const CATPLMTypeHSet & iTypeHSet);

  /**
   * Removes a @href CATPLMTypeH from the set.
   * @param iTypeH [in]
   *        The @href CATPLMTypeH to remove from the set.
   * @return
   *        TRUE if iTypeH was present and removed
   *        FALSE if iTypeH was not in the set
   */
  CATBoolean Remove(const CATPLMTypeH & iTypeH);
  void RemoveAll();

  /**
   * Provides an iterator to browse the set.
   * @return
   *        A @href CATPLMTypeHIter object enabling to browse all the CATPLMTypeH objects in the collection.
   */
  CATPLMTypeHIter Iterator() const;

private:
  CATOmxOHMap<CATPLMTypeH, int> _Set;
  void VisitAllTypes( CATPLMTypeHVisitor & iVisitor);
};

#endif
