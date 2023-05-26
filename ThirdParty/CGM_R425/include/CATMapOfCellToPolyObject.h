// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfCellToPolyObject
//
//===================================================================
// July 2012 Creation: NDO
//===================================================================
#ifndef CATMapOfCellToPolyObject_h
#define CATMapOfCellToPolyObject_h

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATMapOfPtrToPtr.h"

class CATCell;
class CATIPolyObject;


/**
A map of CATCell instances to CATIPolyObject instances.
*/
class ExportedByTessBodyAdapters CATMapOfCellToPolyObject
{

public:

  /**
   * Constructs a map of CATCell To CATIPolyObject instances.
   */
  CATMapOfCellToPolyObject (const unsigned int iEstimatedSize = 0);
  ~CATMapOfCellToPolyObject ();

public:

  /**
   * Inserts a pair (CATCell, CATIPolyObject) in the map.
   * Upon successful insertion of a pair in the map, the method calls AddRef on the inserted CATIPolyObject.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> The CATCell instance and its mapped CATIPolyObject is inserted.
   *   <li> <tt>S_FALSE</tt> The CATCell instance is already in the map and is mapped to a matching CATIPolyObject.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted because the mapped CATIPolyObject does not match the input CATIPolyObject.
   * </ul>
   */
  HRESULT Insert (CATCell* iCell, CATIPolyObject* iPolyCell);

  /** 
   * Returns <tt>TRUE</tt> if the CATCell is associated to a CATIPolyObject.  
   * Returns <tt>FALSE</tt> if the CATCell is not found in the map.
   * The caller must release the returned CATIPolyObject instance.
   */
  CATBoolean Locate (CATCell* iCell, CATIPolyObject*& oPolyObject) const;

public:

  /**
   * Returns the number of elements in the map.
   */
  int Size () const {return _Map.Size ();}

  /**
   * Removes all the (CATCell, CATIPolyObject) instances from the map.
   * The method releases all the CATIPolyObject instances.
   */
  HRESULT RemoveAll ();

public:

  /**
   * Iterator cycling through all the elements in the map.
   */
  class ExportedByTessBodyAdapters Iterator
  {
  public:
    Iterator (const CATMapOfCellToPolyObject& map) : _It (map._Map) {}
    ~Iterator () {}

    /**
     * Returns the current CATCell instance.
     */
    CATCell* GetCell () const;

    /**
     * Returns the mapped CATIPolyObject instance.
     * The instance returned must be released by the caller.
     */
    CATIPolyObject* GetPolyObject () const;

    Iterator& Begin () {_It.Begin (); return *this;}
    CATBoolean End () const {return _It.End ();}
    Iterator& operator++ () {++_It; return *this;}

  private:
    CATMapOfPtrToPtr::Iterator _It;
  };

  friend class Iterator;

private:

 // A map of CATCell to CATIPolyObject.
 // If, in most cases, only few pairs are inserted in the map (say less than 5 pairs) then we may want to use a CATMapOfPtrToPtr with 
 // a smaller default size for the static array (5 instead of 21.)  This will reduce the memory size of the map.
 CATMapOfPtrToPtr _Map;  

};

#endif
