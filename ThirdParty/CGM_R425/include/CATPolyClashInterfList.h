// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyClashInterfList.h
//
//===================================================================
//
// Usage notes:
// List of CATPolyClashInterf
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyClashInterfList_h
#define CATPolyClashInterfList_h

#include "CATPolyBoundingVolumeOperators.h"
// Other
#include "CATSysBoolean.h"

// Polyhedral
#include "CATPolyRefCounted.h"

// Interference
#include "CATPolyTypedInterferenceList.h"
class CATPolyClashInterf;
class CATPolyInterferenceList;

/**
 * List of CATPolyClashInterf
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyClashInterfList : public CATPolyRefCounted
{
public:

  /**
   * Constructor from a full interference list.
   * This class will extract the clash from it.
   */
  CATPolyClashInterfList(const CATPolyInterferenceList & actualList);
  virtual ~CATPolyClashInterfList(); // WARNING : derived from CATPolyRefCounted

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
    Iterator(const CATPolyClashInterfList & listRef);
    Iterator(const Iterator & it);

    void Begin();
    void operator++();
    CATBoolean End();

    const CATPolyClashInterf * operator*() const;
    CATPolyClashInterf * operator*();

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

#endif // CATPolyClashInterfList_h

