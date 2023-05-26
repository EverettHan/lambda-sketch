#ifndef CATICDSInterpolationNURBSCurve_H
#define CATICDSInterpolationNURBSCurve_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSCurve.h"

#include "CATIAV5Level.h"

class CATICDSFactory;
class CATICDSPoint;
class CATICDSLine;
class CATICDSVariable;

/**
 * A 3D NURBS curve constructed from interpolation conditions.
 * Prerequisite :
 *  There is at least 2 points for the interpolation.
 *  The interpolation conditions are given in the ascending parameter order.
 */
class ExportedByCDSInterface CATICDSInterpolationNURBSCurve : public CATICDSCurve
{
public:
  /**
   * Constructs an instance of interpolating NURBS curve.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   */
  static CATICDSInterpolationNURBSCurve * Create(CATICDSFactory *ipFactory);

  /**
   * Get the periodicity of the NURBS
   * @return
   *   Return TRUE if the nurbs is periodic
   */
#if defined(CATIAV5R27) || defined (CATIAR419) || defined(_EMSCRIPTEN_SOURCE)
  virtual CATCDSBoolean IsPeriodic() const = 0;

  virtual CATCDSBoolean IsPeriodic(CATCDSBoolean iPeriodic) const {return IsPeriodic();};
#else
  virtual CATCDSBoolean IsPeriodic(CATCDSBoolean iPeriodic) const = 0;
#endif

  /**
   * Return the number of interpolation points.
   * @return
   *   The number of interpolation points.
   */
  virtual int GetNbOfInterpolationPoints() const = 0;

  /**
   * Return the interpolation point at given index.
   * @param iIdx
   *   The position of the point in the list of interpolating point.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @return
   *   The interpolation point.
   */
  virtual CATICDSPoint* GetInterpolationPoint(int iIdx) const = 0;

  /**
   * Return the parameter of the interpolation point.
   * Be careful. After changing the curve definition or the coordinates of the definition objects, a run of the solver must be done before using this API.
   * @param iIdx
   *   The position of the point in the list of interpolating point.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @return
   *   The parameter.
   */
  virtual double GetInterpolationPointParameter(int iIdx) const = 0;

  /**
   * Return the line which defines first derivative direction at given index.
   * @param iIdx
   *   The index of the interpolation point where first derivative is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @return
   *   The line or a null pointer if the direction isn't defined.
   */
  virtual CATICDSLine* GetFirstDerivativeDirection(int iIdx) const = 0;

  /**
   * Retrieve the value of the specified first derivative norm at given index.
   * @param iIdx
   *   The index of the interpolation point where first derivative norm is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param oValue
   *   The value of the norm.
   * @return 
   *   Return TRUE if the norm was fixed, FALSE otherwise.
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetFirstDerivativeNorm(int iIdx, double & oValue) const = 0;

  /**
   * Get the variable of the specified first derivative norm at given index.
   * @param iIdx
   *   The index of the interpolation point where first derivative norm is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @return 
   *   Return a pointer to the variable which defines the norm or a null pointer if no variable was set.
   */
  virtual CATICDSVariable* GetFirstDerivativeNorm(int iIdx) const = 0;

  /**
   * Return the line which defines second derivative direction at given index.
   * @param iIdx
   *   The index of the interpolation point where second derivative is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @return
   *   The line.
   */
  virtual CATICDSLine* GetSecondDerivativeDirection(int iIdx) const = 0;

  /**
   * Retrieve the value of the specified second derivative norm at given index.
   * @param iIdx
   *   The index of the interpolation point where second derivative norm is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param oValue
   *   The value of the norm.
   * @return 
   *   Return TRUE if the norm was fixed, FALSE otherwise.
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetSecondDerivativeNorm(int iIdx, double & oValue) const = 0;

  /**
   * Get the variable of the specified second derivative norm at given index.
   * @param iIdx
   *   The index of the interpolation point where second derivative norm is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @return 
   *   Return a pointer to the variable which defines the norm or a null pointer if no variable was set.
   */
  virtual CATICDSVariable* GetSecondDerivativeNorm(int iIdx) const = 0;

  /**
   * Retrieve the value of the specified curvature at given index.
   * @param iIdx
   *   The index of the interpolation point where curvature is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param oValue
   *   The value of the curvature.
   * @return 
   *   Return TRUE if the curvature was fixed, FALSE otherwise.
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetCurvature(int iIdx, double & oValue) const = 0;

  /**
   * Get the variable of the specified curvature at given index.
   * @param iIdx
   *   The index of the interpolation point where curvature is specified
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @return 
   *   Return a pointer to the variable which defines the curvature or a null pointer if no variable was set.
   */
  virtual CATICDSVariable* GetCurvature(int iIdx) const = 0;

  /**
   * Returns the control point at the given index
   * @param iIndex
   *   Index of point to return. Must be 0 or greater and less or equal than 
   *   n control points - 1.
   * @param oX
   *   X coordinate of resulting control point.
   * @param oY
   *   Y coordinate of resulting control point.
   * @param oZ
   *   Z coordinate of resulting control point.
   */     
  virtual void GetControlPointCoords(int iIndex, double &oX, double &oY, double &oZ) const = 0;

  /**
   * Set the periodicity of the NURBS
   * @param iPeriodic
   *   Specifies whether the NURBS parameterization is periodic and the NURBS is closed.
   *   Affects the NURBS shape.
   */
  virtual void SetPeriodic(CATCDSBoolean iPeriodic) = 0;

  /**
   * Sets degree of the NURBS curve.
   * @param iDegree
   *   Degree of the NURBS
   * @return TRUE
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean SetDegree(int iDegree) = 0;

  /**
   * Gets the degree of the NURBS curve defined by the caller.
   * If the degree has not been defined, it returns 0
   * @return Specified NURBS degree
   */
  virtual int GetDegree() const = 0;

  /**
   * Gets the current degree of the NURBS.
   * If the degree has been defined with SetDegree, it is equivalent to GetDegree.
   * Otherwise it returns the degree choosen by the implementation.
   * @return NURBS degree
   */
  virtual int GetCurrentDegree() const = 0;

  /**
   * Sets degree, parameters and knot vector of the NURBS curve.
   * If curve definition is changed after a call to this method, this method must be called another time with updated data.
   * @param iDegree
   *   Degree of the NURBS
   * @param iaParameters
   *   Parameters of the NURBS curve. Must be the size of the number
   *   of parameters for this NURBS curve.
   * @param iaKnots
   *   Knot vector of the NURBS curve. Must be the size of the number
   *   of knots (n control points + degree + 1) for this NURBS curve.
   * @return TRUE
   *
   * @SIZE iaParameters GetNbOfInterpolationPoints()
   * @SIZE iaKnots (GetNbOfInterpolationPoints()+iDegree+1)
   * @CHECKRESULT TRUE
   */   
  virtual CATCDSBoolean SetInterpParametersAndKnots(int iDegree, double *iaParameters, double *iaKnots) = 0;

  /**
   * @DEPRECATED
   */
  virtual void SetInterpParametersAndKnots(double *iaParameters, double *iaKnots) = 0;

  /**
   * Returns the NURBS curve definition
   * @param onControlPoints
   *   Number of control points.
   * @param oDegree
   *   Degree of the curve.
   * @param oaKnots
   *   (n control points  + degree + 1 ) array of knots.
   * @param oaControlPointsCoords
   *   (n control points * 3) array of control points.
   * @param oaWeights
   *   (n control points) array of weights.
   *
   * @SKIP
   */
  virtual void ComputeNURBSDefinition(int &onControlPoints, int &oDegree, double const *&oaKnots, double const *&oaControlPointsCoords, double const *&oaWeights) const = 0;

  /**
   * Returns the NURBS curve definition
   * If the NURBS is periodic, it is converted to a clamped NURBS. Otherwise we get same result as ComputeNURBSDefinition.
   * The arrays are allocated by the methods but must be deleted by the caller
   * @param onControlPoints
   *   Number of control points.
   * @param oDegree
   *   Degree of the curve.
   * @param oaKnots
   *   (n control points  + degree + 1 ) array of knots.
   * @param oaControlPointsCoords
   *   (n control points * 3) array of control points.
   * @param oaWeights
   *   (n control points) array of weights.
   *
   * @SKIP
   */
  virtual void ComputeClampedNURBSDefinition(int &onControlPoints, int &oDegree, double *&oaKnots, double *&oaControlPointsCoords, double *&oaWeights) const = 0;
  
  /**
   * Add a new interpolation point to the definition of the NURBS curve.
   * @param iIdx
   *   The position of the new point in the list of interpolating point.
   *   It must belongs to [0, n] where n is the number of interpolating point before insertion.
   * @param ipPoint
   *   New inserted interpolation point.
   */
  virtual void AddInterpolationPoint(int iIdx, CATICDSPoint *ipPoint) = 0;

  /**
   * Remove an interpolation point to the definition of the NURBS curve.
   * @param iIdx
   *   The position of the removed point in the list of interpolating point.
   *   It must belongs to [0, n-1] where n is the number of interpolating point before deletion.
   */
  virtual void RemoveInterpolationPoint(int iIdx) = 0;

  /**
   * Specify the first derivative direction at the specified interpolation point.
   * If a direction was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where first derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param ipLine
   *   The line which defines the direction.
   */
  virtual void SetFirstDerivativeDirection(int iIdx, CATICDSLine *ipLine) = 0;

  /**
   * Remove the first derivative direction at the specified interpolation point.
   * @param iIdx
   *   The index of the point where first derivative is specified.
   */
  virtual void RemoveFirstDerivativeDirection(int iIdx) = 0;

  /**
   * Specify the first derivative norm at the specified interpolation point.
   * If the norm (value or variable) was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where first derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param iNorm
   *   The norm of the first derivative.
   */
  virtual void SetFirstDerivativeNorm(int iIdx, double iNorm) = 0;

  /**
   * Specify the first derivative norm at the specified interpolation point.
   * If the norm (value or variable) was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where first derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param iNorm
   *   The norm of the first derivative.
   *
   * @RENAME SetFirstDerivativeNormVariable
   */
  virtual void SetFirstDerivativeNorm(int iIdx, CATICDSVariable *ipVariable) = 0;

  /**
   * Remove the first derivative norm at the specified interpolation point.
   * @param iIdx
   *   The index of the point where first derivative norm is specified.
   */
  virtual void RemoveFirstDerivativeNorm(int iIdx) = 0;

  /**
   * Specify the second derivative direction at the specified interpolation point.
   * If a direction was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where second derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param ipLine
   *   The line which defines the direction.
   */
  virtual void SetSecondDerivativeDirection(int iIdx, CATICDSLine *ipLine) = 0;

  /**
   * Remove the second derivative direction at the specified interpolation point.
   * @param iIdx
   *   The index of the point where second derivative is specified.
   */
  virtual void RemoveSecondDerivativeDirection(int iIdx) = 0;

  /**
   * Specify the second derivative norm at the specified interpolation point.
   * If the norm (value or variable) was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where second derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param iNorm
   *   The norm of the second derivative.
   */
  virtual void SetSecondDerivativeNorm(int iIdx, double iNorm) = 0;

  /**
   * Specify the second derivative norm at the specified interpolation point.
   * If the norm (value or variable) was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where second derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param iNorm
   *   The norm of the second derivative.
   *
   * @RENAME SetSecondDerivativeNormVariable
   */
  virtual void SetSecondDerivativeNorm(int iIdx, CATICDSVariable *ipVariable) = 0;

  /**
   * Remove the second derivative norm condition at the specified interpolation point.
   * @param iIdx
   *   The index of the point where second derivative norm is specified.
   */
  virtual void RemoveSecondDerivativeNorm(int iIdx) = 0;

    /**
   * Specify the curvature at the specified interpolation point.
   * If the curvature (value or variable) was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where second derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param iNorm
   *   The norm of the second derivative.
   */
  virtual void SetCurvature(int iIdx, double iCurvature) = 0;

  /**
   * Specify the curvature at the specified interpolation point.
   * If the curvature (value or variable) was already specified at this point, it is replaced.
   * @param iIdx
   *   The index of the point where second derivative is specified.
   *   It must belongs to [0, n-1] where n is the number of interpolating point.
   * @param iNorm
   *   The norm of the second derivative.
   *
   * @RENAME SetCurvatureVariable
   */
  virtual void SetCurvature(int iIdx, CATICDSVariable *ipVariable) = 0;

  /**
   * Remove the curvature condition at the specified interpolation point.
   * @param iIdx
   *   The index of the point where curvature is specified.
   */
  virtual void RemoveCurvature(int iIdx) = 0;

  /**
   * Update internal NURBS representation taking into account new nurbs definition constraints and new dependencies coordinates
   * This method is useful when you have modified curve definition or dependencies coordinates since last run
   * and you need to use evaluation method (such as ComputeNURBSDefinition, Evaluate, ...)
   * @return 
   *   Return TRUE if update succeeded (ie if NURBS definition is valid)
   */
  virtual CATCDSBoolean UpdateNURBS() = 0;

  /**
   * @DEPRECATED
   */
  static CATICDSInterpolationNURBSCurve * Create(CATICDSFactory *ipFactory,
                                                 int iNbConditions,
                                                 CATCDSInterpolConditionType * iaConditionTypes,
                                                 double * iaConditionParameters,
                                                 CATICDSPoint** iapConditionPoints,
                                                 CATICDSVariable** iapConditionVariables,
                                                 CATICDSLine** iapConditionLines,
                                                 double * iaConditionValues,
                                                 CATCDSBoolean iPeriodic = FALSE);

  /**
   * @DEPRECATED
   */
  virtual int GetNbConditions() const = 0;

  /**
   * @DEPRECATED
   */
  virtual CATCDSInterpolConditionType const GetConditionType(int iIdx) const = 0;

  /**
   * @DEPRECATED
   */
  virtual double const GetConditionParameter(int iIdx) const = 0;

  /**
   * @DEPRECATED
   */  
  virtual CATICDSPoint * GetConditionPoint(int iIdx) const = 0;

  /**
   * @DEPRECATED
   */    
  virtual CATICDSVariable * GetConditionVariable(int iIdx) const = 0;

  /**
   * @DEPRECATED
   */  
  virtual CATICDSLine * GetConditionLine(int iIdx) const = 0;

  /**
   * @DEPRECATED
   */
  virtual double const GetConditionValue(int iIdx) const = 0;

  /**
   * @DEPRECATED
   */
  virtual void SetConditionValue(int iIdx, double iValue) = 0;

  /**
   * @DEPRECATED
   */
  virtual double const GetParameter(int iIdx) const = 0;

  virtual ~CATICDSInterpolationNURBSCurve() {}
};

#endif
