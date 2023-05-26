// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfCellToMapOfInt
//
//===================================================================
//
// August 2009 Creation: NDO
//===================================================================
#ifndef CATMapOfCellToMapOfInt_h
#define CATMapOfCellToMapOfInt_h

#include "TessPolygon.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATMapOfPtrToPtr.h"

class CATIPolySurface;
class CATMapOfIntToInt;


/**
A map of CATPolyCell instances to CATPolyCell instances.
*/
class ExportedByTessPolygon CATMapOfCellToMapOfInt : protected CATMapOfPtrToPtr
{

public:

	CATMapOfCellToMapOfInt(const int iDimension = 0) : CATMapOfPtrToPtr(iDimension) {}
	~CATMapOfCellToMapOfInt() {}

public:

	/**
	 * Inserts a pair (CATPolyCell, CATPolyCell) in the map.
	 * @return
	 * <ul>
	 *   <li> <tt>S_OK</tt> The CATPolyCell instance and its mapped CATPolyCell is inserted.
	 *   <li> <tt>S_FALSE</tt> The CATPolyCell instance is already in the map and is mapped to a matching CATPolyCell.
	 *   <li> <tt>E_FAIL</tt> The pair cannot be inserted because the mapped CATPolyCell does not match the input CATPolyCell.
	 * </ul>
	 */
	HRESULT Insert(CATIPolySurface* iCell, CATMapOfIntToInt* iMap) { return CATMapOfPtrToPtr::Insert(iCell, iMap); }

	/**
	 * Removes a iCell from the map.  If the iCell is not found in the map, the method returns S_FALSE.
	 */
	HRESULT Remove(CATIPolySurface* iCell) { return CATMapOfPtrToPtr::Remove(iCell); }

	/**
	 * Returns <tt>TRUE</tt> if the CATPolyCell is associated to a CATPolyCell.
	 * Returns <tt>FALSE</tt> if the CATPolyCell is not found in the map.
	 */
	CATBoolean Locate(CATIPolySurface* iCell, CATMapOfIntToInt* &iMap) const { return CATMapOfPtrToPtr::Locate(iCell, (void*&)iMap); }

public:

	/**
	 * Returns the number of elements in the map.
	 */
	int Size() const { return CATMapOfPtrToPtr::Size(); }

	HRESULT RemoveAll() { return CATMapOfPtrToPtr::RemoveAll(); }

public:

	/**
	 * Iterator cycling through all the elements in the map.
	 */
	
	class ExportedByTessPolygon Iterator
	{
	public:
		Iterator( CATMapOfCellToMapOfInt& map) : _It(map) {}
		~Iterator() {}

		CATIPolySurface* GetPolyCell()  { return (CATIPolySurface*)_It.GetKey(); }
		CATMapOfIntToInt* GetMapOfIntToInt() { return (CATMapOfIntToInt*)_It.GetData(); }

		Iterator& Begin() { _It.Begin(); return *this; }
		CATBoolean End()  { return _It.End(); }
		Iterator& operator++ () { ++_It; return *this; }

	private:
		CATMapOfPtrToPtr::Iterator _It;
	};

	friend class Iterator;

};

#endif
