// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySpatialPartition2D.h
//
//===================================================================
// February 2008 Creation: ndo
//===================================================================
#ifndef CATPolySpatialPartition2D_H
#define CATPolySpatialPartition2D_H

#include "PolygonalPartitions.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATMathPoint2D;
class CATMathBox2D;


/**
* A CATPolySpatialPartition2D is a spatial partition defined as a uniform pixel grid. 
* Each pixel is a square with a given side dimension.  The grid contains as many pixels as required to 
* cover a given bounding box.  The number of pixels is not necessarily the same in each 
* direction (when the domain is not a square).
*
*Given a pixel of the two-dimensional grid:
\verbatim

  1-----------------3
  |                 |
  |                 |
  |                 |
  |                 |
  |                 |                  Y
  |                 |                  /\
  |                 |                  |
  |                 |                  |
  |                 |                  |
  0-----------------2                  *-------> X

\endverbatim
*
* A point on the lines (01( or (02( is said to be in the pixel.  A point on the lines (13) (23) is said 
* to be out of the pixel.  (Pixel is half-open on the top and right sides.)
* (Minimum requirement for inclusion of a point in a pixel.)
* The pixel indices range from 0 to GetNbPixels () excluded.
*
* Several iterators return the pixels that are traversed by varions geometrical elements including bars and triangles.
* @see CATPolySpatialPartitionBarPixelIter2D
* @see CATPolySpatialPartitionTrianglePixelIter2D
* 
* @see CATPolyVoxelPartition for the 3D equivalent of a voxel partition in space.
*/
class ExportedByPolygonalPartitions CATPolySpatialPartition2D
{

public:

  /**
   * Defines a spatial partition given a bounding box and a number of pixels not to exceed 
   * along the directions X and Y.  The last optional argument, iDelta, is a positive value,
   * which is used to define the pixel size as an integer multiple of this value.
   */
  CATPolySpatialPartition2D (const CATMathBox2D& iBox, const unsigned int iNbPixelsNotToExceedXorY,
                             const double iDelta = 0);

  /** 
   * Defines a spatial partition given a bounding box and a pixel size.
   * The partition covers the input bounding box. 
   * It can be inflated up to half the pixel size.
   */
  CATPolySpatialPartition2D (const CATMathBox2D& iBox, const double iPixelSize);

  ~CATPolySpatialPartition2D ();

public:

  //
  // QUERIES
  //

  /**
   * Returns the total number of pixels.
   */
  inline unsigned int GetNbPixels () const;

  /**
   * Returns the number of pixels along a side (0 or 1.)
   */
  inline unsigned int GetNbPixels (const unsigned int iSide0or1) const;

  /**
   * Returns the pixel size.
   */
  inline double GetPixelSize () const;

  /**
   * Returns the bounding box.
   */
  void GetBoundingBox (CATMathBox2D& oBox) const;

public:

  /**
   * Returns the integer coordinates of the pixel where a point lies.
   */
  int GetPixelIndex0 (const CATMathPoint2D& P) const;
  int GetPixelIndex1 (const CATMathPoint2D& P) const;
  int GetPixelIndex0 (const double& x) const;
  int GetPixelIndex1 (const double& y) const;

  inline void GetPixel (const CATMathPoint2D& P, int & oIdx0, int & oIdx1) const;

  /**
   * Returns the double coordinates of the pixel where a point lies.
   */
  double GetPixelCoord0 (const CATMathPoint2D& P) const;
  double GetPixelCoord1 (const CATMathPoint2D& P) const;

  /**
   * Returns the pixel where the point lies.
   * A valid pixel is a number from 0 to GetNbPixels () - 1.
   * The method returns a number outside that range if the point is outside the partition.
   */
  unsigned int GetPixel (const CATMathPoint2D& P) const;

  /**
   * Returns the pixel number given its integer coordinates.
   */
  inline unsigned int GetPixel (const int i, const int j) const;
  inline void GetPixel (const unsigned int index, int& i, int& j) const;

public:

  /**
   * Returns the pixel number given its integer coordinates.
   */
  inline unsigned int GetPixelBelow (unsigned int pixel) const;

public:

  /**
   * Sets the initial bounding box for the spatial partition. 
   */

  /**
   * Returns the lower limit of the pixel (Dimension 0).
   */
  inline double GetPixelLowerLimit0 (const int i) const;

  /**
   * Returns the lower limit of the pixel (Dimension 1).
   */
  inline double GetPixelLowerLimit1 (const int j) const;

  /**
   * Returns the lower limit of the pixel for one of the two dimensions.
   */
  inline double GetPixelLowerLimit (const int iDimension, const int i) const;

  /**
   * Returns the center of the pixel (dimension 0 and 1 respectively)
   */
  inline double GetPixelCenter0 (const int i) const;
  inline double GetPixelCenter1 (const int j) const;

  /**
   * Returns the center of the pixel for one of the two dimensions.
   */
  inline double GetPixelCenter (const int iDimension, const int i) const;

private:

  // Geometry of the spatial partition.

  // Min and max corners of the space that is partitionned.  
  // These corners define a rectangular region in space.
  double _Box[2][2];  // [X, Y][Min or Max]

  // Pixel size. 
  double _PixelSize;
  double _OneOverPixelSize;

  // Number of pixels for each dimension.
  unsigned int _NbPixels[2];
};


inline unsigned int CATPolySpatialPartition2D::GetNbPixels () const
{
  return _NbPixels[0] * _NbPixels[1];
}

inline unsigned int CATPolySpatialPartition2D::GetNbPixels (const unsigned int iSide) const
{
  return _NbPixels[iSide];
}

inline double CATPolySpatialPartition2D::GetPixelSize () const
{
  return _PixelSize;
}

inline unsigned int CATPolySpatialPartition2D::GetPixel (const int i, const int j) const
{
  return i + j * _NbPixels[0];
}

inline void CATPolySpatialPartition2D::GetPixel (const unsigned int index, int & i, int & j) const
{
  j = (int) (index / _NbPixels[0]);
  i = (int) (index % _NbPixels[0]);
}

inline void CATPolySpatialPartition2D::GetPixel (const CATMathPoint2D& P, int & oIdx0, int & oIdx1) const
{
  oIdx0 = GetPixelIndex0 (P);
  oIdx1 = GetPixelIndex1 (P);
}

inline double CATPolySpatialPartition2D::GetPixelLowerLimit0 (const int i) const
{
  return _Box[0][0] + i * _PixelSize;
}

inline double CATPolySpatialPartition2D::GetPixelLowerLimit1 (const int j) const
{
  return _Box[1][0] + j * _PixelSize;
}

inline double CATPolySpatialPartition2D::GetPixelLowerLimit (const int iDimension, const int i) const
{
  if (iDimension == 0)
    return _Box[0][0] + i * _PixelSize;
  else
    return _Box[1][0] + i * _PixelSize;
}

inline double CATPolySpatialPartition2D::GetPixelCenter0 (const int i) const
{
  return _Box[0][0] + (((double) i) + 0.5) * _PixelSize;
}

inline double CATPolySpatialPartition2D::GetPixelCenter1 (const int j) const
{
  return _Box[1][0] + (((double) j) + 0.5) * _PixelSize;
}

inline double CATPolySpatialPartition2D::GetPixelCenter (const int iDimension, const int i) const
{
  return (iDimension ? GetPixelCenter1(i) : GetPixelCenter0(i));
}

inline unsigned int CATPolySpatialPartition2D::GetPixelBelow (unsigned int pixel) const
{
  return pixel - _NbPixels[0];
}

#endif
