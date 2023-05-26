// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfVertexToPolySurfaceVertex
//
//===================================================================
// July 2012 Creation: NDO
//===================================================================
#ifndef CATMapOfVertexToPolySurfaceVertex_h
#define CATMapOfVertexToPolySurfaceVertex_h

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATMapOfCellToPolyObject.h"

class CATVertex;
class CATIPolySurfaceVertex;


/**
A map of CATVertex instances to CATIPolySurfaceVertex instances.
*/
class ExportedByTessBodyAdapters CATMapOfVertexToPolySurfaceVertex
{

public:

  /**
   * Constructs a map of CATVertex to CATIPolySurfaceVertex instances.
   */
  CATMapOfVertexToPolySurfaceVertex (const unsigned int iEstimatedSize = 0);
  ~CATMapOfVertexToPolySurfaceVertex ();

public:

  /**
   * Inserts a pair (CATVertex, CATIPolySurfaceVertex) in the map.
   * Upon successful insertion of a pair in the map, the method calls AddRef on the inserted CATIPolySurfaceVertex.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> The CATVertex instance and its mapped CATIPolySurfaceVertex is inserted.
   *   <li> <tt>S_FALSE</tt> The CATVertex instance is already in the map and is mapped to a matching CATIPolySurfaceVertex.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted because the mapped CATIPolySurfaceVertex does not match the input CATIPolySurfaceVertex.
   * </ul>
   */
  HRESULT Insert (CATVertex* iEdge, CATIPolySurfaceVertex* iPolySurfaceVertex);

  /** 
   * Returns <tt>TRUE</tt> if the CATVertex is associated to a CATIPolySurfaceVertex.  
   * Returns <tt>FALSE</tt> if the CATVertex is not found in the map.
   * The caller must release the returned CATIPolySurfaceVertex instance.
   */
  CATBoolean Locate (CATVertex* iEdge, CATIPolySurfaceVertex*& oPolySurfaceVertex) const;

public:

  /**
   * Returns the number of elements in the map.
   */
  int Size () const {return _Map.Size ();}

  /**
   * Removes all the (CATVertex, CATIPolySurfaceVertex) instances from the map.
   * The method releases all the CATIPolySurfaceVertex instances.
   */
  HRESULT RemoveAll ();

public:

  /**
   * Iterator cycling through all the elements in the map.
   */
  class ExportedByTessBodyAdapters Iterator
  {
  public:
    Iterator (const CATMapOfVertexToPolySurfaceVertex& map) : _It (map._Map) {}
    ~Iterator () {}

    /**
     * Returns the current CATVertex instance.
     */
    CATVertex* GetVertex () const {return (CATVertex*) _It.GetCell ();}

    /**
     * Returns the mapped CATIPolySurfaceVertex instance.
     * The instance returned must be released by the caller.
     */
    CATIPolySurfaceVertex* GetPolySurfaceVertex () const {return (CATIPolySurfaceVertex*) _It.GetPolyObject ();}

    Iterator& Begin () {_It.Begin (); return *this;}
    CATBoolean End () const {return _It.End ();}
    Iterator& operator++ () {++_It; return *this;}

  private:
    CATMapOfCellToPolyObject::Iterator _It;
  };

  friend class Iterator;

private:

 CATMapOfCellToPolyObject _Map;  // A map of CATVertex to CATIPolySurfaceVertex.

};

#endif
