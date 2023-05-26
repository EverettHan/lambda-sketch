// COPYRIGHT DASSAULT SYSTEMES 2003, all rights reserved
//===================================================================
//
// CATPolyRefineMap.h
//
//===================================================================
// Sep 2003 Creation: dhp
//===================================================================
#ifndef CATPolyRefineMap_h
#define CATPolyRefineMap_h

#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"

#include "CATListOfInt.h"

class CATHashTable;
class TriangleMap;
class TriangleParent;

class CATCGMOutput;

class ExportedByCATPolyMiscellaneous CATPolyRefineMap 
{

public :

  /**
  * Default constructor.
  */
	CATPolyRefineMap (void);

  /**
  * Copy constructor.
  */
	CATPolyRefineMap (const CATPolyRefineMap & rhs);

  /**
  * Destructor.
  */
	~CATPolyRefineMap (void);

  /**
  * Assignment operator.
  */
	CATPolyRefineMap & operator = (const CATPolyRefineMap & rhs);

  /**
  * Gets the child triangles of the specified triangle.
  * @param triangle
  *   The triangle for which the child triangles are desired.
  * @param children
  *   The child triangles.
  * @return
  *   TRUE if the triangle exists in the map and FALSE otherwise.
  */
  CATBoolean GetChildren (const int triangle,
    CATListOfInt & children) const;

  /**
  * Updates the map.  It also works for a deleted triangle.  A deleted triangle maps to a triangle of index 0.
  * @param triangle
  *   The triangle that was refined.
  * @param targetTriangle
  *   The new triangle corresponding to the refined triangle.  Or 0 if the triangle is deleted.
  */
  void UpdateTriangle (const int triangle,
    const int targetTriangle);

  /**
  * Updates the map.  It also works for a deleted triangle. 
  * @param triangle
  *   The triangle that was refined.
  * @param triangles
  *   The new triangles corresponding to the refined triangle.  Or an empty list for a deleted triangle.
  */
  void UpdateTriangle (const int triangle,
    const CATListOfInt & triangles);

  /**
  * Updates this map with another map.
  * @param rhs
  *   The map with which to update this map.
  */
  void Update (const CATPolyRefineMap & rhs);

  /**
  * Gets the list of triangles that have been refined.
  * @param triangles
  *   The triangles that have been refined.
  */
  void GetRefinedTriangles (CATListOfInt & triangles) const;

  /**
  * Gets the list of triangles that have been refined along
  * with their children.
  * @param triangles
  *   The triangles that have been refined.
  * @param trianglesMap
  *   An array of list of triangles that were produced by the refinement. To each
  *   triangle in <tt>triangles</tt>, is associated a list of entries in the array.
  *   <tt>trianglesMap</tt>.  The size of the array is the number of triangles in
  *   <tt>triangles</tt>.  The array is allocated with the new operator and must be 
  *   deleted with the delete [] operator by the caller.
  */
  void GetTriangles (CATListOfInt & triangles,
    CATListOfInt *& trianglesMap) const;

  /**
  * Gets all children of the refined triangles.
  * @param triangles
  *   The children corresponding to all refined triangles.
  */
  void GetNewTriangles (CATListOfInt & triangles) const;

  /**
  * Removes all information from the map.
  */
  void Clear (void);

private :

  void Print (CATCGMOutput & stream) const;

  TriangleMap * FindTriangle (const int triangle) const;

  TriangleParent * FindParent (const int triangle) const;

  CATBoolean RemoveParent (const int triangle);

  void AddParent (const int triangle,
    const int parent);

  CATHashTable * _hashTable;

  CATHashTable * _parentHashTable;

};

#endif
