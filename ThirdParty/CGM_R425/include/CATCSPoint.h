// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSPoint.h
// Header definition of CATCSPoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSPoint_H
#define CATCSPoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a point in three-dimensional space.
 */
class ExportedBySolverInterface CATCSPoint : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSPoint();

  /**
   * Constructs an instance of the geometry.
   */
  CATCSPoint(double iX, double iY, double iZ);

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates.
   *   
   * @RENAME CATCSPointFromCoord   
   */
  CATCSPoint(const double iaCoord[3]);

  virtual ~CATCSPoint();

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
   * Retrieves coordinates of the geometry.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCoord(double &oX, double &oY, double &oZ);

  virtual void SetCoord(double iX, double iY, double iZ);

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to three for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[3]) CATCDSOverride;

   /**
  * Get a bounding box for the geometry (AABB type)
  * @param oBox
  *   the bounding box
  */
  virtual void GetBoundingBox(CATCDSBox *& oBox) CATCDSOverride;



private:
  double _aCoord[3];
};

//-----------------------------------------------------------------------

#endif
