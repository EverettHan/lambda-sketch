// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfCellToPolyCell
//
//===================================================================
//
// August 2009 Creation: NDO
//===================================================================
#ifndef CATMapOfCellToPolyCell_h
#define CATMapOfCellToPolyCell_h

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATMapOfPtrToPtr.h"

class CATCell;
class CATPolyCell;


/**
A map of CATCell instances to CATPolyCell instances.
*/
class ExportedByTessBodyAdapters CATMapOfCellToPolyCell : protected CATMapOfPtrToPtr
{

public:

  CATMapOfCellToPolyCell (const int iDimension = 0) : CATMapOfPtrToPtr (iDimension) {}
  ~CATMapOfCellToPolyCell () {}

public:

  /**
   * Inserts a pair (CATCell, CATPolyCell) in the map.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> The CATCell instance and its mapped CATPolyCell is inserted.
   *   <li> <tt>S_FALSE</tt> The CATCell instance is already in the map and is mapped to a matching CATPolyCell.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted because the mapped CATPolyCell does not match the input CATPolyCell.
   * </ul>
   */
  HRESULT Insert (CATCell* iCell, CATPolyCell* iPolyCell) {return CATMapOfPtrToPtr::Insert (iCell, iPolyCell);}

  /** 
   * Removes a iCell from the map.  If the iCell is not found in the map, the method returns S_FALSE.
   */
  HRESULT Remove (CATCell* iCell) {return CATMapOfPtrToPtr::Remove (iCell);}

  /** 
   * Returns <tt>TRUE</tt> if the CATCell is associated to a CATPolyCell.  
   * Returns <tt>FALSE</tt> if the CATCell is not found in the map.
   */
  CATBoolean Locate (CATCell* iCell, CATPolyCell*& data) const {return CATMapOfPtrToPtr::Locate (iCell, (void*&) data);}

public:

  /**
   * Returns the number of elements in the map.
   */
  int Size () const {return CATMapOfPtrToPtr::Size ();}

  HRESULT RemoveAll () {return CATMapOfPtrToPtr::RemoveAll ();}

public:

  /**
   * Iterator cycling through all the elements in the map.
   */
  class ExportedByTessBodyAdapters Iterator
  {
  public:
    Iterator (const CATMapOfCellToPolyCell& map) : _It (map) {}
    ~Iterator () {}

    CATCell* GetCell () const {return (CATCell*) _It.GetKey ();}
    CATPolyCell* GetPolyCell () const {return (CATPolyCell*) _It.GetData ();}

    Iterator& Begin () {_It.Begin (); return *this;}
    CATBoolean End () const {return _It.End ();}
    Iterator& operator++ () {++_It; return *this;}

  private:
    CATMapOfPtrToPtr::Iterator _It;
  };

  friend class Iterator;

};

#endif
