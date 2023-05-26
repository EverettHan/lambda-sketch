// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATCSSphere.h
// Header definition of CATCSSphere
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2007  Creation:                     Ilia IVANOV
//===================================================================
#ifndef CATCSSphere_H
#define CATCSSphere_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a sphere in three-dimensional space.
 */
class ExportedBySolverInterface CATCSSphere : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSSphere();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates.
   * @param iRadius
   *   A radius of the sphere.
   */
  CATCSSphere(const double iaCoord[3], double iRadius);

  /**
   * Constructs an instance of the geometry.
   * @param iX
   *   x coordinate of sphere center.
   * @param iY
   *   y coordinate of sphere center.
   * @param iZ
   *   z coordinate of sphere center.
   * @param iRadius
   *   A radius of the sphere.
   */
  CATCSSphere(double iX, double iY, double iZ, double iRadius);

  virtual ~CATCSSphere();

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
   *   A matrix representing a rotation in three-dimensional space.
   * @param iTranslation
   *   A vector representing a translation in three-dimensional space.
   */
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  /**
   * Retrieves coordinates of the sphere center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ);

  virtual void SetCenter(double iX, double iY, double iZ);
  
  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to three for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[3]) CATCDSOverride;

  /**
   * Sets radius of the sphere.
   * @param iRadius
   *   A radius of the sphere.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius);

  /**
   * Retrieves radius of the sphere.
   * @return
   *   A radius of the sphere.
   * @see #SetRadius
   */
  virtual double GetRadius();

private:
  double _aCoord[3];
  double _Radius;
};

//-----------------------------------------------------------------------

#endif
