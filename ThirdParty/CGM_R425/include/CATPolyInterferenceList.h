// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceList.h
//
//===================================================================
//
// Usage notes:
// List of CATPolyInterferences
//
//===================================================================
//
// Jul 2009 Creation: JS9
//===================================================================

#ifndef CATPolyInterferenceList_h
#define CATPolyInterferenceList_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATListPV.h"
#include "CATBoolean.h"

// Polyhedral
#include "CATPolyRefCounted.h"

// Interference
class CATIPolyInterference;

/**
 * Interface describing an interference.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceList : public CATPolyRefCounted
{
public:

  CATPolyInterferenceList();

  /**
   * Add a new interference in the list
   */
  virtual void AddInterference(CATIPolyInterference * interf);

  /**
   * Add a several interferences in the list from an other list.
   * The second list is empty to avoid duplication of interferences.
   */
  virtual void AddInterferences(CATPolyInterferenceList * interfs);

  /**
   * Size of the list.
   */
  int Size() const;

  /**
   * @return the interference with a certain index in the list.
   */
  const CATIPolyInterference * operator[](int index);

  /**
   * Iterator on interferences.
   */
  class ExportedByCATPolyBoundingVolumeOperators Iterator
  {
  public:
    Iterator(const CATPolyInterferenceList & listRef);
    Iterator(const Iterator & it);

    void Begin();
    CATBoolean End();
    virtual const CATIPolyInterference * operator*() const;
    virtual CATIPolyInterference * operator*();
    void operator++();

  private:
    int _CurIndex;
    const CATPolyInterferenceList & _ListRef;
  };

  friend class Iterator;

  /**
   * Get an iterator on the interferences.
   */
  virtual Iterator GetIterator() const;

  /**
   * Sort the list of interferences.
   * Interferences are sorted first by the id of the first interfering object
   * then on the id of the second interfering objects.
   */
  void Sort();

  /**
   * Generic sort on the interferences based on a comparison function.
   * The comparison function must return -1 is interf1 is lower than interf2,
   * 0 if they are equals and 1 if interf1 is greater than interf2.
   */
  void Sort(int (*compareFunc)(const CATIPolyInterference * interf1, const CATIPolyInterference * interf2));

  /**
   * Swap all the interferences whose first object id is greater than the second.
   * To be used only if the list comes from a an interference computation
   * from a single list.
   */
  void SetLowerIdsFirst();

  /**
   * Remove an interference from the list.
   */
  void RemoveInterference(const CATIPolyInterference * interf);

  /**
   * Remove all the interferences from the list.
   */
  void RemoveAllInterferences();

protected:

  // This is a ref counted
  virtual ~CATPolyInterferenceList();

private:

  //------------------------------------------
  static int IdSort(const CATIPolyInterference * interf1, const CATIPolyInterference * interf2);
  static int VoidToInterfComparison(const void * p1, const void * p2);
  //------------------------------------------
  CATListPV _oList;
  //------------------------------------------
  
};

#endif // CATPolyInterferenceList_h

