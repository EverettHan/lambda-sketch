#ifndef CATICDSGeometry_H
#define CATICDSGeometry_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEntity.h"
class CATICDSSketch;

/**
 * A basic class representing geometry as a rigid body in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSGeometry : public CATICDSEntity
{
public:

  /**
   * Returns the status of a geometric object.
   * The status is defined by the constraints imposed on the objects.
   * This function can only be called after Run.
   * @return
   *   The status of the object.
   * @see #GetUnderdefinedStatus
   */
  virtual CATCDSGStatus GetStatus() const = 0;

  /**
   * Returns the extended status for an underdefined geometric object.
   * This function gives more detailed information on degrees of freedom
   * of the geometric object or rigid set than <tt>GetStatus<//tt>.
   * @return
   *   The underdefined status as a bitwise combination of the CATCDSGUStatus members.
   * @see #GetStatus
   *
   * @SKIP
   */
  virtual CATCDSGUStatus GetUnderdefinedStatus() const = 0;
  
  /**
   * Sets the value of a circle or ellipse radii for dynamic move.
   * To make the dynamic move, one should call <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iMajorRadius
   *   The value for a circle radius or ellipse major radius
   * @param iMinorRadius
   *   The value for an ellipse minor radius
   * @see #Run, #Reset, #SetDynamicMoveMode
   *
   * @RENAME MoveRadii
   */
  virtual int SetDynamicMove(double iMajorRadius, double iMinorRadius) = 0;

  /**
   * Checks if a geometry has non-identity current transformation.
   * For dependent curve, checks if any of its definition objects has transformation.
   * Does not take into account dependency on parameter or another dependent curve.
   * @param ipGeometry
   *   A pointer to the geometry or rigid set callback
   * @return
   *   <tt>TRUE</tt> for non-identity transformation,
   *   <tt>FALSE</tt> otherwise
   */
  virtual CATCDSBoolean HasTransformation() const = 0;

  /**
   * Fixes/unfixes a geometric object on the sketch of the 2D geometry.
   * For 3D geometric objects this function does nothing.
   * This function is used as a toggle (it changes the previous state).
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   New fixation state: TRUE if fixed, FALSE if unfixed.
   */
  virtual CATCDSBoolean FixToggle2D() = 0;

  /**
   * Returns fixation status of a geometric object on its sketch.
   * Always FALSE for 3D objects.
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   The fixation state: TRUE if fixed, FALSE if unfixed.
   */
  virtual CATCDSBoolean IsFixed2D() const = 0;

  /**
   * Fixes/unfixes a geometric object in 3D space
   * (geometric object is 3D or 2D).
   * This function is used as a toggle (it changes the previous state).
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   New fixation state: TRUE if fixed, FALSE if unfixed.
   */
  virtual CATCDSBoolean FixToggle() = 0;

  /**
   * Returns fixation status of a geometric object in 3D space.
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   The fixation state: TRUE if fixed, FALSE if unfixed.
   */
  virtual CATCDSBoolean IsFixed() const = 0;
  
  /**
   * Sets a transformation for dynamic move.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iaaRotation
   *   A rotation matrix
   * @param iaTranslation
   *   A translation vector
   * @return
   *   <tt>FALSE</tt> is the object is fixed,
   *   <tt>TRUE</tt> otherwise
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  virtual int SetDynamicMove(double iaaRotation[3][3], double iaTranslation[3]) = 0;

  /**
   * Set translation only to re-evaluate.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   geometry to be moved
   * @param iaTranslation
   *   translation vector
   * @return
   *   <tt>FALSE</tt> is the object is fixed,
   *   <tt>TRUE</tt> otherwise
   * @see #Run, #Reset, #SetDynamicMoveMode
   * 
   * @SKIP
   */
  virtual int SetDynamicMove(double iaTranslation[3]) = 0;
  
  /**
   * Retrieves the information on the instantaneous degrees of freedom (DOFs)
   * of an object or a rigid set under constraints imposed on it.
   * An instantaneous DOF defines an infinitesimal transformation that
   * can be applied to the object (rigid set) without violation of any
   * constraint imposed on it.
   * An instantaneous DOF can be either a translation along some direction,
   * either a rotation around some axis, or a screw (a combination of a
   * rotation around some axis with a translation along it with a given
   * pitch value - a ratio between rotation and translation).
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and axis,
   * All the arrays must be allocated by the user.
   * The function assumes that any object/rigid set always has 6 DOFs.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param onTranslations
   *   The number of translational DOFs
   * @param onRotations
   *   The number of rotational DOFs
   * @param onScrews
   *   The number of screw DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOFs:
   *   for a translational DOF its data is a direction (a unit vector),
   *   for a rotational DOF it is an axis (point and direction),
   *   for a screw DOF it is an axis (point and direction) and a pitch value.
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error.
   * @see #GetDegreesOfFreedom2D
   */
  virtual int GetDegreesOfFreedom(unsigned int &onTranslations,
                                  unsigned int &onRotations,
                                  unsigned int &onScrews,
                                  CATCDSDOFStatus oaStatuses[6],
                                  double oaData[6][7]) const = 0;

  /**
   * Retrieves the information on the relative degrees of freedom (DOFs)
   * of an object or a rigid set under constraints which connects it with
   * the parent object or rigid set.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and axis,
   * All the arrays must be allocated by the user.
   * The function assumes that any object/rigid set always has 6 DOFs.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param ipParentGeom
   *   A pointer to the parent geometry
   * @param onTranslations
   *   The number of translational DOFs
   * @param onRotations
   *   The number of rotational DOFs
   * @param onScrews
   *   The number of screw DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOFs:
   *   for a translational DOF its data is a direction (a unit vector),
   *   for a rotational DOF it is an axis (point and direction),
   *   for a screw DOF it is an axis (point and direction) and a pitch value.
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error.
   */
  virtual int GetRelativeDegreesOfFreedom(CATICDSGeometry* ipParentGeom,
                                          unsigned int &onTranslations,
                                          unsigned int &onRotations,
                                          unsigned int &onScrews,
                                          CATCDSDOFStatus oaStatuses[6],
                                          double oaData[6][7]) const = 0;

  /**
   * Retrieves the current transformation on a geometry.
   * @param ipGeometry
   *   A pointer to the geometry or rigid set callback
   * @param oaaMatrix
   *   A rotation matrix
   * @param oaVector
   *   A translation vector
   * @return
   *   <tt>TRUE</tt> for non-identity transformation,
   *   <tt>FALSE</tt> otherwise
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetTransformation(double oaaMatrix[3][3], double oaVector[3]) const = 0;

  /**
   * Sets a 2D rotation for dynamic move.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iaaRotation
   *   A rotation matrix
   * @param iaTranslation
   *   A translation vector
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  virtual int SetDynamicMove2D(double iaaRotation[2][2], double iaTranslation[2]) = 0;

  /**
   * Sets a 2D translation for dynamic move.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iaTranslation
   *   A translation vector
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  virtual int SetDynamicMove2D(double iaTranslation[2]) = 0;

  /**
   * Retrieves the information on the instantaneous 2D degrees of freedom (DOFs)
   * of an object or a rigid set under constraints imposed on it in 2D space.
   * An instantaneous 2D DOF defines an infinitesimal 2D transformation that
   * can be applied to the object (rigid set) without violation of any
   * constraint imposed on it.
   * An instantaneous 2D DOF can be either a translation along some direction,
   * either a rotation around some point.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and points.
   * All the arrays must be allocated by the user.
   * The function assumes that any object (rigid set) always has 3 degrees
   * of freedom in 2D space.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param onTranslations
   *   The number of translational DOFs
   * @param onRotations
   *   The number of rotational DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOF:
   *   for translational DOF this data is a direction,
   *   for rotational DOF it is a point of rotation
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error.
   * @see #GetDegreesOfFreedom
   */
  virtual int GetDegreesOfFreedom2D(unsigned int &onTranslations,
                                    unsigned int &onRotations,
                                    CATCDSDOFStatus oaStatuses[3],
                                    double oaData[3][2]) const = 0;

  /**
   * Retrieves the information on the instantaneous 2D degrees of freedom (DOFs)
   * of an object or a rigid set under constraints which connects it with
   * the parent object or rigid set in 2D space.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and points.
   * All the arrays must be allocated by the user.
   * The function assumes that any object (rigid set) always has 3 degrees
   * of freedom in 2D space.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param ipParentGeom
   *   A pointer to the parent geometry
   * @param onTranslations
   *   The number of translational DOFs
   * @param onRotations
   *   The number of rotational DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOF:
   *   for translational DOF this data is a direction,
   *   for rotational DOF it is a point of rotation
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error.
   */
  virtual int GetRelativeDegreesOfFreedom2D(CATICDSGeometry* ipParentGeom,
                                            unsigned int &onTranslations,
                                            unsigned int &onRotations,
                                            CATCDSDOFStatus oaStatuses[3],
                                            double oaData[3][2]) const = 0;

  /**
   * Retrieves the current transformation on a geometry.
   * @param ipGeometry
   *   A pointer to the geometry or rigid set callback
   * @param oaaMatrix
   *   A transformation matrix (2x2 rotation and translation vector)
   * @return
   *   <tt>TRUE</tt> for non-identity matrix,
   *   <tt>FALSE</tt> otherwise
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetTransformation2D(double oaaMatrix[3][3]) const = 0;
  
  #if defined(_EMSCRIPTEN_SOURCE)
  virtual CATICDSSketch* GetSketch() const=0;
#endif
  virtual ~CATICDSGeometry() {}
};

#endif
