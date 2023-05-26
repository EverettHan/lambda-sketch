// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfVertexToPolyCurveVertex
//
//===================================================================
// July 2012 Creation: NDO
//===================================================================
#ifndef CATMapOfVertexToPolyCurveVertex_h
#define CATMapOfVertexToPolyCurveVertex_h

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATMapOfCellToPolyObject.h"

class CATVertex;
class CATIPolyCurveVertex;


/**
A map of CATVertex instances to CATIPolyCurveVertex instances.
*/
class ExportedByTessBodyAdapters CATMapOfVertexToPolyCurveVertex
{

public:

  /**
   * Constructs a map of CATVertex to CATIPolyCurveVertex instances.
   */
  CATMapOfVertexToPolyCurveVertex (const unsigned int iEstimatedSize = 0);
  ~CATMapOfVertexToPolyCurveVertex ();

public:

  /**
   * Inserts a pair (CATVertex, CATIPolyCurveVertex) in the map.
   * Upon successful insertion of a pair in the map, the method calls AddRef on the inserted CATIPolyCurveVertex.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> The CATVertex instance and its mapped CATIPolyCurveVertex is inserted.
   *   <li> <tt>S_FALSE</tt> The CATVertex instance is already in the map and is mapped to a matching CATIPolyCurveVertex.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted because the mapped CATIPolyCurveVertex does not match the input CATIPolyCurveVertex.
   * </ul>
   */
  HRESULT Insert (CATVertex* iEdge, CATIPolyCurveVertex* iPolyCurveVertex);

  /** 
   * Returns <tt>TRUE</tt> if the CATVertex is associated to a CATIPolyCurveVertex.  
   * Returns <tt>FALSE</tt> if the CATVertex is not found in the map.
   * The caller must release the returned CATIPolyCurveVertex instance.
   */
  CATBoolean Locate (CATVertex* iEdge, CATIPolyCurveVertex*& oPolyCurveVertex) const;

public:

  /**
   * Returns the number of elements in the map.
   */
  int Size () const {return _Map.Size ();}

  /**
   * Removes all the (CATVertex, CATIPolyCurveVertex) instances from the map.
   * The method releases all the CATIPolyCurveVertex instances.
   */
  HRESULT RemoveAll ();

public:

  /**
   * Iterator cycling through all the elements in the map.
   */
  class ExportedByTessBodyAdapters Iterator
  {
  public:
    Iterator (const CATMapOfVertexToPolyCurveVertex& map) : _It (map._Map) {}
    ~Iterator () {}

    /**
     * Returns the current CATVertex instance.
     */
    CATVertex* GetVertex () const {return (CATVertex*) _It.GetCell ();}

    /**
     * Returns the mapped CATIPolyCurveVertex instance.
     * The instance returned must be released by the caller.
     */
    CATIPolyCurveVertex* GetPolyCurveVertex () const {return (CATIPolyCurveVertex*) _It.GetPolyObject ();}

    Iterator& Begin () {_It.Begin (); return *this;}
    CATBoolean End () const {return _It.End ();}
    Iterator& operator++ () {++_It; return *this;}

  private:
    CATMapOfCellToPolyObject::Iterator _It;
  };

  friend class Iterator;

private:

 CATMapOfCellToPolyObject _Map;  // A map of CATVertex to CATIPolyCurveVertex.

};

#endif
