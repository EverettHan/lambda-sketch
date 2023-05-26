#ifndef CATHLRSurface_H
#define CATHLRSurface_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRSurface
//

/** Surface for the HLR.
 * <BR> A surface is able to evaluate some points.
 */
// Main Methods :
//    - EvalPoint
//    - EvalFirstDeriv
//    - EvalNormal
//    - GetLimits
//  
//=============================================================================
// Abstract Class     : No
// Template Code      : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Nov. 1997 JCH Creation            
// Jun. 1999 HKL Added GetParam, RayFire, IsExtruded methods
// May. 2000 HKL Added IsRevolution method
// Jui. 2000 HKL Added GetDirBox
//
//=============================================================================

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRGeometry.h"

//=============================================================================
// For inheritance and other includes
//-----------------------------------------------------------------------------
#include "CATHLRGeometry.h"
#include "CATIsoParameter.h"
#include "CATHLRConstant.h"


//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------
class CATBaseUnknown;

class CATHLRSurfaceSpec;

class CATMathDirection;
class CATMathPoint;
class CATMathVector;
class CATMathDirBox;

class CATSurEvalCommand;
class CATSurEvalResult;
class CATSurEvalLocal;
class CATSurLimits;
class CATSurParam;
class CATSurParamReference;
class CATSurface;

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

//=============================================================================
// Class definition
//=============================================================================
class ExportedByHLRGeometry CATHLRSurface : public CATHLRGeometry
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a jele, a container, a transformation and a pointer on the
 * specifity of the surface ( that might be NULL).
 */
  CATHLRSurface(int               iJele,
		CATHLRContainer * iContainer,
		const CATHLRTransformation * iTransformation,
		CATHLRSurfaceSpec          * iSpecifity = 0L,
		CATIsoParameter              iLinearity = CATIsoParNoDir);

/** Constructor from a geometry pointer  and a container and a transformation
 */
  CATHLRSurface(void            * iGeometry,
		CATHLRContainer * iContainer,
		const CATHLRTransformation * iTransformation,
		CATHLRSurfaceSpec          * iSpecifity = 0L,
		CATIsoParameter              iLinearity = CATIsoParNoDir);

//=============================================================================
// METHODS FOR THE EVALUATION
//=============================================================================
/**
 * Evaluates cartesian point at a given parameter.
 */
  virtual void EvalPoint(const CATSurParam & iSurfaceParameter,
			 CATMathPoint      & oResult) const = 0;

/**
 * Evaluates derivatives at a given parameter.
 */
  virtual void EvalFirstDeriv(const CATSurParam & iSurfaceParameter,
			      CATMathVector     & oDerivU,
			      CATMathVector     & oDerivV) const = 0;
/**
 * Evaluates second derivatives at a given parameter.
 */
  virtual void EvalSecondDeriv(const CATSurParam & iSurfaceParameter,
                               CATMathVector     & oDerivU2,
                               CATMathVector     & oDerivUV,
                               CATMathVector     & oDerivV2) const = 0;

/**
 * Evaluates Outer Normal ( the result is normalized).
 * Outer Normal is oriented towards : ds/du ^ ds/dv.
 */
  virtual void EvalNormal(const CATSurParam & iSurfaceParameter,
			  CATMathVector     & oNormal) const = 0;

/**
 * Evaluates Outer Normal derivatives (the result is normalized).
 * Outer Normal is oriented towards : ds/du ^ ds/dv.
 */
  virtual void EvalNormalDerivatives(const CATSurParam & iSurfaceParameter,
				     CATMathVector     & oNormalDerivU,
				     CATMathVector     & oNormalDerivV) const;

/** Retrieves multiple evalutions at a given point of <tt>this</tt> CATSurface.
 */
  virtual void Eval(const CATSurParam       & iPoint,
                    const CATSurEvalCommand & iCommand,
                    CATSurEvalLocal         & oResult) const =0;

/**
 * Multi-Evaluation in a given box and given numbers of points
 */
  virtual void Eval(const CATSurLimits      & iBox,
 		    const CATSurEvalCommand & iCommand,  
 		    CATLONG32                      iCntPointsInU,
		    CATLONG32                      iCntPointsInV,
 		    CATSurEvalResult        & oResult) const = 0;

//=============================================================================
// MANAGEMENT METHODS
//=============================================================================
/** Finds the parameter pair closest to the point within the limits.
 */
  enum Diagnostic {NoSolution, SingleSolution, MultipleSolution};
  virtual CATHLRSurface::Diagnostic GetParam(const CATMathPoint & iPoint, 
                                             CATSurParam        & oParam,
                                             CATSurLimits       * iLimits = NULL) const = 0;

/** Fires a ray from iPoint in iDirection direction, 
  * and returns the number N of intersections within the limits.
  * oXYZ, oU and oV are arrays allocated by the method and that the caller should free.
  * oXYZ size is 3*N, oU and oV sies are N
  */
  virtual CATLONG32 RayFire(const CATMathPoint     & iPoint, 
                       const CATMathDirection & iDirection,
                       double **oXYZ, double **oU, double **oV,
                       CATSurLimits * iLimits = NULL) const = 0;

/**
  * Getting a box on the surface
  */
  virtual void GetLimits(CATSurLimits & oBox) = 0;

/** Getting the reference of the Surface ( to build CATSurParam and CATSurLimits)
 */
  virtual const CATSurParamReference  * GetReference() const = 0;

/** Returns 1 if the surface is extruded.
 *  If so, oExtrusionDirection contains the extrusion direction
 */
  virtual CATLONG32 IsExtruded(CATMathDirection & oExtrusionDirection) const;

/** Returns 1 if the surface is extruded.
 *  If so, and if oAxis is not NULL, oAxis contains the revolution axis
 */
  virtual CATLONG32 IsRevolution(CATMathDirection * oAxis = NULL) const = 0;

/** Returns 1 if the surface is C2.
 */
  virtual CATLONG32 IsC2() const;

/** Retrieves the DirBox surrounding the normals of the surface.
 * Returns 1 if the fonction has been implemented, otherwise 0
 */
  virtual CATLONG32 GetDirBox(CATMathDirBox & oDirBox);

  /** Retrieves the surface CGM in the context CATIA Geometric Modeler only
  * returns the surface in case of CATHLRSurfaceCGM, NULL in other contexts (default implementation)
  */
  virtual CATSurface * GetCGMSurface() const;

//=============================================================================
/** Gets the type of the surface
 */
  CATHLRConstant::TypeSurface GetTypeOfSurface() const;

/** Getting the specificity of the surface.
 * <BR> This method returns NULL it the surface has no known specificities.
 */
  CATHLRSurfaceSpec * GetSpecificity() const;

/** Gets the directions of linearity of the surface (if there are some).
  */
  CATIsoParameter IsLinear() const;

//=============================================================================
// Internal datas
//=============================================================================
protected:
// Pointer on the specificities of the surface
  CATHLRSurfaceSpec * _SurfaceSpecifity;

// Type of the surface
  CATHLRConstant::TypeSurface _SurfaceType;

// Linearities of the surface.
  CATIsoParameter             _Linearity;

// statistics on calls; internal use only
  friend class CATHLRSurfaceStats;
  static CATLONG32 CallsToEvalPoint;
  static CATLONG32 CallsToEvalFirstDeriv;
  static CATLONG32 CallsToEvalSecondDeriv;
  static CATLONG32 CallsToEvalNormal;
  static CATLONG32 CallsToEvalNormalDerivatives;
  static CATLONG32 CallsToEvalMultiple;
  static CATLONG32 CallsToEvalMultiplePoints;
  
};

#endif
