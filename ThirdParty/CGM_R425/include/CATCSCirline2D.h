// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCSCirline2D.h
// Header definition of CATCSCirline2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2011  Creation:                  Roman Plotnikov
//===================================================================
#ifndef CATCSCirline2D_H
#define CATCSCirline2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSCirline.h"

class CATCSSketch;

//-----------------------------------------------------------------------

/**
* A geometry representing a Cirline in two-dimensional space.
*/
class ExportedBySolverInterface CATCSCirline2D : public CATCSCirline
{
public:
  /**
  * Constructs an instance of the geometry.
  */
  CATCSCirline2D();

  /**
  * Constructs an instance of the geometry.
  * @param ipSketch
  *   A sketch of the geometry.
  * @param iaCoord
  *   An array of coordinates. The first two coordinates define a center. The
  *   second two ones define a direction of major axis.
  * @param iVertexCurvature
  *   A curvature at the cirline vertex.
  */
  CATCSCirline2D(CATCSSketch *ipSketch, const double iaCoord[4], double iVertexCurvature);

  virtual ~CATCSCirline2D();

  /**
  * Retrieves type of the geometry.
  * @return
  *   Type of the geometry.
  * @see #IsMatched
  */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
  * Checks whether the geometry is matched to a specific type. The geometry
  * can be casted to a corresponding class if the matching is successful.
  * @param iType
  *   A specific type.
  * @return
  *   <ul>
  *     <li><tt>TRUE</tt> - if the matching is successful,
  *     <li><tt>FALSE</tt> - otherwise.
  *   </ul>
  */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
  * Applies an affine transformation to the geometry.
  * @param iMatrix
  *   A matrix containing a rotation in two-dimensional space as 2x2
  *   submatrix and a translation at the last column. The last row of the
  *   matrix is dummy.
  */
  virtual void ApplyTransformation2D(double iMatrix[3][3]);

  /**
  * Applies an affine transformation to the geometry.
  * @param iMatrix
  *   A matrix representing a rotation in three-dimensional space.
  * @param iTranslation
  *   A vector representing a translation in three-dimensional space.
  */
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  /**
  * Retrieves coordinates of the cirline center.
  * @param oX
  *   An abscissa axis.
  * @param oY
  *   An ordinate axis.
  */
  virtual void GetCenter2D(double &oX, double &oY);

  /**
   * Retrieves coordinates of the circle center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void SetCenter2D(double iX, double iY);

  /**
  * Retrieves coordinates of the cirline center.
  * @param oX
  *   An abscissa axis.
  * @param oY
  *   An ordinate axis.
  * @param oZ
  *   An applicate axis.
  */
  virtual void GetCenter(double &oX, double &oY, double &oZ) CATCDSOverride;

  /**
  * Retrieves coordinates of the cirline major direction.
  * @param oX
  *   An abscissa axis.
  * @param oY
  *   An ordinate axis.
  */
  virtual void GetDirection2D(double &oX, double &oY);

  /**
   * Specify coordinates of the cirline major direction (perpendicular to the symmetry axis).
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   */
  virtual void SetDirection2D(double iX, double iY);

  /**
  * Retrieves coordinates of the cirline major direction and the cirline
  * normal.
  * @param oX1
  *   An abscissa axis of major direction.
  * @param oY1
  *   An ordinate axis of major direction.
  * @param oZ1
  *   An applicate axis of major direction.
  * @param oX2
  *   An abscissa axis of normal.
  * @param oY2
  *   An ordinate axis of normal.
  * @param oZ2
  *   An applicate axis of normal.
  */
  virtual void GetDirections(double &oX1, double &oY1, double &oZ1, double &oX2, double &oY2, double &oZ2) CATCDSOverride;

  /**
  * Updates coordinates of the geometry. Length of the array depends on the
  * geometry type. It is equal to four for this geometry.
  * @param iaCoord
  *   An array of coordinates.
  */
  virtual void UpdateCoordinates(const double iaCoord[4]) CATCDSOverride;

private:
  double _aCoord[4];
};

//-----------------------------------------------------------------------

#endif
