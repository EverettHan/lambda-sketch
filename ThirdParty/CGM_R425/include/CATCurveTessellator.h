#ifndef CATCurveTessellator_h
#define CATCurveTessellator_h
// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATDataType.h"
#include "TessAPI.h"
#include "CATMathConstant.h"
#include "CATCGMVirtual.h"
#include "CATIACGMLevel.h"

class CATCurve;
class CATCrvLimits;
class CATMathSetOfPointsND;

/**
 * Class defining a tessellation operator on curves.
 * <br> This operator computes a discretized geometry on the curves as bars.
 * The extremities of the bars are called points. Three parameters tune the tessellation result:
 * <dl>
 * <dt> Sag </dt><dd> Defines the maximum distance between a bar and the object to tessellate
 * <dt> Step </dt><dd> Defines the maximum length of a bar. If not defined, the step is infinite 
 * (this parameter is unused)
 * <dt> Angle </dt><dd> Defines the maximum angle between the normals at each bar end. 
 * </dl>
 * The tessellation operator follows the scheme of all CGM operator:
 * <ul>
 * <li> Create an operator instance,
 * <li> Run,
 * <li> Optionally, adds other curves to tessellate in the same operation,
 * <li> Recover the results into arrays that are allocated by the operator,
 * <li> Delete the operator instance. The deletion of the operator leads to the deletion
 * of the arrays of results.
 * </ul>
 */
class ExportedByTessAPI CATCurveTessellator: public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATCurveTessellator);
public:
  /**
   * Constructs a CATCurveTessellator with an infinite step.
   * @param iSag
   * The Sag value.
   * @param iAngle
   * The Angle value.
   */
  CATCurveTessellator(double iSag,
                      double iAngle=CATPI*.25);

  ~CATCurveTessellator();
  
   /**
   * Adds an other curve to <tt>this</tt> CATCurveTessellator.
   * @param iCurve
   * The other curve to tessellate in the same operation.
   * @param iCurveLimits
   * The part of the curve to take into account.
   */
  void AddCurve(CATCurve * iCurve, const CATCrvLimits& iCurveLimits);

   /**
   * Defines a finite step for <tt>this</tt> CATCurveTessellator.
   * @param iStep
   * The Step value.
   */
  void SetStep(double iStep);

#ifdef CATIACGMR424CAA
   /**
   * Runs <tt>this</tt> CATCurveTessellator.
   */
  virtual void Run();
#else
	/**
	* Runs <tt>this</tt> CATCurveTessellator.
	*/
	void Run();

#endif
   /**
   * Retrieves the results associated with a curve.
   * @param iCurve
   * A curve among the input curves.
   * @param oMathPoints
   * A CATMathSetOfPointsND pointer. This set contains the points (as 3 Cartesian coordinates)
   * of the resulting tessellation.
   * @param oCrvParams
   * A CATMathSetOfPointsND pointer. This set contains the points (as a CATCrvParam on the
   * underlying edge curve)
   * of the resulting tessellation.
   */
  void GetCurve (CATCurve * iCurve,
                 CATMathSetOfPointsND ** oMathPoints,
                 CATMathSetOfPointsND ** oCrvParams);

    /**
   * Retrieves the results (in doubles) associated with a curve.
   * @param iCurve
   * A curve among the input curves.
   * @param ioNumberOfPoints
   * The number of points of the resulting tessellation.
   * @param oPointData
   * The array of the resulting points. This array is allocated by the <tt>GetCurve</tt>
   * method. The j-th coordinate of the i-th point is
   * <tt>oPointData[3*(i-1)+j-1]</tt>. 
   */
  void GetCurve (CATCurve * iCurve, CATLONG32 &ioNumberOfPoints, double ** oPointData);

    /**
   * Retrieves the results (in floats) associated with a curve.
   * @param iCurve
   * A curve among the input curves.
   * @param ioNumberOfPoints
   * The number of points of the resulting tessellation.
   * @param oPointData
   * The array of the resulting points. This array is allocated by the <tt>GetCurve</tt>
   * method. The j-th coordinate of the i-th point is
   * <tt>oPointData[3*(i-1)+j-1]</tt>. 
   */
  void GetCurve (CATCurve * iCurve, CATLONG32 &ioNumberOfPoints, float  ** oPointData);


protected:  
  void * _Tessellator;
};

#endif

