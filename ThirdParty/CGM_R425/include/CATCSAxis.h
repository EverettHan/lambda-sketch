// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSAxis.h
// Header definition of CATCSAxis
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation:                       Ilia IVANOV
//===================================================================
#ifndef CATCSAxis_H
#define CATCSAxis_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

class CATCDS3Frame;

//-----------------------------------------------------------------------

/**
 * A geometry representing an axis in three-dimensional space.
 */
class ExportedBySolverInterface CATCSAxis : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSAxis();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define an origin.
   *   The next three triples define directions of vectors.
   */
  CATCSAxis(const double iaCoord[12]);

  /**
   * Constructs an instance of the geometry.
   */
  CATCSAxis(double iX, double iY, double iZ,
            double iIX, double iIY, double iIZ,
            double iJX, double iJY, double iJZ,
            double iKX, double iKY, double iKZ);

  /**
   * Constructs an instance of the geometry.
   * @param iFrame
   *   CDS frame object (containing one origin and three vectors)
   */
  CATCSAxis(CATCDS3Frame& iFrame);

  virtual ~CATCSAxis();

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
   * Retrieves coordinates of the axis origin.
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
   * Retrieves coordinates of the axis vectors.
   * @param oX1
   *   An abscissa of the first vector.
   * @param oY1
   *   An ordinate of the first vector.
   * @param oZ1
   *   An applicate of the first vector.
   * @param oX2
   *   An abscissa of the second vector.
   * @param oY2
   *   An ordinate of the second vector.
   * @param oZ2
   *   An applicate of the second vector.
   * @param oX3
   *   An abscissa of the third vector.
   * @param oY3
   *   An ordinate of the third vector.
   * @param oZ3
   *   An applicate of the third vector.
   */
  virtual void GetVectors(double &oX1, double &oY1, double &oZ1, double &oX2, double &oY2, double &oZ2, double &oX3, double &oY3, double &oZ3);

  virtual void SetVectors(double iX1, double iY1, double iZ1, double iX2, double iY2, double iZ2, double iX3, double iY3, double iZ3);
  
  /**
   * Set the coordinates of this axis from a frame object.
   * @param iFrame
   *   Input frame object.
   */
  virtual void SetFrame(CATCDS3Frame& iFrame);

  /**
   * Retrieves coordinates of this axis as a frame object.
   * @return
   *   A frame object.
   */
  virtual CATCDS3Frame GetFrame() const;

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to twelve for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[12]) CATCDSOverride;

private:
  double _aCoord[12];
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSAxis, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
