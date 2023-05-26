// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanSegments1.h
//
//===================================================================
// December 2005 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanSegments1_H
#define CATPolyBooleanSegments1_H

#include "CATPolyBooleanOperators.h"
#include "CATBoolean.h"

class CATIPolyMesh;
class CATPolyBooleanIntersectionPoints;
class CATPolyIntersectionPoint;
class CATHTableOfIntInt;
class CATHTableOfIntIntIterator;
class CATCGMOutput;


/*
Container of intersection segments.  The intersection segments are defined symbolically in this class by two
instances of CATPolyIntersectionPoint (intersection points.)  No geometry is constructed in this class.
*/
class ExportedByCATPolyBooleanOperators CATPolyBooleanSegments1 
{

public :

  CATPolyBooleanSegments1 (const CATIPolyMesh* iMesh0, const CATIPolyMesh* iMesh1);

  ~CATPolyBooleanSegments1 ();

  /*
   * Adds an intersection point and returns its index.
   * Returns 0 if the intersection point could not be added.
   */
  int AddIntersectionPoint (const CATPolyIntersectionPoint& iPoint);

  /* 
   * Returns the index of an intersection point or 0 if the intersection point is not found.
   */
  int GetIndex (const CATPolyIntersectionPoint& iPoint) const;

  CATBoolean AddSegment (const int iIdxPoint0, const int iIdxPoint1);

  CATBoolean RemoveSegment (const int iIdxPoint0, const int iIdxPoint1);

  // LocateSegment is not symmetric because segments are oriented!  
  // LocateSegment (iIdxPoint0, iIdxPoint1) != LocateSegment (iIdxPoint1, iIdxPoint0).
  CATBoolean LocateSegment (const int iIdxPoint0, const int iIdxPoint1) const;

  /**
  * Returns the number of intersection points.
  */
  int GetNbIntersectionPoints () const;

  /**
  * Returns the number of intersection segments.
  */
  int GetNbSegments () const;

  /** 
  * Return an intersection point.
  */
  const CATPolyIntersectionPoint& GetIntersectionPoint (const int iIdxPoint) const;

  /*
  * Returns the mesh.
  * @param iMesh
  *   The mesh index: 0 for the first mesh and 1 for the second mesh.
  * @return
  *   The mesh.  The method does not AddRef () to the returned object.
  */
  const CATIPolyMesh* GetMesh (const int iMesh) const;

  // For debugging purposes.
  void Print (CATCGMOutput & stream) const;
  void PrintIntersectionPoints (CATCGMOutput & stream) const;
  void PrintSegments (CATCGMOutput& stream) const;
  void PrintConcatenation (CATCGMOutput& stream) const;

private :

  CATPolyBooleanIntersectionPoints* _IntersectionPoints;
  CATHTableOfIntInt* _Segments;

  friend class CATPolyBooleanSegments1Iterator;
};


class ExportedByCATPolyBooleanOperators CATPolyBooleanSegments1Iterator
{

public:

  CATPolyBooleanSegments1Iterator (const CATPolyBooleanSegments1& iSegments);

  ~CATPolyBooleanSegments1Iterator ();

  // Resets the iterator to the beginning.
  void Beginning ();

  // Increments the iterator and returns an intersection segment.
  // Returns TRUE if a valid segment is returned and FALSE otherwise.
  CATBoolean GetNextSegment (int& oIdxPoint0, int& oIdxPoint1);

protected:

  CATHTableOfIntIntIterator* _Iterator;

};

#endif
