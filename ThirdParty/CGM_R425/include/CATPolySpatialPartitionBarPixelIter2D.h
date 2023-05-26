// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySpatialPartitionBarPixelIter2D.h
//
//===================================================================
// February 2008 Creation: ndo
//===================================================================
#ifndef CATPolySpatialPartitionBarPixelIter2D_H
#define CATPolySpatialPartitionBarPixelIter2D_H

#include "PolygonalPartitions.h"
#include "CATPolySpatialPartition2D.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATPolySpatialPartition2D;
class CATMathPoint2D;


/*
Iterates through the pixels of a spatial partition that intersect a segment defined by two points.
*/
class ExportedByPolygonalPartitions CATPolySpatialPartitionBarPixelIter2D
{

public:

  CATPolySpatialPartitionBarPixelIter2D (const CATPolySpatialPartition2D& iPartition);

  ~CATPolySpatialPartitionBarPixelIter2D () {}

public:

  CATPolySpatialPartitionBarPixelIter2D& Begin (const CATMathPoint2D& P0, const CATMathPoint2D& P1);
  inline CATBoolean End () const;

public:

  CATPolySpatialPartitionBarPixelIter2D& operator++ ();

public:

  inline void Get (int& i, int& j) const;
  inline void Get (unsigned int& pixel) const;

  //inline int operator* () const;
  //inline int operator-> () const;

private:

  const CATPolySpatialPartition2D& _Partition;

  int _I;
  int _J;
  int _IEnd;
  int _JEnd;
  int _IStep;
  int _JStep;

  int _JStep0;      // For special case, Epsilon equals 0.

  double _DeltaX;
  double _DeltaY;
  double _Epsilon;

  double _Epsilon0; // For special case, Epsilon equals 0.

private:

  // No implementation of copy constructor and operator =.
  CATPolySpatialPartitionBarPixelIter2D (const CATPolySpatialPartitionBarPixelIter2D& iOther) ;
  CATPolySpatialPartitionBarPixelIter2D& operator = (const CATPolySpatialPartitionBarPixelIter2D& iOther) ;

};

inline CATBoolean CATPolySpatialPartitionBarPixelIter2D::End () const
{
  return _I < 0;
}

inline void CATPolySpatialPartitionBarPixelIter2D::Get (int& i, int& j) const
{
  i = _I;
  j = _J;
}

inline void CATPolySpatialPartitionBarPixelIter2D::Get (unsigned int& pixel) const
{
  pixel = (unsigned int) _I + _J * _Partition.GetNbPixels (0);
}

/*
inline int CATPolySpatialPartitionBarPixelIter2D::operator* () const
{
  int pixel;
  Get (pixel);
  return pixel;
}

inline int CATPolySpatialPartitionBarPixelIter2D::operator-> () const
{
  int pixel;
  Get (pixel);
  return pixel;
}
*/

#endif
