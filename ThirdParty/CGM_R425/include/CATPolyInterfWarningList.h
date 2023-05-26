// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfWarningList.h
//
//===================================================================
//
// Usage notes:
// Classes containing lists of warnings.
//
//===================================================================
//
// Jan 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterfWarningList_h
#define CATPolyInterfWarningList_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATListPV.h"
#include "CATMapOfIntIntToPtr.h"

// Polyhedral
#include "CATPolyRefCounted.h"

// Interference
class CATPolyInterferenceWarning;
class CATIPolyInterference;

// Define at the bottom of the file
class CATPolyInterfObjectPairWarnings;

/**
 * Classes containing all the warnings created by on operator.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfWarningList : public CATPolyRefCounted
{
public:


  CATPolyInterfWarningList();
  ~CATPolyInterfWarningList();

  /**
   * Add a warning in the list.
   * Actually a copy of the warning is inserted in the list.
   * So the input warning can be deleted afterwards.
   * @return TRUE if a copy of the warning in inserted in the list.
   *         FALSE if a warning with same properties was alredy inserted.
   */
  CATBoolean AddWarning(const CATPolyInterferenceWarning & warning);

  /**
   * Add several warnings into the list.
   * @param warnings Contains the list of warnings that will be poured into this one.
   */
  void AddWarnings(CATPolyInterfWarningList & warnings);

  /**
   * Get all the warnings relative to an interference.
   * See below for the declaration of CATPolyInterfObjectWarnings.
   * @return The list of associated warnings or NULL if there is not.
   */
  const CATPolyInterfObjectPairWarnings * GetInterferenceWarnings(const CATIPolyInterference * interf) const;

  /**
   * Get all the warnings relative to a couple of objects.
   * See below for the declaration of CATPolyInterfObjectWarnings.
   * @return The list of associated warnings or NULL if there is not.
   */
  const CATPolyInterfObjectPairWarnings * GetObjectPairWarnings(int firstObjectId, int secondObjectId) const;

  /**
   * @return wether the list contains some warnings or not.
   */
  CATBoolean IsEmpty() const;

  /**
   * Iterator on all the warnings contained in the list.
   */
  class ExportedByCATPolyBoundingVolumeOperators Iterator
  {
  public:
    Iterator(const CATPolyInterfWarningList & listRef);
    Iterator(const Iterator & it);

    void Begin();
    CATBoolean End();
    const CATPolyInterferenceWarning * operator*() const;
    void operator++();

  private:
    int _iCurIndex;
    CATMapOfIntIntToPtr::Iterator _oItList;
    const CATPolyInterfWarningList & _rListRef;
  };

  friend class Iterator;

  /**
   * Get an iterator on the warnings contained in the list.
   */
  Iterator GetIterator() const;

  /**
   * Specify whether to operator computation was between a single list or between two list.
   * If in single list, the object id can be in any order whereas in double list
   * the first id refer to the first list and the second to the second list.
   */
  void SetIsSingleListComputation(CATBoolean singleList);

private:

  CATMapOfIntIntToPtr _oObjectsWarnings; // Map between objects ids couple and their respective warnings.
  CATBoolean _bIsSingleListInterference; // To know whether the warnings refer to a single list interference or a double list one.
  
};

/**
 * Class containing all the warning relative to an pair of objects.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfObjectPairWarnings
{
public:

  CATPolyInterfObjectPairWarnings();
  ~CATPolyInterfObjectPairWarnings();

  /**
   * Add a warning in the list.
   * The list claims ownership of the warning and will destroy when deleted.
   */
  void AddWarning(const CATPolyInterferenceWarning * warning);

  /**
   * Iterator on all the warnings contained in the list.
   */
  class ExportedByCATPolyBoundingVolumeOperators Iterator
  {
  public:
    Iterator(const CATPolyInterfObjectPairWarnings & listRef);
    Iterator(const Iterator & it);

    void Begin();
    CATBoolean End();
    const CATPolyInterferenceWarning * operator*() const;
    void operator++();

  private:
    int _iCurIndex;
    const CATPolyInterfObjectPairWarnings & _rListRef;
  };

  friend class Iterator;

  /**
   * Get an iterator on the warnings contained in the list.
   */
  Iterator GetIterator() const;

  /**
   * Size of the list.
   */
  int Size() const;

  /**
   * Other way to access the data.
   * Range is 0..n-1
   */
  const CATPolyInterferenceWarning * operator[](int index) const;

  friend class CATPolyInterfWarningList;

private:

  CATListPV _oWarnings;

};



#endif // CATPolyInterfWarningList_h

