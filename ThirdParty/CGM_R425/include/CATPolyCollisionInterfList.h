// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCollisionInterfList.h
//
//===================================================================
//
// Usage notes:
// List of CATPolyCollisionInterf
//
//===================================================================
//
// 2010-04-20 XXC: New
//===================================================================

#ifndef CATPolyCollisionInterfList_h
#define CATPolyCollisionInterfList_h

#include "CATPolyBoundingVolumeOperators.h"
// Other
#include "CATBoolean.h"

// Polyhedral
#include "CATPolyRefCounted.h"

// Interference
#include "CATPolyTypedInterferenceList.h"
class CATPolyCollisionInterf;
class CATPolyInterferenceList;

/**
 * List of CATPolyCollisionInterf
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyCollisionInterfList : public CATPolyRefCounted
{
public:

  /**
   * Constructor from a full interference list.
   * This class will extract the clash from it.
   */
  CATPolyCollisionInterfList(const CATPolyInterferenceList & actualList);
  virtual ~CATPolyCollisionInterfList(); // derived from CATPolyRefCounted: use AddRef() / Release() instead

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
    Iterator(const CATPolyCollisionInterfList & listRef);
    Iterator(const Iterator & it);

    void Begin();
    void operator++();
    CATBoolean End();

    const CATPolyCollisionInterf * operator*() const;
    CATPolyCollisionInterf * operator*();

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

#endif // CATPolyCollisionInterfList_h

