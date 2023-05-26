// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSSketch.h
// Header definition of CATCSSketch
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSSketch_H
#define CATCSSketch_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a sketch in three-dimensional space. The sketch is
 * a two-dimensional subspace which contains two-dimensional geometries.
 */
class ExportedBySolverInterface CATCSSketch : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSSketch();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define an origin.
   *   The next two triples define axes of coordinate system.
   */
  CATCSSketch(const double iaCoord[9]);

  virtual ~CATCSSketch();

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
   * Retrieves coordinate system of the sketch.
   * @param oaOrigin
   *   An origin of the sketch.
   * @param oaAxisOX
   *   An abscissa axis.
   * @param oaAxisOY
   *   An ordinate axis.
   */
  virtual void GetCoordinateSystem(double oaOrigin[3], double oaAxisOX[3], double oaAxisOY[3]) const;

  virtual void SetCoordinateSystem(const double iaOrigin[3], const double iaAxisOX[3], const double iaAxisOY[3]);
  
  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to nine for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[9]) CATCDSOverride;
  
  /**
   * Converts an 2D position to a 3D position
   */
  void Get3DPoint(const double iX, const double iY, double &oX, double &oY, double &oZ) const;

  /**
   * Converts an 2D direction to a 3D direction
   */
  void Get3DDirection(const double iDX, const double iDY, double &oDX, double &oDY, double &oDZ) const;

  /**
   * Converts an 3D position to a 2D position
   */
  void Get2DPoint(const double iX, const double iY, const double iZ, double &oX, double &oY) const;

  /**
   * Converts an 3D direction to a 2D direction
   */
  void Get2DDirection(const double iDX, const double iDY, const double iDZ, double &oDX, double &oDY) const;
  
  void GetNormal(double oaCoords[3]) const;


private:
  double _aCoord[9];
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSSketch, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
