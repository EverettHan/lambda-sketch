/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeHArray_H
#define CATPLMTypeHArray_H

#include "CATOmxArray.h"
#include "CATPLMTypeH.h"

class CATPLMTypeHSet;

/**
 * Class implementing an array of @href CATPLMTypeH objects.
 * <br><b>Role</b>: This class allows to handle an array of @href CATPLMTypeH objects.
 * The @href CATPLMTypeH objects are indexed, with index starting from 1. There can be duplicates.
 *
 * If you want to forbid duplicates and don't need to manage an order, use @href CATPLMTypeHSet instead.
 */
class ExportedByCATPLMIdentificationAccess CATPLMTypeHArray
{
public:
  CATPLMTypeHArray();
  CATPLMTypeHArray(const CATPLMTypeHSet & iArray);
  CATPLMTypeHArray(const CATPLMTypeHArray & iOther);
  CATPLMTypeHArray & operator=(const CATPLMTypeHArray & iOther);
  ~CATPLMTypeHArray();

  unsigned Size() const;

 /**
  * Appends a @href CATPLMTypeH at the end of the array.
  * @param iTypeH [in]
  *        The @href CATPLMTypeH to append.
  */
  void Append(const CATPLMTypeH & iTypeH);

 /**
  * Appends a @href CATPLMTypeHArray at the end of the array.
  * @param iTypeHArray [in]
  *        The @href CATPLMTypeHArray to append.
  */
  void Append(const CATPLMTypeHArray & iTypeHArray);

 /**
  * Sets iTypeH at ith position.
  * @param i [in]
  *        The index at which to insert iTypeH.
  * @param iTypeH [in]
  *        The @href CATPLMTypeH to insert.
  */
  void Insert(int i, const CATPLMTypeH & iTypeH);

 /**
  * Sets the ith element of the array with the value iTypeH.
  * @param i [in]
  *        The index at which to put iTypeH. Must be smaller or equal than Size().
  * @param iTypeH [in]
  *        The @href CATPLMTypeH to set.
  */
  void Set(int i, const CATPLMTypeH & iTypeH);

 /**
  * Returns a read-only reference on the ith element of the array.
  * Do not use this to modify the array (use Set instead).
  * @param i [in]
  *        The index of the CATPLMTypeH object to return.
  * @return
  *        A read-only reference on the ith element of the array.
  */
  const CATPLMTypeH & operator [] (int i) const;

 /**
  * Returns the index of the first occurrence of iTypeH in the array.
  * @param iTypeH [in]
  *        The @href CATPLMTypeH to locate.
  * @return
  *        The index of the first occurrence of iTypeH.
  */
  int Locate(const CATPLMTypeH & iTypeH) const;

 /**
  * Removes the ith element of the array.
  * @param i [in]
  *        The index of the TypeH to remove.
  */
  void Remove(int i);
  void RemoveAll();

 /**
  * Removes the first occurrence of iTypeH from the array.
  * @param iTypeH [in]
  *        The @href CATPLMTypeH to remove.
  */
  void RemoveValue(const CATPLMTypeH & iTypeH);

 /**
  * Swaps the ith and the jth elements of the array.
  * @param i, j [in]
  *        The index of elements to swap.
  */
  void Swap(int i, int j);

 /**
  * Reverses the array.
  */
  void Reverse();


private:
  CATOmxArray<CATPLMTypeH> _array;
};

#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMTypeHArray>::manager();
#endif
