#ifndef CATICDSCSSketch_H
#define CATICDSCSSketch_H

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a sketch in three-dimensional space. The sketch is
 * a two-dimensional subspace which contains two-dimensional geometries.
 */
class ExportedBySolverInterface CATICDSSketch : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinate system of the sketch.
   * @param oaOrigin
   *   Origin of the sketch.
   * @param oaAxisOX
   *   Normalized abscissa axis of the sketch.
   * @param oaAxisOY
   *   Normalized ordinate axis of the sketch.
   */
  virtual void GetCoordinateSystem(double oaOrigin[3], double oaAxisOX[3], double oaAxisOY[3]) const = 0;

  /**
   * Specify coordinate system of the sketch.
   * @param iaOrigin
   *   Origin of the sketch.
   * @param iaAxisOX
   *   Normalized abscissa axis of the sketch.
   * @param iaAxisOY
   *   Normalized ordinate axis of the sketch.
   */
  virtual void SetCoordinateSystem(const double iaOrigin[3], const double iaAxisOX[3], const double iaAxisOY[3]) = 0;

  /**
   * Retreive sketch's normal.
   * @param oaCoords
   *   Normalized sketch normal.
   */
  virtual void GetNormal(double oaCoords[3]) const = 0;

  /**
   * Evaluate the 3D position of a 2D point in the sketch's coordinates.
   * @param ia2DCoords
   *   2D coordinates of the point in sketch's referential.
   * @param oa3DCoords
   *   Output 3D coordinates of the point.
   */
  virtual void EvaluatePoint(const double iaCoords2D[2], double oa3DCoords[3]) const = 0;

  /**
   * Evaluate the 3D direction of a 2D direction in the sketch's basis.
   * @param ia2DDirection
   *   2D coordinates of the direction in sketch's referential.
   * @param oa3DDirection
   *   Output 3D coordinates of the direction.
   */
  virtual void EvaluateDirection(const double iaDirection2D[2], double oa3DDirection[3]) const = 0;

  /**
   * Evaluate the 3D position of a 2D point in the sketch's coordinates.
   * @param iX
   * @param iY
   *   2D coordinates of the point in sketch's referential.
   * @param oX
   * @param oY
   * @param oZ
   *   Output 3D coordinates of the point.
   *
   * @SKIP
   */
  virtual void EvaluatePoint(double iX, double iY, double &oX, double &oY, double &oZ) const = 0;

  /**
   * Evaluate the 3D direction of a 2D direction in the sketch's basis.
   * @param iDX
   * @param iDY
   *   2D coordinates of the direction in sketch's referential.
   * @param oDX
   * @param oDY
   * @param oDZ
   *   Output 3D coordinates of the direction.
   *
   * @SKIP
   */
  virtual void EvaluateDirection(double iDX, double iDY, double &oDX, double &oDY, double &oDZ) const = 0;

  /**
   * Convert the 3D position to a 2D point in the sketch's coordinates.
   * If the point is not in the sketch, the method will return the orthogonal projection with respect to the sketch.
   * @param ia3DCoords
   *   3D coordinates of the point.
   * @param oa2DCoords
   *   Output 2D coordinates of the point in sketch's referential.
   */
  virtual void Get2DPoint(const double iaCoords3D[3], double oa2DCoords[2]) const = 0;

  /**
   * Convert the 3D direction to a 2D direction in the sketch's basis.
   * If the direction is not in the sketch, the method will return the orthogonal projection with respect to the sketch.
   * @param ia3DDirection
   *   3D coordinates of the direction.
   * @param oa2DDirection
   *   Output 2D coordinates of the direction in sketch's referential..
   */
  virtual void Get2DDirection(const double iaDirection3D[3], double oaDirection2D[2]) const = 0;

  /**
   * Convert the 3D position to a 2D point in the sketch's coordinates.
   * If the point is not in the sketch, the method will return the orthogonal projection with respect to the sketch.
   * @param iX
   * @param iY
   * @param iZ
   *   3D coordinates of the point.
   * @param oX
   * @param oY
   *   Output 2D coordinates of the point in sketch's referential.
   *
   * @SKIP
   */
  virtual void Get2DPoint(double iX, double iY, double iZ, double &oX, double &oY) const = 0;

  /**
   * Convert the 3D direction to a 2D direction in the sketch's basis.
   * If the direction is not in the sketch, the method will return the orthogonal projection with respect to the sketch.
   * @param iDX
   * @param iDY
   * @param iDZ
   *   3D coordinates of the direction.
   * @param oDX
   * @param oDY
   *   Output 2D coordinates of the direction in sketch's referential.
   *
   * @SKIP
   */
  virtual void Get2DDirection(double iDX, double iDY, double iDZ, double &oDX, double &oDY) const = 0;

  /**
   * Creates an instance of the CATICDSSketch geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iaOrigin
   *   Normalized origin of the sketch.
   * @param iaAxisOX
   *   Normalized abscissa axis of the sketch.
   * @param iaAxisOY
   *   Normalized ordinate axis of the sketch.
   */
  static CATICDSSketch* Create(CATICDSFactory *ipFactory,
                               const double iaOrigin[3],
                               const double iaAxisOX[3],
                               const double iaAxisOY[3]);

  virtual ~CATICDSSketch() {}
};

#endif
