// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySPOctreeLeaf.h
// Header definition of CATPolySPOctreeLeaf
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2006 Creation: ndo
//===================================================================
#ifndef CATPolySPOctreeLeaf_H
#define CATPolySPOctreeLeaf_H

#include "CATPolySpatialPartitions.h"

#include "CATPolySPOctreeDefine.h"

class CATCGMOutput;


class ExportedByCATPolySpatialPartitions CATPolySPOctreeLeaf
{

public :

  CATPolySPOctreeLeaf ();

  ~CATPolySPOctreeLeaf ();

#ifdef DEBUG_SPOCTREE
  // For debugging purposes only.
  inline void SetTag (const int iTag);
  inline unsigned int GetTag () const;
#endif

  inline void SetTriangles (int* iTriangles);
  inline int* GetTriangles () const;

  inline void SetNbTriangles (const int iNbTriangles);
  inline int GetNbTriangles () const;

  // Given a triangle, returns the index where the triangle should be inserted.
  // If the triangle is already in the leaf, then returns the index of the triangle.
  int GetInsertionIndex (const int iTriangle) const;

  inline void Clear ();

  // For debugging purposes.
  void Print (CATCGMOutput& stream, const int iDepth = 0, int* positions = 0) const;

  static void Print (CATCGMOutput& stream, const CATPolySPOctreeLeaf* iLeaf, const int iDepth = 0, int* positions = 0);
  static void Print (CATCGMOutput& stream, const int* iTriangles, const int iNbTriangles);

private :

  // No implementation of copy constructor and operator =.
  CATPolySPOctreeLeaf (CATPolySPOctreeLeaf& iOther) ;
  CATPolySPOctreeLeaf& operator = (CATPolySPOctreeLeaf& iOther) ;

#ifdef DEBUG_SPOCTREE
  unsigned int _Tag; 
#endif

  // Triangle indices.  The triangles are stored in sorted order (increasing indices) in the following list.

  int* _Triangles;
  int _NbTriangles;

};


#ifdef DEBUG_SPOCTREE
inline void CATPolySPOctreeLeaf::SetTag (const int iTag)
{
  _Tag = iTag;
}

inline unsigned int CATPolySPOctreeLeaf::GetTag () const 
{
  return _Tag; 
}
#endif


inline void CATPolySPOctreeLeaf::SetTriangles (int* iTriangles)
{
  _Triangles = iTriangles;
}


inline int* CATPolySPOctreeLeaf::GetTriangles () const
{
  return _Triangles;
}


inline void CATPolySPOctreeLeaf::SetNbTriangles (const int iNbTriangles)
{
  _NbTriangles = iNbTriangles;
}


inline int CATPolySPOctreeLeaf::GetNbTriangles () const
{
  return _NbTriangles;
}


inline void CATPolySPOctreeLeaf::Clear ()
{
  _Triangles = 0;
  _NbTriangles = 0;
}


#endif

