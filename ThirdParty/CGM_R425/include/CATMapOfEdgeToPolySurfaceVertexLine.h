// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfEdgeToPolySurfaceVertexLine
//
//===================================================================
// July 2012 Creation: NDO
//===================================================================
#ifndef CATMapOfEdgeToPolySurfaceVertexLine_h
#define CATMapOfEdgeToPolySurfaceVertexLine_h

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATMapOfCellToPolyObject.h"

class CATEdge;
class CATIPolySurfaceVertexLine;


/**
A map of CATEdge instances to CATIPolySurfaceVertexLine instances.
*/
class ExportedByTessBodyAdapters CATMapOfEdgeToPolySurfaceVertexLine
{

public:

  /**
   * Constructs a map of CATEdge to CATIPolySurfaceVertexLine instances.
   */
  CATMapOfEdgeToPolySurfaceVertexLine (const unsigned int iEstimatedSize = 0);
  ~CATMapOfEdgeToPolySurfaceVertexLine ();

public:

  /**
   * Inserts a pair (CATEdge, CATIPolySurfaceVertexLine) in the map.
   * Upon successful insertion of a pair in the map, the method calls AddRef on the inserted CATIPolySurfaceVertexLine.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> The CATEdge instance and its mapped CATIPolySurfaceVertexLine is inserted.
   *   <li> <tt>S_FALSE</tt> The CATEdge instance is already in the map and is mapped to a matching CATIPolySurfaceVertexLine.
   *   <li> <tt>E_FAIL</tt> The pair cannot be inserted because the mapped CATIPolySurfaceVertexLine does not match the input CATIPolySurfaceVertexLine.
   * </ul>
   */
  HRESULT Insert (CATEdge* iEdge, CATIPolySurfaceVertexLine* iPolySurfaceVertexLine);

  /** 
   * Returns <tt>TRUE</tt> if the CATEdge is associated to a CATIPolySurfaceVertexLine.  
   * Returns <tt>FALSE</tt> if the CATEdge is not found in the map.
   * The caller must release the returned CATIPolySurfaceVertexLine instance.
   */
  CATBoolean Locate (CATEdge* iEdge, CATIPolySurfaceVertexLine*& oPolySurfaceVertexLine) const;

public:

  /**
   * Returns the number of elements in the map.
   */
  int Size () const {return _Map.Size ();}

  /**
   * Removes all the (CATEdge, CATIPolySurfaceVertexLine) instances from the map.
   * The method releases all the CATIPolySurfaceVertexLine instances.
   */
  HRESULT RemoveAll ();

public:

  /**
   * Iterator cycling through all the elements in the map.
   */
  class ExportedByTessBodyAdapters Iterator
  {
  public:
    Iterator (const CATMapOfEdgeToPolySurfaceVertexLine& map) : _It (map._Map) {}
    ~Iterator () {}

    /**
     * Returns the current CATEdge instance.
     */
    CATEdge* GetEdge () const {return (CATEdge*) _It.GetCell ();}

    /**
     * Returns the mapped CATIPolySurfaceVertexLine instance.
     * The instance returned must be released by the caller.
     */
    CATIPolySurfaceVertexLine* GetPolySurfaceVertexLine () const {return (CATIPolySurfaceVertexLine*) _It.GetPolyObject ();}

    Iterator& Begin () {_It.Begin (); return *this;}
    CATBoolean End () const {return _It.End ();}
    Iterator& operator++ () {++_It; return *this;}

  private:
    CATMapOfCellToPolyObject::Iterator _It;
  };

  friend class Iterator;

private:

 CATMapOfCellToPolyObject _Map;  // A map of CATEdge to CATIPolySurfaceVertexLine.

};

#endif
