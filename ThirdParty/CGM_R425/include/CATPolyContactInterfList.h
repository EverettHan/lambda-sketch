// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyContactInterfList.h
//
//===================================================================
//
// Usage notes:
// List of CATPolyContactInterf
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyContactInterfList_h
#define CATPolyContactInterfList_h

#include "CATPolyBoundingVolumeOperators.h"

// Other
#include "CATSysBoolean.h"

// Polyhedral
#include "CATPolyRefCounted.h"

// Interference
#include "CATPolyTypedInterferenceList.h"
class CATPolyContactInterf;
class CATPolyInterferenceList;

/**
 * List of CATPolyClashInterf
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyContactInterfList : public CATPolyRefCounted 
{
public:

  /**
   * Constructor from a full interference list.
   * This class will extract the contacts from it.
   */
  CATPolyContactInterfList(const CATPolyInterferenceList & actualList);
  virtual ~CATPolyContactInterfList(); // WARNING : derived from CATPolyRefCounted
  

  /**
   * Size of the list.
   */
  int Size() const;

  /**
   * Iterator on contacts.
   */
  class ExportedByCATPolyBoundingVolumeOperators Iterator
  {
  public:
    Iterator(const CATPolyContactInterfList & listRef);
    Iterator(const Iterator & it);

    void Begin();
    void operator++();
    CATBoolean End();

    const CATPolyContactInterf * operator*() const;
    CATPolyContactInterf * operator*();

  private:
    CATPolyTypedInterferenceList::TypedIterator _oIt;
  };

  friend class Iterator;

  /**
   * Get an iterator on the contact interferences.
   */
  Iterator GetIterator() const;

private:

  // We're not able to derive from ref counted publicly and
  // CATPolyTypedInterferenceList protectedly.
  CATPolyTypedInterferenceList _oActualList;
  
};

#endif // CATPolyContactInterfList_h

