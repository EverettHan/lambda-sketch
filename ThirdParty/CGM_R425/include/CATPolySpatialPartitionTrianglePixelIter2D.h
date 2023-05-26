// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySpatialPartitionTrianglePixelIter2D.h
//
//===================================================================
// 2012-04-04 XXC: Creation
//===================================================================
#ifndef CATPolySpatialPartitionTrianglePixelIter2D_H
#define CATPolySpatialPartitionTrianglePixelIter2D_H

#include "PolygonalPartitions.h"
#include "CATPolySpatialPartition2D.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATPolySpatialPartition2D;
class CATMathPoint2D;


/**
 * Iterates through the pixels of a spatial partition that intersect a triangle defined by three points.
 *
 * It rasterizes the triangle in the plane. 
 * It applies two algorithms to trace the triangle edges : 
 *   * Bresenham discrete segments; or,
 *   * Reveilles discrete segments (segments with a given width). 
 *
 * The width of the segments is given in the constructor. With a width set to 0 (or negative) the standard Bresenham algorithm is applied.
 */
class ExportedByPolygonalPartitions CATPolySpatialPartitionTrianglePixelIter2D
{

public:

  /** Constructor.
   * The iterator is constructed from the partition, three triangle points and the
   * width of the triangle edges. If the width is lower or equal to 0,
   * a classical bresenham discret line algorithm is used. If not, a
   * Reveilles discrete line algorithm is used.
   */
  CATPolySpatialPartitionTrianglePixelIter2D (const CATPolySpatialPartition2D& iPartition, const CATMathPoint2D Triangle[3], const double iEdgeWidth = 0.0);

  ~CATPolySpatialPartitionTrianglePixelIter2D ();

public:

  inline CATPolySpatialPartitionTrianglePixelIter2D& Begin ();
  inline CATBoolean End () const;

public:

  inline CATPolySpatialPartitionTrianglePixelIter2D& operator++ ();

public:

  inline void Get (int& i, int& j) const;
  inline void Get (unsigned int& pixel) const;

private:

  void PseudoBresenham(char * grid2D, const unsigned int dimGrid, const char mask,
                       const double a[2], const int Va[2], const double b[2], const int Vb[2], const double iEdgeWidth);
  void AddPixel(unsigned int i, unsigned int j);
  void AddSize(int more);
    
private:
  const CATPolySpatialPartition2D& _Partition;

  unsigned int _NbPixels;
  unsigned int _BufferSize;
  unsigned int _CurrentPixel;
  unsigned int * _Buffer;

private:

  // No implementation of copy constructor and operator =.
  CATPolySpatialPartitionTrianglePixelIter2D (const CATPolySpatialPartitionTrianglePixelIter2D& iOther) ;
  CATPolySpatialPartitionTrianglePixelIter2D& operator = (const CATPolySpatialPartitionTrianglePixelIter2D& iOther) ;

};

CATPolySpatialPartitionTrianglePixelIter2D& CATPolySpatialPartitionTrianglePixelIter2D::Begin ()
{
  _CurrentPixel = 0;
  return *this;
}

inline CATBoolean CATPolySpatialPartitionTrianglePixelIter2D::End () const
{
  return _CurrentPixel >= _NbPixels;
}

CATPolySpatialPartitionTrianglePixelIter2D& CATPolySpatialPartitionTrianglePixelIter2D::operator++ ()
{
  _CurrentPixel++;
  return *this;
}

inline void CATPolySpatialPartitionTrianglePixelIter2D::Get (int& i, int& j) const
{
  unsigned int pixel = (_Buffer[_CurrentPixel]);
  _Partition.GetPixel(pixel, i, j);
}

inline void CATPolySpatialPartitionTrianglePixelIter2D::Get (unsigned int& pixel) const
{
  pixel = (_Buffer[_CurrentPixel]);
}

/*
inline int CATPolySpatialPartitionTrianglePixelIter2D::operator* () const
{
  int pixel;
  Get (pixel);
  return pixel;
}

inline int CATPolySpatialPartitionTrianglePixelIter2D::operator-> () const
{
  int pixel;
  Get (pixel);
  return pixel;
}
*/

#endif
