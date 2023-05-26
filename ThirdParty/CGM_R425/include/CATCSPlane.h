// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSPlane.h
// Header definition of CATCSPlane
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSPlane_H
#define CATCSPlane_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a plane in three-dimensional space.
 */
class ExportedBySolverInterface CATCSPlane : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSPlane();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define an origin.
   *   The second three ones define a normal.
   */
  CATCSPlane(const double iaCoord[6]);

  /**
   * Constructs an instance of the geometry.
   * @param iX
   *   x coordinate of plane origin.
   * @param iY
   *   y coordinate of plane origin.
   * @param iZ
   *   z coordinate of plane origin.
   * @param iNX
   *   x coordinate of plane normal.
   * @param iNY
   *   y coordinate of plane normal.
   * @param iNZ
   *   z coordinate of plane normal.
   */
  CATCSPlane(double iX, double iY, double iZ, double iNX, double iNY, double iNZ);

  virtual ~CATCSPlane();

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
   * Retrieves coordinates of the plane origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetOrigin(double &oX, double &oY, double &oZ);

  virtual void SetOrigin(double iX, double iY, double iZ);
  
  /**
   * Retrieves coordinates of the plane normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ);

  virtual void SetNormal(double iX, double iY, double iZ);
  
  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to six for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[6]) CATCDSOverride;

private:
  double _aCoord[6];
};

//-----------------------------------------------------------------------

#endif
