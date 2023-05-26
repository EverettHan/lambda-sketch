// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyClearanceInterfList.h
//
//===================================================================
//
// Usage notes:
// List of CATPolyClearanceInterf
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyClearanceInterfList_h
#define CATPolyClearanceInterfList_h

#include "CATPolyBoundingVolumeOperators.h"

// Other
#include "CATSysBoolean.h"

// Polyhedral
#include "CATPolyRefCounted.h"

// Interference
#include "CATPolyTypedInterferenceList.h"
class CATPolyClearanceInterf;
class CATPolyInterferenceList;

/**
 * List of CATPolyClashInterf
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyClearanceInterfList : public CATPolyRefCounted
{
public:

  /**
   * Constructor from a full interference list.
   * This class will extract the clearance from it.
   */
  CATPolyClearanceInterfList(const CATPolyInterferenceList & actualList);
  virtual ~CATPolyClearanceInterfList(); // WARNING : derived from CATPolyRefCounted

  /**
   * Size of the list.
   */
  int Size() const;

  /**
   * Iterator on clearances.
   */
  class ExportedByCATPolyBoundingVolumeOperators Iterator
  {
  public:
    Iterator(const CATPolyClearanceInterfList & listRef);
    Iterator(const Iterator & it);

    void Begin();
    void operator++();
    CATBoolean End();

    const CATPolyClearanceInterf * operator*() const;
    CATPolyClearanceInterf * operator*();


  private:
    CATPolyTypedInterferenceList::TypedIterator _oIt;
  };

  friend class Iterator;

  /**
   * Get an iterator on the clearance interferences.
   */
  Iterator GetIterator() const;

private:

  // We're not able to derive from ref counted publicly and
  // CATPolyTypedInterferenceList protectedly.
  CATPolyTypedInterferenceList _oActualList;
  
  
};

#endif // CATPolyClearanceInterfList_h

