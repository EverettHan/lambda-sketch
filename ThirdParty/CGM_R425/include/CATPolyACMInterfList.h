// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyACMInterfList.h
//
//===================================================================
//
// Usage notes:
// List of CATPolyACMInterf
//
//===================================================================

#ifndef CATPolyACMInterfList_h
#define CATPolyACMInterfList_h

#include "CATPolyBoundingVolumeOperators.h"
// Other
#include "CATBoolean.h"

// Polyhedral
#include "CATPolyRefCounted.h"

// Interference
#include "CATPolyTypedInterferenceList.h"
class CATPolyACMInterf;
class CATPolyInterferenceList;

/**
 * List of CATPolyACMInterf
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyACMInterfList : public CATPolyRefCounted
{
public:

  /**
   * Constructor from a full interference list.
   * This class will extract the clash from it.
   */
  CATPolyACMInterfList(const CATPolyInterferenceList & actualList);
  virtual ~CATPolyACMInterfList(); // derived from CATPolyRefCounted: use AddRef() / Release() instead

public:

  /**
   * Size of the list.
   */
  int Size() const;

  /**
   * Iterator on interferences.
   */
  class ExportedByCATPolyBoundingVolumeOperators Iterator
  {
  public:
    Iterator(const CATPolyACMInterfList & listRef);
    Iterator(const Iterator & it);

    void Begin();
    void operator++();
    CATBoolean End();

    const CATPolyACMInterf * operator*() const;
    CATPolyACMInterf * operator*();

  private:
    CATPolyTypedInterferenceList::TypedIterator _oIt;
  };

  /**
   * Get an iterator on the clash interferences.
   */
  virtual Iterator GetIterator() const;

private:

  // We're not able to derive from ref counted publicly and
  // CATPolyTypedInterferenceList protectedly.
  CATPolyTypedInterferenceList _oActualList;

};

#endif // CATPolyACMInterfList_h

