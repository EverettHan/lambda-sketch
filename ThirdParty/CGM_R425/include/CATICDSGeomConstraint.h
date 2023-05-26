#ifndef CATICDSGeomConstraint_H
#define CATICDSGeomConstraint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATCDSBoolean.h"
#include "CATICDSConstraint.h"

class CATICDSVariable;
class CATICDSGeometryLeaf;

/**
 * A basic class for all logical constraints.
 */
class ExportedByCDSInterface CATICDSGeomConstraint : public CATICDSConstraint
{
public:

  /**
   * Retrieves geometries connected with the constraint.
   * @param opGeom1
   *   The first geometry.
   * @param opGeom2
   *   The second geometry.
   * @param opGeom3
   *   The third geometry.
   *
   * @RETURNARRAY
   */
  virtual void GetGeometries(CATICDSGeometryLeaf *&opGeom1,  CATICDSGeometryLeaf *&opGeom2, CATICDSGeometryLeaf *&opGeom3) const = 0;

  /**
   * Retrieves alignment of the constraint.
   * @return
   *   An alignment of the constraint.
   * @see #SetAlignment
   */
  virtual CATCAlignment GetAlignment() const = 0;

  /**
   * Sets alignment of the constraint.
   * @param iAlignment
   *   An alignment of the constraint.
   * @see #GetAlignment
   */
  virtual void SetAlignment(CATCAlignment iAlignment) = 0;

  /**
   * Retrieves help parameter of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param oValue
   *   Value of the help parameter.
   * @return
   *   TRUE if the help parameter is specified.
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetHelpParameter(CATICDSGeometryLeaf *ipGeom, double& oValue) const = 0;

  /**
   * Updates help parameter of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param iParam
   *   A value of the help parameter.
   */
  virtual void SetHelpParameter(CATICDSGeometryLeaf *ipGeom, double iParam) = 0;

  /**
   * Retrieves help parameters of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param oFirstParameter
   *   A value of the first help parameter.
   * @param oSecondParameter
   *   A value of the second help parameter.
   * @return
   *   TRUE if the help parameters are specified.
   *
   * @CHECKRESULT TRUE
   * @RETURNARRAY
   */
  virtual CATCDSBoolean GetHelpParameters(CATICDSGeometryLeaf *ipGLeaf, double &oFirstParameter, double &oSecondParameter) const = 0;
  
  /**
   * Updates help parameters of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param iFirstParam
   *   A value of the first help parameter.
   * @param iSecondParam
   *   A value of the second help parameter.
   */
  virtual void SetHelpParameters(CATICDSGeometryLeaf *ipGLeaf, double iFirstParam, double iSecondParam) = 0;
  
  /**
   * Associates given variables with a given argument of a given constraint.
   * @param ipGLeaf
   *   A pointer to the geometric object that is the argument of constraint
   * @param ipVariable
   *   A pointer to variable callback to be associated
   */
  virtual void SetHelpParameterVariable(CATICDSGeometryLeaf* ipGLeaf, CATICDSVariable* ipVariable) = 0;

  /**
   * Retreive the variable associated with the given argument of the constraint
   * @param ipGLeaf
   *   A pointer to the geometric object that is the argument of constraint
   * @param opVariable
   *   A pointer to variable callback to be associated
   * @return
   *   TRUE if the help parameter variable is specified.
   *
   * @CHECKRESULT TRUE
   */
   virtual CATCDSBoolean GetHelpParameterVariable(CATICDSGeometryLeaf* ipGLeaf, CATICDSVariable*& opVariable) const = 0;

  /**
   * Change chirality of a particular constraint.
   * This function forces the solver to find the opposite relative positions
   * for arguments of the constraints. E.g. if the constraint is a distance
   * between a point and a line in 2D, it forces the point to jump over the
   * line; if it is a point-circle distance, it forces a point to jump inside
   * or outside the circle to change their initial relative position.
   */
  virtual void ChangeChirality() = 0;

  /*
  @return
  * TRUE if ChangeChirality() has been used.
  */
  virtual CATCDSBoolean GetChangeChirality() = 0;

  // @DEPRECATED
  virtual void FlushChirality() = 0;

  /**
   * Compute current chirality of a particular constraint.
   * If some values can't be calculated or have no sense
   * corresponding parameters get NOTSPECIFIED values.
   * @param oAlignment
   *   Geometries alignments.
   * @param oSurfaceOrientation
   *  Surface orientation.
   * @param oHalfSpaceGeom1
   *  Half space of first geometry.
   * @param oHalfSpaceGeom2
   *  Half space of second geometry. 
   */
  virtual void ComputeChirality(CATCAlignment& oAlignment, CATCDSSurfaceOrientation& oSurfaceOrientation, CATCDSHalfSpace& oHalfSpaceGeom1, CATCDSHalfSpace& oHalfSpaceGeom2) = 0;

  /**
   * Retrieves the help point 2D location.
   * @param ipGeometry
   *   A pointer to the circle callback
   * @param oaHelpPoint
   *   Coordinates of the corresponding help point
   * @return
   *   <tt>TRUE</tt> if succeeded,
   *   <tt>FALSE</tt> is failed
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetHelpPoint2D(CATICDSGeometryLeaf* ipGLeaf, double oaHelpPoint[2]) const = 0;

  /**
   * Specify the help point 2D location.
   * @param ipGeometry
   *   A pointer to the circle callback
   * @param iaHelpPoint
   *   Coordinates of the corresponding help point
   */
  virtual void SetHelpPoint2D(CATICDSGeometryLeaf* ipGLeaf, double iaHelpPoint[2]) = 0;

  /**
   * Retrieves help point of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param oaPoint
   *   An array of coordinates of the help point.
   * @see #SetHelpPoint
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetHelpPoint(CATICDSGeometryLeaf *ipGLeaf, double oaPoint[3]) const = 0;
  
  /**
   * Updates help point of the constraint for a specified geometry.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param iaPoint
   *   An array of coordinates of the help point.
   * @see #GetHelpPoint
   */
  virtual void SetHelpPoint(CATICDSGeometryLeaf *ipGLeaf, double iaPoint[3]) = 0;
  
  /**
   * Associates given variables with a given argument of a given constraint.
   * @param ipGLeaf
   *   A pointer to the geometric object that is the argument of constraint
   * @param ipVariable1
   *   A pointer to variable callback to be associated
   *   with parameter on curve or the first parameter on surface
   * @param ipVariable2
   *   A pointer to variable callback to be associated
   *   with the second parameter on surface
   */
  virtual void SetHelpParameterVariables(CATICDSGeometryLeaf* ipGLeaf, CATICDSVariable* ipVariable1, CATICDSVariable* ipVariable2) = 0;

  /**
   * Retreive the variables associated with the given argument of the constraint
   * @param ipGLeaf
   *   A pointer to the geometric object that is the argument of constraint
   * @param ipVariable1
   *   A pointer to variable callback to be associated
   *   with parameter on curve or the first parameter on surface
   * @param ipVariable2
   *   A pointer to variable callback to be associated
   *   with the second parameter on surface
   *
   * @CHECKRESULT TRUE
   * @RETURNARRAY
   */
  virtual CATCDSBoolean GetHelpParameterVariables(CATICDSGeometryLeaf* ipGLeaf, CATICDSVariable*& opVariable1, CATICDSVariable*& opVariable2) const = 0;
  
  /**
   * Retrieves surface orientation of the constraint.
   * @return
   *   A surface orientation of the constraint.
   */
  virtual CATCDSSurfaceOrientation GetSurfaceOrientation() const = 0;

  /**
   * Sets surface orientation of the constraint.
   * @param iSurfaceOrientation
   *   Surface orientation of the constraint.
   * @see #GetSurfaceOrientation
   */
  virtual void SetSurfaceOrientation(CATCDSSurfaceOrientation iSurfaceOrientation) = 0;

  /**
   * Check if at least one of constraint's help parameters was transformed by last solver Run.
   */
  virtual CATCDSBoolean HasHelpParamTransformation() const = 0;

  virtual ~CATICDSGeomConstraint() {}
};

#endif
