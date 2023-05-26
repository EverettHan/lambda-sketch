#ifndef CATReflectCurve_H
#define CATReflectCurve_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATCreateReflectCurve.h"
#include "Y30C3XGG.h"
#include "CreateReflectCurve.h"
#include "CATReflectCurveSign.h"
#include "CATMathDef.h"
#include "CATGeoOperator.h"
#include "CATSurLimits.h"

#include "CATIACGMLevel.h"

class CATGeometry;
class CATSurface;
class CATCurve;
class CATPCurve;
class CATPlane;
class CATLISTP(CATPCurve); 

/**
 * Class defining the operator to compute the reflect curves on a surface.
 * <br>The reflect curves are the set of points of a surface such that the surface normal 
 * at these points and a direction defines a constant angle.
 *<ul>
 *<li>The CATReflectCurve operator is created with the <tt>CreateReflectCurve</tt> method and 
 * directly <tt>delete</tt>d with the usual C++ delete operator.
 * It is is not streamable. 
 *<li>In case of <tt>BASIC</tt>
 * mode, the operation is automatically performed at the operator creation. 
 * In case of <tt>ADVANCED</tt>
 * mode, options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. The advanced mode also allows you to
 * run the same operator with different curves or surfaces.
 *<li>In both cases, the result is accessed with specific interators.
 *</ul>
 */
class ExportedByY30C3XGG CATReflectCurve : public CATGeoOperator
{
  CATCGMVirtualDeclareClass(CATReflectCurve);
 public:

 /** 
  * @nodoc
  * Use the <tt>CreateReflectCurve</tt> global function.
  */
  CATReflectCurve(CATGeoFactory * factory);

  virtual ~CATReflectCurve();
/**
 * Initializes the iterator of the solution curves of <tt>this</tt> 
 * CATProjectionCrvSur operator.
 *<br>By default, the initialization is performed once the operator runs, 
 * and this is therefore only used to read the solutions again.
 */
  virtual void BeginningCurve()                      = 0;

/**
 * Skips to the next solution curve of <tt>this</tt> CATReflectCurve operator.
 *<br>After <tt>BeginningCurve</tt>, it skips to the first curve. 
 * @return
 * The existence of the next solution.
 * <br><b>Legal values</b>:
 *<dl><dt><tt>TRUE</tt> <dd>if there is a solution point
 *    <dt><tt>FALSE</tt> <dd>no more solution point.</dl>
 */
  virtual CATBoolean NextCurve()                     = 0;

/**
 * Creates the next solution curve as a curve on surface.
 * @return
 * The pointer to the created curve on surface. A new curve is created each time this method is called.
 * If you do not want to keep the created curve, use the @href CATICGMContainer#Remove method.
 */
  virtual CATPCurve * GetPCurve()              =0 ;

	/**
 * Creates the next solution curve.
 * @return
 * The pointer to the created curve. A new curve is created each time this method is called.
 * If you do not want to keep the created curve, use the @href CATICGMContainer#Remove method.
 */
  virtual CATCurve * GetCurve()                      = 0;
	/** @nodoc */
  virtual CATReflectCurveSign GetSignatureOn() const = 0;  

	/**
	 * Returns the number of solution curves.
	 * @return
	 * The number of curves.
	 */
  virtual CATLONG32 GetNumberOfPCurves()            const = 0;

	/**
 * Modifies the surface domain to take into account for <tt>this</tt> CATReflectCurve
 * operator (<tt>ADVANCED</tt> mode).
 *<br> It does not change the current surface 
 * limitations.  
 * @param iLimits
 * The new limitations of the surface, <tt>NULL</tt> to take the current limitations.
 */
  virtual void SetLimits(CATSurLimits  *iLimits)     = 0;
	
	/** @nodoc */
  virtual void BeginningSurface()                    = 0;
	/** @nodoc */
  virtual CATBoolean NextSurface()                   = 0;

  /** @nodoc */
  virtual void GetExtremitiesIndex(CATLONG32 & oStartIndex, CATLONG32 & oEndIndex) = 0;
  /** @nodoc */
  virtual CATReflectCurveSign GetIntrinsicSignatureOn() const = 0;

#ifdef CATIACGMR214CAA
  /** @nodoc */
  // @nocgmitf
  virtual void ManageStrongCurvatures(CATBoolean iManage) = 0;
#endif

#ifdef CATIACGMR215CAA
  /** @nodoc */
  // @nocgmitf
  virtual void ExtractIsoCurves() = 0;
#endif

  /** @nodoc */
  // @nocgmitf
  virtual void EnableBorderSolutionFilter() =0;
};

#endif
