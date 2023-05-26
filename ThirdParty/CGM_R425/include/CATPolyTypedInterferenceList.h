// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyTypedInterferenceList.h
//
//===================================================================
//
// Usage notes:
// List of CATPolyInterference of a certain type (clash, contact, ...)
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyTypedInterferenceList_h
#define CATPolyTypedInterferenceList_h

#include "CATPolyBoundingVolumeOperators.h"

// Other
#include "CATBoolean.h"

// Interference
#include "CATPolyInterferenceList.h"
#include "CATIPolyInterference.h"

/**
 * List of CATPolyClashInterf
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyTypedInterferenceList
{
public:

  /**
   * Constructor
   * @pram type type of the interference to list (clash, contact, clearance,...)
   */
  CATPolyTypedInterferenceList(const CATPolyInterferenceList & actualList, CATIPolyInterference::InterferenceType type);
  virtual ~CATPolyTypedInterferenceList();

  /**
   * Size of the list.
   */
  int Size() const;

  /**
   * Iterator on interferences.
   * It is public to avoid compilation issues with some lousy compilers.
   * But it should not be used.
   */
  class ExportedByCATPolyBoundingVolumeOperators TypedIterator
  {
  public:
    TypedIterator(const CATPolyTypedInterferenceList & listRef);
    TypedIterator(const TypedIterator & it);

    void Begin();
    void operator++();
    CATBoolean End();

    const CATIPolyInterference * operator*() const;
    CATIPolyInterference * operator*();

  private:
    void GoToNextTypedInterf();
    const CATPolyTypedInterferenceList & _rListRef;
    CATPolyInterferenceList::Iterator _oIt;
  };

  friend class TypedIterator;

  /**
   * Get an iterator on the types interferences.
   */
  TypedIterator GetTypedIterator() const;

private:

  //------------------------------------------------------
  // Get the number of clashes found in an interference list
  int GetNbTypedInterferences(const CATPolyInterferenceList & actualList);
  //------------------------------------------------------
  // Actually this list does not contains anything,
  // It is just scanning the interference list to find clashes
  const CATPolyInterferenceList & _rActualList;
  int _iSize; // Compute it for faster access.
  CATIPolyInterference::InterferenceType _eInterfType; // Interference type to search
  //------------------------------------------------------
  
};

#endif // CATPolyTypedInterferenceList_h

